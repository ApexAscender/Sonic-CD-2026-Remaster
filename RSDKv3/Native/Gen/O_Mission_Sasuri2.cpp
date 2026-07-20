#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_Sasuri2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Sasuri2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_Sasuri2::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-24, -16, 48, 32, 174, 141);
    AddSpriteFrame(-24, -16, 48, 32, 174, 174);
    AddSpriteFrame(-32, -4, 32, 16, 100, 110);
    AddSpriteFrame(-21, -3, 32, 16, 100, 110);
    AddSpriteFrame(-28, -4, 32, 16, 100, 110);
    AddSpriteFrame(-25, -3, 32, 16, 100, 110);
    AddSpriteFrame(-32, -4, 32, 16, 100, 127);
    AddSpriteFrame(-21, -3, 32, 16, 100, 127);
    AddSpriteFrame(-28, -4, 32, 16, 100, 127);
    AddSpriteFrame(-25, -3, 32, 16, 100, 127);
    AddSpriteFrame(-9, -24, 24, 16, 100, 93);
    AddSpriteFrame(-5, -29, 24, 16, 100, 93);
    AddSpriteFrame(-1, -24, 16, 16, 133, 110);
    AddSpriteFrame(3, -29, 16, 16, 133, 110);
}

void O_Mission_Sasuri2::ObjectMain()
{
    Entity *self = Self();

    self->frame++;
    self->frame %= 60;
    switch (self->state) {
        case 0:
        self->YPos = objectEntityList[objectLoop + 1].YPos;
        objectEntityList[objectLoop].YPos = ((objectEntityList[objectLoop].YPos >> 16) - (28)) << 16;
        self->values[3] = 32;
        self->values[3] <<= 16;
        self->values[2] = 0;
        self->values[2] -= self->values[3];
        self->values[3] += objectEntityList[objectLoop + 1].XPos;
        self->values[2] += objectEntityList[objectLoop + 1].XPos;
        self->state = 1;
        break;
        case 1:
        self->XPos -= 0x10000;
        self->values[0]--;
        if (self->values[0] <= -80) {
            self->state = 2;
            self->direction = 1;
        }
        if (self->XPos < self->values[2]) {
            self->state = 2;
            self->values[0] = 0;
            self->direction = 1;
        }
        break;
        case 2:
        self->XPos += 0x10000;
        self->values[0]++;
        if (self->values[0] >= 80) {
            self->state = 1;
            self->direction = 0;
        }
        if (self->XPos > self->values[3]) {
            self->state = 1;
            self->values[0] = 0;
            self->direction = 0;
        }
        break;
        case 3:
        if (self->values[1] < 30) {
            self->values[1]++;
        } else {
            self->state = 4;
            self->values[1] = 0;
        }
        break;
        case 4:
        if (self->values[1] < 40) {
            if (self->values[1] == 10) {
                PlaySfx(globalSFXCount + 2, 0);
                CreateTempObject(TypeNameID("Sasuri Bullet"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x180000;
                if (self->direction == 0) {
                    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x70000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x30000;
                } else {
                    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x70000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x30000;
                }
                self->drawOrder = 4;
            }
            self->values[1]++;
        } else {
            self->state = 5;
            self->values[1] = 0;
            self->drawOrder = 3;
        }
        break;
        case 5:
        if (self->values[1] < 30) {
            self->values[1]++;
        } else {
            self->state = 4;
            if (self->direction == 0) {
                self->state = 1;
            } else {
                self->state = 2;
            }
        }
        break;
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_Mission_Sasuri2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_ENEMY, -22, -14, 22, 14);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
    switch (self->state) {
        case 1:
        case 2:
        if (self->values[1] == 0) {
            PlayerObjectCollision(C_TOUCH, -64, -24, 64, 24);
            if (CheckResult() == 1) {
                self->state = 3;
                if (pXPos() < self->XPos) {
                    self->direction = 0;
                } else {
                    self->direction = 1;
                }
            }
        } else {
            self->values[1] = 0;
        }
        break;
    }
}

void O_Mission_Sasuri2::ObjectDraw()
{
    Entity *self = Self();

    if (self->frame < 30) {
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
    } else {
        DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(5, FX_FLIP, self->XPos, self->YPos);
    }
    switch (self->state) {
        case 1:
        case 2:
        case 3:
        case 5:
        DrawSpriteFX_Script(10, FX_FLIP, self->XPos, self->YPos);
        break;
        case 4:
        DrawSpriteFX_Script(11, FX_FLIP, self->XPos, self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
