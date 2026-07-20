#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_MenuHeading.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MenuHeading.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_MenuHeading::ObjectStartup()
{
    LoadSpriteSheet("Menu/MenuGfx1_EN.gif");
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Menu Heading")) {
            objectEntityList[scriptEng.arrayPosition[0]].frame = 5;
            objectEntityList[scriptEng.arrayPosition[0]].alpha = 255;
            objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 5;
            objectEntityList[scriptEng.arrayPosition[0]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = -256;
            objectEntityList[scriptEng.arrayPosition[0]].state = 2;
            LoadSpriteSheet("Menu/MenuGfx1_EN.gif");
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectScriptList[objectEntityList[scriptEng.arrayPosition[0]].type].spriteSheetID;
            switch (Engine.language) {
                case 0:
                LoadSpriteSheet("Menu/MenuGfx2_EN.gif");
                break;
                case 1:
                LoadSpriteSheet("Menu/MenuGfx2_FR.gif");
                break;
                case 2:
                LoadSpriteSheet("Menu/MenuGfx2_IT.gif");
                break;
                case 3:
                LoadSpriteSheet("Menu/MenuGfx2_DE.gif");
                break;
                case 4:
                LoadSpriteSheet("Menu/MenuGfx2_ES.gif");
                break;
                case 5:
                LoadSpriteSheet("Menu/MenuGfx2_JP.gif");
                break;
            }
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = objectScriptList[objectEntityList[scriptEng.arrayPosition[0]].type].spriteSheetID;
        }
        scriptEng.arrayPosition[0]++;
    }
    AddSpriteFrame(12, 0, 216, 9, 1, 225);
    AddSpriteFrame(8, 0, 8, 240, 503, 1);
    AddSpriteFrame(8, 240, 8, 240, 503, 1);
    CheckResult() = 1;
    if (CheckResult() == 1) {
        AddSpriteFrame(-11, -36, 22, 72, 418, 366);
        AddSpriteFrame(-11, -36, 22, 72, 441, 366);
    } else {
        switch (Engine.language) {
            case 0:
            case 5:
            AddSpriteFrame(-11, -36, 22, 72, 418, 1);
            AddSpriteFrame(-11, -36, 22, 72, 441, 1);
            break;
            case 1:
            AddSpriteFrame(-11, -36, 22, 72, 418, 74);
            AddSpriteFrame(-11, -36, 22, 72, 441, 74);
            break;
            case 2:
            AddSpriteFrame(-11, -36, 22, 72, 418, 147);
            AddSpriteFrame(-11, -36, 22, 72, 441, 147);
            break;
            case 3:
            AddSpriteFrame(-11, -36, 22, 72, 418, 220);
            AddSpriteFrame(-11, -36, 22, 72, 441, 220);
            break;
            case 4:
            AddSpriteFrame(-11, -36, 22, 72, 418, 293);
            AddSpriteFrame(-11, -36, 22, 72, 441, 293);
            break;
        }
    }
    switch (Engine.language) {
        case 0:
        case 5:
        AddSpriteFrame(32, 0, 160, 30, 1, 615);
        AddSpriteFrame(32, 0, 160, 30, 1, 646);
        AddSpriteFrame(16, 0, 160, 30, 1, 677);
        AddSpriteFrame(32, 0, 160, 30, 1, 708);
        AddSpriteFrame(24, 0, 160, 30, 1, 739);
        AddSpriteFrame(24, 0, 160, 30, 1, 770);
        break;
        case 1:
        AddSpriteFrame(12, 0, 160, 30, 1, 615);
        AddSpriteFrame(20, 0, 160, 30, 1, 646);
        AddSpriteFrame(14, 0, 160, 30, 1, 677);
        AddSpriteFrame(32, 0, 160, 30, 1, 708);
        AddSpriteFrame(10, 0, 160, 30, 1, 739);
        AddSpriteFrame(24, 0, 160, 30, 1, 770);
        break;
        case 2:
        AddSpriteFrame(8, 0, 160, 30, 1, 615);
        AddSpriteFrame(32, 0, 160, 30, 1, 646);
        AddSpriteFrame(14, 0, 160, 30, 1, 677);
        AddSpriteFrame(32, 0, 160, 30, 1, 708);
        AddSpriteFrame(8, 0, 160, 30, 1, 739);
        AddSpriteFrame(24, 0, 160, 30, 1, 770);
        break;
        case 3:
        AddSpriteFrame(24, 0, 160, 30, 1, 615);
        AddSpriteFrame(16, 0, 160, 30, 1, 646);
        AddSpriteFrame(6, 0, 160, 30, 1, 677);
        AddSpriteFrame(32, 0, 160, 30, 1, 708);
        AddSpriteFrame(24, 0, 160, 30, 1, 739);
        AddSpriteFrame(24, 0, 160, 30, 1, 770);
        break;
        case 4:
        AddSpriteFrame(16, 0, 160, 30, 1, 615);
        AddSpriteFrame(16, 0, 160, 30, 1, 646);
        AddSpriteFrame(8, 0, 160, 30, 1, 677);
        AddSpriteFrame(32, 0, 160, 30, 1, 708);
        AddSpriteFrame(6, 0, 160, 30, 1, 739);
        AddSpriteFrame(24, 0, 160, 30, 1, 770);
        break;
    }
}

void O_Menu_MenuHeading::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] < 16) {
            self->values[0]++;
            self->values[2] -= 16;
        } else {
            self->frame = self->propertyValue;
            self->values[0] = 0;
            self->state++;
        }
        if (self->alpha == 255) {
            self->alpha = 240;
        } else {
            if (self->alpha > 0) {
                self->alpha -= 16;
            }
        }
        break;
        case 2:
        if (self->values[0] < 16) {
            self->values[0]++;
            self->values[2] += 16;
        } else {
            self->values[0] = 0;
            self->state = 0;
        }
        if (self->propertyValue == 5) {
            if (self->alpha == 240) {
                self->alpha = 255;
            } else {
                if (self->alpha < 255) {
                    self->alpha += 16;
                }
            }
        }
        break;
    }
}

void O_Menu_MenuHeading::ObjectDraw()
{
    Entity *self = Self();

    self->values[1]--;
    self->values[1] %= 240;
    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[4];
    DrawSprite_ScreenXY(1, SCREEN_CENTERX, self->values[1]);
    DrawSprite_ScreenXY(2, SCREEN_CENTERX, self->values[1]);
    DrawSprite_ScreenXY(0, SCREEN_CENTERX, 20);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] += 200;
    DrawRectangle(scriptEng.tempValue[0], 20, SCREEN_XSIZE, 9, 0, 0, 0, 255);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] += 12;
    DrawRectangle(0, 212, scriptEng.tempValue[0], 13, 0, 0, 0, 255);
    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[5];
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 160;
    scriptEng.tempValue[0] >>= 2;
    scriptEng.tempValue[0] += self->values[2];
    DrawSprite_ScreenXY(self->frame, scriptEng.tempValue[0], 194);
    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[4];
    self->values[3] += 4;
    self->values[3] &= 511;
    scriptEng.tempValue[0] = SCREEN_XSIZE;
    scriptEng.tempValue[0] -= 40;
    if (objectEntityList[1].values[2] > 4) {
        scriptEng.tempValue[1] = Sin512(self->values[3]);
        scriptEng.tempValue[1] >>= 6;
        scriptEng.tempValue[1] += 96;
        DrawSpriteScreenFX_Script(3, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[1] = Sin512(self->values[3]);
        scriptEng.tempValue[1] /= -64;
        scriptEng.tempValue[1] += 144;
        DrawSpriteScreenFX_Script(4, FX_INK, 40, scriptEng.tempValue[1]);
    }
}

void O_Menu_MenuHeading::MenuHeading_CheckTouchBack()
{
    Entity *self = Self();

    if (Engine.message == 2) {
        self->values[1] = -1;
    }
    scriptEng.tempValue[0] = SCREEN_XSIZE;
    scriptEng.tempValue[0] -= 76;
    CheckTouchRect_Script(scriptEng.tempValue[0], 192, SCREEN_XSIZE, SCREEN_YSIZE);
    if (CheckResult() > -1) {
        self->values[1] = 5;
        objectEntityList[1].values[4] = 1;
    } else {
        objectEntityList[1].values[4] = 0;
        if (scriptEng.tempValue[3] < 0) {
            if (self->values[1] == 5) {
                keyPress.B = 1;
            }
        } else {
            if (self->values[1] == 5) {
                self->values[1] = -1;
            }
        }
    }
}

const Native::NativeFunctionDef O_Menu_MenuHeading::funcs[1] = {
    { "MenuHeading_CheckTouchBack", O_Menu_MenuHeading::MenuHeading_CheckTouchBack },
};

#endif // RETRO_USE_NATIVE_OBJECTS
