#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_HangingTrigger.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HangingTrigger.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_HangingTrigger::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -8, -2, 8, 20);
    if (pYVel() > -1) {
        if (pXPos() > self->XPos) {
            if (CheckResult() == 1) {
                if (pAnimation() != GVar("ANI_HANGING")) {
                    pState() = PlayerStateID("Player_State_HangBar");
                    pYVel() = 0;
                    pAnimation() = GVar("ANI_HANGING");
                    pYPos() = pCollisionTop();
                    pYPos() *= -0x10000;
                    pYPos() += self->YPos;
                    PlaySfx(globalSFXCount + 2, 0);
                    cameraAdjustY = 0;
                }
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
