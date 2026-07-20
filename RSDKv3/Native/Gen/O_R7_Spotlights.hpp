#ifndef O_R7_SPOTLIGHTS_H
#define O_R7_SPOTLIGHTS_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R7_Spotlights {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void Spotlights_UpdateCorner();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R7_SPOTLIGHTS_H
