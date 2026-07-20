#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_InvisibleBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from InvisibleBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_InvisibleBlock::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
    if (pGravity() == 0) {
        if (CheckResult() == 4) {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
