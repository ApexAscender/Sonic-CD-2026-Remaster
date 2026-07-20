#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Mosqui.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Mosqui.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Mosqui::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-16, -11, 32, 24, 51, 1);
    AddSpriteFrame(-16, -3, 32, 16, 51, 26);
    AddSpriteFrame(-16, -14, 32, 32, 51, 43);
    AddSpriteFrame(-6, -13, 24, 32, 117, 43);
    AddSpriteFrame(-10, -14, 24, 32, 142, 43);
    AddSpriteFrame(-16, -11, 32, 24, 84, 1);
    AddSpriteFrame(-16, -3, 32, 16, 84, 26);
    AddSpriteFrame(-16, -14, 32, 32, 84, 43);
    AddSpriteFrame(-6, -13, 24, 32, 51, 76);
    AddSpriteFrame(-10, -14, 24, 32, 76, 76);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Mosqui")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_Mosqui::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->priority = 1;
            self->frame++;
            self->frame &= 3;
            self->XPos -= 0x10000;
            self->values[0]--;
            if (self->values[0] == -128) {
                self->state = 1;
                self->direction = 1;
            }
            if (pYPos() > self->YPos) {
                scriptEng.tempValue[0] = pYPos();
                scriptEng.tempValue[0] -= self->YPos;
                if (scriptEng.tempValue[0] < 0x800000) {
                    if (pXPos() > self->XPos) {
                        scriptEng.tempValue[0] = pXPos();
                        scriptEng.tempValue[0] -= self->XPos;
                    } else {
                        scriptEng.tempValue[0] = self->XPos;
                        scriptEng.tempValue[0] -= pXPos();
                    }
                    if (scriptEng.tempValue[0] < 0x300000) {
                        self->values[0] = 0;
                        self->frame = 2;
                        self->state = 2;
                    }
                }
            }
            break;
            case 1:
            self->frame++;
            self->frame &= 3;
            self->XPos += 0x10000;
            self->values[0]++;
            if (self->values[0] == 128) {
                self->state = 0;
                self->direction = 0;
            }
            if (pYPos() > self->YPos) {
                scriptEng.tempValue[0] = pYPos();
                scriptEng.tempValue[0] -= self->YPos;
                if (scriptEng.tempValue[0] < 0x800000) {
                    if (pXPos() > self->XPos) {
                        scriptEng.tempValue[0] = pXPos();
                        scriptEng.tempValue[0] -= self->XPos;
                    } else {
                        scriptEng.tempValue[0] = self->XPos;
                        scriptEng.tempValue[0] -= pXPos();
                    }
                    if (scriptEng.tempValue[0] < 0x300000) {
                        self->values[0] = 0;
                        self->frame = 2;
                        self->state = 2;
                    }
                }
            }
            break;
            case 2:
            self->values[0]++;
            if (self->values[0] == 8) {
                self->values[0] = 0;
                self->frame++;
                if (self->frame == 5) {
                    self->frame = 4;
                    self->state = 3;
                }
            }
            break;
            case 3:
            self->YPos += 0x60000;
            ObjectTileCollision_Script(0, 0, 14, 0);
            if (CheckResult() == 1) {
                self->state = 4;
                PlaySfx(globalSFXCount + 2, 0);
            }
            break;
            case 4:
            break;
            case 5:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->direction = 0;
                self->priority = 0;
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            self->priority = 1;
            self->frame++;
            self->frame %= 10;
            self->XPos -= 0x8000;
            self->values[0]--;
            if (self->values[0] == -256) {
                self->state = 1;
                self->direction = 1;
            }
            if (pYPos() > self->YPos) {
                scriptEng.tempValue[0] = pYPos();
                scriptEng.tempValue[0] -= self->YPos;
                if (scriptEng.tempValue[0] < 0x400000) {
                    if (pXPos() > self->XPos) {
                        scriptEng.tempValue[0] = pXPos();
                        scriptEng.tempValue[0] -= self->XPos;
                    } else {
                        scriptEng.tempValue[0] = self->XPos;
                        scriptEng.tempValue[0] -= pXPos();
                    }
                    if (scriptEng.tempValue[0] < 0x300000) {
                        self->values[0] = 0;
                        self->frame = 7;
                        self->state = 2;
                    }
                }
            }
            break;
            case 1:
            self->frame++;
            self->frame %= 10;
            self->XPos += 0x8000;
            self->values[0]++;
            if (self->values[0] == 256) {
                self->state = 0;
                self->direction = 0;
            }
            if (pYPos() > self->YPos) {
                scriptEng.tempValue[0] = pYPos();
                scriptEng.tempValue[0] -= self->YPos;
                if (scriptEng.tempValue[0] < 0x400000) {
                    if (pXPos() > self->XPos) {
                        scriptEng.tempValue[0] = pXPos();
                        scriptEng.tempValue[0] -= self->XPos;
                    } else {
                        scriptEng.tempValue[0] = self->XPos;
                        scriptEng.tempValue[0] -= pXPos();
                    }
                    if (scriptEng.tempValue[0] < 0x300000) {
                        self->values[0] = 0;
                        self->frame = 7;
                        self->state = 2;
                    }
                }
            }
            break;
            case 2:
            self->values[0]++;
            if (self->values[0] == 16) {
                self->values[0] = 0;
                self->frame++;
                if (self->frame == 10) {
                    self->frame = 9;
                    self->state = 3;
                }
            }
            break;
            case 3:
            self->YPos += 0x60000;
            ObjectTileCollision_Script(0, 0, 14, 0);
            if (CheckResult() == 1) {
                self->state = 4;
            }
            break;
            case 4:
            break;
            case 5:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
            }
            break;
        }
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        self->XPos = self->values[1];
        self->YPos = self->values[2];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->XPos = self->values[1];
            self->YPos = self->values[2];
            self->direction = 0;
            self->values[0] = 0;
            self->frame = 0;
            self->priority = 0;
            self->state = 0;
        } else {
            self->XPos = scriptEng.tempValue[0];
            self->YPos = scriptEng.tempValue[1];
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R1_Mosqui::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 5) {
        PlayerObjectCollision(C_TOUCH, -15, -10, 15, 10);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
    }
}

void O_R1_Mosqui::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 5) {
        if (self->propertyValue == 0) {
            if (self->state < 2) {
                scriptEng.tempValue[0] = self->frame;
                scriptEng.tempValue[0] >>= 1;
                DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            } else {
                DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
            }
        } else {
            if (self->state < 2) {
                scriptEng.tempValue[0] = self->frame;
                scriptEng.tempValue[0] /= 5;
                scriptEng.tempValue[0] += 5;
                DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            } else {
                DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
