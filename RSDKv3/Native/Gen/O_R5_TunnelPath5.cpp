#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_TunnelPath5.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath5.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_TunnelPath5::ObjectMain()
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
            pXPos() = 0x100;
            pYPos() = 0x8AF00;
            break;
            case 1:
            pXPos() = 0xA0100;
            pYPos() = 0xDAF00;
            break;
            case 2:
            pXPos() = 0x140100;
            pYPos() = 0x12AF00;
            break;
            case 3:
            pXPos() = 0x1E0100;
            pYPos() = 0x17AF00;
            break;
            case 4:
            pXPos() = 0x280100;
            pYPos() = 0x1CAF00;
            break;
            case 5:
            pXPos() = 0x320100;
            pYPos() = 0x21AF00;
            break;
            case 6:
            pXPos() = 0x3C0100;
            pYPos() = 0x26AF00;
            break;
            case 7:
            pXPos() = 0x460100;
            pYPos() = 0x2BAF00;
            break;
            case 8:
            pXPos() = 0x500100;
            pYPos() = 0x30AF00;
            break;
            case 9:
            pXPos() = 0x5A0100;
            pYPos() = 0x35AF00;
            break;
            case 10:
            pXPos() = 0x640100;
            pYPos() = 0x3AAF00;
            break;
            case 11:
            pXPos() = 0x6E0100;
            pYPos() = 0x3FAF00;
            break;
            case 12:
            pXPos() = 0x780100;
            pYPos() = 0x44AF00;
            break;
            case 13:
            pXPos() = 0x820100;
            pYPos() = 0x49AF00;
            break;
            case 14:
            pXPos() = 0x8C0100;
            pYPos() = 0x4EAF00;
            break;
            case 15:
            pXPos() = 0x900100;
            pYPos() = 0x50AF00;
            break;
            case 16:
            pXPos() = 0x860100;
            pYPos() = 0x532F00;
            break;
            case 17:
            pXPos() = 0x7C0100;
            pYPos() = 0x55AF00;
            break;
            case 18:
            pXPos() = 0x720100;
            pYPos() = 0x582F00;
            break;
            case 19:
            pXPos() = 0x680100;
            pYPos() = 0x5AAF00;
            break;
            case 20:
            pXPos() = 0x5E0100;
            pYPos() = 0x5D2F00;
            break;
            case 21:
            pXPos() = 0x540100;
            pYPos() = 0x5FAF00;
            break;
            case 22:
            pXPos() = 0x4A0100;
            pYPos() = 0x622F00;
            break;
            case 23:
            pXPos() = 0x400100;
            pYPos() = 0x64AF00;
            break;
            case 24:
            pXPos() = 0x360100;
            pYPos() = 0x672F00;
            break;
            case 25:
            pXPos() = 0x2C0100;
            pYPos() = 0x69AF00;
            break;
            case 26:
            pXPos() = 0x220100;
            pYPos() = 0x6C2F00;
            break;
            case 27:
            pXPos() = 0x180100;
            pYPos() = 0x6EAF00;
            break;
            case 28:
            pXPos() = 0x100100;
            pYPos() = 0x70AF00;
            break;
            case 29:
            pXPos() = 0x1A0100;
            pYPos() = 0x732F00;
            break;
            case 30:
            pXPos() = 0x240100;
            pYPos() = 0x75AF00;
            break;
            case 31:
            pXPos() = 0x2E0100;
            pYPos() = 0x782F00;
            break;
            case 32:
            pXPos() = 0x380100;
            pYPos() = 0x7AAF00;
            break;
            case 33:
            pXPos() = 0x420100;
            pYPos() = 0x7D2F00;
            break;
            case 34:
            pXPos() = 0x4C0100;
            pYPos() = 0x7FAF00;
            break;
            case 35:
            pXPos() = 0x560100;
            pYPos() = 0x822F00;
            break;
            case 36:
            pXPos() = 0x600100;
            pYPos() = 0x84AF00;
            break;
            case 37:
            pXPos() = 0x6A0100;
            pYPos() = 0x872F00;
            break;
            case 38:
            pXPos() = 0x740100;
            pYPos() = 0x89AF00;
            break;
            case 39:
            pXPos() = 0x7E0100;
            pYPos() = 0x8C2F00;
            break;
            case 40:
            pXPos() = 0x880100;
            pYPos() = 0x8EAF00;
            break;
            case 41:
            pXPos() = 0x900100;
            pYPos() = 0x90AF00;
            break;
            case 42:
            pXPos() = 0x860100;
            pYPos() = 0x932F00;
            break;
            case 43:
            pXPos() = 0x7C0100;
            pYPos() = 0x95AF00;
            break;
            case 44:
            pXPos() = 0x720100;
            pYPos() = 0x982F00;
            break;
            case 45:
            pXPos() = 0x680100;
            pYPos() = 0x9AAF00;
            break;
            case 46:
            pXPos() = 0x5E0100;
            pYPos() = 0x9D2F00;
            break;
            case 47:
            pXPos() = 0x540100;
            pYPos() = 0x9FAF00;
            break;
            case 48:
            pXPos() = 0x4A0100;
            pYPos() = 0xA22F00;
            break;
            case 49:
            pXPos() = 0x400100;
            pYPos() = 0xA4AF00;
            break;
            case 50:
            pXPos() = 0x360100;
            pYPos() = 0xA72F00;
            break;
            case 51:
            pXPos() = 0x2C0100;
            pYPos() = 0xA9AF00;
            break;
            case 52:
            pXPos() = 0x220100;
            pYPos() = 0xAC2F00;
            break;
            case 53:
            pXPos() = 0x180100;
            pYPos() = 0xAEAF00;
            break;
            case 54:
            pXPos() = 0x100100;
            pYPos() = 0xB0AF00;
            break;
            case 55:
            pXPos() = 0x1A0100;
            pYPos() = 0xB32F00;
            break;
            case 56:
            pXPos() = 0x240100;
            pYPos() = 0xB5AF00;
            break;
            case 57:
            pXPos() = 0x2E0100;
            pYPos() = 0xB82F00;
            break;
            case 58:
            pXPos() = 0x380100;
            pYPos() = 0xBAAF00;
            break;
            case 59:
            pXPos() = 0x420100;
            pYPos() = 0xBD2F00;
            break;
            case 60:
            pXPos() = 0x4C0100;
            pYPos() = 0xBFAF00;
            break;
            case 61:
            pXPos() = 0x560100;
            pYPos() = 0xC22F00;
            break;
            case 62:
            pXPos() = 0x600100;
            pYPos() = 0xC4AF00;
            break;
            case 63:
            pXPos() = 0x6A0100;
            pYPos() = 0xC72F00;
            break;
            case 64:
            pXPos() = 0x740100;
            pYPos() = 0xC9AF00;
            break;
            case 65:
            pXPos() = 0x7E0100;
            pYPos() = 0xCC2F00;
            break;
            case 66:
            pXPos() = 0x880100;
            pYPos() = 0xCEAF00;
            break;
            case 67:
            pXPos() = 0x900100;
            pYPos() = 0xD0AF00;
            break;
            case 68:
            pXPos() = 0x860100;
            pYPos() = 0xD32F00;
            break;
            case 69:
            pXPos() = 0x7C0100;
            pYPos() = 0xD5AF00;
            break;
            case 70:
            pXPos() = 0x720100;
            pYPos() = 0xD82F00;
            break;
            case 71:
            pXPos() = 0x680100;
            pYPos() = 0xDAAF00;
            break;
            case 72:
            pXPos() = 0x5E0100;
            pYPos() = 0xDD2F00;
            break;
            case 73:
            pXPos() = 0x540100;
            pYPos() = 0xDFAF00;
            break;
            case 74:
            pXPos() = 0x4A0100;
            pYPos() = 0xE22F00;
            break;
            case 75:
            pXPos() = 0x400100;
            pYPos() = 0xE4AF00;
            break;
            case 76:
            pXPos() = 0x360100;
            pYPos() = 0xE72F00;
            break;
            case 77:
            pXPos() = 0x2C0100;
            pYPos() = 0xE9AF00;
            break;
            case 78:
            pXPos() = 0x220100;
            pYPos() = 0xEC2F00;
            break;
            case 79:
            pXPos() = 0x180100;
            pYPos() = 0xEEAF00;
            break;
            case 80:
            pXPos() = 0x100100;
            pYPos() = 0xF0AF00;
            break;
            case 81:
            pXPos() = 0x1A0100;
            pYPos() = 0xF32F00;
            break;
            case 82:
            pXPos() = 0x240100;
            pYPos() = 0xF5AF00;
            break;
            case 83:
            pXPos() = 0x2E0100;
            pYPos() = 0xF82F00;
            break;
            case 84:
            pXPos() = 0x380100;
            pYPos() = 0xFAAF00;
            break;
            case 85:
            pXPos() = 0x420100;
            pYPos() = 0xFD2F00;
            break;
            case 86:
            pXPos() = 0x4C0100;
            pYPos() = 0xFFAF00;
            break;
            case 87:
            pXPos() = 0x560100;
            pYPos() = 0x1022F00;
            break;
            case 88:
            pXPos() = 0x600100;
            pYPos() = 0x104AF00;
            break;
            case 89:
            pXPos() = 0x6A0100;
            pYPos() = 0x1072F00;
            break;
            case 90:
            pXPos() = 0x740100;
            pYPos() = 0x109AF00;
            break;
            case 91:
            pXPos() = 0x7E0100;
            pYPos() = 0x10C2F00;
            break;
            case 92:
            pXPos() = 0x880100;
            pYPos() = 0x10EAF00;
            break;
            case 93:
            pXPos() = 0x900100;
            pYPos() = 0x110AF00;
            break;
            case 94:
            pXPos() = 0x860100;
            pYPos() = 0x1132F00;
            break;
            case 95:
            pXPos() = 0x7C0100;
            pYPos() = 0x115AF00;
            break;
            case 96:
            pXPos() = 0x720100;
            pYPos() = 0x1182F00;
            break;
            case 97:
            pXPos() = 0x680100;
            pYPos() = 0x11AAF00;
            break;
            case 98:
            pXPos() = 0x5E0100;
            pYPos() = 0x11D2F00;
            break;
            case 99:
            pXPos() = 0x540100;
            pYPos() = 0x11FAF00;
            break;
            case 100:
            pXPos() = 0x4A0100;
            pYPos() = 0x1222F00;
            break;
            case 101:
            pXPos() = 0x400100;
            pYPos() = 0x124AF00;
            break;
            case 102:
            pXPos() = 0x360100;
            pYPos() = 0x1272F00;
            break;
            case 103:
            pXPos() = 0x2C0100;
            pYPos() = 0x129AF00;
            break;
            case 104:
            pXPos() = 0x220100;
            pYPos() = 0x12C2F00;
            break;
            case 105:
            pXPos() = 0x180100;
            pYPos() = 0x12EAF00;
            break;
            case 106:
            pXPos() = 0x100100;
            pYPos() = 0x130AF00;
            break;
            case 107:
            pXPos() = 0x1A0100;
            pYPos() = 0x1332F00;
            break;
            case 108:
            pXPos() = 0x240100;
            pYPos() = 0x135AF00;
            break;
            case 109:
            pXPos() = 0x2E0100;
            pYPos() = 0x1382F00;
            break;
            case 110:
            pXPos() = 0x380100;
            pYPos() = 0x13AAF00;
            break;
            case 111:
            pXPos() = 0x420100;
            pYPos() = 0x13D2F00;
            break;
            case 112:
            pXPos() = 0x4C0100;
            pYPos() = 0x13FAF00;
            break;
            case 113:
            pXPos() = 0x560100;
            pYPos() = 0x1422F00;
            break;
            case 114:
            pXPos() = 0x600100;
            pYPos() = 0x144AF00;
            break;
            case 115:
            pXPos() = 0x6A0100;
            pYPos() = 0x1472F00;
            break;
            case 116:
            pXPos() = 0x740100;
            pYPos() = 0x149AF00;
            break;
            case 117:
            pXPos() = 0x7E0100;
            pYPos() = 0x14C2F00;
            break;
            case 118:
            pXPos() = 0x880100;
            pYPos() = 0x14EAF00;
            break;
            case 119:
            pXPos() = 0x900100;
            pYPos() = 0x150AF00;
            break;
            case 120:
            pXPos() = 0x860100;
            pYPos() = 0x1532F00;
            break;
            case 121:
            pXPos() = 0x7C0100;
            pYPos() = 0x155AF00;
            break;
            case 122:
            pXPos() = 0x720100;
            pYPos() = 0x1582F00;
            break;
            case 123:
            pXPos() = 0x680100;
            pYPos() = 0x15AAF00;
            break;
            case 124:
            pXPos() = 0x5E0100;
            pYPos() = 0x15D2F00;
            break;
            case 125:
            pXPos() = 0x540100;
            pYPos() = 0x15FAF00;
            break;
            case 126:
            pXPos() = 0x4A0100;
            pYPos() = 0x1622F00;
            break;
            case 127:
            pXPos() = 0x400100;
            pYPos() = 0x164AF00;
            break;
            case 128:
            pXPos() = 0x360100;
            pYPos() = 0x1672F00;
            break;
            case 129:
            pXPos() = 0x2C0100;
            pYPos() = 0x169AF00;
            break;
            case 130:
            pXPos() = 0x220100;
            pYPos() = 0x16C2F00;
            break;
            case 131:
            pXPos() = 0x180100;
            pYPos() = 0x16EAF00;
            break;
            case 132:
            pXPos() = 0x100100;
            pYPos() = 0x170AF00;
            break;
            case 133:
            pXPos() = 0x1A0100;
            pYPos() = 0x1782F00;
            break;
            case 134:
            pXPos() = 0x240100;
            pYPos() = 0x17FAF00;
            break;
            case 135:
            pXPos() = 0x2E0100;
            pYPos() = 0x1872F00;
            break;
            case 136:
            pXPos() = 0x380100;
            pYPos() = 0x18EAF00;
            break;
            case 137:
            pXPos() = 0x420100;
            pYPos() = 0x1962F00;
            break;
            case 138:
            pXPos() = 0x4C0100;
            pYPos() = 0x19DAF00;
            break;
            case 139:
            pXPos() = 0x560100;
            pYPos() = 0x1A52F00;
            break;
            case 140:
            pXPos() = 0x600100;
            pYPos() = 0x1ACAF00;
            break;
            case 141:
            pXPos() = 0x6A0100;
            pYPos() = 0x1B42F00;
            break;
            case 142:
            pXPos() = 0x740100;
            pYPos() = 0x1BBAF00;
            break;
            case 143:
            pXPos() = 0x7E0100;
            pYPos() = 0x1C32F00;
            break;
            case 144:
            pXPos() = 0x880100;
            pYPos() = 0x1CAAF00;
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

void O_R5_TunnelPath5::ObjectPlayerInteraction()
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
