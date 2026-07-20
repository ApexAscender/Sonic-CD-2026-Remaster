#ifndef O_SECRETS_SOUNDTEST_H
#define O_SECRETS_SOUNDTEST_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Secrets_SoundTest {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void SoundTest_PlayTrack();
void SoundTest_CheckSecret();
extern const Native::NativeFunctionDef funcs[2];
}

#endif
#endif // O_SECRETS_SOUNDTEST_H
