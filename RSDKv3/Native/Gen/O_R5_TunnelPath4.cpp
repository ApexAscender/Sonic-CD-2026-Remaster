#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_TunnelPath4.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath4.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_TunnelPath4::ObjectMain()
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
            pXPos() = 0xC100;
            pYPos() = 0x83000;
            break;
            case 1:
            pXPos() = 0xC100;
            pYPos() = 0x123000;
            break;
            case 2:
            pXPos() = 0xC100;
            pYPos() = 0x1C3000;
            break;
            case 3:
            pXPos() = 0xC100;
            pYPos() = 0x203000;
            break;
            case 4:
            pXPos() = 0xAC100;
            pYPos() = 0x243000;
            break;
            case 5:
            pXPos() = 0x14C100;
            pYPos() = 0x283000;
            break;
            case 6:
            pXPos() = 0x1EC100;
            pYPos() = 0x2C3000;
            break;
            case 7:
            pXPos() = 0x28C100;
            pYPos() = 0x303000;
            break;
            case 8:
            pXPos() = 0x32C100;
            pYPos() = 0x343000;
            break;
            case 9:
            pXPos() = 0x3CC100;
            pYPos() = 0x383000;
            break;
            case 10:
            pXPos() = 0x46C100;
            pYPos() = 0x3C3000;
            break;
            case 11:
            pXPos() = 0x50C100;
            pYPos() = 0x403000;
            break;
            case 12:
            pXPos() = 0x46C100;
            pYPos() = 0x42B000;
            break;
            case 13:
            pXPos() = 0x3CC100;
            pYPos() = 0x453000;
            break;
            case 14:
            pXPos() = 0x32C100;
            pYPos() = 0x47B000;
            break;
            case 15:
            pXPos() = 0x28C100;
            pYPos() = 0x4A3000;
            break;
            case 16:
            pXPos() = 0x1EC100;
            pYPos() = 0x4CB000;
            break;
            case 17:
            pXPos() = 0x14C100;
            pYPos() = 0x4F3000;
            break;
            case 18:
            pXPos() = 0xAC100;
            pYPos() = 0x51B000;
            break;
            case 19:
            pXPos() = 0xC100;
            pYPos() = 0x543000;
            break;
            case 20:
            pXPos() = -0x93F00;
            pYPos() = 0x56B000;
            break;
            case 21:
            pXPos() = -0x133F00;
            pYPos() = 0x593000;
            break;
            case 22:
            pXPos() = -0x1D3F00;
            pYPos() = 0x5BB000;
            break;
            case 23:
            pXPos() = -0x273F00;
            pYPos() = 0x5E3000;
            break;
            case 24:
            pXPos() = -0x2F3F00;
            pYPos() = 0x603000;
            break;
            case 25:
            pXPos() = -0x253F00;
            pYPos() = 0x62B000;
            break;
            case 26:
            pXPos() = -0x1B3F00;
            pYPos() = 0x653000;
            break;
            case 27:
            pXPos() = -0x113F00;
            pYPos() = 0x67B000;
            break;
            case 28:
            pXPos() = -0x73F00;
            pYPos() = 0x6A3000;
            break;
            case 29:
            pXPos() = 0x2C100;
            pYPos() = 0x6CB000;
            break;
            case 30:
            pXPos() = 0xCC100;
            pYPos() = 0x6F3000;
            break;
            case 31:
            pXPos() = 0x16C100;
            pYPos() = 0x71B000;
            break;
            case 32:
            pXPos() = 0x20C100;
            pYPos() = 0x743000;
            break;
            case 33:
            pXPos() = 0x2AC100;
            pYPos() = 0x76B000;
            break;
            case 34:
            pXPos() = 0x34C100;
            pYPos() = 0x793000;
            break;
            case 35:
            pXPos() = 0x3EC100;
            pYPos() = 0x7BB000;
            break;
            case 36:
            pXPos() = 0x48C100;
            pYPos() = 0x7E3000;
            break;
            case 37:
            pXPos() = 0x50C100;
            pYPos() = 0x803000;
            break;
            case 38:
            pXPos() = 0x46C100;
            pYPos() = 0x82B000;
            break;
            case 39:
            pXPos() = 0x3CC100;
            pYPos() = 0x853000;
            break;
            case 40:
            pXPos() = 0x32C100;
            pYPos() = 0x87B000;
            break;
            case 41:
            pXPos() = 0x28C100;
            pYPos() = 0x8A3000;
            break;
            case 42:
            pXPos() = 0x1EC100;
            pYPos() = 0x8CB000;
            break;
            case 43:
            pXPos() = 0x14C100;
            pYPos() = 0x8F3000;
            break;
            case 44:
            pXPos() = 0xAC100;
            pYPos() = 0x91B000;
            break;
            case 45:
            pXPos() = 0xC100;
            pYPos() = 0x943000;
            break;
            case 46:
            pXPos() = -0x93F00;
            pYPos() = 0x96B000;
            break;
            case 47:
            pXPos() = -0x133F00;
            pYPos() = 0x993000;
            break;
            case 48:
            pXPos() = -0x1D3F00;
            pYPos() = 0x9BB000;
            break;
            case 49:
            pXPos() = -0x273F00;
            pYPos() = 0x9E3000;
            break;
            case 50:
            pXPos() = -0x2F3F00;
            pYPos() = 0xA03000;
            break;
            case 51:
            pXPos() = -0x253F00;
            pYPos() = 0xA2B000;
            break;
            case 52:
            pXPos() = -0x1B3F00;
            pYPos() = 0xA53000;
            break;
            case 53:
            pXPos() = -0x113F00;
            pYPos() = 0xA7B000;
            break;
            case 54:
            pXPos() = -0x73F00;
            pYPos() = 0xAA3000;
            break;
            case 55:
            pXPos() = 0x2C100;
            pYPos() = 0xACB000;
            break;
            case 56:
            pXPos() = 0xCC100;
            pYPos() = 0xAF3000;
            break;
            case 57:
            pXPos() = 0x16C100;
            pYPos() = 0xB1B000;
            break;
            case 58:
            pXPos() = 0x20C100;
            pYPos() = 0xB43000;
            break;
            case 59:
            pXPos() = 0x2AC100;
            pYPos() = 0xB6B000;
            break;
            case 60:
            pXPos() = 0x34C100;
            pYPos() = 0xB93000;
            break;
            case 61:
            pXPos() = 0x3EC100;
            pYPos() = 0xBBB000;
            break;
            case 62:
            pXPos() = 0x48C100;
            pYPos() = 0xBE3000;
            break;
            case 63:
            pXPos() = 0x50C100;
            pYPos() = 0xC03000;
            break;
            case 64:
            pXPos() = 0x46C100;
            pYPos() = 0xC2B000;
            break;
            case 65:
            pXPos() = 0x3CC100;
            pYPos() = 0xC53000;
            break;
            case 66:
            pXPos() = 0x32C100;
            pYPos() = 0xC7B000;
            break;
            case 67:
            pXPos() = 0x28C100;
            pYPos() = 0xCA3000;
            break;
            case 68:
            pXPos() = 0x1EC100;
            pYPos() = 0xCCB000;
            break;
            case 69:
            pXPos() = 0x14C100;
            pYPos() = 0xCF3000;
            break;
            case 70:
            pXPos() = 0xAC100;
            pYPos() = 0xD1B000;
            break;
            case 71:
            pXPos() = 0xC100;
            pYPos() = 0xD43000;
            break;
            case 72:
            pXPos() = -0x93F00;
            pYPos() = 0xD6B000;
            break;
            case 73:
            pXPos() = -0x133F00;
            pYPos() = 0xD93000;
            break;
            case 74:
            pXPos() = -0x1D3F00;
            pYPos() = 0xDBB000;
            break;
            case 75:
            pXPos() = -0x273F00;
            pYPos() = 0xDE3000;
            break;
            case 76:
            pXPos() = -0x2F3F00;
            pYPos() = 0xE03000;
            break;
            case 77:
            pXPos() = -0x253F00;
            pYPos() = 0xE2B000;
            break;
            case 78:
            pXPos() = -0x1B3F00;
            pYPos() = 0xE53000;
            break;
            case 79:
            pXPos() = -0x113F00;
            pYPos() = 0xE7B000;
            break;
            case 80:
            pXPos() = -0x73F00;
            pYPos() = 0xEA3000;
            break;
            case 81:
            pXPos() = 0x2C100;
            pYPos() = 0xECB000;
            break;
            case 82:
            pXPos() = 0xCC100;
            pYPos() = 0xEF3000;
            break;
            case 83:
            pXPos() = 0x16C100;
            pYPos() = 0xF1B000;
            break;
            case 84:
            pXPos() = 0x20C100;
            pYPos() = 0xF43000;
            break;
            case 85:
            pXPos() = 0x2AC100;
            pYPos() = 0xF6B000;
            break;
            case 86:
            pXPos() = 0x34C100;
            pYPos() = 0xF93000;
            break;
            case 87:
            pXPos() = 0x3EC100;
            pYPos() = 0xFBB000;
            break;
            case 88:
            pXPos() = 0x48C100;
            pYPos() = 0xFE3000;
            break;
            case 89:
            pXPos() = 0x50C100;
            pYPos() = 0x1003000;
            break;
            case 90:
            pXPos() = 0x46C100;
            pYPos() = 0x102B000;
            break;
            case 91:
            pXPos() = 0x3CC100;
            pYPos() = 0x1053000;
            break;
            case 92:
            pXPos() = 0x32C100;
            pYPos() = 0x107B000;
            break;
            case 93:
            pXPos() = 0x28C100;
            pYPos() = 0x10A3000;
            break;
            case 94:
            pXPos() = 0x1EC100;
            pYPos() = 0x10CB000;
            break;
            case 95:
            pXPos() = 0x14C100;
            pYPos() = 0x10F3000;
            break;
            case 96:
            pXPos() = 0xAC100;
            pYPos() = 0x111B000;
            break;
            case 97:
            pXPos() = 0xC100;
            pYPos() = 0x1143000;
            break;
            case 98:
            pXPos() = -0x93F00;
            pYPos() = 0x116B000;
            break;
            case 99:
            pXPos() = -0x133F00;
            pYPos() = 0x1193000;
            break;
            case 100:
            pXPos() = -0x1D3F00;
            pYPos() = 0x11BB000;
            break;
            case 101:
            pXPos() = -0x273F00;
            pYPos() = 0x11E3000;
            break;
            case 102:
            pXPos() = -0x2F3F00;
            pYPos() = 0x1203000;
            break;
            case 103:
            pXPos() = -0x253F00;
            pYPos() = 0x122B000;
            break;
            case 104:
            pXPos() = -0x1B3F00;
            pYPos() = 0x1253000;
            break;
            case 105:
            pXPos() = -0x113F00;
            pYPos() = 0x127B000;
            break;
            case 106:
            pXPos() = -0x73F00;
            pYPos() = 0x12A3000;
            break;
            case 107:
            pXPos() = 0x2C100;
            pYPos() = 0x12CB000;
            break;
            case 108:
            pXPos() = 0xCC100;
            pYPos() = 0x12F3000;
            break;
            case 109:
            pXPos() = 0x16C100;
            pYPos() = 0x131B000;
            break;
            case 110:
            pXPos() = 0x20C100;
            pYPos() = 0x1343000;
            break;
            case 111:
            pXPos() = 0x2AC100;
            pYPos() = 0x136B000;
            break;
            case 112:
            pXPos() = 0x34C100;
            pYPos() = 0x1393000;
            break;
            case 113:
            pXPos() = 0x3EC100;
            pYPos() = 0x13BB000;
            break;
            case 114:
            pXPos() = 0x48C100;
            pYPos() = 0x13E3000;
            break;
            case 115:
            pXPos() = 0x50C100;
            pYPos() = 0x1403000;
            break;
            case 116:
            pXPos() = 0x46C100;
            pYPos() = 0x142B000;
            break;
            case 117:
            pXPos() = 0x3CC100;
            pYPos() = 0x1453000;
            break;
            case 118:
            pXPos() = 0x32C100;
            pYPos() = 0x147B000;
            break;
            case 119:
            pXPos() = 0x28C100;
            pYPos() = 0x14A3000;
            break;
            case 120:
            pXPos() = 0x1EC100;
            pYPos() = 0x14CB000;
            break;
            case 121:
            pXPos() = 0x14C100;
            pYPos() = 0x14F3000;
            break;
            case 122:
            pXPos() = 0xAC100;
            pYPos() = 0x151B000;
            break;
            case 123:
            pXPos() = 0xC100;
            pYPos() = 0x1543000;
            break;
            case 124:
            pXPos() = -0x93F00;
            pYPos() = 0x156B000;
            break;
            case 125:
            pXPos() = -0x133F00;
            pYPos() = 0x1593000;
            break;
            case 126:
            pXPos() = -0x1D3F00;
            pYPos() = 0x15BB000;
            break;
            case 127:
            pXPos() = -0x273F00;
            pYPos() = 0x15E3000;
            break;
            case 128:
            pXPos() = -0x2F3F00;
            pYPos() = 0x1603000;
            break;
            case 129:
            pXPos() = -0x253F00;
            pYPos() = 0x162B000;
            break;
            case 130:
            pXPos() = -0x1B3F00;
            pYPos() = 0x1653000;
            break;
            case 131:
            pXPos() = -0x113F00;
            pYPos() = 0x167B000;
            break;
            case 132:
            pXPos() = -0x73F00;
            pYPos() = 0x16A3000;
            break;
            case 133:
            pXPos() = 0x2C100;
            pYPos() = 0x16CB000;
            break;
            case 134:
            pXPos() = 0xCC100;
            pYPos() = 0x16F3000;
            break;
            case 135:
            pXPos() = 0x16C100;
            pYPos() = 0x171B000;
            break;
            case 136:
            pXPos() = 0x20C100;
            pYPos() = 0x1743000;
            break;
            case 137:
            pXPos() = 0x2AC100;
            pYPos() = 0x176B000;
            break;
            case 138:
            pXPos() = 0x34C100;
            pYPos() = 0x1793000;
            break;
            case 139:
            pXPos() = 0x3EC100;
            pYPos() = 0x17BB000;
            break;
            case 140:
            pXPos() = 0x48C100;
            pYPos() = 0x17E3000;
            break;
            case 141:
            pXPos() = 0x50C100;
            pYPos() = 0x1803000;
            break;
            case 142:
            pXPos() = 0x46C100;
            pYPos() = 0x182B000;
            break;
            case 143:
            pXPos() = 0x3CC100;
            pYPos() = 0x1853000;
            break;
            case 144:
            pXPos() = 0x32C100;
            pYPos() = 0x187B000;
            break;
            case 145:
            pXPos() = 0x28C100;
            pYPos() = 0x18A3000;
            break;
            case 146:
            pXPos() = 0x1EC100;
            pYPos() = 0x18CB000;
            break;
            case 147:
            pXPos() = 0x14C100;
            pYPos() = 0x18F3000;
            break;
            case 148:
            pXPos() = 0xAC100;
            pYPos() = 0x191B000;
            break;
            case 149:
            pXPos() = 0xC100;
            pYPos() = 0x1943000;
            break;
            case 150:
            pXPos() = -0x93F00;
            pYPos() = 0x196B000;
            break;
            case 151:
            pXPos() = -0x133F00;
            pYPos() = 0x1993000;
            break;
            case 152:
            pXPos() = -0x1D3F00;
            pYPos() = 0x19BB000;
            break;
            case 153:
            pXPos() = -0x273F00;
            pYPos() = 0x19E3000;
            break;
            case 154:
            pXPos() = -0x2F3F00;
            pYPos() = 0x1A03000;
            break;
            case 155:
            pXPos() = -0x253F00;
            pYPos() = 0x1A67000;
            break;
            case 156:
            pXPos() = -0x1B3F00;
            pYPos() = 0x1ACB000;
            break;
            case 157:
            pXPos() = -0x113F00;
            pYPos() = 0x1B2F000;
            break;
            case 158:
            pXPos() = -0x73F00;
            pYPos() = 0x1B93000;
            break;
            case 159:
            pXPos() = 0x2C100;
            pYPos() = 0x1BF7000;
            break;
            case 160:
            pXPos() = 0xCC100;
            pYPos() = 0x1C5B000;
            break;
            case 161:
            pXPos() = 0x16C100;
            pYPos() = 0x1CBF000;
            break;
            case 162:
            pXPos() = 0x20C100;
            pYPos() = 0x1D23000;
            break;
            case 163:
            pXPos() = 0x2AC100;
            pYPos() = 0x1D87000;
            break;
            case 164:
            pXPos() = 0x34C100;
            pYPos() = 0x1DEB000;
            break;
            case 165:
            pXPos() = 0x3EC100;
            pYPos() = 0x1E4F000;
            break;
            case 166:
            pXPos() = 0x48C100;
            pYPos() = 0x1EB3000;
            self->state = 0;
            self->priority = 0;
            pXVel() = 0xA0000;
            pSpeed() = 0xA0000;
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

void O_R5_TunnelPath4::ObjectPlayerInteraction()
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
