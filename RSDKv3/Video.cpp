#include "RetroEngine.hpp"
#include <string>

int currentVideoFrame = 0;
int videoFrameCount   = 0;
int videoWidth        = 0;
int videoHeight       = 0;
float videoAR         = 0;

THEORAPLAY_Decoder *videoDecoder;
const THEORAPLAY_VideoFrame *videoVidData;
THEORAPLAY_Io callbacks;

byte videoSurface = 0;
int videoFilePos  = 0;
int videoPlaying  = 0;
int vidFrameMS    = 0;
int vidBaseticks  = 0;

bool videoSkipped = false;

#if RETRO_USE_MP4
bool videoIsMp4       = false;
Mp4Decoder *mp4Decoder = nullptr;

// Play an .mp4 via the libav decoder, reusing the engine's video pipeline
// (YUV420p frames -> videoBuffer, float-stereo audio -> ogv_stream). Returns
// true if the mp4 opened and playback started.
static bool TryPlayMp4(const char *filePath)
{
    char pathBuffer[0x100];
    StrCopy(pathBuffer, "videos/");
    StrAdd(pathBuffer, filePath);
    StrAdd(pathBuffer, ".mp4");

    FileIO *probe = fOpen(pathBuffer, "rb");
    if (!probe)
        return false;
    fClose(probe);

    mp4Decoder = Mp4_Open(pathBuffer);
    if (!mp4Decoder) {
        PrintLog("MP4 decoder failed to open '%s'", pathBuffer);
        return false;
    }

    PrintLog("Playing MP4 '%s'!", pathBuffer);
    videoWidth  = Mp4_Width(mp4Decoder);
    videoHeight = Mp4_Height(mp4Decoder);
    videoAR     = float(videoWidth) / float(videoHeight);

    SetupVideoBuffer(videoWidth, videoHeight);
    vidBaseticks = SDL_GetTicks();
    double fps   = Mp4_FPS(mp4Decoder);
    vidFrameMS   = (fps <= 0.0) ? 0 : (int)(1000.0 / fps);
    videoPlaying = 1;
    videoIsMp4   = true;
    trackID      = TRACK_COUNT - 1;
    videoSkipped = false;
    Engine.gameMode = ENGINE_VIDEOWAIT;
    return true;
}
#endif

static long videoRead(THEORAPLAY_Io *io, void *buf, long buflen)
{
    FileIO *file    = (FileIO *)io->userdata;
    const size_t br = fRead(buf, 1, buflen * sizeof(byte), file);
    if (br == 0)
        return -1;
    return (int)br;
} // IoFopenRead

static void videoClose(THEORAPLAY_Io *io)
{
    FileIO *file = (FileIO *)io->userdata;
    fClose(file);
}

void PlayVideoFile(char *filePath)
{
    char pathBuffer[0x100];
    int len = StrLength(filePath);

    if (StrComp(filePath + ((size_t)len - 2), "us")) {
        filePath[len - 2] = 0;
    }

#if RETRO_USE_MP4
    // Prefer an .mp4 of the same name if present (drop-in mp4 support); fall
    // back to the .ogv theora path below.
    if (TryPlayMp4(filePath))
        return;
#endif

    StrCopy(pathBuffer, "videos/");
    StrAdd(pathBuffer, filePath);
    StrAdd(pathBuffer, ".ogv");

    bool addPath = true;
    // Fixes ".ani" ".Ani" bug and any other case differences
    char pathLower[0x100];
    memset(pathLower, 0, sizeof(char) * 0x100);
    for (int c = 0; c < strlen(pathBuffer); ++c) {
        pathLower[c] = tolower(pathBuffer[c]);
    }

#if RETRO_USE_MOD_LOADER
    for (int m = 0; m < modList.size(); ++m) {
        if (modList[m].active) {
            std::map<std::string, std::string>::const_iterator iter = modList[m].fileMap.find(pathLower);
            if (iter != modList[m].fileMap.cend()) {
                StrCopy(pathBuffer, iter->second.c_str());
                Engine.forceFolder   = true;
                Engine.usingDataFile = false;
                addPath              = false;
                break;
            }
        }
    }
#endif

    char filepath[0x100];
    if (addPath) {
#if RETRO_PLATFORM == RETRO_UWP
        static char resourcePath[256] = { 0 };

        if (strlen(resourcePath) == 0) {
            auto folder = winrt::Windows::Storage::ApplicationData::Current().LocalFolder();
            auto path   = to_string(folder.Path());

            std::copy(path.begin(), path.end(), resourcePath);
        }

        sprintf(filepath, "%s/%s", resourcePath, pathBuffer);
#elif RETRO_PLATFORM == RETRO_OSX || RETRO_PLATFORM == RETRO_ANDROID
        sprintf(filepath, "%s/%s", gamePath, pathBuffer);
#else
        sprintf(filepath, "%s%s", BASE_PATH, pathBuffer);
#endif
    }
    else {
        sprintf(filepath, "%s", pathBuffer);
    }

    FileIO *file = fOpen(filepath, "rb");
    if (file) {
        PrintLog("Loaded File '%s'!", filepath);

        callbacks.read     = videoRead;
        callbacks.close    = videoClose;
        callbacks.userdata = (void *)file;
#if RETRO_USING_SDL2 && !RETRO_USING_OPENGL
        videoDecoder = THEORAPLAY_startDecode(&callbacks, /*FPS*/ 30, THEORAPLAY_VIDFMT_IYUV, GetGlobalVariableByName("Options.Soundtrack") ? 1 : 0);
#endif

        // TODO: does SDL1.2 support YUV?
#if RETRO_USING_SDL1 && !RETRO_USING_OPENGL
        videoDecoder = THEORAPLAY_startDecode(&callbacks, /*FPS*/ 30, THEORAPLAY_VIDFMT_RGBA, GetGlobalVariableByName("Options.Soundtrack") ? 1 : 0);
#endif

#if RETRO_USING_OPENGL
        videoDecoder = THEORAPLAY_startDecode(&callbacks, /*FPS*/ 30, THEORAPLAY_VIDFMT_RGBA, GetGlobalVariableByName("Options.Soundtrack") ? 1 : 0);
#endif

        if (!videoDecoder) {
            PrintLog("Video Decoder Error!");
            return;
        }
        while (!videoVidData) {
            if (!videoVidData)
                videoVidData = THEORAPLAY_getVideo(videoDecoder);
        }
        if (!videoVidData) {
            PrintLog("Video Error!");
            return;
        }

        videoWidth  = videoVidData->width;
        videoHeight = videoVidData->height;
        // commit video Aspect Ratio.
        videoAR = float(videoWidth) / float(videoHeight);

        SetupVideoBuffer(videoWidth, videoHeight);
        vidBaseticks = SDL_GetTicks();
        vidFrameMS   = (videoVidData->fps == 0.0) ? 0 : ((Uint32)(1000.0 / videoVidData->fps));
        videoPlaying = 1; // playing ogv
        trackID      = TRACK_COUNT - 1;

        videoSkipped    = false;
        Engine.gameMode = ENGINE_VIDEOWAIT;
    }
    else {
        PrintLog("Couldn't find file '%s'!", filepath);
    }
}

void UpdateVideoFrame()
{
    if (videoPlaying == 2) {
        if (currentVideoFrame < videoFrameCount) {
            GFXSurface *surface = &gfxSurface[videoSurface];
            byte fileBuffer     = 0;
            ushort fileBuffer2  = 0;
            FileRead(&fileBuffer, 1);
            videoFilePos += fileBuffer;
            FileRead(&fileBuffer, 1);
            videoFilePos += fileBuffer << 8;
            FileRead(&fileBuffer, 1);
            videoFilePos += fileBuffer << 16;
            FileRead(&fileBuffer, 1);
            videoFilePos += fileBuffer << 24;

            byte clr[3];
            for (int i = 0; i < 0x80; ++i) {
                FileRead(&clr, 3);
                activePalette32[i].r = clr[0];
                activePalette32[i].g = clr[1];
                activePalette32[i].b = clr[2];
                activePalette[i]     = ((ushort)(clr[0] >> 3) << 11) | 32 * (clr[1] >> 2) | (clr[2] >> 3);
            }

            FileRead(&fileBuffer, 1);
            while (fileBuffer != ',') FileRead(&fileBuffer, 1); // gif image start identifier

            FileRead(&fileBuffer2, 2); // IMAGE LEFT
            FileRead(&fileBuffer2, 2); // IMAGE TOP
            FileRead(&fileBuffer2, 2); // IMAGE WIDTH
            FileRead(&fileBuffer2, 2); // IMAGE HEIGHT
            FileRead(&fileBuffer, 1);  // PaletteType
            bool interlaced = (fileBuffer & 0x40) >> 6;
            if (fileBuffer >> 7 == 1) {
                int c = 0x80;
                do {
                    ++c;
                    FileRead(&fileBuffer, 1);
                    FileRead(&fileBuffer, 1);
                    FileRead(&fileBuffer, 1);
                } while (c != 0x100);
            }
            ReadGifPictureData(surface->width, surface->height, interlaced, graphicData, surface->dataPosition);

            SetFilePosition(videoFilePos);
            ++currentVideoFrame;
        }
        else {
            videoPlaying = 0;
            CloseFile();
        }
    }
}

int ProcessVideo()
{
    if (videoPlaying == 1) {
        CheckKeyPress(&keyPress, 0xFF);

        if (videoSkipped && fadeMode < 0xFF) {
            fadeMode += 8;
        }

        if (anyPress || touches > 0) {
            if (!videoSkipped)
                fadeMode = 0;

            videoSkipped = true;
        }

#if RETRO_USE_MP4
        if (videoIsMp4) {
            static Mp4VideoFrame *mp4Pending = nullptr;

            if (!Mp4_IsDecoding(mp4Decoder) || (videoSkipped && fadeMode >= 0xFF)) {
                if (mp4Pending) {
                    Mp4_FreeVideo(mp4Pending);
                    mp4Pending = nullptr;
                }
                StopVideoPlayback();
                ResumeSound();
                return 1; // video finished
            }

            const Uint32 now = (SDL_GetTicks() - vidBaseticks);
            if (!mp4Pending)
                mp4Pending = Mp4_GetVideo(mp4Decoder);

            // Only advance when the frame is due; drop frames to catch up if
            // we're running behind (same policy as the theora path).
            if (mp4Pending && mp4Pending->playms <= now) {
                if (vidFrameMS && (now - mp4Pending->playms) >= (Uint32)vidFrameMS) {
                    Mp4VideoFrame *next;
                    while ((next = Mp4_GetVideo(mp4Decoder)) != nullptr) {
                        Mp4_FreeVideo(mp4Pending);
                        mp4Pending = next;
                        if ((now - mp4Pending->playms) < (Uint32)vidFrameMS)
                            break;
                    }
                }

                int half_w     = mp4Pending->width / 2;
                const Uint8 *y = (const Uint8 *)mp4Pending->pixels;
                const Uint8 *u = y + (mp4Pending->width * mp4Pending->height);
                const Uint8 *v = u + (half_w * (mp4Pending->height / 2));
                SDL_UpdateYUVTexture(Engine.videoBuffer, NULL, y, mp4Pending->width, u, half_w, v, half_w);

                Mp4_FreeVideo(mp4Pending);
                mp4Pending = nullptr;
            }
            return 2; // playing
        }
#endif

        if (!THEORAPLAY_isDecoding(videoDecoder) || (videoSkipped && fadeMode >= 0xFF)) {
            StopVideoPlayback();
            ResumeSound();
            return 1; // video finished
        }

        // Don't pause or it'll go wild
        if (videoPlaying == 1) {
            const Uint32 now = (SDL_GetTicks() - vidBaseticks);

            if (!videoVidData)
                videoVidData = THEORAPLAY_getVideo(videoDecoder);

            // Play video frames when it's time.
            if (videoVidData && (videoVidData->playms <= now)) {
                if (vidFrameMS && ((now - videoVidData->playms) >= vidFrameMS)) {

                    // Skip frames to catch up, but keep track of the last one+
                    //  in case we catch up to a series of dupe frames, which
                    //  means we'd have to draw that final frame and then wait for
                    //  more.

                    const THEORAPLAY_VideoFrame *last = videoVidData;
                    while ((videoVidData = THEORAPLAY_getVideo(videoDecoder)) != NULL) {
                        THEORAPLAY_freeVideo(last);
                        last = videoVidData;
                        if ((now - videoVidData->playms) < vidFrameMS)
                            break;
                    }

                    if (!videoVidData)
                        videoVidData = last;
                }

                // do nothing; we're far behind and out of options.
                if (!videoVidData) {
                    // video lagging uh oh
                }

#if RETRO_USING_OPENGL
                glBindTexture(GL_TEXTURE_2D, videoBuffer);
                glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, videoVidData->width, videoVidData->height, GL_RGBA, GL_UNSIGNED_BYTE, videoVidData->pixels);
                glBindTexture(GL_TEXTURE_2D, 0);
#elif RETRO_USING_SDL2
                int half_w     = videoVidData->width / 2;
                const Uint8 *y = (const Uint8 *)videoVidData->pixels;
                const Uint8 *u = y + (videoVidData->width * videoVidData->height);
                const Uint8 *v = u + (half_w * (videoVidData->height / 2));

                SDL_UpdateYUVTexture(Engine.videoBuffer, NULL, y, videoVidData->width, u, half_w, v, half_w);
#elif RETRO_USING_SDL1
                memcpy(Engine.videoBuffer->pixels, videoVidData->pixels, videoVidData->width * videoVidData->height * sizeof(uint));
#endif

                THEORAPLAY_freeVideo(videoVidData);
                videoVidData = NULL;
            }

            return 2; // its playing as expected
        }
    }

    return 0; // its not even initialised
}

void StopVideoPlayback()
{
    if (videoPlaying == 1) {
        // `videoPlaying` and the decoder are read by the audio thread, so lock
        // it to prevent a race that results in invalid memory accesses.
        SDL_LockAudio();

        if (videoSkipped && fadeMode >= 0xFF)
            fadeMode = 0;

#if RETRO_USE_MP4
        if (videoIsMp4) {
            // stop feeding audio before tearing the decoder down
            videoPlaying = 0;
            videoIsMp4   = false;
            Mp4Decoder *d = mp4Decoder;
            mp4Decoder    = nullptr;
            SDL_UnlockAudio();
            Mp4_Close(d); // joins the decode thread outside the audio lock
            CloseVideoBuffer();
            return;
        }
#endif

        if (videoVidData) {
            THEORAPLAY_freeVideo(videoVidData);
            videoVidData = NULL;
        }
        if (videoDecoder) {
            THEORAPLAY_stopDecode(videoDecoder);
            videoDecoder = NULL;
        }

        CloseVideoBuffer();
        videoPlaying = 0;

        SDL_UnlockAudio();
    }
}

void SetupVideoBuffer(int width, int height)
{
#if RETRO_USING_OPENGL
    if (videoBuffer > 0) {
        glDeleteTextures(1, &videoBuffer);
        videoBuffer = 0;
    }
    glGenTextures(1, &videoBuffer);
    glBindTexture(GL_TEXTURE_2D, videoBuffer);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, videoVidData->width, videoVidData->height, GL_RGBA, GL_UNSIGNED_BYTE, videoVidData->pixels);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_2D, 0);
#elif RETRO_USING_SDL1
    Engine.videoBuffer = SDL_CreateRGBSurface(0, width, height, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);

    if (!Engine.videoBuffer)
        PrintLog("Failed to create video buffer!");
#elif RETRO_USING_SDL2
    Engine.videoBuffer = SDL_CreateTexture(Engine.renderer, SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STREAMING, width, height);

    if (!Engine.videoBuffer)
        PrintLog("Failed to create video buffer!");
#endif
}

void CloseVideoBuffer()
{
    if (videoPlaying == 1) {
#if RETRO_USING_OPENGL
        if (videoBuffer > 0) {
            glDeleteTextures(1, &videoBuffer);
            videoBuffer = 0;
        }
#elif RETRO_USING_SDL1
        SDL_FreeSurface(Engine.videoBuffer);
        Engine.videoBuffer = nullptr;
#elif RETRO_USING_SDL2
        SDL_DestroyTexture(Engine.videoBuffer);
        Engine.videoBuffer = nullptr;
#endif
    }
}
