#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_CrushingPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CrushingPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_CrushingPlatform::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-32, -32, 64, 64, 1, 1);
    AddSpriteFrame(-32, -96, 64, 64, 1, 1);
    AddSpriteFrame(-32, 32, 64, 64, 1, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Crush Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[6] = 2;
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 0) {
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x1000;
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x1800;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 5) {
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x1000;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 69) {
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x1800;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 72) {
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 6;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_CrushingPlatform::ObjectMain()
{
    Entity *self = Self();

    if (self->values[5] == 0) {
        self->values[3] += self->values[6];
        self->values[3] &= 511;
        if (self->propertyValue == 1) {
            self->values[3] += 256;
        }
        self->values[2] = Sin512(self->values[3]);
        self->values[2] *= self->values[4];
        self->values[2] += self->YPos;
        self->values[2] &= 0xFFFF0000;
        self->values[2] -= self->values[1];
    } else {
        switch (self->state) {
            case 0:
            self->values[3] += 4;
            self->values[3] &= 511;
            if (self->values[3] == 128) {
                self->state++;
            }
            break;
            case 1:
            if (self->values[0] < 64) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 2:
            self->values[3] += 4;
            self->values[3] &= 511;
            if (self->values[3] == 384) {
                self->state++;
            }
            break;
            case 3:
            if (self->values[0] < 64) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state = 0;
            }
            break;
        }
        self->values[2] = Sin512(self->values[3]);
        self->values[2] *= self->values[4];
        self->values[2] += self->YPos;
        self->values[2] &= 0xFFFF0000;
        self->values[2] -= self->values[1];
    }
}

void O_R8_CrushingPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    scriptEng.tempValue[1] = pYPos();
    self->YPos = self->values[1];
    if (self->values[5] == 0) {
        PlayerObjectCollision(C_BOX, -32, -32, 32, 32);
        if (CheckResult() == 1) {
            pYPos() += self->values[2];
        } else {
            if (CheckResult() == 4) {
                if (pGravity() == 0) {
                    if (self->values[2] > 0) {
                        CallScriptFunctionNamed("Player_Kill", scriptSub);
                    } else {
                        pYPos() = scriptEng.tempValue[1];
                    }
                } else {
                }
            }
        }
    } else {
        PlayerObjectCollision(C_BOX, -32, -96, 32, 96);
        if (CheckResult() == 1) {
            pYPos() += self->values[2];
            if (self->values[3] == 320) {
                pState() = PlayerStateID("Player_State_Air");
                pTimer() = 0;
                pYVel() = -0x100000;
                pAnimation() = GVar("ANI_BOUNCING");
                pGravity() = 1;
                PlayerValue(7) = GVar("ANI_WALKING");
            }
        } else {
            if (CheckResult() == 4) {
                if (pGravity() == 0) {
                    if (self->values[2] > 0) {
                        CallScriptFunctionNamed("Player_Kill", scriptSub);
                    } else {
                        pYPos() = scriptEng.tempValue[1];
                    }
                } else {
                }
            }
        }
    }
    self->YPos = scriptEng.tempValue[0];
}

void O_R8_CrushingPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = Sin512(self->values[3]);
    self->values[1] *= self->values[4];
    self->values[1] += self->YPos;
    self->values[1] &= 0xFFFF0000;
    DrawSprite_FrameXY(0, self->XPos, self->values[1]);
    if (self->values[5] == 1) {
        DrawSprite_FrameXY(1, self->XPos, self->values[1]);
        DrawSprite_FrameXY(2, self->XPos, self->values[1]);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
