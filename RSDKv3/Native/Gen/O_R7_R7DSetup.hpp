#ifndef O_R7_R7DSETUP_H
#define O_R7_R7DSETUP_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R7_R7DSetup {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void R7Setup_GetLoopTileInfo();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R7_R7DSETUP_H
