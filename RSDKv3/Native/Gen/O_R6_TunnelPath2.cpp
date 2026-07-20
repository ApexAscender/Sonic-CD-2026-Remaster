#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath2::ObjectMain()
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
            pXPos() = 0xB700;
            pYPos() = 0xCA00;
            break;
            case 1:
            pXPos() = 0xB700;
            pYPos() = 0x8CA00;
            break;
            case 2:
            pXPos() = 0xB700;
            pYPos() = 0x10CA00;
            break;
            case 3:
            pXPos() = 0xB700;
            pYPos() = 0x18CA00;
            break;
            case 4:
            pXPos() = 0xB700;
            pYPos() = 0x20CA00;
            break;
            case 5:
            pXPos() = 0xB700;
            pYPos() = 0x28CA00;
            break;
            case 6:
            pXPos() = 0xB700;
            pYPos() = 0x30CA00;
            break;
            case 7:
            pXPos() = 0xB700;
            pYPos() = 0x38CA00;
            break;
            case 8:
            pXPos() = 0xB700;
            pYPos() = 0x40CA00;
            break;
            case 9:
            pXPos() = 0xB700;
            pYPos() = 0x48CA00;
            break;
            case 10:
            pXPos() = 0xB700;
            pYPos() = 0x50CA00;
            break;
            case 11:
            pXPos() = 0xB700;
            pYPos() = 0x58CA00;
            break;
            case 12:
            pXPos() = 0xB700;
            pYPos() = 0x60CA00;
            break;
            case 13:
            pXPos() = 0xB700;
            pYPos() = 0x68CA00;
            break;
            case 14:
            pXPos() = 0xB700;
            pYPos() = 0x70CA00;
            break;
            case 15:
            pXPos() = 0xB700;
            pYPos() = 0x78CA00;
            break;
            case 16:
            pXPos() = 0xB700;
            pYPos() = 0x80CA00;
            break;
            case 17:
            pXPos() = 0xB700;
            pYPos() = 0x88CA00;
            break;
            case 18:
            pXPos() = 0xB700;
            pYPos() = 0x90CA00;
            break;
            case 19:
            pXPos() = 0xB700;
            pYPos() = 0x98CA00;
            break;
            case 20:
            pXPos() = 0xB700;
            pYPos() = 0xA0CA00;
            break;
            case 21:
            pXPos() = 0xB700;
            pYPos() = 0xA8CA00;
            break;
            case 22:
            pXPos() = 0xB700;
            pYPos() = 0xB0CA00;
            break;
            case 23:
            pXPos() = 0xB700;
            pYPos() = 0xB8CA00;
            break;
            case 24:
            pXPos() = 0xB700;
            pYPos() = 0xC0CA00;
            break;
            case 25:
            pXPos() = 0xB700;
            pYPos() = 0xC8CA00;
            break;
            case 26:
            pXPos() = 0xB700;
            pYPos() = 0xD0CA00;
            break;
            case 27:
            pXPos() = 0xB700;
            pYPos() = 0xD8CA00;
            break;
            case 28:
            pXPos() = 0xB700;
            pYPos() = 0xE0CA00;
            break;
            case 29:
            pXPos() = 0xB700;
            pYPos() = 0xE8CA00;
            break;
            case 30:
            pXPos() = 0xB700;
            pYPos() = 0xF0CA00;
            break;
            case 31:
            pXPos() = 0xB700;
            pYPos() = 0xF8CA00;
            break;
            case 32:
            pXPos() = 0xB700;
            pYPos() = 0x100CA00;
            break;
            case 33:
            pXPos() = 0xB700;
            pYPos() = 0x108CA00;
            break;
            case 34:
            pXPos() = 0xB700;
            pYPos() = 0x110CA00;
            break;
            case 35:
            pXPos() = 0xB700;
            pYPos() = 0x118CA00;
            break;
            case 36:
            pXPos() = 0xB700;
            pYPos() = 0x120CA00;
            break;
            case 37:
            pXPos() = 0xB700;
            pYPos() = 0x128CA00;
            break;
            case 38:
            pXPos() = 0xB700;
            pYPos() = 0x130CA00;
            break;
            case 39:
            pXPos() = 0xB700;
            pYPos() = 0x138CA00;
            break;
            case 40:
            pXPos() = 0xB700;
            pYPos() = 0x140CA00;
            break;
            case 41:
            pXPos() = 0xB700;
            pYPos() = 0x148CA00;
            break;
            case 42:
            pXPos() = 0xB700;
            pYPos() = 0x150CA00;
            break;
            case 43:
            pXPos() = 0xB700;
            pYPos() = 0x158CA00;
            break;
            case 44:
            pXPos() = 0xB700;
            pYPos() = 0x160CA00;
            break;
            case 45:
            pXPos() = 0xB700;
            pYPos() = 0x168CA00;
            break;
            case 46:
            pXPos() = 0xB700;
            pYPos() = 0x170CA00;
            break;
            case 47:
            pXPos() = 0xB700;
            pYPos() = 0x178CA00;
            break;
            case 48:
            pXPos() = 0xB700;
            pYPos() = 0x180CA00;
            break;
            case 49:
            pXPos() = 0xB700;
            pYPos() = 0x188CA00;
            break;
            case 50:
            pXPos() = 0xB700;
            pYPos() = 0x190CA00;
            break;
            case 51:
            pXPos() = 0xB700;
            pYPos() = 0x198CA00;
            break;
            case 52:
            pXPos() = 0xB700;
            pYPos() = 0x1A0CA00;
            break;
            case 53:
            pXPos() = 0xB700;
            pYPos() = 0x1A8CA00;
            break;
            case 54:
            pXPos() = 0xB700;
            pYPos() = 0x1B0CA00;
            break;
            case 55:
            pXPos() = 0xB700;
            pYPos() = 0x1B8CA00;
            break;
            case 56:
            pXPos() = 0xB700;
            pYPos() = 0x1C0CA00;
            break;
            case 57:
            pXPos() = 0xB700;
            pYPos() = 0x1C8CA00;
            break;
            case 58:
            pXPos() = 0xB700;
            pYPos() = 0x1D0CA00;
            break;
            case 59:
            pXPos() = 0xB700;
            pYPos() = 0x1D8CA00;
            break;
            case 60:
            pXPos() = 0xB700;
            pYPos() = 0x1E0CA00;
            break;
            case 61:
            pXPos() = 0xB700;
            pYPos() = 0x1E8CA00;
            break;
            case 62:
            pXPos() = 0xB700;
            pYPos() = 0x1F0CA00;
            break;
            case 63:
            pXPos() = 0xB700;
            pYPos() = 0x1F8CA00;
            break;
            case 64:
            pXPos() = 0xB700;
            pYPos() = 0x200CA00;
            break;
            case 65:
            pXPos() = 0xB700;
            pYPos() = 0x208CA00;
            break;
            case 66:
            pXPos() = 0xB700;
            pYPos() = 0x210CA00;
            break;
            case 67:
            pXPos() = 0xB700;
            pYPos() = 0x218CA00;
            break;
            case 68:
            pXPos() = 0xB700;
            pYPos() = 0x220CA00;
            break;
            case 69:
            pXPos() = 0xB700;
            pYPos() = 0x228CA00;
            break;
            case 70:
            pXPos() = 0xB700;
            pYPos() = 0x230CA00;
            break;
            case 71:
            pXPos() = 0xB700;
            pYPos() = 0x238CA00;
            break;
            case 72:
            pXPos() = 0xB700;
            pYPos() = 0x240CA00;
            break;
            case 73:
            pXPos() = 0xB700;
            pYPos() = 0x248CA00;
            break;
            case 74:
            pXPos() = 0xB700;
            pYPos() = 0x250CA00;
            break;
            case 75:
            pXPos() = 0xB700;
            pYPos() = 0x258CA00;
            break;
            case 76:
            pXPos() = 0xB700;
            pYPos() = 0x260CA00;
            break;
            case 77:
            pXPos() = 0xB700;
            pYPos() = 0x268CA00;
            break;
            case 78:
            pXPos() = 0xB700;
            pYPos() = 0x270CA00;
            break;
            case 79:
            pXPos() = 0xB700;
            pYPos() = 0x278CA00;
            break;
            case 80:
            pXPos() = 0xB700;
            pYPos() = 0x280CA00;
            break;
            case 81:
            pXPos() = 0xB700;
            pYPos() = 0x288CA00;
            break;
            case 82:
            pXPos() = 0xB700;
            pYPos() = 0x290CA00;
            break;
            case 83:
            pXPos() = 0xB700;
            pYPos() = 0x298CA00;
            break;
            case 84:
            pXPos() = 0xB700;
            pYPos() = 0x2A0CA00;
            break;
            case 85:
            pXPos() = 0xB700;
            pYPos() = 0x2A8CA00;
            break;
            case 86:
            pXPos() = 0x8B700;
            pYPos() = 0x2A8CA00;
            break;
            case 87:
            pXPos() = 0x10B700;
            pYPos() = 0x2A8CA00;
            break;
            case 88:
            pXPos() = 0x18B700;
            pYPos() = 0x2A8CA00;
            break;
            case 89:
            pXPos() = 0x20B700;
            pYPos() = 0x2A8CA00;
            break;
            case 90:
            pObjectInteractions() = 1;
            pXPos() = 0x28B700;
            pYPos() = 0x2A8CA00;
            break;
            case 91:
            pXPos() = 0x30B700;
            pYPos() = 0x2A8CA00;
            break;
            case 92:
            pXPos() = 0x38B700;
            pYPos() = 0x2A8CA00;
            break;
            case 93:
            pXPos() = 0x40B700;
            pYPos() = 0x2A8CA00;
            break;
            case 94:
            pXPos() = 0x48B700;
            pYPos() = 0x2A8CA00;
            break;
            case 95:
            pXPos() = 0x50B700;
            pYPos() = 0x2A8CA00;
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

void O_R6_TunnelPath2::ObjectPlayerInteraction()
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
