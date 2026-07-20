#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TunnelPath9.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath9.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TunnelPath9::ObjectMain()
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
            pXPos() = 0x3800;
            pYPos() = 0x7D00;
            break;
            case 1:
            pXPos() = 0x3800;
            pYPos() = 0x87D00;
            break;
            case 2:
            pXPos() = 0x3800;
            pYPos() = 0x107D00;
            break;
            case 3:
            pXPos() = 0x3800;
            pYPos() = 0x187D00;
            break;
            case 4:
            pXPos() = 0x3800;
            pYPos() = 0x207D00;
            break;
            case 5:
            pXPos() = 0x3800;
            pYPos() = 0x287D00;
            break;
            case 6:
            pXPos() = 0x3800;
            pYPos() = 0x307D00;
            break;
            case 7:
            pXPos() = 0x3800;
            pYPos() = 0x387D00;
            break;
            case 8:
            pXPos() = 0x3800;
            pYPos() = 0x407D00;
            break;
            case 9:
            pXPos() = 0x3800;
            pYPos() = 0x487D00;
            break;
            case 10:
            pXPos() = 0x3800;
            pYPos() = 0x507D00;
            break;
            case 11:
            pXPos() = 0x3800;
            pYPos() = 0x587D00;
            break;
            case 12:
            pXPos() = 0x3800;
            pYPos() = 0x607D00;
            break;
            case 13:
            pXPos() = 0x3800;
            pYPos() = 0x687D00;
            break;
            case 14:
            pXPos() = 0x3800;
            pYPos() = 0x707D00;
            break;
            case 15:
            pXPos() = 0x3800;
            pYPos() = 0x787D00;
            break;
            case 16:
            pXPos() = 0x3800;
            pYPos() = 0x807D00;
            break;
            case 17:
            pXPos() = 0x3800;
            pYPos() = 0x887D00;
            break;
            case 18:
            pXPos() = 0x3800;
            pYPos() = 0x907D00;
            break;
            case 19:
            pXPos() = 0x3800;
            pYPos() = 0x987D00;
            break;
            case 20:
            pXPos() = 0x3800;
            pYPos() = 0xA07D00;
            break;
            case 21:
            pXPos() = 0x3800;
            pYPos() = 0xA87D00;
            break;
            case 22:
            pXPos() = 0x3800;
            pYPos() = 0xB07D00;
            break;
            case 23:
            pXPos() = 0x3800;
            pYPos() = 0xB87D00;
            break;
            case 24:
            pXPos() = 0x3800;
            pYPos() = 0xC07D00;
            break;
            case 25:
            pXPos() = 0x3800;
            pYPos() = 0xC87D00;
            break;
            case 26:
            pXPos() = 0x3800;
            pYPos() = 0xD07D00;
            break;
            case 27:
            pXPos() = 0x3800;
            pYPos() = 0xD87D00;
            break;
            case 28:
            pXPos() = 0x3800;
            pYPos() = 0xE07D00;
            break;
            case 29:
            pXPos() = 0x3800;
            pYPos() = 0xE87D00;
            break;
            case 30:
            pXPos() = 0x3800;
            pYPos() = 0xF07D00;
            break;
            case 31:
            pXPos() = 0x3800;
            pYPos() = 0xF87D00;
            break;
            case 32:
            pXPos() = 0x3800;
            pYPos() = 0x1007D00;
            break;
            case 33:
            pXPos() = 0x3800;
            pYPos() = 0x1087D00;
            break;
            case 34:
            pXPos() = 0x3800;
            pYPos() = 0x1107D00;
            break;
            case 35:
            pXPos() = 0x3800;
            pYPos() = 0x1187D00;
            break;
            case 36:
            pXPos() = 0x3800;
            pYPos() = 0x1207D00;
            break;
            case 37:
            pXPos() = 0x3800;
            pYPos() = 0x1287D00;
            break;
            case 38:
            pXPos() = 0x3800;
            pYPos() = 0x1307D00;
            break;
            case 39:
            pXPos() = 0x3800;
            pYPos() = 0x1387D00;
            break;
            case 40:
            pXPos() = 0x3800;
            pYPos() = 0x1407D00;
            break;
            case 41:
            pXPos() = 0x3800;
            pYPos() = 0x1487D00;
            break;
            case 42:
            pXPos() = 0x3800;
            pYPos() = 0x1507D00;
            break;
            case 43:
            pXPos() = 0x3800;
            pYPos() = 0x1587D00;
            break;
            case 44:
            pXPos() = 0x3800;
            pYPos() = 0x1607D00;
            break;
            case 45:
            pXPos() = 0x3800;
            pYPos() = 0x1687D00;
            break;
            case 46:
            pXPos() = 0x3800;
            pYPos() = 0x1707D00;
            break;
            case 47:
            pXPos() = 0x3800;
            pYPos() = 0x1787D00;
            break;
            case 48:
            pXPos() = 0x3800;
            pYPos() = 0x1807D00;
            break;
            case 49:
            pXPos() = 0x3800;
            pYPos() = 0x1887D00;
            break;
            case 50:
            pXPos() = 0x3800;
            pYPos() = 0x1907D00;
            break;
            case 51:
            pXPos() = 0x3800;
            pYPos() = 0x1987D00;
            break;
            case 52:
            pXPos() = 0x3800;
            pYPos() = 0x1A07D00;
            break;
            case 53:
            pXPos() = 0x3800;
            pYPos() = 0x1A87D00;
            break;
            case 54:
            pXPos() = 0x3800;
            pYPos() = 0x1B07D00;
            break;
            case 55:
            pXPos() = 0x3800;
            pYPos() = 0x1B87D00;
            break;
            case 56:
            pXPos() = 0x3800;
            pYPos() = 0x1C07D00;
            break;
            case 57:
            pXPos() = 0x3800;
            pYPos() = 0x1C87D00;
            break;
            case 58:
            pXPos() = 0x3800;
            pYPos() = 0x1D07D00;
            break;
            case 59:
            pXPos() = 0x3800;
            pYPos() = 0x1D87D00;
            break;
            case 60:
            pXPos() = 0x3800;
            pYPos() = 0x1E07D00;
            break;
            case 61:
            pXPos() = 0x3800;
            pYPos() = 0x1E87D00;
            break;
            case 62:
            pXPos() = 0x3800;
            pYPos() = 0x1F07D00;
            break;
            case 63:
            pXPos() = 0x3800;
            pYPos() = 0x1F87D00;
            break;
            case 64:
            pXPos() = 0x3800;
            pYPos() = 0x2007D00;
            break;
            case 65:
            pXPos() = 0x3800;
            pYPos() = 0x2087D00;
            break;
            case 66:
            pXPos() = 0x3800;
            pYPos() = 0x2107D00;
            break;
            case 67:
            pXPos() = 0x3800;
            pYPos() = 0x2187D00;
            break;
            case 68:
            pXPos() = 0x3800;
            pYPos() = 0x2207D00;
            break;
            case 69:
            pXPos() = 0x3800;
            pYPos() = 0x2287D00;
            break;
            case 70:
            pXPos() = 0x3800;
            pYPos() = 0x2307D00;
            break;
            case 71:
            pXPos() = 0x3800;
            pYPos() = 0x2387D00;
            break;
            case 72:
            pXPos() = 0x3800;
            pYPos() = 0x2407D00;
            break;
            case 73:
            pXPos() = 0x3800;
            pYPos() = 0x2487D00;
            break;
            case 74:
            pXPos() = 0x3800;
            pYPos() = 0x2507D00;
            break;
            case 75:
            pXPos() = 0x3800;
            pYPos() = 0x2587D00;
            break;
            case 76:
            pXPos() = 0x3800;
            pYPos() = 0x2607D00;
            break;
            case 77:
            pXPos() = 0x3800;
            pYPos() = 0x2687D00;
            break;
            case 78:
            pXPos() = 0x3800;
            pYPos() = 0x2707D00;
            break;
            case 79:
            pXPos() = 0x3800;
            pYPos() = 0x2787D00;
            break;
            case 80:
            pXPos() = 0x3800;
            pYPos() = 0x2807D00;
            break;
            case 81:
            pXPos() = 0x3800;
            pYPos() = 0x2887D00;
            break;
            case 82:
            pXPos() = 0x3800;
            pYPos() = 0x2907D00;
            break;
            case 83:
            pXPos() = 0x3800;
            pYPos() = 0x2987D00;
            break;
            case 84:
            pXPos() = 0x3800;
            pYPos() = 0x2A07D00;
            break;
            case 85:
            pXPos() = 0x3800;
            pYPos() = 0x2A87D00;
            break;
            case 86:
            pXPos() = 0x83800;
            pYPos() = 0x2A87D00;
            break;
            case 87:
            pXPos() = 0x103800;
            pYPos() = 0x2A87D00;
            break;
            case 88:
            pXPos() = 0x183800;
            pYPos() = 0x2A87D00;
            break;
            case 89:
            pXPos() = 0x203800;
            pYPos() = 0x2A87D00;
            break;
            case 90:
            pXPos() = 0x283800;
            pYPos() = 0x2A87D00;
            break;
            case 91:
            pXPos() = 0x303800;
            pYPos() = 0x2A87D00;
            break;
            case 92:
            pXPos() = 0x383800;
            pYPos() = 0x2A87D00;
            break;
            case 93:
            pXPos() = 0x403800;
            pYPos() = 0x2A87D00;
            break;
            case 94:
            pXPos() = 0x483800;
            pYPos() = 0x2A87D00;
            break;
            case 95:
            pXPos() = 0x503800;
            pYPos() = 0x2A87D00;
            break;
            case 96:
            pXPos() = 0x583800;
            pYPos() = 0x2A87D00;
            break;
            case 97:
            pXPos() = 0x603800;
            pYPos() = 0x2A87D00;
            break;
            case 98:
            pXPos() = 0x683800;
            pYPos() = 0x2A87D00;
            break;
            case 99:
            pXPos() = 0x703800;
            pYPos() = 0x2A87D00;
            break;
            case 100:
            pXPos() = 0x783800;
            pYPos() = 0x2A87D00;
            break;
            case 101:
            pXPos() = 0x803800;
            pYPos() = 0x2A87D00;
            break;
            case 102:
            pXPos() = 0x883800;
            pYPos() = 0x2A87D00;
            break;
            case 103:
            pXPos() = 0x903800;
            pYPos() = 0x2A87D00;
            break;
            case 104:
            pXPos() = 0x983800;
            pYPos() = 0x2A87D00;
            break;
            case 105:
            pXPos() = 0xA03800;
            pYPos() = 0x2A87D00;
            break;
            case 106:
            pXPos() = 0xA83800;
            pYPos() = 0x2A87D00;
            break;
            case 107:
            pXPos() = 0xB03800;
            pYPos() = 0x2A87D00;
            break;
            case 108:
            pXPos() = 0xB83800;
            pYPos() = 0x2A87D00;
            break;
            case 109:
            pXPos() = 0xC03800;
            pYPos() = 0x2A87D00;
            break;
            case 110:
            pXPos() = 0xC83800;
            pYPos() = 0x2A87D00;
            break;
            case 111:
            pXPos() = 0xD03800;
            pYPos() = 0x2A87D00;
            break;
            case 112:
            pXPos() = 0xD83800;
            pYPos() = 0x2A87D00;
            break;
            case 113:
            pXPos() = 0xE03800;
            pYPos() = 0x2A87D00;
            break;
            case 114:
            pXPos() = 0xE83800;
            pYPos() = 0x2A87D00;
            break;
            case 115:
            pXPos() = 0xF03800;
            pYPos() = 0x2A87D00;
            break;
            case 116:
            pXPos() = 0xF83800;
            pYPos() = 0x2A87D00;
            break;
            case 117:
            pXPos() = 0x1003800;
            pYPos() = 0x2A87D00;
            break;
            case 118:
            pXPos() = 0x1083800;
            pYPos() = 0x2A87D00;
            break;
            case 119:
            pXPos() = 0x1103800;
            pYPos() = 0x2A87D00;
            break;
            case 120:
            pXPos() = 0x1183800;
            pYPos() = 0x2A87D00;
            break;
            case 121:
            pXPos() = 0x1203800;
            pYPos() = 0x2A87D00;
            break;
            case 122:
            pXPos() = 0x1283800;
            pYPos() = 0x2A87D00;
            break;
            case 123:
            pXPos() = 0x1303800;
            pYPos() = 0x2A87D00;
            break;
            case 124:
            pXPos() = 0x1383800;
            pYPos() = 0x2A87D00;
            break;
            case 125:
            pXPos() = 0x1403800;
            pYPos() = 0x2A87D00;
            break;
            case 126:
            pXPos() = 0x1483800;
            pYPos() = 0x2A87D00;
            break;
            case 127:
            pXPos() = 0x1503800;
            pYPos() = 0x2A87D00;
            break;
            case 128:
            pXPos() = 0x1583800;
            pYPos() = 0x2A87D00;
            break;
            case 129:
            pXPos() = 0x1603800;
            pYPos() = 0x2A87D00;
            break;
            case 130:
            pXPos() = 0x1683800;
            pYPos() = 0x2A87D00;
            break;
            case 131:
            pXPos() = 0x1703800;
            pYPos() = 0x2A87D00;
            break;
            case 132:
            pXPos() = 0x1783800;
            pYPos() = 0x2A87D00;
            break;
            case 133:
            pXPos() = 0x1803800;
            pYPos() = 0x2A87D00;
            break;
            case 134:
            pXPos() = 0x1883800;
            pYPos() = 0x2A87D00;
            break;
            case 135:
            pXPos() = 0x1903800;
            pYPos() = 0x2A87D00;
            break;
            case 136:
            pXPos() = 0x1983800;
            pYPos() = 0x2A87D00;
            break;
            case 137:
            pXPos() = 0x1A03800;
            pYPos() = 0x2A87D00;
            break;
            case 138:
            pXPos() = 0x1A83800;
            pYPos() = 0x2A87D00;
            break;
            case 139:
            pXPos() = 0x1B03800;
            pYPos() = 0x2A87D00;
            break;
            case 140:
            pXPos() = 0x1B83800;
            pYPos() = 0x2A87D00;
            break;
            case 141:
            pXPos() = 0x1C03800;
            pYPos() = 0x2A87D00;
            break;
            case 142:
            pXPos() = 0x1C83800;
            pYPos() = 0x2A87D00;
            break;
            case 143:
            pXPos() = 0x1D03800;
            pYPos() = 0x2A87D00;
            break;
            case 144:
            pXPos() = 0x1D83800;
            pYPos() = 0x2A87D00;
            break;
            case 145:
            pXPos() = 0x1E03800;
            pYPos() = 0x2A87D00;
            break;
            case 146:
            pXPos() = 0x1E83800;
            pYPos() = 0x2A87D00;
            break;
            case 147:
            pXPos() = 0x1F03800;
            pYPos() = 0x2A87D00;
            break;
            case 148:
            pXPos() = 0x1F83800;
            pYPos() = 0x2A87D00;
            break;
            case 149:
            pXPos() = 0x2003800;
            pYPos() = 0x2A87D00;
            break;
            case 150:
            pXPos() = 0x2083800;
            pYPos() = 0x2A87D00;
            break;
            case 151:
            pXPos() = 0x2103800;
            pYPos() = 0x2A87D00;
            break;
            case 152:
            pXPos() = 0x2183800;
            pYPos() = 0x2A87D00;
            break;
            case 153:
            pXPos() = 0x2203800;
            pYPos() = 0x2A87D00;
            break;
            case 154:
            pXPos() = 0x2283800;
            pYPos() = 0x2A87D00;
            break;
            case 155:
            pXPos() = 0x2303800;
            pYPos() = 0x2A87D00;
            break;
            case 156:
            pXPos() = 0x2383800;
            pYPos() = 0x2A87D00;
            break;
            case 157:
            pXPos() = 0x2403800;
            pYPos() = 0x2A87D00;
            break;
            case 158:
            pXPos() = 0x2483800;
            pYPos() = 0x2A87D00;
            break;
            case 159:
            pXPos() = 0x2503800;
            pYPos() = 0x2A87D00;
            break;
            case 160:
            pXPos() = 0x2583800;
            pYPos() = 0x2A87D00;
            break;
            case 161:
            pXPos() = 0x2603800;
            pYPos() = 0x2A87D00;
            break;
            case 162:
            pXPos() = 0x2683800;
            pYPos() = 0x2A87D00;
            break;
            case 163:
            pXPos() = 0x2703800;
            pYPos() = 0x2A87D00;
            break;
            case 164:
            pXPos() = 0x2783800;
            pYPos() = 0x2A87D00;
            break;
            case 165:
            pXPos() = 0x2803800;
            pYPos() = 0x2A87D00;
            break;
            case 166:
            pXPos() = 0x2883800;
            pYPos() = 0x2A87D00;
            break;
            case 167:
            pXPos() = 0x2903800;
            pYPos() = 0x2A87D00;
            break;
            case 168:
            pXPos() = 0x2983800;
            pYPos() = 0x2A87D00;
            break;
            case 169:
            pXPos() = 0x2A03800;
            pYPos() = 0x2A87D00;
            break;
            case 170:
            pXPos() = 0x2A83800;
            pYPos() = 0x2A87D00;
            break;
            case 171:
            pXPos() = 0x2B03800;
            pYPos() = 0x2A87D00;
            break;
            case 172:
            pXPos() = 0x2B83800;
            pYPos() = 0x2A87D00;
            break;
            case 173:
            pXPos() = 0x2C03800;
            pYPos() = 0x2A87D00;
            break;
            case 174:
            pXPos() = 0x2C83800;
            pYPos() = 0x2A87D00;
            break;
            case 175:
            pXPos() = 0x2D03800;
            pYPos() = 0x2A87D00;
            break;
            case 176:
            pXPos() = 0x2D83800;
            pYPos() = 0x2A87D00;
            break;
            case 177:
            pXPos() = 0x2E03800;
            pYPos() = 0x2A87D00;
            break;
            case 178:
            pXPos() = 0x2E83800;
            pYPos() = 0x2A87D00;
            break;
            case 179:
            pXPos() = 0x2F03800;
            pYPos() = 0x2A87D00;
            break;
            case 180:
            pXPos() = 0x2F83800;
            pYPos() = 0x2A87D00;
            break;
            case 181:
            pXPos() = 0x3003800;
            pYPos() = 0x2A87D00;
            break;
            case 182:
            pXPos() = 0x3083800;
            pYPos() = 0x2A87D00;
            break;
            case 183:
            pXPos() = 0x3103800;
            pYPos() = 0x2A87D00;
            break;
            case 184:
            pXPos() = 0x3183800;
            pYPos() = 0x2A87D00;
            break;
            case 185:
            pXPos() = 0x3203800;
            pYPos() = 0x2A87D00;
            break;
            case 186:
            pXPos() = 0x3283800;
            pYPos() = 0x2A87D00;
            break;
            case 187:
            pXPos() = 0x3303800;
            pYPos() = 0x2A87D00;
            break;
            case 188:
            pXPos() = 0x3383800;
            pYPos() = 0x2A87D00;
            break;
            case 189:
            pXPos() = 0x3403800;
            pYPos() = 0x2A87D00;
            break;
            case 190:
            pXPos() = 0x3483800;
            pYPos() = 0x2A87D00;
            break;
            case 191:
            pXPos() = 0x3503800;
            pYPos() = 0x2A87D00;
            break;
            case 192:
            pXPos() = 0x3583800;
            pYPos() = 0x2A87D00;
            break;
            case 193:
            pXPos() = 0x3603800;
            pYPos() = 0x2A87D00;
            break;
            case 194:
            pXPos() = 0x3683800;
            pYPos() = 0x2A87D00;
            break;
            case 195:
            pXPos() = 0x3703800;
            pYPos() = 0x2A87D00;
            break;
            case 196:
            pXPos() = 0x3783800;
            pYPos() = 0x2A87D00;
            break;
            case 197:
            pXPos() = 0x3803800;
            pYPos() = 0x2A87D00;
            break;
            case 198:
            pXPos() = 0x3883800;
            pYPos() = 0x2A87D00;
            break;
            case 199:
            pXPos() = 0x3903800;
            pYPos() = 0x2A87D00;
            break;
            case 200:
            pXPos() = 0x3983800;
            pYPos() = 0x2A87D00;
            break;
            case 201:
            pXPos() = 0x3A03800;
            pYPos() = 0x2A87D00;
            break;
            case 202:
            pXPos() = 0x3A83800;
            pYPos() = 0x2A87D00;
            break;
            case 203:
            pXPos() = 0x3B03800;
            pYPos() = 0x2A87D00;
            break;
            case 204:
            pXPos() = 0x3B83800;
            pYPos() = 0x2A87D00;
            break;
            case 205:
            pXPos() = 0x3C03800;
            pYPos() = 0x2A87D00;
            break;
            case 206:
            pXPos() = 0x3C03800;
            pYPos() = 0x2A07D00;
            break;
            case 207:
            pXPos() = 0x3C03800;
            pYPos() = 0x2987D00;
            break;
            case 208:
            pXPos() = 0x3C03800;
            pYPos() = 0x2907D00;
            break;
            case 209:
            pXPos() = 0x3C03800;
            pYPos() = 0x2887D00;
            break;
            case 210:
            pXPos() = 0x3C03800;
            pYPos() = 0x2807D00;
            break;
            case 211:
            pXPos() = 0x3C03800;
            pYPos() = 0x2787D00;
            break;
            case 212:
            pXPos() = 0x3C03800;
            pYPos() = 0x2707D00;
            break;
            case 213:
            pXPos() = 0x3C03800;
            pYPos() = 0x2687D00;
            break;
            case 214:
            pXPos() = 0x3C03800;
            pYPos() = 0x2607D00;
            break;
            case 215:
            pXPos() = 0x3C03800;
            pYPos() = 0x2587D00;
            break;
            case 216:
            pXPos() = 0x3C03800;
            pYPos() = 0x2507D00;
            break;
            case 217:
            pXPos() = 0x3C03800;
            pYPos() = 0x2487D00;
            break;
            case 218:
            pXPos() = 0x3C03800;
            pYPos() = 0x2407D00;
            break;
            case 219:
            pXPos() = 0x3C03800;
            pYPos() = 0x2387D00;
            break;
            case 220:
            pXPos() = 0x3C03800;
            pYPos() = 0x2307D00;
            break;
            case 221:
            pXPos() = 0x3C03800;
            pYPos() = 0x2287D00;
            break;
            case 222:
            pXPos() = 0x3C03800;
            pYPos() = 0x2207D00;
            break;
            case 223:
            pXPos() = 0x3C03800;
            pYPos() = 0x2187D00;
            break;
            case 224:
            pXPos() = 0x3C03800;
            pYPos() = 0x2107D00;
            break;
            case 225:
            pXPos() = 0x3C03800;
            pYPos() = 0x2087D00;
            break;
            case 226:
            pXPos() = 0x3C03800;
            pYPos() = 0x2007D00;
            break;
            case 227:
            pXPos() = 0x3C03800;
            pYPos() = 0x1F87D00;
            break;
            case 228:
            pXPos() = 0x3C03800;
            pYPos() = 0x1F07D00;
            break;
            case 229:
            pXPos() = 0x3C03800;
            pYPos() = 0x1E87D00;
            break;
            case 230:
            pXPos() = 0x3C03800;
            pYPos() = 0x1E07D00;
            break;
            case 231:
            pXPos() = 0x3C03800;
            pYPos() = 0x1D87D00;
            break;
            case 232:
            pXPos() = 0x3C03800;
            pYPos() = 0x1D07D00;
            break;
            case 233:
            pXPos() = 0x3C03800;
            pYPos() = 0x1C87D00;
            break;
            case 234:
            pXPos() = 0x3C03800;
            pYPos() = 0x1C07D00;
            break;
            case 235:
            pXPos() = 0x3C03800;
            pYPos() = 0x1B87D00;
            break;
            case 236:
            pXPos() = 0x3C03800;
            pYPos() = 0x1B07D00;
            break;
            case 237:
            pXPos() = 0x3C03800;
            pYPos() = 0x1A87D00;
            break;
            case 238:
            pXPos() = 0x3B83800;
            pYPos() = 0x1A87D00;
            break;
            case 239:
            pXPos() = 0x3B03800;
            pYPos() = 0x1A87D00;
            break;
            case 240:
            pXPos() = 0x3A83800;
            pYPos() = 0x1A87D00;
            break;
            case 241:
            pXPos() = 0x3A03800;
            pYPos() = 0x1A87D00;
            break;
            case 242:
            pXPos() = 0x3983800;
            pYPos() = 0x1A87D00;
            break;
            case 243:
            pXPos() = 0x3903800;
            pYPos() = 0x1A87D00;
            break;
            case 244:
            pXPos() = 0x3883800;
            pYPos() = 0x1A87D00;
            break;
            case 245:
            pXPos() = 0x3803800;
            pYPos() = 0x1A87D00;
            break;
            case 246:
            pXPos() = 0x3783800;
            pYPos() = 0x1A87D00;
            break;
            case 247:
            pXPos() = 0x3703800;
            pYPos() = 0x1A87D00;
            break;
            case 248:
            pXPos() = 0x3683800;
            pYPos() = 0x1A87D00;
            break;
            case 249:
            pXPos() = 0x3603800;
            pYPos() = 0x1A87D00;
            break;
            case 250:
            pXPos() = 0x3583800;
            pYPos() = 0x1A87D00;
            break;
            case 251:
            pXPos() = 0x3503800;
            pYPos() = 0x1A87D00;
            break;
            case 252:
            pXPos() = 0x3483800;
            pYPos() = 0x1A87D00;
            break;
            case 253:
            pXPos() = 0x3403800;
            pYPos() = 0x1A87D00;
            break;
            case 254:
            pXPos() = 0x3383800;
            pYPos() = 0x1A87D00;
            break;
            case 255:
            pXPos() = 0x3303800;
            pYPos() = 0x1A87D00;
            break;
            case 256:
            pXPos() = 0x3283800;
            pYPos() = 0x1A87D00;
            break;
            case 257:
            pXPos() = 0x3203800;
            pYPos() = 0x1A87D00;
            break;
            case 258:
            pXPos() = 0x3183800;
            pYPos() = 0x1A87D00;
            break;
            case 259:
            pXPos() = 0x3103800;
            pYPos() = 0x1A87D00;
            break;
            case 260:
            pXPos() = 0x3083800;
            pYPos() = 0x1A87D00;
            break;
            case 261:
            pXPos() = 0x3003800;
            pYPos() = 0x1A87D00;
            break;
            case 262:
            pXPos() = 0x2F83800;
            pYPos() = 0x1A87D00;
            break;
            case 263:
            pXPos() = 0x2F03800;
            pYPos() = 0x1A87D00;
            break;
            case 264:
            pXPos() = 0x2E83800;
            pYPos() = 0x1A87D00;
            break;
            case 265:
            pXPos() = 0x2E03800;
            pYPos() = 0x1A87D00;
            break;
            case 266:
            pXPos() = 0x2D83800;
            pYPos() = 0x1A87D00;
            break;
            case 267:
            pXPos() = 0x2D03800;
            pYPos() = 0x1A87D00;
            break;
            case 268:
            pXPos() = 0x2C83800;
            pYPos() = 0x1A87D00;
            break;
            case 269:
            pXPos() = 0x2C03800;
            pYPos() = 0x1A87D00;
            break;
            case 270:
            pXPos() = 0x2B83800;
            pYPos() = 0x1A87D00;
            break;
            case 271:
            pXPos() = 0x2B03800;
            pYPos() = 0x1A87D00;
            break;
            case 272:
            pXPos() = 0x2A83800;
            pYPos() = 0x1A87D00;
            break;
            case 273:
            pXPos() = 0x2A03800;
            pYPos() = 0x1A87D00;
            break;
            case 274:
            pXPos() = 0x2983800;
            pYPos() = 0x1A87D00;
            break;
            case 275:
            pXPos() = 0x2903800;
            pYPos() = 0x1A87D00;
            break;
            case 276:
            pXPos() = 0x2883800;
            pYPos() = 0x1A87D00;
            break;
            case 277:
            pXPos() = 0x2803800;
            pYPos() = 0x1A87D00;
            break;
            case 278:
            pXPos() = 0x2783800;
            pYPos() = 0x1A87D00;
            break;
            case 279:
            pXPos() = 0x2703800;
            pYPos() = 0x1A87D00;
            break;
            case 280:
            pXPos() = 0x2683800;
            pYPos() = 0x1A87D00;
            break;
            case 281:
            pXPos() = 0x2603800;
            pYPos() = 0x1A87D00;
            break;
            case 282:
            pXPos() = 0x2583800;
            pYPos() = 0x1A87D00;
            break;
            case 283:
            pXPos() = 0x2503800;
            pYPos() = 0x1A87D00;
            break;
            case 284:
            pXPos() = 0x2483800;
            pYPos() = 0x1A87D00;
            break;
            case 285:
            pXPos() = 0x2403800;
            pYPos() = 0x1A87D00;
            break;
            case 286:
            pXPos() = 0x2383800;
            pYPos() = 0x1A87D00;
            break;
            case 287:
            pXPos() = 0x2303800;
            pYPos() = 0x1A87D00;
            break;
            case 288:
            pXPos() = 0x2283800;
            pYPos() = 0x1A87D00;
            break;
            case 289:
            pXPos() = 0x2203800;
            pYPos() = 0x1A87D00;
            break;
            case 290:
            pXPos() = 0x2183800;
            pYPos() = 0x1A87D00;
            break;
            case 291:
            pXPos() = 0x2103800;
            pYPos() = 0x1A87D00;
            break;
            case 292:
            pXPos() = 0x2083800;
            pYPos() = 0x1A87D00;
            break;
            case 293:
            pXPos() = 0x2003800;
            pYPos() = 0x1A87D00;
            break;
            case 294:
            pXPos() = 0x1F83800;
            pYPos() = 0x1A87D00;
            break;
            case 295:
            pXPos() = 0x1F03800;
            pYPos() = 0x1A87D00;
            break;
            case 296:
            pXPos() = 0x1E83800;
            pYPos() = 0x1A87D00;
            break;
            case 297:
            pXPos() = 0x1E03800;
            pYPos() = 0x1A87D00;
            break;
            case 298:
            pXPos() = 0x1D83800;
            pYPos() = 0x1A87D00;
            break;
            case 299:
            pXPos() = 0x1D03800;
            pYPos() = 0x1A87D00;
            break;
            case 300:
            pXPos() = 0x1C83800;
            pYPos() = 0x1A87D00;
            break;
            case 301:
            pXPos() = 0x1C03800;
            pYPos() = 0x1A87D00;
            break;
            case 302:
            pXPos() = 0x1B03800;
            pYPos() = 0x1A87D00;
            break;
            case 303:
            pXPos() = 0x1A83800;
            pYPos() = 0x1A87D00;
            break;
            case 304:
            pXPos() = 0x1A03800;
            pYPos() = 0x1A87D00;
            break;
            case 305:
            pXPos() = 0x1983800;
            pYPos() = 0x1A87D00;
            break;
            case 306:
            pXPos() = 0x1903800;
            pYPos() = 0x1A87D00;
            self->state = 0;
            self->priority = 0;
            pXVel() = -0xA0000;
            pSpeed() = -0xA0000;
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

void O_R6_TunnelPath9::ObjectPlayerInteraction()
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
