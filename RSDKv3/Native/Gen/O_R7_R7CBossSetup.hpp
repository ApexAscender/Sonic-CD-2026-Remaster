#ifndef O_R7_R7CBOSSSETUP_H
#define O_R7_R7CBOSSSETUP_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R7_R7CBossSetup {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
void R7Setup_GetLoopTileInfo();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R7_R7CBOSSSETUP_H
