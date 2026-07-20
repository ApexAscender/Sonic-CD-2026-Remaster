#ifndef O_MISSION_BOSS_ARM2_H
#define O_MISSION_BOSS_ARM2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_Boss_Arm2 {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void BossArm2_HandleArmMovement();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MISSION_BOSS_ARM2_H
