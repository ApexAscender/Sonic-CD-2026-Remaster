#ifndef O_MISSION_BOSS_BODY2_H
#define O_MISSION_BOSS_BODY2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_Boss_Body2 {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void BossBody2_RestoreNormalSpeed();
void BossBody2_SetLegPosSaveTrue();
void BossBody2_SetLegPosSaveFalse();
void BossBody2_SwitchLeg();
void BossBody2_SwitchLeg_Revert();
void BossBody2_MoveRArmToFront();
void BossBody2_MoveLArmToFront();
void BossBody2_HandleCharge();
void BossBody2_SetArmsToCharge();
extern const Native::NativeFunctionDef funcs[9];
}

#endif
#endif // O_MISSION_BOSS_BODY2_H
