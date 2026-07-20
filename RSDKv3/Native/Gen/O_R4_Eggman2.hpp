#ifndef O_R4_EGGMAN2_H
#define O_R4_EGGMAN2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_Eggman2 {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void EggBubble_HandleBubbleMovement();
void EggBubble_HandleBubbleTurn();
void EggBubble_CheckShieldCondition();
void EggBubble_CheckBubbleAmount();
void EggBubble_DestroyBubbles();
void EggBubble_FireBullet();
extern const Native::NativeFunctionDef funcs[6];
}

#endif
#endif // O_R4_EGGMAN2_H
