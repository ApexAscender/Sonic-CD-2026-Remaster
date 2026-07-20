#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_RotatingSpikes.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RotatingSpikes.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_RotatingSpikes::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 133, 199);
    AddSpriteFrame(-8, -8, 16, 16, 150, 199);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Rotating Spikes")) {
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 0:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 2;
                switch (objectEntityList[24].propertyValue) {
                    case 0:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 5;
                    break;
                    case 1:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 4;
                    break;
                    case 2:
                    case 3:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 6;
                    break;
                }
                break;
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = -2;
                switch (objectEntityList[24].propertyValue) {
                    case 0:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 5;
                    break;
                    case 1:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 4;
                    break;
                    case 2:
                    case 3:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 6;
                    break;
                }
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 384;
                break;
                case 2:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = -2;
                switch (objectEntityList[24].propertyValue) {
                    case 0:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 5;
                    break;
                    case 1:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 4;
                    break;
                    case 2:
                    case 3:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 6;
                    break;
                }
                break;
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = -2;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 2;
                break;
                case 4:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 2;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 6;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_RotatingSpikes::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 2) {
        self->values[0] = objectEntityList[objectLoop - 1].rotation;
    } else {
        self->values[0] += self->values[1];
    }
    if (self->values[0] < 0) {
        self->values[0] += 512;
    }
    self->values[0] &= 511;
}

void O_R6_RotatingSpikes::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 16;
    scriptEng.tempValue[2] = self->XPos;
    scriptEng.tempValue[3] = self->YPos;
    while (scriptEng.tempValue[0] < self->values[2]) {
        self->XPos = Cos512(self->values[0]);
        self->XPos *= scriptEng.tempValue[1];
        self->XPos <<= 7;
        self->XPos += scriptEng.tempValue[2];
        self->YPos = Sin512(self->values[0]);
        self->YPos *= scriptEng.tempValue[1];
        self->YPos <<= 7;
        self->YPos += scriptEng.tempValue[3];
        PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 16;
    }
    self->XPos = scriptEng.tempValue[2];
    self->YPos = scriptEng.tempValue[3];
}

void O_R6_RotatingSpikes::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(0);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 16;
    while (scriptEng.tempValue[0] < self->values[2]) {
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
}

#endif // RETRO_USE_NATIVE_OBJECTS
