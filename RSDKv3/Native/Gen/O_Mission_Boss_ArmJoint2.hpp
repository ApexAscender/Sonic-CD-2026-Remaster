#ifndef O_MISSION_BOSS_ARMJOINT2_H
#define O_MISSION_BOSS_ARMJOINT2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_Boss_ArmJoint2 {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void BossArmJoint2_HandleMovement();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_MISSION_BOSS_ARMJOINT2_H
