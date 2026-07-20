#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_RotatingLog.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RotatingLog.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_RotatingLog::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    switch (objectEntityList[24].propertyValue) {
        case 0:
        AddSpriteFrame(-8, -8, 16, 16, 35, 1);
        break;
        case 1:
        AddSpriteFrame(-8, -8, 16, 16, 67, 174);
        break;
        case 2:
        AddSpriteFrame(-8, -8, 16, 16, 83, 174);
        break;
        case 3:
        AddSpriteFrame(-8, -8, 16, 16, 83, 158);
        break;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Rotating Log")) {
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 504;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 8;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 120;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 136;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 248;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 264;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 376;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 392;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R5_RotatingLog::ObjectMain()
{
    Entity *self = Self();

    self->values[0]++;
    self->values[0] &= 511;
    scriptEng.tempValue[1] = 96;
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

void O_R5_RotatingLog::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = self->YPos;
    self->XPos = self->values[1];
    self->YPos = self->values[2];
    PlayerObjectCollision(C_BOX, -8, -8, 8, 8);
    if (CheckResult() == 1) {
        pXPos() += self->values[3];
        pYPos() += self->values[4];
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
}

void O_R5_RotatingLog::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[1] = 96;
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
    DrawSprite_FrameXY(0, self->values[1], self->values[2]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
