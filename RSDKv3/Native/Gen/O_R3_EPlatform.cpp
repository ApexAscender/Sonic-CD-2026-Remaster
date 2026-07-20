#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_EPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from EPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_EPlatform::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects2.gif");
    AddSpriteFrame(-8, -16, 16, 32, 117, 0);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("EPlatform")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] <<= 3;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_EPlatform::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->propertyValue == 8) {
            PlayerObjectCollision(C_TOUCH, -64, -64, 64, -48);
            if (CheckResult() == 1) {
                self->state = 1;
                newYBoundary2 = (objectEntityList[objectLoop].YPos >> 16);
                newYBoundary2 += 24;
            }
        } else {
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] += 32;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] += self->XPos;
            if (pXPos() > scriptEng.tempValue[0]) {
                self->state = 2;
                self->priority = 1;
            }
        }
        break;
        case 1:
        if (self->values[2] < self->propertyValue) {
            self->values[2]++;
            self->values[0] -= 16;
        } else {
            self->state = 3;
        }
        break;
        case 2:
        if (self->values[2] < self->propertyValue) {
            self->values[2]++;
            self->values[0] -= 16;
        }
        if (self->values[3] < 100) {
            self->values[3]++;
            masterVolume--;
        } else {
            PlayMusic(4);
            self->state = 3;
            self->priority = 0;
        }
        break;
        case 3:
        break;
    }
}

void O_R3_EPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_PLATFORM, self->values[0], -16, self->values[1], 16);
}

void O_R3_EPlatform::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = self->values[1];
    scriptEng.tempValue[1] <<= 16;
    scriptEng.tempValue[1] -= 0x80000;
    scriptEng.tempValue[1] += self->XPos;
    while (scriptEng.tempValue[0] < self->values[2]) {
        DrawSprite_FrameXY(0, scriptEng.tempValue[1], self->YPos);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] -= 0x100000;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
