#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Players_PlayerObject.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PlayerObject.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Players_PlayerObject::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Player Object")) {
            switch (playerListPos) {
                case 0:
                ResetObjectEntity(0, TypeNameID("Player Object"), 0, objectEntityList[scriptEng.arrayPosition[0]].XPos, objectEntityList[scriptEng.arrayPosition[0]].YPos);
                pXPos() = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                pYPos() = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                LoadAnimation_Script("Sonic.Ani");
                BindPlayerToObject_Script(0, 0);
                pState() = PlayerStateID("Player_State_Air");
                PlrEntity()->priority = 1;
                PlrEntity()->drawOrder = 4;
                pTopSpeed() = 0x60000;
                pAccel() = 0xC00;
                pDecel() = 0xC00;
                pAirAccel() = 0x1800;
                pAirDecel() = 0x600;
                pGravityStrength() = 0x3800;
                pJumpStrength() = 0x68000;
                pJumpCap() = -0x40000;
                pRollingDecel() = 0x2000;
                PlayerValue(9) = -5;
                PlayerValue(10) = PlayerStateID("Player_State_Static");
                if (GVar("Options.OriginalControls") == 0) {
                    PlayerValue(11) = PlayerFuncID("Player_Action_Peelout_S2");
                    PlayerValue(12) = PlayerFuncID("Player_Action_Spindash_S2");
                } else {
                    PlayerValue(11) = PlayerFuncID("Player_Action_Peelout_CD");
                    PlayerValue(12) = PlayerFuncID("Player_Action_Spindash_CD");
                }
                break;
                case 1:
                ResetObjectEntity(0, TypeNameID("Player Object"), 0, objectEntityList[scriptEng.arrayPosition[0]].XPos, objectEntityList[scriptEng.arrayPosition[0]].YPos);
                pXPos() = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                pYPos() = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                LoadAnimation_Script("Tails.Ani");
                BindPlayerToObject_Script(0, 0);
                pState() = PlayerStateID("Player_State_Air");
                PlrEntity()->priority = 1;
                PlrEntity()->drawOrder = 4;
                pTopSpeed() = 0x60000;
                pAccel() = 0xC00;
                pDecel() = 0xC00;
                pAirAccel() = 0x1800;
                pAirDecel() = 0x600;
                pGravityStrength() = 0x3800;
                pJumpStrength() = 0x68000;
                pJumpCap() = -0x40000;
                pRollingDecel() = 0x2000;
                PlayerValue(9) = -1;
                PlayerValue(10) = PlayerFuncID("Player_Action_DblJumpTails");
                PlayerValue(11) = PlayerFuncID("Player_Action_Jump");
                if (GVar("Options.OriginalControls") == 0) {
                    PlayerValue(12) = PlayerFuncID("Player_Action_Spindash_S2");
                } else {
                    PlayerValue(12) = PlayerFuncID("Player_Action_Spindash_CD");
                }
                break;
            }
            GVar("ANI_SPINNING_TOP") = GetAnimationByName("Spinning Top");
            GVar("ANI_RAMP_RUNNING1") = GetAnimationByName("3D Ramp 1");
            GVar("ANI_RAMP_RUNNING2") = GetAnimationByName("3D Ramp 2");
            GVar("ANI_RAMP_RUNNING3") = GetAnimationByName("3D Ramp 3");
            GVar("ANI_RAMP_RUNNING4") = GetAnimationByName("3D Ramp 4");
            GVar("ANI_RAMP_RUNNING5") = GetAnimationByName("3D Ramp 5");
            GVar("ANI_RAMP_RUNNING6") = GetAnimationByName("3D Ramp 6");
            GVar("ANI_ROLL3D") = GetAnimationByName("3D Ramp 7");
            GVar("ANI_SIZE_CHANGE") = GetAnimationByName("Size Change");
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Blank Object"), 0, 0, 0);
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Players_PlayerObject::ObjectMain()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[0] = debugMode;
    if (scriptEng.tempValue[0] == 1) {
        if (keyPress.B == 1) {
            self->type = TypeNameID("Debug Mode");
            if (playerListPos != 0) {
                objectEntityList[objectLoop + 1].type = TypeNameID("Blank Object");
            }
            pYVel() = 0;
            pState() = PlayerStateID("Player_State_Static");
            pFrame() = 0;
            pRotation() = 0;
            pObjectInteractions() = 0;
            pTileCollisions() = 1;
            PlrEntity()->drawOrder = 4;
            PlayerValue(1) = 0;
            PlayerValue(6) = 0;
            cameraEnabled = 1;
            cameraStyle = GVar("Options.OriginalControls");
        } else {
            Player_ProcessUpdate();
            CallPlayerFunc(pState(), scriptSub);
            ProcessAnimation_Script();
            if (pAnimation() == GVar("ANI_JUMPING")) {
                cameraAdjustY = PlayerValue(9);
            } else {
                if (cameraAdjustY == PlayerValue(9)) {
                    cameraAdjustY = 0;
                    pYPos() = ((pYPos() >> 16) + (PlayerValue(9))) << 16;
                }
            }
            if (pYVel() > 0x100000) {
                pYVel() = 0x100000;
            }
            PlayerTileCollision_Script();
            if (CheckResult() == 1) {
                if (pAnimation() == GVar("ANI_JUMPING")) {
                    if (pDown() == 0) {
                        pAnimation() = GVar("ANI_WALKING");
                        cameraAdjustY = 0;
                        pYPos() = ((pYPos() >> 16) + (PlayerValue(9))) << 16;
                    }
                }
            }
        }
    } else {
        Player_ProcessUpdate();
        CallPlayerFunc(pState(), scriptSub);
        ProcessAnimation_Script();
        if (pAnimation() == GVar("ANI_JUMPING")) {
            cameraAdjustY = PlayerValue(9);
        } else {
            if (cameraAdjustY == PlayerValue(9)) {
                cameraAdjustY = 0;
                pYPos() = ((pYPos() >> 16) + (PlayerValue(9))) << 16;
            }
        }
        if (pYVel() > 0x100000) {
            pYVel() = 0x100000;
        }
        PlayerTileCollision_Script();
        if (CheckResult() == 1) {
            if (pAnimation() == GVar("ANI_JUMPING")) {
                if (pDown() == 0) {
                    pAnimation() = GVar("ANI_WALKING");
                    cameraAdjustY = 0;
                    pYPos() = ((pYPos() >> 16) + (PlayerValue(9))) << 16;
                }
            }
        }
    }
}

void O_Players_PlayerObject::ObjectDraw()
{
    if (pAnimation() != pPrevAnimation()) {
        pPrevAnimation() = pAnimation();
        pFrame() = 0;
        pAnimationTimer() = 0;
        pAnimationSpeed() = 0;
    }
    DrawPlayerAnimation_Script();
}

void O_Players_PlayerObject::Player_BadnikBreak()
{
    Entity *self = Self();

    CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
    scriptEng.tempValue[0] = CheckResult();
    CheckResult() = (pAnimation() == GVar("ANI_SPINDASH"));
    scriptEng.tempValue[0] |= CheckResult();
    scriptEng.arrayPosition[0] = Plr()->entityNo;
    scriptEng.arrayPosition[0] += 2;
    CheckResult() = (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Invincibility"));
    scriptEng.tempValue[0] |= CheckResult();
    if (GVar("Warp.Timer") > 0) {
        scriptEng.tempValue[0] |= 1;
    }
    if (pAnimation() == GVar("ANI_FLYING")) {
        CheckResult() = (pYPos() > self->YPos);
        scriptEng.tempValue[0] |= CheckResult();
    }
    if (scriptEng.tempValue[0] == 1) {
        ResetObjectEntity(objectLoop, GVar("Flower_TypeNo"), 0, self->XPos, self->YPos);
        self->drawOrder = 4;
        CreateTempObject(TypeNameID("Smoke Puff"), 0, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
        CreateTempObject(TypeNameID("Object Score"), objectEntityList[26].values[0], self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
        PlaySfx(8, 0);
        if (pYVel() > 0) {
            pYVel() = -pYVel();
        } else {
            pYVel() += 0xC000;
        }
        switch (objectEntityList[26].values[0]) {
            case 0:
            GVar("Player.Score") += 100;
            break;
            case 1:
            GVar("Player.Score") += 200;
            break;
            case 2:
            GVar("Player.Score") += 500;
            break;
            case 3:
            GVar("Player.Score") += 1000;
            break;
        }
        HapticEffect_Script(10, 0, 0, 0);
    } else {
        if (PlayerValue(4) == 0) {
            pState() = PlayerStateID("Player_State_GotHit");
            if (pXPos() > self->XPos) {
                pSpeed() = 0x20000;
            } else {
                pSpeed() = -0x20000;
            }
        }
    }
}

void O_Players_PlayerObject::Player_Hit()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = Plr()->entityNo;
    scriptEng.arrayPosition[0] += 2;
    if (objectEntityList[scriptEng.arrayPosition[0]].type != TypeNameID("Invincibility")) {
        if (PlayerValue(4) == 0) {
            pState() = PlayerStateID("Player_State_GotHit");
            if (pXPos() > self->XPos) {
                pSpeed() = 0x20000;
            } else {
                pSpeed() = -0x20000;
            }
        }
    }
}

void O_Players_PlayerObject::Player_ClimbBlock()
{
}

void O_Players_PlayerObject::Player_Unstick()
{
}

void O_Players_PlayerObject::Player_CancelClimb()
{
}

void O_Players_PlayerObject::Player_ForceNoGrip()
{
}

void O_Players_PlayerObject::Player_ForceGrip()
{
}

void O_Players_PlayerObject::Player_Kill()
{
    PlaySfx(5, 0);
    PlrEntity()->drawOrder = 5;
    pSpeed() = 0;
    pXVel() = 0;
    pYVel() = -0x68000;
    pState() = PlayerStateID("Player_State_Death");
    pAnimation() = GVar("ANI_DYING");
    pTileCollisions() = 0;
    pObjectInteractions() = 0;
    cameraEnabled = 0;
    HapticEffect_Script(28, 0, 0, 0);
}

void O_Players_PlayerObject::Player_ProcessUpdate()
{
    if (GVar("Options.AttractMode") == 0) {
        if (pControlMode() == 0) {
            if (objectEntityList[9].type == TypeNameID("Blank Object")) {
                if (keyPress.start == 1) {
                    keyPress.start = 0;
                    if (GVar("Options.DevMenuFlag") == 1) {
                        stageMode = 2;
                        PauseSound();
                        PlaySfx(27, 0);
                        StopSfx(24);
                        StopSfx(25);
                        objectEntityList[9].type = TypeNameID("Pause Menu");
                        objectEntityList[9].drawOrder = 7;
                        objectEntityList[9].priority = 2;
                    } else {
                        Engine.Callback(13);
                    }
                }
            }
        }
        ::ProcessPlayerControl(Plr());
    }
    if (GVar("Options.AttractMode") == 0) {
        if (pControlMode() == 0) {
            if (objectEntityList[9].type == TypeNameID("Blank Object")) {
                if (Engine.message == 2) {
                    stageMode = 2;
                    PauseSound();
                    PlaySfx(27, 0);
                    StopSfx(24);
                    StopSfx(25);
                    objectEntityList[9].type = TypeNameID("Pause Menu");
                    objectEntityList[9].drawOrder = 7;
                    objectEntityList[9].priority = 2;
                    if (Engine.frameSkipTimer > -1) {
                        Engine.frameSkipTimer = -1;
                    }
                }
            }
        }
    }
    if (PlayerValue(3) > 0) {
        PlayerValue(3)--;
        if (PlayerValue(3) == 0) {
            pAccel() = 0xC00;
            pAirAccel() = 0x1800;
            pTopSpeed() = 0x60000;
            if (trackID == 3) {
                PlayMusic(0);
            }
        }
    }
    if (PlayerValue(4) > 0) {
        if (pState() != PlayerStateID("Player_State_Hurt")) {
            if (PlayerValue(4) > 2000) {
                PlayerValue(4) = 120;
                PlayerValue(5) = 3;
            }
        }
        if (PlayerValue(5) > 0) {
            PlayerValue(5)++;
            if (PlayerValue(5) > 8) {
                PlayerValue(5) = 1;
            }
            if (PlayerValue(5) > 4) {
                pVisible() = 0;
            } else {
                pVisible() = 1;
            }
        }
        PlayerValue(4)--;
        if (PlayerValue(4) == 0) {
            PlayerValue(5) = 0;
            pVisible() = 1;
            if (trackID == 2) {
                PlayMusic(0);
            }
            if (objectEntityList[objectLoop + 2].type == TypeNameID("Invincibility")) {
                switch (objectEntityList[objectLoop + 2].propertyValue) {
                    case 0:
                    scriptEng.tempValue[0] = Plr()->entityNo;
                    scriptEng.tempValue[0] += 2;
                    ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
                    break;
                    case 1:
                    scriptEng.tempValue[0] = Plr()->entityNo;
                    scriptEng.tempValue[0] += 2;
                    ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Blank Object"), 0, 0, 0);
                    objectEntityList[objectLoop + 2].type = TypeNameID("Blue Shield");
                    objectEntityList[objectLoop + 2].propertyValue = 1;
                    objectEntityList[objectLoop + 2].priority = 1;
                    objectEntityList[objectLoop + 2].drawOrder = 4;
                    objectEntityList[objectLoop + 2].inkEffect = 2;
                    objectEntityList[objectLoop + 2].alpha = 160;
                    objectEntityList[objectLoop + 2].XPos = pXPos();
                    objectEntityList[objectLoop + 2].YPos = pYPos();
                    break;
                }
            }
        }
    }
    if (pState() != PlayerStateID("Player_State_LookUp")) {
        if (pState() != PlayerStateID("Player_State_Crouch")) {
            if (pLookPos() > 0) {
                pLookPos() -= 2;
            }
            if (pLookPos() < 0) {
                pLookPos() += 2;
            }
        }
    }
    if (GVar("Warp.Timer") > 0) {
        GVar("Warp.Timer")++;
        if (GVar("Warp.Timer") == 204) {
            cameraEnabled = 0;
            CreateTempObject(TypeNameID("Time Warp"), 0, 0, 0);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 6;
        }
    }
    if (PlayerValue(8) > 0) {
        PlayerValue(8)--;
        if (PlayerValue(8) == 0) {
            cameraStyle = 0;
        }
    }
    if (pState() != PlayerStateID("Player_State_Fly")) {
        if (PlayerValue(15) != 0) {
            StopSfx(24);
            StopSfx(25);
            PlayerValue(15) = 0;
        }
    }
}

void O_Players_PlayerObject::Player_State_Static()
{
    CheckResult() = 0;
}

void O_Players_PlayerObject::Player_HandleRollAnimSpeed()
{
    if (playerListPos == 1) {
        PlayerValue(2) = 120;
    } else {
        PlayerValue(2) = pSpeed();
        if (PlayerValue(2) < 0) {
            PlayerValue(2) = -PlayerValue(2);
        }
        PlayerValue(2) *= 240;
        PlayerValue(2) /= 0x60000;
        PlayerValue(2) += 48;
    }
}

void O_Players_PlayerObject::Player_HandleWalkAnimSpeed()
{
    pAnimationSpeed() = pSpeed();
    if (pAnimationSpeed() < 0) {
        pAnimationSpeed() = -pAnimationSpeed();
    }
    pAnimationSpeed() *= 60;
    pAnimationSpeed() /= 0x60000;
    pAnimationSpeed() += 20;
}

void O_Players_PlayerObject::Player_HandleRunAnimSpeed()
{
    pAnimationSpeed() = pSpeed();
    if (pAnimationSpeed() < 0) {
        pAnimationSpeed() = -pAnimationSpeed();
    }
    pAnimationSpeed() *= 80;
    pAnimationSpeed() /= 0x60000;
}

void O_Players_PlayerObject::Player_HandleGroundMovement()
{
    if (pControlLock() > 0) {
        pControlLock()--;
        scriptEng.tempValue[0] = Sin256(pAngle());
        scriptEng.tempValue[0] *= 0x2000;
        scriptEng.tempValue[0] >>= 8;
        pSpeed() += scriptEng.tempValue[0];
    } else {
        if (pLeft() == 1) {
            scriptEng.tempValue[0] = pTopSpeed();
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
            if (pSpeed() > scriptEng.tempValue[0]) {
                if (pSpeed() > 0) {
                    if (pCollisionMode() == 0) {
                        if (pSpeed() > 0x40000) {
                            pSkidding() = 16;
                        }
                    }
                    if (pSpeed() < 0x8000) {
                        pSpeed() = -0x8000;
                        pSkidding() = 0;
                    } else {
                        pSpeed() -= 0x8000;
                    }
                } else {
                    pSpeed() -= pAccel();
                    pSkidding() = 0;
                }
            }
            if (pSpeed() <= 0) {
                pDirection() = 1;
            }
        }
        if (pRight() == 1) {
            if (pSpeed() < pTopSpeed()) {
                if (pSpeed() < 0) {
                    if (pCollisionMode() == 0) {
                        if (pSpeed() < -0x40000) {
                            pSkidding() = 16;
                        }
                    }
                    if (pSpeed() > -0x8000) {
                        pSpeed() = 0x8000;
                        pSkidding() = 0;
                    } else {
                        pSpeed() += 0x8000;
                    }
                } else {
                    pSpeed() += pAccel();
                    pSkidding() = 0;
                }
            }
            if (pSpeed() >= 0) {
                pDirection() = 0;
            }
        }
        scriptEng.tempValue[0] = pLeft();
        scriptEng.tempValue[0] |= pRight();
        if (scriptEng.tempValue[0] == 0) {
            if (pSpeed() > 0) {
                pSpeed() -= pDecel();
                if (pSpeed() < 0) {
                    pSpeed() = 0;
                }
            } else {
                pSpeed() += pDecel();
                if (pSpeed() > 0) {
                    pSpeed() = 0;
                }
            }
            if (pSpeed() > 0x2000) {
                scriptEng.tempValue[0] = Sin256(pAngle());
                scriptEng.tempValue[0] *= 0x2000;
                scriptEng.tempValue[0] >>= 8;
                pSpeed() += scriptEng.tempValue[0];
            }
            if (pSpeed() < -0x2000) {
                scriptEng.tempValue[0] = Sin256(pAngle());
                scriptEng.tempValue[0] *= 0x2000;
                scriptEng.tempValue[0] >>= 8;
                pSpeed() += scriptEng.tempValue[0];
            }
            if (pAngle() > 192) {
                if (pAngle() < 228) {
                    if (pSpeed() > -0x10000) {
                        if (pSpeed() < 0x10000) {
                            pControlLock() = 30;
                        }
                    }
                }
            }
            if (pAngle() > 28) {
                if (pAngle() < 64) {
                    if (pSpeed() > -0x10000) {
                        if (pSpeed() < 0x10000) {
                            pControlLock() = 30;
                        }
                    }
                }
            }
        } else {
            scriptEng.tempValue[0] = Sin256(pAngle());
            scriptEng.tempValue[0] *= 0x2000;
            scriptEng.tempValue[0] >>= 8;
            pSpeed() += scriptEng.tempValue[0];
            if (pRight() == 1) {
                if (pLeft() == 0) {
                    if (pAngle() > 192) {
                        if (pAngle() < 228) {
                            if (pSpeed() < 0x28000) {
                                if (pSpeed() > -0x20000) {
                                    pControlLock() = 30;
                                }
                            }
                        }
                    }
                }
            } else {
                if (pLeft() == 1) {
                    if (pAngle() > 28) {
                        if (pAngle() < 64) {
                            if (pSpeed() > -0x28000) {
                                if (pSpeed() < 0x20000) {
                                    pControlLock() = 30;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void O_Players_PlayerObject::Player_HandleAirFriction()
{
    if (pYVel() > -0x40000) {
        if (pYVel() < 0) {
            scriptEng.tempValue[0] = pSpeed();
            scriptEng.tempValue[0] >>= 5;
            pSpeed() -= scriptEng.tempValue[0];
        }
    }
    scriptEng.tempValue[0] = pTopSpeed();
    scriptEng.tempValue[0] = -scriptEng.tempValue[0];
    if (pSpeed() > scriptEng.tempValue[0]) {
        if (pLeft() == 1) {
            pSpeed() -= pAirAccel();
            pDirection() = 1;
        }
    } else {
        if (pLeft() == 1) {
            pDirection() = 1;
        }
    }
    if (pSpeed() < pTopSpeed()) {
        if (pRight() == 1) {
            pSpeed() += pAirAccel();
            pDirection() = 0;
        }
    } else {
        if (pRight() == 1) {
            pDirection() = 0;
        }
    }
    if (GVar("Options.OriginalControls") == 1) {
        if (pLeft() == 1) {
            scriptEng.tempValue[0] = pTopSpeed();
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
            if (pSpeed() < scriptEng.tempValue[0]) {
                pSpeed() = scriptEng.tempValue[0];
            }
        }
        if (pRight() == 1) {
            if (pSpeed() > pTopSpeed()) {
                pSpeed() = pTopSpeed();
            }
        }
    }
}

void O_Players_PlayerObject::Player_HandleRollDeceleration()
{
    if (pRight() == 1) {
        if (pSpeed() < 0) {
            pSpeed() += pRollingDecel();
        }
    }
    if (pLeft() == 1) {
        if (pSpeed() > 0) {
            pSpeed() -= pRollingDecel();
        }
    }
    if (pSpeed() > 0) {
        pSpeed() -= pAirDecel();
        if (pSpeed() < 0) {
            pSpeed() = 0;
        }
        if (pSpeed() == 0) {
            if (pAngle() > 224) {
                pState() = PlayerStateID("Player_State_Ground");
            }
            if (pAngle() < 32) {
                pState() = PlayerStateID("Player_State_Ground");
            }
        }
        scriptEng.tempValue[0] = Sin256(pAngle());
        if (scriptEng.tempValue[0] > 0) {
            scriptEng.tempValue[0] = Sin256(pAngle());
            scriptEng.tempValue[0] *= 0x5000;
        } else {
            scriptEng.tempValue[0] = Sin256(pAngle());
            scriptEng.tempValue[0] *= 0x1E00;
        }
        scriptEng.tempValue[0] >>= 8;
        pSpeed() += scriptEng.tempValue[0];
    } else {
        pSpeed() += pAirDecel();
        if (pSpeed() > 0) {
            pSpeed() = 0;
        }
        if (pSpeed() == 0) {
            if (pAngle() > 224) {
                pState() = PlayerStateID("Player_State_Ground");
            }
            if (pAngle() < 32) {
                pState() = PlayerStateID("Player_State_Ground");
            }
        }
        scriptEng.tempValue[0] = Sin256(pAngle());
        if (scriptEng.tempValue[0] < 0) {
            scriptEng.tempValue[0] = Sin256(pAngle());
            scriptEng.tempValue[0] *= 0x5000;
        } else {
            scriptEng.tempValue[0] = Sin256(pAngle());
            scriptEng.tempValue[0] *= 0x1E00;
        }
        scriptEng.tempValue[0] >>= 8;
        pSpeed() += scriptEng.tempValue[0];
    }
    if (pSpeed() > 0x180000) {
        pSpeed() = 0x180000;
    }
    if (pSpeed() < -0x180000) {
        pSpeed() = -0x180000;
    }
}

void O_Players_PlayerObject::Player_HandleAirMovement()
{
    pTrackScroll() = 1;
    pYVel() += pGravityStrength();
    if (pYVel() < pJumpCap()) {
        if (pJumpHold() == 0) {
            if (pTimer() > 0) {
                pYVel() = pJumpCap();
                scriptEng.tempValue[0] = pSpeed();
                scriptEng.tempValue[0] >>= 5;
                pSpeed() -= scriptEng.tempValue[0];
            }
        }
    }
    pXVel() = pSpeed();
    if (pRotation() < 256) {
        if (pRotation() > 0) {
            pRotation() -= 4;
        } else {
            pRotation() = 0;
        }
    } else {
        if (pRotation() < 512) {
            pRotation() += 4;
        } else {
            pRotation() = 0;
        }
    }
    pCollisionMode() = 0;
    if (pAnimation() == GVar("ANI_JUMPING")) {
        pAnimationSpeed() = PlayerValue(2);
    }
}

void O_Players_PlayerObject::Player_HandleOnGround()
{
    pTrackScroll() = 0;
    scriptEng.tempValue[0] = Cos256(pAngle());
    scriptEng.tempValue[0] *= pSpeed();
    scriptEng.tempValue[0] >>= 8;
    pXVel() = scriptEng.tempValue[0];
    scriptEng.tempValue[0] = Sin256(pAngle());
    scriptEng.tempValue[0] *= pSpeed();
    scriptEng.tempValue[0] >>= 8;
    pYVel() = scriptEng.tempValue[0];
}

void O_Players_PlayerObject::Player_Action_Jump()
{
    Entity *self = Self();

    CheckResult() = 0;
    if (pCollisionMode() == 0) {
        scriptEng.tempValue[6] = self->XPos;
        scriptEng.tempValue[7] = self->YPos;
        self->XPos = pXPos();
        self->YPos = pYPos();
        scriptEng.tempValue[0] = pCollisionTop();
        scriptEng.tempValue[0] -= 2;
        ObjectTileCollision_Script(2, 0, scriptEng.tempValue[0], 0);
        self->XPos = scriptEng.tempValue[6];
        self->YPos = scriptEng.tempValue[7];
    }
    if (CheckResult() == 0) {
        pControlLock() = 0;
        pGravity() = 1;
        PlayerValue(1) = 8;
        pXVel() = Sin256(pAngle());
        pXVel() *= pJumpStrength();
        scriptEng.tempValue[0] = Cos256(pAngle());
        scriptEng.tempValue[0] *= pSpeed();
        pXVel() += scriptEng.tempValue[0];
        pXVel() >>= 8;
        pYVel() = Sin256(pAngle());
        pYVel() *= pSpeed();
        scriptEng.tempValue[0] = Cos256(pAngle());
        scriptEng.tempValue[0] *= pJumpStrength();
        pYVel() -= scriptEng.tempValue[0];
        pYVel() >>= 8;
        pSpeed() = pXVel();
        pTrackScroll() = 1;
        pAnimation() = GVar("ANI_JUMPING");
        pAngle() = 0;
        pCollisionMode() = 0;
        pTimer() = 1;
        Player_HandleRollAnimSpeed();
        pState() = PlayerStateID("Player_State_Air");
        PlaySfx(0, 0);
    }
}

void O_Players_PlayerObject::Player_Action_Spindash_S2()
{
    pState() = PlayerStateID("Player_State_Spindash_S2");
    pAnimation() = GVar("ANI_SPINDASH");
    PlayerValue(1) = 0;
    PlaySfx(6, 0);
    CreateTempObject(TypeNameID("Dust Puff"), objectLoop, pXPos(), pYPos());
    objectEntityList[scriptEng.arrayPosition[2]].YPos = (pCollisionBottom()) << 16;
    objectEntityList[scriptEng.arrayPosition[2]].YPos += pYPos();
    objectEntityList[scriptEng.arrayPosition[2]].frame = 4;
    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    objectEntityList[scriptEng.arrayPosition[2]].direction = pDirection();
    HapticEffect_Script(112, 0, 0, 0);
}

void O_Players_PlayerObject::Player_Action_Spindash_CD()
{
    pState() = PlayerStateID("Player_State_Spindash_CD");
    pAnimation() = GVar("ANI_JUMPING");
    pYPos() += 0x50000;
    PlayerValue(1) = 0;
    PlaySfx(6, 0);
    HapticEffect_Script(112, 0, 0, 0);
}

void O_Players_PlayerObject::Player_Action_Peelout_S2()
{
    pState() = PlayerStateID("Player_State_Peelout_S2");
    PlayerValue(1) = 0;
    PlaySfx(6, 0);
    HapticEffect_Script(115, 0, 0, 0);
}

void O_Players_PlayerObject::Player_Action_Peelout_CD()
{
    pState() = PlayerStateID("Player_State_Peelout_CD");
    PlayerValue(1) = 0;
    PlaySfx(6, 0);
    HapticEffect_Script(115, 0, 0, 0);
}

void O_Players_PlayerObject::Player_Action_DblJumpTails()
{
    if (PlayerValue(1) > 0) {
        PlayerValue(1)--;
    } else {
        if (pJumpPress() == 1) {
            pTimer() = 0;
            pState() = PlayerStateID("Player_State_Fly");
            PlayerValue(15) = 0x800;
            if (pGravityStrength() == 0x3800) {
                PlaySfx(24, 1);
                pAnimation() = GVar("ANI_FLYING");
            } else {
                pAnimation() = GVar("ANI_SWIMMING");
            }
        }
    }
}

void O_Players_PlayerObject::Player_State_Ground()
{
    if (pAnimation() != GVar("ANI_SKIDDING")) {
        scriptEng.tempValue[7] = 1;
    } else {
        scriptEng.tempValue[7] = 0;
    }
    Player_HandleGroundMovement();
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        Player_HandleAirMovement();
    } else {
        Player_HandleOnGround();
        if (pSpeed() == 0) {
            if (GVar("Warp.Destination") > 0) {
                if (GVar("Warp.Timer") > 99) {
                    if (GVar("Warp.Timer") < 220) {
                        GVar("Warp.Destination") = 0;
                    }
                }
                GVar("Warp.Timer") = 0;
            }
            if (pCollisionMode() == 0) {
                if (pTimer() < 240) {
                    pAnimation() = GVar("ANI_STOPPED");
                    pTimer()++;
                } else {
                    pAnimation() = GVar("ANI_WAITING");
                    if (playerListPos == 0) {
                        pTimer()++;
                        if (pTimer() == 10620) {
                            pTimer() = 0;
                            PlaySfx(26, 0);
                            pState() = PlayerStateID("Player_State_OuttaHere");
                            pAnimation() = GVar("ANI_BORED");
                        }
                    }
                }
                if (Plr()->flailing[1] == 0) {
                    if (Plr()->flailing[2] == 0) {
                        pTimer() = 0;
                        if (pDirection() == 1) {
                            pAnimation() = GVar("ANI_FLAILINGLEFT");
                        } else {
                            pAnimation() = GVar("ANI_FLAILINGRIGHT");
                        }
                    }
                    if (Plr()->flailing[0] == 0) {
                        pTimer() = 0;
                        if (pDirection() == 0) {
                            pAnimation() = GVar("ANI_FLAILINGLEFT");
                        } else {
                            pAnimation() = GVar("ANI_FLAILINGRIGHT");
                        }
                    }
                }
            }
        } else {
            pTimer() = 0;
            if (pSpeed() > 0) {
                if (pSpeed() < 0x5F5C2) {
                    pAnimation() = GVar("ANI_WALKING");
                    Player_HandleWalkAnimSpeed();
                    if (GVar("Warp.Destination") > 0) {
                        if (GVar("Warp.Timer") > 99) {
                            if (GVar("Warp.Timer") < 204) {
                                GVar("Warp.Destination") = 0;
                            }
                        }
                        GVar("Warp.Timer") = 0;
                        objectEntityList[3].type = TypeNameID("Blank Object");
                    }
                } else {
                    if (GVar("Warp.Destination") > 0) {
                        if (GVar("Warp.Timer") == 0) {
                            GVar("Warp.Timer") = 1;
                            ResetObjectEntity(3, TypeNameID("Warp Star"), 0, pXPos(), pYPos());
                            objectEntityList[3].values[0] = 7;
                            objectEntityList[3].drawOrder = 4;
                        }
                    }
                    if (pSpeed() > 0x9FFFF) {
                        pAnimation() = GVar("ANI_PEELOUT");
                    } else {
                        pAnimation() = GVar("ANI_RUNNING");
                    }
                    Player_HandleRunAnimSpeed();
                }
            } else {
                if (pSpeed() > -0x5F5C2) {
                    pAnimation() = GVar("ANI_WALKING");
                    Player_HandleWalkAnimSpeed();
                    if (GVar("Warp.Destination") > 0) {
                        if (GVar("Warp.Timer") > 99) {
                            if (GVar("Warp.Timer") < 204) {
                                GVar("Warp.Destination") = 0;
                            }
                        }
                        GVar("Warp.Timer") = 0;
                        objectEntityList[3].type = TypeNameID("Blank Object");
                    }
                } else {
                    if (GVar("Warp.Destination") > 0) {
                        if (GVar("Warp.Timer") == 0) {
                            GVar("Warp.Timer") = 1;
                            ResetObjectEntity(3, TypeNameID("Warp Star"), 0, pXPos(), pYPos());
                            objectEntityList[3].values[0] = 7;
                            objectEntityList[3].drawOrder = 4;
                        }
                    }
                    if (pSpeed() < -0x9FFFF) {
                        pAnimation() = GVar("ANI_PEELOUT");
                    } else {
                        pAnimation() = GVar("ANI_RUNNING");
                    }
                    Player_HandleRunAnimSpeed();
                }
            }
        }
        if (pSkidding() > 0) {
            if (scriptEng.tempValue[7] == 1) {
                PlaySfx(3, 0);
            }
            pAnimation() = GVar("ANI_SKIDDING");
            pAnimationSpeed() = 0;
            pSkidding()--;
            if (GVar("Ring.AniCount") == 0) {
                CreateTempObject(TypeNameID("Dust Puff"), 0, pXPos(), pYPos());
                objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) + (pCollisionBottom())) << 16;
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = PlrEntity()->drawOrder;
            }
            if (pSpeed() > 0) {
                pDirection() = 0;
            } else {
                pDirection() = 1;
            }
        }
        if (pCollisionMode() == 0) {
            if (pPushing() == 2) {
                pAnimation() = GVar("ANI_PUSHING");
                pAnimationSpeed() = 0;
            }
        }
        if (pJumpPress() == 1) {
            Player_Action_Jump();
        } else {
            if (pUp() == 1) {
                if (pSpeed() == 0) {
                    if (pAnimation() != GVar("ANI_FLAILINGLEFT")) {
                        if (pAnimation() != GVar("ANI_FLAILINGRIGHT")) {
                            pState() = PlayerStateID("Player_State_LookUp");
                            pAnimation() = GVar("ANI_LOOKINGUP");
                            pTimer() = 0;
                        }
                    }
                }
            }
            if (pDown() == 1) {
                if (pSpeed() == 0) {
                    if (pAnimation() != GVar("ANI_FLAILINGLEFT")) {
                        if (pAnimation() != GVar("ANI_FLAILINGRIGHT")) {
                            pState() = PlayerStateID("Player_State_Crouch");
                            pAnimation() = GVar("ANI_LOOKINGDOWN");
                            pTimer() = 0;
                        }
                    }
                } else {
                    if (pLeft() == 0) {
                        if (pRight() == 0) {
                            if (pSpeed() > 0) {
                                if (pSpeed() > 0x8800) {
                                    pState() = PlayerStateID("Player_State_Roll");
                                    pAnimation() = GVar("ANI_JUMPING");
                                    pYPos() = ((pYPos() >> 16) - (PlayerValue(9))) << 16;
                                    PlayerValue(1) = 1024;
                                }
                            } else {
                                if (pSpeed() < -0x8800) {
                                    pState() = PlayerStateID("Player_State_Roll");
                                    pAnimation() = GVar("ANI_JUMPING");
                                    pYPos() = ((pYPos() >> 16) - (PlayerValue(9))) << 16;
                                    PlayerValue(1) = 1024;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void O_Players_PlayerObject::Player_State_Air_NoDropDash()
{
}

void O_Players_PlayerObject::Player_State_Air()
{
    Player_HandleAirFriction();
    if (pGravity() == 1) {
        Player_HandleAirMovement();
        if (GVar("Warp.Destination") > 0) {
            scriptEng.tempValue[0] = pYVel();
            if (scriptEng.tempValue[0] < 0) {
                scriptEng.tempValue[0] = -scriptEng.tempValue[0];
            }
            if (scriptEng.tempValue[0] < 0x60000) {
                scriptEng.tempValue[0] = pXVel();
                if (scriptEng.tempValue[0] < 0) {
                    scriptEng.tempValue[0] = -scriptEng.tempValue[0];
                }
                if (scriptEng.tempValue[0] < 0x60000) {
                    scriptEng.tempValue[0] = pXVel();
                    scriptEng.tempValue[0] -= GVar("Warp.SpeedCompare");
                    if (scriptEng.tempValue[0] < 0) {
                        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
                    }
                    if (scriptEng.tempValue[0] > 0x40000) {
                        if (GVar("Warp.Timer") > 99) {
                            if (GVar("Warp.Timer") < 204) {
                                GVar("Warp.Destination") = 0;
                            }
                        }
                        GVar("Warp.Timer") = 0;
                    }
                }
            }
            GVar("Warp.SpeedCompare") = pXVel();
        }
        if (pYVel() > 0x20000) {
            if (pAnimation() == GVar("ANI_FLAILINGLEFT")) {
                pAnimation() = GVar("ANI_WALKING");
            }
            if (pAnimation() == GVar("ANI_FLAILINGRIGHT")) {
                pAnimation() = GVar("ANI_WALKING");
            }
        }
        if (pAnimation() == GVar("ANI_BOUNCING")) {
            if (pYVel() >= 0) {
                if (PlayerValue(7) == GVar("ANI_STOPPED")) {
                    PlayerValue(7) = GVar("ANI_WALKING");
                }
                pAnimation() = PlayerValue(7);
            }
        }
        if (pAnimation() == GVar("ANI_HURT")) {
            if (pYVel() >= 0) {
                if (PlayerValue(7) == GVar("ANI_STOPPED")) {
                    PlayerValue(7) = GVar("ANI_WALKING");
                }
                pAnimation() = PlayerValue(7);
            }
        }
        if (pAnimation() == GVar("ANI_JUMPING")) {
            CallPlayerFunc(PlayerValue(10), scriptSub);
        }
    } else {
        pState() = PlayerStateID("Player_State_Ground");
        Player_HandleOnGround();
        pSkidding() = 0;
    }
}

void O_Players_PlayerObject::Player_State_Roll()
{
    Player_HandleRollDeceleration();
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pTimer() = 0;
        Player_HandleAirMovement();
    } else {
        Player_HandleRollAnimSpeed();
        pAnimationSpeed() = PlayerValue(2);
        scriptEng.tempValue[0] = pSpeed();
        if (scriptEng.tempValue[0] < 0) {
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        }
        if (scriptEng.tempValue[0] < 0x5F5C2) {
            if (GVar("Warp.Destination") > 0) {
                if (GVar("Warp.Timer") > 99) {
                    if (GVar("Warp.Timer") < 204) {
                        GVar("Warp.Destination") = 0;
                    }
                }
                GVar("Warp.Timer") = 0;
            }
        } else {
            if (GVar("Warp.Destination") > 0) {
                if (GVar("Warp.Timer") == 0) {
                    GVar("Warp.Timer") = 1;
                    ResetObjectEntity(3, TypeNameID("Warp Star"), 0, pXPos(), pYPos());
                    objectEntityList[3].values[0] = 7;
                    objectEntityList[3].drawOrder = 4;
                }
            }
        }
        Player_HandleOnGround();
        if (pJumpPress() == 1) {
            Player_Action_Jump();
        }
    }
}

void O_Players_PlayerObject::Player_State_RollJump()
{
    pLeft() = 0;
    pRight() = 0;
    Player_HandleAirFriction();
    if (pGravity() == 1) {
        Player_HandleAirMovement();
    } else {
        pState() = PlayerStateID("Player_State_Ground");
        Player_HandleOnGround();
        pSkidding() = 0;
    }
}

void O_Players_PlayerObject::Player_State_LookUp()
{
    if (pUp() == 0) {
        pState() = PlayerStateID("Player_State_Ground");
        pTimer() = 0;
    } else {
        if (pTimer() < 60) {
            pTimer()++;
        } else {
            if (pLookPos() > -112) {
                pLookPos() -= 2;
            }
        }
        if (pGravity() == 1) {
            pState() = PlayerStateID("Player_State_Air");
            pTimer() = 0;
        } else {
            if (pJumpPress() == 1) {
                CallPlayerFunc(PlayerValue(11), scriptSub);
            }
        }
    }
}

void O_Players_PlayerObject::Player_State_Crouch()
{
    if (pDown() == 0) {
        pState() = PlayerStateID("Player_State_Ground");
        pTimer() = 0;
    } else {
        if (pTimer() < 60) {
            pTimer()++;
        } else {
            if (pLookPos() < 96) {
                pLookPos() += 2;
            }
        }
        if (pGravity() == 1) {
            pState() = PlayerStateID("Player_State_Air");
            pTimer() = 0;
        } else {
            if (pJumpPress() == 1) {
                CallPlayerFunc(PlayerValue(12), scriptSub);
            }
        }
    }
}

void O_Players_PlayerObject::Player_State_Spindash_S2()
{
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pSpeed() = 0;
    }
    if (pJumpPress() == 1) {
        if (PlayerValue(1) < 512) {
            PlayerValue(1) += 64;
        }
        pFrame() = 0;
        PlaySfx(6, 0);
    } else {
        if (PlayerValue(1) > 0) {
            PlayerValue(1)--;
        }
    }
    CheckResult() = (pDown() == 0);
    if (CheckResult() == 1) {
        pTimer() = 0;
        pState() = PlayerStateID("Player_State_Roll");
        pAnimation() = GVar("ANI_JUMPING");
        pYPos() = ((pYPos() >> 16) - (PlayerValue(9))) << 16;
        PlayerValue(8) = 15;
        cameraStyle = 4;
        scriptEng.tempValue[0] = PlayerValue(1);
        scriptEng.tempValue[0] <<= 9;
        scriptEng.tempValue[0] += 0x80000;
        if (pDirection() == 0) {
            pSpeed() = scriptEng.tempValue[0];
        } else {
            pSpeed() = scriptEng.tempValue[0];
            pSpeed() = -pSpeed();
        }
        PlaySfx(7, 0);
        Player_HandleOnGround();
        HapticEffect_Script(42, 0, 0, 0);
    }
}

void O_Players_PlayerObject::Player_State_Spindash_CD()
{
    if (pDirection() == 0) {
        cameraStyle = 2;
    } else {
        cameraStyle = 3;
    }
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pSpeed() = 0;
        cameraStyle = 1;
    }
    if (pGravityStrength() == 0x1000) {
        if (PlayerValue(1) < 0x80000) {
            PlayerValue(1) += 0x6000;
        }
    } else {
        if (PlayerValue(1) < 0xC0000) {
            PlayerValue(1) += 0x6000;
        }
    }
    if (pDown() == 0) {
        cameraStyle = 1;
        pTimer() = 0;
        if (PlayerValue(1) < 0x2FAE1) {
            pSpeed() = 0;
            pState() = PlayerStateID("Player_State_Ground");
        } else {
            pState() = PlayerStateID("Player_State_Roll");
            pAnimation() = GVar("ANI_JUMPING");
            pSpeed() = PlayerValue(1);
            if (pDirection() == 1) {
                pSpeed() = -pSpeed();
            }
            PlaySfx(7, 0);
        }
        Player_HandleOnGround();
        HapticEffect_Script(42, 0, 0, 0);
    }
}

void O_Players_PlayerObject::Player_State_Peelout_S2()
{
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pSpeed() = 0;
    }
    if (pGravityStrength() == 0x1000) {
        if (PlayerValue(1) < 0x60000) {
            PlayerValue(1) += 0x6000;
        }
    } else {
        if (PlayerValue(1) < 0xC0000) {
            PlayerValue(1) += 0x6000;
        }
    }
    if (PlayerValue(1) < 0x5F5C2) {
        pAnimation() = GVar("ANI_WALKING");
        scriptEng.tempValue[0] = PlayerValue(1);
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[0] *= 80;
        scriptEng.tempValue[0] /= 6;
        scriptEng.tempValue[0] += 20;
    } else {
        scriptEng.tempValue[0] = PlayerValue(1);
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[0] *= 80;
        scriptEng.tempValue[0] /= 6;
        if (PlayerValue(1) > 0x9FFFF) {
            pAnimation() = GVar("ANI_PEELOUT");
        } else {
            pAnimation() = GVar("ANI_RUNNING");
        }
    }
    if (pUp() == 0) {
        PlayerValue(8) = 15;
        cameraStyle = 4;
        pState() = PlayerStateID("Player_State_Ground");
        if (PlayerValue(1) < 0x5F5C2) {
            pSpeed() = 0;
        } else {
            pSpeed() = PlayerValue(1);
            if (pDirection() == 1) {
                pSpeed() = -pSpeed();
            }
            PlaySfx(7, 0);
        }
        Player_HandleOnGround();
        HapticEffect_Script(42, 0, 0, 0);
    }
    pAnimationSpeed() = scriptEng.tempValue[0];
}

void O_Players_PlayerObject::Player_State_Peelout_CD()
{
    if (pDirection() == 0) {
        cameraStyle = 2;
    } else {
        cameraStyle = 3;
    }
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pSpeed() = 0;
        cameraStyle = 1;
    }
    if (pGravityStrength() == 0x1000) {
        if (PlayerValue(1) < 0x60000) {
            PlayerValue(1) += 0x6000;
        }
    } else {
        if (PlayerValue(1) < 0xC0000) {
            PlayerValue(1) += 0x6000;
        }
    }
    if (PlayerValue(1) < 0x5F5C2) {
        pAnimation() = GVar("ANI_WALKING");
        scriptEng.tempValue[0] = PlayerValue(1);
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[0] *= 80;
        scriptEng.tempValue[0] /= 6;
        scriptEng.tempValue[0] += 20;
    } else {
        scriptEng.tempValue[0] = PlayerValue(1);
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[0] *= 80;
        scriptEng.tempValue[0] /= 6;
        if (PlayerValue(1) > 0x9FFFF) {
            pAnimation() = GVar("ANI_PEELOUT");
        } else {
            pAnimation() = GVar("ANI_RUNNING");
        }
    }
    if (pUp() == 0) {
        cameraStyle = 1;
        pState() = PlayerStateID("Player_State_Ground");
        if (PlayerValue(1) < 0x5F5C2) {
            pSpeed() = 0;
        } else {
            pSpeed() = PlayerValue(1);
            if (pDirection() == 1) {
                pSpeed() = -pSpeed();
            }
            PlaySfx(7, 0);
        }
        Player_HandleOnGround();
        HapticEffect_Script(42, 0, 0, 0);
    }
    pAnimationSpeed() = scriptEng.tempValue[0];
}

void O_Players_PlayerObject::Player_State_Fly()
{
    Player_HandleAirFriction();
    if (pGravity() == 1) {
        pXVel() = pSpeed();
        if (GVar("Warp.Destination") > 0) {
            scriptEng.tempValue[0] = pXVel();
            if (scriptEng.tempValue[0] < 0) {
                scriptEng.tempValue[0] = -scriptEng.tempValue[0];
            }
            scriptEng.tempValue[1] = pYVel();
            if (scriptEng.tempValue[1] < 0) {
                scriptEng.tempValue[1] = -scriptEng.tempValue[1];
            }
            scriptEng.tempValue[0] += scriptEng.tempValue[1];
            if (scriptEng.tempValue[0] < 0x40000) {
                if (GVar("Warp.Timer") > 99) {
                    if (GVar("Warp.Timer") < 220) {
                        GVar("Warp.Destination") = 0;
                    }
                }
                GVar("Warp.Timer") = 0;
            }
        }
        if (pYVel() < -0x10000) {
            PlayerValue(15) = 0x800;
        } else {
            if (pYVel() < 1) {
                if (PlayerValue(1) < 60) {
                    PlayerValue(1)++;
                } else {
                    PlayerValue(15) = 0x800;
                }
            }
        }
        pYVel() += PlayerValue(15);
        if (pTimer() < 480) {
            if (pGravityStrength() == 0x3800) {
                pAnimation() = GVar("ANI_FLYING");
            } else {
                pAnimation() = GVar("ANI_SWIMMING");
            }
            pTimer()++;
            if (pTimer() == 480) {
                if (pGravityStrength() == 0x3800) {
                    pAnimation() = GVar("ANI_FLYINGTIRED");
                    StopSfx(24);
                    PlaySfx(25, 1);
                } else {
                    pAnimation() = GVar("ANI_SWIMMINGTIRED");
                }
            } else {
                if (pJumpPress() == 1) {
                    PlayerValue(15) = -0x2000;
                    PlayerValue(1) = 0;
                }
            }
        } else {
            if (pGravityStrength() == 0x3800) {
                pAnimation() = GVar("ANI_FLYINGTIRED");
            } else {
                pAnimation() = GVar("ANI_SWIMMINGTIRED");
            }
        }
    } else {
        pState() = PlayerStateID("Player_State_Ground");
        Player_HandleOnGround();
    }
    if (GVar("Player.RoofBarrier") == 1) {
        scriptEng.tempValue[0] = pYPos();
        scriptEng.tempValue[0] >>= 16;
        if (scriptEng.tempValue[0] < pCollisionBottom()) {
            pYPos() = pCollisionBottom();
            pYPos() <<= 16;
        }
    }
}

void O_Players_PlayerObject::Player_State_GotHit()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = Plr()->entityNo;
    scriptEng.arrayPosition[0] += 2;
    if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue > 0) {
        scriptEng.tempValue[0] = 1;
        ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Blank Object"), 0, 0, 0);
        PlaySfx(5, 0);
    } else {
        if (PlayerValue(0) == 0) {
            PlaySfx(5, 0);
            scriptEng.tempValue[0] = 3;
        } else {
            PlaySfx(4, 0);
            scriptEng.tempValue[0] = 2;
        }
    }
    switch (scriptEng.tempValue[0]) {
        case 1:
        HapticEffect_Script(16, 0, 0, 0);
        pState() = PlayerStateID("Player_State_Hurt");
        pAnimation() = GVar("ANI_HURT");
        pYVel() = -0x40000;
        pGravity() = 1;
        pTrackScroll() = 1;
        PlayerValue(4) = 8000;
        if (pGravityStrength() == 0x1000) {
            pSpeed() >>= 1;
            pYVel() >>= 1;
        }
        break;
        case 2:
        HapticEffect_Script(16, 0, 0, 0);
        if (pCollisionPlane() == 0) {
            scriptEng.tempValue[4] = 3;
        } else {
            scriptEng.tempValue[4] = 1;
        }
        pState() = PlayerStateID("Player_State_Hurt");
        pAnimation() = GVar("ANI_HURT");
        pYVel() = -0x40000;
        pGravity() = 1;
        pTrackScroll() = 1;
        PlayerValue(4) = 8000;
        if (pGravityStrength() == 0x1000) {
            pSpeed() >>= 1;
            pYVel() >>= 1;
        }
        scriptEng.tempValue[0] = PlayerValue(0);
        if (scriptEng.tempValue[0] > 16) {
            scriptEng.tempValue[1] = scriptEng.tempValue[0];
            scriptEng.tempValue[1] -= 16;
            scriptEng.tempValue[0] = 16;
        } else {
            scriptEng.tempValue[1] = 0;
        }
        if (scriptEng.tempValue[1] > 16) {
            scriptEng.tempValue[1] = 16;
        }
        scriptEng.tempValue[3] = scriptEng.tempValue[1];
        scriptEng.tempValue[3] >>= 1;
        scriptEng.tempValue[3] <<= 5;
        scriptEng.tempValue[2] = 384;
        scriptEng.tempValue[2] -= scriptEng.tempValue[3];
        scriptEng.tempValue[3] >>= 4;
        if (scriptEng.tempValue[3] == scriptEng.tempValue[1]) {
            scriptEng.tempValue[2] += 16;
        } else {
            scriptEng.tempValue[2] -= 16;
        }
        scriptEng.tempValue[3] = 0;
        while (scriptEng.tempValue[3] < scriptEng.tempValue[1]) {
            CreateTempObject(TypeNameID("Lose Ring"), pCollisionPlane(), pXPos(), pYPos());
            objectEntityList[scriptEng.arrayPosition[2]].values[0] = Cos512(scriptEng.tempValue[2]);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = Sin512(scriptEng.tempValue[2]);
            objectEntityList[scriptEng.arrayPosition[2]].values[0] <<= 8;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 8;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = scriptEng.tempValue[4];
            objectEntityList[scriptEng.arrayPosition[2]].animationSpeed = 256;
            scriptEng.tempValue[3]++;
            scriptEng.tempValue[2] += 32;
        }
        scriptEng.tempValue[3] = scriptEng.tempValue[0];
        scriptEng.tempValue[3] >>= 1;
        scriptEng.tempValue[3] <<= 5;
        scriptEng.tempValue[2] = 384;
        scriptEng.tempValue[2] -= scriptEng.tempValue[3];
        scriptEng.tempValue[3] >>= 4;
        if (scriptEng.tempValue[3] == scriptEng.tempValue[0]) {
            scriptEng.tempValue[2] += 16;
        } else {
            scriptEng.tempValue[2] -= 16;
        }
        scriptEng.tempValue[3] = 0;
        while (scriptEng.tempValue[3] < scriptEng.tempValue[0]) {
            CreateTempObject(TypeNameID("Lose Ring"), pCollisionPlane(), pXPos(), pYPos());
            objectEntityList[scriptEng.arrayPosition[2]].values[0] = Cos512(scriptEng.tempValue[2]);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = Sin512(scriptEng.tempValue[2]);
            objectEntityList[scriptEng.arrayPosition[2]].values[0] <<= 9;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 9;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = scriptEng.tempValue[4];
            objectEntityList[scriptEng.arrayPosition[2]].animationSpeed = 256;
            scriptEng.tempValue[3]++;
            scriptEng.tempValue[2] += 32;
        }
        PlayerValue(0) = 0;
        GVar("Ring.ExtraLife") = 100;
        break;
        case 3:
        HapticEffect_Script(28, 0, 0, 0);
        self->drawOrder = 5;
        pSpeed() = 0;
        pYVel() = -0x70000;
        pXVel() = 0;
        pState() = PlayerStateID("Player_State_Death");
        pAnimation() = GVar("ANI_DYING");
        pTileCollisions() = 0;
        pObjectInteractions() = 0;
        if (Plr()->entityNo == 0) {
            cameraEnabled = 0;
        }
        break;
    }
    if (GVar("Warp.Destination") > 0) {
        if (GVar("Warp.Timer") > 99) {
            if (GVar("Warp.Timer") < 204) {
                GVar("Warp.Destination") = 0;
            }
        }
        GVar("Warp.Timer") = 0;
    }
}

void O_Players_PlayerObject::Player_State_Hurt()
{
    if (pGravity() == 1) {
        pTrackScroll() = 1;
        if (pGravityStrength() == 0x3800) {
            pYVel() += 0x3000;
        } else {
            pYVel() += 0xF00;
        }
        pXVel() = pSpeed();
    } else {
        pState() = PlayerStateID("Player_State_Ground");
        PlayerValue(4) = 120;
        PlayerValue(5) = 3;
        pSpeed() = 0;
        pXVel() = 0;
        Player_HandleOnGround();
    }
}

void O_Players_PlayerObject::Player_State_OuttaHere()
{
    if (pTimer() < 140) {
        pTimer()++;
    } else {
        pTimer() = 0;
        PlrEntity()->drawOrder = 5;
        if (pDirection() == 0) {
            pSpeed() = 0x10000;
            pXVel() = 0x10000;
        } else {
            pSpeed() = -0x10000;
            pXVel() = -0x10000;
        }
        pYVel() = -0x58000;
        pState() = PlayerStateID("Player_State_Death");
        pTileCollisions() = 0;
        pObjectInteractions() = 0;
        cameraEnabled = 0;
    }
}

void O_Players_PlayerObject::Player_State_Death()
{
    Entity *self = Self();

    pControlMode() = -1;
    pYVel() += 0x3800;
    if (pAnimation() != GVar("ANI_BORED")) {
        pAnimation() = GVar("ANI_DYING");
    }
    if (pYVel() > 0x100000) {
        if (GVar("Player.Lives") > 0) {
            if (pAnimation() == GVar("ANI_BORED")) {
                GVar("Player.Lives") = 0;
            } else {
                GVar("Player.Lives")--;
            }
        }
        timeEnabled = 0;
        CheckResult() = 1;
        if (CheckResult() != 0) {
            self->type = TypeNameID("Death Event");
            self->drawOrder = 7;
            self->values[1] = SCREEN_CENTERX;
            self->values[1] -= 232;
            self->values[2] = SCREEN_CENTERX;
            self->values[2] += 232;
        }
        if (GVar("Options.GameMode") == 2) {
            self->values[3] = 0;
            self->state = 3;
        } else {
            if (GVar("Player.Lives") == 0) {
                self->values[3] = -2880;
                self->state = 0;
                PlayMusic(5);
                pauseEnabled = 0;
            } else {
                self->values[3] = 0;
                self->state = 2;
                if (stageMinutes == 9) {
                    if (stageSeconds == 59) {
                        self->values[3] = -2880;
                        self->state = 1;
                        PlayMusic(5);
                        pauseEnabled = 0;
                    }
                }
            }
        }
    }
}

void O_Players_PlayerObject::Player_State_Drown()
{
    Entity *self = Self();

    pControlMode() = -1;
    pYVel() += pGravityStrength();
    pAnimation() = GVar("ANI_DROWNING");
    if (pYVel() > 0x80000) {
        if (GVar("Player.Lives") > 0) {
            GVar("Player.Lives")--;
        }
        timeEnabled = 0;
        self->type = TypeNameID("DeathEvent");
        self->drawOrder = 7;
        self->values[1] = SCREEN_CENTERX;
        self->values[1] -= 232;
        self->values[2] = SCREEN_CENTERX;
        self->values[2] += 232;
        if (GVar("Options.GameMode") == 2) {
            self->values[3] = 0;
            self->state = 3;
        } else {
            if (GVar("Player.Lives") == 0) {
                self->values[3] = -2880;
                self->state = 0;
                PlayMusic(5);
                pauseEnabled = 0;
            } else {
                self->values[3] = 0;
                self->state = 2;
            }
        }
    }
}

void O_Players_PlayerObject::Player_State_HangBar()
{
    if (pLeft() == 1) {
        pDirection() = 1;
        pSpeed() = -0x20000;
        pAnimationSpeed() = 30;
    } else {
        if (pRight() == 1) {
            pDirection() = 0;
            pSpeed() = 0x20000;
            pAnimationSpeed() = 30;
        } else {
            pSpeed() = 0;
            pAnimationSpeed() = 0;
        }
    }
    scriptEng.tempValue[1] = pXPos();
    scriptEng.tempValue[1] >>= 16;
    scriptEng.tempValue[2] = pYPos();
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[2] += pCollisionTop();
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[1], scriptEng.tempValue[2], 8);
    if (scriptEng.tempValue[0] != 3) {
        pState() = PlayerStateID("Player_State_Air");
        pSpeed() = 0;
        pAnimationSpeed() = 0;
        pYVel() = 0;
    }
    if (pJumpPress() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pYVel() = 0;
        pSpeed() = 0;
        pAnimationSpeed() = 0;
        pYPos() += 0x40000;
    }
    pXVel() = pSpeed();
    if (GVar("Warp.Destination") > 0) {
        if (GVar("Warp.Timer") > 99) {
            if (GVar("Warp.Timer") < 204) {
                GVar("Warp.Destination") = 0;
            }
        }
        GVar("Warp.Timer") = 0;
    }
}

void O_Players_PlayerObject::Player_State_CorkscrewRun()
{
    pAngle() = 0;
    Player_HandleGroundMovement();
    pAnimation() = 34;
    if (pSpeed() < 0x60000) {
        if (pSpeed() > -0x60000) {
            pAnimation() = GVar("ANI_WALKING");
            pState() = PlayerStateID("Player_State_Air");
            pRotation() = 0;
            if (pSpeed() < 0) {
                pDirection() = 1;
            }
        }
    }
    if (pDown() == 1) {
        if (pSpeed() > 0x199A) {
            pState() = PlayerStateID("Player_State_CorkscrewRoll");
            pAnimation() = GVar("ANI_JUMPING");
        }
        if (pSpeed() < -0x199A) {
            pState() = PlayerStateID("Player_State_CorkscrewRoll");
            pAnimation() = GVar("ANI_JUMPING");
        }
    }
    if (pSkidding() > 0) {
        if (pSkidding() == 16) {
            PlaySfx(8, 0);
        }
        pAnimation() = GVar("ANI_SKIDDING");
        pSkidding()--;
    }
    if (pJumpPress() == 1) {
        Player_Action_Jump();
    } else {
        Player_HandleOnGround();
    }
}

void O_Players_PlayerObject::Player_State_CorkscrewRoll()
{
    pAngle() = 0;
    Player_HandleRollDeceleration();
    if (pSpeed() < 0x60000) {
        if (pSpeed() > -0x60000) {
            pState() = PlayerStateID("Player_State_Air");
        }
    }
    if (pJumpPress() == 1) {
        Player_Action_Jump();
    } else {
        Player_HandleOnGround();
    }
}

void O_Players_PlayerObject::Player_State_TubeRoll()
{
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pTimer() = 0;
        Player_HandleAirMovement();
    } else {
        if (pSpeed() > 0) {
            if (pSpeed() < PlayerValue(6)) {
                pSpeed() = PlayerValue(6);
            }
            if (pSpeed() > 0x100000) {
                pSpeed() = 0x100000;
            }
        } else {
            scriptEng.tempValue[0] = PlayerValue(6);
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
            if (pSpeed() > scriptEng.tempValue[0]) {
                pSpeed() = scriptEng.tempValue[0];
                Player_HandleOnGround();
            }
            if (pSpeed() < -0x100000) {
                pSpeed() = -0x100000;
            }
        }
        scriptEng.tempValue[0] = pSpeed();
        if (scriptEng.tempValue[0] < 0) {
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        }
        if (scriptEng.tempValue[0] < 0x5F5C2) {
            if (GVar("Warp.Destination") > 0) {
                if (GVar("Warp.Timer") > 99) {
                    if (GVar("Warp.Timer") < 204) {
                        GVar("Warp.Destination") = 0;
                    }
                }
                GVar("Warp.Timer") = 0;
            }
        } else {
            if (GVar("Warp.Destination") > 0) {
                if (GVar("Warp.Timer") == 0) {
                    GVar("Warp.Timer") = 1;
                    CreateTempObject(TypeNameID("Warp Star"), 0, pXPos(), pYPos());
                    objectEntityList[3].values[0] = 7;
                    objectEntityList[3].drawOrder = 4;
                }
            }
        }
        Player_HandleRollDeceleration();
        Player_HandleRollAnimSpeed();
        pAnimationSpeed() = PlayerValue(2);
        Player_HandleOnGround();
    }
}

void O_Players_PlayerObject::Player_State_TubeAirRoll()
{
    pRight() = 0;
    pLeft() = 0;
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pTimer() = 0;
        Player_HandleAirMovement();
    } else {
        if (pSpeed() > 0) {
            pSpeed() = PlayerValue(6);
        } else {
            scriptEng.tempValue[0] = PlayerValue(6);
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
            pSpeed() = scriptEng.tempValue[0];
        }
        scriptEng.tempValue[0] = pSpeed();
        if (scriptEng.tempValue[0] < 0) {
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        }
        if (scriptEng.tempValue[0] < 0x5F5C2) {
            if (GVar("Warp.Destination") > 0) {
                if (GVar("Warp.Timer") > 99) {
                    if (GVar("Warp.Timer") < 204) {
                        GVar("Warp.Destination") = 0;
                    }
                }
                GVar("Warp.Timer") = 0;
            }
        } else {
            if (GVar("Warp.Destination") > 0) {
                if (GVar("Warp.Timer") == 0) {
                    GVar("Warp.Timer") = 1;
                    CreateTempObject(TypeNameID("Warp Star"), 0, pXPos(), pYPos());
                    objectEntityList[3].values[0] = 7;
                    objectEntityList[3].drawOrder = 4;
                }
            }
        }
        Player_HandleRollDeceleration();
        Player_HandleRollAnimSpeed();
        pAnimationSpeed() = PlayerValue(2);
        Player_HandleOnGround();
    }
}

void O_Players_PlayerObject::Player_State_SpinningTop()
{
    pTimer() += PlayerValue(6);
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pAnimation() = GVar("ANI_WALKING");
        pTimer() = 0;
        Player_HandleAirMovement();
    } else {
        Player_HandleOnGround();
    }
}

void O_Players_PlayerObject::Player_State_Hugged()
{
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pAnimation() = GVar("ANI_WALKING");
        pTimer() = 0;
        Player_HandleAirMovement();
    } else {
        Player_HandleOnGround();
        if (pTimer() < 240) {
            pAnimation() = GVar("ANI_STOPPED");
            pTimer()++;
        } else {
            pAnimation() = GVar("ANI_WAITING");
        }
        if (GVar("Warp.Destination") > 0) {
            if (GVar("Warp.Timer") > 99) {
                if (GVar("Warp.Timer") < 204) {
                    GVar("Warp.Destination") = 0;
                }
            }
            GVar("Warp.Timer") = 0;
        }
        if (pJumpPress() == 1) {
            Player_Action_Jump();
        }
    }
}

void O_Players_PlayerObject::Player_State_Ramp3D()
{
    Player_HandleGroundMovement();
    if (pGravity() == 1) {
        pState() = PlayerStateID("Player_State_Air");
        pTimer() = 0;
        Player_HandleAirMovement();
        if (pDirection() == 1) {
            if (pAnimation() == GVar("ANI_RAMP_RUNNING3")) {
                pAnimation() = GVar("ANI_RAMP_RUNNING5");
            }
            if (pAnimation() == GVar("ANI_RAMP_RUNNING2")) {
                pAnimation() = GVar("ANI_RAMP_RUNNING6");
            }
        }
    } else {
        Player_HandleOnGround();
        if (pSpeed() == 0) {
            if (GVar("Warp.Destination") > 0) {
                if (GVar("Warp.Timer") > 99) {
                    if (GVar("Warp.Timer") < 204) {
                        GVar("Warp.Destination") = 0;
                    }
                }
                GVar("Warp.Timer") = 0;
            }
            if (pTimer() < 240) {
                pAnimation() = GVar("ANI_STOPPED");
                pTimer()++;
            } else {
                pAnimation() = GVar("ANI_WAITING");
            }
        } else {
            if (pAngle() == 0) {
                pAnimation() = GVar("ANI_RAMP_RUNNING1");
            }
            if (pAngle() > 200) {
                if (pDirection() == 0) {
                    pAnimation() = GVar("ANI_RAMP_RUNNING3");
                } else {
                    pAnimation() = GVar("ANI_RAMP_RUNNING5");
                }
            }
            if (pAngle() > 216) {
                if (pDirection() == 0) {
                    pAnimation() = GVar("ANI_RAMP_RUNNING2");
                } else {
                    pAnimation() = GVar("ANI_RAMP_RUNNING6");
                }
            }
            if (pAngle() > 232) {
                pAnimation() = GVar("ANI_RAMP_RUNNING1");
            }
            if (pAngle() == 192) {
                pAnimation() = GVar("ANI_RAMP_RUNNING4");
            }
        }
        if (pJumpPress() == 1) {
            Player_Action_Jump();
        } else {
            if (pUp() == 1) {
                if (pSpeed() == 0) {
                    pState() = PlayerStateID("Player_State_LookUp");
                    pAnimation() = GVar("ANI_LOOKINGUP");
                    pTimer() = 0;
                }
            }
            if (pDown() == 1) {
                if (pSpeed() == 0) {
                    pState() = PlayerStateID("Player_State_Crouch");
                    pAnimation() = GVar("ANI_LOOKINGDOWN");
                    pTimer() = 0;
                } else {
                    if (pSpeed() > 0x199A) {
                        pControlLock() = 0;
                        pState() = PlayerStateID("Player_State_Roll");
                        pAnimation() = GVar("ANI_JUMPING");
                    }
                    if (pSpeed() < -0x199A) {
                        pControlLock() = 0;
                        pState() = PlayerStateID("Player_State_Roll");
                        pAnimation() = GVar("ANI_JUMPING");
                    }
                }
            }
        }
    }
    if (pAnimation() != GVar("ANI_STOPPED")) {
        pAnimationSpeed() = pSpeed();
        if (pAnimationSpeed() < 0) {
            pAnimationSpeed() = -pAnimationSpeed();
        }
        pAnimationSpeed() *= 60;
        pAnimationSpeed() /= 0x60000;
        pAnimationSpeed() += 20;
    } else {
        pAnimationSpeed() = 0;
    }
}

void O_Players_PlayerObject::Player_State_WaterCurrent()
{
    pGravity() = 1;
    if (pUp() == 1) {
        pYPos() -= 0x20000;
    }
    if (pDown() == 1) {
        pYPos() += 0x20000;
    }
    if (pLeft() == 1) {
        pXPos() -= 0x20000;
    }
    if (pRight() == 1) {
        pXPos() += 0x20000;
    }
}

void O_Players_PlayerObject::Player_SetJumpOffset()
{
}

void O_Players_PlayerObject::Player_State_SizeChange()
{
    pTileCollisions() = 1;
    if (pGravity() == 1) {
        pTrackScroll() = 1;
        pYVel() += 0x3000;
        pXVel() = pSpeed();
    } else {
        pState() = PlayerStateID("Player_State_Ground");
        PlayerValue(4) = 120;
        PlayerValue(5) = 3;
        pSpeed() = 0;
        pXVel() = 0;
        Player_HandleOnGround();
        if (GVar("Mini_PlayerFlag") == 0) {
            GVar("Mini_PlayerFlag") = 1;
            PlayerValue(9) = -1;
            switch (playerListPos) {
                case 0:
                LoadAnimation_Script("MiniSonic.Ani");
                break;
                case 1:
                LoadAnimation_Script("MiniTails.Ani");
                objectEntityList[1].type = TypeNameID("Blank Object");
                break;
            }
        } else {
            GVar("Mini_PlayerFlag") = 0;
            switch (playerListPos) {
                case 0:
                LoadAnimation_Script("Sonic.Ani");
                PlayerValue(9) = -5;
                break;
                case 1:
                LoadAnimation_Script("Tails.Ani");
                PlayerValue(9) = -1;
                objectEntityList[1].type = TypeNameID("Tails Object");
                break;
            }
        }
        BindPlayerToObject_Script(0, 0);
    }
}

void O_Players_PlayerObject::Player_HandleDropDash()
{
}

void O_Players_PlayerObject::Player_Action_DblJumpKnux()
{
}

void O_Players_PlayerObject::Player_State_GlideLeft()
{
}

void O_Players_PlayerObject::Player_State_GlideRight()
{
}

void O_Players_PlayerObject::Player_State_GlideDrop()
{
}

void O_Players_PlayerObject::Player_State_GlideSlide()
{
}

void O_Players_PlayerObject::Player_State_Climb()
{
}

void O_Players_PlayerObject::Player_State_LedgePullUp()
{
}

void O_Players_PlayerObject::Player_State_GlideLeftNoGrip()
{
}

void O_Players_PlayerObject::Player_State_GlideRightNoGrip()
{
}

void O_Players_PlayerObject::Player_CheckRoofGlide()
{
}

void O_Players_PlayerObject::Player_Action_GlideDrop()
{
}

void O_Players_PlayerObject::Player_Action_DblJumpAmy()
{
}

void O_Players_PlayerObject::Player_Action_HammerDash()
{
}

void O_Players_PlayerObject::Player_State_HammerDash()
{
}

void O_Players_PlayerObject::Player_SetHammerDashSpeed()
{
}

void O_Players_PlayerObject::Player_Setup_Startup()
{
}

const Native::NativeFunctionDef O_Players_PlayerObject::funcs[69] = {
    { "Player_BadnikBreak", O_Players_PlayerObject::Player_BadnikBreak },
    { "Player_Hit", O_Players_PlayerObject::Player_Hit },
    { "Player_ClimbBlock", O_Players_PlayerObject::Player_ClimbBlock },
    { "Player_Unstick", O_Players_PlayerObject::Player_Unstick },
    { "Player_CancelClimb", O_Players_PlayerObject::Player_CancelClimb },
    { "Player_ForceNoGrip", O_Players_PlayerObject::Player_ForceNoGrip },
    { "Player_ForceGrip", O_Players_PlayerObject::Player_ForceGrip },
    { "Player_Kill", O_Players_PlayerObject::Player_Kill },
    { "Player_ProcessUpdate", O_Players_PlayerObject::Player_ProcessUpdate },
    { "Player_State_Static", O_Players_PlayerObject::Player_State_Static },
    { "Player_HandleRollAnimSpeed", O_Players_PlayerObject::Player_HandleRollAnimSpeed },
    { "Player_HandleWalkAnimSpeed", O_Players_PlayerObject::Player_HandleWalkAnimSpeed },
    { "Player_HandleRunAnimSpeed", O_Players_PlayerObject::Player_HandleRunAnimSpeed },
    { "Player_HandleGroundMovement", O_Players_PlayerObject::Player_HandleGroundMovement },
    { "Player_HandleAirFriction", O_Players_PlayerObject::Player_HandleAirFriction },
    { "Player_HandleRollDeceleration", O_Players_PlayerObject::Player_HandleRollDeceleration },
    { "Player_HandleAirMovement", O_Players_PlayerObject::Player_HandleAirMovement },
    { "Player_HandleOnGround", O_Players_PlayerObject::Player_HandleOnGround },
    { "Player_Action_Jump", O_Players_PlayerObject::Player_Action_Jump },
    { "Player_Action_Spindash_S2", O_Players_PlayerObject::Player_Action_Spindash_S2 },
    { "Player_Action_Spindash_CD", O_Players_PlayerObject::Player_Action_Spindash_CD },
    { "Player_Action_Peelout_S2", O_Players_PlayerObject::Player_Action_Peelout_S2 },
    { "Player_Action_Peelout_CD", O_Players_PlayerObject::Player_Action_Peelout_CD },
    { "Player_Action_DblJumpTails", O_Players_PlayerObject::Player_Action_DblJumpTails },
    { "Player_State_Ground", O_Players_PlayerObject::Player_State_Ground },
    { "Player_State_Air_NoDropDash", O_Players_PlayerObject::Player_State_Air_NoDropDash },
    { "Player_State_Air", O_Players_PlayerObject::Player_State_Air },
    { "Player_State_Roll", O_Players_PlayerObject::Player_State_Roll },
    { "Player_State_RollJump", O_Players_PlayerObject::Player_State_RollJump },
    { "Player_State_LookUp", O_Players_PlayerObject::Player_State_LookUp },
    { "Player_State_Crouch", O_Players_PlayerObject::Player_State_Crouch },
    { "Player_State_Spindash_S2", O_Players_PlayerObject::Player_State_Spindash_S2 },
    { "Player_State_Spindash_CD", O_Players_PlayerObject::Player_State_Spindash_CD },
    { "Player_State_Peelout_S2", O_Players_PlayerObject::Player_State_Peelout_S2 },
    { "Player_State_Peelout_CD", O_Players_PlayerObject::Player_State_Peelout_CD },
    { "Player_State_Fly", O_Players_PlayerObject::Player_State_Fly },
    { "Player_State_GotHit", O_Players_PlayerObject::Player_State_GotHit },
    { "Player_State_Hurt", O_Players_PlayerObject::Player_State_Hurt },
    { "Player_State_OuttaHere", O_Players_PlayerObject::Player_State_OuttaHere },
    { "Player_State_Death", O_Players_PlayerObject::Player_State_Death },
    { "Player_State_Drown", O_Players_PlayerObject::Player_State_Drown },
    { "Player_State_HangBar", O_Players_PlayerObject::Player_State_HangBar },
    { "Player_State_CorkscrewRun", O_Players_PlayerObject::Player_State_CorkscrewRun },
    { "Player_State_CorkscrewRoll", O_Players_PlayerObject::Player_State_CorkscrewRoll },
    { "Player_State_TubeRoll", O_Players_PlayerObject::Player_State_TubeRoll },
    { "Player_State_TubeAirRoll", O_Players_PlayerObject::Player_State_TubeAirRoll },
    { "Player_State_SpinningTop", O_Players_PlayerObject::Player_State_SpinningTop },
    { "Player_State_Hugged", O_Players_PlayerObject::Player_State_Hugged },
    { "Player_State_Ramp3D", O_Players_PlayerObject::Player_State_Ramp3D },
    { "Player_State_WaterCurrent", O_Players_PlayerObject::Player_State_WaterCurrent },
    { "Player_SetJumpOffset", O_Players_PlayerObject::Player_SetJumpOffset },
    { "Player_State_SizeChange", O_Players_PlayerObject::Player_State_SizeChange },
    { "Player_HandleDropDash", O_Players_PlayerObject::Player_HandleDropDash },
    { "Player_Action_DblJumpKnux", O_Players_PlayerObject::Player_Action_DblJumpKnux },
    { "Player_State_GlideLeft", O_Players_PlayerObject::Player_State_GlideLeft },
    { "Player_State_GlideRight", O_Players_PlayerObject::Player_State_GlideRight },
    { "Player_State_GlideDrop", O_Players_PlayerObject::Player_State_GlideDrop },
    { "Player_State_GlideSlide", O_Players_PlayerObject::Player_State_GlideSlide },
    { "Player_State_Climb", O_Players_PlayerObject::Player_State_Climb },
    { "Player_State_LedgePullUp", O_Players_PlayerObject::Player_State_LedgePullUp },
    { "Player_State_GlideLeftNoGrip", O_Players_PlayerObject::Player_State_GlideLeftNoGrip },
    { "Player_State_GlideRightNoGrip", O_Players_PlayerObject::Player_State_GlideRightNoGrip },
    { "Player_CheckRoofGlide", O_Players_PlayerObject::Player_CheckRoofGlide },
    { "Player_Action_GlideDrop", O_Players_PlayerObject::Player_Action_GlideDrop },
    { "Player_Action_DblJumpAmy", O_Players_PlayerObject::Player_Action_DblJumpAmy },
    { "Player_Action_HammerDash", O_Players_PlayerObject::Player_Action_HammerDash },
    { "Player_State_HammerDash", O_Players_PlayerObject::Player_State_HammerDash },
    { "Player_SetHammerDashSpeed", O_Players_PlayerObject::Player_SetHammerDashSpeed },
    { "Player_Setup_Startup", O_Players_PlayerObject::Player_Setup_Startup },
};

// --- native player state/action dispatch ------------------------------------
//  Player.State (a byte) and Player.Value10..12 hold indices into funcs[] above.
//  These replace the old CallScriptFunction(id) interpreter dispatch so the
//  player runs entirely natively — no scripts/bytecode required.
namespace Native
{
int PlayerFuncID(const char *funcName)
{
    for (int i = 0; i < 69; ++i)
        if (StrComp(O_Players_PlayerObject::funcs[i].name, funcName))
            return i;
    return -1;
}
void CallPlayerFunc(int id, byte sub)
{
    if (id < 0 || id >= 69)
        return;
    byte prev = scriptSub;
    scriptSub = sub;
    O_Players_PlayerObject::funcs[id].fn();
    scriptSub = prev;
}
} // namespace Native

#endif // RETRO_USE_NATIVE_OBJECTS
