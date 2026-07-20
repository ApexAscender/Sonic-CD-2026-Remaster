#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_Amy.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Amy.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_Amy::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects3.gif");
    AddSpriteFrame(-11, -20, 22, 40, 34, 208);
    AddSpriteFrame(-11, -20, 22, 40, 57, 208);
    AddSpriteFrame(-11, -20, 22, 40, 34, 208);
    AddSpriteFrame(-11, -20, 22, 40, 126, 167);
    AddSpriteFrame(-15, -20, 30, 40, 68, 167);
    AddSpriteFrame(-10, -20, 21, 40, 206, 208);
    AddSpriteFrame(-13, -20, 26, 40, 99, 167);
    AddSpriteFrame(-10, -20, 21, 40, 206, 208);
    AddSpriteFrame(0, -16, 24, 40, 1, 170);
    AddSpriteFrame(0, -16, 24, 40, 1, 211);
    AddSpriteFrame(-12, -20, 24, 40, 107, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Amy Rose")) {
            if (playerListPos == 0) {
                if (GVar("Options.GameMode") == 2) {
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                    scriptEng.arrayPosition[0]++;
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                    scriptEng.arrayPosition[0]++;
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                    scriptEng.arrayPosition[0]++;
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                    scriptEng.arrayPosition[0]++;
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                } else {
                    objectEntityList[scriptEng.arrayPosition[0]].state = 3;
                    objectEntityList[scriptEng.arrayPosition[0]].values[3] = 0x780000;
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x3BC0000;
                    objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
                }
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_Amy::ObjectMain()
{
    Entity *self = Self();

    self->priority = 1;
    if (pXPos() < self->XPos) {
        self->direction = 1;
    } else {
        self->direction = 0;
    }
    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] /= 10;
        scriptEng.tempValue[0] += 11;
        self->frame = scriptEng.tempValue[0];
        self->values[0]++;
        if (self->values[0] > 139) {
            self->values[0] = 0;
        }
        PlayerObjectCollision(C_TOUCH, -96, -360, 96, 360);
        if (CheckResult() == 1) {
            self->values[1] = 0;
            self->state = 1;
            self->frame = 4;
            self->values[0] = 0;
        }
        break;
        case 1:
        self->values[0]++;
        switch (self->frame) {
            case 4:
            case 6:
            if (self->values[0] == 4) {
                self->values[0] = 0;
                self->frame++;
            }
            break;
            case 5:
            case 7:
            if (self->values[0] == 3) {
                self->values[0] = 0;
                self->frame++;
            }
            break;
        }
        if (self->frame > 7) {
            self->frame = 4;
        }
        if (self->direction == 0) {
            if (self->values[1] < 0x20000) {
                self->values[1] += 0x2000;
            }
            if (self->XPos < self->values[4]) {
                self->XPos += self->values[1];
            } else {
                self->values[1] = 0;
                self->XPos = self->values[4];
                self->state = 2;
                self->frame = 0;
                self->values[0] = 0;
            }
        } else {
            if (self->values[1] > -0x20000) {
                self->values[1] -= 0x2000;
            }
            if (self->XPos > self->values[3]) {
                self->XPos += self->values[1];
            } else {
                self->values[1] = 0;
                self->XPos = self->values[3];
                self->state = 3;
                self->frame = 0;
                self->values[0] = 0;
            }
        }
        break;
        case 2:
        self->values[0]++;
        if (self->values[0] == 12) {
            self->values[0] = 0;
            self->frame++;
        }
        if (self->frame > 3) {
            self->frame = 0;
        }
        if (objectEntityList[objectLoop + 1].state == 0) {
            if (objectEntityList[objectLoop + 1].values[0] < 60) {
                objectEntityList[objectLoop + 1].values[0]++;
            } else {
                objectEntityList[objectLoop + 1].values[0] = 0;
                objectEntityList[objectLoop + 1].state = 1;
                objectEntityList[objectLoop + 1].priority = 1;
            }
        }
        break;
        case 3:
        self->values[0]++;
        if (self->values[0] == 12) {
            self->values[0] = 0;
            self->frame++;
        }
        if (self->frame > 3) {
            self->frame = 0;
        }
        if (self->direction == 0) {
            self->state = 1;
            self->frame = 4;
            self->values[0] = 0;
        }
        break;
        case 4:
        self->values[0]++;
        if (self->values[0] > 13) {
            self->values[0] = 0;
            self->frame++;
            if (self->frame > 9) {
                self->frame = 8;
            }
        }
        break;
    }
    self->values[7]++;
    if (self->state < 4) {
        if (self->values[7] > 41) {
            CreateTempObject(TypeNameID("Love Heart"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (6)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 255;
            self->values[7] = 0;
        }
    }
    if (self->values[5] == 0) {
        ObjectTileGrip_Script(0, 0, 19, 0);
    } else {
        self->values[2] += 0x4000;
        self->YPos += self->values[2];
        ObjectTileCollision_Script(0, 0, 19, 0);
        if (CheckResult() == 1) {
            self->values[2] = 0;
            self->values[5] = 0;
        }
    }
}

void O_R3_Amy::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
