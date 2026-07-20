#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_TagaTaga.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TagaTaga.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_TagaTaga::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-16, -22, 32, 44, 223, 154);
    AddSpriteFrame(-16, -22, 32, 44, 223, 199);
    AddSpriteFrame(-16, -16, 32, 32, 35, 109);
    AddSpriteFrame(-16, -16, 32, 32, 68, 109);
    AddSpriteFrame(-16, -22, 32, 44, 1, 101);
    AddSpriteFrame(-16, -22, 32, 44, 1, 146);
    AddSpriteFrame(-16, -22, 32, 44, 223, 154);
    AddSpriteFrame(-16, -16, 32, 32, 35, 109);
    AddSpriteFrame(-16, -16, 32, 32, 35, 142);
    AddSpriteFrame(-16, -22, 32, 44, 1, 191);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("TagaTaga")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_TagaTaga::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->values[1] = -0x40000;
            self->values[0] = 1;
            self->state = 1;
            break;
            case 1:
            self->values[1] += 0x1000;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 24) {
                self->state = 2;
            }
            break;
            case 2:
            self->values[1] += 0x1000;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 48) {
                self->state = 3;
            }
            break;
            case 3:
            self->values[1] += 0x1000;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 56) {
                self->state = 4;
            }
            break;
            case 4:
            self->values[1] += 0x1000;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 64) {
                self->state = 5;
            }
            break;
            case 5:
            self->values[1] += 0x1000;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 96) {
                self->state = 6;
            }
            break;
            case 6:
            self->values[1] += 0x1000;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 128) {
                self->state = 7;
                PlaySfx(globalSFXCount + 3, 0);
            }
            break;
            case 7:
            self->values[0]++;
            if (self->values[0] > 204) {
                self->state = 0;
                self->values[0] = 0;
                self->YPos = self->values[2];
                PlaySfx(globalSFXCount + 3, 0);
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            self->values[1] = -0x30000;
            self->values[0] = 1;
            self->state = 1;
            break;
            case 1:
            self->values[1] += 0xEC4;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 40) {
                self->state = 2;
            }
            break;
            case 2:
            self->values[1] += 0xEC4;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 50) {
                self->state = 3;
            }
            break;
            case 3:
            self->values[1] += 0xEC4;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 60) {
                self->state = 4;
            }
            break;
            case 4:
            self->values[1] += 0xEC4;
            self->YPos += self->values[1];
            self->values[0]++;
            if (self->values[0] > 104) {
                self->state = 5;
                PlaySfx(globalSFXCount + 3, 0);
            }
            break;
            case 5:
            self->values[0]++;
            if (self->values[0] > 188) {
                self->state = 0;
                self->values[0] = 0;
                self->YPos = self->values[2];
                PlaySfx(globalSFXCount + 3, 0);
            }
            break;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R1_TagaTaga::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (self->state < 7) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
            }
        }
    } else {
        if (self->state < 5) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
            }
        }
    }
}

void O_R1_TagaTaga::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            case 1:
            DrawSprite_Frame(0);
            break;
            case 2:
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 15;
            if (scriptEng.tempValue[0] < 8) {
                DrawSprite_Frame(0);
            } else {
                DrawSprite_Frame(1);
            }
            break;
            case 3:
            DrawSprite_Frame(2);
            break;
            case 4:
            DrawSprite_Frame(3);
            break;
            case 5:
            DrawSprite_Frame(4);
            break;
            case 6:
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 15;
            if (scriptEng.tempValue[0] < 8) {
                DrawSprite_Frame(4);
            } else {
                DrawSprite_Frame(5);
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            case 1:
            DrawSprite_Frame(6);
            break;
            case 2:
            DrawSprite_Frame(7);
            break;
            case 3:
            DrawSprite_Frame(8);
            break;
            case 4:
            DrawSprite_Frame(9);
            break;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
