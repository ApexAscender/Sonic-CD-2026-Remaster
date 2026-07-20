#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_SpecialSetup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpecialSetup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_SpecialSetup::ObjectStartup()
{
    LoadSpriteSheet("Special/Objects.gif");
    stageLayouts[0].type = 4;
    if (GVar("Options.Soundtrack") == 0) {
        SetMusicTrack_Script("JP/SpecialStage.ogg", 0, 1);
        SetMusicTrack_Script("JP/ZoneComplete.ogg", 1, 0);
    } else {
        SetMusicTrack_Script("US/SpecialStage.ogg", 0, 270972);
        SetMusicTrack_Script("US/ZoneComplete.ogg", 1, 0);
    }
    pauseEnabled = 0;
    if (GVar("Options.GameMode") == 2) {
        timeEnabled = 0;
    } else {
        timeEnabled = 1;
    }
    objectEntityList[23].type = TypeNameID("Special Setup");
    objectEntityList[23].priority = 1;
    objectEntityList[23].drawOrder = 2;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Blank Object")) {
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Blank Object"), 0, 0, 0);
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Special_SpecialSetup::ObjectMain()
{
    vertexCount = 0;
    faceCount = 0;
    GVar("Oscillation")++;
    if (GVar("Oscillation") == 512) {
        GVar("Oscillation") = 0;
    }
    if (objectEntityList[4].values[0] > 0) {
        if (timeEnabled == 1) {
            if (GVar("Options.GameMode") != 2) {
                objectEntityList[4].values[2]++;
                if (objectEntityList[4].values[2] == 60) {
                    objectEntityList[4].values[2] = 0;
                    if (objectEntityList[4].values[1] > 0) {
                        if (objectEntityList[4].values[1] < 6) {
                            PlaySfx(globalSFXCount + 7, 0);
                        }
                        objectEntityList[4].values[1]--;
                        if (objectEntityList[4].values[1] < 20) {
                            scriptEng.arrayPosition[0] = objectEntityList[4].values[6];
                            if (objectEntityList[scriptEng.arrayPosition[0]].type != TypeNameID("UFO")) {
                                PlaySfx(globalSFXCount + 5, 0);
                                scriptEng.arrayPosition[1] = scriptEng.arrayPosition[0];
                                scriptEng.arrayPosition[1]++;
                                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("UFO");
                                objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
                                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 2;
                                objectEntityList[scriptEng.arrayPosition[0]].XPos = objectEntityList[scriptEng.arrayPosition[1]].XPos;
                                objectEntityList[scriptEng.arrayPosition[0]].YPos = objectEntityList[scriptEng.arrayPosition[1]].YPos;
                            }
                        }
                    } else {
                        if (GVar("Options.GameMode") != 2) {
                            objectEntityList[30].type = TypeNameID("Stage Finish");
                            if (actID == 8) {
                                objectEntityList[30].state = 9;
                                objectEntityList[30].drawOrder = 7;
                            } else {
                                objectEntityList[30].drawOrder = 6;
                            }
                            pControlMode() = -1;
                        }
                    }
                }
                if (objectEntityList[4].values[7] > 0) {
                    if (objectEntityList[4].values[7] > 1) {
                        if (objectEntityList[4].values[7] > 20) {
                            scriptEng.tempValue[0] = objectEntityList[4].values[2];
                            scriptEng.tempValue[0] &= 1;
                            if (objectEntityList[4].values[1] > 0) {
                                objectEntityList[4].values[1] -= scriptEng.tempValue[0];
                            } else {
                                if (GVar("Options.GameMode") != 2) {
                                    objectEntityList[30].type = TypeNameID("Stage Finish");
                                    if (actID == 8) {
                                        objectEntityList[30].state = 9;
                                        objectEntityList[30].drawOrder = 7;
                                    } else {
                                        objectEntityList[30].drawOrder = 6;
                                    }
                                    pControlMode() = -1;
                                }
                            }
                        } else {
                            if (objectEntityList[3].type != TypeNameID("WaterSplash")) {
                                objectEntityList[4].values[7] = 0;
                            }
                        }
                        objectEntityList[4].values[7]--;
                    } else {
                        if (objectEntityList[3].type != TypeNameID("WaterSplash")) {
                            objectEntityList[4].values[7] = 0;
                        } else {
                            scriptEng.tempValue[0] = objectEntityList[4].values[2];
                            scriptEng.tempValue[0] &= 1;
                            if (objectEntityList[4].values[1] > 0) {
                                objectEntityList[4].values[1] -= scriptEng.tempValue[0];
                            } else {
                                if (GVar("Options.GameMode") != 2) {
                                    objectEntityList[30].type = TypeNameID("Stage Finish");
                                    if (actID == 8) {
                                        objectEntityList[30].state = 9;
                                        objectEntityList[30].drawOrder = 7;
                                    } else {
                                        objectEntityList[30].drawOrder = 6;
                                    }
                                    pControlMode() = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void O_Special_SpecialSetup::ObjectDraw()
{
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = drawListEntries[3].listSize;
    while (scriptEng.tempValue[0] < scriptEng.tempValue[1]) {
        scriptEng.tempValue[2] = scriptEng.tempValue[1];
        scriptEng.tempValue[2]--;
        while (scriptEng.tempValue[2] > scriptEng.tempValue[0]) {
            scriptEng.tempValue[3] = scriptEng.tempValue[2];
            scriptEng.tempValue[2]--;
            scriptEng.arrayPosition[0] = drawListEntries[3].entityRefs[scriptEng.tempValue[3]];
            scriptEng.arrayPosition[1] = drawListEntries[3].entityRefs[scriptEng.tempValue[2]];
            if (objectEntityList[scriptEng.arrayPosition[0]].values[5] > objectEntityList[scriptEng.arrayPosition[1]].values[5]) {
                drawListEntries[3].entityRefs[scriptEng.tempValue[2]] = scriptEng.arrayPosition[0];
                drawListEntries[3].entityRefs[scriptEng.tempValue[3]] = scriptEng.arrayPosition[1];
            }
        }
        scriptEng.tempValue[0]++;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
