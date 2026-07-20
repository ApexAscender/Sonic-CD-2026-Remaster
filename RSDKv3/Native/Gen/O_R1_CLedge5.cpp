#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_CLedge5.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CLedge5.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_CLedge5::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects2.gif");
    AddSpriteFrame(-8, -40, 16, 48, 163, 1);
    AddSpriteFrame(-8, 8, 16, 16, 190, 66);
    AddSpriteFrame(-8, 24, 16, 16, 82, 49);
    AddSpriteFrame(-8, 24, 16, 16, 98, 49);
    AddSpriteFrame(-8, 24, 16, 16, 130, 49);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Crumble Ledge 5")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] <<= 3;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = -objectEntityList[scriptEng.arrayPosition[0]].values[0];
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_CLedge5::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[2] > 0) {
            self->values[2]--;
        } else {
            PlaySfx(globalSFXCount + 0, 0);
            self->state = 3;
        }
        break;
        case 2:
        if (self->values[2] > 0) {
            self->values[2]--;
        } else {
            PlaySfx(globalSFXCount + 0, 0);
            self->state = 4;
        }
        break;
        case 3:
        self->values[2]++;
        if (self->values[2] == 12) {
            self->values[2] = 0;
            if (self->values[1] > self->values[0]) {
                self->values[1] -= 16;
                scriptEng.tempValue[0] = self->values[1];
                scriptEng.tempValue[0] += 8;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                CreateTempObject(TypeNameID("Crumble Ledge 5"), 0, scriptEng.tempValue[0], self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].state = 6;
                if (self->values[3] == 1) {
                    objectEntityList[scriptEng.arrayPosition[2]].frame = 4;
                } else {
                    if (self->values[3] == self->propertyValue) {
                        objectEntityList[scriptEng.arrayPosition[2]].frame = 2;
                    } else {
                        objectEntityList[scriptEng.arrayPosition[2]].frame = 3;
                    }
                }
                self->values[3]--;
            } else {
                ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            }
        }
        break;
        case 4:
        self->values[2]++;
        if (self->values[2] == 12) {
            self->values[2] = 0;
            if (self->values[0] < self->values[1]) {
                self->values[0] += 16;
                scriptEng.tempValue[0] = self->values[0];
                scriptEng.tempValue[0] -= 8;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                CreateTempObject(TypeNameID("Crumble Ledge 5"), 0, scriptEng.tempValue[0], self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].state = 6;
                if (self->values[3] == 1) {
                    objectEntityList[scriptEng.arrayPosition[2]].frame = 2;
                } else {
                    if (self->values[3] == self->propertyValue) {
                        objectEntityList[scriptEng.arrayPosition[2]].frame = 4;
                    } else {
                        objectEntityList[scriptEng.arrayPosition[2]].frame = 3;
                    }
                }
                self->values[3]--;
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

void O_R1_CLedge5::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_PLATFORM, self->values[0], -24, self->values[1], 16);
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
        PlayerObjectCollision(C_PLATFORM, self->values[0], -24, self->values[1], 16);
    }
}

void O_R1_CLedge5::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        case 2:
        case 3:
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = self->values[0];
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] += 0x80000;
        scriptEng.tempValue[1] += self->XPos;
        scriptEng.tempValue[2] = self->propertyValue;
        scriptEng.tempValue[2]--;
        while (scriptEng.tempValue[0] < self->values[3]) {
            DrawSprite_FrameXY(0, scriptEng.tempValue[1], self->YPos);
            DrawSprite_FrameXY(1, scriptEng.tempValue[1], self->YPos);
            if (scriptEng.tempValue[0] == scriptEng.tempValue[2]) {
                DrawSprite_FrameXY(4, scriptEng.tempValue[1], self->YPos);
            } else {
                if (scriptEng.tempValue[0] == 0) {
                    DrawSprite_FrameXY(2, scriptEng.tempValue[1], self->YPos);
                } else {
                    DrawSprite_FrameXY(3, scriptEng.tempValue[1], self->YPos);
                }
            }
            scriptEng.tempValue[0]++;
            scriptEng.tempValue[1] += 0x100000;
        }
        break;
        case 4:
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = self->values[1];
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] -= 0x80000;
        scriptEng.tempValue[1] += self->XPos;
        scriptEng.tempValue[2] = self->propertyValue;
        scriptEng.tempValue[2]--;
        while (scriptEng.tempValue[0] < self->values[3]) {
            DrawSprite_FrameXY(0, scriptEng.tempValue[1], self->YPos);
            DrawSprite_FrameXY(1, scriptEng.tempValue[1], self->YPos);
            if (scriptEng.tempValue[0] == scriptEng.tempValue[2]) {
                DrawSprite_FrameXY(2, scriptEng.tempValue[1], self->YPos);
            } else {
                if (scriptEng.tempValue[0] == 0) {
                    DrawSprite_FrameXY(4, scriptEng.tempValue[1], self->YPos);
                } else {
                    DrawSprite_FrameXY(3, scriptEng.tempValue[1], self->YPos);
                }
            }
            scriptEng.tempValue[0]++;
            scriptEng.tempValue[1] -= 0x100000;
        }
        break;
        case 6:
        DrawSprite_Frame(0);
        DrawSprite_Frame(1);
        DrawSprite_Frame(self->frame);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
