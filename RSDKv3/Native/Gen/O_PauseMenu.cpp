#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_PauseMenu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PauseMenu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_PauseMenu::ObjectStartup()
{
    switch (Engine.language) {
        case 0:
        case 5:
        LoadSpriteSheet("Global/Pause_EN.gif");
        break;
        case 1:
        LoadSpriteSheet("Global/Pause_FR.gif");
        break;
        case 2:
        LoadSpriteSheet("Global/Pause_IT.gif");
        break;
        case 3:
        LoadSpriteSheet("Global/Pause_DE.gif");
        break;
        case 4:
        LoadSpriteSheet("Global/Pause_ES.gif");
        break;
    }
    if (playerListPos != 1) {
        AddSpriteFrame(-28, -14, 16, 24, 1, 103);
        AddSpriteFrame(-28, -14, 16, 24, 18, 103);
        AddSpriteFrame(-28, -14, 16, 24, 35, 103);
    } else {
        AddSpriteFrame(-28, -14, 16, 24, 52, 103);
        AddSpriteFrame(-28, -14, 16, 24, 69, 103);
        AddSpriteFrame(-28, -14, 16, 24, 86, 103);
    }
    AddSpriteFrame(0, 0, 128, 32, 0, 0);
    AddSpriteFrame(0, -19, 128, 32, 0, 32);
    AddSpriteFrame(-6, 7, 128, 3, 0, 65);
    switch (Engine.language) {
        case 0:
        case 5:
        AddSpriteFrame(0, -5, 65, 11, 0, 69);
        AddSpriteFrame(0, -5, 55, 11, 0, 81);
        AddSpriteFrame(0, -5, 30, 11, 66, 69);
        AddSpriteFrame(0, -5, 64, 11, 56, 81);
        AddSpriteFrame(0, -5, 72, 11, 0, 92);
        break;
        case 1:
        AddSpriteFrame(0, -5, 73, 11, 0, 69);
        AddSpriteFrame(0, -5, 95, 11, 0, 81);
        AddSpriteFrame(0, -5, 53, 11, 74, 69);
        AddSpriteFrame(0, -5, 23, 11, 96, 81);
        AddSpriteFrame(0, -5, 72, 11, 0, 92);
        break;
        case 2:
        AddSpriteFrame(0, -5, 65, 11, 0, 69);
        AddSpriteFrame(0, -5, 78, 11, 0, 81);
        AddSpriteFrame(0, -5, 28, 11, 66, 69);
        AddSpriteFrame(0, -5, 23, 11, 79, 81);
        AddSpriteFrame(0, -5, 72, 11, 0, 92);
        break;
        case 3:
        AddSpriteFrame(0, -5, 48, 11, 0, 69);
        AddSpriteFrame(0, -5, 65, 11, 0, 81);
        AddSpriteFrame(0, -5, 71, 11, 49, 69);
        AddSpriteFrame(0, -5, 23, 11, 66, 81);
        AddSpriteFrame(0, -5, 72, 11, 0, 92);
        break;
        case 4:
        AddSpriteFrame(0, -5, 73, 11, 0, 69);
        AddSpriteFrame(0, -5, 67, 11, 0, 81);
        AddSpriteFrame(0, -5, 36, 11, 74, 69);
        AddSpriteFrame(0, -5, 23, 11, 68, 81);
        AddSpriteFrame(0, -5, 55, 11, 0, 92);
        break;
    }
}

void O_PauseMenu::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PauseSound();
        self->XPos = SCREEN_XSIZE;
        self->values[3] = 0;
        self->values[0] = 0;
        self->inkEffect = 2;
        self->alpha = 0;
        switch (Engine.language) {
            case 0:
            case 5:
            self->propertyValue = 12;
            break;
            case 1:
            self->propertyValue = 15;
            break;
            case 2:
            case 3:
            case 4:
            self->propertyValue = 13;
            break;
        }
        if (GVar("Player.Lives") < 2) {
            self->values[6] = 1;
        } else {
            if (activeStageList == 3) {
                self->values[6] = 1;
            } else {
                self->values[6] = 0;
            }
        }
        HapticEffect_Script(-1, 0, 0, 0);
        self->state++;
        break;
        case 1:
        self->values[3] = self->values[0];
        self->values[3] *= SCREEN_XSIZE;
        self->values[3] /= 12;
        self->values[4] = self->values[0];
        self->values[4] *= 240;
        self->values[4] /= 12;
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] <<= 7;
        scriptEng.tempValue[0] /= 12;
        self->XPos = SCREEN_XSIZE;
        self->XPos -= scriptEng.tempValue[0];
        if (self->values[0] < self->propertyValue) {
            self->values[0]++;
        } else {
            PauseSound();
            self->values[2] = self->XPos;
            self->values[2] += 48;
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 256) {
            self->values[0] += 16;
            if (self->values[0] < 255) {
                self->alpha = self->values[0];
            } else {
                self->alpha = 255;
            }
        } else {
            self->values[0] = 0;
            self->alpha = 255;
            self->state++;
        }
        break;
        case 3:
        CheckResult() = 1;
        if (CheckResult() == 1) {
            if (keyPress.up == 1) {
                PlaySfx(23, 0);
                self->values[0] = 0;
                self->animationTimer = 0;
                self->frame = 0;
                self->values[2] = SCREEN_XSIZE;
                self->values[1]--;
                if (GVar("Options.DevMenuFlag") == 1) {
                    if (self->values[1] < 0) {
                        self->values[1] = 3;
                    }
                } else {
                    if (self->values[1] < 0) {
                        if (Engine.trialMode == 1) {
                            self->values[1] = 3;
                        } else {
                            self->values[1] = 2;
                        }
                    }
                }
                if (self->values[6] == 1) {
                    if (self->values[1] == 1) {
                        self->values[1]--;
                    }
                }
            }
            if (keyPress.down == 1) {
                PlaySfx(23, 0);
                self->values[0] = 0;
                self->animationTimer = 0;
                self->frame = 0;
                self->values[2] = SCREEN_XSIZE;
                self->values[1]++;
                if (GVar("Options.DevMenuFlag") == 1) {
                    if (self->values[1] > 3) {
                        self->values[1] = 0;
                    }
                } else {
                    if (Engine.trialMode == 1) {
                        if (self->values[1] > 3) {
                            self->values[1] = 0;
                        }
                    } else {
                        if (self->values[1] > 2) {
                            self->values[1] = 0;
                        }
                    }
                }
                if (self->values[6] == 1) {
                    if (self->values[1] == 1) {
                        self->values[1]++;
                    }
                }
            }
            if (keyPress.start == 1) {
                PlaySfx(27, 0);
                self->state = 4;
                self->alpha = 248;
                self->values[0] = 0;
            }
            if (keyPress.A == 1) {
                PlaySfx(27, 0);
                self->state = 4;
                self->alpha = 248;
                self->values[0] = 0;
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
            }
        } else {
            if (Engine.message == 2) {
                self->values[1] = -1;
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            scriptEng.tempValue[3] = CheckResult();
            CheckTouchRect_Script(scriptEng.tempValue[0], 32, SCREEN_XSIZE, 64);
            if (CheckResult() > -1) {
                self->values[1] = 0;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 0) {
                        PlaySfx(27, 0);
                        self->state = 4;
                        self->alpha = 248;
                        self->values[0] = 0;
                    }
                } else {
                    if (self->values[1] == 0) {
                        self->values[1] = -1;
                    }
                }
            }
            if (self->values[6] == 0) {
                CheckTouchRect_Script(scriptEng.tempValue[0], 80, SCREEN_XSIZE, 112);
                if (CheckResult() > -1) {
                    self->values[1] = 1;
                } else {
                    if (scriptEng.tempValue[3] < 0) {
                        if (self->values[1] == 1) {
                            PlaySfx(27, 0);
                            self->state = 4;
                            self->alpha = 248;
                            self->values[0] = 0;
                        }
                    } else {
                        if (self->values[1] == 1) {
                            self->values[1] = -1;
                        }
                    }
                }
            }
            CheckTouchRect_Script(scriptEng.tempValue[0], 128, SCREEN_XSIZE, 160);
            if (CheckResult() > -1) {
                self->values[1] = 2;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 2) {
                        PlaySfx(27, 0);
                        self->state = 4;
                        self->alpha = 248;
                        self->values[0] = 0;
                    }
                } else {
                    if (self->values[1] == 2) {
                        self->values[1] = -1;
                    }
                }
            }
            if (GVar("Options.DevMenuFlag") == 1) {
                CheckTouchRect_Script(scriptEng.tempValue[0], 176, SCREEN_XSIZE, 208);
                if (CheckResult() > -1) {
                    self->values[1] = 3;
                } else {
                    if (scriptEng.tempValue[3] < 0) {
                        if (self->values[1] == 3) {
                            PlaySfx(27, 0);
                            self->state = 4;
                            self->alpha = 248;
                            self->values[0] = 0;
                        }
                    } else {
                        if (self->values[1] == 3) {
                            self->values[1] = -1;
                        }
                    }
                }
            }
            if (Engine.trialMode == 1) {
                CheckTouchRect_Script(scriptEng.tempValue[0], 176, SCREEN_XSIZE, 208);
                if (CheckResult() > -1) {
                    self->values[1] = 3;
                } else {
                    if (scriptEng.tempValue[3] < 0) {
                        if (self->values[1] == 3) {
                            PlaySfx(27, 0);
                            self->state = 4;
                            self->alpha = 248;
                            self->values[0] = 0;
                        }
                    } else {
                        if (self->values[1] == 3) {
                            self->values[1] = -1;
                        }
                    }
                }
            }
            if (keyPress.up == 1) {
                if (GVar("Options.DevMenuFlag") == 1) {
                    self->values[1] = 3;
                } else {
                    self->values[1] = 2;
                }
            }
            if (keyPress.down == 1) {
                self->values[1] = 0;
            }
        }
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->frame = self->animationTimer;
            self->frame >>= 4;
            self->frame++;
            self->animationTimer++;
            self->animationTimer &= 31;
        }
        break;
        case 4:
        self->values[0]++;
        self->values[0] &= 3;
        self->values[2] += 4;
        if (self->alpha > 0) {
            self->alpha -= 8;
        } else {
            if (self->values[1] == 0) {
                self->values[2] = self->XPos;
                self->values[2] += 48;
                self->values[4] = 202;
                self->values[0] = 0;
                self->alpha = 128;
                self->state = 5;
                stageMode = 1;
            } else {
                self->values[2] = self->XPos;
                self->values[2] += 48;
                StopMusic();
                self->state = 6;
            }
        }
        break;
        case 5:
        if (self->alpha > 0) {
            self->alpha -= 8;
            self->XPos += 16;
            self->values[2] += 16;
            self->values[4] += 16;
        } else {
            ResumeSound();
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            if (pAnimation() == GVar("ANI_FLYING")) {
                PlaySfx(24, 1);
            }
            if (pAnimation() == GVar("ANI_FLYINGTIRED")) {
                PlaySfx(24, 1);
            }
            if (Engine.frameSkipSetting > 0) {
                Engine.frameSkipTimer = 0;
            }
        }
        break;
        case 6:
        if (self->XPos > -64) {
            self->XPos -= 16;
            self->values[2] += 16;
        } else {
            switch (self->values[1]) {
                case 1:
                GVar("LampPost.Check") = 0;
                if (GVar("Options.GameMode") == 2) {
                    GVar("Player.Lives") = 1;
                    GVar("Player.Score") = 0;
                } else {
                    GVar("Player.Lives")--;
                }
                stageMode = STAGEMODE_LOAD;
                break;
                case 2:
                GVar("Good_Future_Count") = 0;
                GVar("Good_Future_List") = 0;
                GVar("Good_Future") = 0;
                GVar("Transporter_Destroyed") = 0;
                GVar("MetalSonic_Destroyed") = 0;
                activeStageList = 0;
                GVar("LampPost.Check") = 0;
                if (GVar("Options.GameMode") == 2) {
                    stageListPosition = 2;
                    GVar("TimeAttack.Result") = 0;
                } else {
                    stageListPosition = 0;
                }
                stageMode = STAGEMODE_LOAD;
                break;
                case 3:
                GVar("TimeAttack.Round") = -1;
                Engine.gameMode = 2;
                break;
            }
        }
        break;
    }
}

void O_PauseMenu::ObjectDraw()
{
    Entity *self = Self();

    SetActivePalette(0, 0, SCREEN_YSIZE);
    switch (self->state) {
        case 0:
        case 1:
        case 2:
        if (self->values[5] < 240) {
            if (self->values[4] > self->values[5]) {
                scriptEng.tempValue[0] = self->values[4];
                scriptEng.tempValue[0] -= self->values[5];
                DrawRectangle(0, self->values[5], 384, scriptEng.tempValue[0], 255, 255, 255, 128);
                self->values[5] = self->values[4];
            }
        }
        case 3:
        DrawSprite_ScreenXY(3, self->XPos, 0);
        DrawSprite_ScreenXY(3, self->XPos, 32);
        DrawSprite_ScreenXY(3, self->XPos, 64);
        DrawSprite_ScreenXY(3, self->XPos, 96);
        DrawSprite_ScreenXY(3, self->XPos, 128);
        DrawSprite_ScreenXY(3, self->XPos, 160);
        DrawSprite_ScreenXY(3, self->XPos, 192);
        DrawSprite_ScreenXY(3, self->XPos, 224);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 128;
        DrawRectangle(scriptEng.tempValue[0], 0, 128, SCREEN_YSIZE, 0, 0, 0, 255);
        DrawRectangle(0, 202, self->values[3], 13, 0, 0, 0, 255);
        DrawSpriteScreenFX_Script(4, FX_INK, 0, 202);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 48;
        if (self->values[2] > scriptEng.tempValue[0]) {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] -= self->values[2];
            scriptEng.tempValue[1] >>= 3;
            self->values[2] += scriptEng.tempValue[1];
        }
        scriptEng.tempValue[1] = 48;
        DrawSpriteScreenFX_Script(6, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        if (self->values[1] == 0) {
            DrawSpriteScreenFX_Script(5, FX_INK, self->values[2], scriptEng.tempValue[1]);
            DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        scriptEng.tempValue[1] += 48;
        if (self->values[6] == 0) {
            DrawSpriteScreenFX_Script(7, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        } else {
            scriptEng.tempValue[2] = self->alpha;
            self->alpha >>= 1;
            DrawSpriteScreenFX_Script(7, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            self->alpha = scriptEng.tempValue[2];
        }
        if (self->values[1] == 1) {
            DrawSpriteScreenFX_Script(5, FX_INK, self->values[2], scriptEng.tempValue[1]);
            DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        scriptEng.tempValue[1] += 48;
        DrawSpriteScreenFX_Script(8, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        if (self->values[1] == 2) {
            DrawSpriteScreenFX_Script(5, FX_INK, self->values[2], scriptEng.tempValue[1]);
            DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        scriptEng.tempValue[1] += 48;
        if (GVar("Options.DevMenuFlag") == 1) {
            DrawSpriteScreenFX_Script(9, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            if (self->values[1] == 3) {
                DrawSpriteScreenFX_Script(5, FX_INK, self->values[2], scriptEng.tempValue[1]);
                DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
        } else {
            if (Engine.trialMode == 1) {
                DrawSpriteScreenFX_Script(10, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                if (self->values[1] == 3) {
                    DrawSpriteScreenFX_Script(5, FX_INK, self->values[2], scriptEng.tempValue[1]);
                    DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                }
            }
        }
        break;
        case 4:
        DrawSprite_ScreenXY(3, self->XPos, 0);
        DrawSprite_ScreenXY(3, self->XPos, 32);
        DrawSprite_ScreenXY(3, self->XPos, 64);
        DrawSprite_ScreenXY(3, self->XPos, 96);
        DrawSprite_ScreenXY(3, self->XPos, 128);
        DrawSprite_ScreenXY(3, self->XPos, 160);
        DrawSprite_ScreenXY(3, self->XPos, 192);
        DrawSprite_ScreenXY(3, self->XPos, 224);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 128;
        DrawRectangle(scriptEng.tempValue[0], 0, 128, SCREEN_YSIZE, 0, 0, 0, 255);
        DrawRectangle(0, 202, self->values[3], 13, 0, 0, 0, 255);
        DrawSprite_ScreenXY(4, 0, 202);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 48;
        scriptEng.tempValue[1] = 48;
        if (self->values[1] == 0) {
            if (self->values[0] < 2) {
                DrawSprite_ScreenXY(6, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
            DrawSprite_ScreenXY(5, self->values[2], scriptEng.tempValue[1]);
            DrawSprite_ScreenXY(self->frame, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        } else {
            DrawSpriteScreenFX_Script(6, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        scriptEng.tempValue[1] += 48;
        if (self->values[1] == 1) {
            if (self->values[0] < 2) {
                DrawSprite_ScreenXY(7, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
            DrawSprite_ScreenXY(5, self->values[2], scriptEng.tempValue[1]);
            DrawSprite_ScreenXY(self->frame, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        } else {
            if (self->values[6] == 0) {
                DrawSpriteScreenFX_Script(7, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            } else {
                scriptEng.tempValue[2] = self->alpha;
                self->alpha >>= 1;
                DrawSpriteScreenFX_Script(7, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                self->alpha = scriptEng.tempValue[2];
            }
        }
        scriptEng.tempValue[1] += 48;
        if (self->values[1] == 2) {
            if (self->values[0] < 2) {
                DrawSprite_ScreenXY(8, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
            DrawSprite_ScreenXY(5, self->values[2], scriptEng.tempValue[1]);
            DrawSprite_ScreenXY(self->frame, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        } else {
            DrawSpriteScreenFX_Script(8, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        }
        scriptEng.tempValue[1] += 48;
        if (GVar("Options.DevMenuFlag") == 1) {
            if (self->values[1] == 3) {
                if (self->values[0] < 2) {
                    DrawSprite_ScreenXY(9, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                }
                DrawSprite_ScreenXY(5, self->values[2], scriptEng.tempValue[1]);
                DrawSprite_ScreenXY(self->frame, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            } else {
                DrawSpriteScreenFX_Script(9, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
        } else {
            if (Engine.trialMode == 1) {
                if (self->values[1] == 3) {
                    if (self->values[0] < 2) {
                        DrawSprite_ScreenXY(10, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                    }
                    DrawSprite_ScreenXY(5, self->values[2], scriptEng.tempValue[1]);
                    DrawSprite_ScreenXY(self->frame, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                } else {
                    DrawSpriteScreenFX_Script(10, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                }
            }
        }
        break;
        case 5:
        if (self->alpha < 128) {
            DrawRectangle(0, 0, SCREEN_XSIZE, 240, 255, 255, 255, self->alpha);
        }
        DrawSprite_ScreenXY(3, self->XPos, 0);
        DrawSprite_ScreenXY(3, self->XPos, 32);
        DrawSprite_ScreenXY(3, self->XPos, 64);
        DrawSprite_ScreenXY(3, self->XPos, 96);
        DrawSprite_ScreenXY(3, self->XPos, 128);
        DrawSprite_ScreenXY(3, self->XPos, 160);
        DrawSprite_ScreenXY(3, self->XPos, 192);
        DrawSprite_ScreenXY(3, self->XPos, 224);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 128;
        DrawRectangle(scriptEng.tempValue[0], 0, 128, SCREEN_YSIZE, 0, 0, 0, 255);
        DrawRectangle(0, self->values[4], SCREEN_XSIZE, 13, 0, 0, 0, 255);
        DrawSprite_ScreenXY(4, 0, self->values[4]);
        switch (self->values[1]) {
            case 0:
            DrawSprite_ScreenXY(6, self->values[2], 48);
            DrawSprite_ScreenXY(self->frame, self->values[2], 48);
            break;
            case 1:
            DrawSprite_ScreenXY(6, self->values[2], 96);
            DrawSprite_ScreenXY(self->frame, self->values[2], 96);
            break;
            case 2:
            DrawSprite_ScreenXY(8, self->values[2], 144);
            DrawSprite_ScreenXY(self->frame, self->values[2], 144);
            break;
            case 3:
            if (GVar("Options.DevMenuFlag") == 1) {
                DrawSprite_ScreenXY(9, self->values[2], 192);
                DrawSprite_ScreenXY(self->frame, self->values[2], 192);
            } else {
                if (Engine.trialMode == 1) {
                    DrawSprite_ScreenXY(10, self->values[2], 192);
                    DrawSprite_ScreenXY(self->frame, self->values[2], 192);
                }
            }
            break;
        }
        break;
        case 6:
        scriptEng.tempValue[0] = SCREEN_XSIZE;
        scriptEng.tempValue[0] -= 96;
        DrawRectangle(scriptEng.tempValue[0], 0, 96, 240, 0, 0, 0, 255);
        DrawSprite_ScreenXY(3, self->XPos, 0);
        DrawSprite_ScreenXY(3, self->XPos, 32);
        DrawSprite_ScreenXY(3, self->XPos, 64);
        DrawSprite_ScreenXY(3, self->XPos, 96);
        DrawSprite_ScreenXY(3, self->XPos, 128);
        DrawSprite_ScreenXY(3, self->XPos, 160);
        DrawSprite_ScreenXY(3, self->XPos, 192);
        DrawSprite_ScreenXY(3, self->XPos, 224);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 128;
        DrawRectangle(scriptEng.tempValue[0], 0, 128, SCREEN_YSIZE, 0, 0, 0, 255);
        switch (self->values[1]) {
            case 0:
            DrawSprite_ScreenXY(6, self->values[2], 48);
            DrawSprite_ScreenXY(self->frame, self->values[2], 48);
            break;
            case 1:
            DrawSprite_ScreenXY(6, self->values[2], 96);
            DrawSprite_ScreenXY(self->frame, self->values[2], 96);
            break;
            case 2:
            DrawSprite_ScreenXY(8, self->values[2], 144);
            DrawSprite_ScreenXY(self->frame, self->values[2], 144);
            break;
            case 3:
            if (GVar("Options.DevMenuFlag") == 1) {
                DrawSprite_ScreenXY(9, self->values[2], 192);
                DrawSprite_ScreenXY(self->frame, self->values[2], 192);
            } else {
                if (Engine.trialMode == 1) {
                    DrawSprite_ScreenXY(10, self->values[2], 192);
                    DrawSprite_ScreenXY(self->frame, self->values[2], 192);
                }
            }
            break;
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
