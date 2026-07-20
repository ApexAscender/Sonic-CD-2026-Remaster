#ifndef O_R1_BOSS_FOOT_H
#define O_R1_BOSS_FOOT_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_Boss_Foot {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void BossFoot_HandleMovement();
void BossFoot_StepEarthQuake();
void BossFoot_SaveFootPosition();
void BossFoot_Unused();
extern const Native::NativeFunctionDef funcs[4];
}

#endif
#endif // O_R1_BOSS_FOOT_H
