#ifndef O_PLAYERS_PLAYEROBJECT_H
#define O_PLAYERS_PLAYEROBJECT_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Players_PlayerObject {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void Player_BadnikBreak();
void Player_Hit();
void Player_ClimbBlock();
void Player_Unstick();
void Player_CancelClimb();
void Player_ForceNoGrip();
void Player_ForceGrip();
void Player_Kill();
void Player_ProcessUpdate();
void Player_State_Static();
void Player_HandleRollAnimSpeed();
void Player_HandleWalkAnimSpeed();
void Player_HandleRunAnimSpeed();
void Player_HandleGroundMovement();
void Player_HandleAirFriction();
void Player_HandleRollDeceleration();
void Player_HandleAirMovement();
void Player_HandleOnGround();
void Player_Action_Jump();
void Player_Action_Spindash_S2();
void Player_Action_Spindash_CD();
void Player_Action_Peelout_S2();
void Player_Action_Peelout_CD();
void Player_Action_DblJumpTails();
void Player_State_Ground();
void Player_State_Air_NoDropDash();
void Player_State_Air();
void Player_State_Roll();
void Player_State_RollJump();
void Player_State_LookUp();
void Player_State_Crouch();
void Player_State_Spindash_S2();
void Player_State_Spindash_CD();
void Player_State_Peelout_S2();
void Player_State_Peelout_CD();
void Player_State_Fly();
void Player_State_GotHit();
void Player_State_Hurt();
void Player_State_OuttaHere();
void Player_State_Death();
void Player_State_Drown();
void Player_State_HangBar();
void Player_State_CorkscrewRun();
void Player_State_CorkscrewRoll();
void Player_State_TubeRoll();
void Player_State_TubeAirRoll();
void Player_State_SpinningTop();
void Player_State_Hugged();
void Player_State_Ramp3D();
void Player_State_WaterCurrent();
void Player_SetJumpOffset();
void Player_State_SizeChange();
void Player_HandleDropDash();
void Player_Action_DblJumpKnux();
void Player_State_GlideLeft();
void Player_State_GlideRight();
void Player_State_GlideDrop();
void Player_State_GlideSlide();
void Player_State_Climb();
void Player_State_LedgePullUp();
void Player_State_GlideLeftNoGrip();
void Player_State_GlideRightNoGrip();
void Player_CheckRoofGlide();
void Player_Action_GlideDrop();
void Player_Action_DblJumpAmy();
void Player_Action_HammerDash();
void Player_State_HammerDash();
void Player_SetHammerDashSpeed();
void Player_Setup_Startup();
extern const Native::NativeFunctionDef funcs[69];
}

#endif
#endif // O_PLAYERS_PLAYEROBJECT_H
