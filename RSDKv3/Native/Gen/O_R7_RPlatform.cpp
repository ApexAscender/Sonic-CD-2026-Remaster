#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_RPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_RPlatform::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 34, 1);
    AddSpriteFrame(-8, -8, 16, 16, 51, 1);
    AddSpriteFrame(-32, -8, 64, 16, 68, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("R Platform")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 19) {
                objectEntityList[scriptEng.arrayPosition[0]].state = 5;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 2;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 35) {
                objectEntityList[scriptEng.arrayPosition[0]].state = 3;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 2;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 54) {
                objectEntityList[scriptEng.arrayPosition[0]].state = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 5;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 67) {
                objectEntityList[scriptEng.arrayPosition[0]].state = 4;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 2;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 99) {
                objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 2;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 115) {
                objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 2;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_RPlatform::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[5]++;
        self->values[5] &= 511;
        self->values[0] = Sin512(self->values[5]);
        self->values[0] /= 3;
        self->values[0] += 640;
        break;
        case 1:
        self->values[5]++;
        self->values[5] &= 511;
        scriptEng.tempValue[0] = self->values[5];
        scriptEng.tempValue[0] >>= 1;
        scriptEng.tempValue[1] = Cos512(scriptEng.tempValue[0]);
        scriptEng.tempValue[1] >>= 1;
        self->values[0] = 640;
        self->values[0] -= scriptEng.tempValue[1];
        break;
        case 2:
        self->values[5]++;
        self->values[5] &= 511;
        scriptEng.tempValue[0] = self->values[5];
        scriptEng.tempValue[0] >>= 1;
        self->values[0] = Cos512(scriptEng.tempValue[0]);
        self->values[0] >>= 1;
        self->values[0] += 640;
        break;
        case 3:
        self->values[5]++;
        self->values[5] &= 511;
        self->values[0] = Sin512(self->values[5]);
        self->values[0] >>= 2;
        self->values[0] += 896;
        break;
        case 4:
        self->values[5]++;
        self->values[5] &= 511;
        self->values[0] = Sin512(self->values[5]);
        self->values[0] >>= 2;
        self->values[0] += 512;
        break;
        case 5:
        self->values[5]++;
        self->values[5] &= 511;
        self->values[0] = Sin512(self->values[5]);
        self->values[0] >>= 2;
        self->values[0] += 640;
        break;
    }
    scriptEng.tempValue[1] = self->values[6];
    scriptEng.tempValue[1]++;
    scriptEng.tempValue[1] <<= 4;
    self->values[3] = Cos512(self->values[0]);
    self->values[3] *= scriptEng.tempValue[1];
    self->values[3] <<= 7;
    self->values[3] += self->XPos;
    self->values[3] &= 0xFFFF0000;
    self->values[3] -= self->values[1];
    self->values[4] = Sin512(self->values[0]);
    self->values[4] *= scriptEng.tempValue[1];
    self->values[4] <<= 7;
    self->values[4] += self->YPos;
    self->values[4] &= 0xFFFF0000;
    self->values[4] -= self->values[2];
}

void O_R7_RPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[2] = pYPos();
    self->XPos = self->values[1];
    self->YPos = self->values[2];
    if (pState() == PlayerStateID("Player_State_Hurt")) {
        PlayerObjectCollision(C_BOX, -32, -8, 32, 8);
    } else {
        PlayerObjectCollision(C_BOX, -24, -8, 24, 8);
    }
    switch (CheckResult()) {
        case 1:
        pXPos() += self->values[3];
        pYPos() += self->values[4];
        break;
        case 2:
        case 3:
        CallScriptFunctionNamed("Player_Hit", scriptSub);
        case 4:
        PlayerObjectCollision(C_TOUCH, -16, -8, 16, 9);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Hurt")) {
                scriptEng.tempValue[3] = pXVel();
                if (scriptEng.tempValue[3] < 0) {
                    scriptEng.tempValue[3] = -scriptEng.tempValue[3];
                }
                if (scriptEng.tempValue[3] < 0x60000) {
                    if (pGravity() == 0) {
                        CallScriptFunctionNamed("Player_Kill", scriptSub);
                    }
                } else {
                    if (pGravity() == 0) {
                        CallScriptFunctionNamed("Player_Hit", scriptSub);
                    }
                }
            } else {
                pYPos() = scriptEng.tempValue[2];
            }
        } else {
            pYPos() = scriptEng.tempValue[2];
            if (pGravity() == 0) {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
        }
        break;
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
}

void O_R7_RPlatform::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(0);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 16;
    while (scriptEng.tempValue[0] < self->values[6]) {
        scriptEng.tempValue[2] = Cos512(self->values[0]);
        scriptEng.tempValue[2] *= scriptEng.tempValue[1];
        scriptEng.tempValue[2] <<= 7;
        scriptEng.tempValue[2] += self->XPos;
        scriptEng.tempValue[3] = Sin512(self->values[0]);
        scriptEng.tempValue[3] *= scriptEng.tempValue[1];
        scriptEng.tempValue[3] <<= 7;
        scriptEng.tempValue[3] += self->YPos;
        DrawSprite_FrameXY(1, scriptEng.tempValue[2], scriptEng.tempValue[3]);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 16;
    }
    self->values[1] = Cos512(self->values[0]);
    self->values[1] *= scriptEng.tempValue[1];
    self->values[1] <<= 7;
    self->values[1] += self->XPos;
    self->values[1] &= 0xFFFF0000;
    self->values[2] = Sin512(self->values[0]);
    self->values[2] *= scriptEng.tempValue[1];
    self->values[2] <<= 7;
    self->values[2] += self->YPos;
    self->values[2] &= 0xFFFF0000;
    DrawSprite_FrameXY(2, self->values[1], self->values[2]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
