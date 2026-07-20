#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_InvisibleBlockNK.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from InvisibleBlockNK.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_InvisibleBlockNK::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
}

#endif // RETRO_USE_NATIVE_OBJECTS
