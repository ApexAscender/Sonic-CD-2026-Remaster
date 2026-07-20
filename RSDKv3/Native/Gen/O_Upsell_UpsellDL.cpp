#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Upsell_UpsellDL.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from UpsellDL.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Upsell_UpsellDL::ObjectStartup()
{
    scriptEng.tempValue[0] = 0;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Upsell DL")) {
            scriptEng.tempValue[0] = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
    if (scriptEng.tempValue[0] == 1) {
        switch (Engine.language) {
            case 0:
            LoadSpriteSheet("Upsell/UpsellDL_EN.gif");
            break;
            case 1:
            LoadSpriteSheet("Upsell/UpsellDL_FR.gif");
            break;
            case 2:
            LoadSpriteSheet("Upsell/UpsellDL_IT.gif");
            break;
            case 3:
            LoadSpriteSheet("Upsell/UpsellDL_DE.gif");
            break;
            case 4:
            LoadSpriteSheet("Upsell/UpsellDL_ES.gif");
            break;
            case 5:
            LoadSpriteSheet("Upsell/UpsellDL_JP.gif");
            break;
        }
        LoadPalette("UpsellDL.act", 0, 0, 0, 256);
    }
    Engine.gameMode = 5;
    AddSpriteFrame(-512, -288, 1024, 576, 0, 0);
    if (Engine.language != 5) {
        AddSpriteFrame(-128, -35, 260, 69, 381, 580);
        AddSpriteFrame(-91, -24, 182, 49, 420, 673);
    } else {
        AddSpriteFrame(-128, -36, 260, 69, 381, 580);
        AddSpriteFrame(-91, -24, 183, 49, 420, 677);
    }
}

void O_Upsell_UpsellDL::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (GVar("Options.PhysicalControls") == 0) {
            self->values[1] = -1;
        } else {
            self->values[1] = 0;
        }
        if (self->values[0] < 16) {
            self->values[0]++;
        } else {
            self->values[0] = 288;
            self->state++;
        }
        SetFade(0, 0, 0, 255);
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            self->state++;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 2:
        if (GVar("Options.PhysicalControls") == 1) {
            if (keyPress.up == 1) {
                self->values[1]--;
                if (self->values[1] < 0) {
                    self->values[1] = 1;
                }
                PlaySfx(23, 0);
            }
            if (keyPress.down == 1) {
                self->values[1]++;
                if (self->values[1] > 1) {
                    self->values[1] = 0;
                }
                PlaySfx(23, 0);
            }
            if (keyPress.start == 1) {
                switch (self->values[1]) {
                    case 0:
                    Engine.Callback(8);
                    break;
                    case 1:
                    self->state = 3;
                    break;
                }
            }
            if (keyPress.A == 1) {
                switch (self->values[1]) {
                    case 0:
                    Engine.Callback(8);
                    break;
                    case 1:
                    self->state = 3;
                    break;
                }
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
                GVar("Options.PhysicalControls") = 0;
                self->values[1] = -1;
            }
        } else {
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            scriptEng.tempValue[3] = CheckResult();
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] -= 80;
            scriptEng.tempValue[1] = SCREEN_CENTERX;
            scriptEng.tempValue[1] += 80;
            CheckTouchRect_Script(scriptEng.tempValue[0], 168, scriptEng.tempValue[1], 200);
            if (CheckResult() > -1) {
                self->values[1] = 0;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 0) {
                        Engine.Callback(8);
                        self->values[1] = -1;
                    }
                } else {
                    if (self->values[1] == 0) {
                        self->values[1] = -1;
                    }
                }
            }
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] -= 64;
            scriptEng.tempValue[1] = SCREEN_CENTERX;
            scriptEng.tempValue[1] += 64;
            CheckTouchRect_Script(scriptEng.tempValue[0], 208, scriptEng.tempValue[1], 236);
            if (CheckResult() > -1) {
                self->values[1] = 1;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 1) {
                        self->state = 3;
                        self->values[1] = -1;
                    }
                } else {
                    if (self->values[1] == 1) {
                        self->values[1] = -1;
                    }
                }
            }
            if (keyPress.up == 1) {
                self->values[1] = 1;
                GVar("Options.PhysicalControls") = 1;
            }
            if (keyPress.down == 1) {
                self->values[1] = 0;
                GVar("Options.PhysicalControls") = 1;
            }
        }
        break;
        case 3:
        if (self->values[0] < 288) {
            self->values[0] += 8;
        } else {
            Engine.gameMode = 6;
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

void O_Upsell_UpsellDL::ObjectDraw()
{
    Entity *self = Self();

    self->scale = 216;
    DrawSpriteScreenFX_Script(0, FX_SCALE, SCREEN_CENTERX, SCREEN_CENTERY);
    if (self->values[1] == 0) {
        DrawSpriteScreenFX_Script(1, FX_SCALE, SCREEN_CENTERX, 186);
    }
    if (self->values[1] == 1) {
        DrawSpriteScreenFX_Script(2, FX_SCALE, SCREEN_CENTERX, 222);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
