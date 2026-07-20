#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_InvisibleBarrier.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from InvisibleBarrier.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_InvisibleBarrier::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pAnimation() != GVar("ANI_LEDGEPULLUP")) {
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
            switch (self->propertyValue) {
                case 1:
                pYPos() = pCollisionTop();
                pYPos() <<= 16;
                pYPos() += self->YPos;
                pYPos() -= 0x100000;
                break;
                case 2:
                pYPos() = pCollisionBottom();
                pYPos() <<= 16;
                pYPos() += self->YPos;
                pYPos() += 0x300000;
                break;
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
