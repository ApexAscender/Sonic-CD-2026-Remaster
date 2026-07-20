#ifndef O_R4_BGEFFECTSD_H
#define O_R4_BGEFFECTSD_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_BGEffectsD {
void ObjectStartup();
void ObjectDraw();
void BGEffects_Deform_Left();
void BGEffects_Deform_Right();
extern const Native::NativeFunctionDef funcs[2];
}

#endif
#endif // O_R4_BGEFFECTSD_H
