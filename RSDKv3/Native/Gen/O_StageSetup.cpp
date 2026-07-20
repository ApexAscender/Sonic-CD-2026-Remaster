#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_StageSetup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from StageSetup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_StageSetup::ObjectStartup()
{
    if (GVar("Options.Soundtrack") == 0) {
        SetMusicTrack_Script("JP/ZoneComplete.ogg", 1, 0);
        SetMusicTrack_Script("JP/Invincibility.ogg", 2, 0);
        SetMusicTrack_Script("JP/SpeedShoes.ogg", 3, 0);
        SetMusicTrack_Script("JP/Boss.ogg", 4, 1);
        SetMusicTrack_Script("JP/GameOver.ogg", 5, 0);
    } else {
        SetMusicTrack_Script("US/ZoneComplete.ogg", 1, 0);
        SetMusicTrack_Script("US/Invincibility.ogg", 2, 0);
        SetMusicTrack_Script("US/SpeedShoes.ogg", 3, 0);
        SetMusicTrack_Script("US/Boss.ogg", 4, 196526);
        SetMusicTrack_Script("US/GameOver.ogg", 5, 0);
    }
    pauseEnabled = 0;
    // The stock script sets cameraStyle = Options.OriginalControls (the spin-dash
    // option), so the default (0 = Sonic 2 spin dash) selects CAMERASTYLE_FOLLOW —
    // a basic no-look-ahead camera. Sonic CD's levels + boss arenas are built for
    // the EXTENDED look-ahead camera (bosses spawn ahead of the trigger, fast falls
    // in Wacky Workbench need the tracking), so on FOLLOW the boss appears off-screen
    // and the camera reads as "static". Force the authentic CD extended camera; the
    // spin-dash style stays controlled by saveRAM[35] independently.
    cameraStyle = CAMERASTYLE_EXTENDED;
    cameraTarget = 0;
    GVar("Stage.DeathBoundary") = yBoundary2;
    GVar("Stage.DeathBoundary") <<= 16;
    objectEntityList[23].type = TypeNameID("Stage Setup");
    objectEntityList[23].priority = 1;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Stage Setup")) {
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Blank Object"), 0, 0, 0);
        }
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("HUD")) {
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            objectEntityList[24].type = TypeNameID("HUD");
            objectEntityList[24].priority = 1;
            objectEntityList[24].drawOrder = 6;
            objectEntityList[24].propertyValue = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
        }
        scriptEng.arrayPosition[0]++;
    }
    GVar("Warp.Timer") = 0;
    if (GVar("Warp.XPos") > 0) {
        pXPos() = GVar("Warp.XPos");
        pYPos() = GVar("Warp.YPos");
        pXVel() = GVar("Warp.XVelocity");
        pYVel() = GVar("Warp.YVelocity");
        pSpeed() = GVar("Warp.Speed");
        pCollisionMode() = GVar("Warp.CollisionMode");
        pGravity() = GVar("Warp.Gravity");
        pState() = GVar("Warp.State");
        pAnimation() = GVar("Warp.Animation");
        pFrame() = GVar("Warp.PlayerFrame");
        pAngle() = GVar("Warp.Angle");
        PlayerValue(0) = GVar("Warp.Rings");
        PlayerValue(6) = GVar("Warp.MinRollSpeed");
        stageMilliseconds = GVar("Rec_Milliseconds");
        stageSeconds = GVar("Rec_Seconds");
        stageMinutes = GVar("Rec_Minutes");
        StageSetup_LoadStageState();
    } else {
        scriptEng.arrayPosition[0] = 7168;
        while (scriptEng.arrayPosition[0] < 8192) {
            saveRAM[scriptEng.arrayPosition[0]] = 0;
            scriptEng.arrayPosition[0]++;
        }
        pDirection() = 0;
        pLeft() = 0;
        pRight() = 1;
        pControlMode() = -1;
        pSpeed() = 0;
        pAnimation() = GVar("ANI_STOPPED");
    }
    if (objectEntityList[24].propertyValue == 2) {
        GVar("Good_Future") = 1;
        GVar("Transporter_Destroyed") = 1;
    }
    if (GVar("SpecialStage.TimeStones") == 127) {
        GVar("Good_Future") = 1;
        GVar("Transporter_Destroyed") = 1;
    }
    GVar("Warp.Destination") = 0;
    GVar("Ring.ExtraLife") = 100;
    GVar("Player.RoofBarrier") = 0;
}

void O_StageSetup::ObjectMain()
{
    GVar("Ring.AniCount")++;
    if (GVar("Ring.AniCount") == 4) {
        GVar("Ring.AniCount") = 0;
        GVar("Ring.Frame")++;
        GVar("Ring.Frame") &= 7;
    }
    if (GVar("Options.GameMode") != 2) {
        if (GVar("Player.Score") >= GVar("Player.ScoreBonus")) {
            GVar("Player.Lives")++;
            GVar("Player.ScoreBonus") += 50000;
            if (playerListPos == 0) {
                PlaySfx(20, 0);
            } else {
                PlaySfx(21, 0);
            }
        }
    }
    GVar("Oscillation")++;
    GVar("Oscillation") &= 511;
    if (timeEnabled == 1) {
        if (stageMinutes == 10) {
            stageMinutes = 9;
            stageSeconds = 59;
            stageMilliseconds = 99;
            timeEnabled = 0;
            objectEntityList[0].type = TypeNameID("Player Object");
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
    }
}

void O_StageSetup::ObjectPlayerInteraction()
{
    scriptEng.tempValue[0] = pCollisionLeft();
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[0] += pXPos();
    scriptEng.tempValue[1] = xBoundary1;
    scriptEng.tempValue[1] <<= 16;
    if (scriptEng.tempValue[0] < scriptEng.tempValue[1]) {
        if (pRight() == 1) {
            pXVel() = 0x10000;
            pSpeed() = 0x10000;
        } else {
            pXVel() = 0;
            pSpeed() = 0;
        }
        pXPos() = scriptEng.tempValue[1];
        scriptEng.tempValue[0] = pCollisionLeft();
        scriptEng.tempValue[0] <<= 16;
        pXPos() -= scriptEng.tempValue[0];
    }
    scriptEng.tempValue[0] = pCollisionBottom();
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[0] += pYPos();
    if (scriptEng.tempValue[0] > GVar("Stage.DeathBoundary")) {
        CallScriptFunctionNamed("Player_Kill", scriptSub);
    }
}

void O_StageSetup::StageSetup_CheckGoodFuture()
{
    Entity *self = Self();

    if (GVar("Good_Future") == 1) {
        if (self->propertyValue > 0) {
            ResetObjectEntity(objectLoop, GVar("Flower_TypeNo"), 0, self->XPos, self->YPos);
            self->drawOrder = 4;
            self->state = 1;
        } else {
            if (objectEntityList[24].propertyValue > 0) {
                ResetObjectEntity(objectLoop, GVar("Flower_TypeNo"), 0, self->XPos, self->YPos);
                self->drawOrder = 4;
                self->state = 1;
            }
        }
    }
}

void O_StageSetup::StageSetup_SaveStageState()
{
    scriptEng.arrayPosition[0] = 32;
    scriptEng.arrayPosition[1] = 7168;
    scriptEng.tempValue[1] = objectEntityList[24].propertyValue;
    scriptEng.tempValue[1] += 4;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Blank Object")) {
            saveRAM[scriptEng.arrayPosition[1]] = (1) ? (saveRAM[scriptEng.arrayPosition[1]] | (1 << objectEntityList[24].propertyValue)) : (saveRAM[scriptEng.arrayPosition[1]] & ~(1 << objectEntityList[24].propertyValue));
        } else {
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Broken Monitor")) {
                saveRAM[scriptEng.arrayPosition[1]] = (1) ? (saveRAM[scriptEng.arrayPosition[1]] | (1 << objectEntityList[24].propertyValue)) : (saveRAM[scriptEng.arrayPosition[1]] & ~(1 << objectEntityList[24].propertyValue));
            } else {
                if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Future Post")) {
                    if (objectEntityList[scriptEng.arrayPosition[0]].state == 2) {
                        saveRAM[scriptEng.arrayPosition[1]] = (1) ? (saveRAM[scriptEng.arrayPosition[1]] | (1 << objectEntityList[24].propertyValue)) : (saveRAM[scriptEng.arrayPosition[1]] & ~(1 << objectEntityList[24].propertyValue));
                    } else {
                        saveRAM[scriptEng.arrayPosition[1]] = (0) ? (saveRAM[scriptEng.arrayPosition[1]] | (1 << objectEntityList[24].propertyValue)) : (saveRAM[scriptEng.arrayPosition[1]] & ~(1 << objectEntityList[24].propertyValue));
                    }
                } else {
                    if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Past Post")) {
                        if (objectEntityList[scriptEng.arrayPosition[0]].state == 2) {
                            saveRAM[scriptEng.arrayPosition[1]] = (1) ? (saveRAM[scriptEng.arrayPosition[1]] | (1 << objectEntityList[24].propertyValue)) : (saveRAM[scriptEng.arrayPosition[1]] & ~(1 << objectEntityList[24].propertyValue));
                        } else {
                            saveRAM[scriptEng.arrayPosition[1]] = (0) ? (saveRAM[scriptEng.arrayPosition[1]] | (1 << objectEntityList[24].propertyValue)) : (saveRAM[scriptEng.arrayPosition[1]] & ~(1 << objectEntityList[24].propertyValue));
                        }
                    } else {
                        saveRAM[scriptEng.arrayPosition[1]] = (0) ? (saveRAM[scriptEng.arrayPosition[1]] | (1 << objectEntityList[24].propertyValue)) : (saveRAM[scriptEng.arrayPosition[1]] & ~(1 << objectEntityList[24].propertyValue));
                        if (objectEntityList[scriptEng.arrayPosition[0]].type == GVar("Flower_TypeNo")) {
                            saveRAM[scriptEng.arrayPosition[1]] = (1) ? (saveRAM[scriptEng.arrayPosition[1]] | (1 << scriptEng.tempValue[1])) : (saveRAM[scriptEng.arrayPosition[1]] & ~(1 << scriptEng.tempValue[1]));
                        } else {
                            saveRAM[scriptEng.arrayPosition[1]] = (0) ? (saveRAM[scriptEng.arrayPosition[1]] | (1 << scriptEng.tempValue[1])) : (saveRAM[scriptEng.arrayPosition[1]] & ~(1 << scriptEng.tempValue[1]));
                        }
                    }
                }
            }
        }
        scriptEng.arrayPosition[0]++;
        scriptEng.arrayPosition[1]++;
    }
}

void O_StageSetup::StageSetup_LoadStageState()
{
    scriptEng.arrayPosition[0] = 32;
    scriptEng.arrayPosition[1] = 7168;
    scriptEng.tempValue[1] = objectEntityList[24].propertyValue;
    scriptEng.tempValue[1] += 4;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Ring")) {
            scriptEng.tempValue[0] = ((saveRAM[scriptEng.arrayPosition[1]] >> objectEntityList[24].propertyValue) & 1);
            if (scriptEng.tempValue[0] == 1) {
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            }
        } else {
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Monitor")) {
                scriptEng.tempValue[0] = ((saveRAM[scriptEng.arrayPosition[1]] >> objectEntityList[24].propertyValue) & 1);
                if (scriptEng.tempValue[0] == 1) {
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Broken Monitor");
                    objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                }
            } else {
                if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Future Post")) {
                    scriptEng.tempValue[0] = ((saveRAM[scriptEng.arrayPosition[1]] >> objectEntityList[24].propertyValue) & 1);
                    if (scriptEng.tempValue[0] == 1) {
                        objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                    }
                } else {
                    if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Past Post")) {
                        scriptEng.tempValue[0] = ((saveRAM[scriptEng.arrayPosition[1]] >> objectEntityList[24].propertyValue) & 1);
                        if (scriptEng.tempValue[0] == 1) {
                            objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                        }
                    } else {
                        scriptEng.tempValue[0] = ((saveRAM[scriptEng.arrayPosition[1]] >> scriptEng.tempValue[1]) & 1);
                        if (scriptEng.tempValue[0] == 1) {
                            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                        }
                    }
                }
            }
        }
        scriptEng.arrayPosition[0]++;
        scriptEng.arrayPosition[1]++;
    }
}

void O_StageSetup::EditorHelpers_DrawHitbox()
{
}

void O_StageSetup::EditorHelpers_DrawX()
{
}

void O_StageSetup::EditorHelpers_FindTimePeriod()
{
}

const Native::NativeFunctionDef O_StageSetup::funcs[6] = {
    { "StageSetup_CheckGoodFuture", O_StageSetup::StageSetup_CheckGoodFuture },
    { "StageSetup_SaveStageState", O_StageSetup::StageSetup_SaveStageState },
    { "StageSetup_LoadStageState", O_StageSetup::StageSetup_LoadStageState },
    { "EditorHelpers_DrawHitbox", O_StageSetup::EditorHelpers_DrawHitbox },
    { "EditorHelpers_DrawX", O_StageSetup::EditorHelpers_DrawX },
    { "EditorHelpers_FindTimePeriod", O_StageSetup::EditorHelpers_FindTimePeriod },
};

#endif // RETRO_USE_NATIVE_OBJECTS
