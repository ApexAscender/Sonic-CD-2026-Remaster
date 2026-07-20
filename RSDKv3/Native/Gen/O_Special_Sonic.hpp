#ifndef O_SPECIAL_SONIC_H
#define O_SPECIAL_SONIC_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Special_Sonic {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void Sonic_ProcessPlayer();
void Sonic_HandlePause();
void Sonic_HandleMovement();
void Sonic_ProcessAnimation();
void Sonic_HandleBumperInteraction();
void Sonic_HandleTileInteractions();
extern const Native::NativeFunctionDef funcs[6];
}

#endif
#endif // O_SPECIAL_SONIC_H
