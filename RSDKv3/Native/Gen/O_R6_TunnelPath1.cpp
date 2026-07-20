#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath1.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath1.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath1::ObjectMain()
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
            pXPos() = 0x2000;
            pYPos() = 0x1500;
            break;
            case 1:
            pXPos() = 0x2000;
            pYPos() = 0x81500;
            break;
            case 2:
            pXPos() = 0x2000;
            pYPos() = 0x101500;
            break;
            case 3:
            pXPos() = 0x2000;
            pYPos() = 0x181500;
            break;
            case 4:
            pXPos() = 0x2000;
            pYPos() = 0x201500;
            break;
            case 5:
            pXPos() = 0x2000;
            pYPos() = 0x281500;
            break;
            case 6:
            pXPos() = 0x2000;
            pYPos() = 0x301500;
            break;
            case 7:
            pXPos() = 0x2000;
            pYPos() = 0x381500;
            break;
            case 8:
            pXPos() = 0x2000;
            pYPos() = 0x401500;
            break;
            case 9:
            pXPos() = 0x2000;
            pYPos() = 0x481500;
            break;
            case 10:
            pXPos() = 0x2000;
            pYPos() = 0x501500;
            break;
            case 11:
            pXPos() = 0x2000;
            pYPos() = 0x581500;
            break;
            case 12:
            pXPos() = 0x2000;
            pYPos() = 0x601500;
            break;
            case 13:
            pXPos() = 0x2000;
            pYPos() = 0x681500;
            break;
            case 14:
            pXPos() = 0x2000;
            pYPos() = 0x701500;
            break;
            case 15:
            pXPos() = 0x2000;
            pYPos() = 0x781500;
            break;
            case 16:
            pXPos() = 0x2000;
            pYPos() = 0x801500;
            break;
            case 17:
            pXPos() = 0x2000;
            pYPos() = 0x881500;
            break;
            case 18:
            pXPos() = 0x2000;
            pYPos() = 0x901500;
            break;
            case 19:
            pXPos() = 0x2000;
            pYPos() = 0x981500;
            break;
            case 20:
            pXPos() = 0x2000;
            pYPos() = 0xA01500;
            break;
            case 21:
            pXPos() = 0x2000;
            pYPos() = 0xA81500;
            break;
            case 22:
            pXPos() = 0x2000;
            pYPos() = 0xB01500;
            break;
            case 23:
            pXPos() = 0x2000;
            pYPos() = 0xB81500;
            break;
            case 24:
            pXPos() = 0x2000;
            pYPos() = 0xC01500;
            break;
            case 25:
            pXPos() = 0x2000;
            pYPos() = 0xC81500;
            break;
            case 26:
            pXPos() = 0x2000;
            pYPos() = 0xD01500;
            break;
            case 27:
            pXPos() = 0x2000;
            pYPos() = 0xD81500;
            break;
            case 28:
            pXPos() = 0x2000;
            pYPos() = 0xE01500;
            break;
            case 29:
            pXPos() = 0x2000;
            pYPos() = 0xE81500;
            break;
            case 30:
            pXPos() = 0x2000;
            pYPos() = 0xF01500;
            break;
            case 31:
            pXPos() = 0x2000;
            pYPos() = 0xF81500;
            break;
            case 32:
            pXPos() = 0x2000;
            pYPos() = 0x1001500;
            break;
            case 33:
            pXPos() = 0x2000;
            pYPos() = 0x1081500;
            break;
            case 34:
            pXPos() = 0x2000;
            pYPos() = 0x1101500;
            break;
            case 35:
            pXPos() = 0x2000;
            pYPos() = 0x1181500;
            break;
            case 36:
            pXPos() = 0x2000;
            pYPos() = 0x1201500;
            break;
            case 37:
            pXPos() = 0x2000;
            pYPos() = 0x1281500;
            break;
            case 38:
            pXPos() = 0x2000;
            pYPos() = 0x1301500;
            break;
            case 39:
            pXPos() = 0x2000;
            pYPos() = 0x1381500;
            break;
            case 40:
            pXPos() = 0x2000;
            pYPos() = 0x1401500;
            break;
            case 41:
            pXPos() = 0x2000;
            pYPos() = 0x1481500;
            break;
            case 42:
            pXPos() = 0x2000;
            pYPos() = 0x1501500;
            break;
            case 43:
            pXPos() = -0x7E000;
            pYPos() = 0x1501500;
            break;
            case 44:
            pXPos() = -0xFE000;
            pYPos() = 0x1501500;
            break;
            case 45:
            pXPos() = -0x17E000;
            pYPos() = 0x1501500;
            break;
            case 46:
            pXPos() = -0x1FE000;
            pYPos() = 0x1501500;
            break;
            case 47:
            pXPos() = -0x27E000;
            pYPos() = 0x1501500;
            break;
            case 48:
            pXPos() = -0x2FE000;
            pYPos() = 0x1501500;
            break;
            case 49:
            pXPos() = -0x37E000;
            pYPos() = 0x1501500;
            break;
            case 50:
            pXPos() = -0x3FE000;
            pYPos() = 0x1501500;
            break;
            case 51:
            pXPos() = -0x47E000;
            pYPos() = 0x1501500;
            break;
            case 52:
            pXPos() = -0x4FE000;
            pYPos() = 0x1501500;
            break;
            case 53:
            pXPos() = -0x57E000;
            pYPos() = 0x1501500;
            break;
            case 54:
            pXPos() = -0x5FE000;
            pYPos() = 0x1501500;
            break;
            case 55:
            pXPos() = -0x67E000;
            pYPos() = 0x1501500;
            break;
            case 56:
            pXPos() = -0x67E000;
            pYPos() = 0x1581500;
            break;
            case 57:
            pXPos() = -0x67E000;
            pYPos() = 0x1601500;
            break;
            case 58:
            pXPos() = -0x67E000;
            pYPos() = 0x1681500;
            break;
            case 59:
            pXPos() = -0x67E000;
            pYPos() = 0x1701500;
            break;
            case 60:
            pXPos() = -0x67E000;
            pYPos() = 0x1781500;
            break;
            case 61:
            pXPos() = -0x67E000;
            pYPos() = 0x1801500;
            break;
            case 62:
            pXPos() = -0x67E000;
            pYPos() = 0x1881500;
            break;
            case 63:
            pXPos() = -0x67E000;
            pYPos() = 0x1901500;
            break;
            case 64:
            pXPos() = -0x67E000;
            pYPos() = 0x1981500;
            break;
            case 65:
            pXPos() = -0x67E000;
            pYPos() = 0x1A01500;
            break;
            case 66:
            pXPos() = -0x67E000;
            pYPos() = 0x1A81500;
            break;
            case 67:
            pXPos() = -0x67E000;
            pYPos() = 0x1B01500;
            break;
            case 68:
            pXPos() = -0x67E000;
            pYPos() = 0x1B81500;
            break;
            case 69:
            pXPos() = -0x67E000;
            pYPos() = 0x1C01500;
            break;
            case 70:
            pXPos() = -0x67E000;
            pYPos() = 0x1C81500;
            break;
            case 71:
            pXPos() = -0x67E000;
            pYPos() = 0x1D01500;
            break;
            case 72:
            pXPos() = -0x67E000;
            pYPos() = 0x1D81500;
            break;
            case 73:
            pXPos() = -0x67E000;
            pYPos() = 0x1E01500;
            break;
            case 74:
            pXPos() = -0x67E000;
            pYPos() = 0x1E81500;
            break;
            case 75:
            pXPos() = -0x67E000;
            pYPos() = 0x1F01500;
            break;
            case 76:
            pXPos() = -0x67E000;
            pYPos() = 0x1F81500;
            break;
            case 77:
            pXPos() = -0x67E000;
            pYPos() = 0x2001500;
            break;
            case 78:
            pXPos() = -0x5FE000;
            pYPos() = 0x2001500;
            break;
            case 79:
            pXPos() = -0x57E000;
            pYPos() = 0x2001500;
            break;
            case 80:
            pXPos() = -0x4FE000;
            pYPos() = 0x2001500;
            break;
            case 81:
            pXPos() = -0x47E000;
            pYPos() = 0x2001500;
            break;
            case 82:
            pXPos() = -0x3FE000;
            pYPos() = 0x2001500;
            break;
            case 83:
            pXPos() = -0x37E000;
            pYPos() = 0x2001500;
            break;
            case 84:
            pXPos() = -0x2FE000;
            pYPos() = 0x2001500;
            break;
            case 85:
            pXPos() = -0x27E000;
            pYPos() = 0x2001500;
            break;
            case 86:
            pXPos() = -0x1FE000;
            pYPos() = 0x2001500;
            break;
            case 87:
            pXPos() = -0x17E000;
            pYPos() = 0x2001500;
            break;
            case 88:
            pXPos() = -0xFE000;
            pYPos() = 0x2001500;
            break;
            case 89:
            pXPos() = -0x7E000;
            pYPos() = 0x2001500;
            break;
            case 90:
            pXPos() = -0xFE000;
            pYPos() = 0x2001500;
            break;
            case 91:
            pXPos() = -0x17E000;
            pYPos() = 0x2001500;
            break;
            case 92:
            pXPos() = -0x1FE000;
            pYPos() = 0x2001500;
            break;
            case 93:
            pXPos() = -0x27E000;
            pYPos() = 0x2001500;
            break;
            case 94:
            pXPos() = -0x2FE000;
            pYPos() = 0x2001500;
            break;
            case 95:
            pXPos() = -0x37E000;
            pYPos() = 0x2001500;
            break;
            case 96:
            pXPos() = -0x37E000;
            pYPos() = 0x2081500;
            break;
            case 97:
            pXPos() = -0x37E000;
            pYPos() = 0x2101500;
            break;
            case 98:
            pXPos() = -0x37E000;
            pYPos() = 0x2181500;
            break;
            case 99:
            pXPos() = -0x37E000;
            pYPos() = 0x2201500;
            break;
            case 100:
            pXPos() = -0x37E000;
            pYPos() = 0x2281500;
            break;
            case 101:
            pXPos() = -0x37E000;
            pYPos() = 0x2301500;
            break;
            case 102:
            pXPos() = -0x37E000;
            pYPos() = 0x2381500;
            break;
            case 103:
            pXPos() = -0x37E000;
            pYPos() = 0x2401500;
            break;
            case 104:
            pXPos() = -0x37E000;
            pYPos() = 0x2481500;
            break;
            case 105:
            pXPos() = -0x37E000;
            pYPos() = 0x2501500;
            break;
            case 106:
            pXPos() = -0x37E000;
            pYPos() = 0x2581500;
            break;
            case 107:
            pXPos() = -0x37E000;
            pYPos() = 0x2601500;
            break;
            case 108:
            pXPos() = -0x37E000;
            pYPos() = 0x2681500;
            break;
            case 109:
            pXPos() = -0x37E000;
            pYPos() = 0x2701500;
            break;
            case 110:
            pXPos() = -0x37E000;
            pYPos() = 0x2781500;
            break;
            case 111:
            pXPos() = -0x37E000;
            pYPos() = 0x2801500;
            break;
            case 112:
            pXPos() = -0x37E000;
            pYPos() = 0x2881500;
            break;
            case 113:
            pXPos() = -0x37E000;
            pYPos() = 0x2901500;
            break;
            case 114:
            pXPos() = -0x37E000;
            pYPos() = 0x2981500;
            break;
            case 115:
            pXPos() = -0x37E000;
            pYPos() = 0x2A01500;
            break;
            case 116:
            pXPos() = -0x37E000;
            pYPos() = 0x2A81500;
            break;
            case 117:
            pXPos() = -0x37E000;
            pYPos() = 0x2B01500;
            break;
            case 118:
            pXPos() = -0x37E000;
            pYPos() = 0x2B81500;
            break;
            case 119:
            pXPos() = -0x37E000;
            pYPos() = 0x2C01500;
            break;
            case 120:
            pXPos() = -0x37E000;
            pYPos() = 0x2C81500;
            break;
            case 121:
            pXPos() = -0x37E000;
            pYPos() = 0x2D01500;
            break;
            case 122:
            pXPos() = -0x37E000;
            pYPos() = 0x2D81500;
            break;
            case 123:
            pXPos() = -0x37E000;
            pYPos() = 0x2E01500;
            break;
            case 124:
            pXPos() = -0x37E000;
            pYPos() = 0x2E81500;
            break;
            case 125:
            pXPos() = -0x37E000;
            pYPos() = 0x2F01500;
            break;
            case 126:
            pXPos() = -0x37E000;
            pYPos() = 0x2F81500;
            break;
            case 127:
            pXPos() = -0x37E000;
            pYPos() = 0x3001500;
            break;
            case 128:
            pXPos() = -0x37E000;
            pYPos() = 0x3081500;
            break;
            case 129:
            pXPos() = -0x37E000;
            pYPos() = 0x3101500;
            break;
            case 130:
            pXPos() = -0x37E000;
            pYPos() = 0x3181500;
            break;
            case 131:
            pXPos() = -0x37E000;
            pYPos() = 0x3201500;
            break;
            case 132:
            pXPos() = -0x37E000;
            pYPos() = 0x3281500;
            break;
            case 133:
            pXPos() = -0x2FE000;
            pYPos() = 0x3281500;
            break;
            case 134:
            pXPos() = -0x27E000;
            pYPos() = 0x3281500;
            break;
            case 135:
            pXPos() = -0x1FE000;
            pYPos() = 0x3281500;
            break;
            case 136:
            pXPos() = -0x17E000;
            pYPos() = 0x3281500;
            break;
            case 137:
            pXPos() = -0xFE000;
            pYPos() = 0x3281500;
            break;
            case 138:
            pXPos() = -0x7E000;
            pYPos() = 0x3281500;
            break;
            case 139:
            pXPos() = 0x2000;
            pYPos() = 0x3281500;
            break;
            case 140:
            pXPos() = 0x82000;
            pYPos() = 0x3281500;
            break;
            case 141:
            pXPos() = 0x102000;
            pYPos() = 0x3281500;
            break;
            case 142:
            pXPos() = 0x182000;
            pYPos() = 0x3281500;
            break;
            case 143:
            pXPos() = 0x202000;
            pYPos() = 0x3281500;
            break;
            case 144:
            pXPos() = 0x282000;
            pYPos() = 0x3281500;
            break;
            case 145:
            pXPos() = 0x302000;
            pYPos() = 0x3281500;
            break;
            case 146:
            pXPos() = 0x382000;
            pYPos() = 0x3281500;
            break;
            case 147:
            pXPos() = 0x402000;
            pYPos() = 0x3281500;
            break;
            case 148:
            pXPos() = 0x482000;
            pYPos() = 0x3281500;
            break;
            case 149:
            pXPos() = 0x502000;
            pYPos() = 0x3281500;
            break;
            case 150:
            pXPos() = 0x582000;
            pYPos() = 0x3281500;
            break;
            case 151:
            pXPos() = 0x602000;
            pYPos() = 0x3281500;
            break;
            case 152:
            pXPos() = 0x682000;
            pYPos() = 0x3281500;
            break;
            case 153:
            pXPos() = 0x702000;
            pYPos() = 0x3281500;
            break;
            case 154:
            pXPos() = 0x782000;
            pYPos() = 0x3281500;
            break;
            case 155:
            pXPos() = 0x802000;
            pYPos() = 0x3281500;
            break;
            case 156:
            pXPos() = 0x882000;
            pYPos() = 0x3281500;
            break;
            case 157:
            pXPos() = 0x902000;
            pYPos() = 0x3281500;
            break;
            case 158:
            pXPos() = 0x982000;
            pYPos() = 0x3281500;
            break;
            case 159:
            pXPos() = 0xA02000;
            pYPos() = 0x3281500;
            break;
            case 160:
            pXPos() = 0xA82000;
            pYPos() = 0x3281500;
            break;
            case 161:
            pXPos() = 0xB02000;
            pYPos() = 0x3281500;
            break;
            case 162:
            pXPos() = 0xB82000;
            pYPos() = 0x3281500;
            break;
            case 163:
            pXPos() = 0xC02000;
            pYPos() = 0x3281500;
            break;
            case 164:
            pXPos() = 0xC82000;
            pYPos() = 0x3281500;
            break;
            case 165:
            pXPos() = 0xD02000;
            pYPos() = 0x3281500;
            break;
            case 166:
            pXPos() = 0xD82000;
            pYPos() = 0x3281500;
            break;
            case 167:
            pXPos() = 0xE02000;
            pYPos() = 0x3281500;
            break;
            case 168:
            pXPos() = 0xE82000;
            pYPos() = 0x3281500;
            break;
            case 169:
            pXPos() = 0xF02000;
            pYPos() = 0x3281500;
            break;
            case 170:
            pXPos() = 0xF82000;
            pYPos() = 0x3281500;
            break;
            case 171:
            pXPos() = 0x1002000;
            pYPos() = 0x3281500;
            break;
            case 172:
            pXPos() = 0x1082000;
            pYPos() = 0x3281500;
            break;
            case 173:
            pXPos() = 0x1102000;
            pYPos() = 0x3281500;
            break;
            case 174:
            pXPos() = 0x1182000;
            pYPos() = 0x3281500;
            break;
            case 175:
            pXPos() = 0x1202000;
            pYPos() = 0x3281500;
            break;
            case 176:
            pXPos() = 0x1282000;
            pYPos() = 0x3281500;
            break;
            case 177:
            pXPos() = 0x1302000;
            pYPos() = 0x3281500;
            break;
            case 178:
            pXPos() = 0x1382000;
            pYPos() = 0x3281500;
            break;
            case 179:
            pXPos() = 0x1402000;
            pYPos() = 0x3281500;
            break;
            case 180:
            pXPos() = 0x1482000;
            pYPos() = 0x3281500;
            break;
            case 181:
            pXPos() = 0x1502000;
            pYPos() = 0x3281500;
            break;
            case 182:
            pXPos() = 0x1582000;
            pYPos() = 0x3281500;
            break;
            case 183:
            pXPos() = 0x1602000;
            pYPos() = 0x3281500;
            break;
            case 184:
            pXPos() = 0x1682000;
            pYPos() = 0x3281500;
            break;
            case 185:
            pXPos() = 0x1702000;
            pYPos() = 0x3281500;
            break;
            case 186:
            pXPos() = 0x1782000;
            pYPos() = 0x3281500;
            break;
            case 187:
            pXPos() = 0x1802000;
            pYPos() = 0x3281500;
            break;
            case 188:
            pXPos() = 0x1882000;
            pYPos() = 0x3281500;
            break;
            case 189:
            pXPos() = 0x1902000;
            pYPos() = 0x3281500;
            break;
            case 190:
            pXPos() = 0x1982000;
            pYPos() = 0x3281500;
            break;
            case 191:
            pXPos() = 0x1A02000;
            pYPos() = 0x3281500;
            break;
            case 192:
            pXPos() = 0x1A82000;
            pYPos() = 0x3281500;
            break;
            case 193:
            pXPos() = 0x1B02000;
            pYPos() = 0x3281500;
            break;
            case 194:
            pXPos() = 0x1B82000;
            pYPos() = 0x3281500;
            break;
            case 195:
            pXPos() = 0x1C02000;
            pYPos() = 0x3281500;
            break;
            case 196:
            pXPos() = 0x1C82000;
            pYPos() = 0x3281500;
            break;
            case 197:
            pXPos() = 0x1D02000;
            pYPos() = 0x3281500;
            break;
            case 198:
            pXPos() = 0x1D82000;
            pYPos() = 0x3281500;
            break;
            case 199:
            pXPos() = 0x1E02000;
            pYPos() = 0x3281500;
            break;
            case 200:
            pXPos() = 0x1E82000;
            pYPos() = 0x3281500;
            break;
            case 201:
            pXPos() = 0x1F02000;
            pYPos() = 0x3281500;
            break;
            case 202:
            pXPos() = 0x1F82000;
            pYPos() = 0x3281500;
            break;
            case 203:
            pXPos() = 0x2002000;
            pYPos() = 0x3281500;
            break;
            case 204:
            pXPos() = 0x2082000;
            pYPos() = 0x3281500;
            break;
            case 205:
            pXPos() = 0x2102000;
            pYPos() = 0x3281500;
            break;
            case 206:
            pXPos() = 0x2182000;
            pYPos() = 0x3281500;
            break;
            case 207:
            pXPos() = 0x2182000;
            pYPos() = 0x3301500;
            break;
            case 208:
            pXPos() = 0x2182000;
            pYPos() = 0x3381500;
            break;
            case 209:
            pXPos() = 0x2182000;
            pYPos() = 0x3401500;
            break;
            case 210:
            pXPos() = 0x2182000;
            pYPos() = 0x3481500;
            break;
            case 211:
            pXPos() = 0x2182000;
            pYPos() = 0x3501500;
            break;
            case 212:
            pXPos() = 0x2182000;
            pYPos() = 0x3581500;
            break;
            case 213:
            pXPos() = 0x2182000;
            pYPos() = 0x3601500;
            break;
            case 214:
            pXPos() = 0x2182000;
            pYPos() = 0x3681500;
            break;
            case 215:
            pXPos() = 0x2182000;
            pYPos() = 0x3701500;
            break;
            case 216:
            pXPos() = 0x2202000;
            pYPos() = 0x3701500;
            break;
            case 217:
            pXPos() = 0x2282000;
            pYPos() = 0x3701500;
            break;
            case 218:
            pXPos() = 0x2302000;
            pYPos() = 0x3701500;
            break;
            case 219:
            pXPos() = 0x2382000;
            pYPos() = 0x3701500;
            break;
            case 220:
            pXPos() = 0x2402000;
            pYPos() = 0x3701500;
            break;
            case 221:
            pXPos() = 0x2482000;
            pYPos() = 0x3701500;
            break;
            case 222:
            pXPos() = 0x2502000;
            pYPos() = 0x3701500;
            break;
            case 223:
            pXPos() = 0x2582000;
            pYPos() = 0x3701500;
            break;
            case 224:
            pXPos() = 0x2602000;
            pYPos() = 0x3701500;
            break;
            case 225:
            pXPos() = 0x2682000;
            pYPos() = 0x3701500;
            break;
            case 226:
            pXPos() = 0x2702000;
            pYPos() = 0x3701500;
            break;
            case 227:
            pXPos() = 0x2782000;
            pYPos() = 0x3701500;
            break;
            case 228:
            pXPos() = 0x2802000;
            pYPos() = 0x3701500;
            break;
            case 229:
            pXPos() = 0x2882000;
            pYPos() = 0x3701500;
            break;
            case 230:
            pXPos() = 0x2902000;
            pYPos() = 0x3701500;
            break;
            case 231:
            pXPos() = 0x2982000;
            pYPos() = 0x3701500;
            break;
            case 232:
            pXPos() = 0x2A02000;
            pYPos() = 0x3701500;
            break;
            case 233:
            pXPos() = 0x2A82000;
            pYPos() = 0x3701500;
            break;
            case 234:
            pXPos() = 0x2B02000;
            pYPos() = 0x3701500;
            break;
            case 235:
            pXPos() = 0x2B82000;
            pYPos() = 0x3701500;
            break;
            case 236:
            pXPos() = 0x2C02000;
            pYPos() = 0x3701500;
            break;
            case 237:
            pXPos() = 0x2C82000;
            pYPos() = 0x3701500;
            break;
            case 238:
            pXPos() = 0x2D02000;
            pYPos() = 0x3701500;
            break;
            case 239:
            pXPos() = 0x2D82000;
            pYPos() = 0x3701500;
            break;
            case 240:
            pXPos() = 0x2E02000;
            pYPos() = 0x3701500;
            break;
            case 241:
            pXPos() = 0x2E82000;
            pYPos() = 0x3701500;
            break;
            case 242:
            pXPos() = 0x2F02000;
            pYPos() = 0x3701500;
            break;
            case 243:
            pXPos() = 0x2F82000;
            pYPos() = 0x3701500;
            break;
            case 244:
            pXPos() = 0x3002000;
            pYPos() = 0x3701500;
            break;
            case 245:
            pXPos() = 0x3082000;
            pYPos() = 0x3701500;
            break;
            case 246:
            pXPos() = 0x3102000;
            pYPos() = 0x3701500;
            break;
            case 247:
            pXPos() = 0x3182000;
            pYPos() = 0x3701500;
            break;
            case 248:
            pXPos() = 0x3202000;
            pYPos() = 0x3701500;
            break;
            case 249:
            pXPos() = 0x3282000;
            pYPos() = 0x3701500;
            break;
            case 250:
            pXPos() = 0x3302000;
            pYPos() = 0x3701500;
            break;
            case 251:
            pXPos() = 0x3382000;
            pYPos() = 0x3701500;
            break;
            case 252:
            pXPos() = 0x3402000;
            pYPos() = 0x3701500;
            break;
            case 253:
            pXPos() = 0x3482000;
            pYPos() = 0x3701500;
            break;
            case 254:
            pXPos() = 0x3502000;
            pYPos() = 0x3701500;
            break;
            case 255:
            pXPos() = 0x3582000;
            pYPos() = 0x3701500;
            break;
            case 256:
            pXPos() = 0x3602000;
            pYPos() = 0x3701500;
            break;
            case 257:
            pXPos() = 0x3682000;
            pYPos() = 0x3701500;
            break;
            case 258:
            pXPos() = 0x3702000;
            pYPos() = 0x3701500;
            break;
            case 259:
            pXPos() = 0x3782000;
            pYPos() = 0x3701500;
            break;
            case 260:
            pXPos() = 0x3802000;
            pYPos() = 0x3701500;
            break;
            case 261:
            pXPos() = 0x3882000;
            pYPos() = 0x3701500;
            break;
            case 262:
            pXPos() = 0x3902000;
            pYPos() = 0x3701500;
            break;
            case 263:
            pXPos() = 0x3982000;
            pYPos() = 0x3701500;
            break;
            case 264:
            pXPos() = 0x3A02000;
            pYPos() = 0x3701500;
            break;
            case 265:
            pXPos() = 0x3A82000;
            pYPos() = 0x3701500;
            break;
            case 266:
            pXPos() = 0x3B02000;
            pYPos() = 0x3701500;
            break;
            case 267:
            pObjectInteractions() = 1;
            pXPos() = 0x3B82000;
            pYPos() = 0x3701500;
            break;
            case 268:
            pXPos() = 0x3C02000;
            pYPos() = 0x3701500;
            break;
            case 269:
            pXPos() = 0x3C82000;
            pYPos() = 0x3701500;
            break;
            case 270:
            pXPos() = 0x3D02000;
            pYPos() = 0x3704D00;
            self->state = 0;
            self->priority = 0;
            pXVel() = 0xA0000;
            pSpeed() = 0xA0000;
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

void O_R6_TunnelPath1::ObjectPlayerInteraction()
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
