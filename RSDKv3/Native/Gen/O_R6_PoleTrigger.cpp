#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_PoleTrigger.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PoleTrigger.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_PoleTrigger::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Pole Trigger")) {
            scriptEng.arrayPosition[1] = scriptEng.arrayPosition[0];
            scriptEng.arrayPosition[1]++;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] <<= 3;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = -objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[0] -= 8;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 8;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_PoleTrigger::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_TOUCH, -4, self->values[0], 4, self->values[1]);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Hurt")) {
                self->state = 1;
                self->values[3] = 0;
                pState() = PlayerStateID("Player_State_Static");
                pAnimation() = GVar("ANI_JUMPING");
                pXPos() = self->XPos;
                pXVel() = 0;
                pSpeed() = 0;
                PlrEntity()->drawOrder = 5;
                if (pYVel() > 0) {
                    pYVel() = 0x20000;
                } else {
                    pYVel() = -0x20000;
                }
            }
        }
    } else {
        if (pState() == PlayerStateID("Player_State_Static")) {
            if (pJumpPress() == 1) {
                self->values[3] = 1;
            }
            self->values[2] += 16;
            self->values[2] &= 511;
            pXPos() = Sin512(self->values[2]);
            pXPos() *= -0xC00;
            pXPos() += self->XPos;
            PlrEntity()->drawOrder = 4;
            if (self->values[2] < 129) {
                PlrEntity()->drawOrder = 5;
            }
            if (self->values[2] > 383) {
                PlrEntity()->drawOrder = 5;
            }
            scriptEng.tempValue[0] = pYPos();
            scriptEng.tempValue[0] -= self->YPos;
            scriptEng.tempValue[0] >>= 16;
            if (scriptEng.tempValue[0] < 0) {
                if (scriptEng.tempValue[0] < self->values[0]) {
                    pYVel() = 0x20000;
                }
            } else {
                if (scriptEng.tempValue[0] > self->values[1]) {
                    pYVel() = -0x20000;
                }
            }
            if (self->values[3] == 1) {
                if (self->values[2] == 128) {
                    PlrEntity()->drawOrder = 4;
                    pState() = PlayerStateID("Player_State_Air");
                    pSpeed() = -0xC0000;
                    pXVel() = -0xC0000;
                    self->state = 0;
                }
                if (self->values[2] == 384) {
                    PlrEntity()->drawOrder = 4;
                    pState() = PlayerStateID("Player_State_Air");
                    pSpeed() = 0xC0000;
                    pXVel() = 0xC0000;
                    self->state = 0;
                }
            }
        } else {
            if (PlrEntity()->drawOrder == 5) {
                PlrEntity()->drawOrder = 4;
            }
            self->state = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
