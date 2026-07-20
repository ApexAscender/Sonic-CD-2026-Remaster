#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_TunnelPath3.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath3.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_TunnelPath3::ObjectMain()
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
            pXPos() = 0xC800;
            pYPos() = 0xEE00;
            break;
            case 1:
            pXPos() = 0xC800;
            pYPos() = 0xAEE00;
            break;
            case 2:
            pXPos() = 0xC800;
            pYPos() = 0x14EE00;
            break;
            case 3:
            pXPos() = 0xC800;
            pYPos() = 0x1EEE00;
            break;
            case 4:
            pXPos() = 0xC800;
            pYPos() = 0x20EE00;
            break;
            case 5:
            pXPos() = 0xAC800;
            pYPos() = 0x244300;
            break;
            case 6:
            pXPos() = 0x14C800;
            pYPos() = 0x279800;
            break;
            case 7:
            pXPos() = 0x1EC800;
            pYPos() = 0x2AED00;
            break;
            case 8:
            pXPos() = 0x28C800;
            pYPos() = 0x2E4200;
            break;
            case 9:
            pXPos() = 0x32C800;
            pYPos() = 0x319700;
            break;
            case 10:
            pXPos() = 0x3CC800;
            pYPos() = 0x34EC00;
            break;
            case 11:
            pXPos() = 0x46C800;
            pYPos() = 0x384100;
            break;
            case 12:
            pXPos() = 0x50C800;
            pYPos() = 0x3B9600;
            break;
            case 13:
            pXPos() = 0x5AC800;
            pYPos() = 0x3EEB00;
            break;
            case 14:
            pXPos() = 0x60C800;
            pYPos() = 0x40EB00;
            break;
            case 15:
            pXPos() = 0x56C800;
            pYPos() = 0x436B00;
            break;
            case 16:
            pXPos() = 0x4CC800;
            pYPos() = 0x45EB00;
            break;
            case 17:
            pXPos() = 0x42C800;
            pYPos() = 0x486B00;
            break;
            case 18:
            pXPos() = 0x38C800;
            pYPos() = 0x4AEB00;
            break;
            case 19:
            pXPos() = 0x2EC800;
            pYPos() = 0x4D6B00;
            break;
            case 20:
            pXPos() = 0x24C800;
            pYPos() = 0x4FEB00;
            break;
            case 21:
            pXPos() = 0x1AC800;
            pYPos() = 0x526B00;
            break;
            case 22:
            pXPos() = 0x10C800;
            pYPos() = 0x54EB00;
            break;
            case 23:
            pXPos() = 0x6C800;
            pYPos() = 0x576B00;
            break;
            case 24:
            pXPos() = -0x33800;
            pYPos() = 0x59EB00;
            break;
            case 25:
            pXPos() = -0xD3800;
            pYPos() = 0x5C6B00;
            break;
            case 26:
            pXPos() = -0x173800;
            pYPos() = 0x5EEB00;
            break;
            case 27:
            pXPos() = -0x1F3800;
            pYPos() = 0x60EB00;
            break;
            case 28:
            pXPos() = -0x153800;
            pYPos() = 0x636B00;
            break;
            case 29:
            pXPos() = -0xB3800;
            pYPos() = 0x65EB00;
            break;
            case 30:
            pXPos() = -0x13800;
            pYPos() = 0x686B00;
            break;
            case 31:
            pXPos() = 0x8C800;
            pYPos() = 0x6AEB00;
            break;
            case 32:
            pXPos() = 0x12C800;
            pYPos() = 0x6D6B00;
            break;
            case 33:
            pXPos() = 0x1CC800;
            pYPos() = 0x6FEB00;
            break;
            case 34:
            pXPos() = 0x26C800;
            pYPos() = 0x726B00;
            break;
            case 35:
            pXPos() = 0x30C800;
            pYPos() = 0x74EB00;
            break;
            case 36:
            pXPos() = 0x3AC800;
            pYPos() = 0x776B00;
            break;
            case 37:
            pXPos() = 0x44C800;
            pYPos() = 0x79EB00;
            break;
            case 38:
            pXPos() = 0x4EC800;
            pYPos() = 0x7C6B00;
            break;
            case 39:
            pXPos() = 0x58C800;
            pYPos() = 0x7EEB00;
            break;
            case 40:
            pXPos() = 0x60C800;
            pYPos() = 0x80EB00;
            break;
            case 41:
            pXPos() = 0x56C800;
            pYPos() = 0x836B00;
            break;
            case 42:
            pXPos() = 0x4CC800;
            pYPos() = 0x85EB00;
            break;
            case 43:
            pXPos() = 0x42C800;
            pYPos() = 0x886B00;
            break;
            case 44:
            pXPos() = 0x38C800;
            pYPos() = 0x8AEB00;
            break;
            case 45:
            pXPos() = 0x2EC800;
            pYPos() = 0x8D6B00;
            break;
            case 46:
            pXPos() = 0x24C800;
            pYPos() = 0x8FEB00;
            break;
            case 47:
            pXPos() = 0x1AC800;
            pYPos() = 0x926B00;
            break;
            case 48:
            pXPos() = 0x10C800;
            pYPos() = 0x94EB00;
            break;
            case 49:
            pXPos() = 0x6C800;
            pYPos() = 0x976B00;
            break;
            case 50:
            pXPos() = -0x33800;
            pYPos() = 0x99EB00;
            break;
            case 51:
            pXPos() = -0xD3800;
            pYPos() = 0x9C6B00;
            break;
            case 52:
            pXPos() = -0x173800;
            pYPos() = 0x9EEB00;
            break;
            case 53:
            pXPos() = -0x1F3800;
            pYPos() = 0xA0EB00;
            break;
            case 54:
            pXPos() = -0x153800;
            pYPos() = 0xA36B00;
            break;
            case 55:
            pXPos() = -0xB3800;
            pYPos() = 0xA5EB00;
            break;
            case 56:
            pXPos() = -0x13800;
            pYPos() = 0xA86B00;
            break;
            case 57:
            pXPos() = 0x8C800;
            pYPos() = 0xAAEB00;
            break;
            case 58:
            pXPos() = 0x12C800;
            pYPos() = 0xAD6B00;
            break;
            case 59:
            pXPos() = 0x1CC800;
            pYPos() = 0xAFEB00;
            break;
            case 60:
            pXPos() = 0x26C800;
            pYPos() = 0xB26B00;
            break;
            case 61:
            pXPos() = 0x30C800;
            pYPos() = 0xB4EB00;
            break;
            case 62:
            pXPos() = 0x3AC800;
            pYPos() = 0xB76B00;
            break;
            case 63:
            pXPos() = 0x44C800;
            pYPos() = 0xB9EB00;
            break;
            case 64:
            pXPos() = 0x4EC800;
            pYPos() = 0xBC6B00;
            break;
            case 65:
            pXPos() = 0x58C800;
            pYPos() = 0xBEEB00;
            break;
            case 66:
            pXPos() = 0x60C800;
            pYPos() = 0xC0EB00;
            break;
            case 67:
            pXPos() = 0x56C800;
            pYPos() = 0xC36B00;
            break;
            case 68:
            pXPos() = 0x4CC800;
            pYPos() = 0xC5EB00;
            break;
            case 69:
            pXPos() = 0x42C800;
            pYPos() = 0xC86B00;
            break;
            case 70:
            pXPos() = 0x38C800;
            pYPos() = 0xCAEB00;
            break;
            case 71:
            pXPos() = 0x2EC800;
            pYPos() = 0xCD6B00;
            break;
            case 72:
            pXPos() = 0x24C800;
            pYPos() = 0xCFEB00;
            break;
            case 73:
            pXPos() = 0x1AC800;
            pYPos() = 0xD26B00;
            break;
            case 74:
            pXPos() = 0x10C800;
            pYPos() = 0xD4EB00;
            break;
            case 75:
            pXPos() = 0x6C800;
            pYPos() = 0xD76B00;
            break;
            case 76:
            pXPos() = -0x33800;
            pYPos() = 0xD9EB00;
            break;
            case 77:
            pXPos() = -0xD3800;
            pYPos() = 0xDC6B00;
            break;
            case 78:
            pXPos() = -0x173800;
            pYPos() = 0xDEEB00;
            break;
            case 79:
            pXPos() = -0x1F3800;
            pYPos() = 0xE0EB00;
            break;
            case 80:
            pXPos() = -0x153800;
            pYPos() = 0xE36B00;
            break;
            case 81:
            pXPos() = -0xB3800;
            pYPos() = 0xE5EB00;
            break;
            case 82:
            pXPos() = -0x13800;
            pYPos() = 0xE86B00;
            break;
            case 83:
            pXPos() = 0x8C800;
            pYPos() = 0xEAEB00;
            break;
            case 84:
            pXPos() = 0x12C800;
            pYPos() = 0xED6B00;
            break;
            case 85:
            pXPos() = 0x1CC800;
            pYPos() = 0xEFEB00;
            break;
            case 86:
            pXPos() = 0x26C800;
            pYPos() = 0xF26B00;
            break;
            case 87:
            pXPos() = 0x30C800;
            pYPos() = 0xF4EB00;
            break;
            case 88:
            pXPos() = 0x3AC800;
            pYPos() = 0xF76B00;
            break;
            case 89:
            pXPos() = 0x44C800;
            pYPos() = 0xF9EB00;
            break;
            case 90:
            pXPos() = 0x4EC800;
            pYPos() = 0xFC6B00;
            break;
            case 91:
            pXPos() = 0x58C800;
            pYPos() = 0xFEEB00;
            break;
            case 92:
            pXPos() = 0x60C800;
            pYPos() = 0x100EB00;
            break;
            case 93:
            pXPos() = 0x6AC800;
            pYPos() = 0x1076B00;
            break;
            case 94:
            pXPos() = 0x74C800;
            pYPos() = 0x1112300;
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

void O_R5_TunnelPath3::ObjectPlayerInteraction()
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
