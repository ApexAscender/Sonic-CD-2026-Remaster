#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath10.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath10.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath10::ObjectMain()
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
            pXPos() = 0x5200;
            pYPos() = 0x3500;
            break;
            case 1:
            pXPos() = 0x5200;
            pYPos() = 0x83500;
            break;
            case 2:
            pXPos() = 0x5200;
            pYPos() = 0x103500;
            break;
            case 3:
            pXPos() = 0x5200;
            pYPos() = 0x183500;
            break;
            case 4:
            pXPos() = 0x5200;
            pYPos() = 0x203500;
            break;
            case 5:
            pXPos() = 0x5200;
            pYPos() = 0x283500;
            break;
            case 6:
            pXPos() = 0x5200;
            pYPos() = 0x303500;
            break;
            case 7:
            pXPos() = 0x5200;
            pYPos() = 0x383500;
            break;
            case 8:
            pXPos() = 0x5200;
            pYPos() = 0x403500;
            break;
            case 9:
            pXPos() = 0x5200;
            pYPos() = 0x483500;
            break;
            case 10:
            pXPos() = 0x5200;
            pYPos() = 0x503500;
            break;
            case 11:
            pXPos() = 0x5200;
            pYPos() = 0x583500;
            break;
            case 12:
            pXPos() = 0x5200;
            pYPos() = 0x603500;
            break;
            case 13:
            pXPos() = 0x5200;
            pYPos() = 0x683500;
            break;
            case 14:
            pXPos() = 0x5200;
            pYPos() = 0x703500;
            break;
            case 15:
            pXPos() = 0x5200;
            pYPos() = 0x783500;
            break;
            case 16:
            pXPos() = 0x5200;
            pYPos() = 0x803500;
            break;
            case 17:
            pXPos() = 0x5200;
            pYPos() = 0x883500;
            break;
            case 18:
            pXPos() = 0x5200;
            pYPos() = 0x903500;
            break;
            case 19:
            pXPos() = 0x5200;
            pYPos() = 0x983500;
            break;
            case 20:
            pXPos() = 0x5200;
            pYPos() = 0xA03500;
            break;
            case 21:
            pXPos() = 0x5200;
            pYPos() = 0xA83500;
            break;
            case 22:
            pXPos() = 0x5200;
            pYPos() = 0xB03500;
            break;
            case 23:
            pXPos() = 0x5200;
            pYPos() = 0xB83500;
            break;
            case 24:
            pXPos() = 0x5200;
            pYPos() = 0xC03500;
            break;
            case 25:
            pXPos() = 0x5200;
            pYPos() = 0xC83500;
            break;
            case 26:
            pXPos() = 0x5200;
            pYPos() = 0xD03500;
            break;
            case 27:
            pXPos() = 0x5200;
            pYPos() = 0xD83500;
            break;
            case 28:
            pXPos() = 0x5200;
            pYPos() = 0xE03500;
            break;
            case 29:
            pXPos() = 0x5200;
            pYPos() = 0xE83500;
            break;
            case 30:
            pXPos() = 0x5200;
            pYPos() = 0xF03500;
            break;
            case 31:
            pXPos() = 0x5200;
            pYPos() = 0xF83500;
            break;
            case 32:
            pXPos() = 0x5200;
            pYPos() = 0x1003500;
            break;
            case 33:
            pXPos() = 0x5200;
            pYPos() = 0x1083500;
            break;
            case 34:
            pXPos() = 0x5200;
            pYPos() = 0x1103500;
            break;
            case 35:
            pXPos() = 0x5200;
            pYPos() = 0x1183500;
            break;
            case 36:
            pXPos() = 0x5200;
            pYPos() = 0x1203500;
            break;
            case 37:
            pXPos() = 0x5200;
            pYPos() = 0x1283500;
            break;
            case 38:
            pXPos() = 0x5200;
            pYPos() = 0x1303500;
            break;
            case 39:
            pXPos() = 0x5200;
            pYPos() = 0x1383500;
            break;
            case 40:
            pXPos() = 0x5200;
            pYPos() = 0x1403500;
            break;
            case 41:
            pXPos() = 0x5200;
            pYPos() = 0x1483500;
            break;
            case 42:
            pXPos() = 0x5200;
            pYPos() = 0x1503500;
            break;
            case 43:
            pXPos() = 0x5200;
            pYPos() = 0x1583500;
            break;
            case 44:
            pXPos() = 0x5200;
            pYPos() = 0x1603500;
            break;
            case 45:
            pXPos() = 0x5200;
            pYPos() = 0x1683500;
            break;
            case 46:
            pXPos() = 0x5200;
            pYPos() = 0x1703500;
            break;
            case 47:
            pXPos() = 0x5200;
            pYPos() = 0x1783500;
            break;
            case 48:
            pXPos() = 0x5200;
            pYPos() = 0x1803500;
            break;
            case 49:
            pXPos() = 0x5200;
            pYPos() = 0x1883500;
            break;
            case 50:
            pXPos() = 0x5200;
            pYPos() = 0x1903500;
            break;
            case 51:
            pXPos() = 0x5200;
            pYPos() = 0x1983500;
            break;
            case 52:
            pXPos() = 0x5200;
            pYPos() = 0x1A03500;
            break;
            case 53:
            pXPos() = 0x5200;
            pYPos() = 0x1A83500;
            break;
            case 54:
            pXPos() = 0x5200;
            pYPos() = 0x1B03500;
            break;
            case 55:
            pXPos() = 0x5200;
            pYPos() = 0x1B83500;
            break;
            case 56:
            pXPos() = 0x5200;
            pYPos() = 0x1C03500;
            break;
            case 57:
            pXPos() = 0x5200;
            pYPos() = 0x1C83500;
            break;
            case 58:
            pXPos() = 0x5200;
            pYPos() = 0x1D03500;
            break;
            case 59:
            pXPos() = 0x5200;
            pYPos() = 0x1D83500;
            break;
            case 60:
            pXPos() = 0x5200;
            pYPos() = 0x1E03500;
            break;
            case 61:
            pXPos() = 0x5200;
            pYPos() = 0x1E83500;
            break;
            case 62:
            pXPos() = 0x5200;
            pYPos() = 0x1F03500;
            break;
            case 63:
            pXPos() = 0x5200;
            pYPos() = 0x1F83500;
            break;
            case 64:
            pXPos() = 0x5200;
            pYPos() = 0x2003500;
            break;
            case 65:
            pXPos() = 0x5200;
            pYPos() = 0x2083500;
            break;
            case 66:
            pXPos() = 0x5200;
            pYPos() = 0x2103500;
            break;
            case 67:
            pXPos() = 0x5200;
            pYPos() = 0x2183500;
            break;
            case 68:
            pXPos() = 0x5200;
            pYPos() = 0x2203500;
            break;
            case 69:
            pXPos() = 0x5200;
            pYPos() = 0x2283500;
            break;
            case 70:
            pXPos() = 0x5200;
            pYPos() = 0x2303500;
            break;
            case 71:
            pXPos() = 0x5200;
            pYPos() = 0x2383500;
            break;
            case 72:
            pXPos() = 0x5200;
            pYPos() = 0x2403500;
            break;
            case 73:
            pXPos() = 0x5200;
            pYPos() = 0x2483500;
            break;
            case 74:
            pXPos() = 0x5200;
            pYPos() = 0x2503500;
            break;
            case 75:
            pXPos() = 0x5200;
            pYPos() = 0x2583500;
            break;
            case 76:
            pXPos() = 0x5200;
            pYPos() = 0x2603500;
            break;
            case 77:
            pXPos() = 0x5200;
            pYPos() = 0x2683500;
            break;
            case 78:
            pXPos() = 0x5200;
            pYPos() = 0x2703500;
            break;
            case 79:
            pXPos() = 0x5200;
            pYPos() = 0x2783500;
            break;
            case 80:
            pXPos() = 0x5200;
            pYPos() = 0x2803500;
            break;
            case 81:
            pXPos() = 0x5200;
            pYPos() = 0x2883500;
            break;
            case 82:
            pXPos() = 0x5200;
            pYPos() = 0x2903500;
            break;
            case 83:
            pXPos() = 0x5200;
            pYPos() = 0x2983500;
            break;
            case 84:
            pXPos() = 0x5200;
            pYPos() = 0x2A03500;
            break;
            case 85:
            pXPos() = 0x5200;
            pYPos() = 0x2A83500;
            break;
            case 86:
            pXPos() = 0x5200;
            pYPos() = 0x2B03500;
            break;
            case 87:
            pXPos() = 0x5200;
            pYPos() = 0x2B83500;
            break;
            case 88:
            pXPos() = -0x7AE00;
            pYPos() = 0x2B83500;
            break;
            case 89:
            pXPos() = -0xFAE00;
            pYPos() = 0x2B83500;
            break;
            case 90:
            pXPos() = -0x17AE00;
            pYPos() = 0x2B83500;
            break;
            case 91:
            pXPos() = -0x1FAE00;
            pYPos() = 0x2B83500;
            break;
            case 92:
            pXPos() = -0x27AE00;
            pYPos() = 0x2B83500;
            break;
            case 93:
            pXPos() = -0x2FAE00;
            pYPos() = 0x2B83500;
            break;
            case 94:
            pXPos() = -0x37AE00;
            pYPos() = 0x2B83500;
            break;
            case 95:
            pXPos() = -0x3FAE00;
            pYPos() = 0x2B83500;
            break;
            case 96:
            pXPos() = -0x47AE00;
            pYPos() = 0x2B83500;
            break;
            case 97:
            pXPos() = -0x4FAE00;
            pYPos() = 0x2B83500;
            break;
            case 98:
            pXPos() = -0x57AE00;
            pYPos() = 0x2B83500;
            break;
            case 99:
            pXPos() = -0x5FAE00;
            pYPos() = 0x2B83500;
            break;
            case 100:
            pXPos() = -0x67AE00;
            pYPos() = 0x2B83500;
            break;
            case 101:
            pXPos() = -0x6FAE00;
            pYPos() = 0x2B83500;
            break;
            case 102:
            pXPos() = -0x77AE00;
            pYPos() = 0x2B83500;
            break;
            case 103:
            pXPos() = -0x77AE00;
            pYPos() = 0x2C03500;
            break;
            case 104:
            pXPos() = -0x77AE00;
            pYPos() = 0x2C83500;
            break;
            case 105:
            pXPos() = -0x77AE00;
            pYPos() = 0x2D03500;
            break;
            case 106:
            pXPos() = -0x77AE00;
            pYPos() = 0x2D83500;
            break;
            case 107:
            pXPos() = -0x77AE00;
            pYPos() = 0x2E03500;
            break;
            case 108:
            pXPos() = -0x77AE00;
            pYPos() = 0x2E83500;
            break;
            case 109:
            pXPos() = -0x77AE00;
            pYPos() = 0x2F03500;
            break;
            case 110:
            pXPos() = -0x77AE00;
            pYPos() = 0x2F83500;
            break;
            case 111:
            pXPos() = -0x77AE00;
            pYPos() = 0x3003500;
            break;
            case 112:
            pXPos() = -0x77AE00;
            pYPos() = 0x3083500;
            break;
            case 113:
            pXPos() = -0x77AE00;
            pYPos() = 0x3103500;
            break;
            case 114:
            pXPos() = -0x77AE00;
            pYPos() = 0x3183500;
            break;
            case 115:
            pXPos() = -0x77AE00;
            pYPos() = 0x3203500;
            break;
            case 116:
            pXPos() = -0x77AE00;
            pYPos() = 0x3283500;
            break;
            case 117:
            pXPos() = -0x77AE00;
            pYPos() = 0x3303500;
            break;
            case 118:
            pXPos() = -0x77AE00;
            pYPos() = 0x3383500;
            break;
            case 119:
            pXPos() = -0x77AE00;
            pYPos() = 0x3403500;
            break;
            case 120:
            pXPos() = -0x77AE00;
            pYPos() = 0x3483500;
            break;
            case 121:
            pXPos() = -0x77AE00;
            pYPos() = 0x3503500;
            break;
            case 122:
            pXPos() = -0x77AE00;
            pYPos() = 0x3583500;
            break;
            case 123:
            pXPos() = -0x77AE00;
            pYPos() = 0x3603500;
            break;
            case 124:
            pXPos() = -0x77AE00;
            pYPos() = 0x3683500;
            break;
            case 125:
            pXPos() = -0x6FAE00;
            pYPos() = 0x3683500;
            break;
            case 126:
            pXPos() = -0x67AE00;
            pYPos() = 0x3683500;
            break;
            case 127:
            pXPos() = -0x5FAE00;
            pYPos() = 0x3683500;
            break;
            case 128:
            pXPos() = -0x57AE00;
            pYPos() = 0x3683500;
            break;
            case 129:
            pXPos() = -0x4FAE00;
            pYPos() = 0x3683500;
            break;
            case 130:
            pXPos() = -0x47AE00;
            pYPos() = 0x3683500;
            break;
            case 131:
            pXPos() = -0x3FAE00;
            pYPos() = 0x3683500;
            break;
            case 132:
            pXPos() = -0x37AE00;
            pYPos() = 0x3683500;
            break;
            case 133:
            pXPos() = -0x2FAE00;
            pYPos() = 0x3683500;
            break;
            case 134:
            pXPos() = -0x27AE00;
            pYPos() = 0x3683500;
            break;
            case 135:
            pXPos() = -0x1FAE00;
            pYPos() = 0x3683500;
            break;
            case 136:
            pXPos() = -0x17AE00;
            pYPos() = 0x3683500;
            break;
            case 137:
            pXPos() = -0x1C7A00;
            pYPos() = 0x3703500;
            break;
            case 138:
            pXPos() = -0x214600;
            pYPos() = 0x3783500;
            break;
            case 139:
            pXPos() = -0x261200;
            pYPos() = 0x3803500;
            break;
            case 140:
            pXPos() = -0x2ADE00;
            pYPos() = 0x3883500;
            break;
            case 141:
            pXPos() = -0x2FAA00;
            pYPos() = 0x3903500;
            break;
            case 142:
            pXPos() = -0x347600;
            pYPos() = 0x3983500;
            break;
            case 143:
            pXPos() = -0x394200;
            pYPos() = 0x3A03500;
            break;
            case 144:
            pXPos() = -0x3E0E00;
            pYPos() = 0x3A83500;
            break;
            case 145:
            pXPos() = -0x42DA00;
            pYPos() = 0x3B03500;
            break;
            case 146:
            pXPos() = -0x47A600;
            pYPos() = 0x3B83500;
            break;
            case 147:
            pXPos() = -0x4FA600;
            pYPos() = 0x3B83500;
            break;
            case 148:
            pXPos() = -0x57A600;
            pYPos() = 0x3B83500;
            break;
            case 149:
            pXPos() = -0x5FA600;
            pYPos() = 0x3B83500;
            break;
            case 150:
            pXPos() = -0x67A600;
            pYPos() = 0x3B83500;
            break;
            case 151:
            pXPos() = -0x6FA600;
            pYPos() = 0x3B83500;
            break;
            case 152:
            pXPos() = -0x77A600;
            pYPos() = 0x3B83500;
            break;
            case 153:
            pXPos() = -0x7FA600;
            pYPos() = 0x3B83500;
            break;
            case 154:
            pXPos() = -0x87A600;
            pYPos() = 0x3B83500;
            break;
            case 155:
            pXPos() = -0x8FA600;
            pYPos() = 0x3B83500;
            break;
            case 156:
            pXPos() = -0x97A600;
            pYPos() = 0x3B83500;
            break;
            case 157:
            pXPos() = -0x9FA600;
            pYPos() = 0x3B83500;
            break;
            case 158:
            pXPos() = -0xA7A600;
            pYPos() = 0x3B83500;
            break;
            case 159:
            pXPos() = -0x9FA600;
            pYPos() = 0x3B83500;
            break;
            case 160:
            pXPos() = -0x97A600;
            pYPos() = 0x3B83500;
            break;
            case 161:
            pXPos() = -0x8FA600;
            pYPos() = 0x3B83500;
            break;
            case 162:
            pXPos() = -0x87A600;
            pYPos() = 0x3B83500;
            break;
            case 163:
            pXPos() = -0x7FA600;
            pYPos() = 0x3B83500;
            break;
            case 164:
            pXPos() = -0x77A600;
            pYPos() = 0x3B83500;
            break;
            case 165:
            pXPos() = -0x6FA600;
            pYPos() = 0x3B83500;
            break;
            case 166:
            pXPos() = -0x67A600;
            pYPos() = 0x3B83500;
            break;
            case 167:
            pXPos() = -0x5FA600;
            pYPos() = 0x3B83500;
            break;
            case 168:
            pXPos() = -0x57A600;
            pYPos() = 0x3B83500;
            break;
            case 169:
            pXPos() = -0x4FA600;
            pYPos() = 0x3B83500;
            break;
            case 170:
            pXPos() = -0x47A600;
            pYPos() = 0x3B83500;
            break;
            case 171:
            pXPos() = -0x47A600;
            pYPos() = 0x3C03500;
            break;
            case 172:
            pXPos() = -0x47A600;
            pYPos() = 0x3C83500;
            break;
            case 173:
            pXPos() = -0x47A600;
            pYPos() = 0x3D03500;
            break;
            case 174:
            pXPos() = -0x47A600;
            pYPos() = 0x3D83500;
            break;
            case 175:
            pXPos() = -0x47A600;
            pYPos() = 0x3E03500;
            break;
            case 176:
            pXPos() = -0x47A600;
            pYPos() = 0x3E83500;
            break;
            case 177:
            pXPos() = -0x47A600;
            pYPos() = 0x3F03500;
            break;
            case 178:
            pXPos() = -0x47A600;
            pYPos() = 0x3F83500;
            break;
            case 179:
            pXPos() = -0x3FA600;
            pYPos() = 0x3F83500;
            break;
            case 180:
            pXPos() = -0x37A600;
            pYPos() = 0x3F83500;
            break;
            case 181:
            pXPos() = -0x2FA600;
            pYPos() = 0x3F83500;
            break;
            case 182:
            pXPos() = -0x27A600;
            pYPos() = 0x3F83500;
            break;
            case 183:
            pXPos() = -0x1FA600;
            pYPos() = 0x3F83500;
            break;
            case 184:
            pXPos() = -0x17A600;
            pYPos() = 0x3F83500;
            break;
            case 185:
            pXPos() = -0xFA600;
            pYPos() = 0x3F83500;
            break;
            case 186:
            pXPos() = -0x7A600;
            pYPos() = 0x3F83500;
            break;
            case 187:
            pXPos() = 0x5A00;
            pYPos() = 0x3F83500;
            break;
            case 188:
            pXPos() = 0x85A00;
            pYPos() = 0x3F83500;
            break;
            case 189:
            pXPos() = 0x105A00;
            pYPos() = 0x3F83500;
            break;
            case 190:
            pXPos() = 0x185A00;
            pYPos() = 0x3F83500;
            break;
            case 191:
            pXPos() = 0x185A00;
            pYPos() = 0x4003500;
            break;
            case 192:
            pXPos() = 0x185A00;
            pYPos() = 0x4083500;
            break;
            case 193:
            pXPos() = 0x185A00;
            pYPos() = 0x4103500;
            break;
            case 194:
            pXPos() = 0x185A00;
            pYPos() = 0x4183500;
            break;
            case 195:
            pXPos() = 0x185A00;
            pYPos() = 0x4203500;
            break;
            case 196:
            pXPos() = 0x185A00;
            pYPos() = 0x4283500;
            break;
            case 197:
            pXPos() = 0x185A00;
            pYPos() = 0x4303500;
            break;
            case 198:
            pXPos() = 0x185A00;
            pYPos() = 0x4383500;
            break;
            case 199:
            pXPos() = 0x185A00;
            pYPos() = 0x4403500;
            break;
            case 200:
            pXPos() = 0x185A00;
            pYPos() = 0x4483500;
            break;
            case 201:
            pXPos() = 0x185A00;
            pYPos() = 0x4503500;
            break;
            case 202:
            pXPos() = 0x185A00;
            pYPos() = 0x4583500;
            break;
            case 203:
            pXPos() = 0x105A00;
            pYPos() = 0x4583500;
            break;
            case 204:
            pXPos() = 0x85A00;
            pYPos() = 0x4583500;
            break;
            case 205:
            pXPos() = 0x5A00;
            pYPos() = 0x4583500;
            break;
            case 206:
            pXPos() = -0x7A600;
            pYPos() = 0x4583500;
            break;
            case 207:
            pXPos() = -0xFA600;
            pYPos() = 0x4583500;
            break;
            case 208:
            pXPos() = -0x17A600;
            pYPos() = 0x4583500;
            break;
            case 209:
            pXPos() = -0x1FA600;
            pYPos() = 0x4583500;
            break;
            case 210:
            pXPos() = -0x27A600;
            pYPos() = 0x4583500;
            break;
            case 211:
            pXPos() = -0x2FA600;
            pYPos() = 0x4583500;
            break;
            case 212:
            pXPos() = -0x37A600;
            pYPos() = 0x4583500;
            break;
            case 213:
            pXPos() = -0x37A600;
            pYPos() = 0x4603500;
            break;
            case 214:
            pXPos() = -0x37A600;
            pYPos() = 0x4683500;
            break;
            case 215:
            pXPos() = -0x37A600;
            pYPos() = 0x4703500;
            break;
            case 216:
            pXPos() = -0x37A600;
            pYPos() = 0x4783500;
            break;
            case 217:
            pXPos() = -0x37A600;
            pYPos() = 0x4803500;
            break;
            case 218:
            pXPos() = -0x37A600;
            pYPos() = 0x4883500;
            break;
            case 219:
            pXPos() = -0x37A600;
            pYPos() = 0x4903500;
            break;
            case 220:
            pXPos() = -0x37A600;
            pYPos() = 0x4983500;
            break;
            case 221:
            pXPos() = -0x37A600;
            pYPos() = 0x4A03500;
            break;
            case 222:
            pXPos() = -0x37A600;
            pYPos() = 0x4A83500;
            break;
            case 223:
            pXPos() = -0x37A600;
            pYPos() = 0x4B03500;
            break;
            case 224:
            pXPos() = -0x37A600;
            pYPos() = 0x4B83500;
            break;
            case 225:
            pXPos() = -0x37A600;
            pYPos() = 0x4C03500;
            break;
            case 226:
            pXPos() = -0x37A600;
            pYPos() = 0x4C83500;
            break;
            case 227:
            pXPos() = -0x37A600;
            pYPos() = 0x4D03500;
            break;
            case 228:
            pXPos() = -0x37A600;
            pYPos() = 0x4D83500;
            break;
            case 229:
            pXPos() = -0x37A600;
            pYPos() = 0x4E03500;
            break;
            case 230:
            pXPos() = -0x37A600;
            pYPos() = 0x4E83500;
            self->state = 0;
            self->priority = 0;
            pObjectInteractions() = 1;
            pXVel() = 0;
            pSpeed() = 0;
            pYVel() = 0x20000;
            pAnimation() = GVar("ANI_JUMPING");
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

void O_R6_TunnelPath10::ObjectPlayerInteraction()
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
