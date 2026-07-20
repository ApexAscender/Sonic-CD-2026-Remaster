#ifndef O_MISSION_BOSS_FOOT2_H
#define O_MISSION_BOSS_FOOT2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_Boss_Foot2 {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void BossFoot2_HandleMovement();
void BossFoot2_StepEarthQuake();
void BossFoot2_SaveFootPosition();
void BossFoot2_Unused();
void BossFoot2_CheckStepHeight();
extern const Native::NativeFunctionDef funcs[5];
}

#endif
#endif // O_MISSION_BOSS_FOOT2_H
