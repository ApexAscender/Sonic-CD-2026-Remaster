#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_ActFinish.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ActFinish.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_ActFinish::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Display.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Display_t.gif");
    }
    AddSpriteFrame(0, 0, 136, 16, 0, 206);
    AddSpriteFrame(0, 0, 8, 16, 194, 223);
    AddSpriteFrame(0, 0, 16, 16, 203, 223);
    AddSpriteFrame(0, 0, 16, 16, 220, 223);
    AddSpriteFrame(0, 0, 113, 16, 137, 206);
    AddSpriteFrame(0, 0, 56, 16, 137, 223);
    AddSpriteFrame(0, 0, 39, 11, 1, 1);
    AddSpriteFrame(0, 0, 31, 11, 1, 33);
    AddSpriteFrame(0, 0, 31, 11, 1, 17);
    AddSpriteFrame(0, 0, 41, 11, 1, 107);
    AddSpriteFrame(0, 0, 8, 11, 1, 50);
    AddSpriteFrame(0, 0, 8, 11, 10, 50);
    AddSpriteFrame(0, 0, 8, 11, 19, 50);
    AddSpriteFrame(0, 0, 8, 11, 28, 50);
    AddSpriteFrame(0, 0, 8, 11, 1, 62);
    AddSpriteFrame(0, 0, 8, 11, 10, 62);
    AddSpriteFrame(0, 0, 8, 11, 19, 62);
    AddSpriteFrame(0, 0, 8, 11, 28, 62);
    AddSpriteFrame(0, 0, 8, 11, 1, 74);
    AddSpriteFrame(0, 0, 8, 11, 10, 74);
    AddSpriteFrame(-60, 0, 256, 16, 0, 240);
    AddSpriteFrame(-12, 0, 136, 16, 0, 223);
}

void O_ActFinish::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->XPos = -799;
        self->values[1] = 0x490;
        self->values[2] = 0x4E7;
        self->values[3] = 0x527;
        self->values[4] = 0x57A;
        self->state = 1;
        switch (stageMinutes) {
            case 0:
            if (stageSeconds < 30) {
                self->values[5] = 50000;
            } else {
                if (stageSeconds < 45) {
                    self->values[5] = 10000;
                } else {
                    self->values[5] = 5000;
                }
            }
            break;
            case 1:
            if (stageSeconds < 30) {
                self->values[5] = 4000;
            } else {
                self->values[5] = 3000;
            }
            break;
            case 2:
            self->values[5] = 2000;
            break;
            case 3:
            self->values[5] = 1000;
            break;
            case 4:
            self->values[5] = 500;
            break;
            case 5:
            self->values[5] = 100;
            break;
        }
        self->values[6] = objectEntityList[0].values[0];
        self->values[6] *= 100;
        break;
        case 1:
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 68;
        if (self->XPos < scriptEng.tempValue[0]) {
            self->XPos += 16;
            if (self->XPos > scriptEng.tempValue[0]) {
                self->XPos = scriptEng.tempValue[0];
            }
        } else {
            self->XPos = scriptEng.tempValue[0];
        }
        scriptEng.tempValue[0] -= 32;
        if (self->values[1] > scriptEng.tempValue[0]) {
            self->values[1] -= 16;
            if (self->values[1] < scriptEng.tempValue[0]) {
                self->values[1] = scriptEng.tempValue[0];
            }
        } else {
            self->values[1] = scriptEng.tempValue[0];
        }
        scriptEng.tempValue[0] += 9;
        if (self->values[2] > scriptEng.tempValue[0]) {
            self->values[2] -= 16;
            if (self->values[2] < scriptEng.tempValue[0]) {
                self->values[2] = scriptEng.tempValue[0];
            }
        } else {
            self->values[2] = scriptEng.tempValue[0];
        }
        if (self->values[3] > scriptEng.tempValue[0]) {
            self->values[3] -= 16;
            if (self->values[3] < scriptEng.tempValue[0]) {
                self->values[3] = scriptEng.tempValue[0];
            }
        } else {
            self->values[3] = scriptEng.tempValue[0];
        }
        if (self->values[4] > scriptEng.tempValue[0]) {
            self->values[4] -= 16;
            if (self->values[4] < scriptEng.tempValue[0]) {
                self->values[4] = scriptEng.tempValue[0];
            }
        } else {
            self->values[4] = scriptEng.tempValue[0];
            self->state = 2;
            self->values[0] = 0;
        }
        break;
        case 2:
        self->values[0]++;
        if (GVar("Options.Soundtrack") == 0) {
            if (self->values[0] > 299) {
                self->values[0] = 0;
                self->state = 3;
                if (playerListPos == 0) {
                    if (objectEntityList[24].propertyValue == 2) {
                        if (debugMode == 0) {
                            SetAchievement(2, 100);
                        }
                    }
                }
            }
        } else {
            if (self->values[0] > 429) {
                self->values[0] = 0;
                self->state = 3;
                if (playerListPos == 0) {
                    if (objectEntityList[24].propertyValue == 2) {
                        if (debugMode == 0) {
                            SetAchievement(2, 100);
                        }
                    }
                }
            }
        }
        break;
        case 3:
        if (self->values[6] > 0) {
            self->values[6] -= 100;
            GVar("Player.Score") += 100;
        }
        if (self->values[5] > 0) {
            self->values[5] -= 100;
            GVar("Player.Score") += 100;
        }
        CheckResult() = (self->values[6] > 0);
        scriptEng.tempValue[0] = CheckResult();
        CheckResult() = (self->values[5] > 0);
        scriptEng.tempValue[0] |= CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            self->values[0]++;
            if (self->values[0] == 2) {
                PlaySfx(16, 0);
                self->values[0] = 0;
            }
        } else {
            self->state = 4;
            self->values[0] = 0;
            PlaySfx(17, 0);
        }
        break;
        case 4:
        self->values[0]++;
        if (self->values[0] == 160) {
            self->values[0] = 0;
            self->state = 5;
            if (objectEntityList[0].type == TypeNameID("Blank Object")) {
                PlaySfx(19, 0);
            }
        }
        break;
        case 5:
        if (objectEntityList[0].type == TypeNameID("Blank Object")) {
            self->values[0] += 8;
            SetFade(208, 255, 224, self->values[0]);
            if (Engine.trialMode == 1) {
                if (self->values[0] == 1016) {
                    Engine.Callback(11);
                }
            }
            if (self->values[0] == 1024) {
                GVar("Fade_Colour") = 208;
                GVar("Fade_Colour") <<= 16;
                scriptEng.tempValue[0] = 255;
                scriptEng.tempValue[0] <<= 8;
                GVar("Fade_Colour") += scriptEng.tempValue[0];
                GVar("Fade_Colour") += 224;
                pDirection() = 0;
                self->values[0] = 0;
                GVar("LampPost.Check") = 0;
                GVar("Good_Future_Count") += GVar("Good_Future");
                GVar("Good_Future") = 0;
                GVar("Transporter_Destroyed") = 0;
                GVar("MetalSonic_Destroyed") = 0;
                if (actID == 2) {
                    if (GVar("Good_Future_Count") < 2) {
                        stageListPosition++;
                    }
                }
                if (actID == 3) {
                    GVar("Good_Future_Count") = 0;
                }
                switch (objectEntityList[24].propertyValue) {
                    case 0:
                    stageListPosition += 4;
                    break;
                    case 1:
                    stageListPosition += 3;
                    break;
                    case 2:
                    stageListPosition += 2;
                    break;
                    case 3:
                    stageListPosition++;
                    break;
                }
                if (GVar("Options.GameMode") == 1) {
                    scriptEng.arrayPosition[1] = GVar("Options.SaveSlot");
                    scriptEng.arrayPosition[1] <<= 3;
                    saveRAM[scriptEng.arrayPosition[1]] = playerListPos;
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("Player.Lives");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("Player.Score");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = stageListPosition;
                    saveRAM[scriptEng.arrayPosition[1]] += 81;
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("SpecialStage.TimeStones");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("SpecialStage.ListPos");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("Player.ScoreBonus");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("MetalSonic_List");
                    saveRAM[scriptEng.arrayPosition[1]] <<= 16;
                    saveRAM[scriptEng.arrayPosition[1]] += GVar("Good_Future_List");
                    CheckResult() = WriteSaveRAMData();
                }
                GVar("SpecialStage.NextZone") = stageListPosition;
                stageListPosition = GVar("SpecialStage.ListPos");
                activeStageList = 3;
                scriptEng.tempValue[0] = Engine.trialMode;
                if (stageListPosition >= stageListCount[activeStageList]) {
                    scriptEng.tempValue[0] = 1;
                }
                if (scriptEng.tempValue[0] == 0) {
                    stageMode = STAGEMODE_LOAD;
                } else {
                    activeStageList = 0;
                    stageListPosition = 0;
                    stageMode = STAGEMODE_LOAD;
                }
            }
        } else {
            self->values[0] += 4;
            SetFade(0, 0, 0, self->values[0]);
            if (Engine.trialMode == 1) {
                if (self->values[0] == 380) {
                    Engine.Callback(11);
                }
            }
            if (self->values[0] == 384) {
                GVar("Fade_Colour") = 0;
                self->values[0] = 0;
                GVar("LampPost.Check") = 0;
                pDirection() = 0;
                GVar("Good_Future_Count") += GVar("Good_Future");
                GVar("Good_Future") = 0;
                GVar("Transporter_Destroyed") = 0;
                GVar("MetalSonic_Destroyed") = 0;
                if (actID == 2) {
                    if (GVar("Good_Future_Count") < 2) {
                        stageListPosition++;
                    }
                }
                if (actID == 3) {
                    GVar("Good_Future_Count") = 0;
                }
                switch (objectEntityList[24].propertyValue) {
                    case 0:
                    stageListPosition += 4;
                    break;
                    case 1:
                    stageListPosition += 3;
                    break;
                    case 2:
                    stageListPosition += 2;
                    break;
                    case 3:
                    stageListPosition++;
                    break;
                }
                if (GVar("Options.GameMode") == 1) {
                    scriptEng.arrayPosition[1] = GVar("Options.SaveSlot");
                    scriptEng.arrayPosition[1] <<= 3;
                    saveRAM[scriptEng.arrayPosition[1]] = playerListPos;
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("Player.Lives");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("Player.Score");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = stageListPosition;
                    saveRAM[scriptEng.arrayPosition[1]]++;
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("SpecialStage.TimeStones");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("SpecialStage.ListPos");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("Player.ScoreBonus");
                    scriptEng.arrayPosition[1]++;
                    saveRAM[scriptEng.arrayPosition[1]] = GVar("MetalSonic_List");
                    saveRAM[scriptEng.arrayPosition[1]] <<= 16;
                    saveRAM[scriptEng.arrayPosition[1]] += GVar("Good_Future_List");
                    CheckResult() = WriteSaveRAMData();
                }
                if (GVar("Options.GameMode") == 3) {
                    GVar("TimeAttack.Result") = stageSeconds;
                    GVar("TimeAttack.Result") *= 100;
                    scriptEng.tempValue[0] = stageMinutes;
                    scriptEng.tempValue[0] *= 6000;
                    GVar("TimeAttack.Result") += scriptEng.tempValue[0];
                    GVar("TimeAttack.Result") += stageMilliseconds;
                    switch (GVar("TimeAttack.Round")) {
                        case 0:
                        if (GVar("TimeAttack.Result") < saveRAM[48]) {
                            saveRAM[48] = GVar("TimeAttack.Result");
                        }
                        break;
                        case 1:
                        if (GVar("TimeAttack.Result") < saveRAM[49]) {
                            saveRAM[49] = GVar("TimeAttack.Result");
                        }
                        break;
                    }
                    CheckResult() = WriteSaveRAMData();
                    activeStageList = 0;
                    stageListPosition = 11;
                }
                if (GVar("Options.GameMode") == 2) {
                    GVar("TimeAttack.Result") = stageSeconds;
                    GVar("TimeAttack.Result") *= 100;
                    scriptEng.tempValue[0] = stageMinutes;
                    scriptEng.tempValue[0] *= 6000;
                    GVar("TimeAttack.Result") += scriptEng.tempValue[0];
                    GVar("TimeAttack.Result") += stageMilliseconds;
                    activeStageList = 0;
                    stageListPosition = 2;
                    stageMode = STAGEMODE_LOAD;
                } else {
                    if (GVar("Options.GameMode") < 3) {
                        scriptEng.tempValue[0] = Engine.trialMode;
                    } else {
                        scriptEng.tempValue[0] = 0;
                    }
                    if (stageListPosition >= stageListCount[activeStageList]) {
                        scriptEng.tempValue[0] = 1;
                    }
                    if (scriptEng.tempValue[0] == 0) {
                        stageMode = STAGEMODE_LOAD;
                    } else {
                        activeStageList = 0;
                        stageListPosition = 0;
                        stageMode = STAGEMODE_LOAD;
                    }
                }
            }
        }
        break;
    }
}

void O_ActFinish::ObjectDraw()
{
    Entity *self = Self();

    if (GVar("Good_Future") == 0) {
        DrawSprite_ScreenXY(0, self->XPos, 65);
        DrawSprite_ScreenXY(4, self->values[1], 89);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += 128;
        DrawSprite_ScreenXY(5, scriptEng.tempValue[0], 89);
    } else {
        DrawSprite_ScreenXY(20, self->XPos, 65);
        DrawSprite_ScreenXY(21, self->values[1], 89);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += 140;
        DrawSprite_ScreenXY(5, scriptEng.tempValue[0], 89);
    }
    scriptEng.tempValue[0] += 64;
    DrawSprite_ScreenXY(actID, scriptEng.tempValue[0], 89);
    DrawSprite_ScreenXY(6, self->values[2], 121);
    scriptEng.tempValue[0] = self->values[2];
    scriptEng.tempValue[0] += 163;
    DrawNumbers_Script(10, scriptEng.tempValue[0], 121, GVar("Player.Score"), 6, 8, 0);
    DrawSprite_ScreenXY(7, self->values[3], 145);
    scriptEng.tempValue[0] = self->values[3];
    scriptEng.tempValue[0] += 40;
    DrawSprite_ScreenXY(9, scriptEng.tempValue[0], 145);
    scriptEng.tempValue[0] += 123;
    DrawNumbers_Script(10, scriptEng.tempValue[0], 145, self->values[6], 5, 8, 0);
    DrawSprite_ScreenXY(8, self->values[4], 169);
    scriptEng.tempValue[0] = self->values[4];
    scriptEng.tempValue[0] += 40;
    DrawSprite_ScreenXY(9, scriptEng.tempValue[0], 169);
    scriptEng.tempValue[0] += 123;
    DrawNumbers_Script(10, scriptEng.tempValue[0], 169, self->values[5], 5, 8, 0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
