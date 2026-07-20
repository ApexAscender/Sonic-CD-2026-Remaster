#ifndef O_MISSION_BOSS_LEGJOINT2_H
#define O_MISSION_BOSS_LEGJOINT2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_Boss_LegJoint2 {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void BossLegJoint2_JointRotation();
void BossLegJoint2_HandleMovement();
void BossLegJoint2_HandleLanding();
extern const Native::NativeFunctionDef funcs[3];
}

#endif
#endif // O_MISSION_BOSS_LEGJOINT2_H
