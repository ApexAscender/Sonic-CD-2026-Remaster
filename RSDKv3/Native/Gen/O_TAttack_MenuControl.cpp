#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TAttack_MenuControl.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MenuControl.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TAttack_MenuControl::ObjectStartup()
{
    if (GVar("Options.Soundtrack") == 0) {
        SetMusicTrack_Script("JP/TimeAttack.ogg", 0, 100512);
    } else {
        SetMusicTrack_Script("US/DAGarden.ogg", 0, 117382);
    }
    objectEntityList[0].type = TypeNameID("Menu Control");
    objectEntityList[0].drawOrder = 1;
}

void O_TAttack_MenuControl::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        debugMode = 0;
        playerListPos = 0;
        GVar("LampPost.Check") = 0;
        GVar("Good_Future") = 0;
        GVar("Good_Future_Count") = 0;
        GVar("Good_Future_List") = 0;
        GVar("SpecialStage.TimeStones") = 0;
        CheckResult() = ReadSaveRAMData();
        self->state = 1;
        self->values[0] = 384;
        self->scale = 0x40000;
        SetFade(0, 0, 0, 255);
        MenuControl_ZoneUnlockCheck();
        if (GVar("TimeAttack.Round") > -1) {
            self->state = 12;
            objectEntityList[40].propertyValue = GVar("TimeAttack.Round");
            self->values[3] = GVar("TimeAttack.Round");
            objectEntityList[40].XPos = SCREEN_CENTERX;
            objectEntityList[40].XPos -= 72;
            objectEntityList[40].XPos <<= 16;
            self->values[4] = GVar("TimeAttack.Zone");
            self->values[4] *= 192;
            self->values[4] += 192;
            if (GVar("TimeAttack.Result") > 0) {
                scriptEng.arrayPosition[0] = GVar("TimeAttack.Round");
                scriptEng.arrayPosition[0] *= 18;
                scriptEng.tempValue[0] = GVar("TimeAttack.Zone");
                scriptEng.tempValue[0] *= 6;
                scriptEng.arrayPosition[0] += scriptEng.tempValue[0];
                scriptEng.arrayPosition[0] += 48;
                scriptEng.arrayPosition[0] += GVar("TimeAttack.MenuSection");
                if (GVar("TimeAttack.Result") < saveRAM[scriptEng.arrayPosition[0]]) {
                    scriptEng.arrayPosition[1] = scriptEng.arrayPosition[0];
                    scriptEng.arrayPosition[1] += 4;
                    scriptEng.arrayPosition[0] += 2;
                    saveRAM[scriptEng.arrayPosition[1]] = saveRAM[scriptEng.arrayPosition[0]];
                    scriptEng.arrayPosition[1] -= 2;
                    scriptEng.arrayPosition[0] -= 2;
                    saveRAM[scriptEng.arrayPosition[1]] = saveRAM[scriptEng.arrayPosition[0]];
                    saveRAM[scriptEng.arrayPosition[0]] = GVar("TimeAttack.Result");
                    self->values[6] = 1;
                } else {
                    scriptEng.arrayPosition[0] += 2;
                    if (GVar("TimeAttack.Result") < saveRAM[scriptEng.arrayPosition[0]]) {
                        scriptEng.arrayPosition[1] = scriptEng.arrayPosition[0];
                        scriptEng.arrayPosition[1] += 2;
                        saveRAM[scriptEng.arrayPosition[1]] = saveRAM[scriptEng.arrayPosition[0]];
                        saveRAM[scriptEng.arrayPosition[0]] = GVar("TimeAttack.Result");
                        self->values[6] = 2;
                    } else {
                        scriptEng.arrayPosition[0] += 2;
                        if (GVar("TimeAttack.Result") < saveRAM[scriptEng.arrayPosition[0]]) {
                            saveRAM[scriptEng.arrayPosition[0]] = GVar("TimeAttack.Result");
                            self->values[6] = 3;
                        }
                    }
                }
            }
            self->scale = 0x50000;
        } else {
            GVar("TimeAttack.MenuSection") = 0;
        }
        MenuControl_DefaultRecord();
        if (GVar("TimeAttack.MenuSection") == 0) {
            MenuControl_TotalRegularRecord();
        } else {
            MenuControl_TotalSpecialRecord();
            objectEntityList[40].type = TypeNameID("S Large Icon");
            objectEntityList[41].type = TypeNameID("S Records");
            scriptEng.arrayPosition[0] = 32;
            while (scriptEng.arrayPosition[0] < 40) {
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Special Icon");
                scriptEng.arrayPosition[0]++;
            }
        }
        CheckResult() = WriteSaveRAMData();
        MenuControl_IconTransitions();
        Engine.Callback(2);
        PlayMusic(0);
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
            self->scale -= 0x1000;
        } else {
            self->state = 2;
        }
        SetFade(0, 0, 0, self->values[0]);
        MenuControl_IconTransitions();
        break;
        case 2:
        CheckResult() = 1;
        if (CheckResult() == 1) {
            scriptEng.arrayPosition[0] = 32;
            scriptEng.arrayPosition[0] += self->values[3];
            CheckResult() = 0;
            if (objectEntityList[scriptEng.arrayPosition[0]].state != 1) {
                if (keyPress.left == 1) {
                    self->values[3]--;
                    if (self->values[3] < 0) {
                        self->values[3] = 7;
                    }
                    PlaySfx(23, 0);
                }
                if (keyPress.right == 1) {
                    self->values[3]++;
                    if (self->values[3] > 7) {
                        self->values[3] = 0;
                    }
                    PlaySfx(23, 0);
                }
                if (keyPress.up == 1) {
                    self->values[3] -= 4;
                    if (self->values[3] < 0) {
                        self->values[3] += 8;
                        if (self->values[7] == 1) {
                            self->state = 18;
                        }
                    }
                    PlaySfx(23, 0);
                }
                if (keyPress.down == 1) {
                    self->values[3] += 4;
                    if (self->values[3] > 7) {
                        self->values[3] -= 8;
                        if (self->values[7] == 1) {
                            self->state = 16;
                        }
                    }
                    PlaySfx(23, 0);
                }
                if (keyPress.start == 1) {
                    CheckResult() = 1;
                }
                if (keyPress.A == 1) {
                    CheckResult() = 1;
                }
            }
            if (CheckResult() == 1) {
                scriptEng.arrayPosition[0] = 32;
                scriptEng.arrayPosition[0] += self->values[3];
                if (objectEntityList[scriptEng.arrayPosition[0]].values[4] == 0) {
                    objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                    self->values[5] = 0;
                    switch (self->values[3]) {
                        case -1:
                        break;
                        case 0:
                        PlaySfx(27, 0);
                        break;
                        case 1:
                        PlaySfx(27, 0);
                        break;
                        case 2:
                        PlaySfx(27, 0);
                        break;
                        case 3:
                        PlaySfx(27, 0);
                        break;
                        case 4:
                        PlaySfx(27, 0);
                        break;
                        case 5:
                        PlaySfx(27, 0);
                        break;
                        case 6:
                        PlaySfx(27, 0);
                        break;
                        case 7:
                        PlaySfx(27, 0);
                        self->state++;
                        StopMusic();
                        break;
                    }
                }
            }
        }
        if (keyPress.B == 1) {
            self->values[3] = 7;
            scriptEng.arrayPosition[0] = 32;
            scriptEng.arrayPosition[0] += self->values[3];
            objectEntityList[scriptEng.arrayPosition[0]].state = 1;
            self->state++;
            StopMusic();
            PlaySfx(27, 0);
        }
        break;
        case 3:
        break;
        case 4:
        if (self->values[0] < 384) {
            self->values[0] += 8;
            self->scale += 0x1000;
        } else {
            stageListPosition = 1;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        MenuControl_IconTransitions();
        Engine.Callback(3);
        break;
        case 5:
        if (self->values[0] < 256) {
            self->values[0] += 8;
            self->scale += 0x2000;
        } else {
            if (GVar("TimeAttack.MenuSection") == 0) {
                objectEntityList[40].type = TypeNameID("Large Icon");
                objectEntityList[41].type = TypeNameID("Records");
            } else {
                objectEntityList[40].type = TypeNameID("S Large Icon");
                objectEntityList[41].type = TypeNameID("S Records");
            }
            objectEntityList[40].propertyValue = self->values[3];
            objectEntityList[40].state = 1;
            objectEntityList[41].drawOrder = 2;
            objectEntityList[42].drawOrder = 2;
            objectEntityList[43].drawOrder = 2;
            self->values[0] = 0;
            self->values[4] = 0;
            self->state++;
        }
        MenuControl_IconTransitions();
        break;
        case 6:
        if (self->values[4] < 192) {
            self->values[4] += 8;
        } else {
            self->state++;
        }
        self->values[5] = 0;
        break;
        case 7:
        CheckResult() = 1;
        if (CheckResult() == 1) {
            if (GVar("TimeAttack.MenuSection") == 0) {
                if (keyPress.up == 1) {
                    self->state = 9;
                }
                if (keyPress.down == 1) {
                    self->state = 8;
                }
                if (keyPress.left == 1) {
                    self->values[5]--;
                    if (self->values[5] < 0) {
                        self->values[5] = 2;
                    }
                }
                if (keyPress.right == 1) {
                    self->values[5]++;
                    if (self->values[5] > 2) {
                        self->values[5] = 0;
                    }
                }
            } else {
                if (keyPress.left == 1) {
                    self->values[5] -= 2;
                    if (self->values[5] < 0) {
                        self->values[5] = 2;
                    }
                }
                if (keyPress.right == 1) {
                    self->values[5] += 2;
                    if (self->values[5] > 2) {
                        self->values[5] = 0;
                    }
                }
            }
            CheckResult() = 0;
            if (keyPress.start == 1) {
                CheckResult() = 1;
            }
            if (keyPress.A == 1) {
                CheckResult() = 1;
            }
            if (keyPress.B == 1) {
                PlaySfx(globalSFXCount + 0, 0);
                objectEntityList[40].state = 2;
                self->state = 13;
                objectEntityList[41].drawOrder = 8;
                objectEntityList[42].drawOrder = 8;
                objectEntityList[43].drawOrder = 8;
                scriptEng.arrayPosition[0] = self->values[4];
                scriptEng.arrayPosition[0] /= 192;
                scriptEng.arrayPosition[0] += 40;
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            }
            if (CheckResult() == 1) {
                switch (self->values[5]) {
                    case 0:
                    PlaySfx(globalSFXCount + 0, 0);
                    objectEntityList[40].state = 2;
                    self->state = 13;
                    objectEntityList[41].drawOrder = 8;
                    objectEntityList[42].drawOrder = 8;
                    objectEntityList[43].drawOrder = 8;
                    scriptEng.arrayPosition[0] = self->values[4];
                    scriptEng.arrayPosition[0] /= 192;
                    scriptEng.arrayPosition[0] += 40;
                    objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
                    break;
                    case 1:
                    PlaySfx(23, 0);
                    self->state = 9;
                    break;
                    case 2:
                    PlaySfx(27, 0);
                    self->state = 10;
                    StopMusic();
                    break;
                }
            }
        }
        break;
        case 9:
        if (self->values[0] < 192) {
            self->values[0] += 8;
            self->values[4] += 8;
            if (self->values[4] > 767) {
                self->values[4] -= 576;
            }
        } else {
            self->values[0] = 0;
            self->state = 7;
        }
        break;
        case 8:
        if (self->values[0] < 192) {
            self->values[0] += 8;
            self->values[4] -= 8;
            if (self->values[4] < 192) {
                self->values[4] += 576;
            }
        } else {
            self->values[0] = 0;
            self->state = 7;
        }
        break;
        case 10:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 11:
        if (self->values[0] < 320) {
            self->values[0] += 8;
        } else {
            if (GVar("TimeAttack.MenuSection") == 0) {
                activeStageList = 1;
                stageListPosition = objectEntityList[40].propertyValue;
                GVar("TimeAttack.Round") = objectEntityList[40].propertyValue;
                stageListPosition *= 10;
                scriptEng.tempValue[0] = self->values[4];
                scriptEng.tempValue[0] -= 192;
                scriptEng.tempValue[0] /= 192;
                GVar("TimeAttack.Zone") = scriptEng.tempValue[0];
                scriptEng.tempValue[0] <<= 2;
                stageListPosition += scriptEng.tempValue[0];
                if (scriptEng.tempValue[0] == 8) {
                    stageListPosition++;
                }
            } else {
                activeStageList = 3;
                stageListPosition = objectEntityList[40].propertyValue;
                GVar("TimeAttack.Round") = objectEntityList[40].propertyValue;
                GVar("TimeAttack.Zone") = 0;
            }
            GVar("Player.Lives") = 1;
            GVar("Player.Score") = 0;
            GVar("Options.GameMode") = 2;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 12:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            GVar("TimeAttack.Round") = -1;
            if (self->values[6] > 0) {
                PlaySfx(21, 0);
                self->state = 15;
                objectEntityList[0].drawOrder = 4;
            } else {
                self->state = 7;
            }
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 13:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->scale = 0x50000;
            self->values[0] = 0;
            self->state++;
        }
        if (self->values[4] > 0) {
            self->values[4] -= 8;
        }
        break;
        case 14:
        if (self->values[0] < 256) {
            self->values[0] += 8;
            self->scale -= 0x2000;
        } else {
            self->values[0] = 0;
            self->state = 2;
        }
        MenuControl_IconTransitions();
        break;
        case 15:
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 7;
            self->values[6] = 0;
            objectEntityList[0].drawOrder = 1;
        }
        break;
        case 16:
        if (self->values[0] < 20) {
            self->values[0]++;
            scriptEng.arrayPosition[0] = 32;
            while (scriptEng.arrayPosition[0] < 40) {
                objectEntityList[scriptEng.arrayPosition[0]].YPos -= 0xC0000;
                scriptEng.arrayPosition[0]++;
            }
        } else {
            self->values[0] = 0;
            scriptEng.arrayPosition[0] = 32;
            if (GVar("TimeAttack.MenuSection") == 0) {
                while (scriptEng.arrayPosition[0] < 40) {
                    objectEntityList[scriptEng.arrayPosition[0]].YPos += 0x1E00000;
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Special Icon");
                    scriptEng.arrayPosition[0]++;
                }
                GVar("TimeAttack.MenuSection") = 1;
                MenuControl_TotalSpecialRecord();
            } else {
                while (scriptEng.arrayPosition[0] < 40) {
                    objectEntityList[scriptEng.arrayPosition[0]].YPos += 0x1E00000;
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Round Icon");
                    scriptEng.arrayPosition[0]++;
                }
                GVar("TimeAttack.MenuSection") = 0;
                MenuControl_TotalRegularRecord();
            }
            self->state++;
        }
        break;
        case 17:
        if (self->values[0] < 20) {
            self->values[0]++;
            scriptEng.arrayPosition[0] = 32;
            while (scriptEng.arrayPosition[0] < 40) {
                objectEntityList[scriptEng.arrayPosition[0]].YPos -= 0xC0000;
                scriptEng.arrayPosition[0]++;
            }
        } else {
            self->values[0] = 0;
            self->state = 2;
        }
        break;
        case 18:
        if (self->values[0] < 20) {
            self->values[0]++;
            scriptEng.arrayPosition[0] = 32;
            while (scriptEng.arrayPosition[0] < 40) {
                objectEntityList[scriptEng.arrayPosition[0]].YPos += 0xC0000;
                scriptEng.arrayPosition[0]++;
            }
        } else {
            self->values[0] = 0;
            scriptEng.arrayPosition[0] = 32;
            if (GVar("TimeAttack.MenuSection") == 0) {
                while (scriptEng.arrayPosition[0] < 40) {
                    objectEntityList[scriptEng.arrayPosition[0]].YPos -= 0x1E00000;
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Special Icon");
                    scriptEng.arrayPosition[0]++;
                }
                GVar("TimeAttack.MenuSection") = 1;
                MenuControl_TotalSpecialRecord();
            } else {
                while (scriptEng.arrayPosition[0] < 40) {
                    objectEntityList[scriptEng.arrayPosition[0]].YPos -= 0x1E00000;
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Round Icon");
                    scriptEng.arrayPosition[0]++;
                }
                GVar("TimeAttack.MenuSection") = 0;
                MenuControl_TotalRegularRecord();
            }
            self->state++;
        }
        break;
        case 19:
        if (self->values[0] < 20) {
            self->values[0]++;
            scriptEng.arrayPosition[0] = 32;
            while (scriptEng.arrayPosition[0] < 40) {
                objectEntityList[scriptEng.arrayPosition[0]].YPos += 0xC0000;
                scriptEng.arrayPosition[0]++;
            }
        } else {
            self->values[0] = 0;
            self->state = 2;
        }
        break;
    }
}

void O_TAttack_MenuControl::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 13:
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] += 16;
        DrawRectangle(scriptEng.tempValue[0], 31, SCREEN_CENTERX, 9, 0, 0, 0, 255);
        DrawRectangle(scriptEng.tempValue[0], 40, SCREEN_CENTERX, 135, 224, 0, 0, 255);
        DrawRectangle(scriptEng.tempValue[0], 175, SCREEN_CENTERX, 38, 0, 0, 96, 255);
        break;
        case 15:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] >>= 2;
        scriptEng.tempValue[0] &= 1;
        if (scriptEng.tempValue[0] == 0) {
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] += 16;
            scriptEng.tempValue[1] = self->values[6];
            scriptEng.tempValue[1] *= 24;
            scriptEng.tempValue[1] += 105;
            DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], 34, 24, 8, 0, 104, 255);
        }
        break;
    }
}

void O_TAttack_MenuControl::MenuControl_IconTransitions()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 32;
    scriptEng.tempValue[2] = SCREEN_CENTERX;
    scriptEng.tempValue[2] <<= 16;
    scriptEng.tempValue[0] = -210;
    scriptEng.tempValue[1] = -46;
    while (scriptEng.arrayPosition[0] < 36) {
        objectEntityList[scriptEng.arrayPosition[0]].XPos = scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].XPos *= self->scale;
        objectEntityList[scriptEng.arrayPosition[0]].XPos >>= 1;
        objectEntityList[scriptEng.arrayPosition[0]].XPos += scriptEng.tempValue[2];
        objectEntityList[scriptEng.arrayPosition[0]].YPos = scriptEng.tempValue[1];
        objectEntityList[scriptEng.arrayPosition[0]].YPos *= self->scale;
        objectEntityList[scriptEng.arrayPosition[0]].YPos += 0x640000;
        scriptEng.tempValue[0] += 140;
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.tempValue[0] = -210;
    scriptEng.tempValue[1] = 46;
    while (scriptEng.arrayPosition[0] < 40) {
        objectEntityList[scriptEng.arrayPosition[0]].XPos = scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].XPos *= self->scale;
        objectEntityList[scriptEng.arrayPosition[0]].XPos >>= 1;
        objectEntityList[scriptEng.arrayPosition[0]].XPos += scriptEng.tempValue[2];
        objectEntityList[scriptEng.arrayPosition[0]].YPos = scriptEng.tempValue[1];
        objectEntityList[scriptEng.arrayPosition[0]].YPos *= self->scale;
        objectEntityList[scriptEng.arrayPosition[0]].YPos += 0x640000;
        scriptEng.tempValue[0] += 140;
        scriptEng.arrayPosition[0]++;
    }
}

void O_TAttack_MenuControl::MenuControl_DefaultRecord()
{
    scriptEng.arrayPosition[0] = 48;
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 0;
    while (scriptEng.tempValue[0] < 21) {
        scriptEng.tempValue[1] += saveRAM[scriptEng.arrayPosition[0]];
        scriptEng.arrayPosition[0] += 6;
        scriptEng.tempValue[0]++;
    }
    if (scriptEng.tempValue[1] == 0) {
        scriptEng.arrayPosition[0] = 48;
        scriptEng.tempValue[0] = 0;
        while (scriptEng.tempValue[0] < 21) {
            saveRAM[scriptEng.arrayPosition[0]] = 30000;
            scriptEng.arrayPosition[0]++;
            saveRAM[scriptEng.arrayPosition[0]] = 30000;
            scriptEng.arrayPosition[0]++;
            saveRAM[scriptEng.arrayPosition[0]] = 30000;
            scriptEng.arrayPosition[0]++;
            saveRAM[scriptEng.arrayPosition[0]] = 30000;
            scriptEng.arrayPosition[0]++;
            saveRAM[scriptEng.arrayPosition[0]] = 30000;
            scriptEng.arrayPosition[0]++;
            saveRAM[scriptEng.arrayPosition[0]] = 30000;
            scriptEng.arrayPosition[0]++;
            scriptEng.tempValue[0]++;
        }
    }
}

void O_TAttack_MenuControl::MenuControl_ZoneUnlockCheck()
{
    scriptEng.tempValue[0] = -1;
    scriptEng.arrayPosition[0] = 3;
    while (scriptEng.arrayPosition[0] < 40) {
        scriptEng.tempValue[1] = saveRAM[scriptEng.arrayPosition[0]];
        if (scriptEng.tempValue[1] > 10) {
            if (scriptEng.tempValue[1] > 67) {
                if (scriptEng.tempValue[1] < 80) {
                    scriptEng.tempValue[1] = 7;
                } else {
                    scriptEng.tempValue[1] -= 80;
                    scriptEng.tempValue[1] /= 10;
                }
            } else {
                scriptEng.tempValue[1] /= 10;
            }
        } else {
            scriptEng.tempValue[1] = 0;
        }
        if (scriptEng.tempValue[1] > scriptEng.tempValue[0]) {
            scriptEng.tempValue[0] = scriptEng.tempValue[1];
        }
        scriptEng.arrayPosition[0] += 8;
    }
    if (scriptEng.tempValue[0] > saveRAM[39]) {
        saveRAM[39] = scriptEng.tempValue[0];
    } else {
        scriptEng.tempValue[0] = saveRAM[39];
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.tempValue[0] > 0) {
        objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0;
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0]--;
    }
    while (scriptEng.arrayPosition[0] < 39) {
        objectEntityList[scriptEng.arrayPosition[0]].values[4] = 1;
        scriptEng.arrayPosition[0]++;
    }
}

void O_TAttack_MenuControl::MenuControl_TotalRegularRecord()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 32;
    scriptEng.arrayPosition[1] = 48;
    scriptEng.tempValue[1] = 0;
    while (scriptEng.arrayPosition[0] < 39) {
        scriptEng.tempValue[0] = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1] += 6;
        scriptEng.tempValue[0] += saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1] += 6;
        scriptEng.tempValue[0] += saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1] += 6;
        scriptEng.tempValue[1] += scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].values[1] = scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].values[1] /= 6000;
        objectEntityList[scriptEng.arrayPosition[0]].values[2] = scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].values[2] /= 100;
        objectEntityList[scriptEng.arrayPosition[0]].values[2] %= 60;
        objectEntityList[scriptEng.arrayPosition[0]].values[3] = scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].values[3] %= 100;
        scriptEng.arrayPosition[0]++;
    }
    objectEntityList[scriptEng.arrayPosition[0]].values[1] = scriptEng.tempValue[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[1] /= 6000;
    objectEntityList[scriptEng.arrayPosition[0]].values[2] = scriptEng.tempValue[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[2] /= 100;
    objectEntityList[scriptEng.arrayPosition[0]].values[2] %= 60;
    objectEntityList[scriptEng.arrayPosition[0]].values[3] = scriptEng.tempValue[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[3] %= 100;
    if (objectEntityList[scriptEng.arrayPosition[0]].values[1] < 25) {
        SetAchievement(10, 100);
    }
    if (objectEntityList[scriptEng.arrayPosition[0]].values[1] < 30) {
        self->values[7] = 1;
    }
}

void O_TAttack_MenuControl::MenuControl_TotalSpecialRecord()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 32;
    scriptEng.arrayPosition[1] = 49;
    scriptEng.tempValue[1] = 0;
    while (scriptEng.arrayPosition[0] < 39) {
        scriptEng.tempValue[0] = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1] += 18;
        scriptEng.tempValue[1] += scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].values[1] = scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].values[1] /= 6000;
        objectEntityList[scriptEng.arrayPosition[0]].values[2] = scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].values[2] /= 100;
        objectEntityList[scriptEng.arrayPosition[0]].values[2] %= 60;
        objectEntityList[scriptEng.arrayPosition[0]].values[3] = scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].values[3] %= 100;
        scriptEng.arrayPosition[0]++;
    }
    objectEntityList[scriptEng.arrayPosition[0]].values[1] = scriptEng.tempValue[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[1] /= 6000;
    objectEntityList[scriptEng.arrayPosition[0]].values[2] = scriptEng.tempValue[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[2] /= 100;
    objectEntityList[scriptEng.arrayPosition[0]].values[2] %= 60;
    objectEntityList[scriptEng.arrayPosition[0]].values[3] = scriptEng.tempValue[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[3] %= 100;
    self->values[7] = 1;
}

const Native::NativeFunctionDef O_TAttack_MenuControl::funcs[5] = {
    { "MenuControl_IconTransitions", O_TAttack_MenuControl::MenuControl_IconTransitions },
    { "MenuControl_DefaultRecord", O_TAttack_MenuControl::MenuControl_DefaultRecord },
    { "MenuControl_ZoneUnlockCheck", O_TAttack_MenuControl::MenuControl_ZoneUnlockCheck },
    { "MenuControl_TotalRegularRecord", O_TAttack_MenuControl::MenuControl_TotalRegularRecord },
    { "MenuControl_TotalSpecialRecord", O_TAttack_MenuControl::MenuControl_TotalSpecialRecord },
};

#endif // RETRO_USE_NATIVE_OBJECTS
