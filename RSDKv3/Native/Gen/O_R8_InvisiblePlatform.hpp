#ifndef O_R8_INVISIBLEPLATFORM_H
#define O_R8_INVISIBLEPLATFORM_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_InvisiblePlatform {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void InvPlatform_SetMaxTimer();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R8_INVISIBLEPLATFORM_H
