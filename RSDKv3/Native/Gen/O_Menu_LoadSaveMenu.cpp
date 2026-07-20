#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_LoadSaveMenu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LoadSaveMenu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_LoadSaveMenu::ObjectStartup()
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
    AddSpriteFrame(4, 2, 32, 32, 389, 1);
    AddSpriteFrame(4, 2, 32, 32, 422, 1);
    AddSpriteFrame(4, 2, 32, 32, 455, 1);
    AddSpriteFrame(4, 2, 32, 32, 446, 34);
    AddSpriteFrame(3, 2, 40, 32, 259, 1);
    AddSpriteFrame(3, 2, 64, 32, 259, 1);
    AddSpriteFrame(3, 2, 40, 32, 324, 1);
    AddSpriteFrame(3, 2, 64, 32, 324, 1);
    AddSpriteFrame(45, 12, 13, 13, 488, 1);
    AddSpriteFrame(0, 0, 250, 37, 259, 421);
    AddSpriteFrame(64, 12, 128, 16, 1, 1);
    AddSpriteFrame(64, 12, 144, 16, 259, 93);
    AddSpriteFrame(64, 12, 144, 16, 259, 110);
    AddSpriteFrame(64, 12, 144, 16, 259, 127);
    AddSpriteFrame(64, 12, 144, 16, 259, 144);
    AddSpriteFrame(64, 12, 144, 16, 259, 161);
    AddSpriteFrame(64, 12, 144, 16, 259, 178);
    AddSpriteFrame(64, 12, 144, 16, 259, 195);
    AddSpriteFrame(64, 12, 144, 16, 259, 212);
    AddSpriteFrame(64, 12, 144, 16, 259, 229);
    AddSpriteFrame(64, 12, 128, 16, 130, 1);
    AddSpriteFrame(64, 12, 144, 16, 259, 268);
    AddSpriteFrame(64, 12, 144, 16, 259, 285);
    AddSpriteFrame(64, 12, 144, 16, 259, 302);
    AddSpriteFrame(64, 12, 144, 16, 259, 319);
    AddSpriteFrame(64, 12, 144, 16, 259, 336);
    AddSpriteFrame(64, 12, 144, 16, 259, 353);
    AddSpriteFrame(64, 12, 144, 16, 259, 370);
    AddSpriteFrame(64, 12, 144, 16, 259, 387);
    AddSpriteFrame(64, 12, 144, 16, 259, 404);
    CheckResult() = ReadSaveRAMData();
    GVar("Options.Soundtrack") = saveRAM[38];
    if (saveRAM[36] == 1) {
        GVar("Options.TailsUnlocked") = 1;
    }
    AddSpriteFrame(-112, 0, 224, 16, 1, 477);
    AddSpriteFrame(-16, -20, 32, 40, 26, 357);
    if (GVar("Options.TailsUnlocked") == 1) {
        AddSpriteFrame(-16, -12, 32, 32, 59, 365);
    } else {
        AddSpriteFrame(-16, -12, 32, 32, 72, 332);
    }
    AddSpriteFrame(-24, -24, 48, 48, 405, 88);
    AddSpriteFrame(-14, 0, 27, 8, 454, 88);
    if (GVar("Options.TailsUnlocked") == 1) {
        AddSpriteFrame(-12, 0, 24, 8, 482, 88);
    } else {
        AddSpriteFrame(-12, 0, 24, 8, 92, 365);
    }
    AddSpriteFrame(-14, 0, 27, 8, 454, 97);
    if (GVar("Options.TailsUnlocked") == 1) {
        AddSpriteFrame(-12, 0, 24, 8, 482, 97);
    } else {
        AddSpriteFrame(-12, 0, 24, 8, 92, 374);
    }
    AddSpriteFrame(224, 7, 8, 8, 404, 137);
    AddSpriteFrame(232, 7, 8, 8, 413, 137);
    AddSpriteFrame(220, 15, 8, 8, 422, 137);
    AddSpriteFrame(228, 15, 8, 8, 431, 137);
    AddSpriteFrame(236, 15, 8, 8, 440, 137);
    AddSpriteFrame(224, 23, 8, 8, 449, 137);
    AddSpriteFrame(232, 23, 8, 8, 458, 137);
    AddSpriteFrame(224, 7, 8, 8, 467, 137);
    AddSpriteFrame(232, 7, 8, 8, 467, 137);
    AddSpriteFrame(220, 15, 8, 8, 467, 137);
    AddSpriteFrame(228, 15, 8, 8, 467, 137);
    AddSpriteFrame(236, 15, 8, 8, 467, 137);
    AddSpriteFrame(224, 23, 8, 8, 467, 137);
    AddSpriteFrame(232, 23, 8, 8, 467, 137);
    AddSpriteFrame(0, 0, 64, 18, 404, 196);
    AddSpriteFrame(0, 0, 64, 18, 404, 215);
    AddSpriteFrame(0, 0, 64, 18, 404, 234);
    AddSpriteFrame(0, 0, 64, 18, 404, 253);
    AddSpriteFrame(0, 0, 250, 37, 259, 459);
    AddSpriteFrame(-112, 0, 224, 16, 1, 443);
    AddSpriteFrame(-112, 0, 224, 16, 1, 460);
    AddSpriteFrame(208, 12, 8, 16, 478, 183);
    AddSpriteFrame(208, 12, 8, 16, 487, 183);
    AddSpriteFrame(208, 12, 8, 16, 496, 183);
    AddSpriteFrame(208, 12, 8, 16, 469, 200);
    AddSpriteFrame(208, 12, 8, 16, 478, 200);
    AddSpriteFrame(208, 12, 8, 16, 487, 200);
    AddSpriteFrame(208, 12, 8, 16, 496, 200);
    AddSpriteFrame(208, 12, 8, 16, 469, 217);
    AddSpriteFrame(208, 12, 8, 16, 478, 234);
    AddSpriteFrame(208, 12, 8, 16, 487, 234);
    AddSpriteFrame(208, 12, 8, 16, 496, 234);
    AddSpriteFrame(208, 12, 8, 16, 469, 251);
    AddSpriteFrame(208, 12, 8, 16, 478, 251);
    AddSpriteFrame(208, 12, 8, 16, 487, 251);
    AddSpriteFrame(208, 12, 8, 16, 496, 251);
    AddSpriteFrame(208, 12, 8, 16, 469, 268);
    AddSpriteFrame(-32, 0, 64, 21, 404, 319);
    AddSpriteFrame(-32, 0, 64, 21, 404, 341);
    AddSpriteFrame(-32, 0, 64, 21, 404, 363);
    AddSpriteFrame(-32, 0, 64, 21, 404, 385);
}

void O_Menu_LoadSaveMenu::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->XPos = SCREEN_CENTERX;
        self->XPos -= 126;
        if (self->values[0] == 0) {
            LoadSaveMenu_SetShowDelete();
            scriptEng.arrayPosition[0] = 0;
            scriptEng.arrayPosition[1] = 0;
            while (scriptEng.arrayPosition[0] < 4) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = saveRAM[scriptEng.arrayPosition[1]];
                scriptEng.arrayPosition[1]++;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[6] = saveRAM[scriptEng.arrayPosition[1]];
                scriptEng.arrayPosition[1]++;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[5] = saveRAM[scriptEng.arrayPosition[1]];
                scriptEng.arrayPosition[1]++;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = saveRAM[scriptEng.arrayPosition[1]];
                scriptEng.arrayPosition[1]++;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[4] = saveRAM[scriptEng.arrayPosition[1]];
                scriptEng.arrayPosition[1]++;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].propertyValue = saveRAM[scriptEng.arrayPosition[1]];
                scriptEng.arrayPosition[1]++;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].scale = saveRAM[scriptEng.arrayPosition[1]];
                scriptEng.arrayPosition[1]++;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[7] = saveRAM[scriptEng.arrayPosition[1]];
                scriptEng.arrayPosition[1]++;
                if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
                    self->direction = 1;
                }
                scriptEng.arrayPosition[0]++;
            }
        }
        objectEntityList[objectLoop + 1].XPos = SCREEN_CENTERX;
        objectEntityList[objectLoop + 1].XPos -= 120;
        objectEntityList[objectLoop + 1].YPos = 32;
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
        if (objectEntityList[objectLoop + 4].rotation == 3) {
            self->animationTimer++;
            self->animationTimer &= 63;
        } else {
            self->animationTimer = 0;
        }
        CheckResult() = 1;
        if (CheckResult() == 1) {
            if (self->direction == 0) {
                if (keyPress.up == 1) {
                    self->values[1]--;
                    PlaySfx(23, 0);
                    if (self->values[1] < 0) {
                        self->values[1] = 3;
                    }
                }
                if (keyPress.down == 1) {
                    self->values[1]++;
                    PlaySfx(23, 0);
                    if (self->values[1] > 3) {
                        self->values[1] = 0;
                    }
                }
            } else {
                if (keyPress.up == 1) {
                    self->values[1]--;
                    PlaySfx(23, 0);
                    if (self->values[1] < 0) {
                        self->values[1] = 4;
                    }
                }
                if (keyPress.down == 1) {
                    self->values[1]++;
                    PlaySfx(23, 0);
                    if (self->values[1] > 4) {
                        self->values[1] = 0;
                    }
                }
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
            }
        } else {
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            scriptEng.tempValue[3] = CheckResult();
            if (self->direction == 1) {
                scriptEng.tempValue[0] = objectEntityList[objectLoop + 1].XPos;
                scriptEng.tempValue[0] -= 4;
                scriptEng.tempValue[1] = scriptEng.tempValue[0];
                scriptEng.tempValue[1] += 72;
                CheckTouchRect_Script(scriptEng.tempValue[0], 0, scriptEng.tempValue[1], 32);
            } else {
                CheckResult() = -1;
            }
            if (CheckResult() > -1) {
                self->values[1] = 4;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 4) {
                        keyPress.start = 1;
                    }
                } else {
                    if (self->values[1] == 4) {
                        self->values[1] = -1;
                    }
                }
            }
            scriptEng.tempValue[0] = 0;
            LoadSaveMenu_CheckTouchSave();
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
            LoadSaveMenu_CheckTouchSave();
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
            LoadSaveMenu_CheckTouchSave();
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
            LoadSaveMenu_CheckTouchSave();
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
                if (self->direction == 0) {
                    self->values[1] = 0;
                } else {
                    self->values[1] = 4;
                }
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
                switch (objectEntityList[objectLoop + 4].rotation) {
                    case 0:
                    self->direction = 0;
                    scriptEng.arrayPosition[0] = self->values[1];
                    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].rotation = 1;
                    self->state = 2;
                    PlaySfx(27, 0);
                    if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
                        StopMusic();
                    } else {
                        if (GVar("Options.TailsUnlocked") == 2) {
                            StopMusic();
                        }
                    }
                    break;
                    case 2:
                    scriptEng.arrayPosition[0] = self->values[1];
                    if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
                        self->direction = 0;
                        self->state = 13;
                        self->rotation = 0;
                        objectEntityList[objectLoop + 1].rotation = 0;
                        objectEntityList[objectLoop + 2].rotation = 0;
                        objectEntityList[objectLoop + 3].rotation = 0;
                        objectEntityList[objectLoop + scriptEng.arrayPosition[0]].rotation = 3;
                        objectEntityList[objectLoop + 4].rotation = 0;
                        PlaySfx(9, 0);
                    } else {
                        self->rotation = 0;
                        objectEntityList[objectLoop + 1].rotation = 0;
                        objectEntityList[objectLoop + 2].rotation = 0;
                        objectEntityList[objectLoop + 3].rotation = 0;
                        objectEntityList[objectLoop + 4].rotation = 0;
                    }
                    break;
                }
            }
            if (self->values[1] == 4) {
                PlaySfx(9, 0);
                self->state = 12;
            }
        }
        if (keyPress.B == 1) {
            self->direction = 0;
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
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].rotation = 0;
            if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
                self->state = 3;
            } else {
                if (GVar("Options.TailsUnlocked") < 2) {
                    self->state = 4;
                    self->YPos = 40;
                    self->YPos *= self->values[1];
                    self->YPos += SCREEN_CENTERY;
                    self->YPos -= 87;
                } else {
                    self->state = 8;
                }
            }
        }
        break;
        case 3:
        if (self->values[0] < 256) {
            self->values[0] += 8;
        } else {
            scriptEng.arrayPosition[0] = self->values[1];
            GVar("Options.GameMode") = 1;
            GVar("Options.SaveSlot") = self->values[1];
            GVar("Player.Lives") = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[6];
            GVar("Player.Score") = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[5];
            GVar("Player.ScoreBonus") = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].scale;
            GVar("Good_Future_List") = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[7];
            GVar("Good_Future_List") &= 0xFFFF;
            GVar("Good_Future_Count") = 0;
            GVar("Good_Future") = 0;
            GVar("MetalSonic_List") = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[7];
            GVar("MetalSonic_List") >>= 16;
            GVar("SpecialStage.TimeStones") = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[4];
            GVar("SpecialStage.ListPos") = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].propertyValue;
            GVar("LampPost.Check") = 0;
            activeStageList = 1;
            stageListPosition = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2];
            stageListPosition--;
            if (stageListPosition < 0) {
                stageListPosition = 0;
                GVar("Player.Lives") = 3;
                GVar("Player.Score") = 0;
            }
            if (stageListPosition >= 80) {
                GVar("SpecialStage.NextZone") = stageListPosition;
                GVar("SpecialStage.NextZone") -= 80;
                activeStageList = 3;
                stageListPosition = GVar("SpecialStage.ListPos");
                scriptEng.tempValue[0] = GVar("SpecialStage.NextZone");
                scriptEng.tempValue[0] %= 10;
                scriptEng.tempValue[0] >>= 2;
                if (scriptEng.tempValue[0] == 1) {
                    scriptEng.tempValue[1] = GVar("SpecialStage.NextZone");
                    scriptEng.tempValue[1] /= 10;
                    scriptEng.tempValue[1] <<= 1;
                    scriptEng.tempValue[0] = ((GVar("Good_Future_List") >> scriptEng.tempValue[1]) & 1);
                    GVar("Good_Future_Count") += scriptEng.tempValue[0];
                }
            } else {
                scriptEng.tempValue[0] = stageListPosition;
                scriptEng.tempValue[0] %= 10;
                scriptEng.tempValue[0] >>= 2;
                if (scriptEng.tempValue[0] == 1) {
                    scriptEng.tempValue[1] = stageListPosition;
                    scriptEng.tempValue[1] /= 10;
                    scriptEng.tempValue[1] <<= 1;
                    scriptEng.tempValue[0] = ((GVar("Good_Future_List") >> scriptEng.tempValue[1]) & 1);
                    GVar("Good_Future_Count") += scriptEng.tempValue[0];
                }
            }
            playerListPos = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3];
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
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
            self->state = 5;
            self->alpha = 0;
        }
        break;
        case 5:
        if (self->values[0] < 256) {
            self->alpha = self->values[0];
            self->values[0] += 8;
        } else {
            self->values[0] = 0;
            self->alpha = 255;
            self->state = 6;
        }
        break;
        case 6:
        scriptEng.arrayPosition[0] = self->values[1];
        CheckResult() = 1;
        if (CheckResult() == 1) {
            if (keyPress.left == 1) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3]--;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] < 0) {
                    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 1;
                }
            }
            if (keyPress.right == 1) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3]++;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] > 1) {
                    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 0;
                }
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
            }
        } else {
            if (Engine.message == 2) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = -1;
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            scriptEng.tempValue[3] = CheckResult();
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] -= 56;
            scriptEng.tempValue[1] = SCREEN_CENTERX;
            scriptEng.tempValue[1] -= 8;
            CheckTouchRect_Script(scriptEng.tempValue[0], 126, scriptEng.tempValue[1], 184);
            if (CheckResult() > -1) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 0;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 0) {
                        keyPress.start = 1;
                    }
                } else {
                    if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 0) {
                        objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = -1;
                    }
                }
            }
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] += 8;
            scriptEng.tempValue[1] = SCREEN_CENTERX;
            scriptEng.tempValue[1] += 56;
            CheckTouchRect_Script(scriptEng.tempValue[0], 126, scriptEng.tempValue[1], 184);
            if (CheckResult() > -1) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 1;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 1) {
                        keyPress.start = 1;
                    }
                } else {
                    if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 1) {
                        objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = -1;
                    }
                }
            }
            scriptEng.tempValue[0] = SCREEN_XSIZE;
            scriptEng.tempValue[0] -= 76;
            CheckTouchRect_Script(scriptEng.tempValue[0], 192, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 2;
                objectEntityList[1].values[4] = 1;
            } else {
                objectEntityList[1].values[4] = 0;
                if (scriptEng.tempValue[3] < 0) {
                    if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 2) {
                        keyPress.B = 1;
                    }
                } else {
                    if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 2) {
                        objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = -1;
                    }
                }
            }
            if (keyPress.left == 1) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 1;
            }
            if (keyPress.right == 1) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 0;
            }
        }
        CheckResult() = 0;
        if (keyPress.start == 1) {
            CheckResult() = 1;
        }
        if (keyPress.A == 1) {
            CheckResult() = 1;
        }
        if (CheckResult() == 1) {
            if (GVar("Options.TailsUnlocked") == 1) {
                PlaySfx(27, 0);
                StopMusic();
                self->state = 7;
            } else {
                if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 0) {
                    PlaySfx(27, 0);
                    StopMusic();
                    self->state = 7;
                } else {
                }
            }
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
            self->state = 8;
        }
        break;
        case 8:
        if (self->values[0] < 256) {
            self->values[0] += 8;
        } else {
            scriptEng.arrayPosition[0] = self->values[1];
            scriptEng.arrayPosition[1] = self->values[1];
            scriptEng.arrayPosition[1] <<= 3;
            saveRAM[scriptEng.arrayPosition[1]] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3];
            scriptEng.arrayPosition[1]++;
            saveRAM[scriptEng.arrayPosition[1]] = 3;
            scriptEng.arrayPosition[1]++;
            saveRAM[scriptEng.arrayPosition[1]] = 0;
            scriptEng.arrayPosition[1]++;
            saveRAM[scriptEng.arrayPosition[1]] = 1;
            scriptEng.arrayPosition[1]++;
            saveRAM[scriptEng.arrayPosition[1]] = 0;
            scriptEng.arrayPosition[1]++;
            saveRAM[scriptEng.arrayPosition[1]] = 0;
            scriptEng.arrayPosition[1]++;
            saveRAM[scriptEng.arrayPosition[1]] = 50000;
            scriptEng.arrayPosition[1]++;
            saveRAM[scriptEng.arrayPosition[1]] = 0;
            CheckResult() = WriteSaveRAMData();
            GVar("Options.GameMode") = 1;
            GVar("Options.SaveSlot") = self->values[1];
            GVar("Player.Lives") = 3;
            GVar("Player.Score") = 0;
            GVar("Player.ScoreBonus") = 50000;
            GVar("Good_Future_List") = 0;
            GVar("Good_Future_Count") = 0;
            GVar("Good_Future") = 0;
            GVar("Transporter_Destroyed") = 0;
            GVar("MetalSonic_Destroyed") = 0;
            GVar("MetalSonic_List") = 0;
            GVar("SpecialStage.TimeStones") = 0;
            GVar("SpecialStage.ListPos") = 0;
            GVar("LampPost.Check") = 0;
            activeStageList = 1;
            scriptEng.arrayPosition[0] = self->values[1];
            stageListPosition = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2];
            stageListPosition--;
            if (stageListPosition < 0) {
                stageListPosition = 0;
            }
            playerListPos = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3];
            stageMode = STAGEMODE_LOAD;
            if (playerListPos == 0) {
                LoadVideo_Script("Opening");
            }
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 9:
        if (self->values[0] > 0) {
            self->alpha = self->values[0];
            self->values[0] -= 8;
        } else {
            self->alpha = 0;
            self->state = 10;
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
            self->rotation = 0;
            objectEntityList[objectLoop + 1].rotation = 0;
            objectEntityList[objectLoop + 2].rotation = 0;
            objectEntityList[objectLoop + 3].rotation = 0;
            objectEntityList[objectLoop + 4].rotation = 0;
            LoadSaveMenu_SetShowDelete();
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
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 1;
            self->values[1] = 0;
            if (objectEntityList[objectLoop + 4].rotation >= 2) {
                self->rotation = 0;
                objectEntityList[objectLoop + 1].rotation = 0;
                objectEntityList[objectLoop + 2].rotation = 0;
                objectEntityList[objectLoop + 3].rotation = 0;
                objectEntityList[objectLoop + 4].rotation = 0;
            } else {
                self->rotation = 2;
                objectEntityList[objectLoop + 1].rotation = 2;
                objectEntityList[objectLoop + 2].rotation = 2;
                objectEntityList[objectLoop + 3].rotation = 2;
                objectEntityList[objectLoop + 4].rotation = 2;
            }
        }
        break;
        case 13:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            scriptEng.arrayPosition[0] = self->values[1];
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].rotation = 2;
            self->state = 14;
            self->YPos = 40;
            self->YPos *= self->values[1];
            self->YPos += SCREEN_CENTERY;
            self->YPos -= 87;
        }
        break;
        case 14:
        scriptEng.tempValue[0] = SCREEN_CENTERY;
        scriptEng.tempValue[0] -= 87;
        if (self->YPos > scriptEng.tempValue[0]) {
            self->YPos -= 8;
            if (self->YPos < scriptEng.tempValue[0]) {
                self->YPos = scriptEng.tempValue[0];
            }
        } else {
            self->state = 15;
            self->alpha = 0;
            objectEntityList[objectLoop + 4].values[1] = 0;
        }
        break;
        case 15:
        if (self->values[0] < 256) {
            self->alpha = self->values[0];
            self->values[0] += 8;
        } else {
            self->values[0] = 0;
            self->alpha = 255;
            self->state = 16;
        }
        break;
        case 16:
        scriptEng.arrayPosition[0] = self->values[1];
        self->animationTimer++;
        self->animationTimer &= 63;
        CheckResult() = 1;
        if (CheckResult() == 1) {
            if (keyPress.up == 1) {
                objectEntityList[objectLoop + 4].values[1]--;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + 4].values[1] < 0) {
                    objectEntityList[objectLoop + 4].values[1] = 1;
                }
            }
            if (keyPress.down == 1) {
                objectEntityList[objectLoop + 4].values[1]++;
                PlaySfx(23, 0);
                if (objectEntityList[objectLoop + 4].values[1] > 1) {
                    objectEntityList[objectLoop + 4].values[1] = 0;
                }
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
            }
        } else {
            if (Engine.message == 2) {
                objectEntityList[objectLoop + 4].values[1] = -1;
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            scriptEng.tempValue[3] = CheckResult();
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] -= 34;
            scriptEng.tempValue[1] = SCREEN_CENTERX;
            scriptEng.tempValue[1] += 34;
            CheckTouchRect_Script(scriptEng.tempValue[0], 110, scriptEng.tempValue[1], 135);
            if (CheckResult() > -1) {
                objectEntityList[objectLoop + 4].values[1] = 0;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (objectEntityList[objectLoop + 4].values[1] == 0) {
                        keyPress.start = 1;
                    }
                } else {
                    if (objectEntityList[objectLoop + 4].values[1] == 0) {
                        objectEntityList[objectLoop + 4].values[1] = -1;
                    }
                }
            }
            CheckTouchRect_Script(scriptEng.tempValue[0], 144, scriptEng.tempValue[1], 169);
            if (CheckResult() > -1) {
                objectEntityList[objectLoop + 4].values[1] = 1;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (objectEntityList[objectLoop + 4].values[1] == 1) {
                        keyPress.start = 1;
                    }
                } else {
                    if (objectEntityList[objectLoop + 4].values[1] == 1) {
                        objectEntityList[objectLoop + 4].values[1] = -1;
                    }
                }
            }
            scriptEng.tempValue[0] = SCREEN_XSIZE;
            scriptEng.tempValue[0] -= 76;
            CheckTouchRect_Script(scriptEng.tempValue[0], 192, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
                objectEntityList[objectLoop + 4].values[1] = 2;
                objectEntityList[1].values[4] = 1;
            } else {
                objectEntityList[1].values[4] = 0;
                if (scriptEng.tempValue[3] < 0) {
                    if (objectEntityList[objectLoop + 4].values[1] == 2) {
                        keyPress.B = 1;
                    }
                } else {
                    if (objectEntityList[objectLoop + 4].values[1] == 2) {
                        objectEntityList[objectLoop + 4].values[1] = -1;
                    }
                }
            }
            if (keyPress.up == 1) {
                objectEntityList[objectLoop + 4].values[1] = 1;
            }
            if (keyPress.down == 1) {
                objectEntityList[objectLoop + 4].values[1] = 0;
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
            if (objectEntityList[objectLoop + 4].values[1] == 0) {
                PlaySfx(globalSFXCount + 0, 0);
            } else {
                PlaySfx(27, 0);
            }
            self->animationTimer = 0;
            self->state = 17;
        }
        if (keyPress.B == 1) {
            scriptEng.arrayPosition[0] = self->values[1];
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].rotation = 0;
            self->state = 18;
            self->values[0] = 248;
            self->animationTimer = 0;
            PlaySfx(globalSFXCount + 1, 0);
        }
        break;
        case 17:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->state = 18;
            self->values[0] = 248;
            scriptEng.arrayPosition[0] = self->values[1];
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].rotation = 0;
            if (objectEntityList[objectLoop + 4].values[1] == 0) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 0;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[6] = 3;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[5] = 0;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 0;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[4] = 0;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].propertyValue = 0;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].scale = 50000;
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[7] = 0;
                scriptEng.arrayPosition[1] = self->values[1];
                scriptEng.arrayPosition[1] <<= 3;
                saveRAM[scriptEng.arrayPosition[1]] = 0;
                scriptEng.arrayPosition[1]++;
                saveRAM[scriptEng.arrayPosition[1]] = 3;
                scriptEng.arrayPosition[1]++;
                saveRAM[scriptEng.arrayPosition[1]] = 0;
                scriptEng.arrayPosition[1]++;
                saveRAM[scriptEng.arrayPosition[1]] = 0;
                scriptEng.arrayPosition[1]++;
                saveRAM[scriptEng.arrayPosition[1]] = 0;
                scriptEng.arrayPosition[1]++;
                saveRAM[scriptEng.arrayPosition[1]] = 0;
                scriptEng.arrayPosition[1]++;
                saveRAM[scriptEng.arrayPosition[1]] = 0;
                scriptEng.arrayPosition[1]++;
                saveRAM[scriptEng.arrayPosition[1]] = 0;
            }
            CheckResult() = WriteSaveRAMData();
        }
        break;
        case 18:
        if (self->values[0] > 0) {
            self->alpha = self->values[0];
            self->values[0] -= 8;
        } else {
            self->alpha = 0;
            self->state = 10;
        }
        break;
    }
}

void O_Menu_LoadSaveMenu::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 11:
        case 13:
        if (self->state != 0) {
            LoadSaveMenu_DrawDeleteNoSave();
        }
        self->YPos = SCREEN_CENTERY;
        self->YPos -= 87;
        scriptEng.arrayPosition[0] = 0;
        LoadSaveMenu_DrawSaveFiles();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        LoadSaveMenu_DrawSaveFiles();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        LoadSaveMenu_DrawSaveFiles();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        LoadSaveMenu_DrawSaveFiles();
        break;
        case 4:
        case 14:
        LoadSaveMenu_DrawDeleteNoSave();
        scriptEng.arrayPosition[0] = self->values[1];
        LoadSaveMenu_DrawSaveFiles();
        break;
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
        DrawSpriteScreenFX_Script(30, FX_INK, SCREEN_CENTERX, 84);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 32;
        scriptEng.arrayPosition[0] = self->values[1];
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 0) {
            DrawSpriteScreenFX_Script(31, FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(36, FX_INK, scriptEng.tempValue[0], 164);
            DrawSpriteScreenFX_Script(33, FX_INK, scriptEng.tempValue[0], 136);
        } else {
            DrawSpriteScreenFX_Script(31, FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(34, FX_INK, scriptEng.tempValue[0], 164);
        }
        scriptEng.tempValue[0] += 64;
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 1) {
            DrawSpriteScreenFX_Script(32, FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(37, FX_INK, scriptEng.tempValue[0], 164);
            DrawSpriteScreenFX_Script(33, FX_INK, scriptEng.tempValue[0], 136);
        } else {
            DrawSpriteScreenFX_Script(32, FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(35, FX_INK, scriptEng.tempValue[0], 164);
        }
        self->alpha = 255;
        LoadSaveMenu_DrawSaveFiles();
        break;
        case 7:
        DrawSpriteScreenFX_Script(30, FX_INK, SCREEN_CENTERX, 84);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 32;
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.tempValue[1] = self->values[0];
        scriptEng.tempValue[1] &= 3;
        scriptEng.tempValue[1] >>= 1;
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 0) {
            if (scriptEng.tempValue[1] == 0) {
                DrawSpriteScreenFX_Script(31, FX_INK, scriptEng.tempValue[0], 136);
            }
            DrawSpriteScreenFX_Script(36, FX_INK, scriptEng.tempValue[0], 164);
            DrawSpriteScreenFX_Script(33, FX_INK, scriptEng.tempValue[0], 136);
        } else {
            DrawSpriteScreenFX_Script(31, FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(34, FX_INK, scriptEng.tempValue[0], 164);
        }
        scriptEng.tempValue[0] += 64;
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] == 1) {
            if (scriptEng.tempValue[1] == 0) {
                DrawSpriteScreenFX_Script(32, FX_INK, scriptEng.tempValue[0], 136);
            }
            DrawSpriteScreenFX_Script(37, FX_INK, scriptEng.tempValue[0], 164);
            DrawSpriteScreenFX_Script(33, FX_INK, scriptEng.tempValue[0], 136);
        } else {
            DrawSpriteScreenFX_Script(32, FX_INK, scriptEng.tempValue[0], 136);
            DrawSpriteScreenFX_Script(35, FX_INK, scriptEng.tempValue[0], 164);
        }
        self->alpha = 255;
        LoadSaveMenu_DrawSaveFiles();
        break;
        case 12:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        if (self->rotation == 2) {
            if (scriptEng.tempValue[0] == 0) {
                DrawSprite_ScreenXY(55, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
            } else {
                DrawSprite_ScreenXY(54, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
            }
        } else {
            if (scriptEng.tempValue[0] == 0) {
                DrawSprite_ScreenXY(53, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
            } else {
                DrawSprite_ScreenXY(52, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
            }
        }
        self->YPos = SCREEN_CENTERY;
        self->YPos -= 87;
        scriptEng.arrayPosition[0] = 0;
        LoadSaveMenu_DrawSaveFiles();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        LoadSaveMenu_DrawSaveFiles();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        LoadSaveMenu_DrawSaveFiles();
        self->YPos += 40;
        scriptEng.arrayPosition[0]++;
        LoadSaveMenu_DrawSaveFiles();
        break;
        case 15:
        case 16:
        case 18:
        DrawSpriteScreenFX_Script(57, FX_INK, SCREEN_CENTERX, 84);
        if (objectEntityList[objectLoop + 4].values[1] == 0) {
            DrawSpriteScreenFX_Script(76, FX_INK, SCREEN_CENTERX, 112);
        } else {
            DrawSpriteScreenFX_Script(75, FX_INK, SCREEN_CENTERX, 112);
        }
        if (objectEntityList[objectLoop + 4].values[1] == 1) {
            DrawSpriteScreenFX_Script(78, FX_INK, SCREEN_CENTERX, 146);
        } else {
            DrawSpriteScreenFX_Script(77, FX_INK, SCREEN_CENTERX, 146);
        }
        scriptEng.arrayPosition[0] = self->values[1];
        self->alpha = 255;
        LoadSaveMenu_DrawSaveFiles();
        break;
        case 17:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        DrawSpriteScreenFX_Script(57, FX_INK, SCREEN_CENTERX, 84);
        if (objectEntityList[objectLoop + 4].values[1] == 0) {
            if (scriptEng.tempValue[0] == 0) {
                DrawSpriteScreenFX_Script(76, FX_INK, SCREEN_CENTERX, 112);
            } else {
                DrawSpriteScreenFX_Script(75, FX_INK, SCREEN_CENTERX, 112);
            }
        } else {
            DrawSpriteScreenFX_Script(75, FX_INK, SCREEN_CENTERX, 112);
        }
        if (objectEntityList[objectLoop + 4].values[1] == 1) {
            if (scriptEng.tempValue[0] == 0) {
                DrawSpriteScreenFX_Script(78, FX_INK, SCREEN_CENTERX, 146);
            } else {
                DrawSpriteScreenFX_Script(77, FX_INK, SCREEN_CENTERX, 146);
            }
        } else {
            DrawSpriteScreenFX_Script(77, FX_INK, SCREEN_CENTERX, 146);
        }
        scriptEng.arrayPosition[0] = self->values[1];
        self->alpha = 255;
        LoadSaveMenu_DrawSaveFiles();
        break;
    }
}

void O_Menu_LoadSaveMenu::LoadSaveMenu_DrawSaveFiles()
{
    Entity *self = Self();

    switch (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].rotation) {
        case 2:
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
            self->alpha = 64;
            DrawSpriteScreenFX_Script(56, FX_INK, self->XPos, self->YPos);
            self->alpha = 255;
        }
        case 0:
        if (scriptEng.arrayPosition[0] == self->values[1]) {
            DrawSpriteScreenFX_Script(9, FX_INK, self->XPos, self->YPos);
            scriptEng.tempValue[0] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2];
            if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
                scriptEng.tempValue[0]--;
                scriptEng.tempValue[0] /= 10;
                if (scriptEng.tempValue[0] >= 8) {
                    scriptEng.tempValue[0] = 8;
                    scriptEng.tempValue[1] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].propertyValue;
                } else {
                    scriptEng.tempValue[2] = scriptEng.tempValue[0];
                    scriptEng.tempValue[2] *= 10;
                    scriptEng.tempValue[1] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2];
                    scriptEng.tempValue[1]--;
                    scriptEng.tempValue[1] -= scriptEng.tempValue[2];
                    scriptEng.tempValue[1] >>= 2;
                }
                scriptEng.tempValue[0] += 21;
                scriptEng.tempValue[1] += 67;
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, self->XPos, self->YPos);
            } else {
                scriptEng.tempValue[0] += 20;
            }
            DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, self->YPos);
        } else {
            scriptEng.tempValue[0] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2];
            if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
                scriptEng.tempValue[0]--;
                scriptEng.tempValue[0] /= 10;
                if (scriptEng.tempValue[0] >= 8) {
                    scriptEng.tempValue[0] = 8;
                    scriptEng.tempValue[1] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].propertyValue;
                } else {
                    scriptEng.tempValue[2] = scriptEng.tempValue[0];
                    scriptEng.tempValue[2] *= 10;
                    scriptEng.tempValue[1] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2];
                    scriptEng.tempValue[1]--;
                    scriptEng.tempValue[1] -= scriptEng.tempValue[2];
                    scriptEng.tempValue[1] >>= 2;
                }
                scriptEng.tempValue[0] += 11;
                scriptEng.tempValue[1] += 59;
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, self->XPos, self->YPos);
            } else {
                scriptEng.tempValue[0] += 10;
            }
            DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, self->YPos);
        }
        break;
        case 3:
        self->alpha = 64;
        DrawSpriteScreenFX_Script(56, FX_INK, self->XPos, self->YPos);
        self->alpha = 255;
        case 1:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        DrawSpriteScreenFX_Script(9, FX_INK, self->XPos, self->YPos);
        if (scriptEng.tempValue[0] == 0) {
            scriptEng.tempValue[0] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2];
            if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
                scriptEng.tempValue[0]--;
                scriptEng.tempValue[0] /= 10;
                if (scriptEng.tempValue[0] >= 8) {
                    scriptEng.tempValue[0] = 8;
                    scriptEng.tempValue[1] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].propertyValue;
                } else {
                    scriptEng.tempValue[2] = scriptEng.tempValue[0];
                    scriptEng.tempValue[2] *= 10;
                    scriptEng.tempValue[1] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2];
                    scriptEng.tempValue[1]--;
                    scriptEng.tempValue[1] -= scriptEng.tempValue[2];
                    scriptEng.tempValue[1] >>= 2;
                }
                scriptEng.tempValue[0] += 21;
                scriptEng.tempValue[1] += 67;
                DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, self->XPos, self->YPos);
            } else {
                scriptEng.tempValue[0] += 20;
            }
            DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, self->YPos);
        }
        break;
    }
    DrawSpriteScreenFX_Script(8, FX_INK, self->XPos, self->YPos);
    if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
        scriptEng.tempValue[0] = objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3];
        scriptEng.tempValue[0] <<= 1;
        scriptEng.tempValue[0] += 4;
        scriptEng.tempValue[1] = self->animationTimer;
        scriptEng.tempValue[1] >>= 5;
        scriptEng.tempValue[0] += scriptEng.tempValue[1];
        DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, self->YPos);
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = 38;
        while (scriptEng.tempValue[0] < 7) {
            scriptEng.tempValue[2] = scriptEng.tempValue[1];
            CheckResult() = ((objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[4] >> scriptEng.tempValue[0]) & 1);
            if (CheckResult() == 0) {
                scriptEng.tempValue[2] += 7;
            }
            DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_INK, self->XPos, self->YPos);
            scriptEng.tempValue[1]++;
            scriptEng.tempValue[0]++;
        }
    } else {
        DrawSpriteScreenFX_Script(scriptEng.arrayPosition[0], FX_INK, self->XPos, self->YPos);
    }
}

void O_Menu_LoadSaveMenu::LoadSaveMenu_DrawDeleteNoSave()
{
    Entity *self = Self();

    if (objectEntityList[objectLoop + 4].rotation >= 2) {
        if (self->values[1] == 4) {
            DrawSprite_ScreenXY(55, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
        } else {
            DrawSprite_ScreenXY(54, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
        }
    } else {
        if (self->values[1] == 4) {
            DrawSprite_ScreenXY(53, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
        } else {
            DrawSprite_ScreenXY(52, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
        }
    }
    if (self->direction == 1) {
        if (objectEntityList[objectLoop + 1].YPos > 14) {
            objectEntityList[objectLoop + 1].YPos -= 2;
            DrawRectangle(objectEntityList[objectLoop + 1].XPos, 32, 64, 18, 96, 96, 128, 255);
        }
    } else {
        if (objectEntityList[objectLoop + 1].YPos < 32) {
            objectEntityList[objectLoop + 1].YPos += 2;
        }
        DrawRectangle(objectEntityList[objectLoop + 1].XPos, 32, 64, 18, 96, 96, 128, 255);
    }
}

void O_Menu_LoadSaveMenu::LoadSaveMenu_CheckTouchSave()
{
    Entity *self = Self();

    scriptEng.tempValue[0] *= 40;
    scriptEng.tempValue[0] += SCREEN_CENTERY;
    scriptEng.tempValue[0] -= 87;
    scriptEng.tempValue[1] = scriptEng.tempValue[0];
    scriptEng.tempValue[1] += 37;
    scriptEng.tempValue[2] = self->XPos;
    scriptEng.tempValue[2] += 250;
    CheckTouchRect_Script(self->XPos, scriptEng.tempValue[0], scriptEng.tempValue[2], scriptEng.tempValue[1]);
}

void O_Menu_LoadSaveMenu::LoadSaveMenu_SetShowDelete()
{
    Entity *self = Self();

    self->direction = 0;
    scriptEng.arrayPosition[0] = 0;
    while (scriptEng.arrayPosition[0] < 4) {
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] > 0) {
            self->direction = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

const Native::NativeFunctionDef O_Menu_LoadSaveMenu::funcs[4] = {
    { "LoadSaveMenu_DrawSaveFiles", O_Menu_LoadSaveMenu::LoadSaveMenu_DrawSaveFiles },
    { "LoadSaveMenu_DrawDeleteNoSave", O_Menu_LoadSaveMenu::LoadSaveMenu_DrawDeleteNoSave },
    { "LoadSaveMenu_CheckTouchSave", O_Menu_LoadSaveMenu::LoadSaveMenu_CheckTouchSave },
    { "LoadSaveMenu_SetShowDelete", O_Menu_LoadSaveMenu::LoadSaveMenu_SetShowDelete },
};

#endif // RETRO_USE_NATIVE_OBJECTS
