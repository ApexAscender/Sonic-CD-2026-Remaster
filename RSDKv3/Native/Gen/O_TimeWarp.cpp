#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TimeWarp.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TimeWarp.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TimeWarp::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-16, -16, 32, 32, 83, 0);
    AddSpriteFrame(-16, -16, 32, 32, 83, 32);
    AddSpriteFrame(-16, -16, 32, 32, 83, 64);
    AddSpriteFrame(-16, -16, 32, 32, 83, 96);
    AddSpriteFrame(-16, -16, 32, 32, 83, 128);
    AddSpriteFrame(-16, -16, 32, 32, 83, 160);
    AddSpriteFrame(-16, -16, 32, 32, 83, 192);
    AddSpriteFrame(-16, -16, 32, 32, 83, 224);
    AddSpriteFrame(-16, -16, 32, 32, 115, 0);
    AddSpriteFrame(-16, -16, 32, 32, 115, 32);
    AddSpriteFrame(-16, -16, 32, 32, 115, 64);
    AddSpriteFrame(-16, -16, 32, 32, 115, 96);
    AddSpriteFrame(-16, -16, 32, 32, 115, 128);
    AddSpriteFrame(-16, -16, 32, 32, 115, 160);
}

void O_TimeWarp::ObjectDraw()
{
    Entity *self = Self();

    // The whole warp runs from THIS draw sub. After the setup (state 0) blanks the
    // stage, the engine's camera keeps scrolling the view to the (now-cleared)
    // player each frame, which pushes this controller — recreated at world (0,0)
    // with PRIORITY_BOUNDS — off-screen. Off-screen bounded objects aren't added
    // to the draw list, so ObjectDraw stops being called and the state machine
    // freezes on the green fade (the "stuck, only SFX" bug). Pin the view to (0,0)
    // for every post-setup state so the controller + cutscene stay on-screen and
    // the warp always runs to completion.
    if (self->state != 0) {
        xScrollOffset = 0;
        yScrollOffset = 0;
    }

    switch (self->state) {
        case 0:
        if (self->values[1] < 320) {
            if (self->values[1] == 0) {
                GVar("Warp.XPos") = pXPos();
                GVar("Warp.YPos") = pYPos();
                GVar("Warp.XVelocity") = pXVel();
                GVar("Warp.YVelocity") = pYVel();
                GVar("Warp.Speed") = pSpeed();
                GVar("Warp.MinRollSpeed") = PlayerValue(6);
                GVar("Warp.CollisionMode") = pCollisionMode();
                GVar("Warp.Gravity") = pGravity();
                if (pState() == PlayerStateID("Player_State_Static")) {
                    GVar("Warp.State") = PlayerStateID("Player_State_Air");
                } else {
                    if (pState() == PlayerStateID("Player_State_SpinningTop")) {
                        GVar("Warp.State") = PlayerStateID("Player_State_Air");
                    } else {
                        if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                            GVar("Warp.State") = PlayerStateID("Player_State_Air");
                        } else {
                            GVar("Warp.State") = pState();
                        }
                    }
                }
                GVar("Warp.Animation") = pAnimation();
                GVar("Warp.Angle") = pAngle();
                GVar("Warp.PlayerFrame") = pFrame();
                PlayerValue(4) = 1000;
                pControlMode() = -1;
                pVisible() = 0;
            }
            masterVolume -= 8;
            SetFade(208, 255, 224, self->values[1]);
            self->values[1] += 10;
        } else {
            if (playerListPos == 0) {
                if (debugMode == 0) {
                    SetAchievement(0, 100);
                }
            }
            HapticEffect_Script(91, 0, 0, 0);
            StopSfx(24);
            StopSfx(25);
            stageMode = 1;
            timeEnabled = 0;
            CallScriptFunctionNamed("StageSetup_SaveStageState", scriptSub);
            GVar("Rec_Milliseconds") = stageMilliseconds;
            GVar("Rec_Seconds") = stageSeconds;
            GVar("Rec_Minutes") = stageMinutes;
            GVar("Warp.Rings") = PlayerValue(0);
            scriptEng.tempValue[2] = objectEntityList[24].propertyValue;
            scriptEng.tempValue[0] = 0;
            while (scriptEng.tempValue[0] < 1184) {
                ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
                scriptEng.tempValue[0]++;
            }
            xScrollOffset = 0;
            yScrollOffset = 0;
            activeTileLayers[0] = 9;
            activeTileLayers[1] = 9;
            activeTileLayers[2] = 9;
            activeTileLayers[3] = 9;
            scriptEng.arrayPosition[0] = 0;
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Time Warp");
            objectEntityList[scriptEng.arrayPosition[0]].state = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = 320;
            objectEntityList[scriptEng.arrayPosition[0]].values[7] = scriptEng.tempValue[2];
            // Controller must run every frame regardless of screen scroll — it lives
            // at world (0,0) but drives the whole warp from its draw sub, so a bounds
            // cull would freeze the sequence. Force it always-active.
            objectEntityList[scriptEng.arrayPosition[0]].priority = PRIORITY_ACTIVE;
            scriptEng.arrayPosition[0]++;
            scriptEng.tempValue[0] = -32;
            while (scriptEng.tempValue[0] < 256) {
                scriptEng.tempValue[1] = 0;
                while (scriptEng.tempValue[1] < SCREEN_XSIZE) {
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Time Warp");
                    objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                    objectEntityList[scriptEng.arrayPosition[0]].frame = rand() % 27;
                    objectEntityList[scriptEng.arrayPosition[0]].frame >>= 2;
                    objectEntityList[scriptEng.arrayPosition[0]].frame <<= 2;
                    objectEntityList[scriptEng.arrayPosition[0]].XPos = (scriptEng.tempValue[1]) << 16;
                    objectEntityList[scriptEng.arrayPosition[0]].YPos = (scriptEng.tempValue[0]) << 16;
                    objectEntityList[scriptEng.arrayPosition[0]].XPos = ((objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16) + (16)) << 16;
                    objectEntityList[scriptEng.arrayPosition[0]].YPos = ((objectEntityList[scriptEng.arrayPosition[0]].YPos >> 16) + (16)) << 16;
                    objectEntityList[scriptEng.arrayPosition[0]].direction = rand() % 15;
                    objectEntityList[scriptEng.arrayPosition[0]].direction >>= 2;
                    scriptEng.arrayPosition[0]++;
                    scriptEng.tempValue[1] += 32;
                }
                scriptEng.tempValue[0] += 32;
            }
            objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Warp Sonic");
            objectEntityList[scriptEng.arrayPosition[0]].XPos = (SCREEN_CENTERX) << 16;
            objectEntityList[scriptEng.arrayPosition[0]].YPos = (480) << 16;
            SetFade(208, 255, 224, 255);
            PlaySfx(14, 0);
        }
        break;
        case 1:
        if (self->values[1] > 0) {
            SetFade(208, 255, 224, self->values[1]);
            self->values[1] -= 10;
        } else {
            self->state = 3;
        }
        break;
        case 2:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 1;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        self->frame++;
        if (self->frame == 28) {
            self->frame = 0;
        }
        self->YPos += 0x40000;
        if (self->YPos >= 0x1000000) {
            self->YPos -= 0x1200000;
        }
        break;
        case 3:
        break;
        case 4:
        self->values[1]++;
        if (self->values[1] == 40) {
            self->values[1] = 0;
            self->state = 5;
        }
        break;
        case 5:
        if (self->values[1] < 1800) {
            SetFade(208, 255, 224, self->values[1]);
            self->values[1] += 10;
        } else {
            SetFade(208, 255, 224, 255);
            switch (self->values[7]) {
                case 0:
                if (GVar("Warp.Destination") == 1) {
                    stageListPosition++;
                    self->values[7] = 1;
                } else {
                    if (GVar("Transporter_Destroyed") == 1) {
                        stageListPosition += 2;
                        self->values[7] = 2;
                    } else {
                        stageListPosition += 3;
                        self->values[7] = 3;
                    }
                }
                break;
                case 1:
                stageListPosition--;
                self->values[7] = 0;
                break;
                case 2:
                stageListPosition -= 2;
                self->values[7] = 0;
                break;
                case 3:
                stageListPosition -= 3;
                self->values[7] = 0;
                break;
            }
            GVar("Fade_Colour") = 208;
            GVar("Fade_Colour") <<= 16;
            scriptEng.tempValue[0] = 255;
            scriptEng.tempValue[0] <<= 8;
            GVar("Fade_Colour") += scriptEng.tempValue[0];
            GVar("Fade_Colour") += 224;
            stageMode = STAGEMODE_LOAD;
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
