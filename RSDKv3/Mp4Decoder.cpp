#include "RetroEngine.hpp"

#if RETRO_USE_MP4

#include "Mp4Decoder.hpp"

#include <thread>
#include <mutex>
#include <atomic>
#include <deque>
#include <chrono>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include <libavutil/channel_layout.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
}

// Queue caps so a fast decoder can't run away with memory; the decode thread
// blocks (backpressure) when the consumer side falls behind.
static const size_t VIDEO_QUEUE_CAP = 24;
static const size_t AUDIO_QUEUE_CAP = 256;

struct Mp4Decoder {
    AVFormatContext *fmt = nullptr;
    AVCodecContext *vctx = nullptr;
    AVCodecContext *actx = nullptr;
    SwsContext *sws      = nullptr;
    SwrContext *swr      = nullptr;
    int vStream          = -1;
    int aStream          = -1;
    int width            = 0;
    int height           = 0;
    double fps           = 30.0;
    AVRational vTimeBase = { 1, 1000 };

    std::thread worker;
    std::mutex mtx;
    std::deque<Mp4VideoFrame *> videoQ;
    std::deque<Mp4AudioPacket *> audioQ;
    std::atomic<bool> stop{ false };
    std::atomic<bool> finished{ false };
};

// --- helpers ----------------------------------------------------------------
static void pushVideo(Mp4Decoder *d, Mp4VideoFrame *f)
{
    for (;;) {
        {
            std::lock_guard<std::mutex> lk(d->mtx);
            if (d->videoQ.size() < VIDEO_QUEUE_CAP) {
                d->videoQ.push_back(f);
                return;
            }
        }
        if (d->stop.load()) {
            Mp4_FreeVideo(f);
            return;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

static void pushAudio(Mp4Decoder *d, Mp4AudioPacket *p)
{
    for (;;) {
        {
            std::lock_guard<std::mutex> lk(d->mtx);
            if (d->audioQ.size() < AUDIO_QUEUE_CAP) {
                d->audioQ.push_back(p);
                return;
            }
        }
        if (d->stop.load()) {
            Mp4_FreeAudio(p);
            return;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

static void emitVideoFrame(Mp4Decoder *d, AVFrame *frame)
{
    int w = d->width, h = d->height;
    int ySize = w * h;
    int cSize = (w / 2) * (h / 2);

    Mp4VideoFrame *out = (Mp4VideoFrame *)malloc(sizeof(Mp4VideoFrame));
    out->width         = w;
    out->height        = h;
    out->pixels        = (unsigned char *)malloc((size_t)ySize + 2 * cSize);

    uint8_t *dstData[4] = { out->pixels, out->pixels + ySize, out->pixels + ySize + cSize, nullptr };
    int dstLines[4]     = { w, w / 2, w / 2, 0 };
    sws_scale(d->sws, frame->data, frame->linesize, 0, h, dstData, dstLines);

    int64_t pts  = (frame->best_effort_timestamp != AV_NOPTS_VALUE) ? frame->best_effort_timestamp : frame->pts;
    double ms    = (pts == AV_NOPTS_VALUE) ? 0.0 : (double)pts * av_q2d(d->vTimeBase) * 1000.0;
    out->playms  = (unsigned int)(ms < 0 ? 0 : ms);

    pushVideo(d, out);
}

static void emitAudioFrame(Mp4Decoder *d, AVFrame *frame)
{
    int maxOut = (int)swr_get_out_samples(d->swr, frame->nb_samples);
    if (maxOut <= 0)
        return;

    Mp4AudioPacket *out = (Mp4AudioPacket *)malloc(sizeof(Mp4AudioPacket));
    out->samples        = (float *)malloc((size_t)maxOut * 2 * sizeof(float));

    uint8_t *outPlanes[1] = { (uint8_t *)out->samples };
    int got               = swr_convert(d->swr, outPlanes, maxOut, (const uint8_t **)frame->data, frame->nb_samples);
    if (got <= 0) {
        free(out->samples);
        free(out);
        return;
    }
    out->frames = got;
    pushAudio(d, out);
}

static void drainDecoder(Mp4Decoder *d, AVCodecContext *ctx, AVFrame *frame, bool isVideo)
{
    for (;;) {
        int ret = avcodec_receive_frame(ctx, frame);
        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
            break;
        if (ret < 0)
            break;
        if (isVideo)
            emitVideoFrame(d, frame);
        else
            emitAudioFrame(d, frame);
        av_frame_unref(frame);
    }
}

static void decodeThread(Mp4Decoder *d)
{
    AVPacket *pkt = av_packet_alloc();
    AVFrame *frame = av_frame_alloc();

    while (!d->stop.load()) {
        int ret = av_read_frame(d->fmt, pkt);
        if (ret < 0) {
            // end of file: flush both decoders
            avcodec_send_packet(d->vctx, nullptr);
            drainDecoder(d, d->vctx, frame, true);
            if (d->actx) {
                avcodec_send_packet(d->actx, nullptr);
                drainDecoder(d, d->actx, frame, false);
            }
            break;
        }

        if (pkt->stream_index == d->vStream) {
            if (avcodec_send_packet(d->vctx, pkt) >= 0)
                drainDecoder(d, d->vctx, frame, true);
        }
        else if (d->actx && pkt->stream_index == d->aStream) {
            if (avcodec_send_packet(d->actx, pkt) >= 0)
                drainDecoder(d, d->actx, frame, false);
        }
        av_packet_unref(pkt);
    }

    av_frame_free(&frame);
    av_packet_free(&pkt);
    d->finished.store(true);
}

// --- public API -------------------------------------------------------------
Mp4Decoder *Mp4_Open(const char *path)
{
    Mp4Decoder *d = new Mp4Decoder();

    if (avformat_open_input(&d->fmt, path, nullptr, nullptr) < 0) {
        delete d;
        return nullptr;
    }
    if (avformat_find_stream_info(d->fmt, nullptr) < 0) {
        Mp4_Close(d);
        return nullptr;
    }

    d->vStream = av_find_best_stream(d->fmt, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
    d->aStream = av_find_best_stream(d->fmt, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
    if (d->vStream < 0) {
        Mp4_Close(d);
        return nullptr;
    }

    // --- video decoder ---
    AVStream *vs               = d->fmt->streams[d->vStream];
    const AVCodec *vcodec      = avcodec_find_decoder(vs->codecpar->codec_id);
    if (!vcodec) {
        Mp4_Close(d);
        return nullptr;
    }
    d->vctx = avcodec_alloc_context3(vcodec);
    avcodec_parameters_to_context(d->vctx, vs->codecpar);
    if (avcodec_open2(d->vctx, vcodec, nullptr) < 0) {
        Mp4_Close(d);
        return nullptr;
    }
    d->width     = d->vctx->width;
    d->height    = d->vctx->height;
    d->vTimeBase = vs->time_base;
    d->fps       = (vs->avg_frame_rate.num && vs->avg_frame_rate.den) ? av_q2d(vs->avg_frame_rate) : 30.0;

    // convert whatever the source pixel format is -> tight YUV420P
    d->sws = sws_getContext(d->width, d->height, d->vctx->pix_fmt, d->width, d->height, AV_PIX_FMT_YUV420P, SWS_BILINEAR, nullptr, nullptr,
                            nullptr);
    if (!d->sws) {
        Mp4_Close(d);
        return nullptr;
    }

    // --- audio decoder (optional) ---
    if (d->aStream >= 0) {
        AVStream *as          = d->fmt->streams[d->aStream];
        const AVCodec *acodec = avcodec_find_decoder(as->codecpar->codec_id);
        if (acodec) {
            d->actx = avcodec_alloc_context3(acodec);
            avcodec_parameters_to_context(d->actx, as->codecpar);
            if (avcodec_open2(d->actx, acodec, nullptr) < 0) {
                avcodec_free_context(&d->actx);
                d->actx = nullptr;
            }
        }
        if (d->actx) {
            // resample to interleaved float stereo @ 48000 Hz (what ogv_stream wants)
            AVChannelLayout outLayout;
            av_channel_layout_default(&outLayout, 2);
            if (swr_alloc_set_opts2(&d->swr, &outLayout, AV_SAMPLE_FMT_FLT, 48000, &d->actx->ch_layout, d->actx->sample_fmt,
                                    d->actx->sample_rate, 0, nullptr)
                    < 0
                || swr_init(d->swr) < 0) {
                if (d->swr)
                    swr_free(&d->swr);
                avcodec_free_context(&d->actx);
                d->actx = nullptr;
            }
            av_channel_layout_uninit(&outLayout);
        }
    }

    d->worker = std::thread(decodeThread, d);
    return d;
}

void Mp4_Close(Mp4Decoder *d)
{
    if (!d)
        return;
    d->stop.store(true);
    if (d->worker.joinable())
        d->worker.join();

    for (auto *f : d->videoQ) Mp4_FreeVideo(f);
    for (auto *p : d->audioQ) Mp4_FreeAudio(p);
    d->videoQ.clear();
    d->audioQ.clear();

    if (d->sws)
        sws_freeContext(d->sws);
    if (d->swr)
        swr_free(&d->swr);
    if (d->vctx)
        avcodec_free_context(&d->vctx);
    if (d->actx)
        avcodec_free_context(&d->actx);
    if (d->fmt)
        avformat_close_input(&d->fmt);
    delete d;
}

int Mp4_Width(Mp4Decoder *d) { return d ? d->width : 0; }
int Mp4_Height(Mp4Decoder *d) { return d ? d->height : 0; }
double Mp4_FPS(Mp4Decoder *d) { return d ? d->fps : 30.0; }

bool Mp4_IsDecoding(Mp4Decoder *d)
{
    if (!d)
        return false;
    if (!d->finished.load())
        return true;
    std::lock_guard<std::mutex> lk(d->mtx);
    return !d->videoQ.empty(); // video-driven: done once decode finished and frames drained
}

Mp4VideoFrame *Mp4_GetVideo(Mp4Decoder *d)
{
    if (!d)
        return nullptr;
    std::lock_guard<std::mutex> lk(d->mtx);
    if (d->videoQ.empty())
        return nullptr;
    Mp4VideoFrame *f = d->videoQ.front();
    d->videoQ.pop_front();
    return f;
}

void Mp4_FreeVideo(Mp4VideoFrame *f)
{
    if (!f)
        return;
    free(f->pixels);
    free(f);
}

Mp4AudioPacket *Mp4_GetAudio(Mp4Decoder *d)
{
    if (!d)
        return nullptr;
    std::lock_guard<std::mutex> lk(d->mtx);
    if (d->audioQ.empty())
        return nullptr;
    Mp4AudioPacket *p = d->audioQ.front();
    d->audioQ.pop_front();
    return p;
}

void Mp4_FreeAudio(Mp4AudioPacket *p)
{
    if (!p)
        return;
    free(p->samples);
    free(p);
}

#endif // RETRO_USE_MP4
