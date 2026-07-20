#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_AboutMenu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from AboutMenu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_AboutMenu::ObjectStartup()
{
    LoadSpriteSheet("Menu/MenuGfx1_EN.gif");
    AddSpriteFrame(0, 0, 132, 113, 154, 235);
    AddSpriteFrame(-28, 0, 56, 16, 154, 349);
    scriptEng.tempValue[1] = 366;
    while (scriptEng.tempValue[1] < 417) {
        scriptEng.tempValue[0] = 154;
        while (scriptEng.tempValue[0] < 280) {
            AddSpriteFrame(-3, 0, 8, 16, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] += 9;
        }
        scriptEng.tempValue[1] += 17;
    }
    AddSpriteFrame(-32, 0, 64, 21, 195, 476);
    AddSpriteFrame(-32, 0, 64, 21, 130, 476);
    AddSpriteFrame(-32, 0, 64, 21, 195, 454);
    AddSpriteFrame(-32, 0, 64, 21, 130, 454);
    AddSpriteFrame(-32, 0, 42, 21, 418, 439);
    AddSpriteFrame(-32, 0, 42, 21, 418, 461);
    AddSpriteFrame(10, 0, 22, 21, 464, 395);
    AddSpriteFrame(10, 0, 22, 21, 464, 417);
    AddSpriteFrame(10, 0, 22, 21, 464, 439);
    AddSpriteFrame(10, 0, 22, 21, 464, 461);
}

void O_Menu_AboutMenu::ObjectMain()
{
    Entity *self = Self();

    self->alpha = objectEntityList[objectLoop - 10].alpha;
}

void O_Menu_AboutMenu::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 120;
    DrawSpriteScreenFX_Script(0, FX_INK, scriptEng.tempValue[0], 72);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] += 72;
    DrawSpriteScreenFX_Script(1, FX_INK, scriptEng.tempValue[0], 82);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] += 72;
    if (self->values[1] == 0) {
        scriptEng.tempValue[2] = self->animationTimer;
        scriptEng.tempValue[2] &= 3;
        scriptEng.tempValue[2] >>= 1;
        scriptEng.tempValue[2] += 44;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, scriptEng.tempValue[0], 128);
    } else {
        DrawSpriteScreenFX_Script(45, FX_INK, scriptEng.tempValue[0], 128);
    }
    if (self->values[1] == 1) {
        scriptEng.tempValue[2] = self->animationTimer;
        scriptEng.tempValue[2] &= 3;
        scriptEng.tempValue[2] >>= 1;
        scriptEng.tempValue[2] += 46;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, scriptEng.tempValue[0], 156);
    } else {
        DrawSpriteScreenFX_Script(47, FX_INK, scriptEng.tempValue[0], 156);
    }
    scriptEng.arrayPosition[0] = 0;
    scriptEng.tempValue[1] = GetTextInfo_Script(0, 1, 0, 0);
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] <<= 2;
    scriptEng.tempValue[2] = -scriptEng.tempValue[2];
    scriptEng.tempValue[2] += SCREEN_CENTERX;
    scriptEng.tempValue[2] += 72;
    self->values[2] = 102;
    while (scriptEng.tempValue[1] > 0) {
        scriptEng.tempValue[0] = GetTextInfo_Script(0, 0, 0, scriptEng.arrayPosition[0]);
        switch (scriptEng.tempValue[0]) {
            default:
            self->frame = 0;
            if (scriptEng.tempValue[0] > 64) {
                if (scriptEng.tempValue[0] < 91) {
                    self->frame = scriptEng.tempValue[0];
                    self->frame -= 63;
                }
            }
            if (scriptEng.tempValue[0] > 96) {
                if (scriptEng.tempValue[0] < 123) {
                    self->frame = scriptEng.tempValue[0];
                    self->frame -= 95;
                }
            }
            if (scriptEng.tempValue[0] > 47) {
                if (scriptEng.tempValue[0] < 58) {
                    self->frame = scriptEng.tempValue[0];
                    self->frame -= 18;
                }
            }
            if (self->frame > 0) {
                DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[2], self->values[2]);
            }
            break;
            case 38:
            DrawSpriteScreenFX_Script(33, FX_INK, scriptEng.tempValue[2], self->values[2]);
            break;
            case 39:
            DrawSpriteScreenFX_Script(31, FX_INK, scriptEng.tempValue[2], self->values[2]);
            break;
            case 44:
            DrawSpriteScreenFX_Script(29, FX_INK, scriptEng.tempValue[2], self->values[2]);
            break;
            case 46:
            DrawSpriteScreenFX_Script(28, FX_INK, scriptEng.tempValue[2], self->values[2]);
            break;
        }
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[1]--;
        scriptEng.tempValue[2] += 8;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
