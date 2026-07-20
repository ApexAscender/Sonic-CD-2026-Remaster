#ifndef O_PLAYER_H
#define O_PLAYER_H

// =============================================================================
//  Player Object  (Players/PlayerObject.txt, 4942 lines)  ->  native C++
// -----------------------------------------------------------------------------
//  The linchpin object: ~60 functions (state machine + physics). Ported bottom-up
//  and IN CHUNKS — leaf physics/state functions first, ObjectMain (the driver)
//  last, because Main dispatches every state via CallFunction(Player.State).
//
//  Field access goes through PlayerFields.hpp (pSpeed(), pAngle(), ...). Player
//  states are still script-function IDs while ObjectMain is interpreted, so this
//  object writes/reads them through the resolver cache below; once ObjectMain is
//  native, PlayerStateID can be replaced by the enum values directly.
//
//  PORT STATUS  (update as chunks land):
//    [done] State_Static, anim-speed helpers, Handle{GroundMovement,AirFriction,
//           RollDeceleration,AirMovement,OnGround}
//    [done] Action_Jump, Action_Spindash_CD, Action_Peelout_CD
//    [done] State_Ground, State_Air, State_Roll, State_LookUp, State_Crouch
//    [todo] Action_Spindash_S2/Peelout_S2/DblJumpTails (non-CD),
//           State_Spindash_CD/Peelout_CD, damage & gimmick states,
//           ObjectMain/Draw/Startup, Setup_Startup
//
//  NOT registered in NativeObject.cpp yet — porting is incomplete, so the player
//  intentionally keeps running its script until the driver (ObjectMain) is done.
// =============================================================================

#if RETRO_USE_NATIVE_OBJECTS

namespace O_Player
{
// Full state inventory (script #function order). Kept for the eventual native
// dispatch switch; today these names are resolved to script-function IDs.
enum PlayerState {
    STATE_Static,      STATE_Ground,      STATE_Air,        STATE_Roll,
    STATE_LookUp,      STATE_Crouch,      STATE_Spindash,   STATE_Peelout,
    STATE_Fly,         STATE_GotHit,      STATE_Hurt,       STATE_OuttaHere,
    STATE_Death,       STATE_Drown,       STATE_HangBar,    STATE_TubeRoll,
    STATE_TubeAirRoll, STATE_SpinningTop, STATE_Hugged,     STATE_Ramp3D,
    STATE_WaterCurrent, STATE_SizeChange,
    STATE_COUNT
};

// ---- Move starters (Sonic CD set; S2 variants + Tails deferred) --------------
void Action_Jump();
void Action_Spindash_CD();
void Action_Peelout_CD();

// ---- Core states -------------------------------------------------------------
void State_Ground();
void State_Air();
void State_Roll();
void State_LookUp();
void State_Crouch();

// ---- Physics helpers (leaf functions; operate on the active player) ----------
void State_Static();
void HandleRollAnimSpeed();
void HandleWalkAnimSpeed();
void HandleRunAnimSpeed();
void HandleGroundMovement();
void HandleAirFriction();
void HandleRollDeceleration();
void HandleAirMovement();
void HandleOnGround();

// ---- Object subs (driver — to be filled in the next chunks) ------------------
void Main();
void Draw();
void Setup();
} // namespace O_Player

#endif // RETRO_USE_NATIVE_OBJECTS
#endif // !O_PLAYER_H
