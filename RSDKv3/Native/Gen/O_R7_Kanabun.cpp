#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_Kanabun.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Kanabun.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_Kanabun::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 1, 100);
    AddSpriteFrame(-16, -16, 32, 32, 1, 133);
    AddSpriteFrame(-12, -12, 24, 24, 34, 71);
    AddSpriteFrame(-12, -12, 27, 27, 62, 43);
    AddSpriteFrame(-12, -12, 24, 24, 59, 71);
    AddSpriteFrame(-12, -12, 24, 24, 84, 71);
    AddSpriteFrame(-16, -16, 32, 32, 1, 34);
    AddSpriteFrame(-16, -16, 32, 32, 1, 67);
    AddSpriteFrame(-12, -12, 24, 24, 34, 18);
    AddSpriteFrame(-12, -12, 27, 27, 34, 43);
    AddSpriteFrame(-12, -12, 24, 24, 59, 18);
    AddSpriteFrame(-12, -12, 24, 24, 84, 18);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Kanabun")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = 256;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 2) {
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 3;
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_Kanabun::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 2;
        self->values[0] = 0;
        self->values[1] = 256;
        self->direction = 0;
        self->XPos = self->values[2];
        self->YPos = self->values[3];
    }
    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->priority = 1;
            self->XPos -= 0x4000;
            self->values[0]++;
            if (self->values[0] == 256) {
                self->state = 1;
                self->direction = 1;
            }
            break;
            case 1:
            self->XPos += 0x4000;
            self->values[0]--;
            if (self->values[0] == 0) {
                self->state = 0;
                self->direction = 0;
            }
            break;
            case 2:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
            }
            break;
        }
        self->values[1] += 4;
        self->values[1] &= 511;
        self->frame = self->animationTimer;
        self->frame >>= 1;
        self->animationTimer++;
        self->animationTimer &= 3;
    } else {
        switch (self->state) {
            case 0:
            self->priority = 1;
            self->XPos -= 0x4000;
            self->values[0]++;
            if (self->values[0] == 256) {
                self->state = 1;
                self->direction = 1;
            }
            break;
            case 1:
            self->XPos += 0x4000;
            self->values[0]--;
            if (self->values[0] == 0) {
                self->state = 0;
                self->direction = 0;
            }
            break;
            case 2:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
            }
            break;
        }
        self->values[1] += 2;
        self->values[1] &= 511;
        self->frame = self->animationTimer;
        self->frame >>= 2;
        self->frame += 6;
        self->animationTimer++;
        self->animationTimer &= 7;
    }
    self->YPos = Sin512(self->values[1]);
    if (self->values[1] < 128) {
        self->drawOrder = 5;
        self->values[4] = 0;
        if (self->YPos < -384) {
            self->values[4] = 2;
        }
        if (self->YPos > 384) {
            self->values[4] = 2;
        }
    } else {
        if (self->values[1] > 384) {
            self->drawOrder = 5;
            self->values[4] = 0;
            if (self->YPos < -384) {
                self->values[4] = 2;
            }
            if (self->YPos > 384) {
                self->values[4] = 2;
            }
        } else {
            self->drawOrder = self->values[5];
            self->values[4] = 4;
            if (self->YPos < -384) {
                self->values[4] = 2;
            }
            if (self->YPos > 384) {
                self->values[4] = 2;
            }
        }
    }
    self->frame += self->values[4];
    self->YPos <<= 13;
    self->YPos += self->values[3];
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R7_Kanabun::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 2) {
        if (self->values[4] == 0) {
            PlayerObjectCollision(C_TOUCH, -14, -14, 14, 14);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
            }
        } else {
            if (pAnimation() == GVar("ANI_JUMPING")) {
                PlayerObjectCollision(C_TOUCH, -14, -14, 14, 14);
                if (CheckResult() == 1) {
                    CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
                }
            }
        }
    }
}

void O_R7_Kanabun::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 2) {
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
