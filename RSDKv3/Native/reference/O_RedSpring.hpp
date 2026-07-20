#ifndef O_REDSPRING_H
#define O_REDSPRING_H

// =============================================================================
//  Red Spring  (Global/RedSpring.txt)  ->  native C++
// -----------------------------------------------------------------------------
//  Faithful translation of the standalone (PC) script path. Origins-only and
//  Haptics-only blocks (#platform: Use_Origins / Use_Haptics) are intentionally
//  omitted because this decomp targets the standalone build; each omission is
//  marked in the .cpp.
//
//  Local variable map (from the script's #alias header):
//     Object.Value0 -> ActiveSpringFrame  (recoil animation counter)
//     Object.Value2 -> Unused             (Origins Plus leftover)
//     Object.Value7 -> EnabledInAir       (horizontal springs only)
//  Player.Value7    -> AnimationReserve
// =============================================================================

#if RETRO_USE_NATIVE_OBJECTS

namespace O_RedSpring
{
// Script subs, one member per ObjectXxx sub. Signature matches NativeObjectSub.
void PlayerInteraction();
void Draw();
void Setup(); // ObjectStartup

// Named indices into Object.values[] — self-documenting replacements for value0/7.
enum { VAL_ACTIVE_SPRING_FRAME = 0, VAL_UNUSED = 2, VAL_ENABLED_IN_AIR = 7 };

// PropertyValue meanings (facing direction), straight from the script aliases.
enum SpringFacing {
    FACE_UP          = 0,
    FACE_RIGHT       = 1,
    FACE_LEFT        = 2,
    FACE_DOWN        = 3,
    FACE_DIAGONAL_UR = 4,
    FACE_DIAGONAL_UL = 5,
    FACE_DIAGONAL_DR = 6,
    FACE_DIAGONAL_DL = 7,
};
} // namespace O_RedSpring

#endif // RETRO_USE_NATIVE_OBJECTS
#endif // !O_REDSPRING_H
