#ifndef O_R1_BOSS_LEG_H
#define O_R1_BOSS_LEG_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_Boss_Leg {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void BossLeg_SaveLegPosition();
void BossLeg_HandleMovement();
extern const Native::NativeFunctionDef funcs[2];
}

#endif
#endif // O_R1_BOSS_LEG_H
