#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_SoundMenu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SoundMenu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_SoundMenu::ObjectStartup()
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
    AddSpriteFrame(-20, -56, 40, 40, 259, 513);
    AddSpriteFrame(-20, -56, 40, 40, 259, 554);
    AddSpriteFrame(-32, -10, 64, 21, 300, 535);
    AddSpriteFrame(-32, -10, 64, 21, 300, 513);
    AddSpriteFrame(-32, -10, 64, 21, 365, 535);
    AddSpriteFrame(-32, -10, 64, 21, 365, 513);
    AddSpriteFrame(-46, -48, 11, 19, 300, 557);
    AddSpriteFrame(32, -48, 17, 16, 312, 557);
    AddSpriteFrame(-35, -13, 70, 27, 430, 497);
}

void O_Menu_SoundMenu::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[1] = GVar("Options.Soundtrack");
        if (self->values[0] < 256) {
            self->alpha = self->values[0];
            self->values[0] += 6;
        } else {
            self->values[0] = 0;
            self->alpha = 255;
            self->state = 1;
        }
        break;
        case 1:
        CheckResult() = 1;
        if (CheckResult() == 1) {
            if (keyPress.left == 1) {
                self->values[1]--;
                if (self->values[1] < 0) {
                    self->values[1] = 1;
                }
                PlaySfx(23, 0);
            }
            if (keyPress.right == 1) {
                self->values[1]++;
                if (self->values[1] > 1) {
                    self->values[1] = 0;
                }
                PlaySfx(23, 0);
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
            }
        } else {
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            scriptEng.tempValue[3] = CheckResult();
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] -= 90;
            scriptEng.tempValue[1] = SCREEN_CENTERX;
            scriptEng.tempValue[1] -= 22;
            CheckTouchRect_Script(scriptEng.tempValue[0], 112, scriptEng.tempValue[1], 144);
            if (CheckResult() > -1) {
                self->values[1] = 0;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 0) {
                        keyPress.start = 1;
                    }
                } else {
                    if (self->values[1] == 0) {
                        self->values[1] = -1;
                    }
                }
            }
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] += 22;
            scriptEng.tempValue[1] = SCREEN_CENTERX;
            scriptEng.tempValue[1] += 90;
            CheckTouchRect_Script(scriptEng.tempValue[0], 112, scriptEng.tempValue[1], 144);
            if (CheckResult() > -1) {
                self->values[1] = 1;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 1) {
                        keyPress.start = 1;
                    }
                } else {
                    if (self->values[1] == 1) {
                        self->values[1] = -1;
                    }
                }
            }
            CallScriptFunctionNamed("MenuHeading_CheckTouchBack", scriptSub);
            if (keyPress.left == 1) {
                self->values[1] = 1;
            }
            if (keyPress.right == 1) {
                self->values[1] = 0;
            }
        }
        CheckResult() = 0;
        if (self->values[1] > -1) {
            if (keyPress.start == 1) {
                CheckResult() = 1;
            }
            if (keyPress.A == 1) {
                CheckResult() = 1;
            }
        }
        if (CheckResult() == 1) {
            GVar("Options.Soundtrack") = self->values[1];
            saveRAM[38] = GVar("Options.Soundtrack");
            self->state = 2;
            StopMusic();
            PlaySfx(27, 0);
            CheckResult() = WriteSaveRAMData();
        }
        if (keyPress.B == 1) {
            self->values[0] = 248;
            self->state = 3;
            PlaySfx(globalSFXCount + 1, 0);
        }
        break;
        case 2:
        if (self->animationTimer < 30) {
            self->animationTimer++;
        } else {
            self->animationTimer = 0;
            self->state = 3;
            PlayMusic(GVar("Options.Soundtrack"));
        }
        break;
        case 3:
        case 4:
        if (self->values[0] > 0) {
            self->alpha = self->values[0];
            self->values[0] -= 8;
        } else {
            self->type = TypeNameID("Blank Object");
            objectEntityList[objectLoop - 1].state = 3;
            objectEntityList[34].state = 1;
            objectEntityList[35].state = 1;
            objectEntityList[36].state = 1;
            objectEntityList[37].state = 1;
            objectEntityList[38].state = 1;
            objectEntityList[39].state = 1;
            objectEntityList[40].state = 1;
            objectEntityList[41].state = 1;
            objectEntityList[42].state = 1;
            objectEntityList[33].state = 1;
            objectEntityList[33].propertyValue = 5;
        }
        break;
    }
}

void O_Menu_SoundMenu::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[2];
    scriptEng.tempValue[0] >>= 5;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, SCREEN_CENTERX, SCREEN_CENTERY);
    self->values[2]++;
    self->values[2] &= 63;
    scriptEng.tempValue[0] = Sin512(self->values[3]);
    scriptEng.tempValue[0] >>= 6;
    scriptEng.tempValue[0] += SCREEN_CENTERY;
    DrawSpriteScreenFX_Script(6, FX_INK, SCREEN_CENTERX, scriptEng.tempValue[0]);
    scriptEng.tempValue[0] = Sin512(self->values[3]);
    scriptEng.tempValue[0] >>= 6;
    scriptEng.tempValue[0] = -scriptEng.tempValue[0];
    scriptEng.tempValue[0] += SCREEN_CENTERY;
    DrawSpriteScreenFX_Script(7, FX_INK, SCREEN_CENTERX, scriptEng.tempValue[0]);
    self->values[3] += 2;
    self->values[3] &= 511;
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 56;
    scriptEng.tempValue[1] = SCREEN_CENTERX;
    scriptEng.tempValue[1] += 56;
    scriptEng.tempValue[3] = SCREEN_CENTERY;
    scriptEng.tempValue[3] += 8;
    if (self->values[1] == 0) {
        scriptEng.tempValue[2] = self->animationTimer;
        scriptEng.tempValue[2] &= 3;
        scriptEng.tempValue[2] >>= 1;
        scriptEng.tempValue[2] += 2;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[3]);
    } else {
        DrawSpriteScreenFX_Script(3, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[3]);
    }
    if (self->values[1] == 1) {
        scriptEng.tempValue[2] = self->animationTimer;
        scriptEng.tempValue[2] &= 3;
        scriptEng.tempValue[2] >>= 1;
        scriptEng.tempValue[2] += 4;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, scriptEng.tempValue[1], scriptEng.tempValue[3]);
    } else {
        DrawSpriteScreenFX_Script(5, FX_INK, scriptEng.tempValue[1], scriptEng.tempValue[3]);
    }
    if (GVar("Options.Soundtrack") == 0) {
        DrawSpriteScreenFX_Script(8, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[3]);
    } else {
        DrawSpriteScreenFX_Script(8, FX_INK, scriptEng.tempValue[1], scriptEng.tempValue[3]);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
