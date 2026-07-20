#ifndef O_R1_BOSS_ARM_H
#define O_R1_BOSS_ARM_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_Boss_Arm {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void BossArm_HandleArmMovement();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R1_BOSS_ARM_H
