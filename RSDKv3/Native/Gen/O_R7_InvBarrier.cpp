#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_InvBarrier.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from InvBarrier.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_InvBarrier::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pAngle() == 0) {
        PlayerObjectCollision(C_TOUCH, -16, -14, 16, 16);
        if (CheckResult() == 1) {
            pXPos() = pCollisionLeft();
            pXPos() <<= 16;
            pXPos() += self->XPos;
            pXPos() -= 0x100000;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
