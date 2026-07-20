#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_Minomusi2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Minomusi2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_Minomusi2::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 32, 82, 134);
    AddSpriteFrame(-8, -8, 16, 32, 17, 184);
    AddSpriteFrame(-8, -8, 16, 32, 1, 184);
    AddSpriteFrame(-12, -8, 24, 32, 133, 166);
    AddSpriteFrame(-16, -8, 32, 32, 1, 151);
    AddSpriteFrame(-4, 16, 8, 0, 246, 91);
    AddSpriteFrame(-4, 16, 8, 8, 246, 91);
    AddSpriteFrame(-4, 16, 8, 16, 246, 91);
    AddSpriteFrame(-4, 16, 8, 24, 246, 91);
    AddSpriteFrame(-4, 16, 8, 32, 246, 91);
    AddSpriteFrame(-4, 16, 8, 40, 246, 91);
    AddSpriteFrame(-4, 16, 8, 48, 246, 91);
    AddSpriteFrame(-4, 16, 8, 56, 246, 91);
    AddSpriteFrame(-4, 16, 8, 64, 246, 91);
    AddSpriteFrame(-4, 16, 8, 72, 246, 91);
    AddSpriteFrame(-4, 16, 8, 72, 246, 91);
    AddSpriteFrame(-4, 16, 8, 72, 246, 91);
    AddSpriteFrame(-4, 16, 8, 72, 246, 91);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Minomusi")) {
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Minomusi2");
        }
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Minomusi2")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Mission_Minomusi2::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 0;
        self->values[0] = 0;
        self->values[2] = 0;
        self->YPos = self->values[1];
        self->priority = 0;
    }
    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->frame = 0;
            if (self->values[0] > 0) {
                self->values[0]--;
            }
            break;
            case 1:
            if (self->values[0] < 6) {
                self->YPos += 0x100000;
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 2:
            if (self->values[2] < 15) {
                self->values[2]++;
            } else {
                self->values[2] = 0;
                self->state++;
                self->frame = 3;
            }
            break;
            case 3:
            self->state++;
            self->frame = 4;
            PlaySfx(globalSFXCount + 8, 0);
            break;
            case 4:
            if (self->values[2] < 2) {
                self->values[2]++;
            } else {
                self->values[2] = 0;
                self->state++;
                self->frame = 3;
            }
            break;
            case 5:
            self->state++;
            self->frame = 0;
            break;
            case 6:
            self->state++;
            self->frame = 3;
            break;
            case 7:
            self->state++;
            self->frame = 4;
            break;
            case 8:
            if (self->values[2] < 15) {
                self->values[2]++;
            } else {
                self->values[2] = 0;
                self->state++;
                self->frame = 3;
            }
            break;
            case 9:
            self->frame = 0;
            if (self->values[0] < 1) {
                self->state = 2;
                self->values[0]++;
            } else {
                self->state++;
                self->values[0] = 0;
            }
            break;
            case 10:
            if (self->values[0] < 10) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 11:
            if (self->values[0] < 6) {
                self->YPos -= 0x100000;
                self->values[0]++;
            } else {
                self->values[0] = 60;
                self->state = 0;
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            self->frame = 1;
            if (self->values[0] > 0) {
                self->values[0]--;
            }
            break;
            case 1:
            self->frame = 1;
            if (self->values[0] < 6) {
                self->YPos += 0x100000;
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 2:
            if (self->values[2] < 5) {
                self->values[2]++;
            } else {
                self->values[2] = 0;
                self->state++;
                self->frame = 2;
            }
            break;
            case 3:
            if (self->values[2] < 5) {
                self->values[2]++;
            } else {
                self->values[2] = 0;
                self->frame = 1;
                self->values[0]++;
                if (self->values[0] == 2) {
                    self->values[0] = 0;
                    self->state++;
                } else {
                    self->state = 2;
                }
            }
            break;
            case 4:
            if (self->values[0] < 24) {
                self->YPos -= 0x40000;
                self->values[0]++;
            } else {
                self->values[0] = 60;
                self->state = 0;
            }
            break;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_Mission_Minomusi2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_ENEMY, -8, -6, 8, 22);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
    if (self->propertyValue == 0) {
        if (self->type == TypeNameID("Minomusi")) {
            if (self->frame > 2) {
                PlayerObjectCollision(C_TOUCH, -17, -4, 17, 20);
                if (CheckResult() == 1) {
                    CallScriptFunctionNamed("Player_Hit", scriptSub);
                }
            }
        }
    }
    if (self->state == 0) {
        if (self->values[0] == 0) {
            PlayerObjectCollision(C_TOUCH, -64, 0, 64, 128);
            if (CheckResult() == 1) {
                self->state = 1;
                self->priority = 1;
            }
        }
    }
}

void O_Mission_Minomusi2::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    scriptEng.tempValue[0] -= self->values[1];
    scriptEng.tempValue[0] >>= 19;
    scriptEng.tempValue[0] += 5;
    DrawSprite_FrameXY(scriptEng.tempValue[0], self->XPos, self->values[1]);
    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
