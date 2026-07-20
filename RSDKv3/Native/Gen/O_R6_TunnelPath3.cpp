#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath3.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath3.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath3::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        if (pState() == PlayerStateID("Player_State_Death")) {
            self->state = 0;
        }
        self->values[0]++;
        pSpeed() = pXPos();
        pAnimation() = GVar("ANI_JUMPING");
        pAnimationSpeed() = 240;
        switch (self->values[0]) {
            case 0:
            pXPos() = 0x2700;
            pYPos() = 0x6200;
            break;
            case 1:
            pXPos() = 0x82700;
            pYPos() = 0x6200;
            break;
            case 2:
            pXPos() = 0x82700;
            pYPos() = -0x79E00;
            break;
            case 3:
            pXPos() = 0x82700;
            pYPos() = -0xF9E00;
            break;
            case 4:
            pXPos() = 0x82700;
            pYPos() = -0x179E00;
            break;
            case 5:
            pXPos() = 0x82700;
            pYPos() = -0x1F9E00;
            break;
            case 6:
            pXPos() = 0x82700;
            pYPos() = -0x279E00;
            break;
            case 7:
            pXPos() = 0x82700;
            pYPos() = -0x2F9E00;
            break;
            case 8:
            pXPos() = 0x82700;
            pYPos() = -0x379E00;
            break;
            case 9:
            pXPos() = 0x82700;
            pYPos() = -0x3F9E00;
            break;
            case 10:
            pXPos() = 0x82700;
            pYPos() = -0x479E00;
            break;
            case 11:
            pXPos() = 0x82700;
            pYPos() = -0x4F9E00;
            break;
            case 12:
            pXPos() = 0x82700;
            pYPos() = -0x579E00;
            break;
            case 13:
            pXPos() = 0x82700;
            pYPos() = -0x5F9E00;
            break;
            case 14:
            pXPos() = 0x82700;
            pYPos() = -0x679E00;
            break;
            case 15:
            pXPos() = 0x82700;
            pYPos() = -0x6F9E00;
            break;
            case 16:
            pXPos() = 0x82700;
            pYPos() = -0x779E00;
            break;
            case 17:
            pXPos() = 0x82700;
            pYPos() = -0x7F9E00;
            break;
            case 18:
            pXPos() = 0x82700;
            pYPos() = -0x879E00;
            break;
            case 19:
            pXPos() = 0x82700;
            pYPos() = -0x8F9E00;
            break;
            case 20:
            pXPos() = 0x82700;
            pYPos() = -0x979E00;
            break;
            case 21:
            pXPos() = 0x82700;
            pYPos() = -0x9F9E00;
            break;
            case 22:
            pXPos() = 0x82700;
            pYPos() = -0xA79E00;
            break;
            case 23:
            pXPos() = 0x82700;
            pYPos() = -0xAF9E00;
            break;
            case 24:
            pXPos() = 0x82700;
            pYPos() = -0xB79E00;
            break;
            case 25:
            pXPos() = 0x82700;
            pYPos() = -0xBF9E00;
            break;
            case 26:
            pXPos() = 0x82700;
            pYPos() = -0xC79E00;
            break;
            case 27:
            pXPos() = 0x82700;
            pYPos() = -0xCF9E00;
            break;
            case 28:
            pXPos() = 0x82700;
            pYPos() = -0xD79E00;
            break;
            case 29:
            pXPos() = 0x82700;
            pYPos() = -0xDF9E00;
            break;
            case 30:
            pXPos() = 0x82700;
            pYPos() = -0xE79E00;
            break;
            case 31:
            pXPos() = 0x82700;
            pYPos() = -0xEF9E00;
            break;
            case 32:
            pXPos() = 0x82700;
            pYPos() = -0xF79E00;
            break;
            case 33:
            pXPos() = 0x82700;
            pYPos() = -0xFF9E00;
            break;
            case 34:
            pXPos() = 0x102700;
            pYPos() = -0xFF9E00;
            break;
            case 35:
            pXPos() = 0x182700;
            pYPos() = -0xFF9E00;
            break;
            case 36:
            pObjectInteractions() = 1;
            pXPos() = 0x202700;
            pYPos() = -0xFF9E00;
            break;
            case 37:
            pXPos() = 0x282700;
            pYPos() = -0xFF9E00;
            break;
            case 38:
            pXPos() = 0x302700;
            pYPos() = -0xFF9E00;
            break;
            case 39:
            pXPos() = 0x382700;
            pYPos() = -0xFF9E00;
            break;
            case 40:
            pXPos() = 0x402700;
            pYPos() = -0xFF9E00;
            pDirection() = 0;
            self->state = 0;
            self->priority = 0;
            pXVel() = 0x80000;
            pSpeed() = 0x80000;
            pYVel() = 0;
            pState() = PlayerStateID("Player_State_Air");
            pVisible() = 1;
            break;
        }
        pXPos() += self->XPos;
        pYPos() += self->YPos;
        if (self->state > 0) {
            pSpeed() -= pXPos();
            pSpeed() = -pSpeed();
        }
    }
}

void O_R6_TunnelPath3::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (pState() != PlayerStateID("Player_State_Static")) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                pState() = PlayerStateID("Player_State_Static");
                pObjectInteractions() = 0;
                if (PlayerValue(5) > 0) {
                    PlayerValue(4) = 0;
                    PlayerValue(5) = 0;
                }
                pVisible() = 0;
                self->state = 1;
                self->values[0] = -1;
                self->priority = 1;
                PlaySfx(7, 0);
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
