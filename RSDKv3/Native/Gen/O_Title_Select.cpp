#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Title_Select.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Select.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Title_Select::ObjectStartup()
{
    LoadSpriteSheet("Title/Select.gif");
    AddSpriteFrame(-39, 2, 128, 16, 1, 171);
    AddSpriteFrame(-31, 2, 128, 16, 1, 18);
    AddSpriteFrame(-42, 2, 128, 16, 1, 35);
    AddSpriteFrame(-31, 2, 128, 16, 1, 154);
    AddSpriteFrame(-43, 2, 128, 16, 1, 86);
    AddSpriteFrame(-24, 2, 128, 16, 1, 137);
    AddSpriteFrame(-15, 2, 128, 16, 1, 103);
    AddSpriteFrame(-39, 2, 128, 16, 130, 171);
    AddSpriteFrame(-31, 2, 128, 16, 130, 18);
    AddSpriteFrame(-42, 2, 128, 16, 130, 35);
    AddSpriteFrame(-31, 2, 128, 16, 130, 154);
    AddSpriteFrame(-43, 2, 128, 16, 130, 86);
    AddSpriteFrame(-24, 2, 128, 16, 130, 137);
    AddSpriteFrame(-15, 2, 128, 16, 130, 103);
    AddSpriteFrame(-66, 0, 9, 16, 259, 1);
    AddSpriteFrame(56, 0, 9, 16, 269, 1);
    AddSpriteFrame(-66, 0, 9, 16, 279, 1);
    AddSpriteFrame(56, 0, 9, 16, 289, 1);
}

void O_Title_Select::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[6] = SCREEN_CENTERX;
        self->values[7] = 0;
        self->values[0] = 0;
        self->state = 1;
        self->values[5] = 0;
        self->values[5] = (1) ? (self->values[5] | (1 << 0)) : (self->values[5] & ~(1 << 0));
        self->values[5] = (1) ? (self->values[5] | (1 << 2)) : (self->values[5] & ~(1 << 2));
        self->values[5] = (1) ? (self->values[5] | (1 << 3)) : (self->values[5] & ~(1 << 3));
        self->values[5] = (1) ? (self->values[5] | (1 << 4)) : (self->values[5] & ~(1 << 4));
        self->values[5] = (1) ? (self->values[5] | (1 << 5)) : (self->values[5] & ~(1 << 5));
        self->values[5] = (1) ? (self->values[5] | (1 << 6)) : (self->values[5] & ~(1 << 6));
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[0];
        if (keyPress.left == 1) {
            if (scriptEng.tempValue[0] > 0) {
                self->values[1] = 0;
                scriptEng.tempValue[1] = 0;
                while (scriptEng.tempValue[1] == 0) {
                    if (scriptEng.tempValue[0] == 0) {
                        scriptEng.tempValue[1] = 1;
                    } else {
                        scriptEng.tempValue[0]--;
                        scriptEng.tempValue[1] = ((self->values[5] >> scriptEng.tempValue[0]) & 1);
                    }
                }
            }
        }
        if (keyPress.right == 1) {
            self->values[1] = 1;
            scriptEng.tempValue[1] = 0;
            while (scriptEng.tempValue[1] == 0) {
                if (scriptEng.tempValue[0] >= 8) {
                    scriptEng.tempValue[1] = 1;
                    scriptEng.tempValue[0] = self->values[0];
                } else {
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[1] = ((self->values[5] >> scriptEng.tempValue[0]) & 1);
                }
            }
        }
        if (self->values[0] != scriptEng.tempValue[0]) {
            self->values[0] = scriptEng.tempValue[0];
            if (self->values[1] == 0) {
                self->state = 12;
            } else {
                self->state = 14;
            }
        } else {
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, 240);
            if (keyPress.start == 1) {
                CheckResult() = 0;
            }
            if (keyPress.A == 1) {
                CheckResult() = 0;
            }
            if (keyPress.C == 1) {
                CheckResult() = 0;
            }
            if (CheckResult() > -1) {
                if (self->values[0] == 0) {
                    self->state = 10;
                } else {
                    self->state = 2;
                    StopMusic();
                    PlaySfx(27, 0);
                    HapticEffect_Script(31, 0, 0, 0);
                }
            } else {
                if (keyPress.B == 1) {
                    objectEntityList[objectLoop - 1].state = 0;
                    self->type = TypeNameID("Blank Object");
                }
            }
            self->values[2]++;
            self->values[2] &= 63;
        }
        break;
        case 2:
        self->values[3] += 4;
        if (self->values[3] == 384) {
            self->state = self->values[0];
            self->state += 3;
        }
        SetFade(0, 0, 0, self->values[3]);
        break;
        case 3:
        scriptEng.arrayPosition[1] = 0;
        saveRAM[scriptEng.arrayPosition[1]] = playerListPos;
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
        saveRAM[scriptEng.arrayPosition[1]] = 50000;
        scriptEng.arrayPosition[1]++;
        saveRAM[scriptEng.arrayPosition[1]] = 0;
        CheckResult() = WriteSaveRAMData();
        self->state++;
        SetFade(0, 0, 0, 255);
        LoadVideo_Script("Opening");
        break;
        case 4:
        scriptEng.arrayPosition[1] = 0;
        GVar("Options.GameMode") = 1;
        GVar("Options.SaveSlot") = 0;
        activeStageList = 1;
        playerListPos = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1]++;
        GVar("Player.Lives") = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1]++;
        GVar("Player.Score") = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1]++;
        stageListPosition = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1]++;
        GVar("SpecialStage.TimeStones") = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1]++;
        GVar("SpecialStage.ListPos") = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1]++;
        GVar("Player.ScoreBonus") = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1]++;
        GVar("Good_Future_List") = saveRAM[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[1]++;
        GVar("Good_Future_List") &= 0xFFFF;
        GVar("Good_Future_Count") = 0;
        GVar("Good_Future") = 0;
        GVar("MetalSonic_List") = GVar("Good_Future_List");
        GVar("MetalSonic_List") >>= 16;
        GVar("LampPost.Check") = 0;
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
        GVar("game.callbackParam0") = 0;
        Engine.Callback(NOTIFY_SAVESLOT_SELECT);
        stageMode = STAGEMODE_LOAD;
        SetFade(0, 0, 0, 255);
        break;
        case 5:
        GVar("game.mainMenuMode") = -1;
        GVar("Options.PhysicalControls") = 1;
        activeStageList = 0;
        stageListPosition = 2;
        stageMode = STAGEMODE_LOAD;
        SetFade(0, 0, 0, 255);
        break;
        case 6:
        GVar("game.mainMenuMode") = GVar("MAINMENUMODE_SETTINGS");
        activeStageList = 0;
        stageListPosition = 1;
        stageMode = STAGEMODE_LOAD;
        SetFade(0, 0, 0, 255);
        break;
        case 7:
        GVar("game.mainMenuMode") = GVar("MAINMENUMODE_SOUNDTRACK");
        activeStageList = 0;
        stageListPosition = 1;
        stageMode = STAGEMODE_LOAD;
        SetFade(0, 0, 0, 255);
        break;
        case 8:
        GVar("game.callbackParam0") = 0;
        Engine.Callback(NOTIFY_PLAYER_SET);
        GVar("game.mainMenuMode") = GVar("MAINMENUMODE_EXTRAS");
        activeStageList = 0;
        stageListPosition = 1;
        stageMode = STAGEMODE_LOAD;
        SetFade(0, 0, 0, 255);
        break;
        case 9:
        Engine.gameMode = 8;
        SetFade(0, 0, 0, 255);
        break;
        case 10:
        GVar("game.continueFlag") = 0;
        GVar("game.callbackResult") = -1;
        GVar("game.callbackParam0") = 0;
        Engine.Callback(NOTIFY_CHARACTER_SELECT);
        self->state = 11;
        break;
        case 11:
        if (GVar("game.callbackResult") > 0) {
            if (GVar("game.continueFlag") != 0) {
                self->state = 16;
            } else {
                CheckResult() = ReadSaveRAMData();
                self->values[0] = 0;
                self->state = 2;
            }
            StopMusic();
            HapticEffect_Script(31, 0, 0, 0);
        } else {
            if (GVar("game.callbackResult") == 0) {
                self->state = 1;
            }
        }
        break;
        case 12:
        self->values[6] += 30;
        if (self->values[6] >= SCREEN_XSIZE) {
            self->values[6] = 0;
            self->values[7] = self->values[0];
            self->state = 13;
        }
        break;
        case 13:
        self->values[6] += 30;
        if (self->values[6] >= SCREEN_CENTERX) {
            self->values[6] = SCREEN_CENTERX;
            self->state = 1;
            self->values[2] = 0;
        }
        break;
        case 14:
        self->values[6] -= 30;
        if (self->values[6] <= 0) {
            self->values[6] = SCREEN_XSIZE;
            self->values[7] = self->values[0];
            self->state = 15;
        }
        break;
        case 15:
        self->values[6] -= 30;
        if (self->values[6] <= SCREEN_CENTERX) {
            self->values[6] = SCREEN_CENTERX;
            self->state = 1;
            self->values[2] = 0;
        }
        break;
        case 16:
        self->values[3] += 4;
        if (self->values[3] >= 384) {
            self->state++;
        }
        SetFade(0, 0, 0, self->values[3]);
        break;
        case 17:
        Engine.gameMode = 2;
        SetFade(0, 0, 0, 255);
        break;
    }
}

void O_Title_Select::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[7];
    if (self->values[6] == SCREEN_CENTERX) {
        scriptEng.tempValue[0] += 7;
    }
    scriptEng.tempValue[1] = self->values[6];
    scriptEng.tempValue[2] = 198;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[0], FX_INK, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    if (self->values[6] == SCREEN_CENTERX) {
        if (self->values[0] != 0) {
            scriptEng.tempValue[3] = self->values[2];
            scriptEng.tempValue[3] &= 48;
            scriptEng.tempValue[3] >>= 3;
            scriptEng.tempValue[4] = SCREEN_CENTERX;
            scriptEng.tempValue[4] -= scriptEng.tempValue[3];
            DrawSpriteScreenFX_Script(16, FX_INK, scriptEng.tempValue[4], scriptEng.tempValue[2]);
        }
        if (self->values[0] < 6) {
            scriptEng.tempValue[3] = self->values[2];
            scriptEng.tempValue[3] &= 48;
            scriptEng.tempValue[3] >>= 3;
            scriptEng.tempValue[4] = SCREEN_CENTERX;
            scriptEng.tempValue[4] += scriptEng.tempValue[3];
            DrawSpriteScreenFX_Script(17, FX_INK, scriptEng.tempValue[4], scriptEng.tempValue[2]);
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
