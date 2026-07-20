#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_Semi.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Semi.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_Semi::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 1, 224);
    AddSpriteFrame(-16, -16, 32, 32, 158, 166);
    AddSpriteFrame(-16, -16, 32, 32, 34, 224);
    AddSpriteFrame(-20, -16, 40, 32, 67, 224);
    AddSpriteFrame(-16, -16, 32, 32, 34, 224);
    AddSpriteFrame(-20, -16, 40, 32, 67, 224);
    AddSpriteFrame(-16, -16, 32, 32, 108, 224);
    AddSpriteFrame(-20, -16, 40, 32, 141, 224);
    AddSpriteFrame(-16, -16, 32, 32, 108, 224);
    AddSpriteFrame(-20, -16, 40, 32, 141, 224);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Semi")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 5;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_Semi::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 3;
        self->values[0] = 0;
        self->XPos = self->values[3];
        self->YPos = self->values[4];
    }
    switch (self->state) {
        case 1:
        self->priority = 1;
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        if (self->values[0] < 96) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        self->XPos += self->values[1];
        if (self->propertyValue == 0) {
            if (self->values[0] == 0) {
                self->values[0] = 60;
                CreateTempObject(TypeNameID("Semi Bomb"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].YPos += 0xC0000;
            } else {
                self->values[0]--;
            }
        }
        break;
        case 3:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        }
        break;
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R6_Semi::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_TOUCH, -96, -128, 96, 128);
        if (CheckResult() == 1) {
            self->state = 1;
            if (self->XPos > pXPos()) {
                if (self->propertyValue == 0) {
                    self->values[1] = 0x10000;
                    self->values[2] = -0x8000;
                } else {
                    self->values[1] = 0xC000;
                    self->values[2] = 0x6000;
                }
            } else {
                if (self->propertyValue == 0) {
                    self->values[1] = -0x10000;
                    self->values[2] = -0x8000;
                } else {
                    self->values[1] = -0xC000;
                    self->values[2] = 0x6000;
                }
            }
        }
        break;
        case 1:
        case 2:
        PlayerObjectCollision(C_TOUCH, -14, -12, 14, 12);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
        break;
    }
}

void O_R6_Semi::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        DrawSprite_Frame(self->propertyValue);
        break;
        case 1:
        case 2:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 2;
        if (self->propertyValue == 0) {
            scriptEng.tempValue[0] += 2;
        } else {
            scriptEng.tempValue[0] += 6;
        }
        if (self->frame > 7) {
            self->direction = 1;
        } else {
            self->direction = 0;
        }
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        self->frame++;
        self->frame &= 15;
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
