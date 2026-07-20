#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Secrets_StageSelect.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from StageSelect.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Secrets_StageSelect::ObjectStartup()
{
    LoadSpriteSheet("Secrets/SecretMenus.gif");
    AddSpriteFrame(0, 0, 8, 16, 1, 49);
    AddSpriteFrame(0, 0, 8, 16, 10, 49);
    AddSpriteFrame(0, 0, 8, 16, 19, 49);
    AddSpriteFrame(0, 0, 8, 16, 28, 49);
    AddSpriteFrame(0, 0, 8, 16, 1, 66);
    AddSpriteFrame(0, 0, 8, 16, 10, 66);
    AddSpriteFrame(0, 0, 8, 16, 19, 66);
    AddSpriteFrame(0, 0, 8, 16, 28, 66);
    AddSpriteFrame(0, 0, 8, 16, 1, 83);
    AddSpriteFrame(0, 0, 8, 16, 10, 83);
    AddSpriteFrame(0, 0, 8, 16, 37, 49);
    AddSpriteFrame(0, 0, 8, 16, 46, 49);
    AddSpriteFrame(0, 0, 8, 16, 55, 49);
    AddSpriteFrame(0, 0, 8, 16, 64, 49);
    AddSpriteFrame(0, 0, 8, 16, 19, 83);
    AddSpriteFrame(0, 0, 224, 48, 0, 0);
    AddSpriteFrame(-48, 0, 96, 16, 136, 66);
    AddSpriteFrame(-10, -10, 20, 20, 136, 117);
    AddSpriteFrame(-10, -10, 20, 20, 136, 138);
    AddSpriteFrame(-10, -10, 20, 20, 157, 117);
    AddSpriteFrame(-10, -10, 20, 20, 157, 138);
    AddSpriteFrame(-20, -10, 40, 20, 159, 159);
    AddSpriteFrame(-20, -10, 40, 20, 159, 180);
    AddSpriteFrame(-20, -10, 40, 20, 200, 159);
    AddSpriteFrame(-20, -10, 40, 20, 200, 180);
}

void O_Secrets_StageSelect::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 8) {
            self->values[0]++;
        } else {
            self->values[0] = 254;
            self->state++;
        }
        SetFade(0, 0, 0, 255);
        break;
        case 1:
        if (self->values[0] > 0) {
            SetFade(0, 0, 0, self->values[0]);
            self->values[0] -= 8;
        } else {
            self->state++;
        }
        break;
        case 2:
        if (keyPress.up == 1) {
            self->values[2] = 0;
            self->values[1]--;
            if (self->values[1] < 0) {
                self->values[1] = 69;
            }
        } else {
            if (keyPress.down == 1) {
                self->values[2] = 0;
                self->values[1]++;
                if (self->values[1] > 69) {
                    self->values[1] = 0;
                }
            }
        }
        if (keyDown.up == 1) {
            self->values[2]++;
            if (self->values[2] == 8) {
                self->values[2] = 0;
                self->values[1]--;
                if (self->values[1] < 0) {
                    self->values[1] = 69;
                }
            }
        } else {
            if (keyDown.down == 1) {
                self->values[2]++;
                if (self->values[2] == 8) {
                    self->values[2] = 0;
                    self->values[1]++;
                    if (self->values[1] > 69) {
                        self->values[1] = 0;
                    }
                }
            }
        }
        if (keyPress.start == 1) {
            self->state = 3;
        }
        if (keyPress.A == 1) {
            self->state = 3;
        }
        if (keyPress.B == 1) {
            self->state = 4;
        }
        break;
        case 3:
        if (self->values[0] < 288) {
            self->values[0] += 8;
        } else {
            GVar("Options.GameMode") = 0;
            GVar("Player.Lives") = 3;
            activeStageList = 1;
            stageListPosition = self->values[1];
            stageMode = STAGEMODE_LOAD;
        }
        scriptEng.tempValue[0] = self->values[0];
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        SetFade(0, 0, 0, scriptEng.tempValue[0]);
        break;
        case 4:
        if (self->values[0] < 288) {
            self->values[0] += 8;
        } else {
            GVar("Options.GameMode") = 0;
            activeStageList = 0;
            stageListPosition = 1;
            stageMode = STAGEMODE_LOAD;
        }
        scriptEng.tempValue[0] = self->values[0];
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        SetFade(0, 0, 0, scriptEng.tempValue[0]);
        break;
    }
}

void O_Secrets_StageSelect::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    while (scriptEng.tempValue[0] < 240) {
        scriptEng.tempValue[1] = 0;
        while (scriptEng.tempValue[1] < SCREEN_XSIZE) {
            DrawSprite_ScreenXY(15, scriptEng.tempValue[1], scriptEng.tempValue[0]);
            scriptEng.tempValue[1] += 224;
        }
        scriptEng.tempValue[0] += 48;
    }
    DrawSprite_ScreenXY(16, SCREEN_CENTERX, 80);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 48;
    scriptEng.tempValue[1] = self->values[1];
    scriptEng.tempValue[1] /= 10;
    switch (scriptEng.tempValue[1]) {
        case 0:
        DrawSprite_ScreenXY(1, scriptEng.tempValue[0], 112);
        break;
        case 1:
        DrawSprite_ScreenXY(3, scriptEng.tempValue[0], 112);
        break;
        case 2:
        DrawSprite_ScreenXY(4, scriptEng.tempValue[0], 112);
        break;
        case 3:
        DrawSprite_ScreenXY(5, scriptEng.tempValue[0], 112);
        break;
        case 4:
        DrawSprite_ScreenXY(6, scriptEng.tempValue[0], 112);
        break;
        case 5:
        DrawSprite_ScreenXY(7, scriptEng.tempValue[0], 112);
        break;
        case 6:
        DrawSprite_ScreenXY(8, scriptEng.tempValue[0], 112);
        break;
    }
    scriptEng.tempValue[0] += 8;
    DrawSprite_ScreenXY(14, scriptEng.tempValue[0], 112);
    scriptEng.tempValue[0] += 8;
    scriptEng.tempValue[1] = self->values[1];
    scriptEng.tempValue[1] %= 10;
    scriptEng.tempValue[1] >>= 2;
    scriptEng.tempValue[1]++;
    DrawSprite_ScreenXY(scriptEng.tempValue[1], scriptEng.tempValue[0], 112);
    scriptEng.tempValue[0] += 8;
    DrawSprite_ScreenXY(14, scriptEng.tempValue[0], 112);
    scriptEng.tempValue[0] += 8;
    scriptEng.tempValue[1] = self->values[1];
    scriptEng.tempValue[1] %= 10;
    switch (scriptEng.tempValue[1]) {
        case 0:
        case 4:
        DrawSprite_ScreenXY(10, scriptEng.tempValue[0], 112);
        break;
        case 1:
        case 5:
        DrawSprite_ScreenXY(11, scriptEng.tempValue[0], 112);
        break;
        case 2:
        case 6:
        case 8:
        DrawSprite_ScreenXY(12, scriptEng.tempValue[0], 112);
        break;
        case 3:
        case 7:
        case 9:
        DrawSprite_ScreenXY(13, scriptEng.tempValue[0], 112);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
