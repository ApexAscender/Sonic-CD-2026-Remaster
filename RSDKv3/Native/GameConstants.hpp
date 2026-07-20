#ifndef NATIVE_GAME_CONSTANTS_H
#define NATIVE_GAME_CONSTANTS_H

// =============================================================================
//  Shared game constants  (foundation layer for the native-object migration)
// -----------------------------------------------------------------------------
//  RetroScript objects lean on names that the *scripts* never define locally
//  (RedSpring uses GRAVITY_AIR, FACING_RIGHT, ANI_WALKING, SFX_G_SPRING with no
//  #alias). In the interpreter these resolve two ways:
//    * ~32 engine "common aliases" baked into Script.cpp (C_*, FX_*, FLIP_*,
//      FACING_*, stage types, true/false) — already usable via those C++ enums.
//    * bytecode-time constants (animation indices, global SFX slots) that are
//      NOT in any header. This file is where we pin those down once, by name,
//      so every ported object reads exactly like its script.
//
//  IMPORTANT: constants that ALREADY exist as engine enums are intentionally NOT
//  redefined here (that caused a real CMODE_* redefinition clash in the first
//  RedSpring draft). Use the engine's own:
//    CMODE_* / CSIDE_*        -> Collision.hpp
//    FLIP_* / INK_* / FX_*    -> Drawing.hpp
//    PRIORITY_*               -> Object.hpp
//    C_TOUCH / C_BOX / ...    -> Collision.hpp
//    CONTROLMODE_*            -> Player.hpp
// =============================================================================

#if RETRO_USE_NATIVE_OBJECTS

namespace Native
{
// --- Gravity (Player.gravity / Object gravity flags) -------------------------
enum Gravity {
    GRAVITY_GROUND = 0,
    GRAVITY_AIR    = 1,
};

// --- Facing (Player/Entity direction). Aliases of FLIP_NONE / FLIP_X. --------
enum Facing {
    FACING_RIGHT = 0, // == FLIP_NONE
    FACING_LEFT  = 1, // == FLIP_X
};

// --- Player list positions (Stage.PlayerListPos) -----------------------------
enum PlayerListPos {
    PLAYER_SONIC_A    = 0,
    PLAYER_TAILS_A    = 1,
    PLAYER_KNUCKLES_A = 2,
    PLAYER_AMY_A      = 5,
};

// --- Damage types (passed to Player_Hit) -------------------------------------
enum DamageType {
    DAMAGE_SHIELDED = 1,
    DAMAGE_HURT     = 2,
    DAMAGE_DEATH    = 3,
};

// --- Shield status -----------------------------------------------------------
enum ShieldStatus {
    NO_SHIELD     = 0,
    ACTIVE_SHIELD = 1,
};

// --- Collision plane ---------------------------------------------------------
enum CollisionPlane {
    COLLISION_PLANE_A = 0,
};

// --- Time-warp destination (global Warp.Destination) -------------------------
enum WarpDest {
    WARPDEST_NONE = 0,
};

// --- Global SFX slots --------------------------------------------------------
//  ✅ VERIFIED against extracted GameConfig.bin (28 global SFX, 0..27, in order).
enum GlobalSfx {
    SFX_G_JUMP        = 0,
    SFX_G_RING        = 1,
    SFX_G_RING2       = 2,
    SFX_G_SKIDDING    = 3,
    SFX_G_LOSERINGS   = 4,
    SFX_G_HURT        = 5,
    SFX_G_CHARGE      = 6,
    SFX_G_RELEASE     = 7,
    SFX_G_DESTROY     = 8,
    SFX_G_LAMPPOST    = 9,
    SFX_G_BLUESHIELD  = 10,
    SFX_G_SPRING      = 11,
    SFX_G_FUTURE      = 12,
    SFX_G_PAST        = 13,
    SFX_G_TIMEWARP    = 14,
    SFX_G_SIGNPOST    = 15,
    SFX_G_SCOREADD    = 16,
    SFX_G_SCORETOTAL  = 17,
    SFX_G_SPECIALRING = 18,
    SFX_G_SPECIALWARP = 19,
    SFX_G_1UP         = 20,
    SFX_G_ACHIEVEMENT = 21,
    SFX_G_EXPLOSION   = 22,
    SFX_G_MENUBUTTON  = 23,
    SFX_G_FLYING      = 24,
    SFX_G_TIRED       = 25,
    SFX_G_OUTTAHERE   = 26,
    SFX_G_SELECT      = 27,
};

// --- Player animation indices (boundEntity->animation) -----------------------
//  Indices into the player's AnimationFile. NOT defined by any script or engine
//  header — the bytecode carries resolved integers.
//
//  ✅ VERIFIED against extracted GameConfig.bin (the ANI_* globals, indices 64+)
//     AND Data/Animations/Sonic.ani. For 0..28 the GameConfig value equals the
//     .ani file order, so these are the real, script-faithful indices.
//  NOTE: scripts resolve ANI_* through GameConfig globals, so a few later gimmick
//     anims (SpinningTop/Ramp/SizeChange) are 0 in GameConfig even though the .ani
//     has them at 36/37+/44 — intentionally omitted here until those states are
//     ported and their real script-facing value is confirmed.
enum PlayerAnim {
    ANI_STOPPED       = 0,
    ANI_WAITING       = 1,
    ANI_BORED         = 2,  // "Bored!"
    ANI_LOOKINGUP     = 3,
    ANI_LOOKINGDOWN   = 4,
    ANI_WALKING       = 5,
    ANI_RUNNING       = 6,
    ANI_SKIDDING      = 7,
    ANI_PEELOUT       = 8,  // "Super Peel Out"
    ANI_SPINDASH      = 9,  // "Spin Dash"
    ANI_JUMPING       = 10,
    ANI_BOUNCING      = 11,
    ANI_HURT          = 12,
    ANI_DYING         = 13,
    ANI_DROWNING      = 14,
    ANI_FANROTATE     = 15,
    ANI_BREATHING     = 16,
    ANI_PUSHING       = 17,
    ANI_FLAILINGLEFT  = 18,
    ANI_FLAILINGRIGHT = 19,
    ANI_SLIDING       = 20,
    ANI_HANGING       = 21,
    ANI_DROPPING      = 22,
    ANI_CLINGING      = 23,
    ANI_FLYING        = 24,
    ANI_FLYINGTIRED   = 25,
    ANI_SWIMMING      = 26,
    ANI_SWIMMINGTIRED = 27,
    ANI_LAUNCHER      = 28,
};
} // namespace Native

#endif // RETRO_USE_NATIVE_OBJECTS
#endif // !NATIVE_GAME_CONSTANTS_H
