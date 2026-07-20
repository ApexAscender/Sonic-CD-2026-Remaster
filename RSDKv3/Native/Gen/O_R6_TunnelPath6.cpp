#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath6.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath6.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath6::ObjectMain()
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
            pXPos() = 0x2500;
            pYPos() = 0x9000;
            break;
            case 1:
            pXPos() = 0x2500;
            pYPos() = 0x89000;
            break;
            case 2:
            pXPos() = 0x2500;
            pYPos() = 0x109000;
            break;
            case 3:
            pXPos() = 0x2500;
            pYPos() = 0x189000;
            break;
            case 4:
            pXPos() = 0x2500;
            pYPos() = 0x209000;
            break;
            case 5:
            pXPos() = 0x2500;
            pYPos() = 0x289000;
            break;
            case 6:
            pXPos() = 0x2500;
            pYPos() = 0x309000;
            break;
            case 7:
            pXPos() = 0x2500;
            pYPos() = 0x389000;
            break;
            case 8:
            pXPos() = 0x2500;
            pYPos() = 0x409000;
            break;
            case 9:
            pXPos() = 0x2500;
            pYPos() = 0x489000;
            break;
            case 10:
            pXPos() = 0x2500;
            pYPos() = 0x509000;
            break;
            case 11:
            pXPos() = 0x2500;
            pYPos() = 0x589000;
            break;
            case 12:
            pXPos() = 0x2500;
            pYPos() = 0x609000;
            break;
            case 13:
            pXPos() = 0x2500;
            pYPos() = 0x689000;
            break;
            case 14:
            pXPos() = 0x2500;
            pYPos() = 0x709000;
            break;
            case 15:
            pXPos() = 0x2500;
            pYPos() = 0x789000;
            break;
            case 16:
            pXPos() = 0x2500;
            pYPos() = 0x809000;
            break;
            case 17:
            pXPos() = 0x2500;
            pYPos() = 0x889000;
            break;
            case 18:
            pXPos() = 0x2500;
            pYPos() = 0x909000;
            break;
            case 19:
            pXPos() = 0x2500;
            pYPos() = 0x989000;
            break;
            case 20:
            pXPos() = 0x2500;
            pYPos() = 0xA09000;
            break;
            case 21:
            pXPos() = 0x2500;
            pYPos() = 0xA89000;
            break;
            case 22:
            pXPos() = 0x2500;
            pYPos() = 0xB09000;
            break;
            case 23:
            pXPos() = 0x2500;
            pYPos() = 0xB89000;
            break;
            case 24:
            pXPos() = 0x2500;
            pYPos() = 0xC09000;
            break;
            case 25:
            pXPos() = 0x2500;
            pYPos() = 0xC89000;
            break;
            case 26:
            pXPos() = 0x2500;
            pYPos() = 0xD09000;
            break;
            case 27:
            pXPos() = 0x2500;
            pYPos() = 0xD89000;
            break;
            case 28:
            pXPos() = 0x2500;
            pYPos() = 0xE09000;
            break;
            case 29:
            pXPos() = 0x2500;
            pYPos() = 0xE89000;
            break;
            case 30:
            pXPos() = 0x2500;
            pYPos() = 0xF09000;
            break;
            case 31:
            pXPos() = 0x2500;
            pYPos() = 0xF89000;
            break;
            case 32:
            pXPos() = 0x2500;
            pYPos() = 0x1009000;
            break;
            case 33:
            pXPos() = 0x2500;
            pYPos() = 0x1089000;
            break;
            case 34:
            pXPos() = 0x2500;
            pYPos() = 0x1109000;
            break;
            case 35:
            pXPos() = 0x2500;
            pYPos() = 0x1189000;
            break;
            case 36:
            pXPos() = 0x2500;
            pYPos() = 0x1209000;
            break;
            case 37:
            pXPos() = 0x2500;
            pYPos() = 0x1289000;
            break;
            case 38:
            pXPos() = 0x2500;
            pYPos() = 0x1309000;
            break;
            case 39:
            pXPos() = 0x2500;
            pYPos() = 0x1389000;
            break;
            case 40:
            pXPos() = 0x2500;
            pYPos() = 0x1409000;
            break;
            case 41:
            pXPos() = 0x2500;
            pYPos() = 0x1489000;
            break;
            case 42:
            pXPos() = 0x2500;
            pYPos() = 0x1509000;
            break;
            case 43:
            pXPos() = 0x2500;
            pYPos() = 0x1589000;
            break;
            case 44:
            pXPos() = 0x2500;
            pYPos() = 0x1609000;
            break;
            case 45:
            pXPos() = 0x2500;
            pYPos() = 0x1689000;
            break;
            case 46:
            pXPos() = 0x2500;
            pYPos() = 0x1709000;
            break;
            case 47:
            pXPos() = 0x2500;
            pYPos() = 0x1789000;
            break;
            case 48:
            pXPos() = 0x2500;
            pYPos() = 0x1809000;
            break;
            case 49:
            pXPos() = 0x2500;
            pYPos() = 0x1889000;
            break;
            case 50:
            pXPos() = 0x2500;
            pYPos() = 0x1909000;
            break;
            case 51:
            pXPos() = 0x2500;
            pYPos() = 0x1989000;
            break;
            case 52:
            pXPos() = 0x2500;
            pYPos() = 0x1A09000;
            break;
            case 53:
            pXPos() = 0x2500;
            pYPos() = 0x1A89000;
            break;
            case 54:
            pXPos() = 0x2500;
            pYPos() = 0x1B09000;
            break;
            case 55:
            pXPos() = 0x2500;
            pYPos() = 0x1B89000;
            break;
            case 56:
            pXPos() = 0x2500;
            pYPos() = 0x1C09000;
            break;
            case 57:
            pXPos() = 0x2500;
            pYPos() = 0x1C89000;
            break;
            case 58:
            pXPos() = 0x2500;
            pYPos() = 0x1D09000;
            break;
            case 59:
            pXPos() = 0x2500;
            pYPos() = 0x1D89000;
            break;
            case 60:
            pXPos() = 0x2500;
            pYPos() = 0x1E09000;
            break;
            case 61:
            pXPos() = 0x2500;
            pYPos() = 0x1E89000;
            break;
            case 62:
            pXPos() = 0x2500;
            pYPos() = 0x1F09000;
            break;
            case 63:
            pXPos() = 0x2500;
            pYPos() = 0x1F89000;
            break;
            case 64:
            pXPos() = 0x2500;
            pYPos() = 0x2009000;
            break;
            case 65:
            pXPos() = 0x2500;
            pYPos() = 0x2089000;
            break;
            case 66:
            pXPos() = -0x7DB00;
            pYPos() = 0x2089000;
            break;
            case 67:
            pXPos() = -0xFDB00;
            pYPos() = 0x2089000;
            break;
            case 68:
            pXPos() = -0x17DB00;
            pYPos() = 0x2089000;
            break;
            case 69:
            pXPos() = -0x1FDB00;
            pYPos() = 0x2089000;
            break;
            case 70:
            pXPos() = -0x27DB00;
            pYPos() = 0x2089000;
            break;
            case 71:
            pXPos() = -0x2FDB00;
            pYPos() = 0x2089000;
            break;
            case 72:
            pXPos() = -0x37DB00;
            pYPos() = 0x2089000;
            break;
            case 73:
            pXPos() = -0x3FDB00;
            pYPos() = 0x2089000;
            break;
            case 74:
            pXPos() = -0x47DB00;
            pYPos() = 0x2089000;
            break;
            case 75:
            pXPos() = -0x4FDB00;
            pYPos() = 0x2089000;
            break;
            case 76:
            pXPos() = -0x57DB00;
            pYPos() = 0x2089000;
            break;
            case 77:
            pXPos() = -0x5FDB00;
            pYPos() = 0x2089000;
            break;
            case 78:
            pXPos() = -0x67DB00;
            pYPos() = 0x2089000;
            break;
            case 79:
            pXPos() = -0x6FDB00;
            pYPos() = 0x2089000;
            break;
            case 80:
            pXPos() = -0x77DB00;
            pYPos() = 0x2089000;
            break;
            case 81:
            pXPos() = -0x77DB00;
            pYPos() = 0x2109000;
            break;
            case 82:
            pXPos() = -0x77DB00;
            pYPos() = 0x2189000;
            break;
            case 83:
            pXPos() = -0x77DB00;
            pYPos() = 0x2209000;
            break;
            case 84:
            pXPos() = -0x77DB00;
            pYPos() = 0x2289000;
            break;
            case 85:
            pXPos() = -0x77DB00;
            pYPos() = 0x2309000;
            break;
            case 86:
            pXPos() = -0x77DB00;
            pYPos() = 0x2389000;
            break;
            case 87:
            pXPos() = -0x77DB00;
            pYPos() = 0x2409000;
            break;
            case 88:
            pXPos() = -0x77DB00;
            pYPos() = 0x2489000;
            break;
            case 89:
            pXPos() = -0x77DB00;
            pYPos() = 0x2509000;
            break;
            case 90:
            pXPos() = -0x77DB00;
            pYPos() = 0x2589000;
            break;
            case 91:
            pXPos() = -0x77DB00;
            pYPos() = 0x2609000;
            break;
            case 92:
            pXPos() = -0x77DB00;
            pYPos() = 0x2689000;
            break;
            case 93:
            pXPos() = -0x77DB00;
            pYPos() = 0x2709000;
            break;
            case 94:
            pXPos() = -0x77DB00;
            pYPos() = 0x2789000;
            break;
            case 95:
            pXPos() = -0x77DB00;
            pYPos() = 0x2809000;
            break;
            case 96:
            pXPos() = -0x77DB00;
            pYPos() = 0x2889000;
            break;
            case 97:
            pXPos() = -0x77DB00;
            pYPos() = 0x2909000;
            break;
            case 98:
            pXPos() = -0x77DB00;
            pYPos() = 0x2989000;
            break;
            case 99:
            pXPos() = -0x77DB00;
            pYPos() = 0x2A09000;
            break;
            case 100:
            pXPos() = -0x77DB00;
            pYPos() = 0x2A89000;
            break;
            case 101:
            pXPos() = -0x77DB00;
            pYPos() = 0x2B09000;
            break;
            case 102:
            pXPos() = -0x77DB00;
            pYPos() = 0x2B89000;
            break;
            case 103:
            pXPos() = -0x6FDB00;
            pYPos() = 0x2B89000;
            break;
            case 104:
            pXPos() = -0x67DB00;
            pYPos() = 0x2B89000;
            break;
            case 105:
            pXPos() = -0x5FDB00;
            pYPos() = 0x2B89000;
            break;
            case 106:
            pXPos() = -0x57DB00;
            pYPos() = 0x2B89000;
            break;
            case 107:
            pXPos() = -0x4FDB00;
            pYPos() = 0x2B89000;
            break;
            case 108:
            pXPos() = -0x47DB00;
            pYPos() = 0x2B89000;
            break;
            case 109:
            pXPos() = -0x3FDB00;
            pYPos() = 0x2B89000;
            break;
            case 110:
            pXPos() = -0x37DB00;
            pYPos() = 0x2B89000;
            break;
            case 111:
            pXPos() = -0x2FDB00;
            pYPos() = 0x2B89000;
            break;
            case 112:
            pXPos() = -0x27DB00;
            pYPos() = 0x2B89000;
            break;
            case 113:
            pXPos() = -0x1FDB00;
            pYPos() = 0x2B89000;
            break;
            case 114:
            pXPos() = -0x17DB00;
            pYPos() = 0x2B89000;
            break;
            case 115:
            pXPos() = -0x1FDB00;
            pYPos() = 0x2B89000;
            break;
            case 116:
            pXPos() = -0x27DB00;
            pYPos() = 0x2B89000;
            break;
            case 117:
            pXPos() = -0x2FDB00;
            pYPos() = 0x2B89000;
            break;
            case 118:
            pXPos() = -0x37DB00;
            pYPos() = 0x2B89000;
            break;
            case 119:
            pXPos() = -0x37DB00;
            pYPos() = 0x2C09000;
            break;
            case 120:
            pXPos() = -0x37DB00;
            pYPos() = 0x2C89000;
            break;
            case 121:
            pXPos() = -0x37DB00;
            pYPos() = 0x2D09000;
            break;
            case 122:
            pXPos() = -0x37DB00;
            pYPos() = 0x2D89000;
            break;
            case 123:
            pXPos() = -0x37DB00;
            pYPos() = 0x2E09000;
            break;
            case 124:
            pXPos() = -0x37DB00;
            pYPos() = 0x2E89000;
            break;
            case 125:
            pXPos() = -0x37DB00;
            pYPos() = 0x2F09000;
            break;
            case 126:
            pXPos() = -0x37DB00;
            pYPos() = 0x2F89000;
            break;
            case 127:
            pXPos() = -0x37DB00;
            pYPos() = 0x3009000;
            break;
            case 128:
            pXPos() = -0x37DB00;
            pYPos() = 0x3089000;
            break;
            case 129:
            pXPos() = -0x37DB00;
            pYPos() = 0x3109000;
            break;
            case 130:
            pXPos() = -0x37DB00;
            pYPos() = 0x3189000;
            break;
            case 131:
            pXPos() = -0x2FDB00;
            pYPos() = 0x3189000;
            break;
            case 132:
            pXPos() = -0x27DB00;
            pYPos() = 0x3189000;
            break;
            case 133:
            pXPos() = -0x1FDB00;
            pYPos() = 0x3189000;
            break;
            case 134:
            pXPos() = -0x17DB00;
            pYPos() = 0x3189000;
            break;
            case 135:
            pXPos() = -0xFDB00;
            pYPos() = 0x3189000;
            break;
            case 136:
            pXPos() = -0x7DB00;
            pYPos() = 0x3189000;
            break;
            case 137:
            pXPos() = 0x2500;
            pYPos() = 0x3189000;
            break;
            case 138:
            pXPos() = 0x82500;
            pYPos() = 0x3189000;
            break;
            case 139:
            pXPos() = 0x102500;
            pYPos() = 0x3189000;
            break;
            case 140:
            pXPos() = 0x182500;
            pYPos() = 0x3189000;
            break;
            case 141:
            pXPos() = 0x202500;
            pYPos() = 0x3189000;
            break;
            case 142:
            pXPos() = 0x282500;
            pYPos() = 0x3189000;
            break;
            case 143:
            pXPos() = 0x302500;
            pYPos() = 0x3189000;
            break;
            case 144:
            pXPos() = 0x382500;
            pYPos() = 0x3189000;
            break;
            case 145:
            pXPos() = 0x402500;
            pYPos() = 0x3189000;
            break;
            case 146:
            pXPos() = 0x482500;
            pYPos() = 0x3189000;
            break;
            case 147:
            pXPos() = 0x502500;
            pYPos() = 0x3189000;
            break;
            case 148:
            pXPos() = 0x582500;
            pYPos() = 0x3189000;
            break;
            case 149:
            pXPos() = 0x602500;
            pYPos() = 0x3189000;
            break;
            case 150:
            pXPos() = 0x682500;
            pYPos() = 0x3189000;
            break;
            case 151:
            pXPos() = 0x702500;
            pYPos() = 0x3189000;
            break;
            case 152:
            pXPos() = 0x782500;
            pYPos() = 0x3189000;
            break;
            case 153:
            pXPos() = 0x802500;
            pYPos() = 0x3189000;
            break;
            case 154:
            pXPos() = 0x882500;
            pYPos() = 0x3189000;
            break;
            case 155:
            pXPos() = 0x902500;
            pYPos() = 0x3189000;
            break;
            case 156:
            pXPos() = 0x982500;
            pYPos() = 0x3189000;
            break;
            case 157:
            pXPos() = 0xA02500;
            pYPos() = 0x3189000;
            break;
            case 158:
            pXPos() = 0xA82500;
            pYPos() = 0x3189000;
            break;
            case 159:
            pXPos() = 0xB02500;
            pYPos() = 0x3189000;
            break;
            case 160:
            pXPos() = 0xB82500;
            pYPos() = 0x3189000;
            break;
            case 161:
            pXPos() = 0xC02500;
            pYPos() = 0x3189000;
            break;
            case 162:
            pXPos() = 0xC82500;
            pYPos() = 0x3189000;
            break;
            case 163:
            pXPos() = 0xD02500;
            pYPos() = 0x3189000;
            break;
            case 164:
            pXPos() = 0xD82500;
            pYPos() = 0x3189000;
            break;
            case 165:
            pXPos() = 0xE02500;
            pYPos() = 0x3189000;
            break;
            case 166:
            pXPos() = 0xE82500;
            pYPos() = 0x3189000;
            break;
            case 167:
            pXPos() = 0xF02500;
            pYPos() = 0x3189000;
            break;
            case 168:
            pXPos() = 0xF82500;
            pYPos() = 0x3189000;
            break;
            case 169:
            pXPos() = 0x1002500;
            pYPos() = 0x3189000;
            break;
            case 170:
            pXPos() = 0x1082500;
            pYPos() = 0x3189000;
            break;
            case 171:
            pXPos() = 0x1102500;
            pYPos() = 0x3189000;
            break;
            case 172:
            pXPos() = 0x1182500;
            pYPos() = 0x3189000;
            break;
            case 173:
            pXPos() = 0x1202500;
            pYPos() = 0x3189000;
            break;
            case 174:
            pXPos() = 0x1282500;
            pYPos() = 0x3189000;
            break;
            case 175:
            pXPos() = 0x1302500;
            pYPos() = 0x3189000;
            break;
            case 176:
            pXPos() = 0x1382500;
            pYPos() = 0x3189000;
            break;
            case 177:
            pXPos() = 0x1402500;
            pYPos() = 0x3189000;
            break;
            case 178:
            pXPos() = 0x1482500;
            pYPos() = 0x3189000;
            break;
            case 179:
            pXPos() = 0x1502500;
            pYPos() = 0x3189000;
            break;
            case 180:
            pXPos() = 0x1582500;
            pYPos() = 0x3189000;
            break;
            case 181:
            pXPos() = 0x1602500;
            pYPos() = 0x3189000;
            break;
            case 182:
            pXPos() = 0x1682500;
            pYPos() = 0x3189000;
            break;
            case 183:
            pXPos() = 0x1702500;
            pYPos() = 0x3189000;
            break;
            case 184:
            pXPos() = 0x1782500;
            pYPos() = 0x3189000;
            break;
            case 185:
            pXPos() = 0x1802500;
            pYPos() = 0x3189000;
            break;
            case 186:
            pXPos() = 0x1882500;
            pYPos() = 0x3189000;
            break;
            case 187:
            pXPos() = 0x1902500;
            pYPos() = 0x3189000;
            break;
            case 188:
            pXPos() = 0x1982500;
            pYPos() = 0x3189000;
            break;
            case 189:
            pXPos() = 0x1A02500;
            pYPos() = 0x3189000;
            break;
            case 190:
            pXPos() = 0x1A82500;
            pYPos() = 0x3189000;
            break;
            case 191:
            pXPos() = 0x1B02500;
            pYPos() = 0x3189000;
            break;
            case 192:
            pXPos() = 0x1B82500;
            pYPos() = 0x3189000;
            break;
            case 193:
            pXPos() = 0x1C02500;
            pYPos() = 0x3189000;
            break;
            case 194:
            pXPos() = 0x1C82500;
            pYPos() = 0x3189000;
            break;
            case 195:
            pXPos() = 0x1D02500;
            pYPos() = 0x3189000;
            break;
            case 196:
            pXPos() = 0x1D82500;
            pYPos() = 0x3189000;
            break;
            case 197:
            pXPos() = 0x1E02500;
            pYPos() = 0x3189000;
            break;
            case 198:
            pXPos() = 0x1E82500;
            pYPos() = 0x3189000;
            break;
            case 199:
            pXPos() = 0x1F02500;
            pYPos() = 0x3189000;
            break;
            case 200:
            pXPos() = 0x1F82500;
            pYPos() = 0x3189000;
            break;
            case 201:
            pXPos() = 0x2002500;
            pYPos() = 0x3189000;
            break;
            case 202:
            pXPos() = 0x2082500;
            pYPos() = 0x3189000;
            break;
            case 203:
            pXPos() = 0x2102500;
            pYPos() = 0x3189000;
            break;
            case 204:
            pXPos() = 0x2182500;
            pYPos() = 0x3189000;
            break;
            case 205:
            pXPos() = 0x2202500;
            pYPos() = 0x3189000;
            break;
            case 206:
            pXPos() = 0x2282500;
            pYPos() = 0x3189000;
            break;
            case 207:
            pXPos() = 0x2302500;
            pYPos() = 0x3189000;
            break;
            case 208:
            pObjectInteractions() = 1;
            pXPos() = 0x2382500;
            pYPos() = 0x3189000;
            break;
            case 209:
            pXPos() = 0x2402500;
            pYPos() = 0x3189000;
            break;
            case 210:
            pXPos() = 0x2482500;
            pYPos() = 0x3189000;
            break;
            case 211:
            pXPos() = 0x2502500;
            pYPos() = 0x3189000;
            break;
            case 212:
            pXPos() = 0x2582500;
            pYPos() = 0x3189000;
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

void O_R6_TunnelPath6::ObjectPlayerInteraction()
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
