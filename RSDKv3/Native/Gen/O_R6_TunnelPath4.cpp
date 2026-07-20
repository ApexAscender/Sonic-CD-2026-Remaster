#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath4.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath4.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath4::ObjectMain()
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
            pXPos() = 0x8B00;
            pYPos() = 0x8200;
            break;
            case 1:
            pXPos() = 0x88B00;
            pYPos() = 0x8200;
            break;
            case 2:
            pXPos() = 0x88B00;
            pYPos() = 0x88200;
            break;
            case 3:
            pXPos() = 0x88B00;
            pYPos() = 0x108200;
            break;
            case 4:
            pXPos() = 0x88B00;
            pYPos() = 0x188200;
            break;
            case 5:
            pXPos() = 0x88B00;
            pYPos() = 0x208200;
            break;
            case 6:
            pXPos() = 0x88B00;
            pYPos() = 0x288200;
            break;
            case 7:
            pXPos() = 0x88B00;
            pYPos() = 0x308200;
            break;
            case 8:
            pXPos() = 0x88B00;
            pYPos() = 0x388200;
            break;
            case 9:
            pXPos() = 0x88B00;
            pYPos() = 0x408200;
            break;
            case 10:
            pXPos() = 0x88B00;
            pYPos() = 0x488200;
            break;
            case 11:
            pXPos() = 0x88B00;
            pYPos() = 0x508200;
            break;
            case 12:
            pXPos() = 0x88B00;
            pYPos() = 0x588200;
            break;
            case 13:
            pXPos() = 0x88B00;
            pYPos() = 0x608200;
            break;
            case 14:
            pXPos() = 0x88B00;
            pYPos() = 0x688200;
            break;
            case 15:
            pXPos() = 0x88B00;
            pYPos() = 0x708200;
            break;
            case 16:
            pXPos() = 0x88B00;
            pYPos() = 0x788200;
            break;
            case 17:
            pXPos() = 0x88B00;
            pYPos() = 0x808200;
            break;
            case 18:
            pXPos() = 0x88B00;
            pYPos() = 0x888200;
            break;
            case 19:
            pXPos() = 0x88B00;
            pYPos() = 0x908200;
            break;
            case 20:
            pXPos() = 0x88B00;
            pYPos() = 0x988200;
            break;
            case 21:
            pXPos() = 0x88B00;
            pYPos() = 0xA08200;
            break;
            case 22:
            pXPos() = 0x88B00;
            pYPos() = 0xA88200;
            break;
            case 23:
            pXPos() = 0x88B00;
            pYPos() = 0xB08200;
            break;
            case 24:
            pXPos() = 0x88B00;
            pYPos() = 0xB88200;
            break;
            case 25:
            pXPos() = 0x88B00;
            pYPos() = 0xC08200;
            break;
            case 26:
            pXPos() = 0x88B00;
            pYPos() = 0xC88200;
            break;
            case 27:
            pXPos() = 0x88B00;
            pYPos() = 0xD08200;
            break;
            case 28:
            pXPos() = 0x88B00;
            pYPos() = 0xD88200;
            break;
            case 29:
            pXPos() = 0x88B00;
            pYPos() = 0xE08200;
            break;
            case 30:
            pXPos() = 0x88B00;
            pYPos() = 0xE88200;
            break;
            case 31:
            pXPos() = 0x88B00;
            pYPos() = 0xF08200;
            break;
            case 32:
            pXPos() = 0x88B00;
            pYPos() = 0xF88200;
            break;
            case 33:
            pXPos() = 0x88B00;
            pYPos() = 0x1008200;
            break;
            case 34:
            pXPos() = 0x108B00;
            pYPos() = 0x1008200;
            break;
            case 35:
            pXPos() = 0x188B00;
            pYPos() = 0x1008200;
            break;
            case 36:
            pObjectInteractions() = 1;
            pXPos() = 0x208B00;
            pYPos() = 0x1008200;
            break;
            case 37:
            pXPos() = 0x288B00;
            pYPos() = 0x1008200;
            break;
            case 38:
            pXPos() = 0x308B00;
            pYPos() = 0x1008200;
            break;
            case 39:
            pXPos() = 0x388B00;
            pYPos() = 0x1008200;
            break;
            case 40:
            pXPos() = 0x408B00;
            pYPos() = 0x1008200;
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

void O_R6_TunnelPath4::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (pState() != PlayerStateID("Player_State_Static")) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                pState() = PlayerStateID("Player_State_Static");
                pObjectInteractions() = 0;
                pVisible() = 0;
                if (PlayerValue(5) > 0) {
                    PlayerValue(4) = 0;
                    PlayerValue(5) = 0;
                }
                self->state = 1;
                self->values[0] = -1;
                self->priority = 1;
                PlaySfx(7, 0);
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
