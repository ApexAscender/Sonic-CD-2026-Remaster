#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_InvisibleBarrier.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from InvisibleBarrier.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_InvisibleBarrier::ObjectStartup()
{
    if (playerListPos == 0) {
        scriptEng.arrayPosition[0] = 32;
        while (scriptEng.arrayPosition[0] < 1056) {
            scriptEng.arrayPosition[0]++;
        }
    }
}

void O_R7_InvisibleBarrier::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (GVar("PathSwap_Flag") == 0) {
        PlayerObjectCollision(C_TOUCH, -16, -14, 16, 16);
        if (CheckResult() == 1) {
            if (pXPos() < self->XPos) {
                pXPos() = pCollisionLeft();
                pXPos() <<= 16;
                pXPos() += self->XPos;
                pXPos() -= 0x100000;
            } else {
                pXPos() = pCollisionRight();
                pXPos() <<= 16;
                pXPos() += self->XPos;
                pXPos() += 0x100000;
            }
            pSpeed() = 0;
            pXVel() = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
