#ifndef O_MISSION_BOSS_LEG2_H
#define O_MISSION_BOSS_LEG2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_Boss_Leg2 {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void BossLeg2_SaveLegPosition();
void BossLeg2_HandleMovement();
extern const Native::NativeFunctionDef funcs[2];
}

#endif
#endif // O_MISSION_BOSS_LEG2_H
