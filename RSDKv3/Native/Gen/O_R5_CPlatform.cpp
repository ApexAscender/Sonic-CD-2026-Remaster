#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_CPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_CPlatform::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("CPlatform")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] <<= 3;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = -objectEntityList[scriptEng.arrayPosition[0]].values[0];
        }
        scriptEng.arrayPosition[0]++;
    }
    AddSpriteFrame(-8, -16, 16, 32, 108, 51);
    AddSpriteFrame(-8, -8, 16, 16, 108, 51);
    AddSpriteFrame(-8, -8, 16, 16, 108, 67);
}

void O_R5_CPlatform::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[2] > 0) {
            self->values[2]--;
        } else {
            PlaySfx(globalSFXCount + 0, 0);
            self->state = 4;
        }
        break;
        case 2:
        if (self->values[2] > 0) {
            self->values[2]--;
        } else {
            PlaySfx(globalSFXCount + 0, 0);
            self->state = 3;
        }
        break;
        case 3:
        self->values[2]++;
        if (self->values[2] == 10) {
            self->values[2] = 0;
            if (self->values[0] < self->values[1]) {
                self->values[3]--;
                self->values[0] += 16;
                scriptEng.tempValue[0] = self->values[0];
                scriptEng.tempValue[0] -= 8;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] -= 0x80000;
                CreateTempObject(TypeNameID("CPlatform"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                objectEntityList[scriptEng.arrayPosition[2]].state = 6;
                objectEntityList[scriptEng.arrayPosition[2]].values[4] = -0x10000;
                objectEntityList[scriptEng.arrayPosition[2]].propertyValue = 1;
                scriptEng.tempValue[1] += 0x100000;
                CreateTempObject(TypeNameID("CPlatform"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                objectEntityList[scriptEng.arrayPosition[2]].state = 6;
                objectEntityList[scriptEng.arrayPosition[2]].propertyValue = 2;
            } else {
                ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            }
        }
        break;
        case 4:
        self->values[2]++;
        if (self->values[2] == 10) {
            self->values[2] = 0;
            if (self->values[1] > self->values[0]) {
                self->values[3]--;
                self->values[1] -= 16;
                scriptEng.tempValue[0] = self->values[1];
                scriptEng.tempValue[0] += 8;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] -= 0x80000;
                CreateTempObject(TypeNameID("CPlatform"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                objectEntityList[scriptEng.arrayPosition[2]].state = 6;
                objectEntityList[scriptEng.arrayPosition[2]].values[4] = -0x10000;
                objectEntityList[scriptEng.arrayPosition[2]].propertyValue = 1;
                scriptEng.tempValue[1] += 0x100000;
                CreateTempObject(TypeNameID("CPlatform"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                objectEntityList[scriptEng.arrayPosition[2]].state = 6;
                objectEntityList[scriptEng.arrayPosition[2]].propertyValue = 2;
            } else {
                ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            }
        }
        break;
        case 5:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->values[3] = self->propertyValue;
            self->values[0] = self->propertyValue;
            self->values[0] <<= 3;
            self->values[1] = self->values[0];
            self->values[0] = -self->values[0];
            self->priority = 0;
            self->values[2] = 0;
        }
        break;
        case 6:
        self->values[4] += 0x4000;
        if (self->values[4] > 0) {
            self->YPos += self->values[4];
        }
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_R5_CPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_PLATFORM, self->values[0], -16, self->values[1], 16);
        if (CheckResult() == 1) {
            self->values[2] = 1;
            self->priority = 1;
            if (pXPos() > self->XPos) {
                self->state = 1;
            } else {
                self->state = 2;
            }
        }
    } else {
        PlayerObjectCollision(C_PLATFORM, self->values[0], -16, self->values[1], 16);
    }
}

void O_R5_CPlatform::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        case 2:
        case 4:
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = self->values[0];
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] += 0x80000;
        scriptEng.tempValue[1] += self->XPos;
        while (scriptEng.tempValue[0] < self->values[3]) {
            DrawSprite_FrameXY(0, scriptEng.tempValue[1], self->YPos);
            scriptEng.tempValue[0]++;
            scriptEng.tempValue[1] += 0x100000;
        }
        break;
        case 3:
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = self->values[1];
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] -= 0x80000;
        scriptEng.tempValue[1] += self->XPos;
        while (scriptEng.tempValue[0] < self->values[3]) {
            DrawSprite_FrameXY(0, scriptEng.tempValue[1], self->YPos);
            scriptEng.tempValue[0]++;
            scriptEng.tempValue[1] -= 0x100000;
        }
        break;
        case 6:
        DrawSprite_Frame(self->propertyValue);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
