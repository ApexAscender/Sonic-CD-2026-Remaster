#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_MenuWindow.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MenuWindow.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_MenuWindow::ObjectStartup()
{
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
    AddSpriteFrame(0, 0, 140, 10, 259, 246);
    AddSpriteFrame(-140, 0, 140, 10, 263, 246);
    AddSpriteFrame(0, -11, 140, 11, 259, 256);
    AddSpriteFrame(-140, -11, 140, 11, 263, 256);
    AddSpriteFrame(-32, -24, 64, 24, 404, 146);
    AddSpriteFrame(-32, -24, 64, 24, 404, 171);
}

void O_Menu_MenuWindow::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 14) {
            self->values[0]++;
            scriptEng.tempValue[0] = 300;
            scriptEng.tempValue[0] -= self->values[1];
            scriptEng.tempValue[0] >>= 3;
            self->values[1] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = 224;
            scriptEng.tempValue[0] -= self->values[2];
            scriptEng.tempValue[0] >>= 3;
            self->values[2] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] -= self->XPos;
            scriptEng.tempValue[0] >>= 2;
            self->XPos += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = SCREEN_CENTERY;
            scriptEng.tempValue[0] -= 6;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] -= self->YPos;
            scriptEng.tempValue[0] >>= 2;
            self->YPos += scriptEng.tempValue[0];
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 1:
        if (self->values[0] < 30) {
            self->values[0]++;
            scriptEng.tempValue[0] = 256;
            scriptEng.tempValue[0] -= self->values[1];
            scriptEng.tempValue[0] >>= 2;
            self->values[1] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = 160;
            scriptEng.tempValue[0] -= self->values[2];
            scriptEng.tempValue[0] >>= 2;
            self->values[2] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] <<= 16;
            if (self->XPos > scriptEng.tempValue[0]) {
                self->XPos -= 0x10000;
            }
            if (self->XPos < scriptEng.tempValue[0]) {
                self->XPos += 0x10000;
            }
            scriptEng.tempValue[0] = SCREEN_CENTERY;
            scriptEng.tempValue[0] -= 8;
            scriptEng.tempValue[0] <<= 16;
            if (self->YPos > scriptEng.tempValue[0]) {
                self->YPos -= 0x10000;
            }
            if (self->YPos < scriptEng.tempValue[0]) {
                self->YPos += 0x10000;
            }
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        break;
        case 3:
        if (self->values[0] < 14) {
            self->values[0]++;
            scriptEng.tempValue[0] = 132;
            scriptEng.tempValue[0] -= self->values[1];
            scriptEng.tempValue[0] >>= 3;
            self->values[1] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = 18;
            scriptEng.tempValue[0] -= self->values[2];
            scriptEng.tempValue[0] >>= 3;
            self->values[2] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] -= self->XPos;
            scriptEng.tempValue[0] >>= 2;
            self->XPos += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = self->values[4];
            scriptEng.tempValue[0] -= self->YPos;
            scriptEng.tempValue[0] >>= 2;
            self->YPos += scriptEng.tempValue[0];
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 4:
        if (self->values[0] < 14) {
            self->values[0]++;
            scriptEng.tempValue[0] = 144;
            scriptEng.tempValue[0] -= self->values[1];
            scriptEng.tempValue[0] >>= 3;
            self->values[1] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = 21;
            scriptEng.tempValue[0] -= self->values[2];
            scriptEng.tempValue[0] >>= 3;
            self->values[2] += scriptEng.tempValue[0];
            if (self->XPos > self->values[3]) {
                self->XPos -= 0x10000;
            }
            if (self->XPos < self->values[3]) {
                self->XPos += 0x10000;
            }
            if (self->YPos > self->values[4]) {
                self->YPos -= 0x10000;
            }
            if (self->YPos < self->values[4]) {
                self->YPos += 0x10000;
            }
        } else {
            self->values[0]++;
            if (self->values[0] == 16) {
                self->values[0] = 0;
                self->type = TypeNameID("Blank Object");
            }
            scriptEng.arrayPosition[0] = self->values[5];
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Menu Button");
            objectEntityList[scriptEng.arrayPosition[0]].state = 7;
        }
        break;
        case 5:
        if (self->values[0] < 14) {
            self->values[0]++;
            scriptEng.tempValue[0] = 300;
            scriptEng.tempValue[0] -= self->values[1];
            scriptEng.tempValue[0] >>= 3;
            self->values[1] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = 192;
            scriptEng.tempValue[0] -= self->values[2];
            scriptEng.tempValue[0] >>= 3;
            self->values[2] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] -= self->XPos;
            scriptEng.tempValue[0] >>= 2;
            self->XPos += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = SCREEN_CENTERY;
            scriptEng.tempValue[0] -= 6;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] -= self->YPos;
            scriptEng.tempValue[0] >>= 2;
            self->YPos += scriptEng.tempValue[0];
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 6:
        if (self->values[0] < 30) {
            self->values[0]++;
            scriptEng.tempValue[0] = 256;
            scriptEng.tempValue[0] -= self->values[1];
            scriptEng.tempValue[0] >>= 2;
            self->values[1] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = 128;
            scriptEng.tempValue[0] -= self->values[2];
            scriptEng.tempValue[0] >>= 2;
            self->values[2] += scriptEng.tempValue[0];
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] <<= 16;
            if (self->XPos > scriptEng.tempValue[0]) {
                self->XPos -= 0x10000;
            }
            if (self->XPos < scriptEng.tempValue[0]) {
                self->XPos += 0x10000;
            }
            scriptEng.tempValue[0] = SCREEN_CENTERY;
            scriptEng.tempValue[0] -= 8;
            scriptEng.tempValue[0] <<= 16;
            if (self->YPos > scriptEng.tempValue[0]) {
                self->YPos -= 0x10000;
            }
            if (self->YPos < scriptEng.tempValue[0]) {
                self->YPos += 0x10000;
            }
        } else {
            self->values[0] = 0;
            self->state = 2;
        }
        break;
    }
}

void O_Menu_MenuWindow::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] *= -0x8000;
    scriptEng.tempValue[0] += self->XPos;
    scriptEng.tempValue[1] = self->values[2];
    scriptEng.tempValue[1] *= -0x8000;
    scriptEng.tempValue[1] += self->YPos;
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] <<= 15;
    scriptEng.tempValue[0] += self->XPos;
    DrawSprite_FrameXY(1, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] *= -0x8000;
    scriptEng.tempValue[0] += self->XPos;
    scriptEng.tempValue[1] = self->values[2];
    scriptEng.tempValue[1] <<= 15;
    scriptEng.tempValue[1] += self->YPos;
    DrawSprite_FrameXY(2, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] <<= 15;
    scriptEng.tempValue[0] += self->XPos;
    DrawSprite_FrameXY(3, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] *= -0x8000;
    scriptEng.tempValue[0] += self->XPos;
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[1] = self->values[2];
    scriptEng.tempValue[1] *= -0x8000;
    scriptEng.tempValue[1] += self->YPos;
    scriptEng.tempValue[1] += 0xA0000;
    scriptEng.tempValue[1] >>= 16;
    scriptEng.tempValue[2] = self->values[1];
    scriptEng.tempValue[2] -= 2;
    scriptEng.tempValue[3] = self->values[2];
    scriptEng.tempValue[3] -= 21;
    DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2], scriptEng.tempValue[3], 96, 96, 128, 255);
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] <<= 15;
    scriptEng.tempValue[0] += self->XPos;
    scriptEng.tempValue[0] -= 0x20000;
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[2] = 2;
    DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2], scriptEng.tempValue[3], 0, 0, 0, 255);
    self->inkEffect = 2;
    switch (self->state) {
        case 0:
        case 1:
        case 5:
        case 6:
        if (self->alpha < 248) {
            self->alpha += 5;
        }
        break;
        case 2:
        self->alpha = 255;
        break;
        case 3:
        case 4:
        if (self->alpha > 0) {
            self->alpha -= 8;
        }
        break;
    }
    scriptEng.tempValue[0] = SCREEN_XSIZE;
    scriptEng.tempValue[0] -= 48;
    if (objectEntityList[1].values[4] == 1) {
        DrawSpriteScreenFX_Script(5, FX_INK, scriptEng.tempValue[0], 225);
    } else {
        DrawSpriteScreenFX_Script(4, FX_INK, scriptEng.tempValue[0], 225);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
