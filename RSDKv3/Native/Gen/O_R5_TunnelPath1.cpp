#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_TunnelPath1.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TunnelPath1.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_TunnelPath1::ObjectMain()
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
            pXPos() = 0xDA00;
            pYPos() = 0xBA00;
            break;
            case 1:
            pXPos() = 0xDA00;
            pYPos() = 0xABA00;
            break;
            case 2:
            pXPos() = 0xDA00;
            pYPos() = 0x14BA00;
            break;
            case 3:
            pXPos() = 0xDA00;
            pYPos() = 0x1EBA00;
            break;
            case 4:
            pXPos() = 0xDA00;
            pYPos() = 0x28BA00;
            break;
            case 5:
            pXPos() = 0xDA00;
            pYPos() = 0x32BA00;
            break;
            case 6:
            pXPos() = 0xDA00;
            pYPos() = 0x38BA00;
            break;
            case 7:
            pXPos() = 0xADA00;
            pYPos() = 0x403A00;
            break;
            case 8:
            pXPos() = 0x14DA00;
            pYPos() = 0x47BA00;
            break;
            case 9:
            pXPos() = 0x1EDA00;
            pYPos() = 0x4F3A00;
            break;
            case 10:
            pXPos() = 0x20DA00;
            pYPos() = 0x503A00;
            break;
            case 11:
            pXPos() = 0x16DA00;
            pYPos() = 0x52BA00;
            break;
            case 12:
            pXPos() = 0xCDA00;
            pYPos() = 0x553A00;
            break;
            case 13:
            pXPos() = 0x2DA00;
            pYPos() = 0x57BA00;
            break;
            case 14:
            pXPos() = -0x72600;
            pYPos() = 0x5A3A00;
            break;
            case 15:
            pXPos() = -0x112600;
            pYPos() = 0x5CBA00;
            break;
            case 16:
            pXPos() = -0x1B2600;
            pYPos() = 0x5F3A00;
            break;
            case 17:
            pXPos() = -0x252600;
            pYPos() = 0x61BA00;
            break;
            case 18:
            pXPos() = -0x2F2600;
            pYPos() = 0x643A00;
            break;
            case 19:
            pXPos() = -0x392600;
            pYPos() = 0x66BA00;
            break;
            case 20:
            pXPos() = -0x432600;
            pYPos() = 0x693A00;
            break;
            case 21:
            pXPos() = -0x4D2600;
            pYPos() = 0x6BBA00;
            break;
            case 22:
            pXPos() = -0x572600;
            pYPos() = 0x6E3A00;
            break;
            case 23:
            pXPos() = -0x5F2600;
            pYPos() = 0x703A00;
            break;
            case 24:
            pXPos() = -0x552600;
            pYPos() = 0x72BA00;
            break;
            case 25:
            pXPos() = -0x4B2600;
            pYPos() = 0x753A00;
            break;
            case 26:
            pXPos() = -0x412600;
            pYPos() = 0x77BA00;
            break;
            case 27:
            pXPos() = -0x372600;
            pYPos() = 0x7A3A00;
            break;
            case 28:
            pXPos() = -0x2D2600;
            pYPos() = 0x7CBA00;
            break;
            case 29:
            pXPos() = -0x232600;
            pYPos() = 0x7F3A00;
            break;
            case 30:
            pXPos() = -0x192600;
            pYPos() = 0x81BA00;
            break;
            case 31:
            pXPos() = -0xF2600;
            pYPos() = 0x843A00;
            break;
            case 32:
            pXPos() = -0x52600;
            pYPos() = 0x86BA00;
            break;
            case 33:
            pXPos() = 0x4DA00;
            pYPos() = 0x893A00;
            break;
            case 34:
            pXPos() = 0xEDA00;
            pYPos() = 0x8BBA00;
            break;
            case 35:
            pXPos() = 0x18DA00;
            pYPos() = 0x8E3A00;
            break;
            case 36:
            pXPos() = 0x20DA00;
            pYPos() = 0x903A00;
            break;
            case 37:
            pXPos() = 0x16DA00;
            pYPos() = 0x92BA00;
            break;
            case 38:
            pXPos() = 0xCDA00;
            pYPos() = 0x953A00;
            break;
            case 39:
            pXPos() = 0x2DA00;
            pYPos() = 0x97BA00;
            break;
            case 40:
            pXPos() = -0x72600;
            pYPos() = 0x9A3A00;
            break;
            case 41:
            pXPos() = -0x112600;
            pYPos() = 0x9CBA00;
            break;
            case 42:
            pXPos() = -0x1B2600;
            pYPos() = 0x9F3A00;
            break;
            case 43:
            pXPos() = -0x252600;
            pYPos() = 0xA1BA00;
            break;
            case 44:
            pXPos() = -0x2F2600;
            pYPos() = 0xA43A00;
            break;
            case 45:
            pXPos() = -0x392600;
            pYPos() = 0xA6BA00;
            break;
            case 46:
            pXPos() = -0x432600;
            pYPos() = 0xA93A00;
            break;
            case 47:
            pXPos() = -0x4D2600;
            pYPos() = 0xABBA00;
            break;
            case 48:
            pXPos() = -0x572600;
            pYPos() = 0xAE3A00;
            break;
            case 49:
            pXPos() = -0x5F2600;
            pYPos() = 0xB03A00;
            break;
            case 50:
            pXPos() = -0x552600;
            pYPos() = 0xB2BA00;
            break;
            case 51:
            pXPos() = -0x4B2600;
            pYPos() = 0xB53A00;
            break;
            case 52:
            pXPos() = -0x412600;
            pYPos() = 0xB7BA00;
            break;
            case 53:
            pXPos() = -0x372600;
            pYPos() = 0xBA3A00;
            break;
            case 54:
            pXPos() = -0x2D2600;
            pYPos() = 0xBCBA00;
            break;
            case 55:
            pXPos() = -0x232600;
            pYPos() = 0xBF3A00;
            break;
            case 56:
            pXPos() = -0x192600;
            pYPos() = 0xC1BA00;
            break;
            case 57:
            pXPos() = -0xF2600;
            pYPos() = 0xC43A00;
            break;
            case 58:
            pXPos() = -0x52600;
            pYPos() = 0xC6BA00;
            break;
            case 59:
            pXPos() = 0x4DA00;
            pYPos() = 0xC93A00;
            break;
            case 60:
            pXPos() = 0xEDA00;
            pYPos() = 0xCBBA00;
            break;
            case 61:
            pXPos() = 0x18DA00;
            pYPos() = 0xCE3A00;
            break;
            case 62:
            pXPos() = 0x20DA00;
            pYPos() = 0xD03A00;
            break;
            case 63:
            pXPos() = 0x2ADA00;
            pYPos() = 0xE0BA00;
            break;
            case 64:
            pXPos() = 0x34DA00;
            pYPos() = 0xE87200;
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

void O_R5_TunnelPath1::ObjectPlayerInteraction()
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
