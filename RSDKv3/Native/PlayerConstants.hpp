#ifndef NATIVE_PLAYER_CONSTANTS_H
#define NATIVE_PLAYER_CONSTANTS_H

// =============================================================================
//  Player constants bridge
// -----------------------------------------------------------------------------
//  Interactive objects poke the player using symbols that the SCRIPTS treat as
//  globals but never define locally (RedSpring uses ANI_WALKING and
//  Player_State_Air without aliasing them). Those symbols resolve to:
//
//    * Player states  -> a script-function ID. `Player.State = Player_State_Air`
//      stores the ID of the #function "Player_State_Air", which the player's
//      Main later runs via CallFunction. While the PlayerObject is still
//      interpreted, we must write the *same* ID, so we look it up by name from
//      scriptFunctionList (stable per bytecode). Once PlayerObject is migrated
//      natively, swap these for direct function pointers / an enum.
//
//    * Player animations -> an index into the player's AnimationFile. Those live
//      in GameConstants.hpp (enum PlayerAnim / ANI_*).
// =============================================================================

#if RETRO_USE_NATIVE_OBJECTS

namespace Native
{
// Resolve a #function state ("Player_State_Air") to the ID the interpreter uses.
// Cached after first lookup; returns 0 (safe no-op state) if not found.
// Fallback map of player-state function IDs for the shipped Sonic CD (2011 mobile)
// bytecode. Bytecode carries no function names, so name resolution below fails and
// we use these instead. Values were captured at runtime from the live interpreted
// player (gravity + animation identify each state) — see notes per entry.
// NOTE: these are specific to this data's GlobalCode.bin; standalone-recompiled
// bytecode assigns different IDs (e.g. Air=21), which is why we can't hardcode
// blindly and why text-mode name resolution is preferred when available.
struct PlayerStateFallback {
    const char *name;
    int id;
};
static const PlayerStateFallback playerStateFallback[] = {
    { "Player_State_Air", 13 },    // gravity=AIR + anim=JUMPING
    { "Player_State_Ground", 12 }, // gravity=GROUND + anim=STOPPED/WALKING
};

// The player's state/action functions live in a native table
// (O_Players_PlayerObject::funcs[]). PlayerFuncID resolves a name to its small
// index — which fits Entity.state's byte — and CallPlayerFunc dispatches that
// index natively (no interpreter). Both are defined in O_Players_PlayerObject.cpp.
// This is what lets the native Player run with the scripts/bytecode gone.
int PlayerFuncID(const char *funcName);
void CallPlayerFunc(int id, byte sub);

inline int PlayerStateID(const char *funcName)
{
    // Native table first (available immediately — it's a static array), so state
    // IDs are the native indices the native Player dispatches against.
    int id = PlayerFuncID(funcName);
    if (id >= 0)
        return id;
    // Legacy fallbacks (only relevant while the interpreted player is still used).
    for (int i = 0; i < scriptFunctionCount; ++i) {
        if (StrComp(scriptFunctionList[i].name, funcName))
            return i;
    }
    for (const PlayerStateFallback &e : playerStateFallback) {
        if (StrComp(funcName, e.name))
            return e.id;
    }
    return 0;
}
} // namespace Native

#endif // RETRO_USE_NATIVE_OBJECTS
#endif // !NATIVE_PLAYER_CONSTANTS_H
