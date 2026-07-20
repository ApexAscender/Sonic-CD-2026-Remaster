#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_TunnelPath.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_TunnelPath::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("R1/Objects.gif");
        AddSpriteFrame(-16, -16, 32, 32, 34, 175);
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("R1/Objects3.gif");
        AddSpriteFrame(-14, -16, 29, 32, 115, 167);
    }
}

void O_R1_TunnelPath::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        if (pState() == PlayerStateID("Player_State_Death")) {
            self->state = 0;
        }
        scriptEng.tempValue[0] = self->values[0];
        self->values[0]++;
        pSpeed() = pXPos();
        pVisible() = 0;
        switch (scriptEng.tempValue[0]) {
            case 0:
            pObjectInteractions() = 0;
            pXPos() = 0x13F0B100;
            pYPos() = 0xF06500;
            break;
            case 1:
            pXPos() = 0x1400B100;
            pYPos() = 0xF06500;
            break;
            case 2:
            pXPos() = 0x1410B100;
            pYPos() = 0xF06500;
            break;
            case 3:
            pXPos() = 0x1420B100;
            pYPos() = 0xF06500;
            break;
            case 4:
            pXPos() = 0x1430B100;
            pYPos() = 0xF06500;
            break;
            case 5:
            pXPos() = 0x1440B100;
            pYPos() = 0xF06500;
            break;
            case 6:
            pXPos() = 0x1450B100;
            pYPos() = 0xF74000;
            break;
            case 7:
            pXPos() = 0x1460B100;
            pYPos() = 0xFE1B00;
            break;
            case 8:
            pXPos() = 0x1470B100;
            pYPos() = 0x104F600;
            break;
            case 9:
            pXPos() = 0x1478B100;
            pYPos() = 0x108F600;
            break;
            case 10:
            pXPos() = 0x147F8C00;
            pYPos() = 0x118F600;
            break;
            case 11:
            pXPos() = 0x14866700;
            pYPos() = 0x128F600;
            break;
            case 12:
            pXPos() = 0x148D4200;
            pYPos() = 0x138F600;
            break;
            case 13:
            pXPos() = 0x14904200;
            pYPos() = 0x140F600;
            break;
            case 14:
            pXPos() = 0x14904200;
            pYPos() = 0x150F600;
            break;
            case 15:
            pXPos() = 0x14904200;
            pYPos() = 0x160F600;
            break;
            case 16:
            pXPos() = 0x14904200;
            pYPos() = 0x170F600;
            break;
            case 17:
            pXPos() = 0x14904200;
            pYPos() = 0x180F600;
            break;
            case 18:
            pXPos() = 0x14904200;
            pYPos() = 0x190F600;
            break;
            case 19:
            pXPos() = 0x14904200;
            pYPos() = 0x1A0F600;
            break;
            case 20:
            pXPos() = 0x14904200;
            pYPos() = 0x1B0F600;
            break;
            case 21:
            pXPos() = 0x14904200;
            pYPos() = 0x1C0F600;
            break;
            case 22:
            pXPos() = 0x14904200;
            pYPos() = 0x1D0F600;
            break;
            case 23:
            pXPos() = 0x14904200;
            pYPos() = 0x1E0F600;
            break;
            case 24:
            pXPos() = 0x14804200;
            pYPos() = 0x1E5C200;
            break;
            case 25:
            pXPos() = 0x14704200;
            pYPos() = 0x1EA8E00;
            break;
            case 26:
            pXPos() = 0x14604200;
            pYPos() = 0x1EF5A00;
            break;
            case 27:
            pXPos() = 0x14504200;
            pYPos() = 0x1F42600;
            break;
            case 28:
            pXPos() = 0x14404200;
            pYPos() = 0x1F8F200;
            break;
            case 29:
            pXPos() = 0x14304200;
            pYPos() = 0x1F2F200;
            break;
            case 30:
            pXPos() = 0x14204200;
            pYPos() = 0x1ECF200;
            break;
            case 31:
            pXPos() = 0x14104200;
            pYPos() = 0x1E6F200;
            break;
            case 32:
            pXPos() = 0x14004200;
            pYPos() = 0x1E0F200;
            break;
            case 33:
            pXPos() = 0x13F84200;
            pYPos() = 0x1D0F200;
            break;
            case 34:
            pXPos() = 0x13F04200;
            pYPos() = 0x1C0F200;
            break;
            case 35:
            pXPos() = 0x13F04200;
            pYPos() = 0x1B0F200;
            break;
            case 36:
            pXPos() = 0x13F04200;
            pYPos() = 0x1A0F200;
            break;
            case 37:
            pXPos() = 0x13F04200;
            pYPos() = 0x190F200;
            break;
            case 38:
            pXPos() = 0x13F04200;
            pYPos() = 0x180F200;
            break;
            case 39:
            pXPos() = 0x14004200;
            pYPos() = 0x170F200;
            break;
            case 40:
            pXPos() = 0x14104200;
            pYPos() = 0x16CF200;
            break;
            case 41:
            pXPos() = 0x14204200;
            pYPos() = 0x168F200;
            break;
            case 42:
            pXPos() = 0x14304200;
            pYPos() = 0x16CF200;
            break;
            case 43:
            pXPos() = 0x14404200;
            pYPos() = 0x170F200;
            break;
            case 44:
            pXPos() = 0x144BAF00;
            pYPos() = 0x180F200;
            break;
            case 45:
            pXPos() = 0x14571C00;
            pYPos() = 0x190F200;
            break;
            case 46:
            pXPos() = 0x14628900;
            pYPos() = 0x1A0F200;
            break;
            case 47:
            pXPos() = 0x14688900;
            pYPos() = 0x1A8F200;
            break;
            case 48:
            pXPos() = 0x14788900;
            pYPos() = 0x1AC8000;
            break;
            case 49:
            pXPos() = 0x14888900;
            pYPos() = 0x1B00E00;
            break;
            case 50:
            pXPos() = 0x14988900;
            pYPos() = 0x1B39C00;
            break;
            case 51:
            pXPos() = 0x14A88900;
            pYPos() = 0x1B72A00;
            break;
            case 52:
            pXPos() = 0x14B88900;
            pYPos() = 0x1BAB800;
            break;
            case 53:
            pXPos() = 0x14C88900;
            pYPos() = 0x1BE4600;
            break;
            case 54:
            pXPos() = 0x14D88900;
            pYPos() = 0x1C1D400;
            break;
            case 55:
            pXPos() = 0x14E88900;
            pYPos() = 0x1C56200;
            break;
            case 56:
            pXPos() = 0x14F88900;
            pYPos() = 0x1C8F000;
            break;
            case 57:
            pXPos() = 0x15088900;
            pYPos() = 0x1CC7E00;
            CreateTempObject(TypeNameID("Waterfall Splash"), 0, pXPos(), pYPos());
            break;
            case 58:
            pXPos() = 0x15188900;
            pYPos() = 0x1D00C00;
            break;
            case 59:
            pXPos() = 0x15288900;
            pYPos() = 0x1D39A00;
            break;
            case 60:
            pXPos() = 0x15388900;
            pYPos() = 0x1D72800;
            CreateTempObject(TypeNameID("Waterfall Splash"), 0, pXPos(), pYPos());
            break;
            case 61:
            pXPos() = 0x15488900;
            pYPos() = 0x1DAB600;
            break;
            case 62:
            pXPos() = 0x15588900;
            pYPos() = 0x1DE4400;
            break;
            case 63:
            pXPos() = 0x15688900;
            pYPos() = 0x1E1D200;
            CreateTempObject(TypeNameID("Waterfall Splash"), 0, pXPos(), pYPos());
            break;
            case 64:
            pXPos() = 0x15788900;
            pYPos() = 0x1E56000;
            break;
            case 65:
            pXPos() = 0x15888900;
            pYPos() = 0x1E8EE00;
            break;
            case 66:
            pXPos() = 0x15988900;
            pYPos() = 0x1EC7C00;
            CreateTempObject(TypeNameID("Waterfall Splash"), 0, pXPos(), pYPos());
            break;
            case 67:
            pXPos() = 0x15A88900;
            pYPos() = 0x1F00A00;
            break;
            case 68:
            pXPos() = 0x15B88900;
            pYPos() = 0x1F39800;
            break;
            case 69:
            pXPos() = 0x15C88900;
            pYPos() = 0x1F72600;
            break;
            case 70:
            pXPos() = 0x15D88900;
            pYPos() = 0x1FAB400;
            break;
            case 71:
            pXPos() = 0x15F88900;
            pYPos() = 0x201D000;
            break;
            case 72:
            pXPos() = 0x16088900;
            pYPos() = 0x2055E00;
            break;
            case 73:
            pXPos() = 0x16188900;
            pYPos() = 0x208EC00;
            break;
            case 74:
            pXPos() = 0x16288900;
            pYPos() = 0x20C7A00;
            break;
            case 75:
            pXPos() = 0x16388900;
            pYPos() = 0x2100800;
            break;
            case 76:
            pXPos() = 0x16488900;
            pYPos() = 0x2139600;
            break;
            case 77:
            pXPos() = 0x16588900;
            pYPos() = 0x2172400;
            break;
            case 78:
            pXPos() = 0x16608900;
            pYPos() = 0x2182400;
            break;
            case 79:
            pXPos() = 0x16708900;
            pYPos() = 0x2162400;
            break;
            case 80:
            pXPos() = 0x16808900;
            pYPos() = 0x2142400;
            break;
            case 81:
            pXPos() = 0x16908900;
            pYPos() = 0x2122400;
            break;
            case 82:
            pXPos() = 0x16A08900;
            pYPos() = 0x2102400;
            break;
            case 83:
            pXPos() = 0x16B08900;
            pYPos() = 0x2042400;
            break;
            case 84:
            pXPos() = 0x16C08900;
            pYPos() = 0x1F82400;
            break;
            case 85:
            pXPos() = 0x16C5DE00;
            pYPos() = 0x1E82400;
            break;
            case 86:
            pXPos() = 0x16CB3300;
            pYPos() = 0x1D82400;
            break;
            case 87:
            pXPos() = 0x16D08800;
            pYPos() = 0x1C82400;
            break;
            case 88:
            pXPos() = 0x16C88800;
            pYPos() = 0x1B82400;
            break;
            case 89:
            pXPos() = 0x16C08800;
            pYPos() = 0x1A82400;
            break;
            case 90:
            pXPos() = 0x16B08800;
            pYPos() = 0x1A42400;
            break;
            case 91:
            pXPos() = 0x16A08800;
            pYPos() = 0x1A02400;
            break;
            case 92:
            pXPos() = 0x16908800;
            pYPos() = 0x19C2400;
            break;
            case 93:
            pXPos() = 0x16808800;
            pYPos() = 0x1982400;
            break;
            case 94:
            pXPos() = 0x16708800;
            pYPos() = 0x19B5700;
            break;
            case 95:
            pXPos() = 0x16608800;
            pYPos() = 0x19E8A00;
            break;
            case 96:
            pXPos() = 0x16588800;
            pYPos() = 0x1A08A00;
            break;
            case 97:
            pXPos() = 0x164EEF00;
            pYPos() = 0x1B08A00;
            break;
            case 98:
            pXPos() = 0x16455600;
            pYPos() = 0x1C08A00;
            break;
            case 99:
            pXPos() = 0x16405600;
            pYPos() = 0x1C88A00;
            break;
            case 100:
            pXPos() = 0x1646BC00;
            pYPos() = 0x1D88A00;
            break;
            case 101:
            pXPos() = 0x164D2200;
            pYPos() = 0x1E88A00;
            break;
            case 102:
            pXPos() = 0x16502200;
            pYPos() = 0x1F08A00;
            break;
            case 103:
            pXPos() = 0x16602200;
            pYPos() = 0x1F5DF00;
            break;
            case 104:
            pXPos() = 0x16702200;
            pYPos() = 0x1FB3400;
            break;
            case 105:
            pXPos() = 0x16802200;
            pYPos() = 0x2008900;
            break;
            case 106:
            pXPos() = 0x16902200;
            pYPos() = 0x2008900;
            break;
            case 107:
            pXPos() = 0x16A02200;
            pYPos() = 0x2008900;
            break;
            case 108:
            pXPos() = 0x16B02200;
            pYPos() = 0x2008900;
            break;
            case 109:
            pXPos() = 0x16C02200;
            pYPos() = 0x2008900;
            break;
            case 110:
            pXPos() = 0x16D02200;
            pYPos() = 0x2108900;
            break;
            case 111:
            pXPos() = 0x16D02200;
            pYPos() = 0x2208900;
            break;
            case 112:
            pXPos() = 0x16D02200;
            pYPos() = 0x2308900;
            break;
            case 113:
            pXPos() = 0x16D02200;
            pYPos() = 0x2408900;
            break;
            case 114:
            pXPos() = 0x16D02200;
            pYPos() = 0x2508900;
            break;
            case 115:
            pXPos() = 0x16D02200;
            pYPos() = 0x2608900;
            break;
            case 116:
            pXPos() = 0x16D02200;
            pYPos() = 0x2708900;
            break;
            case 117:
            pXPos() = 0x16D02200;
            pYPos() = 0x2808900;
            break;
            case 118:
            pXPos() = 0x16D02200;
            pYPos() = 0x2888900;
            break;
            case 119:
            pXPos() = 0x16CB9000;
            pYPos() = 0x2988900;
            break;
            case 120:
            pXPos() = 0x16C6FE00;
            pYPos() = 0x2A88900;
            break;
            case 121:
            pXPos() = 0x16C26C00;
            pYPos() = 0x2B88900;
            break;
            case 122:
            pXPos() = 0x16C06C00;
            pYPos() = 0x2C08900;
            break;
            case 123:
            pXPos() = 0x16B06C00;
            pYPos() = 0x2C68900;
            break;
            case 124:
            pXPos() = 0x16A06C00;
            pYPos() = 0x2CC8900;
            break;
            case 125:
            pXPos() = 0x16906C00;
            pYPos() = 0x2D28900;
            break;
            case 126:
            pXPos() = 0x16806C00;
            pYPos() = 0x2D88900;
            break;
            case 127:
            pXPos() = 0x16706C00;
            pYPos() = 0x2D08900;
            break;
            case 128:
            pXPos() = 0x16606C00;
            pYPos() = 0x2C88900;
            break;
            case 129:
            pXPos() = 0x16506C00;
            pYPos() = 0x2C08900;
            break;
            case 130:
            pXPos() = 0x16506C00;
            pYPos() = 0x2B08900;
            break;
            case 131:
            pXPos() = 0x16506C00;
            pYPos() = 0x2A08900;
            break;
            case 132:
            pXPos() = 0x16606C00;
            pYPos() = 0x29B3400;
            break;
            case 133:
            pXPos() = 0x16706C00;
            pYPos() = 0x295DF00;
            break;
            case 134:
            pXPos() = 0x16806C00;
            pYPos() = 0x2908A00;
            break;
            case 135:
            pXPos() = 0x16906C00;
            pYPos() = 0x2908A00;
            break;
            case 136:
            pXPos() = 0x16A06C00;
            pYPos() = 0x2908A00;
            break;
            case 137:
            pXPos() = 0x16B06C00;
            pYPos() = 0x2908A00;
            break;
            case 138:
            pXPos() = 0x16C06C00;
            pYPos() = 0x2908A00;
            break;
            case 139:
            pXPos() = 0x16D06C00;
            pYPos() = 0x2908A00;
            break;
            case 140:
            pXPos() = 0x16E06C00;
            pYPos() = 0x2908A00;
            break;
            case 141:
            pXPos() = 0x16F06C00;
            pYPos() = 0x2908A00;
            break;
            case 142:
            pXPos() = 0x17006C00;
            pYPos() = 0x2908A00;
            break;
            case 143:
            pXPos() = 0x17106C00;
            pYPos() = 0x296F000;
            break;
            case 144:
            pXPos() = 0x17206C00;
            pYPos() = 0x29D5600;
            break;
            case 145:
            pXPos() = 0x17286C00;
            pYPos() = 0x2A05600;
            break;
            case 146:
            pXPos() = 0x17286C00;
            pYPos() = 0x2B05600;
            break;
            case 147:
            pXPos() = 0x17286C00;
            pYPos() = 0x2C05600;
            break;
            case 148:
            pXPos() = 0x17286C00;
            pYPos() = 0x2D05600;
            break;
            case 149:
            pXPos() = 0x17286C00;
            pYPos() = 0x2E05600;
            break;
            case 150:
            pXPos() = 0x17186C00;
            pYPos() = 0x2E6BC00;
            break;
            case 151:
            pXPos() = 0x17086C00;
            pYPos() = 0x2ED2200;
            break;
            case 152:
            pXPos() = 0x17006C00;
            pYPos() = 0x2F02200;
            break;
            case 153:
            pXPos() = 0x16F06C00;
            pYPos() = 0x2E68800;
            break;
            case 154:
            pXPos() = 0x16E09A00;
            pYPos() = 0x2E4F900;
            break;
            case 155:
            pVisible() = 1;
            pTileCollisions() = 1;
            self->state = 0;
            self->priority = 0;
            pXVel() = -0xC0000;
            pSpeed() = -0xC0000;
            pState() = PlayerStateID("Player_State_Ground");
            pObjectInteractions() = 1;
            if (objectEntityList[objectLoop + 1].type == TypeNameID("Blank Object")) {
                objectEntityList[objectLoop + 1].type = TypeNameID("Tunnel Path");
                PlaySfx(globalSFXCount + 0, 0);
            }
            break;
        }
        if (self->state > 0) {
            pSpeed() -= pXPos();
            pSpeed() = -pSpeed();
        }
    }
}

void O_R1_TunnelPath::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (pState() != PlayerStateID("Player_State_Static")) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                pState() = PlayerStateID("Player_State_Static");
                if (PlayerValue(5) > 0) {
                    PlayerValue(4) = 0;
                    PlayerValue(5) = 0;
                }
                pTileCollisions() = 0;
                pVisible() = 0;
                self->state = 1;
                self->values[0] = 0;
                self->priority = 1;
                PlaySfx(7, 0);
            }
        }
    }
}

void O_R1_TunnelPath::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue > 0) {
        DrawSprite_Frame(0);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
