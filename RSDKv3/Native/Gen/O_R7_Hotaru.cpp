#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_Hotaru.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Hotaru.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_Hotaru::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-20, -12, 40, 24, 182, 121);
    AddSpriteFrame(-12, -20, 24, 40, 231, 119);
    AddSpriteFrame(-12, -20, 24, 40, 231, 160);
    AddSpriteFrame(-20, -12, 40, 24, 182, 146);
    AddSpriteFrame(-12, -20, 24, 40, 231, 201);
    AddSpriteFrame(-12, -20, 24, 40, 206, 215);
    AddSpriteFrame(-11, -7, 24, 24, 175, 196);
    AddSpriteFrame(-12, -12, 24, 24, 150, 171);
    AddSpriteFrame(-12, -12, 24, 24, 175, 171);
    AddSpriteFrame(-12, -12, 24, 24, 150, 196);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Hotaru")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 5;
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 0:
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 0x3C0000;
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x230000;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x230000;
                break;
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 0x3C0000;
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x230000;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x230000;
                break;
                case 4:
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 0x440000;
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x320000;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x320000;
                break;
                case 5:
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 0x440000;
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x320000;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x320000;
                break;
                case 8:
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 0x380000;
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x460000;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x460000;
                break;
                case 9:
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 0x380000;
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x460000;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x460000;
                break;
                case 12:
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 0x120000;
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x600000;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x600000;
                break;
                case 13:
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 0x120000;
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x600000;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x600000;
                break;
            }
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[5] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[5] & ~(1 << 0));
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[5] | (1 << 1)) : (objectEntityList[scriptEng.arrayPosition[0]].values[5] & ~(1 << 1));
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_Hotaru::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 12;
        self->values[0] = 0;
        self->XPos = self->values[1];
        self->YPos = self->values[2];
        self->values[3] = -0x230000;
        self->values[4] = 0x230000;
        self->values[6] = 0;
    }
    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->priority = 1;
            if (self->values[3] < 0x2B0000) {
                self->values[3] += 0x10000;
                self->values[4] -= 0x10000;
            } else {
                self->state = 1;
            }
            break;
            case 1:
            if (self->values[3] > -0x730000) {
                self->values[3] -= 0x10000;
                self->values[4] += 0x10000;
            } else {
                self->state = 0;
            }
            break;
            case 2:
            scriptEng.tempValue[0] = xScrollOffset;
            scriptEng.tempValue[0] += SCREEN_CENTERX;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[1] = 0;
            if (self->XPos < scriptEng.tempValue[0]) {
                self->XPos += 0x20000;
                if (self->XPos >= scriptEng.tempValue[0]) {
                    self->XPos = scriptEng.tempValue[0];
                    scriptEng.tempValue[1] = 1;
                }
            } else {
                self->XPos -= 0x20000;
                if (self->XPos <= scriptEng.tempValue[0]) {
                    self->XPos = scriptEng.tempValue[0];
                    scriptEng.tempValue[1] = 1;
                }
            }
            scriptEng.tempValue[0] = yScrollOffset;
            scriptEng.tempValue[0] += 104;
            scriptEng.tempValue[0] <<= 16;
            if (self->YPos < scriptEng.tempValue[0]) {
                self->YPos += 0x20000;
                if (self->YPos >= scriptEng.tempValue[0]) {
                    self->YPos = scriptEng.tempValue[0];
                    if (scriptEng.tempValue[1] == 1) {
                        self->state++;
                    }
                }
            } else {
                self->YPos -= 0x20000;
                if (self->YPos <= scriptEng.tempValue[0]) {
                    self->YPos = scriptEng.tempValue[0];
                    if (scriptEng.tempValue[1] == 1) {
                        self->state++;
                    }
                }
            }
            break;
            case 3:
            if (self->values[0] < 100) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            self->frame = self->values[0];
            self->frame %= 20;
            self->frame /= 10;
            self->frame++;
            break;
            case 4:
            if (self->values[0] < 4) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 5:
            if (self->values[0] < 12) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 6:
            if (self->values[0] < 8) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 7:
            if (self->values[0] < 8) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 8:
            if (self->values[0] < 12) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 9:
            if (self->values[0] < 4) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->animationTimer = 0;
                self->state++;
            }
            break;
            case 10:
            if (self->values[0] < 100) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            self->frame = self->values[0];
            self->frame %= 20;
            self->frame /= 10;
            self->frame++;
            break;
            case 11:
            self->YPos -= 0x20000;
            self->values[0]++;
            self->values[0] %= 20;
            self->frame = self->values[0];
            self->frame /= 10;
            self->frame++;
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 12;
                self->values[0] = 0;
                self->XPos = self->values[1];
                self->YPos = self->values[2];
                self->values[3] = -0x230000;
                self->values[4] = 0x230000;
            }
            break;
            case 12:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
                self->frame = 0;
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            self->priority = 1;
            self->frame = 3;
            if (self->values[3] < 0x2B0000) {
                self->values[3] += 0x8000;
                self->values[4] -= 0x8000;
            } else {
                self->state = 1;
            }
            break;
            case 1:
            if (self->values[3] > -0x730000) {
                self->values[3] -= 0x8000;
                self->values[4] += 0x8000;
            } else {
                self->state = 0;
            }
            break;
            case 2:
            scriptEng.tempValue[0] = xScrollOffset;
            scriptEng.tempValue[0] += SCREEN_CENTERX;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[1] = 0;
            if (self->XPos < scriptEng.tempValue[0]) {
                self->XPos += 0x10000;
                if (self->XPos >= scriptEng.tempValue[0]) {
                    self->XPos = scriptEng.tempValue[0];
                    scriptEng.tempValue[1] = 1;
                }
            } else {
                self->XPos -= 0x10000;
                if (self->XPos <= scriptEng.tempValue[0]) {
                    self->XPos = scriptEng.tempValue[0];
                    scriptEng.tempValue[1] = 1;
                }
            }
            scriptEng.tempValue[0] = yScrollOffset;
            scriptEng.tempValue[0] += 104;
            scriptEng.tempValue[0] <<= 16;
            if (self->YPos < scriptEng.tempValue[0]) {
                self->YPos += 0x10000;
                if (self->YPos >= scriptEng.tempValue[0]) {
                    self->YPos = scriptEng.tempValue[0];
                    if (scriptEng.tempValue[1] == 1) {
                        self->state++;
                    }
                }
            } else {
                self->YPos -= 0x10000;
                if (self->YPos <= scriptEng.tempValue[0]) {
                    self->YPos = scriptEng.tempValue[0];
                    if (scriptEng.tempValue[1] == 1) {
                        self->state++;
                    }
                }
            }
            break;
            case 3:
            if (self->values[0] < 100) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            self->frame = self->values[0];
            self->frame %= 40;
            self->frame /= 20;
            self->frame += 4;
            break;
            case 4:
            if (self->values[0] < 10) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 5:
            if (self->values[0] < 30) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 6:
            if (self->values[0] < 20) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 7:
            if (self->values[0] < 20) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 8:
            if (self->values[0] < 30) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 9:
            if (self->values[0] < 10) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->animationTimer = 0;
                self->state++;
            }
            break;
            case 10:
            if (self->values[0] < 200) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            self->frame = self->values[0];
            self->frame %= 40;
            self->frame /= 20;
            self->frame += 4;
            break;
            case 11:
            self->YPos -= 0x20000;
            self->values[0]++;
            self->values[0] %= 40;
            self->frame = self->values[0];
            self->frame /= 20;
            self->frame += 4;
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 12;
                self->values[0] = 0;
                self->XPos = self->values[1];
                self->YPos = self->values[2];
                self->values[3] = -0x230000;
                self->values[4] = 0x230000;
            }
            break;
            case 12:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
                self->frame = 0;
            }
            break;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
    if (self->values[5] == 0) {
        ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
    }
}

void O_R7_Hotaru::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        PlayerObjectCollision(C_TOUCH, -64, -64, 64, 64);
        if (CheckResult() == 1) {
            self->state = 2;
        }
        break;
        case 6:
        case 7:
        case 8:
        case 9:
        if (self->propertyValue == 0) {
            if (self->values[3] < 0) {
                scriptEng.tempValue[0] = self->values[3];
                scriptEng.tempValue[0] >>= 16;
                scriptEng.tempValue[1] = self->values[4];
                scriptEng.tempValue[1] >>= 16;
            } else {
                scriptEng.tempValue[0] = self->values[4];
                scriptEng.tempValue[0] >>= 16;
                scriptEng.tempValue[1] = self->values[3];
                scriptEng.tempValue[1] >>= 16;
            }
            scriptEng.tempValue[0] += 8;
            scriptEng.tempValue[1] -= 8;
            PlayerObjectCollision(C_TOUCH, scriptEng.tempValue[0], -60, scriptEng.tempValue[1], 60);
            if (CheckResult() == 1) {
                self->values[6] = 1;
            }
        }
    }
    if (self->state < 12) {
        scriptEng.tempValue[6] = self->XPos;
        scriptEng.tempValue[7] = self->YPos;
        scriptEng.tempValue[1] = ((self->values[5] >> 0) & 1);
        if (scriptEng.tempValue[1] == 1) {
            self->XPos += self->values[3];
            self->YPos -= self->values[7];
            PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
            if (CheckResult() == 1) {
                scriptEng.arrayPosition[1] = objectLoop;
                scriptEng.arrayPosition[1]++;
                Hotaru_HotaruBreak();
                if (objectEntityList[objectLoop + 1].type == GVar("Flower_TypeNo")) {
                    self->values[5] = (0) ? (self->values[5] | (1 << 0)) : (self->values[5] & ~(1 << 0));
                }
            }
            self->XPos = scriptEng.tempValue[6];
            self->YPos = scriptEng.tempValue[7];
        }
        scriptEng.tempValue[1] = ((self->values[5] >> 1) & 1);
        if (scriptEng.tempValue[1] == 1) {
            self->XPos += self->values[4];
            self->YPos += self->values[7];
            PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
            if (CheckResult() == 1) {
                scriptEng.arrayPosition[1] = objectLoop;
                scriptEng.arrayPosition[1] += 2;
                Hotaru_HotaruBreak();
                if (objectEntityList[objectLoop + 2].type == GVar("Flower_TypeNo")) {
                    self->values[5] = (0) ? (self->values[5] | (1 << 1)) : (self->values[5] & ~(1 << 1));
                }
            }
        }
        if (self->state == 10) {
            if (self->values[6] == 1) {
                if (self->values[5] == 3) {
                    self->XPos = scriptEng.tempValue[6];
                    self->YPos = scriptEng.tempValue[7];
                    PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
                    if (CheckResult() == 1) {
                        CallScriptFunctionNamed("Player_Hit", scriptSub);
                    }
                    self->XPos = scriptEng.tempValue[6];
                    self->XPos >>= 1;
                    scriptEng.tempValue[1] = scriptEng.tempValue[6];
                    scriptEng.tempValue[1] += self->values[3];
                    scriptEng.tempValue[1] >>= 1;
                    self->XPos += scriptEng.tempValue[1];
                    self->YPos = scriptEng.tempValue[7];
                    self->YPos >>= 1;
                    scriptEng.tempValue[1] = scriptEng.tempValue[7];
                    scriptEng.tempValue[1] -= self->values[7];
                    scriptEng.tempValue[1] >>= 1;
                    self->YPos += scriptEng.tempValue[1];
                    PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
                    if (CheckResult() == 1) {
                        CallScriptFunctionNamed("Player_Hit", scriptSub);
                    }
                    self->XPos = scriptEng.tempValue[6];
                    self->XPos >>= 1;
                    scriptEng.tempValue[1] = scriptEng.tempValue[6];
                    scriptEng.tempValue[1] += self->values[4];
                    scriptEng.tempValue[1] >>= 1;
                    self->XPos += scriptEng.tempValue[1];
                    self->YPos = scriptEng.tempValue[7];
                    self->YPos >>= 1;
                    scriptEng.tempValue[1] = scriptEng.tempValue[7];
                    scriptEng.tempValue[1] += self->values[7];
                    scriptEng.tempValue[1] >>= 1;
                    self->YPos += scriptEng.tempValue[1];
                    PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
                    if (CheckResult() == 1) {
                        CallScriptFunctionNamed("Player_Hit", scriptSub);
                    }
                }
            }
        }
        self->XPos = scriptEng.tempValue[6];
        self->YPos = scriptEng.tempValue[7];
    }
}

void O_R7_Hotaru::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        CheckResult() = ((self->values[5] >> 0) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] -= self->values[7];
            self->direction = 1;
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        CheckResult() = ((self->values[5] >> 1) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[4];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] += self->values[7];
            self->direction = 0;
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        break;
        case 1:
        CheckResult() = ((self->values[5] >> 0) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] -= self->values[7];
            self->direction = 0;
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        CheckResult() = ((self->values[5] >> 1) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[4];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] += self->values[7];
            self->direction = 1;
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        break;
        case 2:
        if (pXPos() < self->XPos) {
            self->direction = 0;
        } else {
            self->direction = 1;
        }
        CheckResult() = ((self->values[5] >> 0) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] -= self->values[7];
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        CheckResult() = ((self->values[5] >> 1) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[4];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] += self->values[7];
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        break;
        case 3:
        self->XPos = xScrollOffset;
        self->XPos += SCREEN_CENTERX;
        self->XPos <<= 16;
        self->YPos = yScrollOffset;
        self->YPos += 104;
        self->YPos <<= 16;
        CheckResult() = ((self->values[5] >> 0) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] -= self->values[7];
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        CheckResult() = ((self->values[5] >> 1) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[4];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] += self->values[7];
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        break;
        case 4:
        case 6:
        case 8:
        case 11:
        CheckResult() = ((self->values[5] >> 0) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] -= self->values[7];
            DrawSpriteFX_Script(6, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        CheckResult() = ((self->values[5] >> 1) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[4];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] += self->values[7];
            DrawSpriteFX_Script(6, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        break;
        case 5:
        case 7:
        case 9:
        CheckResult() = ((self->values[5] >> 0) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] -= self->values[7];
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        CheckResult() = ((self->values[5] >> 1) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[4];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] += self->values[7];
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        break;
        case 10:
        CheckResult() = ((self->values[5] >> 0) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] -= self->values[7];
            DrawSpriteFX_Script(6, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        CheckResult() = ((self->values[5] >> 1) & 1);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[4];
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = self->YPos;
            scriptEng.tempValue[1] += self->values[7];
            DrawSpriteFX_Script(6, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            DrawSpriteFX_Script(self->frame, FX_FLIP, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        if (self->values[6] == 1) {
            if (self->values[5] == 3) {
                scriptEng.tempValue[0] = self->animationTimer;
                scriptEng.tempValue[0] >>= 1;
                scriptEng.tempValue[0] += 7;
                DrawSprite_Frame(scriptEng.tempValue[0]);
                scriptEng.tempValue[1] = self->XPos;
                scriptEng.tempValue[1] >>= 1;
                scriptEng.tempValue[3] = self->XPos;
                scriptEng.tempValue[3] += self->values[3];
                scriptEng.tempValue[3] >>= 1;
                scriptEng.tempValue[1] += scriptEng.tempValue[3];
                scriptEng.tempValue[2] = self->YPos;
                scriptEng.tempValue[2] >>= 1;
                scriptEng.tempValue[3] = self->YPos;
                scriptEng.tempValue[3] -= self->values[7];
                scriptEng.tempValue[3] >>= 1;
                scriptEng.tempValue[2] += scriptEng.tempValue[3];
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                scriptEng.tempValue[1] = self->XPos;
                scriptEng.tempValue[1] >>= 1;
                scriptEng.tempValue[3] = self->XPos;
                scriptEng.tempValue[3] += self->values[4];
                scriptEng.tempValue[3] >>= 1;
                scriptEng.tempValue[1] += scriptEng.tempValue[3];
                scriptEng.tempValue[2] = self->YPos;
                scriptEng.tempValue[2] >>= 1;
                scriptEng.tempValue[3] = self->YPos;
                scriptEng.tempValue[3] += self->values[7];
                scriptEng.tempValue[3] >>= 1;
                scriptEng.tempValue[2] += scriptEng.tempValue[3];
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                self->animationTimer++;
                self->animationTimer %= 6;
            }
        }
        break;
    }
}

void O_R7_Hotaru::Hotaru_HotaruBreak()
{
    Entity *self = Self();

    CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
    scriptEng.tempValue[0] = CheckResult();
    CheckResult() = (pAnimation() == GVar("ANI_SPINDASH"));
    scriptEng.tempValue[0] |= CheckResult();
    if (pAnimation() == GVar("ANI_FLYING")) {
        CheckResult() = (pYPos() > self->YPos);
        scriptEng.tempValue[0] |= CheckResult();
    }
    if (scriptEng.tempValue[0] == 1) {
        ResetObjectEntity(scriptEng.arrayPosition[1], GVar("Flower_TypeNo"), 0, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[1]].drawOrder = 4;
        CreateTempObject(TypeNameID("Smoke Puff"), 0, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
        CreateTempObject(TypeNameID("Object Score"), objectEntityList[26].values[0], self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
        PlaySfx(8, 0);
        if (pYVel() > 0) {
            pYVel() = -pYVel();
        } else {
            pYVel() += 0xC000;
        }
        switch (objectEntityList[26].values[0]) {
            case 0:
            GVar("Player.Score") += 100;
            break;
            case 1:
            GVar("Player.Score") += 200;
            break;
            case 2:
            GVar("Player.Score") += 500;
            break;
            case 3:
            GVar("Player.Score") += 1000;
            break;
        }
    } else {
        scriptEng.arrayPosition[0] = Plr()->entityNo;
        scriptEng.arrayPosition[0] += 2;
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Invincibility")) {
            ResetObjectEntity(scriptEng.arrayPosition[1], GVar("Flower_TypeNo"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[1]].drawOrder = 4;
            CreateTempObject(TypeNameID("Smoke Puff"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            CreateTempObject(TypeNameID("Object Score"), objectEntityList[26].values[0], self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            PlaySfx(8, 0);
            if (pYVel() > 0) {
                pYVel() = -pYVel();
            }
            switch (objectEntityList[26].values[0]) {
                case 0:
                GVar("Player.Score") += 100;
                break;
                case 1:
                GVar("Player.Score") += 200;
                break;
                case 2:
                GVar("Player.Score") += 500;
                break;
                case 3:
                GVar("Player.Score") += 1000;
                break;
            }
        } else {
            if (self->state > 9) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pXPos() > self->XPos) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
    }
}

const Native::NativeFunctionDef O_R7_Hotaru::funcs[1] = {
    { "Hotaru_HotaruBreak", O_R7_Hotaru::Hotaru_HotaruBreak },
};

#endif // RETRO_USE_NATIVE_OBJECTS
