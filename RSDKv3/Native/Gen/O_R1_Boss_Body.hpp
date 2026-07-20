#ifndef O_R1_BOSS_BODY_H
#define O_R1_BOSS_BODY_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_Boss_Body {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void BossBody_RestoreNormalSpeed();
void BossBody_SetLegPosSaveTrue();
void BossBody_SetLegPosSaveFalse();
void BossBody_SwitchLeg();
void BossBody_SwitchLeg_Revert();
void BossBody_MoveRArmToFront();
void BossBody_MoveLArmToFront();
void BossBody_HandleCharge();
void BossBody_SetArmsToCharge();
extern const Native::NativeFunctionDef funcs[9];
}

#endif
#endif // O_R1_BOSS_BODY_H
