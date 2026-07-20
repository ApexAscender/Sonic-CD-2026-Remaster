#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_OptionsMenu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from OptionsMenu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_OptionsMenu::ObjectStartup()
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
    if (saveRAM[32] == 0) {
        saveRAM[33] = 100;
        saveRAM[34] = 100;
        saveRAM[35] = 0;
    }
    GVar("Options.OriginalControls") = saveRAM[35];
    AddSpriteFrame(4, 2, 32, 32, 479, 34);
    AddSpriteFrame(4, 2, 32, 32, 479, 34);
    AddSpriteFrame(4, 2, 32, 32, 479, 34);
    AddSpriteFrame(4, 2, 32, 32, 479, 34);
    AddSpriteFrame(0, 0, 20, 20, 168, 366);
    AddSpriteFrame(0, 0, 20, 20, 168, 387);
    AddSpriteFrame(0, 0, 20, 20, 189, 366);
    AddSpriteFrame(0, 0, 20, 20, 189, 387);
    AddSpriteFrame(45, 12, 13, 13, 488, 1);
    AddSpriteFrame(0, 0, 250, 37, 259, 421);
    if (GVar("Options.DevMenuFlag") == 1) {
        AddSpriteFrame(64, 12, 66, 16, 259, 598);
    } else {
        AddSpriteFrame(64, 12, 128, 16, 1, 188);
    }
    AddSpriteFrame(64, 12, 128, 16, 1, 205);
    AddSpriteFrame(64, 12, 128, 16, 1, 222);
    AddSpriteFrame(64, 12, 128, 16, 1, 239);
    if (GVar("Options.DevMenuFlag") == 1) {
        AddSpriteFrame(64, 12, 66, 16, 326, 598);
    } else {
        AddSpriteFrame(64, 12, 128, 16, 130, 188);
    }
    AddSpriteFrame(64, 12, 128, 16, 130, 205);
    AddSpriteFrame(64, 12, 128, 16, 130, 222);
    AddSpriteFrame(64, 12, 128, 16, 130, 239);
    AddSpriteFrame(0, 0, 38, 20, 171, 324);
    AddSpriteFrame(0, 0, 4, 20, 171, 345);
    AddSpriteFrame(0, 0, 8, 20, 171, 345);
    AddSpriteFrame(0, 0, 12, 20, 171, 345);
    AddSpriteFrame(0, 0, 16, 20, 171, 345);
    AddSpriteFrame(0, 0, 20, 20, 171, 345);
    AddSpriteFrame(0, 0, 24, 20, 171, 345);
    AddSpriteFrame(0, 0, 28, 20, 171, 345);
    AddSpriteFrame(0, 0, 32, 20, 171, 345);
    AddSpriteFrame(0, 0, 36, 20, 171, 345);
    AddSpriteFrame(0, 0, 38, 20, 171, 345);
    AddSpriteFrame(0, 0, 48, 48, 210, 324);
    AddSpriteFrame(0, 0, 48, 48, 210, 373);
    AddSpriteFrame(0, 0, 128, 16, 1, 256);
    AddSpriteFrame(0, 0, 128, 16, 130, 256);
    AddSpriteFrame(0, 0, 128, 16, 1, 273);
    AddSpriteFrame(0, 0, 128, 16, 130, 273);
    AddSpriteFrame(0, 0, 128, 16, 1, 307);
    AddSpriteFrame(0, 0, 128, 16, 130, 307);
    AddSpriteFrame(0, 0, 88, 8, 259, 44);
    AddSpriteFrame(0, 0, 88, 8, 259, 35);
    AddSpriteFrame(0, 0, 48, 48, 405, 88);
    AddSpriteFrame(0, 0, 48, 48, 119, 324);
    AddSpriteFrame(0, 0, 48, 48, 119, 373);
}

void O_Menu_OptionsMenu::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->XPos = SCREEN_CENTERX;
        self->XPos -= 126;
        if (self->values[0] < 256) {
            self->alpha = self->values[0];
            self->values[0] += 6;
        } else {
            self->values[0] = 0;
            self->alpha = 255;
            self->state++;
        }
        break;
        case 1:
        CheckResult() = 1;
        if (CheckResult() == 1) {
            if (keyPress.up == 1) {
                self->values[1]--;
                if (self->values[1] < 0) {
                    self->values[1] = 3;
                }
                PlaySfx(23, 0);
            }
            if (keyPress.down == 1) {
                self->values[1]++;
                if (self->values[1] > 3) {
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
            scriptEng.tempValue[0] = 0;
            CallScriptFunctionNamed("LoadSaveMenu_CheckTouchSave", scriptSub);
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
            scriptEng.tempValue[0] = 1;
            CallScriptFunctionNamed("LoadSaveMenu_CheckTouchSave", scriptSub);
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
            scriptEng.tempValue[0] = 2;
            CallScriptFunctionNamed("LoadSaveMenu_CheckTouchSave", scriptSub);
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
            scriptEng.tempValue[0] = 3;
            CallScriptFunctionNamed("LoadSaveMenu_CheckTouchSave", scriptSub);
            if (CheckResult() > -1) {
                self->values[1] = 3;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 3) {
                        keyPress.start = 1;
                    }
                } else {
                    if (self->values[1] == 3) {
                        self->values[1] = -1;
                    }
                }
            }
            CallScriptFunctionNamed("MenuHeading_CheckTouchBack", scriptSub);
            if (keyPress.up == 1) {
                self->values[1] = 3;
            }
            if (keyPress.down == 1) {
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
            if (self->values[1] < 4) {
                scriptEng.arrayPosition[0] = self->values[1];
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 1;
                self->state++;
                switch (self->values[1]) {
                    case 0:
                    StopMusic();
                    break;
                    case 1:
                    break;
                    case 2:
                    StopMusic();
                    break;
                    case 3:
                    break;
                }
                PlaySfx(27, 0);
            }
        }
        if (keyPress.B == 1) {
            self->values[0] = 248;
            self->state = 11;
            PlaySfx(globalSFXCount + 1, 0);
        }
        break;
        case 2:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            scriptEng.arrayPosition[0] = self->values[1];
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 0;
            switch (self->values[1]) {
                case 0:
                self->state = 3;
                break;
                case 1:
                CheckResult() = ReadSaveRAMData();
                if (saveRAM[32] == 0) {
                    saveRAM[33] = 100;
                    saveRAM[34] = 100;
                    saveRAM[35] = 0;
                }
                self->state = 4;
                self->YPos = 40;
                self->YPos *= self->values[1];
                self->YPos += SCREEN_CENTERY;
                self->YPos -= 87;
                break;
                case 2:
                self->state = 3;
                break;
                case 3:
                self->state = 12;
                self->YPos = 40;
                self->YPos *= self->values[1];
                self->YPos += SCREEN_CENTERY;
                self->YPos -= 87;
                break;
            }
        }
        break;
        case 3:
        if (self->values[0] < 320) {
            self->values[0] += 8;
        } else {
            switch (self->values[1]) {
                case 0:
                if (GVar("Options.DevMenuFlag") == 1) {
                    Engine.gameMode = 2;
                } else {
                    stageListPosition = 6;
                    stageMode = STAGEMODE_LOAD;
                }
                break;
                case 2:
                stageListPosition = 7;
                stageMode = STAGEMODE_LOAD;
                break;
                case 3:
                Engine.gameMode = 2;
                break;
            }
        }
        scriptEng.tempValue[0] = self->values[0];
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        SetFade(0, 0, 0, scriptEng.tempValue[0]);
        break;
        case 4:
        scriptEng.tempValue[0] = SCREEN_CENTERY;
        scriptEng.tempValue[0] -= 87;
        if (self->YPos > scriptEng.tempValue[0]) {
            self->YPos -= 8;
            if (self->YPos < scriptEng.tempValue[0]) {
                self->YPos = scriptEng.tempValue[0];
            }
        } else {
            self->state++;
            self->alpha = 0;
            objectEntityList[objectLoop + 4].values[1] = 0;
        }
        break;
        case 5:
        if (self->values[0] < 256) {
            self->alpha = self->values[0];
            self->values[0] += 8;
        } else {
            self->values[0] = 0;
            self->alpha = 255;
            self->state++;
        }
        break;
        case 6:
        scriptEng.arrayPosition[0] = self->values[1];
        CheckResult() = 1;
        if (CheckResult() == 1) {
            if (keyPress.up == 1) {
                objectEntityList[objectLoop + 4].values[1]--;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + 4].values[1] < 0) {
                    objectEntityList[objectLoop + 4].values[1] = 2;
                }
            }
            if (keyPress.down == 1) {
                objectEntityList[objectLoop + 4].values[1]++;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + 4].values[1] > 2) {
                    objectEntityList[objectLoop + 4].values[1] = 0;
                }
            }
            switch (objectEntityList[objectLoop + 4].values[1]) {
                case 0:
                if (keyPress.left == 1) {
                    self->values[3] = 10;
                    saveRAM[33] -= 10;
                    if (saveRAM[33] < 0) {
                        saveRAM[33] = 0;
                        bgmVolume = saveRAM[33];
                    } else {
                        bgmVolume = saveRAM[33];
                        PlaySfx(23, 0);
                    }
                }
                if (keyPress.right == 1) {
                    self->values[4] = 10;
                    saveRAM[33] += 10;
                    if (saveRAM[33] > 100) {
                        saveRAM[33] = 100;
                        bgmVolume = saveRAM[33];
                    } else {
                        bgmVolume = saveRAM[33];
                        PlaySfx(23, 0);
                    }
                }
                break;
                case 1:
                if (keyPress.left == 1) {
                    self->values[5] = 10;
                    saveRAM[34] -= 10;
                    if (saveRAM[34] < 0) {
                        saveRAM[34] = 0;
                        sfxVolume = saveRAM[34];
                    } else {
                        PlaySfx(23, 0);
                        sfxVolume = saveRAM[34];
                    }
                }
                if (keyPress.right == 1) {
                    self->values[6] = 10;
                    saveRAM[34] += 10;
                    if (saveRAM[34] > 100) {
                        saveRAM[34] = 100;
                    } else {
                        PlaySfx(23, 0);
                        sfxVolume = saveRAM[34];
                    }
                }
                break;
                case 2:
                if (keyPress.left == 1) {
                    saveRAM[35]--;
                    if (saveRAM[35] < 0) {
                        saveRAM[35] = 1;
                    }
                    PlaySfx(23, 0);
                }
                if (keyPress.right == 1) {
                    saveRAM[35]++;
                    if (saveRAM[35] > 1) {
                        saveRAM[35] = 0;
                    }
                    PlaySfx(23, 0);
                }
                break;
            }
        }
        if (keyPress.B == 1) {
            self->state = 9;
            self->values[0] = 248;
            GVar("Options.OriginalControls") = saveRAM[35];
            saveRAM[32] = 1;
            CheckResult() = WriteSaveRAMData();
            PlaySfx(globalSFXCount + 1, 0);
        }
        break;
        case 7:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 8:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            self->state = 1;
            PlayMusic(0);
        }
        scriptEng.tempValue[0] = self->values[0];
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        SetFade(0, 0, 0, scriptEng.tempValue[0]);
        break;
        case 9:
        if (self->values[0] > 0) {
            self->alpha = self->values[0];
            self->values[0] -= 8;
        } else {
            self->alpha = 0;
            self->state++;
        }
        break;
        case 10:
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] *= 40;
        scriptEng.tempValue[0] += SCREEN_CENTERY;
        scriptEng.tempValue[0] -= 87;
        if (self->YPos < scriptEng.tempValue[0]) {
            self->YPos += 8;
            if (self->YPos > scriptEng.tempValue[0]) {
                self->YPos = scriptEng.tempValue[0];
            }
            self->alpha = 0;
        } else {
            self->state = 1;
            self->alpha = 255;
        }
        break;
        case 11:
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
        case 12:
        scriptEng.tempValue[0] = SCREEN_CENTERY;
        scriptEng.tempValue[0] -= 87;
        if (self->YPos > scriptEng.tempValue[0]) {
            self->YPos -= 8;
            if (self->YPos < scriptEng.tempValue[0]) {
                self->YPos = scriptEng.tempValue[0];
            }
        } else {
            scriptEng.tempValue[0] = objectLoop;
            scriptEng.tempValue[0] += 10;
            ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("About Menu"), 0, 0, 0);
            SetupMenu_Script(0, 0, 3, 1);
            GetVersionNumber_Script(0, 1);
            objectEntityList[objectLoop + 10].inkEffect = 2;
            self->state++;
            self->alpha = 0;
            objectEntityList[objectLoop + 4].values[1] = 0;
        }
        break;
        case 13:
        if (self->values[0] < 256) {
            self->alpha = self->values[0];
            self->values[0] += 8;
        } else {
            self->values[0] = 0;
            self->alpha = 255;
            self->state++;
        }
        break;
        case 14:
        if (keyPress.B == 1) {
            self->state = 15;
            self->values[0] = 248;
            PlaySfx(globalSFXCount + 1, 0);
        }
        break;
        case 15:
        if (self->values[0] > 0) {
            self->alpha = self->values[0];
            self->values[0] -= 8;
        } else {
            self->alpha = 0;
            self->state = 10;
            objectEntityList[objectLoop + 10].type = TypeNameID("Blank Object");
        }
        break;
        case 16:
        self->values[0] += 4;
        if (self->values[0] == 384) {
            activeStageList = 0;
            stageListPosition = 0;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 17:
        self->values[0] += 4;
        if (self->values[0] == 384) {
            activeStageList = 0;
            stageListPosition = 0;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
    }
}

void O_Menu_OptionsMenu::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 8:
        case 11:
        case 16:
        self->YPos = SCREEN_CENTERY;
        self->YPos -= 87;
        scriptEng.arrayPosition[0] = 0;
        OptionsMenu_DrawOptions();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        OptionsMenu_DrawOptions();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        OptionsMenu_DrawOptions();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        OptionsMenu_DrawOptions();
        break;
        case 4:
        case 12:
        scriptEng.arrayPosition[0] = self->values[1];
        OptionsMenu_DrawOptions();
        break;
        case 5:
        case 6:
        case 9:
        case 10:
        case 17:
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] += 15;
        if (objectEntityList[objectLoop + 4].values[1] == 7) {
            DrawSpriteScreenFX_Script(40, FX_INK, scriptEng.tempValue[0], 134);
        } else {
            DrawSpriteScreenFX_Script(29, FX_INK, scriptEng.tempValue[0], 134);
        }
        scriptEng.tempValue[0] += 52;
        if (objectEntityList[objectLoop + 4].values[1] == 8) {
            DrawSpriteScreenFX_Script(41, FX_INK, scriptEng.tempValue[0], 134);
        } else {
            DrawSpriteScreenFX_Script(30, FX_INK, scriptEng.tempValue[0], 134);
        }
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 117;
        CheckResult() = 1;
        if (CheckResult() == 1) {
            switch (objectEntityList[objectLoop + 4].values[1]) {
                case 0:
                DrawSpriteScreenFX_Script(32, FX_INK, scriptEng.tempValue[0], 81);
                DrawSpriteScreenFX_Script(33, FX_INK, scriptEng.tempValue[0], 110);
                DrawSpriteScreenFX_Script(35, FX_INK, scriptEng.tempValue[0], 151);
                break;
                case 1:
                DrawSpriteScreenFX_Script(31, FX_INK, scriptEng.tempValue[0], 81);
                DrawSpriteScreenFX_Script(34, FX_INK, scriptEng.tempValue[0], 110);
                DrawSpriteScreenFX_Script(35, FX_INK, scriptEng.tempValue[0], 151);
                break;
                case 2:
                DrawSpriteScreenFX_Script(31, FX_INK, scriptEng.tempValue[0], 81);
                DrawSpriteScreenFX_Script(33, FX_INK, scriptEng.tempValue[0], 110);
                DrawSpriteScreenFX_Script(36, FX_INK, scriptEng.tempValue[0], 151);
                break;
            }
        } else {
            DrawSpriteScreenFX_Script(31, FX_INK, scriptEng.tempValue[0], 81);
            DrawSpriteScreenFX_Script(33, FX_INK, scriptEng.tempValue[0], 110);
            DrawSpriteScreenFX_Script(35, FX_INK, scriptEng.tempValue[0], 151);
        }
        if (saveRAM[35] == 0) {
            DrawSpriteScreenFX_Script(37, FX_INK, scriptEng.tempValue[0], 169);
            scriptEng.tempValue[0] += 132;
            DrawSpriteScreenFX_Script(39, FX_INK, scriptEng.tempValue[0], 134);
        } else {
            DrawSpriteScreenFX_Script(38, FX_INK, scriptEng.tempValue[0], 169);
            scriptEng.tempValue[0] += 184;
            DrawSpriteScreenFX_Script(39, FX_INK, scriptEng.tempValue[0], 134);
        }
        scriptEng.tempValue[1] = SCREEN_CENTERX;
        scriptEng.tempValue[1] += 23;
        if (self->values[3] > 0) {
            self->values[3]--;
            DrawSpriteScreenFX_Script(5, FX_INK, scriptEng.tempValue[1], 76);
        } else {
            DrawSpriteScreenFX_Script(4, FX_INK, scriptEng.tempValue[1], 76);
        }
        scriptEng.tempValue[1] += 66;
        if (self->values[4] > 0) {
            self->values[4]--;
            DrawSpriteScreenFX_Script(7, FX_INK, scriptEng.tempValue[1], 76);
        } else {
            DrawSpriteScreenFX_Script(6, FX_INK, scriptEng.tempValue[1], 76);
        }
        scriptEng.tempValue[1] -= 42;
        DrawSpriteScreenFX_Script(18, FX_INK, scriptEng.tempValue[1], 76);
        scriptEng.tempValue[0] = saveRAM[33];
        scriptEng.tempValue[0] /= 10;
        scriptEng.tempValue[0] += 18;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, scriptEng.tempValue[1], 76);
        scriptEng.tempValue[1] = SCREEN_CENTERX;
        scriptEng.tempValue[1] += 23;
        if (self->values[5] > 0) {
            self->values[5]--;
            DrawSpriteScreenFX_Script(5, FX_INK, scriptEng.tempValue[1], 105);
        } else {
            DrawSpriteScreenFX_Script(4, FX_INK, scriptEng.tempValue[1], 105);
        }
        scriptEng.tempValue[1] += 66;
        if (self->values[6] > 0) {
            self->values[6]--;
            DrawSpriteScreenFX_Script(7, FX_INK, scriptEng.tempValue[1], 105);
        } else {
            DrawSpriteScreenFX_Script(6, FX_INK, scriptEng.tempValue[1], 105);
        }
        scriptEng.tempValue[1] -= 42;
        DrawSpriteScreenFX_Script(18, FX_INK, scriptEng.tempValue[1], 105);
        scriptEng.tempValue[0] = saveRAM[34];
        scriptEng.tempValue[0] /= 10;
        scriptEng.tempValue[0] += 18;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, scriptEng.tempValue[1], 105);
        self->alpha = 255;
        OptionsMenu_DrawOptions();
        break;
        case 13:
        case 14:
        case 15:
        scriptEng.arrayPosition[0] = self->values[1];
        self->alpha = 255;
        OptionsMenu_DrawOptions();
        break;
    }
}

void O_Menu_OptionsMenu::OptionsMenu_DrawOptions()
{
    Entity *self = Self();

    switch (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2]) {
        case 0:
        if (scriptEng.arrayPosition[0] == self->values[1]) {
            DrawSpriteScreenFX_Script(9, FX_INK, self->XPos, self->YPos);
            scriptEng.tempValue[0] = scriptEng.arrayPosition[0];
            scriptEng.tempValue[0] += 14;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, self->YPos);
        } else {
            scriptEng.tempValue[0] = scriptEng.arrayPosition[0];
            scriptEng.tempValue[0] += 10;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, self->YPos);
        }
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        DrawSpriteScreenFX_Script(9, FX_INK, self->XPos, self->YPos);
        if (scriptEng.tempValue[0] == 0) {
            scriptEng.tempValue[0] = scriptEng.arrayPosition[0];
            scriptEng.tempValue[0] += 14;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, self->YPos);
        }
        break;
    }
    DrawSpriteScreenFX_Script(8, FX_INK, self->XPos, self->YPos);
    DrawSpriteScreenFX_Script(scriptEng.arrayPosition[0], FX_INK, self->XPos, self->YPos);
}

const Native::NativeFunctionDef O_Menu_OptionsMenu::funcs[1] = {
    { "OptionsMenu_DrawOptions", O_Menu_OptionsMenu::OptionsMenu_DrawOptions },
};

#endif // RETRO_USE_NATIVE_OBJECTS
