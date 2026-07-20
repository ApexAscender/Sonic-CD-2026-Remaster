#ifndef O_R7_METALSONIC_H
#define O_R7_METALSONIC_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R7_MetalSonic {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void MetalSonic_FollowGround();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R7_METALSONIC_H
