#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_AboutMenuF.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from AboutMenuF.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_AboutMenuF::ObjectStartup()
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

void O_Menu_AboutMenuF::ObjectMain()
{
    Entity *self = Self();

    self->alpha = objectEntityList[objectLoop - 10].alpha;
    if (self->alpha > 254) {
        if (2 == 1) {
            switch (self->state) {
                case 0:
                if (GVar("Options.PhysicalControls") == 1) {
                    if (keyPress.up == 1) {
                        self->values[1]--;
                        if (self->values[1] < 0) {
                            self->values[1] = 2;
                        }
                        PlaySfx(23, 0);
                    }
                    if (keyPress.down == 1) {
                        self->values[1]++;
                        if (self->values[1] > 2) {
                            self->values[1] = 0;
                        }
                        PlaySfx(23, 0);
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
                    scriptEng.tempValue[0] += 36;
                    scriptEng.tempValue[1] = SCREEN_CENTERX;
                    scriptEng.tempValue[1] += 110;
                    CheckTouchRect_Script(scriptEng.tempValue[0], 108, scriptEng.tempValue[1], 134);
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
                    scriptEng.tempValue[0] += 36;
                    scriptEng.tempValue[1] = SCREEN_CENTERX;
                    scriptEng.tempValue[1] += 110;
                    CheckTouchRect_Script(scriptEng.tempValue[0], 134, scriptEng.tempValue[1], 160);
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
                    scriptEng.tempValue[0] = SCREEN_CENTERX;
                    scriptEng.tempValue[0] += 36;
                    scriptEng.tempValue[1] = SCREEN_CENTERX;
                    scriptEng.tempValue[1] += 110;
                    CheckTouchRect_Script(scriptEng.tempValue[0], 160, scriptEng.tempValue[1], 185);
                    if (CheckResult() > -1) {
                        self->values[1] = 2;
                    } else {
                        if (scriptEng.tempValue[3] < 0) {
                            if (self->values[1] == 2) {
                                keyPress.start = 1;
                            }
                        } else {
                            if (self->values[1] == 2) {
                                self->values[1] = -1;
                            }
                        }
                    }
                    CallScriptFunctionNamed("MenuHeading_CheckTouchBack", scriptSub);
                    if (keyPress.up == 1) {
                        self->values[1] = 1;
                        GVar("Options.PhysicalControls") = 1;
                    }
                    if (keyPress.down == 1) {
                        self->values[1] = 0;
                        GVar("Options.PhysicalControls") = 1;
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
                    PlaySfx(27, 0);
                    self->state++;
                }
                break;
                case 1:
                if (self->animationTimer < 30) {
                    self->animationTimer++;
                } else {
                    self->animationTimer = 0;
                    self->state = 0;
                    switch (self->values[1]) {
                        case 0:
                        Engine.Callback(9);
                        break;
                        case 1:
                        Engine.Callback(10);
                        break;
                        case 2:
                        Engine.Callback(17);
                        break;
                    }
                    if (GVar("Options.PhysicalControls") == 0) {
                        self->values[1] = -1;
                    }
                }
                break;
            }
        }
    } else {
        if (GVar("Options.PhysicalControls") == 0) {
            self->values[1] = -1;
        }
        self->animationTimer = 0;
        self->state = 0;
    }
}

void O_Menu_AboutMenuF::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 120;
    DrawSpriteScreenFX_Script(0, FX_INK, scriptEng.tempValue[0], 72);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] += 72;
    DrawSpriteScreenFX_Script(1, FX_INK, scriptEng.tempValue[0], 74);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] += 72;
    if (2 == 1) {
        switch (self->values[1]) {
            default:
            DrawSpriteScreenFX_Script(47, FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(45, FX_INK, scriptEng.tempValue[0], 110);
            DrawSpriteScreenFX_Script(49, FX_INK, scriptEng.tempValue[0], 162);
            if (GVar("SegaID.LoggedIn") == 0) {
                DrawSpriteScreenFX_Script(51, FX_INK, scriptEng.tempValue[0], 162);
            } else {
                DrawSpriteScreenFX_Script(53, FX_INK, scriptEng.tempValue[0], 162);
            }
            break;
            case 0:
            scriptEng.tempValue[2] = self->animationTimer;
            scriptEng.tempValue[2] &= 3;
            scriptEng.tempValue[2] >>= 1;
            scriptEng.tempValue[2] += 44;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, scriptEng.tempValue[0], 110);
            DrawSpriteScreenFX_Script(47, FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(49, FX_INK, scriptEng.tempValue[0], 162);
            if (GVar("SegaID.LoggedIn") == 0) {
                DrawSpriteScreenFX_Script(51, FX_INK, scriptEng.tempValue[0], 162);
            } else {
                DrawSpriteScreenFX_Script(53, FX_INK, scriptEng.tempValue[0], 162);
            }
            break;
            case 1:
            scriptEng.tempValue[2] = self->animationTimer;
            scriptEng.tempValue[2] &= 3;
            scriptEng.tempValue[2] >>= 1;
            scriptEng.tempValue[2] += 46;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(45, FX_INK, scriptEng.tempValue[0], 110);
            DrawSpriteScreenFX_Script(49, FX_INK, scriptEng.tempValue[0], 162);
            if (GVar("SegaID.LoggedIn") == 0) {
                DrawSpriteScreenFX_Script(51, FX_INK, scriptEng.tempValue[0], 162);
            } else {
                DrawSpriteScreenFX_Script(53, FX_INK, scriptEng.tempValue[0], 162);
            }
            break;
            case 2:
            scriptEng.tempValue[2] = self->animationTimer;
            scriptEng.tempValue[2] &= 3;
            scriptEng.tempValue[2] >>= 1;
            scriptEng.tempValue[2] += 48;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, scriptEng.tempValue[0], 162);
            if (GVar("SegaID.LoggedIn") == 0) {
                scriptEng.tempValue[2] += 2;
                DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, scriptEng.tempValue[0], 162);
            } else {
                scriptEng.tempValue[2] += 4;
                DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, scriptEng.tempValue[0], 162);
            }
            DrawSpriteScreenFX_Script(47, FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(45, FX_INK, scriptEng.tempValue[0], 110);
            break;
        }
    }
    scriptEng.arrayPosition[0] = 0;
    scriptEng.tempValue[1] = GetTextInfo_Script(0, 1, 0, 0);
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] <<= 2;
    scriptEng.tempValue[2] = -scriptEng.tempValue[2];
    scriptEng.tempValue[2] += SCREEN_CENTERX;
    scriptEng.tempValue[2] += 72;
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
                DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[2], 92);
            }
            break;
            case 38:
            DrawSpriteScreenFX_Script(33, FX_INK, scriptEng.tempValue[2], 92);
            break;
            case 39:
            DrawSpriteScreenFX_Script(31, FX_INK, scriptEng.tempValue[2], 92);
            break;
            case 44:
            DrawSpriteScreenFX_Script(29, FX_INK, scriptEng.tempValue[2], 92);
            break;
            case 46:
            DrawSpriteScreenFX_Script(28, FX_INK, scriptEng.tempValue[2], 92);
            break;
        }
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[1]--;
        scriptEng.tempValue[2] += 8;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
