#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_ExtrasMenu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ExtrasMenu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_ExtrasMenu::ObjectStartup()
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
    AddSpriteFrame(4, 2, 32, 32, 479, 34);
    AddSpriteFrame(4, 2, 32, 32, 479, 359);
    AddSpriteFrame(4, 2, 32, 32, 479, 34);
    AddSpriteFrame(4, 2, 32, 32, 479, 34);
    AddSpriteFrame(-18, -18, 36, 36, 476, 106);
    AddSpriteFrame(-18, -18, 36, 36, 476, 143);
    AddSpriteFrame(-18, -18, 36, 36, 476, 285);
    AddSpriteFrame(-18, -18, 36, 36, 476, 322);
    AddSpriteFrame(45, 12, 13, 13, 488, 1);
    AddSpriteFrame(0, 0, 250, 37, 259, 421);
    scriptEng.arrayPosition[0] = 32;
    scriptEng.arrayPosition[1] = 48;
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 0;
    while (scriptEng.arrayPosition[0] < 39) {
        scriptEng.tempValue[0] += saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1]++;
        scriptEng.tempValue[1] += saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1] += 5;
        scriptEng.tempValue[0] += saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1] += 6;
        scriptEng.tempValue[0] += saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1] += 6;
        scriptEng.arrayPosition[0]++;
    }
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = 400000;
        scriptEng.tempValue[1] = 400000;
    }
    if (scriptEng.tempValue[0] < 224757) {
        AddSpriteFrame(64, 12, 128, 16, 1, 120);
        GVar("Options.DAGardenFlag") = 1;
    } else {
        AddSpriteFrame(64, 12, 128, 16, 1, 426);
    }
    if (scriptEng.tempValue[0] < 154612) {
        AddSpriteFrame(64, 12, 128, 16, 1, 137);
        GVar("Options.VisualModeFlag") = 1;
    } else {
        AddSpriteFrame(64, 12, 128, 16, 130, 426);
    }
    if (scriptEng.tempValue[1] < 24207) {
        AddSpriteFrame(64, 12, 128, 16, 1, 154);
        GVar("Options.SoundTestFlag") = 1;
    } else {
        AddSpriteFrame(64, 12, 48, 16, 404, 285);
    }
    if (scriptEng.tempValue[1] < 30125) {
        AddSpriteFrame(64, 12, 128, 16, 1, 171);
        GVar("Options.StageSelectFlag") = 1;
    } else {
        AddSpriteFrame(64, 12, 48, 16, 404, 285);
    }
    if (scriptEng.tempValue[0] < 224757) {
        AddSpriteFrame(64, 12, 128, 16, 130, 120);
    } else {
        AddSpriteFrame(64, 12, 128, 16, 1, 426);
    }
    if (scriptEng.tempValue[0] < 154612) {
        AddSpriteFrame(64, 12, 128, 16, 130, 137);
    } else {
        AddSpriteFrame(64, 12, 128, 16, 130, 426);
    }
    if (scriptEng.tempValue[1] < 24207) {
        AddSpriteFrame(64, 12, 128, 16, 130, 154);
    } else {
        AddSpriteFrame(64, 12, 48, 16, 404, 285);
    }
    if (scriptEng.tempValue[1] < 30125) {
        AddSpriteFrame(64, 12, 128, 16, 130, 171);
    } else {
        AddSpriteFrame(64, 12, 48, 16, 404, 285);
    }
    AddSpriteFrame(-48, 25, 96, 8, 1, 496);
    AddSpriteFrame(-48, 25, 96, 8, 1, 504);
    AddSpriteFrame(-48, 25, 96, 8, 98, 496);
    AddSpriteFrame(-48, 25, 96, 8, 98, 504);
    AddSpriteFrame(-48, 25, 96, 8, 195, 496);
    AddSpriteFrame(-48, 25, 96, 8, 195, 504);
    AddSpriteFrame(-48, 25, 96, 8, 292, 496);
    AddSpriteFrame(-48, 25, 96, 8, 292, 504);
    AddSpriteFrame(-24, -24, 48, 48, 405, 88);
}

void O_Menu_ExtrasMenu::ObjectMain()
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
                switch (self->values[1]) {
                    case 0:
                    if (GVar("Options.DAGardenFlag") == 1) {
                        scriptEng.arrayPosition[0] = self->values[1];
                        objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 1;
                        self->state++;
                        StopMusic();
                        PlaySfx(27, 0);
                    } else {
                    }
                    break;
                    case 1:
                    if (GVar("Options.VisualModeFlag") == 1) {
                        scriptEng.arrayPosition[0] = self->values[1];
                        objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 1;
                        self->state++;
                        PlaySfx(27, 0);
                    } else {
                    }
                    break;
                    case 2:
                    if (GVar("Options.SoundTestFlag") == 1) {
                        scriptEng.arrayPosition[0] = self->values[1];
                        objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 1;
                        self->state++;
                        StopMusic();
                        PlaySfx(27, 0);
                    } else {
                    }
                    break;
                    case 3:
                    if (GVar("Options.StageSelectFlag") == 1) {
                        scriptEng.arrayPosition[0] = self->values[1];
                        objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 1;
                        self->state++;
                        StopMusic();
                        PlaySfx(27, 0);
                    } else {
                    }
                    break;
                }
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
                self->state = 3;
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
                stageListPosition = 5;
                stageMode = STAGEMODE_LOAD;
                break;
                case 2:
                stageListPosition = 4;
                stageMode = STAGEMODE_LOAD;
                break;
                case 3:
                stageListPosition = 3;
                stageMode = STAGEMODE_LOAD;
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
            if (keyPress.left == 1) {
                objectEntityList[objectLoop + 4].values[1]--;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + 4].values[1] < 0) {
                    objectEntityList[objectLoop + 4].values[1] = 3;
                }
            }
            if (keyPress.right == 1) {
                objectEntityList[objectLoop + 4].values[1]++;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + 4].values[1] > 3) {
                    objectEntityList[objectLoop + 4].values[1] = 0;
                }
            }
            if (keyPress.up == 1) {
                objectEntityList[objectLoop + 4].values[1] -= 2;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + 4].values[1] < 0) {
                    objectEntityList[objectLoop + 4].values[1] += 4;
                }
            }
            if (keyPress.down == 1) {
                objectEntityList[objectLoop + 4].values[1] += 2;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + 4].values[1] > 3) {
                    objectEntityList[objectLoop + 4].values[1] -= 4;
                }
            }
        }
        CheckResult() = 0;
        if (objectEntityList[objectLoop + 4].values[1] > -1) {
            if (keyPress.start == 1) {
                CheckResult() = 1;
            }
            if (keyPress.A == 1) {
                CheckResult() = 1;
            }
        }
        if (CheckResult() == 1) {
            PlaySfx(27, 0);
            StopMusic();
            self->state++;
        }
        if (keyPress.B == 1) {
            self->state = 9;
            self->values[0] = 248;
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
        if (self->values[0] < 384) {
            self->values[0] += 8;
        } else {
            switch (objectEntityList[objectLoop + 4].values[1]) {
                case 0:
                LoadVideo_Script("Opening");
                break;
                case 1:
                LoadVideo_Script("Pencil_Test");
                break;
                case 2:
                LoadVideo_Script("Good_Ending");
                break;
                case 3:
                LoadVideo_Script("Bad_Ending");
                break;
            }
            self->state = 12;
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
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            self->state = 6;
            PlayMusic(GVar("Options.Soundtrack"));
        }
        scriptEng.tempValue[0] = self->values[0];
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        SetFade(0, 0, 0, scriptEng.tempValue[0]);
        break;
    }
}

void O_Menu_ExtrasMenu::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 11:
        self->YPos = SCREEN_CENTERY;
        self->YPos -= 87;
        scriptEng.arrayPosition[0] = 0;
        ExtrasMenu_DrawUnlocks();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        ExtrasMenu_DrawUnlocks();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        ExtrasMenu_DrawUnlocks();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        ExtrasMenu_DrawUnlocks();
        break;
        case 4:
        scriptEng.arrayPosition[0] = self->values[1];
        ExtrasMenu_DrawUnlocks();
        break;
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
        case 12:
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 64;
        DrawSpriteScreenFX_Script(4, FX_INK, scriptEng.tempValue[0], 96);
        if (objectEntityList[objectLoop + 4].values[1] == 0) {
            DrawSpriteScreenFX_Script(26, FX_INK, scriptEng.tempValue[0], 96);
            DrawSpriteScreenFX_Script(22, FX_INK, scriptEng.tempValue[0], 96);
        } else {
            DrawSpriteScreenFX_Script(18, FX_INK, scriptEng.tempValue[0], 96);
        }
        DrawSpriteScreenFX_Script(6, FX_INK, scriptEng.tempValue[0], 153);
        if (objectEntityList[objectLoop + 4].values[1] == 2) {
            DrawSpriteScreenFX_Script(26, FX_INK, scriptEng.tempValue[0], 153);
            DrawSpriteScreenFX_Script(24, FX_INK, scriptEng.tempValue[0], 153);
        } else {
            DrawSpriteScreenFX_Script(20, FX_INK, scriptEng.tempValue[0], 153);
        }
        scriptEng.tempValue[0] += 128;
        DrawSpriteScreenFX_Script(5, FX_INK, scriptEng.tempValue[0], 96);
        if (objectEntityList[objectLoop + 4].values[1] == 1) {
            DrawSpriteScreenFX_Script(26, FX_INK, scriptEng.tempValue[0], 96);
            DrawSpriteScreenFX_Script(23, FX_INK, scriptEng.tempValue[0], 96);
        } else {
            DrawSpriteScreenFX_Script(19, FX_INK, scriptEng.tempValue[0], 96);
        }
        DrawSpriteScreenFX_Script(7, FX_INK, scriptEng.tempValue[0], 153);
        if (objectEntityList[objectLoop + 4].values[1] == 3) {
            DrawSpriteScreenFX_Script(26, FX_INK, scriptEng.tempValue[0], 153);
            DrawSpriteScreenFX_Script(25, FX_INK, scriptEng.tempValue[0], 153);
        } else {
            DrawSpriteScreenFX_Script(21, FX_INK, scriptEng.tempValue[0], 153);
        }
        self->alpha = 255;
        ExtrasMenu_DrawUnlocks();
        break;
        case 7:
        scriptEng.tempValue[1] = self->values[0];
        scriptEng.tempValue[1] &= 3;
        scriptEng.tempValue[1] >>= 1;
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 64;
        if (objectEntityList[objectLoop + 4].values[1] == 0) {
            if (scriptEng.tempValue[1] == 0) {
                DrawSpriteScreenFX_Script(4, FX_INK, scriptEng.tempValue[0], 96);
                DrawSpriteScreenFX_Script(26, FX_INK, scriptEng.tempValue[0], 96);
            }
            DrawSpriteScreenFX_Script(22, FX_INK, scriptEng.tempValue[0], 96);
        } else {
            DrawSpriteScreenFX_Script(4, FX_INK, scriptEng.tempValue[0], 96);
            DrawSpriteScreenFX_Script(18, FX_INK, scriptEng.tempValue[0], 96);
        }
        if (objectEntityList[objectLoop + 4].values[1] == 2) {
            if (scriptEng.tempValue[1] == 0) {
                DrawSpriteScreenFX_Script(6, FX_INK, scriptEng.tempValue[0], 153);
                DrawSpriteScreenFX_Script(26, FX_INK, scriptEng.tempValue[0], 153);
            }
            DrawSpriteScreenFX_Script(24, FX_INK, scriptEng.tempValue[0], 153);
        } else {
            DrawSpriteScreenFX_Script(6, FX_INK, scriptEng.tempValue[0], 153);
            DrawSpriteScreenFX_Script(20, FX_INK, scriptEng.tempValue[0], 153);
        }
        scriptEng.tempValue[0] += 128;
        if (objectEntityList[objectLoop + 4].values[1] == 1) {
            if (scriptEng.tempValue[1] == 0) {
                DrawSpriteScreenFX_Script(5, FX_INK, scriptEng.tempValue[0], 96);
                DrawSpriteScreenFX_Script(26, FX_INK, scriptEng.tempValue[0], 96);
            }
            DrawSpriteScreenFX_Script(23, FX_INK, scriptEng.tempValue[0], 96);
        } else {
            DrawSpriteScreenFX_Script(5, FX_INK, scriptEng.tempValue[0], 96);
            DrawSpriteScreenFX_Script(19, FX_INK, scriptEng.tempValue[0], 96);
        }
        if (objectEntityList[objectLoop + 4].values[1] == 3) {
            if (scriptEng.tempValue[1] == 0) {
                DrawSpriteScreenFX_Script(7, FX_INK, scriptEng.tempValue[0], 153);
                DrawSpriteScreenFX_Script(26, FX_INK, scriptEng.tempValue[0], 153);
            }
            DrawSpriteScreenFX_Script(25, FX_INK, scriptEng.tempValue[0], 153);
        } else {
            DrawSpriteScreenFX_Script(7, FX_INK, scriptEng.tempValue[0], 153);
            DrawSpriteScreenFX_Script(21, FX_INK, scriptEng.tempValue[0], 153);
        }
        self->alpha = 255;
        ExtrasMenu_DrawUnlocks();
        break;
    }
}

void O_Menu_ExtrasMenu::ExtrasMenu_DrawUnlocks()
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
    switch (scriptEng.arrayPosition[0]) {
        case 0:
        if (GVar("Options.DAGardenFlag") == 1) {
            DrawSpriteScreenFX_Script(0, FX_INK, self->XPos, self->YPos);
        } else {
            DrawSpriteScreenFX_Script(1, FX_INK, self->XPos, self->YPos);
        }
        break;
        case 1:
        if (GVar("Options.VisualModeFlag") == 1) {
            DrawSpriteScreenFX_Script(0, FX_INK, self->XPos, self->YPos);
        } else {
            DrawSpriteScreenFX_Script(1, FX_INK, self->XPos, self->YPos);
        }
        break;
        case 2:
        if (GVar("Options.SoundTestFlag") == 1) {
            DrawSpriteScreenFX_Script(0, FX_INK, self->XPos, self->YPos);
        } else {
            DrawSpriteScreenFX_Script(1, FX_INK, self->XPos, self->YPos);
        }
        break;
        case 3:
        if (GVar("Options.StageSelectFlag") == 1) {
            DrawSpriteScreenFX_Script(0, FX_INK, self->XPos, self->YPos);
        } else {
            DrawSpriteScreenFX_Script(1, FX_INK, self->XPos, self->YPos);
        }
        break;
    }
}

const Native::NativeFunctionDef O_Menu_ExtrasMenu::funcs[1] = {
    { "ExtrasMenu_DrawUnlocks", O_Menu_ExtrasMenu::ExtrasMenu_DrawUnlocks },
};

#endif // RETRO_USE_NATIVE_OBJECTS
