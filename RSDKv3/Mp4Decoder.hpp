#ifndef MP4_DECODER_H
#define MP4_DECODER_H

// =============================================================================
//  MP4 (H.264 + AAC) decoder for the RSDKv3 video path (SonicCD-Native).
// -----------------------------------------------------------------------------
//  Lets the engine play .mp4 files anywhere it plays .ogv, so you can drop an
//  mp4 straight in (e.g. videos/intro.mp4) with no conversion. It mirrors the
//  small slice of the theoraplay interface the engine actually uses:
//    * a background thread demuxes + decodes into thread-safe queues
//    * video -> tightly packed YUV420p frames (feed SDL_UpdateYUVTexture as-is)
//    * audio -> float32 stereo @ 48000 Hz packets (feed ogv_stream as-is)
//  so Video.cpp / Audio.cpp only need a decoder branch, not a new pipeline.
//
//  Built only when RETRO_USE_MP4 is defined (links FFmpeg libav*).
// =============================================================================

#if RETRO_USE_MP4

struct Mp4Decoder; // opaque

// A decoded video frame. `pixels` is tightly packed IYUV: Y (w*h), then U
// ((w/2)*(h/2)), then V (same) — identical layout to theoraplay's IYUV output.
struct Mp4VideoFrame {
    int width;
    int height;
    unsigned int playms; // presentation time in ms from video start
    unsigned char *pixels;
};

// Decoded audio: interleaved float32 stereo at 48000 Hz. `frames` = sample-frames.
struct Mp4AudioPacket {
    int frames;
    float *samples;
};

// Open an mp4 and start decoding. Returns null on failure (bad file / no video).
Mp4Decoder *Mp4_Open(const char *path);
void Mp4_Close(Mp4Decoder *dec);

int Mp4_Width(Mp4Decoder *dec);
int Mp4_Height(Mp4Decoder *dec);
double Mp4_FPS(Mp4Decoder *dec);

// True while frames may still arrive (decoding, or queued output remains).
bool Mp4_IsDecoding(Mp4Decoder *dec);

// Pull the next queued video frame / audio packet, or null if none ready yet.
// Ownership transfers to the caller; free with the matching Free call.
Mp4VideoFrame *Mp4_GetVideo(Mp4Decoder *dec);
void Mp4_FreeVideo(Mp4VideoFrame *frame);
Mp4AudioPacket *Mp4_GetAudio(Mp4Decoder *dec);
void Mp4_FreeAudio(Mp4AudioPacket *pkt);

#endif // RETRO_USE_MP4
#endif // !MP4_DECODER_H
