#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_Yago.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Yago.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_Yago::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-24, -12, 48, 24, 67, 181);
    AddSpriteFrame(-24, -12, 48, 24, 67, 206);
    AddSpriteFrame(-24, -12, 48, 24, 18, 181);
    AddSpriteFrame(-24, -12, 48, 24, 18, 206);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Yago")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_Yago::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->YPos += 0x10000;
        ObjectTileCollision_Script(0, 0, 17, 0);
        if (CheckResult() == 1) {
            self->direction = 0;
            self->values[3] = 0x500000;
            self->values[1] = -0x4000;
            self->priority = 1;
            self->state++;
        }
        break;
        case 1:
        self->values[3] += self->values[1];
        if (self->values[3] >= 0) {
            self->XPos += self->values[1];
            self->YPos += 0x8000;
            ObjectTileCollision_Script(0, 0, 17, 0);
            if (self->direction == 0) {
                ObjectTileCollision_Script(3, -20, 0, 0);
            } else {
                ObjectTileCollision_Script(1, 20, 0, 0);
            }
            if (CheckResult() == 1) {
                self->state++;
                self->values[0] = 30;
            } else {
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] -= pXPos();
                if (scriptEng.tempValue[0] < 0) {
                    scriptEng.tempValue[0] = -scriptEng.tempValue[0];
                }
                if (scriptEng.tempValue[0] < 0x500000) {
                    self->state = 4;
                    self->values[0] = 6;
                }
            }
        } else {
            self->state++;
            self->values[0] = 30;
        }
        break;
        case 2:
        if (self->values[0] > 0) {
            self->values[0]--;
        } else {
            self->values[0] = 30;
            self->values[3] = 0x500000;
            self->direction++;
            self->direction &= 1;
            self->values[1] = -self->values[1];
            self->state++;
        }
        break;
        case 3:
        if (self->values[0] > 0) {
            self->values[0]--;
        } else {
            self->state = 1;
        }
        break;
        case 4:
        if (self->values[0] > 0) {
            self->values[0]--;
        } else {
            self->values[0] = 30;
            self->state++;
        }
        break;
        case 5:
        self->YPos += 0x2000;
        if (self->values[0] > 0) {
            self->values[0]--;
        } else {
            if (self->propertyValue == 0) {
                if (self->direction == 0) {
                    self->values[3] = -0x48000;
                } else {
                    self->values[3] = 0x48000;
                }
                self->values[2] = -0x18000;
            } else {
                if (self->direction == 0) {
                    self->values[3] = -0x10000;
                } else {
                    self->values[3] = 0x10000;
                }
            }
            self->values[2] = -0x18000;
            if (self->propertyValue == 0) {
                self->state++;
            } else {
                self->state = 7;
            }
        }
        break;
        case 6:
        self->XPos += self->values[3];
        if (self->direction == 0) {
            ObjectTileCollision_Script(2, -20, 0, 0);
        } else {
            ObjectTileCollision_Script(1, 20, 0, 0);
        }
        if (CheckResult() == 1) {
            self->values[0] = 30;
            self->state = 2;
        } else {
            self->YPos += self->values[2];
            if (self->values[2] < 0) {
                self->values[2] += 0x2000;
            }
        }
        break;
        case 7:
        self->XPos += self->values[3];
        if (self->direction == 0) {
            ObjectTileCollision_Script(2, -20, 0, 0);
        } else {
            ObjectTileCollision_Script(1, 20, 0, 0);
        }
        if (CheckResult() == 1) {
            self->values[0] = 30;
            self->state = 2;
        } else {
            self->YPos += self->values[2];
            self->values[2] += 0x1000;
            if (self->values[2] > 0) {
                ObjectTileCollision_Script(0, 0, 17, 0);
                if (CheckResult() == 1) {
                    self->values[3] = 0x500000;
                    self->state = 1;
                }
            }
        }
        break;
    }
    self->animationTimer++;
    self->animationTimer %= 20;
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        self->XPos = self->values[4];
        self->YPos = self->values[5];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        } else {
            self->XPos = scriptEng.tempValue[0];
            self->YPos = scriptEng.tempValue[1];
        }
    }
}

void O_R4_Yago::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -20, -8, 20, 8);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
}

void O_R4_Yago::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] /= 10;
    if (self->propertyValue == 1) {
        scriptEng.tempValue[0] += 2;
    }
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
