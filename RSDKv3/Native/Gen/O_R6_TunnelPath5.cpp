#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath5.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath5.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath5::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        if (pState() == PlayerStateID("Player_State_Death")) {
            self->state = 0;
        }
        self->values[0]++;
        pSpeed() = pXPos();
        pAnimationSpeed() = 240;
        switch (self->values[0]) {
            case 0:
            pXPos() = 0x7700;
            pYPos() = 0x9C00;
            break;
            case 1:
            pXPos() = 0x7700;
            pYPos() = 0x89C00;
            break;
            case 2:
            pXPos() = 0x7700;
            pYPos() = 0x109C00;
            break;
            case 3:
            pXPos() = 0x7700;
            pYPos() = 0x189C00;
            break;
            case 4:
            pXPos() = 0x7700;
            pYPos() = 0x209C00;
            break;
            case 5:
            pXPos() = 0x7700;
            pYPos() = 0x289C00;
            break;
            case 6:
            pXPos() = 0x7700;
            pYPos() = 0x309C00;
            break;
            case 7:
            pXPos() = 0x7700;
            pYPos() = 0x389C00;
            break;
            case 8:
            pXPos() = 0x7700;
            pYPos() = 0x409C00;
            break;
            case 9:
            pXPos() = 0x7700;
            pYPos() = 0x489C00;
            break;
            case 10:
            pXPos() = 0x7700;
            pYPos() = 0x509C00;
            break;
            case 11:
            pXPos() = 0x7700;
            pYPos() = 0x589C00;
            break;
            case 12:
            pXPos() = 0x7700;
            pYPos() = 0x609C00;
            break;
            case 13:
            pXPos() = 0x7700;
            pYPos() = 0x689C00;
            break;
            case 14:
            pXPos() = 0x7700;
            pYPos() = 0x709C00;
            break;
            case 15:
            pXPos() = 0x7700;
            pYPos() = 0x789C00;
            break;
            case 16:
            pXPos() = 0x7700;
            pYPos() = 0x809C00;
            break;
            case 17:
            pXPos() = 0x7700;
            pYPos() = 0x889C00;
            break;
            case 18:
            pXPos() = 0x7700;
            pYPos() = 0x909C00;
            break;
            case 19:
            pXPos() = 0x7700;
            pYPos() = 0x989C00;
            break;
            case 20:
            pXPos() = 0x7700;
            pYPos() = 0xA09C00;
            break;
            case 21:
            pXPos() = 0x7700;
            pYPos() = 0xA89C00;
            break;
            case 22:
            pXPos() = 0x7700;
            pYPos() = 0xB09C00;
            break;
            case 23:
            pXPos() = 0x7700;
            pYPos() = 0xB89C00;
            break;
            case 24:
            pXPos() = 0x7700;
            pYPos() = 0xC09C00;
            break;
            case 25:
            pXPos() = 0x7700;
            pYPos() = 0xC89C00;
            break;
            case 26:
            pXPos() = 0x7700;
            pYPos() = 0xD09C00;
            break;
            case 27:
            pXPos() = 0x7700;
            pYPos() = 0xD89C00;
            break;
            case 28:
            pXPos() = 0x7700;
            pYPos() = 0xE09C00;
            break;
            case 29:
            pXPos() = 0x7700;
            pYPos() = 0xE89C00;
            break;
            case 30:
            pXPos() = 0x7700;
            pYPos() = 0xF09C00;
            break;
            case 31:
            pXPos() = 0x7700;
            pYPos() = 0xF89C00;
            break;
            case 32:
            pXPos() = 0x7700;
            pYPos() = 0x1009C00;
            break;
            case 33:
            pXPos() = 0x7700;
            pYPos() = 0x1089C00;
            break;
            case 34:
            pXPos() = 0x7700;
            pYPos() = 0x1109C00;
            break;
            case 35:
            pXPos() = 0x7700;
            pYPos() = 0x1189C00;
            break;
            case 36:
            pXPos() = 0x7700;
            pYPos() = 0x1209C00;
            break;
            case 37:
            pXPos() = 0x7700;
            pYPos() = 0x1289C00;
            break;
            case 38:
            pXPos() = 0x7700;
            pYPos() = 0x1309C00;
            break;
            case 39:
            pXPos() = 0x7700;
            pYPos() = 0x1389C00;
            break;
            case 40:
            pXPos() = 0x7700;
            pYPos() = 0x1409C00;
            break;
            case 41:
            pXPos() = 0x7700;
            pYPos() = 0x1489C00;
            break;
            case 42:
            pXPos() = 0x7700;
            pYPos() = 0x1509C00;
            break;
            case 43:
            pXPos() = 0x7700;
            pYPos() = 0x1589C00;
            break;
            case 44:
            pXPos() = 0x7700;
            pYPos() = 0x1609C00;
            break;
            case 45:
            pXPos() = 0x7700;
            pYPos() = 0x1689C00;
            break;
            case 46:
            pXPos() = 0x7700;
            pYPos() = 0x1709C00;
            break;
            case 47:
            pXPos() = 0x7700;
            pYPos() = 0x1789C00;
            break;
            case 48:
            pXPos() = 0x7700;
            pYPos() = 0x1809C00;
            break;
            case 49:
            pXPos() = 0x7700;
            pYPos() = 0x1889C00;
            break;
            case 50:
            pXPos() = 0x7700;
            pYPos() = 0x1909C00;
            break;
            case 51:
            pXPos() = 0x7700;
            pYPos() = 0x1989C00;
            break;
            case 52:
            pXPos() = 0x7700;
            pYPos() = 0x1A09C00;
            break;
            case 53:
            pXPos() = 0x7700;
            pYPos() = 0x1A89C00;
            break;
            case 54:
            pXPos() = 0x7700;
            pYPos() = 0x1B09C00;
            break;
            case 55:
            pXPos() = 0x7700;
            pYPos() = 0x1B89C00;
            break;
            case 56:
            pXPos() = 0x7700;
            pYPos() = 0x1C09C00;
            break;
            case 57:
            pXPos() = 0x7700;
            pYPos() = 0x1C89C00;
            break;
            case 58:
            pXPos() = 0x7700;
            pYPos() = 0x1D09C00;
            break;
            case 59:
            pXPos() = 0x7700;
            pYPos() = 0x1D89C00;
            break;
            case 60:
            pXPos() = 0x7700;
            pYPos() = 0x1E09C00;
            break;
            case 61:
            pXPos() = 0x7700;
            pYPos() = 0x1E89C00;
            break;
            case 62:
            pXPos() = 0x7700;
            pYPos() = 0x1F09C00;
            break;
            case 63:
            pXPos() = 0x7700;
            pYPos() = 0x1F89C00;
            break;
            case 64:
            pXPos() = 0x7700;
            pYPos() = 0x2009C00;
            break;
            case 65:
            pXPos() = 0x7700;
            pYPos() = 0x2089C00;
            break;
            case 66:
            pXPos() = 0x7700;
            pYPos() = 0x2109C00;
            break;
            case 67:
            pXPos() = 0x7700;
            pYPos() = 0x2189C00;
            break;
            case 68:
            pXPos() = 0x7700;
            pYPos() = 0x2209C00;
            break;
            case 69:
            pXPos() = 0x7700;
            pYPos() = 0x2289C00;
            break;
            case 70:
            pXPos() = 0x7700;
            pYPos() = 0x2309C00;
            break;
            case 71:
            pXPos() = 0x7700;
            pYPos() = 0x2389C00;
            break;
            case 72:
            pXPos() = 0x7700;
            pYPos() = 0x2409C00;
            break;
            case 73:
            pXPos() = 0x7700;
            pYPos() = 0x2489C00;
            break;
            case 74:
            pXPos() = 0x7700;
            pYPos() = 0x2509C00;
            break;
            case 75:
            pXPos() = 0x7700;
            pYPos() = 0x2589C00;
            break;
            case 76:
            pXPos() = 0x7700;
            pYPos() = 0x2609C00;
            break;
            case 77:
            pXPos() = 0x7700;
            pYPos() = 0x2689C00;
            break;
            case 78:
            pXPos() = 0x7700;
            pYPos() = 0x2709C00;
            break;
            case 79:
            pXPos() = 0x7700;
            pYPos() = 0x2789C00;
            break;
            case 80:
            pXPos() = 0x7700;
            pYPos() = 0x2809C00;
            break;
            case 81:
            pXPos() = 0x7700;
            pYPos() = 0x2889C00;
            break;
            case 82:
            pXPos() = 0x7700;
            pYPos() = 0x2909C00;
            break;
            case 83:
            pXPos() = 0x7700;
            pYPos() = 0x2989C00;
            break;
            case 84:
            pXPos() = 0x7700;
            pYPos() = 0x2A09C00;
            break;
            case 85:
            pXPos() = 0x7700;
            pYPos() = 0x2A89C00;
            break;
            case 86:
            pXPos() = -0x78900;
            pYPos() = 0x2A89C00;
            break;
            case 87:
            pXPos() = -0xF8900;
            pYPos() = 0x2A89C00;
            break;
            case 88:
            pXPos() = -0x178900;
            pYPos() = 0x2A89C00;
            break;
            case 89:
            pXPos() = -0x1F8900;
            pYPos() = 0x2A89C00;
            break;
            case 90:
            pXPos() = -0x278900;
            pYPos() = 0x2A89C00;
            break;
            case 91:
            pXPos() = -0x2F8900;
            pYPos() = 0x2A89C00;
            break;
            case 92:
            pXPos() = -0x378900;
            pYPos() = 0x2A89C00;
            break;
            case 93:
            pXPos() = -0x3F8900;
            pYPos() = 0x2A89C00;
            break;
            case 94:
            pXPos() = -0x478900;
            pYPos() = 0x2A89C00;
            break;
            case 95:
            pXPos() = -0x4F8900;
            pYPos() = 0x2A89C00;
            break;
            case 96:
            pXPos() = -0x578900;
            pYPos() = 0x2A89C00;
            break;
            case 97:
            pXPos() = -0x5F8900;
            pYPos() = 0x2A89C00;
            break;
            case 98:
            pXPos() = -0x678900;
            pYPos() = 0x2A89C00;
            break;
            case 99:
            pXPos() = -0x6F8900;
            pYPos() = 0x2A89C00;
            break;
            case 100:
            pXPos() = -0x778900;
            pYPos() = 0x2A89C00;
            break;
            case 101:
            pXPos() = -0x778900;
            pYPos() = 0x2B09C00;
            break;
            case 102:
            pXPos() = -0x778900;
            pYPos() = 0x2B89C00;
            break;
            case 103:
            pXPos() = -0x778900;
            pYPos() = 0x2C09C00;
            break;
            case 104:
            pXPos() = -0x778900;
            pYPos() = 0x2C89C00;
            break;
            case 105:
            pXPos() = -0x778900;
            pYPos() = 0x2D09C00;
            break;
            case 106:
            pXPos() = -0x778900;
            pYPos() = 0x2D89C00;
            break;
            case 107:
            pXPos() = -0x778900;
            pYPos() = 0x2E09C00;
            break;
            case 108:
            pXPos() = -0x778900;
            pYPos() = 0x2E89C00;
            break;
            case 109:
            pXPos() = -0x778900;
            pYPos() = 0x2F09C00;
            break;
            case 110:
            pXPos() = -0x778900;
            pYPos() = 0x2F89C00;
            break;
            case 111:
            pXPos() = -0x778900;
            pYPos() = 0x3009C00;
            break;
            case 112:
            pXPos() = -0x778900;
            pYPos() = 0x3089C00;
            break;
            case 113:
            pXPos() = -0x778900;
            pYPos() = 0x3109C00;
            break;
            case 114:
            pXPos() = -0x778900;
            pYPos() = 0x3189C00;
            break;
            case 115:
            pXPos() = -0x778900;
            pYPos() = 0x3209C00;
            break;
            case 116:
            pXPos() = -0x778900;
            pYPos() = 0x3289C00;
            break;
            case 117:
            pXPos() = -0x778900;
            pYPos() = 0x3309C00;
            break;
            case 118:
            pXPos() = -0x778900;
            pYPos() = 0x3389C00;
            break;
            case 119:
            pXPos() = -0x778900;
            pYPos() = 0x3409C00;
            break;
            case 120:
            pXPos() = -0x778900;
            pYPos() = 0x3489C00;
            break;
            case 121:
            pXPos() = -0x778900;
            pYPos() = 0x3509C00;
            break;
            case 122:
            pXPos() = -0x778900;
            pYPos() = 0x3589C00;
            break;
            case 123:
            pXPos() = -0x6F8900;
            pYPos() = 0x3589C00;
            break;
            case 124:
            pXPos() = -0x678900;
            pYPos() = 0x3589C00;
            break;
            case 125:
            pXPos() = -0x5F8900;
            pYPos() = 0x3589C00;
            break;
            case 126:
            pXPos() = -0x578900;
            pYPos() = 0x3589C00;
            break;
            case 127:
            pXPos() = -0x4F8900;
            pYPos() = 0x3589C00;
            break;
            case 128:
            pXPos() = -0x478900;
            pYPos() = 0x3589C00;
            break;
            case 129:
            pXPos() = -0x3F8900;
            pYPos() = 0x3589C00;
            break;
            case 130:
            pXPos() = -0x378900;
            pYPos() = 0x3589C00;
            break;
            case 131:
            pXPos() = -0x2F8900;
            pYPos() = 0x3589C00;
            break;
            case 132:
            pXPos() = -0x278900;
            pYPos() = 0x3589C00;
            break;
            case 133:
            pXPos() = -0x1F8900;
            pYPos() = 0x3589C00;
            break;
            case 134:
            pXPos() = -0x178900;
            pYPos() = 0x3589C00;
            break;
            case 135:
            pXPos() = -0x1F8900;
            pYPos() = 0x3589C00;
            break;
            case 136:
            pXPos() = -0x278900;
            pYPos() = 0x3589C00;
            break;
            case 137:
            pXPos() = -0x2F8900;
            pYPos() = 0x3589C00;
            break;
            case 138:
            pXPos() = -0x378900;
            pYPos() = 0x3589C00;
            break;
            case 139:
            pXPos() = -0x3F8900;
            pYPos() = 0x3589C00;
            break;
            case 140:
            pXPos() = -0x478900;
            pYPos() = 0x3589C00;
            break;
            case 141:
            pXPos() = -0x478900;
            pYPos() = 0x3609C00;
            break;
            case 142:
            pXPos() = -0x478900;
            pYPos() = 0x3689C00;
            break;
            case 143:
            pXPos() = -0x478900;
            pYPos() = 0x3709C00;
            break;
            case 144:
            pXPos() = -0x478900;
            pYPos() = 0x3789C00;
            break;
            case 145:
            pXPos() = -0x478900;
            pYPos() = 0x3809C00;
            break;
            case 146:
            pXPos() = -0x478900;
            pYPos() = 0x3889C00;
            break;
            case 147:
            pXPos() = -0x478900;
            pYPos() = 0x3909C00;
            break;
            case 148:
            pXPos() = -0x478900;
            pYPos() = 0x3989C00;
            break;
            case 149:
            pXPos() = -0x478900;
            pYPos() = 0x3A09C00;
            break;
            case 150:
            pXPos() = -0x478900;
            pYPos() = 0x3A89C00;
            break;
            case 151:
            pXPos() = -0x478900;
            pYPos() = 0x3B09C00;
            break;
            case 152:
            pXPos() = -0x478900;
            pYPos() = 0x3B89C00;
            break;
            case 153:
            pXPos() = -0x478900;
            pYPos() = 0x3C09C00;
            break;
            case 154:
            pXPos() = -0x478900;
            pYPos() = 0x3C89C00;
            break;
            case 155:
            pXPos() = -0x478900;
            pYPos() = 0x3D09C00;
            break;
            case 156:
            pXPos() = -0x478900;
            pYPos() = 0x3D89C00;
            break;
            case 157:
            pXPos() = -0x478900;
            pYPos() = 0x3E09C00;
            break;
            case 158:
            pXPos() = -0x478900;
            pYPos() = 0x3E89C00;
            break;
            case 159:
            pXPos() = -0x478900;
            pYPos() = 0x3F09C00;
            break;
            case 160:
            pXPos() = -0x478900;
            pYPos() = 0x3F89C00;
            break;
            case 161:
            pXPos() = -0x478900;
            pYPos() = 0x4009C00;
            break;
            case 162:
            pXPos() = -0x478900;
            pYPos() = 0x4089C00;
            break;
            case 163:
            pXPos() = -0x478900;
            pYPos() = 0x4109C00;
            break;
            case 164:
            pXPos() = -0x478900;
            pYPos() = 0x4189C00;
            break;
            case 165:
            pXPos() = -0x478900;
            pYPos() = 0x4209C00;
            break;
            case 166:
            pXPos() = -0x478900;
            pYPos() = 0x4289C00;
            break;
            case 167:
            pXPos() = -0x478900;
            pYPos() = 0x4309C00;
            break;
            case 168:
            pXPos() = -0x478900;
            pYPos() = 0x4389C00;
            break;
            case 169:
            pXPos() = -0x478900;
            pYPos() = 0x4409C00;
            break;
            case 170:
            pXPos() = -0x478900;
            pYPos() = 0x4489C00;
            break;
            case 171:
            pXPos() = -0x478900;
            pYPos() = 0x4509C00;
            break;
            case 172:
            pXPos() = -0x478900;
            pYPos() = 0x4589C00;
            break;
            case 173:
            pXPos() = -0x478900;
            pYPos() = 0x4609C00;
            break;
            case 174:
            pXPos() = -0x478900;
            pYPos() = 0x4689C00;
            break;
            case 175:
            pXPos() = -0x478900;
            pYPos() = 0x4709C00;
            break;
            case 176:
            pXPos() = -0x478900;
            pYPos() = 0x4789C00;
            break;
            case 177:
            pXPos() = -0x478900;
            pYPos() = 0x4809C00;
            break;
            case 178:
            pXPos() = -0x478900;
            pYPos() = 0x4889C00;
            break;
            case 179:
            pXPos() = -0x478900;
            pYPos() = 0x4909C00;
            break;
            case 180:
            pXPos() = -0x478900;
            pYPos() = 0x4989C00;
            break;
            case 181:
            pXPos() = -0x478900;
            pYPos() = 0x4A09C00;
            break;
            case 182:
            pXPos() = -0x478900;
            pYPos() = 0x4A89C00;
            break;
            case 183:
            pXPos() = -0x478900;
            pYPos() = 0x4B09C00;
            break;
            case 184:
            pXPos() = -0x478900;
            pYPos() = 0x4B89C00;
            break;
            case 185:
            pXPos() = -0x478900;
            pYPos() = 0x4C09C00;
            break;
            case 186:
            pXPos() = -0x478900;
            pYPos() = 0x4C89C00;
            self->state = 0;
            self->priority = 0;
            pObjectInteractions() = 1;
            pXVel() = 0;
            pSpeed() = 0;
            pYVel() = 0x20000;
            pAnimation() = GVar("ANI_WALKING");
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

void O_R6_TunnelPath5::ObjectPlayerInteraction()
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
