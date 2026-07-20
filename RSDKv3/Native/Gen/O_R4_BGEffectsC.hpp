#ifndef O_R4_BGEFFECTSC_H
#define O_R4_BGEFFECTSC_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_BGEffectsC {
void ObjectStartup();
void ObjectDraw();
void BGEffects_Deform_Left();
void BGEffects_Deform_Right();
extern const Native::NativeFunctionDef funcs[2];
}

#endif
#endif // O_R4_BGEFFECTSC_H
