#ifndef O_R6_BOSSFLOORCONTROL_H
#define O_R6_BOSSFLOORCONTROL_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R6_BossFloorControl {
void ObjectMain();
void FloorControl_SpawnRubble();
void FloorControl_SpawnPlatFarLeft();
void FloorControl_SpawnPlatLeft();
void FloorControl_SpawnPlatRight();
void FloorControl_SpawnPlatFarRight();
extern const Native::NativeFunctionDef funcs[5];
}

#endif
#endif // O_R6_BOSSFLOORCONTROL_H
