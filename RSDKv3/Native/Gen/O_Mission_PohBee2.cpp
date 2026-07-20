#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_PohBee2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PohBee2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_PohBee2::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-24, -20, 48, 32, 148, 75);
    AddSpriteFrame(-24, -16, 48, 28, 148, 108);
    AddSpriteFrame(-24, -20, 48, 32, 99, 133);
    AddSpriteFrame(-24, -16, 48, 28, 148, 137);
    AddSpriteFrame(-24, -20, 48, 40, 197, 91);
    AddSpriteFrame(-24, -16, 48, 36, 197, 132);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Poh Bee")) {
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("PohBee2");
        }
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("PohBee2")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Mission_PohBee2::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 6;
        self->values[0] = 0;
        self->direction = 0;
        self->XPos = self->values[1];
        self->values[2] = 0;
        self->values[3] = 0;
        self->values[4] = 0;
    }
    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->priority = 1;
            if (self->values[3] > 0) {
                self->values[3]--;
            }
            if (self->values[0] < 256) {
                self->values[0]++;
                self->XPos -= 0x20000;
            } else {
                self->state = 1;
                self->values[0] = 0;
            }
            break;
            case 1:
            self->priority = 1;
            if (self->values[3] > 0) {
                self->values[3]--;
            }
            if (self->values[0] < 60) {
                if (self->values[0] == 30) {
                    self->direction = 1;
                }
                self->values[0]++;
            } else {
                self->state = 2;
            }
            break;
            case 2:
            self->priority = 1;
            if (self->values[3] > 0) {
                self->values[3]--;
            }
            if (self->values[0] < 256) {
                self->values[0]++;
                self->XPos += 0x20000;
            } else {
                self->state = 3;
                self->values[0] = 0;
            }
            break;
            case 3:
            self->priority = 1;
            if (self->values[3] > 0) {
                self->values[3]--;
            }
            if (self->values[0] < 60) {
                if (self->values[0] == 30) {
                    self->direction = 0;
                }
                self->values[0]++;
            } else {
                self->state = 0;
            }
            break;
            case 4:
            self->priority = 1;
            if (self->values[3] < 46) {
                self->values[3]++;
                if (self->values[3] == 15) {
                    self->values[4] = 4;
                }
                if (self->values[3] == 32) {
                    CreateTempObject(TypeNameID("Poh Bee Bullet"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0xF0000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x1B0000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x40000;
                    PlaySfx(globalSFXCount + 7, 0);
                }
            } else {
                self->state = 0;
                self->values[4] = 0;
                self->values[3] = 30;
            }
            break;
            case 5:
            self->priority = 1;
            if (self->values[3] < 46) {
                self->values[3]++;
                if (self->values[3] == 15) {
                    self->values[4] = 4;
                }
                if (self->values[3] == 32) {
                    CreateTempObject(TypeNameID("Poh Bee Bullet"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
                    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0xF0000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x1B0000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x40000;
                    PlaySfx(globalSFXCount + 7, 0);
                }
            } else {
                self->state = 2;
                self->values[4] = 0;
                self->values[3] = 30;
            }
            break;
            case 6:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            self->priority = 1;
            if (self->values[0] < 256) {
                self->values[0]++;
                self->XPos -= 0x10000;
            } else {
                self->state = 1;
                self->values[0] = 0;
            }
            break;
            case 1:
            self->priority = 1;
            if (self->values[0] < 30) {
                if (self->values[0] == 15) {
                    self->direction = 1;
                }
                self->values[0]++;
            } else {
                self->state = 2;
            }
            break;
            case 2:
            self->priority = 1;
            if (self->values[0] < 512) {
                self->values[0]++;
                self->XPos += 0x10000;
            } else {
                self->state = 3;
                self->values[0] = 0;
            }
            break;
            case 3:
            self->priority = 1;
            if (self->values[0] < 30) {
                if (self->values[0] == 15) {
                    self->direction = 0;
                }
                self->values[0]++;
            } else {
                self->state = 0;
            }
            break;
            case 6:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
            }
            break;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_Mission_PohBee2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (self->state < 4) {
            if (self->values[3] == 0) {
                PlayerObjectCollision(C_TOUCH, -96, -64, 96, 64);
                if (CheckResult() == 1) {
                    if (self->XPos > pXPos()) {
                        self->direction = 0;
                        self->state = 4;
                    } else {
                        self->direction = 1;
                        self->state = 5;
                    }
                }
            }
        }
    }
    if (self->state < 6) {
        PlayerObjectCollision(C_ENEMY, -20, -16, 20, 14);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
    }
}

void O_Mission_PohBee2::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 6) {
        if (self->propertyValue == 0) {
            self->values[2]++;
            self->values[2] &= 3;
            self->frame = self->values[2];
            self->frame >>= 1;
            self->frame += self->values[4];
        } else {
            self->values[2]++;
            self->values[2] &= 3;
            self->frame = self->values[2];
            self->frame >>= 1;
            self->frame += 2;
        }
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
