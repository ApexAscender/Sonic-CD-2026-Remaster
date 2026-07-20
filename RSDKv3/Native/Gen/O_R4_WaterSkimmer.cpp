#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_WaterSkimmer.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterSkimmer.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_WaterSkimmer::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-20, -12, 32, 24, 67, 231);
    AddSpriteFrame(-20, -12, 32, 24, 100, 231);
    AddSpriteFrame(-20, -12, 32, 24, 1, 231);
    AddSpriteFrame(-20, -12, 32, 24, 34, 231);
}

void O_R4_WaterSkimmer::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            if (self->values[1] > -0x18000) {
                self->values[1] -= 0x400;
                self->XPos += self->values[1];
            } else {
                self->state++;
            }
            self->frame++;
            self->frame %= 22;
            break;
            case 1:
            if (self->values[1] < 0) {
                self->values[1] += 0x118;
                self->XPos += self->values[1];
            } else {
                self->values[1] = 0;
                self->state++;
                self->values[0] = 60;
            }
            break;
            case 2:
            if (self->values[0] > 0) {
                self->values[0]--;
            } else {
                self->state++;
                self->direction = 1;
                self->values[0] = 60;
            }
            break;
            case 3:
            if (self->values[0] > 0) {
                self->values[0]--;
            } else {
                self->state++;
            }
            break;
            case 5:
            if (self->values[1] < 0x18000) {
                self->values[1] += 0x400;
                self->XPos += self->values[1];
            } else {
                self->state++;
            }
            self->frame++;
            self->frame %= 22;
            break;
            case 6:
            if (self->values[1] > 0) {
                self->values[1] -= 0x118;
                self->XPos += self->values[1];
            } else {
                self->values[1] = 0;
                self->state++;
                self->values[0] = 60;
            }
            break;
            case 7:
            if (self->values[0] > 0) {
                self->values[0]--;
            } else {
                self->state++;
                self->direction = 0;
                self->values[0] = 60;
            }
            break;
            case 8:
            if (self->values[0] > 0) {
                self->values[0]--;
            } else {
                self->state = 0;
            }
            break;
        }
        if (self->values[2] > 0) {
            self->values[2]--;
            if (self->values[2] == 0) {
                PlaySfx(globalSFXCount + 1, 0);
                CreateTempObject(TypeNameID("SkimmerBullet"), 0, self->XPos, self->YPos);
                if (self->direction == 0) {
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                } else {
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x20000;
                }
            }
        }
    } else {
        switch (self->state) {
            case 0:
            if (self->values[1] > -0x10000) {
                self->values[1] -= 0x400;
                self->XPos += self->values[1];
            } else {
                self->state++;
            }
            self->frame++;
            self->frame %= 22;
            break;
            case 1:
            if (self->values[1] < 0) {
                self->values[1] += 0x118;
                self->XPos += self->values[1];
            } else {
                self->values[1] = 0;
                self->state++;
                self->values[0] = 60;
            }
            break;
            case 2:
            if (self->values[0] > 0) {
                self->values[0]--;
            } else {
                self->state++;
                self->direction = 1;
                self->values[0] = 60;
            }
            break;
            case 4:
            if (self->values[0] > 0) {
                self->values[0]--;
            } else {
                self->state++;
            }
            break;
            case 5:
            if (self->values[1] < 0x10000) {
                self->values[1] += 0x400;
                self->XPos += self->values[1];
            } else {
                self->state++;
            }
            self->frame++;
            self->frame %= 22;
            break;
            case 6:
            if (self->values[1] > 0) {
                self->values[1] -= 0x118;
                self->XPos += self->values[1];
            } else {
                self->values[1] = 0;
                self->state++;
                self->values[0] = 60;
            }
            break;
            case 7:
            if (self->values[0] > 0) {
                self->values[0]--;
            } else {
                self->state++;
                self->direction = 0;
                self->values[0] = 60;
            }
            break;
            case 8:
            if (self->values[0] > 0) {
                self->values[0]--;
            } else {
                self->state = 0;
            }
            break;
        }
    }
    self->YPos = waterLevel;
    self->YPos -= 10;
    self->YPos <<= 16;
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R4_WaterSkimmer::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -12, -8, 12, 8);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
    if (self->values[2] == 0) {
        if (self->direction == 0) {
            PlayerObjectCollision(C_TOUCH, -96, -16, 0, 16);
            if (CheckResult() == 1) {
                self->values[2] = 120;
            }
        } else {
            PlayerObjectCollision(C_TOUCH, 0, -16, 96, 16);
            if (CheckResult() == 1) {
                self->values[2] = 120;
            }
        }
    }
}

void O_R4_WaterSkimmer::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 11;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    } else {
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 11;
        scriptEng.tempValue[0] += 2;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
