#ifndef O_R1_RAMP3D_H
#define O_R1_RAMP3D_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_Ramp3D {
void ObjectStartup();
void ObjectPlayerInteraction();
void Ramp3D_SetPlayerLaunch();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R1_RAMP3D_H
