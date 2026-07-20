#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_RotatingDrum.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RotatingDrum.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_RotatingDrum::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-24, -16, 48, 16, 67, 34);
    AddSpriteFrame(-24, -12, 48, 16, 116, 34);
    AddSpriteFrame(-24, -8, 48, 16, 165, 34);
    AddSpriteFrame(-24, -4, 48, 16, 67, 51);
    AddSpriteFrame(-24, -4, 48, 16, 116, 51);
    AddSpriteFrame(-24, -12, 48, 16, 67, 51);
    AddSpriteFrame(-24, -12, 48, 16, 165, 34);
    AddSpriteFrame(-24, -12, 48, 16, 116, 34);
    AddSpriteFrame(-24, -16, 48, 16, 67, 34);
    AddSpriteFrame(-24, -8, 48, 8, 165, 18);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Rotating Drum")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 3;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].state = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_RotatingDrum::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->frame = 0;
        self->direction = 0;
        self->drawOrder = 3;
        self->values[2] = 0x10000;
        break;
        case 1:
        self->frame = 1;
        self->direction = 0;
        self->drawOrder = 3;
        self->values[2] = 0x50000;
        break;
        case 2:
        self->frame = 2;
        self->direction = 0;
        self->drawOrder = 3;
        self->values[2] = 0x60000;
        break;
        case 3:
        self->frame = 3;
        self->direction = 0;
        self->drawOrder = 3;
        self->values[2] = 0x80000;
        break;
        case 4:
        self->frame = 4;
        self->direction = 0;
        self->drawOrder = 3;
        self->values[2] = 0x80000;
        break;
        case 5:
        self->frame = 5;
        self->direction = 2;
        self->drawOrder = 3;
        self->values[2] = 0x80000;
        break;
        case 6:
        self->frame = 6;
        self->direction = 2;
        self->drawOrder = 3;
        self->values[2] = 0x60000;
        break;
        case 7:
        self->frame = 7;
        self->direction = 2;
        self->drawOrder = 3;
        self->values[2] = 0x50000;
        break;
        case 8:
        self->frame = 8;
        self->direction = 2;
        self->drawOrder = 3;
        self->values[2] = 0x10000;
        break;
        case 9:
        self->frame = 9;
        self->direction = 2;
        self->drawOrder = 2;
        self->values[2] = -0x10000;
        break;
        case 10:
        self->frame = 9;
        self->direction = 2;
        self->drawOrder = 2;
        self->values[2] = -0x50000;
        break;
        case 11:
        self->frame = 9;
        self->direction = 2;
        self->drawOrder = 2;
        self->values[2] = -0x60000;
        break;
        case 12:
        self->frame = 9;
        self->direction = 2;
        self->drawOrder = 2;
        self->values[2] = -0x80000;
        break;
        case 13:
        self->frame = 9;
        self->direction = 2;
        self->drawOrder = 2;
        self->values[2] = -0x80000;
        break;
        case 14:
        self->frame = 9;
        self->direction = 0;
        self->drawOrder = 2;
        self->values[2] = -0x80000;
        break;
        case 15:
        self->frame = 9;
        self->direction = 0;
        self->drawOrder = 2;
        self->values[2] = -0x60000;
        break;
        case 16:
        self->frame = 9;
        self->direction = 0;
        self->drawOrder = 2;
        self->values[2] = -0x50000;
        break;
        case 17:
        self->frame = 9;
        self->direction = 0;
        self->drawOrder = 2;
        self->values[2] = -0x10000;
        break;
    }
    scriptEng.tempValue[0] = GVar("RotatingDrum_Timer");
    scriptEng.tempValue[0] %= 10;
    if (scriptEng.tempValue[0] == 0) {
        self->values[1]++;
        if (self->values[1] > 3) {
            self->values[1] = 0;
            self->state++;
            self->state %= 18;
        }
    } else {
        self->values[2] = 0;
    }
    self->priority = 1;
    scriptEng.tempValue[0] = (objectEntityList[objectLoop].XPos >> 16);
    scriptEng.tempValue[0] -= xScrollOffset;
    scriptEng.tempValue[0] -= SCREEN_XSIZE;
    if (scriptEng.tempValue[0] > 128) {
        self->YPos = self->values[3];
        self->state = self->propertyValue;
        self->values[1] = 0;
        self->values[2] = 0;
        self->priority = 3;
    }
    scriptEng.tempValue[0] = (objectEntityList[objectLoop].XPos >> 16);
    scriptEng.tempValue[0] -= xScrollOffset;
    if (scriptEng.tempValue[0] < -128) {
        self->YPos = self->values[3];
        self->state = self->propertyValue;
        self->values[1] = 0;
        self->values[2] = 0;
        self->priority = 3;
    }
}

void O_R3_RotatingDrum::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 2:
        PlayerObjectCollision(C_PLATFORM, -24, -8, 24, 12);
        if (CheckResult() == 1) {
            pYPos() += self->values[2];
        }
        break;
        case 3:
        case 4:
        case 5:
        case 6:
        PlayerObjectCollision(C_PLATFORM, -24, -4, 24, 12);
        if (CheckResult() == 1) {
            pYPos() += self->values[2];
        }
        break;
    }
}

void O_R3_RotatingDrum::ObjectDraw()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
