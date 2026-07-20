#ifndef O_R1_BOSS_LEGJOINT_H
#define O_R1_BOSS_LEGJOINT_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_Boss_LegJoint {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void BossLegJoint_JointRotation();
void BossLegJoint_HandleMovement();
void BossLegJoint_HandleLanding();
extern const Native::NativeFunctionDef funcs[3];
}

#endif
#endif // O_R1_BOSS_LEGJOINT_H
