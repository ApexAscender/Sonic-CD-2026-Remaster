#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_Moth.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Moth.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_Moth::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-12, -16, 24, 16, 1, 216);
    AddSpriteFrame(-12, -16, 24, 24, 26, 216);
    AddSpriteFrame(-12, -20, 24, 32, 231, 170);
    AddSpriteFrame(-12, -12, 32, 24, 34, 191);
    AddSpriteFrame(-12, -8, 32, 16, 165, 183);
    AddSpriteFrame(-12, -8, 32, 16, 166, 233);
    AddSpriteFrame(-12, -8, 32, 16, 165, 183);
    AddSpriteFrame(-12, -12, 32, 24, 1, 157);
    AddSpriteFrame(-12, -8, 32, 16, 1, 182);
    AddSpriteFrame(-12, -8, 32, 16, 1, 199);
    AddSpriteFrame(-12, -8, 32, 16, 1, 182);
}

void O_R3_Moth::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_TOUCH, -96, -256, 96, 256);
        if (CheckResult() == 1) {
            self->drawOrder = 5;
            self->state = 2;
            self->values[3] = 0;
            self->frame = 0;
            self->priority = 1;
            self->values[4] = self->XPos;
            self->values[5] = self->YPos;
        }
        break;
        case 1:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        }
        break;
        case 2:
        if (self->values[0] < 110) {
            self->values[0]++;
            if (self->values[0] == 30) {
                self->frame++;
            }
            if (self->values[0] == 60) {
                self->frame++;
            }
        } else {
            if (self->XPos > pXPos()) {
                self->values[1] = -0x8000;
                self->direction = 0;
            } else {
                self->values[1] = 0x8000;
                self->direction = 1;
            }
            self->state = 3;
            self->values[0] = 0;
            if (self->propertyValue > 0) {
                self->values[1] >>= 1;
            }
            self->values[2] = 0x8000;
        }
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 1;
            self->values[0] = 0;
            self->XPos = self->values[4];
            self->YPos = self->values[5];
        }
        break;
        case 3:
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        if (self->values[0] < 65) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = -self->values[2];
            if (self->propertyValue == 0) {
                CreateTempObject(TypeNameID("Moth Sparkle"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
            }
        }
        self->values[3]++;
        self->values[3] %= 20;
        self->frame = self->values[3];
        self->frame /= 5;
        if (self->propertyValue == 0) {
            self->frame += 3;
        } else {
            self->frame += 7;
        }
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 1;
            self->values[0] = 0;
            self->XPos = self->values[4];
            self->YPos = self->values[5];
        }
        break;
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R3_Moth::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state > 2) {
        PlayerObjectCollision(C_TOUCH, -16, -8, 16, 8);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
    }
}

void O_R3_Moth::ObjectDraw()
{
    Entity *self = Self();

    if (self->state > 1) {
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
