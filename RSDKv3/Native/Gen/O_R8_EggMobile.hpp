#ifndef O_R8_EGGMOBILE_H
#define O_R8_EGGMOBILE_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_EggMobile {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void EggMobile_StopMovement();
void EggMobile_MoveToLeft();
void EggMobile_MoveToRight();
void EggMobile_GroundSpinAscend();
void EggMobile_GroundSpinDescend();
void EggMobile_MoveLeftToCenter();
void EggMobile_MoveRightToCenter();
void EggMobile_GroundSpinLeft();
void EggMobile_GroundSpinRight();
void EggMobile_HandleWingThrowATK();
void EggMobile_WingThrowVertical();
void EggMobile_WingThrowDiagonal();
void EggMobile_RestoreWings();
void EggMobile_SetTargetDestiny();
void EggMobile_ApproachPlayer();
void EggMobile_ExtendWings();
void EggMobile_RetractWings();
void EggMobile_Hit();
void EggMobile_PreparePogoAttack();
void EggMobile_PogoAttackDescend();
void EggMobile_PogoAttackAscend();
void EggMobile_PogoAttackMoveLeft();
void EggMobile_PogoAttackMoveRight();
void Helper1Controller_FourWings();
void Helper1Controller_ThreeWings();
void Helper1Controller_TwoWings();
void Helper1Controller_OneWing();
void EggMobile_Destroyed();
void EggMobile_Destroyed_FinalFever();
void EggMobile_HandleWingRotation();
void EggMobile_DropDamagedWing();
void EggMobile_HandleAnimations();
extern const Native::NativeFunctionDef funcs[32];
}

#endif
#endif // O_R8_EGGMOBILE_H
