#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_TunnelPath2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_TunnelPath2::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        if (pState() == PlayerStateID("Player_State_Death")) {
            self->state = 0;
        }
        scriptEng.tempValue[0] = self->values[0];
        self->values[0]++;
        pSpeed() = pXPos();
        pAnimation() = GVar("ANI_JUMPING");
        pAnimationSpeed() = 240;
        switch (scriptEng.tempValue[0]) {
            case 0:
            pXPos() = 0x7600;
            pYPos() = 0x3700;
            break;
            case 1:
            pXPos() = 0x7600;
            pYPos() = 0xA3700;
            break;
            case 2:
            pXPos() = 0x7600;
            pYPos() = 0x143700;
            break;
            case 3:
            pXPos() = 0x7600;
            pYPos() = 0x1E3700;
            break;
            case 4:
            pXPos() = 0x7600;
            pYPos() = 0x203700;
            break;
            case 5:
            pXPos() = 0xA7600;
            pYPos() = 0x243700;
            break;
            case 6:
            pXPos() = 0x147600;
            pYPos() = 0x283700;
            break;
            case 7:
            pXPos() = 0x1E7600;
            pYPos() = 0x2C3700;
            break;
            case 8:
            pXPos() = 0x287600;
            pYPos() = 0x303700;
            break;
            case 9:
            pXPos() = 0x327600;
            pYPos() = 0x343700;
            break;
            case 10:
            pXPos() = 0x3C7600;
            pYPos() = 0x383700;
            break;
            case 11:
            pXPos() = 0x467600;
            pYPos() = 0x3C3700;
            break;
            case 12:
            pXPos() = 0x507600;
            pYPos() = 0x403700;
            break;
            case 13:
            pXPos() = 0x467600;
            pYPos() = 0x42B700;
            break;
            case 14:
            pXPos() = 0x3C7600;
            pYPos() = 0x453700;
            break;
            case 15:
            pXPos() = 0x327600;
            pYPos() = 0x47B700;
            break;
            case 16:
            pXPos() = 0x287600;
            pYPos() = 0x4A3700;
            break;
            case 17:
            pXPos() = 0x1E7600;
            pYPos() = 0x4CB700;
            break;
            case 18:
            pXPos() = 0x147600;
            pYPos() = 0x4F3700;
            break;
            case 19:
            pXPos() = 0xA7600;
            pYPos() = 0x51B700;
            break;
            case 20:
            pXPos() = 0x7600;
            pYPos() = 0x543700;
            break;
            case 21:
            pXPos() = -0x98A00;
            pYPos() = 0x56B700;
            break;
            case 22:
            pXPos() = -0x138A00;
            pYPos() = 0x593700;
            break;
            case 23:
            pXPos() = -0x1D8A00;
            pYPos() = 0x5BB700;
            break;
            case 24:
            pXPos() = -0x278A00;
            pYPos() = 0x5E3700;
            break;
            case 25:
            pXPos() = -0x2F8A00;
            pYPos() = 0x603700;
            break;
            case 26:
            pXPos() = -0x258A00;
            pYPos() = 0x62B700;
            break;
            case 27:
            pXPos() = -0x1B8A00;
            pYPos() = 0x653700;
            break;
            case 28:
            pXPos() = -0x118A00;
            pYPos() = 0x67B700;
            break;
            case 29:
            pXPos() = -0x78A00;
            pYPos() = 0x6A3700;
            break;
            case 30:
            pXPos() = 0x27600;
            pYPos() = 0x6CB700;
            break;
            case 31:
            pXPos() = 0xC7600;
            pYPos() = 0x6F3700;
            break;
            case 32:
            pXPos() = 0x167600;
            pYPos() = 0x71B700;
            break;
            case 33:
            pXPos() = 0x207600;
            pYPos() = 0x743700;
            break;
            case 34:
            pXPos() = 0x2A7600;
            pYPos() = 0x76B700;
            break;
            case 35:
            pXPos() = 0x347600;
            pYPos() = 0x793700;
            break;
            case 36:
            pXPos() = 0x3E7600;
            pYPos() = 0x7BB700;
            break;
            case 37:
            pXPos() = 0x487600;
            pYPos() = 0x7E3700;
            break;
            case 38:
            pXPos() = 0x507600;
            pYPos() = 0x803700;
            break;
            case 39:
            pXPos() = 0x467600;
            pYPos() = 0x82B700;
            break;
            case 40:
            pXPos() = 0x3C7600;
            pYPos() = 0x853700;
            break;
            case 41:
            pXPos() = 0x327600;
            pYPos() = 0x87B700;
            break;
            case 42:
            pXPos() = 0x287600;
            pYPos() = 0x8A3700;
            break;
            case 43:
            pXPos() = 0x1E7600;
            pYPos() = 0x8CB700;
            break;
            case 44:
            pXPos() = 0x147600;
            pYPos() = 0x8F3700;
            break;
            case 45:
            pXPos() = 0xA7600;
            pYPos() = 0x91B700;
            break;
            case 46:
            pXPos() = 0x7600;
            pYPos() = 0x943700;
            break;
            case 47:
            pXPos() = -0x98A00;
            pYPos() = 0x96B700;
            break;
            case 48:
            pXPos() = -0x138A00;
            pYPos() = 0x993700;
            break;
            case 49:
            pXPos() = -0x1D8A00;
            pYPos() = 0x9BB700;
            break;
            case 50:
            pXPos() = -0x278A00;
            pYPos() = 0x9E3700;
            break;
            case 51:
            pXPos() = -0x2F8A00;
            pYPos() = 0xA03700;
            break;
            case 52:
            pXPos() = -0x258A00;
            pYPos() = 0xA2B700;
            break;
            case 53:
            pXPos() = -0x1B8A00;
            pYPos() = 0xA53700;
            break;
            case 54:
            pXPos() = -0x118A00;
            pYPos() = 0xA7B700;
            break;
            case 55:
            pXPos() = -0x78A00;
            pYPos() = 0xAA3700;
            break;
            case 56:
            pXPos() = 0x27600;
            pYPos() = 0xACB700;
            break;
            case 57:
            pXPos() = 0xC7600;
            pYPos() = 0xAF3700;
            break;
            case 58:
            pXPos() = 0x167600;
            pYPos() = 0xB1B700;
            break;
            case 59:
            pXPos() = 0x207600;
            pYPos() = 0xB43700;
            break;
            case 60:
            pXPos() = 0x2A7600;
            pYPos() = 0xB6B700;
            break;
            case 61:
            pXPos() = 0x347600;
            pYPos() = 0xB93700;
            break;
            case 62:
            pXPos() = 0x3E7600;
            pYPos() = 0xBBB700;
            break;
            case 63:
            pXPos() = 0x487600;
            pYPos() = 0xBE3700;
            break;
            case 64:
            pXPos() = 0x507600;
            pYPos() = 0xC03700;
            break;
            case 65:
            pXPos() = 0x467600;
            pYPos() = 0xC2B700;
            break;
            case 66:
            pXPos() = 0x3C7600;
            pYPos() = 0xC53700;
            break;
            case 67:
            pXPos() = 0x327600;
            pYPos() = 0xC7B700;
            break;
            case 68:
            pXPos() = 0x287600;
            pYPos() = 0xCA3700;
            break;
            case 69:
            pXPos() = 0x1E7600;
            pYPos() = 0xCCB700;
            break;
            case 70:
            pXPos() = 0x147600;
            pYPos() = 0xCF3700;
            break;
            case 71:
            pXPos() = 0xA7600;
            pYPos() = 0xD1B700;
            break;
            case 72:
            pXPos() = 0x7600;
            pYPos() = 0xD43700;
            break;
            case 73:
            pXPos() = -0x98A00;
            pYPos() = 0xD6B700;
            break;
            case 74:
            pXPos() = -0x138A00;
            pYPos() = 0xD93700;
            break;
            case 75:
            pXPos() = -0x1D8A00;
            pYPos() = 0xDBB700;
            break;
            case 76:
            pXPos() = -0x278A00;
            pYPos() = 0xDE3700;
            break;
            case 77:
            pXPos() = -0x2F8A00;
            pYPos() = 0xE03700;
            break;
            case 78:
            pXPos() = -0x258A00;
            pYPos() = 0xE41A00;
            break;
            case 79:
            pXPos() = -0x1B8A00;
            pYPos() = 0xE7FD00;
            break;
            case 80:
            pXPos() = -0x118A00;
            pYPos() = 0xEBE000;
            break;
            case 81:
            pXPos() = -0x78A00;
            pYPos() = 0xEFC300;
            break;
            case 82:
            pXPos() = 0x27600;
            pYPos() = 0xF3A600;
            break;
            case 83:
            pXPos() = 0xC7600;
            pYPos() = 0xF78900;
            break;
            case 84:
            pXPos() = 0x167600;
            pYPos() = 0xFB6C00;
            break;
            case 85:
            pXPos() = 0x207600;
            pYPos() = 0xFF4F00;
            break;
            case 86:
            pXPos() = 0x2A7600;
            pYPos() = 0x1033200;
            break;
            case 87:
            pXPos() = 0x347600;
            pYPos() = 0x1071500;
            break;
            case 88:
            pXPos() = 0x3E7600;
            pYPos() = 0x10AF800;
            break;
            case 89:
            pXPos() = 0x487600;
            pYPos() = 0x10EDB00;
            break;
            case 90:
            pXPos() = 0x527600;
            pYPos() = 0x112BE00;
            break;
            case 91:
            pXPos() = 0x5C7600;
            pYPos() = 0x116A100;
            break;
            case 92:
            pXPos() = 0x607600;
            pYPos() = 0x118A100;
            break;
            case 93:
            pXPos() = 0x607600;
            pYPos() = 0x122A100;
            break;
            case 94:
            pXPos() = 0x607600;
            pYPos() = 0x12CA100;
            break;
            case 95:
            pXPos() = 0x607600;
            pYPos() = 0x136A100;
            break;
            case 96:
            pXPos() = 0x607600;
            pYPos() = 0x138A100;
            break;
            case 97:
            pXPos() = 0x657600;
            pYPos() = 0x142A100;
            break;
            case 98:
            pXPos() = 0x657600;
            pYPos() = 0x14CD900;
            break;
            case 99:
            pXPos() = 0x657600;
            pYPos() = 0x1574900;
            break;
            case 100:
            pXPos() = 0x657600;
            pYPos() = 0x161F100;
            self->state = 0;
            self->priority = 0;
            pXVel() = 0;
            pSpeed() = 0;
            pYVel() = 0x60000;
            pState() = PlayerStateID("Player_State_Air");
            pObjectInteractions() = 1;
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

void O_R5_TunnelPath2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (pState() != PlayerStateID("Player_State_Static")) {
            PlayerObjectCollision(C_TOUCH, -8, -16, 8, 16);
            if (CheckResult() == 1) {
                pState() = PlayerStateID("Player_State_Static");
                pObjectInteractions() = 0;
                self->state = 1;
                self->values[0] = 0;
                self->priority = 1;
                PlaySfx(7, 0);
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
