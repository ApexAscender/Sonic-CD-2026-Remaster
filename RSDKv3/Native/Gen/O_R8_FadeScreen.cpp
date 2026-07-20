#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_FadeScreen.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FadeScreen.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_FadeScreen::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 480) {
            self->values[0] += 4;
            masterVolume--;
        } else {
            self->values[0] = 224;
            if (self->propertyValue == 0) {
                self->state++;
            } else {
                self->state += 2;
            }
        }
        if (self->propertyValue == 1) {
            SetFade(0, 0, 0, self->values[0]);
        } else {
            SetFade(224, 224, 224, self->values[0]);
        }
        break;
        case 1:
        if (self->values[0] > 0) {
            masterVolume--;
            self->values[0] -= 16;
        } else {
            StopMusic();
            scriptEng.tempValue[0] = 0;
            if (scriptEng.tempValue[0] != 0) {
                self->state = 4;
            } else {
                if (GVar("Options.GameMode") == 2) {
                    GVar("TimeAttack.Result") = stageSeconds;
                    GVar("TimeAttack.Result") *= 100;
                    scriptEng.tempValue[0] = stageMinutes;
                    scriptEng.tempValue[0] *= 6000;
                    GVar("TimeAttack.Result") += scriptEng.tempValue[0];
                    GVar("TimeAttack.Result") += stageMilliseconds;
                    scriptEng.tempValue[0] = stageListPosition;
                    scriptEng.tempValue[0] %= 10;
                    scriptEng.tempValue[0] >>= 2;
                    scriptEng.tempValue[1] = stageListPosition;
                    scriptEng.tempValue[1] /= 10;
                    scriptEng.tempValue[1] *= 3;
                    scriptEng.tempValue[0] += scriptEng.tempValue[1];
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[1] = stageSeconds;
                    scriptEng.tempValue[1] *= 100;
                    scriptEng.tempValue[2] = stageMinutes;
                    scriptEng.tempValue[2] *= 6000;
                    scriptEng.tempValue[1] += scriptEng.tempValue[2];
                    scriptEng.tempValue[1] += stageMilliseconds;
                    SetLeaderboard(scriptEng.tempValue[0], scriptEng.tempValue[1]);
                    stageListPosition = 2;
                } else {
                    Engine.Callback(4);
                    if (GVar("Player.Score") > 0) {
                        if (GVar("Options.GameMode") == 1) {
                            if (debugMode == 0) {
                                SetLeaderboard(0, GVar("Player.Score"));
                            }
                        }
                    }
                    if (playerListPos == 0) {
                        if (GVar("SpecialStage.TimeStones") > 126) {
                            LoadVideo_Script("Good_Ending");
                        } else {
                            if (GVar("Good_Future_List") > 0x3FFE) {
                                LoadVideo_Script("Good_Ending");
                            } else {
                                LoadVideo_Script("Bad_Ending");
                            }
                        }
                    }
                    if (saveRAM[36] == 0) {
                        saveRAM[36] = 1;
                        CheckResult() = WriteSaveRAMData();
                        stageListPosition = 8;
                    } else {
                        stageListPosition = 0;
                    }
                    if (Engine.gameMode == 8) {
                        Engine.gameMode = 1;
                    }
                    if (playerListPos == 1) {
                        stageListPosition = 7;
                    }
                }
                activeStageList = 0;
                stageMode = STAGEMODE_LOAD;
            }
        }
        SetFade(self->values[0], self->values[0], self->values[0], 255);
        break;
        case 2:
        if (self->values[0] > 0) {
            masterVolume--;
            self->values[0] -= 16;
        } else {
            StopMusic();
            stageListPosition += 2;
            stageMode = STAGEMODE_LOAD;
        }
        break;
        case 3:
        break;
        case 4:
        SetFade(255, 255, 255, 255);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
