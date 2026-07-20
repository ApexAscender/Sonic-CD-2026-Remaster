#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_StageFinish.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from StageFinish.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_StageFinish::ObjectStartup()
{
    switch (Engine.language) {
        case 0:
        case 5:
        LoadSpriteSheet("Special/ScoreScreen.gif");
        break;
        case 1:
        LoadSpriteSheet("Special/ScoreScreen_FR.gif");
        break;
        case 2:
        LoadSpriteSheet("Special/ScoreScreen_IT.gif");
        break;
        case 3:
        LoadSpriteSheet("Special/ScoreScreen_DE.gif");
        break;
        case 4:
        LoadSpriteSheet("Special/ScoreScreen_ES.gif");
        break;
    }
    AddSpriteFrame(0, 0, 224, 48, 0, 63);
    AddSpriteFrame(0, 0, 184, 14, 1, 1);
    AddSpriteFrame(9, 0, 167, 14, 1, 16);
    AddSpriteFrame(-16, 0, 205, 14, 1, 48);
    AddSpriteFrame(0, 0, 39, 11, 1, 112);
    AddSpriteFrame(0, 0, 31, 11, 41, 112);
    AddSpriteFrame(0, 0, 31, 11, 73, 112);
    AddSpriteFrame(0, 0, 41, 11, 105, 112);
    AddSpriteFrame(0, 0, 40, 11, 147, 112);
    AddSpriteFrame(0, 0, 36, 11, 188, 112);
    AddSpriteFrame(0, 0, 8, 11, 220, 1);
    AddSpriteFrame(0, 0, 8, 11, 229, 1);
    AddSpriteFrame(0, 0, 8, 11, 238, 1);
    AddSpriteFrame(0, 0, 8, 11, 247, 1);
    AddSpriteFrame(0, 0, 8, 11, 220, 13);
    AddSpriteFrame(0, 0, 8, 11, 229, 13);
    AddSpriteFrame(0, 0, 8, 11, 238, 13);
    AddSpriteFrame(0, 0, 8, 11, 247, 13);
    AddSpriteFrame(0, 0, 8, 11, 238, 25);
    AddSpriteFrame(0, 0, 8, 11, 247, 25);
    AddSpriteFrame(0, 0, 16, 16, 1, 31);
    AddSpriteFrame(0, 0, 16, 16, 18, 31);
    AddSpriteFrame(0, 0, 16, 16, 35, 31);
    AddSpriteFrame(0, 0, 16, 16, 52, 31);
    AddSpriteFrame(0, 0, 16, 16, 69, 31);
    AddSpriteFrame(0, 0, 16, 16, 86, 31);
    AddSpriteFrame(0, 0, 16, 16, 103, 31);
    if (playerListPos == 0) {
        AddSpriteFrame(0, 0, 16, 23, 169, 24);
        AddSpriteFrame(0, 0, 16, 23, 186, 24);
    }
    if (playerListPos == 1) {
        AddSpriteFrame(0, 0, 16, 23, 139, 203);
        AddSpriteFrame(0, 0, 16, 23, 156, 203);
    }
}

void O_Special_StageFinish::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->XPos = -799;
        self->values[1] = 1255;
        self->values[2] = 1319;
        self->values[3] = 1402;
        self->values[4] = 1466;
        self->state = 1;
        self->values[0] = 0;
        self->alpha = 0;
        self->inkEffect = 2;
        if (self->propertyValue > 0) {
            self->values[5] = objectEntityList[4].values[1];
            self->values[5] *= 200;
            scriptEng.tempValue[0] = actID;
            scriptEng.tempValue[0]--;
            GVar("SpecialStage.TimeStones") = (1) ? (GVar("SpecialStage.TimeStones") | (1 << scriptEng.tempValue[0])) : (GVar("SpecialStage.TimeStones") & ~(1 << scriptEng.tempValue[0]));
        } else {
            self->values[5] = 0;
        }
        self->values[6] = objectEntityList[4].values[3];
        self->values[6] *= 200;
        stageListPosition = GVar("SpecialStage.NextZone");
        activeStageList = 1;
        if (GVar("SpecialStage.TimeStones") < 127) {
            scriptEng.tempValue[0] = 0;
            while (scriptEng.tempValue[0] == 0) {
                GVar("SpecialStage.ListPos")++;
                if (GVar("SpecialStage.ListPos") > 6) {
                    GVar("SpecialStage.ListPos") = 0;
                }
                scriptEng.tempValue[1] = ((GVar("SpecialStage.TimeStones") >> GVar("SpecialStage.ListPos")) & 1);
                if (scriptEng.tempValue[1] == 0) {
                    scriptEng.tempValue[0] = 1;
                }
            }
        } else {
            scriptEng.tempValue[0] = stageListPosition;
            scriptEng.tempValue[0] %= 10;
            if (scriptEng.tempValue[0] == 9) {
                stageListPosition--;
            }
            GVar("Good_Future_Count") = 2;
            if (playerListPos == 0) {
                SetAchievement(8, 100);
            }
        }
        break;
        case 1:
        if (self->values[0] == 120) {
            self->state = 2;
            self->values[0] = 256;
            if (GVar("SpecialStage.TimeStones") > 126) {
                self->propertyValue = 2;
            }
            PlayMusic(1);
        } else {
            self->values[0]++;
            masterVolume--;
            if (self->values[0] == 24) {
                scriptEng.tempValue[0] = 0;
                while (scriptEng.tempValue[0] < 30) {
                    ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
                    scriptEng.tempValue[0]++;
                }
                scriptEng.tempValue[0]++;
                while (scriptEng.tempValue[0] < 1184) {
                    ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
                    scriptEng.tempValue[0]++;
                }
                activeTileLayers[0] = 9;
                activeTileLayers[1] = 9;
                activeTileLayers[2] = 9;
                activeTileLayers[3] = 9;
                pControlMode() = 0;
                keyDown.left = 0;
                keyDown.right = 0;
                pDirection() = 0;
            }
        }
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] <<= 4;
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        SetFade(208, 255, 224, scriptEng.tempValue[0]);
        break;
        case 2:
        self->values[0] -= 16;
        if (self->values[0] == 0) {
            self->state = 3;
        }
        SetFade(208, 255, 224, self->values[0]);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 88;
        if (self->XPos < scriptEng.tempValue[0]) {
            self->XPos += 16;
            if (self->XPos > scriptEng.tempValue[0]) {
                self->XPos = scriptEng.tempValue[0];
            }
        } else {
            self->XPos = scriptEng.tempValue[0];
        }
        scriptEng.tempValue[0]++;
        if (self->values[1] > scriptEng.tempValue[0]) {
            self->values[1] -= 16;
            if (self->values[1] < scriptEng.tempValue[0]) {
                self->values[1] = scriptEng.tempValue[0];
            }
        } else {
            self->values[1] = scriptEng.tempValue[0];
        }
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
            self->state = 4;
            self->values[0] = 0;
        }
        break;
        case 3:
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 88;
        if (self->XPos < scriptEng.tempValue[0]) {
            self->XPos += 16;
            if (self->XPos > scriptEng.tempValue[0]) {
                self->XPos = scriptEng.tempValue[0];
            }
        } else {
            self->XPos = scriptEng.tempValue[0];
        }
        scriptEng.tempValue[0]++;
        if (self->values[1] > scriptEng.tempValue[0]) {
            self->values[1] -= 16;
            if (self->values[1] < scriptEng.tempValue[0]) {
                self->values[1] = scriptEng.tempValue[0];
            }
        } else {
            self->values[1] = scriptEng.tempValue[0];
        }
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
            self->state = 4;
            self->values[0] = 0;
        }
        break;
        case 4:
        if (self->alpha < 255) {
            scriptEng.tempValue[0] = self->alpha;
            scriptEng.tempValue[0] += 8;
            if (scriptEng.tempValue[0] > 255) {
                scriptEng.tempValue[0] = 255;
            }
            self->alpha = scriptEng.tempValue[0];
        }
        if (GVar("Options.Soundtrack") == 0) {
            self->values[0]++;
            if (self->values[0] > 299) {
                self->values[0] = 0;
                self->state = 5;
            }
        } else {
            self->values[0]++;
            if (self->values[0] > 429) {
                self->values[0] = 0;
                self->state = 5;
            }
        }
        break;
        case 5:
        if (self->values[6] > 0) {
            self->values[6] -= 200;
            GVar("Player.Score") += 200;
            if (self->values[6] < 0) {
                GVar("Player.Score") += self->values[6];
                self->values[6] = 0;
            }
        } else {
            if (self->values[5] > 0) {
                self->values[5] -= 200;
                GVar("Player.Score") += 200;
                if (self->values[5] < 0) {
                    GVar("Player.Score") += self->values[5];
                    self->values[5] = 0;
                }
            }
        }
        if (GVar("Player.Score") >= GVar("Player.ScoreBonus")) {
            self->values[7]++;
            GVar("Player.Lives")++;
            GVar("Player.ScoreBonus") += 50000;
            if (playerListPos == 0) {
                PlaySfx(20, 0);
            } else {
                PlaySfx(21, 0);
            }
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
            self->state = 6;
            self->values[0] = 0;
            PlaySfx(17, 0);
        }
        break;
        case 6:
        self->values[0]++;
        if (self->values[0] == 160) {
            self->values[0] = 0;
            self->state = 7;
            if (objectEntityList[0].type == TypeNameID("Blank Object")) {
                PlaySfx(19, 0);
            }
        }
        break;
        case 7:
        if (objectEntityList[0].type == TypeNameID("Blank Object")) {
            self->values[0] += 8;
            SetFade(208, 255, 224, self->values[0]);
            if (self->values[0] == 1024) {
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
                    CheckResult() = WriteSaveRAMData();
                }
                GVar("Fade_Colour") = 208;
                GVar("Fade_Colour") <<= 16;
                scriptEng.tempValue[0] = 255;
                scriptEng.tempValue[0] <<= 8;
                GVar("Fade_Colour") += scriptEng.tempValue[0];
                GVar("Fade_Colour") += 224;
                if (stageListPosition < stageListCount[activeStageList]) {
                    stageMode = STAGEMODE_LOAD;
                } else {
                    activeStageList = 0;
                    stageListPosition = 0;
                    stageMode = STAGEMODE_LOAD;
                }
            }
        }
        break;
        case 8:
        if (self->values[0] < 480) {
            self->values[0] += 4;
            masterVolume--;
        } else {
            StopMusic();
            GVar("TimeAttack.Result") = stageSeconds;
            GVar("TimeAttack.Result") *= 100;
            scriptEng.tempValue[0] = stageMinutes;
            scriptEng.tempValue[0] *= 6000;
            GVar("TimeAttack.Result") += scriptEng.tempValue[0];
            GVar("TimeAttack.Result") += stageMilliseconds;
            activeStageList = 0;
            stageListPosition = 2;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 9:
        if (self->values[0] < 480) {
            self->values[0] += 4;
            masterVolume--;
        } else {
            StopMusic();
            activeStageList = 0;
            stageListPosition = 7;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
    }
}

void O_Special_StageFinish::ObjectDraw()
{
    Entity *self = Self();

    if (self->state != 9) {
        if (self->state > 1) {
            scriptEng.tempValue[0] = 0;
            while (scriptEng.tempValue[0] < 240) {
                scriptEng.tempValue[1] = 0;
                while (scriptEng.tempValue[1] < 360) {
                    DrawSprite_ScreenXY(0, scriptEng.tempValue[1], scriptEng.tempValue[0]);
                    scriptEng.tempValue[1] += 224;
                }
                scriptEng.tempValue[0] += 48;
            }
            scriptEng.tempValue[0] = 0;
            while (scriptEng.tempValue[0] < 240) {
                scriptEng.tempValue[1] = 448;
                while (scriptEng.tempValue[1] < 720) {
                    DrawSprite_ScreenXY(0, scriptEng.tempValue[1], scriptEng.tempValue[0]);
                    scriptEng.tempValue[1] += 224;
                }
                scriptEng.tempValue[0] += 48;
            }
            scriptEng.tempValue[0] = 0;
            scriptEng.tempValue[1] = 20;
            scriptEng.tempValue[2] = SCREEN_CENTERX;
            scriptEng.tempValue[2] -= 79;
            while (scriptEng.tempValue[0] < 7) {
                scriptEng.tempValue[3] = ((GVar("SpecialStage.TimeStones") >> scriptEng.tempValue[0]) & 1);
                scriptEng.tempValue[0]++;
                if (scriptEng.tempValue[3] == 1) {
                    DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[2], 81);
                }
                scriptEng.tempValue[1]++;
                scriptEng.tempValue[2] += 24;
            }
        }
        switch (self->propertyValue) {
            case 0:
            DrawSprite_ScreenXY(1, self->XPos, 50);
            break;
            case 1:
            DrawSprite_ScreenXY(2, self->XPos, 50);
            break;
            case 2:
            DrawSprite_ScreenXY(3, self->XPos, 50);
            break;
        }
        DrawSprite_ScreenXY(4, self->values[1], 105);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += 176;
        DrawNumbers_Script(10, scriptEng.tempValue[0], 105, GVar("Player.Score"), 6, 8, 0);
        DrawSprite_ScreenXY(5, self->values[2], 129);
        scriptEng.tempValue[0] = self->values[2];
        scriptEng.tempValue[0] += 40;
        DrawSprite_ScreenXY(7, scriptEng.tempValue[0], 129);
        scriptEng.tempValue[0] += 136;
        DrawNumbers_Script(10, scriptEng.tempValue[0], 129, self->values[6], 5, 8, 0);
        DrawSprite_ScreenXY(6, self->values[3], 153);
        scriptEng.tempValue[0] = self->values[3];
        scriptEng.tempValue[0] += 40;
        DrawSprite_ScreenXY(7, scriptEng.tempValue[0], 153);
        scriptEng.tempValue[0] += 136;
        DrawNumbers_Script(10, scriptEng.tempValue[0], 153, self->values[5], 5, 8, 0);
        DrawSprite_ScreenXY(8, self->values[4], 177);
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] += 49;
        DrawSprite_ScreenXY(9, scriptEng.tempValue[0], 177);
        scriptEng.tempValue[0] += 86;
        self->frame++;
        self->frame &= 15;
        scriptEng.tempValue[1] = self->frame;
        scriptEng.tempValue[1] >>= 3;
        scriptEng.tempValue[1] += 27;
        scriptEng.tempValue[2] = self->values[7];
        while (scriptEng.tempValue[2] > 0) {
            DrawSprite_ScreenXY(scriptEng.tempValue[1], scriptEng.tempValue[0], 177);
            scriptEng.tempValue[2]--;
            scriptEng.tempValue[0] += 24;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
