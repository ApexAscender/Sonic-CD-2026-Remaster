#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath7.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath7.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath7::ObjectMain()
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
            pXPos() = 0x2B00;
            pYPos() = 0x2000;
            break;
            case 1:
            pXPos() = 0x82B00;
            pYPos() = 0x2000;
            break;
            case 2:
            pXPos() = 0x102B00;
            pYPos() = 0x2000;
            break;
            case 3:
            pXPos() = 0x182B00;
            pYPos() = 0x2000;
            break;
            case 4:
            pXPos() = 0x202B00;
            pYPos() = 0x2000;
            break;
            case 5:
            pXPos() = 0x282B00;
            pYPos() = 0x2000;
            break;
            case 6:
            pXPos() = 0x302B00;
            pYPos() = 0x2000;
            break;
            case 7:
            pXPos() = 0x382B00;
            pYPos() = 0x2000;
            break;
            case 8:
            pXPos() = 0x402B00;
            pYPos() = 0x2000;
            break;
            case 9:
            pXPos() = 0x482B00;
            pYPos() = 0x2000;
            break;
            case 10:
            pXPos() = 0x502B00;
            pYPos() = 0x2000;
            break;
            case 11:
            pXPos() = 0x582B00;
            pYPos() = 0x2000;
            break;
            case 12:
            pXPos() = 0x602B00;
            pYPos() = 0x2000;
            break;
            case 13:
            pXPos() = 0x682B00;
            pYPos() = 0x2000;
            break;
            case 14:
            pXPos() = 0x702B00;
            pYPos() = 0x2000;
            break;
            case 15:
            pXPos() = 0x782B00;
            pYPos() = 0x2000;
            break;
            case 16:
            pXPos() = 0x802B00;
            pYPos() = 0x2000;
            break;
            case 17:
            pXPos() = 0x882B00;
            pYPos() = 0x2000;
            break;
            case 18:
            pXPos() = 0x902B00;
            pYPos() = 0x2000;
            break;
            case 19:
            pXPos() = 0x982B00;
            pYPos() = 0x2000;
            break;
            case 20:
            pXPos() = 0xA02B00;
            pYPos() = 0x2000;
            break;
            case 21:
            pXPos() = 0xA82B00;
            pYPos() = 0x2000;
            break;
            case 22:
            pXPos() = 0xB02B00;
            pYPos() = 0x2000;
            break;
            case 23:
            pXPos() = 0xB82B00;
            pYPos() = 0x2000;
            break;
            case 24:
            pXPos() = 0xC02B00;
            pYPos() = 0x2000;
            break;
            case 25:
            pXPos() = 0xC82B00;
            pYPos() = 0x2000;
            break;
            case 26:
            pXPos() = 0xD02B00;
            pYPos() = 0x2000;
            break;
            case 27:
            pXPos() = 0xD82B00;
            pYPos() = 0x2000;
            break;
            case 28:
            pXPos() = 0xE02B00;
            pYPos() = 0x2000;
            break;
            case 29:
            pXPos() = 0xE82B00;
            pYPos() = 0x2000;
            break;
            case 30:
            pXPos() = 0xF02B00;
            pYPos() = 0x2000;
            break;
            case 31:
            pXPos() = 0xF82B00;
            pYPos() = 0x2000;
            break;
            case 32:
            pXPos() = 0x1002B00;
            pYPos() = 0x2000;
            break;
            case 33:
            pXPos() = 0x1082B00;
            pYPos() = 0x2000;
            break;
            case 34:
            pXPos() = 0x1102B00;
            pYPos() = 0x2000;
            break;
            case 35:
            pXPos() = 0x1182B00;
            pYPos() = 0x2000;
            break;
            case 36:
            pXPos() = 0x1202B00;
            pYPos() = 0x2000;
            break;
            case 37:
            pXPos() = 0x1282B00;
            pYPos() = 0x2000;
            break;
            case 38:
            pXPos() = 0x1302B00;
            pYPos() = 0x2000;
            break;
            case 39:
            pXPos() = 0x1382B00;
            pYPos() = 0x5800;
            self->state = 0;
            self->priority = 0;
            pXVel() = 0xA0000;
            pSpeed() = 0xA0000;
            pYVel() = 0;
            pState() = PlayerStateID("Player_State_Air");
            pObjectInteractions() = 1;
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

void O_R6_TunnelPath7::ObjectPlayerInteraction()
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
