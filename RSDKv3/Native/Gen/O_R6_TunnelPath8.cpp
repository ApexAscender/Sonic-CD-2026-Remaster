#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath8.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath8.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath8::ObjectMain()
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
            pXPos() = 0;
            pYPos() = 0x7D00;
            break;
            case 1:
            pXPos() = 0x80000;
            pYPos() = 0x7D00;
            break;
            case 2:
            pXPos() = 0x100000;
            pYPos() = 0x7D00;
            break;
            case 3:
            pXPos() = 0x180000;
            pYPos() = 0x7D00;
            break;
            case 4:
            pXPos() = 0x200000;
            pYPos() = 0x7D00;
            break;
            case 5:
            pXPos() = 0x280000;
            pYPos() = 0x7D00;
            break;
            case 6:
            pXPos() = 0x300000;
            pYPos() = 0x7D00;
            break;
            case 7:
            pXPos() = 0x380000;
            pYPos() = 0x7D00;
            break;
            case 8:
            pXPos() = 0x400000;
            pYPos() = 0x7D00;
            break;
            case 9:
            pXPos() = 0x480000;
            pYPos() = 0x7D00;
            break;
            case 10:
            pXPos() = 0x500000;
            pYPos() = 0x7D00;
            break;
            case 11:
            pXPos() = 0x580000;
            pYPos() = 0x7D00;
            break;
            case 12:
            pXPos() = 0x600000;
            pYPos() = 0x7D00;
            break;
            case 13:
            pXPos() = 0x680000;
            pYPos() = 0x7D00;
            break;
            case 14:
            pXPos() = 0x700000;
            pYPos() = 0x7D00;
            break;
            case 15:
            pXPos() = 0x780000;
            pYPos() = 0x7D00;
            break;
            case 16:
            pXPos() = 0x800000;
            pYPos() = 0x7D00;
            break;
            case 17:
            pXPos() = 0x880000;
            pYPos() = 0x7D00;
            break;
            case 18:
            pXPos() = 0x900000;
            pYPos() = 0x7D00;
            break;
            case 19:
            pXPos() = 0x980000;
            pYPos() = 0x7D00;
            break;
            case 20:
            pXPos() = 0xA00000;
            pYPos() = 0x7D00;
            break;
            case 21:
            pXPos() = 0xA80000;
            pYPos() = 0x7D00;
            break;
            case 22:
            pXPos() = 0xB00000;
            pYPos() = 0x7D00;
            break;
            case 23:
            pXPos() = 0xB80000;
            pYPos() = 0x7D00;
            break;
            case 24:
            pXPos() = 0xC00000;
            pYPos() = 0x7D00;
            break;
            case 25:
            pXPos() = 0xC80000;
            pYPos() = 0x7D00;
            break;
            case 26:
            pXPos() = 0xD00000;
            pYPos() = 0x7D00;
            break;
            case 27:
            pXPos() = 0xD80000;
            pYPos() = 0x7D00;
            break;
            case 28:
            pXPos() = 0xE00000;
            pYPos() = 0x7D00;
            break;
            case 29:
            pXPos() = 0xE80000;
            pYPos() = 0x7D00;
            break;
            case 30:
            pXPos() = 0xF00000;
            pYPos() = 0x7D00;
            break;
            case 31:
            pXPos() = 0xF80000;
            pYPos() = 0x7D00;
            break;
            case 32:
            pXPos() = 0x1000000;
            pYPos() = 0x7D00;
            break;
            case 33:
            pXPos() = 0x1080000;
            pYPos() = 0x7D00;
            break;
            case 34:
            pXPos() = 0x1100000;
            pYPos() = 0x7D00;
            break;
            case 35:
            pXPos() = 0x1180000;
            pYPos() = 0x7D00;
            break;
            case 36:
            pXPos() = 0x1200000;
            pYPos() = 0x7D00;
            break;
            case 37:
            pXPos() = 0x1280000;
            pYPos() = 0x7D00;
            break;
            case 38:
            pXPos() = 0x1300000;
            pYPos() = 0x7D00;
            break;
            case 39:
            pXPos() = 0x1380000;
            pYPos() = 0x7D00;
            break;
            case 40:
            pXPos() = 0x1400000;
            pYPos() = 0x7D00;
            break;
            case 41:
            pXPos() = 0x1480000;
            pYPos() = 0x7D00;
            break;
            case 42:
            pXPos() = 0x1500000;
            pYPos() = 0x7D00;
            break;
            case 43:
            pXPos() = 0x1580000;
            pYPos() = 0x7D00;
            break;
            case 44:
            pXPos() = 0x1600000;
            pYPos() = 0x7D00;
            break;
            case 45:
            pXPos() = 0x1680000;
            pYPos() = 0x7D00;
            break;
            case 46:
            pXPos() = 0x1700000;
            pYPos() = 0x7D00;
            break;
            case 47:
            pXPos() = 0x1780000;
            pYPos() = 0x7D00;
            break;
            case 48:
            pXPos() = 0x1800000;
            pYPos() = 0x7D00;
            break;
            case 49:
            pXPos() = 0x1880000;
            pYPos() = 0x7D00;
            break;
            case 50:
            pXPos() = 0x1900000;
            pYPos() = 0x7D00;
            break;
            case 51:
            pXPos() = 0x1980000;
            pYPos() = 0x7D00;
            break;
            case 52:
            pXPos() = 0x1A00000;
            pYPos() = 0x7D00;
            break;
            case 53:
            pXPos() = 0x1A80000;
            pYPos() = 0x7D00;
            break;
            case 54:
            pXPos() = 0x1B00000;
            pYPos() = 0x7D00;
            break;
            case 55:
            pXPos() = 0x1B00000;
            pYPos() = 0x87D00;
            break;
            case 56:
            pXPos() = 0x1B00000;
            pYPos() = 0x107D00;
            break;
            case 57:
            pXPos() = 0x1B00000;
            pYPos() = 0x187D00;
            break;
            case 58:
            pXPos() = 0x1B00000;
            pYPos() = 0x207D00;
            break;
            case 59:
            pXPos() = 0x1B00000;
            pYPos() = 0x287D00;
            break;
            case 60:
            pXPos() = 0x1B00000;
            pYPos() = 0x307D00;
            break;
            case 61:
            pXPos() = 0x1B00000;
            pYPos() = 0x387D00;
            break;
            case 62:
            pXPos() = 0x1B00000;
            pYPos() = 0x407D00;
            break;
            case 63:
            pXPos() = 0x1B00000;
            pYPos() = 0x487D00;
            break;
            case 64:
            pXPos() = 0x1B00000;
            pYPos() = 0x507D00;
            break;
            case 65:
            pXPos() = 0x1B00000;
            pYPos() = 0x587D00;
            break;
            case 66:
            pXPos() = 0x1B00000;
            pYPos() = 0x607D00;
            break;
            case 67:
            pXPos() = 0x1B00000;
            pYPos() = 0x687D00;
            break;
            case 68:
            pXPos() = 0x1B00000;
            pYPos() = 0x707D00;
            break;
            case 69:
            pXPos() = 0x1B00000;
            pYPos() = 0x787D00;
            break;
            case 70:
            pXPos() = 0x1B00000;
            pYPos() = 0x807D00;
            break;
            case 71:
            pXPos() = 0x1B00000;
            pYPos() = 0x887D00;
            break;
            case 72:
            pXPos() = 0x1B00000;
            pYPos() = 0x907D00;
            break;
            case 73:
            pXPos() = 0x1B00000;
            pYPos() = 0x987D00;
            break;
            case 74:
            pXPos() = 0x1B00000;
            pYPos() = 0xA07D00;
            break;
            case 75:
            pXPos() = 0x1B00000;
            pYPos() = 0xA87D00;
            break;
            case 76:
            pXPos() = 0x1B00000;
            pYPos() = 0xB07D00;
            break;
            case 77:
            pXPos() = 0x1B00000;
            pYPos() = 0xB87D00;
            break;
            case 78:
            pXPos() = 0x1B00000;
            pYPos() = 0xC07D00;
            break;
            case 79:
            pXPos() = 0x1B00000;
            pYPos() = 0xC87D00;
            break;
            case 80:
            pXPos() = 0x1B00000;
            pYPos() = 0xD07D00;
            break;
            case 81:
            pXPos() = 0x1B00000;
            pYPos() = 0xD87D00;
            break;
            case 82:
            pXPos() = 0x1B00000;
            pYPos() = 0xE07D00;
            break;
            case 83:
            pXPos() = 0x1B00000;
            pYPos() = 0xE87D00;
            break;
            case 84:
            pXPos() = 0x1B00000;
            pYPos() = 0xF07D00;
            break;
            case 85:
            pXPos() = 0x1B00000;
            pYPos() = 0xF87D00;
            break;
            case 86:
            pXPos() = 0x1B00000;
            pYPos() = 0x1007D00;
            break;
            case 87:
            pXPos() = 0x1B80000;
            pYPos() = 0x1007D00;
            break;
            case 88:
            pXPos() = 0x1C00000;
            pYPos() = 0x1007D00;
            break;
            case 89:
            pXPos() = 0x1C80000;
            pYPos() = 0x1007D00;
            break;
            case 90:
            pXPos() = 0x1D00000;
            pYPos() = 0x1007D00;
            break;
            case 91:
            pXPos() = 0x1D80000;
            pYPos() = 0x1007D00;
            break;
            case 92:
            pXPos() = 0x1E00000;
            pYPos() = 0x1007D00;
            break;
            case 93:
            pXPos() = 0x1E80000;
            pYPos() = 0x1007D00;
            break;
            case 94:
            pXPos() = 0x1F00000;
            pYPos() = 0x1007D00;
            break;
            case 95:
            pXPos() = 0x1F80000;
            pYPos() = 0x1007D00;
            break;
            case 96:
            pXPos() = 0x2000000;
            pYPos() = 0x1007D00;
            break;
            case 97:
            pXPos() = 0x2080000;
            pYPos() = 0x1007D00;
            break;
            case 98:
            pXPos() = 0x2100000;
            pYPos() = 0x1007D00;
            break;
            case 99:
            pXPos() = 0x2180000;
            pYPos() = 0x1007D00;
            break;
            case 100:
            pXPos() = 0x2200000;
            pYPos() = 0x1007D00;
            break;
            case 101:
            pXPos() = 0x2280000;
            pYPos() = 0x1007D00;
            break;
            case 102:
            pXPos() = 0x2300000;
            pYPos() = 0x1007D00;
            break;
            case 103:
            pXPos() = 0x2380000;
            pYPos() = 0x1007D00;
            break;
            case 104:
            pXPos() = 0x2400000;
            pYPos() = 0x1007D00;
            break;
            case 105:
            pXPos() = 0x2480000;
            pYPos() = 0x1007D00;
            break;
            case 106:
            pXPos() = 0x2500000;
            pYPos() = 0x1007D00;
            break;
            case 107:
            pXPos() = 0x2580000;
            pYPos() = 0x1007D00;
            break;
            case 108:
            pXPos() = 0x2600000;
            pYPos() = 0x1007D00;
            break;
            case 109:
            pXPos() = 0x2680000;
            pYPos() = 0x1007D00;
            break;
            case 110:
            pXPos() = 0x2700000;
            pYPos() = 0x1007D00;
            break;
            case 111:
            pXPos() = 0x2780000;
            pYPos() = 0x1007D00;
            break;
            case 112:
            pXPos() = 0x2800000;
            pYPos() = 0x1007D00;
            break;
            case 113:
            pXPos() = 0x2880000;
            pYPos() = 0x1007D00;
            break;
            case 114:
            pXPos() = 0x2900000;
            pYPos() = 0x1007D00;
            break;
            case 115:
            pXPos() = 0x2980000;
            pYPos() = 0x1007D00;
            break;
            case 116:
            pXPos() = 0x2A00000;
            pYPos() = 0x1007D00;
            break;
            case 117:
            pXPos() = 0x2A80000;
            pYPos() = 0x1007D00;
            break;
            case 118:
            pXPos() = 0x2B00000;
            pYPos() = 0x1007D00;
            break;
            case 119:
            pXPos() = 0x2B80000;
            pYPos() = 0x1007D00;
            break;
            case 120:
            pXPos() = 0x2C00000;
            pYPos() = 0x1007D00;
            break;
            case 121:
            pXPos() = 0x2C80000;
            pYPos() = 0x1007D00;
            break;
            case 122:
            pXPos() = 0x2D00000;
            pYPos() = 0x1007D00;
            break;
            case 123:
            pXPos() = 0x2D80000;
            pYPos() = 0x1007D00;
            break;
            case 124:
            pXPos() = 0x2E00000;
            pYPos() = 0x1007D00;
            break;
            case 125:
            pXPos() = 0x2E80000;
            pYPos() = 0x1007D00;
            break;
            case 126:
            pXPos() = 0x2F00000;
            pYPos() = 0x1007D00;
            break;
            case 127:
            pXPos() = 0x2F80000;
            pYPos() = 0x1007D00;
            break;
            case 128:
            pXPos() = 0x3000000;
            pYPos() = 0x1007D00;
            break;
            case 129:
            pXPos() = 0x3080000;
            pYPos() = 0x1007D00;
            break;
            case 130:
            pXPos() = 0x3100000;
            pYPos() = 0x1007D00;
            break;
            case 131:
            pXPos() = 0x3180000;
            pYPos() = 0x1007D00;
            break;
            case 132:
            pXPos() = 0x3200000;
            pYPos() = 0x1007D00;
            break;
            case 133:
            pXPos() = 0x3280000;
            pYPos() = 0x1007D00;
            break;
            case 134:
            pXPos() = 0x3300000;
            pYPos() = 0x1007D00;
            break;
            case 135:
            pXPos() = 0x3380000;
            pYPos() = 0x1007D00;
            break;
            case 136:
            pXPos() = 0x3400000;
            pYPos() = 0x1007D00;
            break;
            case 137:
            pXPos() = 0x3480000;
            pYPos() = 0x1007D00;
            break;
            case 138:
            pXPos() = 0x3500000;
            pYPos() = 0x1007D00;
            break;
            case 139:
            pXPos() = 0x3580000;
            pYPos() = 0x1007D00;
            break;
            case 140:
            pXPos() = 0x3600000;
            pYPos() = 0x1007D00;
            break;
            case 141:
            pXPos() = 0x3680000;
            pYPos() = 0x1007D00;
            break;
            case 142:
            pXPos() = 0x3700000;
            pYPos() = 0x1007D00;
            break;
            case 143:
            pXPos() = 0x3780000;
            pYPos() = 0x1007D00;
            break;
            case 144:
            pXPos() = 0x3800000;
            pYPos() = 0x1007D00;
            break;
            case 145:
            pXPos() = 0x3880000;
            pYPos() = 0x1007D00;
            break;
            case 146:
            pXPos() = 0x3900000;
            pYPos() = 0x1007D00;
            break;
            case 147:
            pXPos() = 0x3980000;
            pYPos() = 0x1007D00;
            break;
            case 148:
            pXPos() = 0x3A00000;
            pYPos() = 0x1007D00;
            break;
            case 149:
            pXPos() = 0x3A80000;
            pYPos() = 0x1007D00;
            break;
            case 150:
            pXPos() = 0x3B00000;
            pYPos() = 0x1007D00;
            break;
            case 151:
            pXPos() = 0x3B80000;
            pYPos() = 0x1007D00;
            break;
            case 152:
            pXPos() = 0x3C00000;
            pYPos() = 0x1007D00;
            break;
            case 153:
            pXPos() = 0x3C80000;
            pYPos() = 0x1007D00;
            break;
            case 154:
            pXPos() = 0x3D00000;
            pYPos() = 0x1007D00;
            break;
            case 155:
            pXPos() = 0x3D80000;
            pYPos() = 0x1007D00;
            break;
            case 156:
            pXPos() = 0x3E00000;
            pYPos() = 0x1007D00;
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

void O_R6_TunnelPath8::ObjectPlayerInteraction()
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
