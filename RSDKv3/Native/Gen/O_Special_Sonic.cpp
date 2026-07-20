#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_Sonic.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Sonic.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_Sonic::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Special/Sonic.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Special/Tails.gif");
    }
    objectEntityList[2].type = TypeNameID("Sonic");
    objectEntityList[2].priority = 1;
    objectEntityList[2].values[5] = 0x5800;
    objectEntityList[2].frame = 5;
    objectEntityList[2].values[1] = 5;
    objectEntityList[2].values[2] = 8;
    objectEntityList[2].animationSpeed = 30;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Sonic")) {
            pXPos() = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[2].values[0] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            pYPos() = 0;
            pAngle() = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            pAngle() <<= 1;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Blank Object"), 0, 0, 0);
        }
        scriptEng.arrayPosition[0]++;
    }
    AddSpriteFrame(-20, -4, 40, 8, 210, 377);
    AddSpriteFrame(-20, -48, 40, 48, 1, 197);
    AddSpriteFrame(-20, -48, 40, 48, 83, 197);
    AddSpriteFrame(-20, -48, 40, 48, 42, 197);
    AddSpriteFrame(-20, -48, 40, 48, 1, 197);
    AddSpriteFrame(-20, -48, 40, 48, 1, 246);
    AddSpriteFrame(-20, -48, 40, 48, 42, 246);
    AddSpriteFrame(-20, -48, 40, 48, 83, 246);
    AddSpriteFrame(-20, -48, 40, 48, 42, 246);
    AddSpriteFrame(-20, -48, 40, 48, 1, 1);
    AddSpriteFrame(-20, -48, 40, 48, 42, 1);
    AddSpriteFrame(-20, -48, 40, 48, 83, 1);
    AddSpriteFrame(-20, -48, 40, 48, 1, 50);
    AddSpriteFrame(-20, -48, 40, 48, 42, 50);
    AddSpriteFrame(-20, -48, 40, 48, 83, 50);
    AddSpriteFrame(-20, -48, 40, 48, 1, 99);
    AddSpriteFrame(-20, -48, 40, 48, 42, 99);
    AddSpriteFrame(-20, -48, 40, 48, 83, 99);
    AddSpriteFrame(-20, -48, 40, 48, 1, 148);
    AddSpriteFrame(-20, -48, 40, 48, 42, 148);
    AddSpriteFrame(-20, -48, 40, 48, 83, 148);
    AddSpriteFrame(-20, -48, 40, 48, 124, 1);
    AddSpriteFrame(-20, -48, 40, 48, 165, 1);
    AddSpriteFrame(-20, -48, 40, 48, 206, 1);
    AddSpriteFrame(-20, -48, 40, 48, 124, 50);
    AddSpriteFrame(-20, -48, 40, 48, 165, 50);
    AddSpriteFrame(-20, -48, 40, 48, 206, 50);
    AddSpriteFrame(-20, -48, 40, 48, 124, 50);
    AddSpriteFrame(-20, -48, 40, 48, 165, 50);
    AddSpriteFrame(-20, -48, 40, 48, 206, 50);
    AddSpriteFrame(-20, -48, 40, 48, 124, 1);
    AddSpriteFrame(-20, -48, 40, 48, 165, 1);
    AddSpriteFrame(-20, -48, 40, 48, 206, 1);
    AddSpriteFrame(-20, -48, 40, 48, 1, 148);
    AddSpriteFrame(-20, -48, 40, 48, 42, 148);
    AddSpriteFrame(-20, -48, 40, 48, 83, 148);
    AddSpriteFrame(-20, -48, 40, 48, 1, 99);
    AddSpriteFrame(-20, -48, 40, 48, 42, 99);
    AddSpriteFrame(-20, -48, 40, 48, 83, 99);
    AddSpriteFrame(-20, -40, 40, 40, 165, 99);
    AddSpriteFrame(-20, -40, 40, 40, 206, 99);
    AddSpriteFrame(-20, -40, 40, 40, 124, 140);
    AddSpriteFrame(-20, -40, 40, 40, 124, 99);
    AddSpriteFrame(-20, -48, 40, 48, 51, 344);
    AddSpriteFrame(-21, -48, 42, 48, 182, 295);
    AddSpriteFrame(-25, -48, 49, 48, 1, 344);
    if (playerListPos == 0) {
        AddSpriteFrame(-21, -48, 42, 48, 135, 410);
        AddSpriteFrame(-20, -48, 40, 48, 178, 410);
    }
    if (playerListPos == 1) {
        AddSpriteFrame(-21, -48, 42, 48, 135, 426);
        AddSpriteFrame(-20, -48, 40, 48, 178, 426);
    }
    AddSpriteFrame(-16, -32, 54, 32, 17, 442);
    AddSpriteFrame(-26, -32, 52, 32, 78, 442);
    AddSpriteFrame(-37, -32, 54, 32, 178, 475);
    AddSpriteFrame(-32, -32, 48, 32, 1, 475);
    AddSpriteFrame(-30, -32, 60, 32, 115, 475);
    AddSpriteFrame(-16, -32, 48, 32, 208, 344);
    AddSpriteFrame(-28, -48, 56, 48, 92, 344);
    AddSpriteFrame(-30, -32, 60, 32, 54, 475);
    if (playerListPos != 1) {
        AddSpriteFrame(-29, -32, 58, 32, 149, 344);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
        AddSpriteFrame(-30, -32, 60, 32, 149, 377);
    } else {
        AddSpriteFrame(-29, -32, 58, 37, 149, 344);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
        AddSpriteFrame(-30, -32, 60, 32, 149, 382);
    }
    AddSpriteFrame(-20, -48, 40, 48, 1, 393);
    AddSpriteFrame(-20, -48, 40, 48, 42, 393);
    AddSpriteFrame(-20, -48, 40, 48, 83, 393);
    AddSpriteFrame(-20, -48, 40, 48, 165, 140);
    AddSpriteFrame(-20, -48, 40, 48, 206, 140);
    AddSpriteFrame(-20, -48, 40, 48, 165, 189);
    AddSpriteFrame(-20, -48, 40, 48, 206, 189);
    AddSpriteFrame(-20, -48, 40, 48, 1, 197);
    AddSpriteFrame(-20, -48, 40, 48, 124, 246);
    AddSpriteFrame(-20, -48, 40, 48, 165, 246);
    AddSpriteFrame(-20, -48, 40, 48, 206, 246);
    AddSpriteFrame(-20, -48, 40, 48, 1, 295);
    AddSpriteFrame(-20, -48, 40, 48, 42, 295);
    AddSpriteFrame(-16, -48, 32, 48, 83, 295);
    AddSpriteFrame(-16, -48, 32, 48, 116, 295);
    AddSpriteFrame(-16, -48, 32, 48, 116, 295);
    AddSpriteFrame(-16, -48, 32, 48, 149, 295);
}

void O_Special_Sonic::ObjectMain()
{
    Entity *self = Self();

    if (objectEntityList[4].values[5] > 0) {
        objectEntityList[4].values[5]--;
    }
    switch (self->state) {
        case 0:
        Sonic_ProcessAnimation();
        self->values[6]++;
        if (self->values[6] == 120) {
            self->values[6] = 0;
            self->state = 1;
            self->frame = 2;
            self->values[1] = 4;
            self->values[2] = 4;
            self->values[3] = 0;
            self->animationSpeed = 20;
        }
        break;
        case 1:
        Sonic_ProcessAnimation();
        self->values[6]++;
        if (self->values[6] == 140) {
            self->values[6] = 0;
            self->state = 2;
            self->frame = 9;
            self->values[1] = 9;
            self->values[2] = 14;
            pSpeed() = 0;
        }
        break;
        case 2:
        Sonic_ProcessPlayer();
        if (pSpeed() < 0x50000) {
            pSpeed() += 0x0800;
        } else {
            pSpeed() = 0x50000;
        }
        if (keyDown.down == 1) {
            pSpeed() -= 0x0C00;
            if (pSpeed() < 0x1E000) {
                pSpeed() = 0x1E000;
            }
        }
        self->animationSpeed = pSpeed();
        self->animationSpeed *= 15;
        self->animationSpeed /= 0x14000;
        self->animationSpeed += 20;
        Sonic_HandleMovement();
        Sonic_ProcessAnimation();
        if (self->values[6] > 0) {
            self->values[6]--;
            pXPos() += pScreenXPos();
            self->values[0] += pScreenYPos();
        }
        Sonic_HandleTileInteractions();
        if (pJumpPress() == 1) {
            self->state = 3;
            self->values[6] = 0;
            self->frame = 39;
            self->values[1] = 39;
            self->values[2] = 42;
            self->values[3] = 0;
            self->animationSpeed = 80;
            pYVel() = 0x46000;
            PlaySfx(0, 0);
        }
        break;
        case 3:
        Sonic_ProcessPlayer();
        if (pSpeed() < 0x50000) {
            pSpeed() += 0x0800;
        }
        if (keyDown.down == 1) {
            pSpeed() -= 0x0C00;
            if (pSpeed() < 0x1E000) {
                pSpeed() = 0x1E000;
            }
        }
        if (pJumpHold() == 0) {
            if (pYVel() > 0x2A000) {
                pYVel() = 0x2A000;
            }
        }
        Sonic_HandleMovement();
        Sonic_ProcessAnimation();
        pYVel() -= 0x2000;
        pYPos() += pYVel();
        if (pYPos() < 0) {
            pYPos() = 0;
            if (objectEntityList[4].values[0] > 0) {
                if (objectEntityList[4].values[5] == 0) {
                    self->state = 2;
                    self->frame = 9;
                    self->values[1] = 9;
                    self->values[2] = 14;
                    self->values[3] = 0;
                } else {
                    self->state = 7;
                    self->frame = 77;
                    self->values[1] = 77;
                    self->values[2] = 80;
                    self->animationSpeed = 80;
                    self->values[3] = 0;
                }
            } else {
                pControlMode() = -1;
                self->state = 8;
                timeEnabled = 0;
            }
        }
        break;
        case 4:
        Sonic_ProcessPlayer();
        if (pSpeed() < 0x50000) {
            pSpeed() += 0x0800;
        }
        if (keyDown.down == 1) {
            pSpeed() -= 0x0C00;
            if (pSpeed() < 0x1E000) {
                pSpeed() = 0x1E000;
            }
        }
        Sonic_HandleMovement();
        Sonic_ProcessAnimation();
        if (self->values[6] > 0) {
            self->values[6]--;
            pXPos() += pScreenXPos();
            self->values[0] += pScreenYPos();
        } else {
            if (objectEntityList[4].values[5] == 0) {
                self->state = 2;
                self->frame = 9;
                self->values[1] = 9;
                self->values[2] = 14;
                self->values[3] = 0;
            } else {
                self->state = 7;
                self->frame = 77;
                self->values[1] = 77;
                self->values[2] = 80;
                self->animationSpeed = 80;
                self->values[3] = 0;
            }
        }
        Sonic_HandleTileInteractions();
        if (pJumpPress() == 1) {
            self->state = 3;
            self->values[6] = 0;
            self->frame = 39;
            self->values[1] = 39;
            self->values[2] = 42;
            self->animationSpeed = 80;
            pYVel() = 0x46000;
            PlaySfx(0, 0);
        }
        break;
        case 5:
        Sonic_ProcessPlayer();
        if (pSpeed() < 0x50000) {
            pSpeed() += 0x0800;
        }
        Sonic_HandleMovement();
        Sonic_ProcessAnimation();
        pYVel() -= 0x0800;
        pYPos() += pYVel();
        if (pYPos() < 0) {
            pYPos() = 0;
            if (objectEntityList[4].values[0] > 0) {
                if (objectEntityList[4].values[5] == 0) {
                    self->state = 2;
                    self->frame = 9;
                    self->values[1] = 9;
                    self->values[2] = 14;
                    self->values[3] = 0;
                } else {
                    self->state = 7;
                    self->frame = 77;
                    self->values[1] = 77;
                    self->values[2] = 80;
                    self->animationSpeed = 80;
                    self->values[3] = 0;
                }
            } else {
                self->state = 8;
                pControlMode() = -1;
                timeEnabled = 0;
            }
        }
        break;
        case 6:
        Sonic_HandlePause();
        pLeft() = 0;
        pRight() = 0;
        Sonic_HandleMovement();
        Sonic_ProcessAnimation();
        scriptEng.tempValue[0] = pXPos();
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[1] = self->values[0];
        scriptEng.tempValue[1] >>= 16;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 6);
        if (CheckResult() == 3) {
            self->state = 2;
            self->frame = 9;
            self->values[1] = 9;
            self->values[2] = 14;
            self->values[3] = 0;
        }
        if (self->values[6] > 0) {
            self->values[6]--;
        } else {
            if (objectEntityList[4].values[5] == 0) {
                self->state = 2;
                self->frame = 9;
                self->values[1] = 9;
                self->values[2] = 14;
                self->values[3] = 0;
            } else {
                self->state = 7;
                self->frame = 77;
                self->values[1] = 77;
                self->values[2] = 80;
                self->animationSpeed = 80;
                self->values[3] = 0;
            }
        }
        break;
        case 7:
        Sonic_ProcessPlayer();
        if (pSpeed() < 0x70000) {
            pSpeed() += 0x1000;
        }
        if (keyDown.down == 1) {
            pSpeed() -= 0x0C00;
            if (pSpeed() < 0x1E000) {
                pSpeed() = 0x1E000;
            }
        }
        Sonic_HandleMovement();
        Sonic_ProcessAnimation();
        if (self->values[6] > 0) {
            self->values[6]--;
            pXPos() += pScreenXPos();
            self->values[0] += pScreenYPos();
        }
        Sonic_HandleTileInteractions();
        if (pJumpPress() == 1) {
            self->state = 3;
            self->values[6] = 0;
            self->frame = 39;
            self->values[1] = 39;
            self->values[2] = 42;
            self->values[3] = 0;
            self->animationSpeed = 80;
            pYVel() = 0x46000;
            PlaySfx(0, 0);
        }
        if (objectEntityList[4].values[5] == 0) {
            self->state = 2;
            self->frame = 9;
            self->values[1] = 9;
            self->values[2] = 14;
            self->values[3] = 0;
        }
        break;
        case 8:
        self->frame = 1;
        self->values[6] = 0;
        pSpeed() = 0;
        break;
        case 9:
        if (self->values[6] < 128) {
            self->values[6]++;
            pAngle() -= 2;
            if (pAngle() < 0) {
                pAngle() += 512;
            }
        } else {
            if (objectEntityList[3].type == TypeNameID("Blank Object")) {
                ResetObjectEntity(3, TypeNameID("Time Stone"), 0, 0, -0x180000);
                objectEntityList[3].XPos = (SCREEN_CENTERX) << 16;
                objectEntityList[3].priority = 1;
            }
        }
        self->frame = self->values[6];
        self->frame >>= 4;
        self->frame += 81;
        break;
        case 10:
        if (self->values[6] == 308) {
            objectEntityList[30].type = TypeNameID("Stage Finish");
            objectEntityList[30].propertyValue = 1;
        } else {
            self->values[6]++;
        }
        break;
        case 11:
        Sonic_ProcessPlayer();
        if (pSpeed() < 0x50000) {
            pSpeed() += 0x0800;
        }
        if (keyDown.down == 1) {
            pSpeed() -= 0x0C00;
            if (pSpeed() < 0x1E000) {
                pSpeed() = 0x1E000;
            }
        }
        Sonic_HandleMovement();
        Sonic_ProcessAnimation();
        pYVel() -= 0x2000;
        pYPos() += pYVel();
        if (pYPos() < 0) {
            pYPos() = 0;
            if (objectEntityList[4].values[0] > 0) {
                if (objectEntityList[4].values[5] == 0) {
                    self->state = 2;
                    self->frame = 9;
                    self->values[1] = 9;
                    self->values[2] = 14;
                    self->values[3] = 0;
                } else {
                    self->state = 7;
                    self->frame = 77;
                    self->values[1] = 77;
                    self->values[2] = 80;
                    self->animationSpeed = 80;
                    self->values[3] = 0;
                }
            } else {
                pControlMode() = -1;
                self->state = 8;
            }
        }
        break;
    }
    if (pXPos() > xBoundary2) {
        pXPos() = xBoundary2;
    }
    if (pXPos() < xBoundary1) {
        pXPos() = xBoundary1;
    }
    if (self->values[0] > yBoundary2) {
        self->values[0] = yBoundary2;
    }
    if (self->values[0] < yBoundary1) {
        self->values[0] = yBoundary1;
    }
    stageLayouts[0].angle = pAngle();
    stageLayouts[0].XPos = Sin512(stageLayouts[0].angle);
    stageLayouts[0].ZPos = Cos512(stageLayouts[0].angle);
    stageLayouts[0].XPos *= -0x2C00;
    stageLayouts[0].ZPos *= -0x2C00;
    stageLayouts[0].XPos += pXPos();
    stageLayouts[0].ZPos += self->values[0];
    stageLayouts[0].YPos = pYPos();
    stageLayouts[0].YPos /= 3;
    stageLayouts[0].YPos += 0x580000;
}

void O_Special_Sonic::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = stageLayouts[0].YPos;
    scriptEng.tempValue[0] >>= 8;
    scriptEng.tempValue[0] *= 96;
    scriptEng.tempValue[0] /= 0x5800;
    scriptEng.tempValue[0] += 128;
    DrawSprite_ScreenXY(0, SCREEN_CENTERX, scriptEng.tempValue[0]);
    scriptEng.tempValue[0] = stageLayouts[0].YPos;
    scriptEng.tempValue[0] -= pYPos();
    scriptEng.tempValue[0] >>= 8;
    scriptEng.tempValue[0] *= 96;
    scriptEng.tempValue[0] /= 0x5800;
    scriptEng.tempValue[0] += 128;
    switch (self->state) {
        default:
        DrawSprite_ScreenXY(self->frame, SCREEN_CENTERX, scriptEng.tempValue[0]);
        break;
        case 2:
        scriptEng.tempValue[1] = self->frame;
        scriptEng.tempValue[2] = self->values[7];
        scriptEng.tempValue[2] >>= 2;
        scriptEng.tempValue[2] += 2;
        switch (scriptEng.tempValue[2]) {
            case 0:
            scriptEng.tempValue[1] += 6;
            self->direction = 1;
            break;
            case 1:
            scriptEng.tempValue[1] += 12;
            self->direction = 1;
            break;
            case 2:
            self->direction = 0;
            break;
            case 3:
            scriptEng.tempValue[1] += 18;
            self->direction = 0;
            break;
            case 4:
            scriptEng.tempValue[1] += 24;
            self->direction = 0;
            break;
        }
        DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_FLIP, SCREEN_CENTERX, scriptEng.tempValue[0]);
        break;
    }
}

void O_Special_Sonic::Sonic_ProcessPlayer()
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
                        objectEntityList[9].drawOrder = 6;
                        objectEntityList[9].priority = 2;
                        stageLayouts[0].type = 3;
                    } else {
                        Engine.Callback(13);
                    }
                }
            }
        }
        ::ProcessPlayerControl(Plr());
    }
}

void O_Special_Sonic::Sonic_HandlePause()
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
                        objectEntityList[9].drawOrder = 6;
                        objectEntityList[9].priority = 2;
                        stageLayouts[0].type = 3;
                    } else {
                        Engine.Callback(13);
                    }
                }
            }
        }
    }
}

void O_Special_Sonic::Sonic_HandleMovement()
{
    Entity *self = Self();

    if (pLeft() == 1) {
        self->values[7]--;
        if (self->values[7] < -8) {
            self->values[7] = -8;
        }
    } else {
        if (pRight() == 1) {
            self->values[7]++;
            if (self->values[7] > 8) {
                self->values[7] = 8;
            }
        } else {
            if (self->values[7] > 0) {
                self->values[7]--;
            }
            if (self->values[7] < 0) {
                self->values[7]++;
            }
        }
    }
    if (pLeft() == 1) {
        pAngle() += 2;
    }
    if (pRight() == 1) {
        pAngle() -= 2;
    }
    if (pAngle() < 0) {
        pAngle() += 512;
    }
    pAngle() &= 511;
    scriptEng.tempValue[0] = Sin512(pAngle());
    scriptEng.tempValue[0] *= pSpeed();
    scriptEng.tempValue[0] >>= 9;
    pXPos() += scriptEng.tempValue[0];
    scriptEng.tempValue[0] = Cos512(pAngle());
    scriptEng.tempValue[0] *= pSpeed();
    scriptEng.tempValue[0] >>= 9;
    self->values[0] += scriptEng.tempValue[0];
}

void O_Special_Sonic::Sonic_ProcessAnimation()
{
    Entity *self = Self();

    self->values[3] += self->animationSpeed;
    if (self->values[3] > 239) {
        self->values[3] -= 240;
        self->frame++;
        if (self->frame > self->values[2]) {
            self->frame = self->values[1];
        }
    }
}

void O_Special_Sonic::Sonic_HandleBumperInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[2] = 0;
    scriptEng.tempValue[0] -= 8;
    scriptEng.tempValue[1] -= 8;
    CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 6);
    if (CheckResult() == 3) {
        scriptEng.tempValue[2] = (1) ? (scriptEng.tempValue[2] | (1 << 0)) : (scriptEng.tempValue[2] & ~(1 << 0));
    }
    scriptEng.tempValue[0] += 16;
    CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 6);
    if (CheckResult() == 3) {
        scriptEng.tempValue[2] = (1) ? (scriptEng.tempValue[2] | (1 << 1)) : (scriptEng.tempValue[2] & ~(1 << 1));
    }
    scriptEng.tempValue[0] -= 16;
    scriptEng.tempValue[1] += 16;
    CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 6);
    if (CheckResult() == 3) {
        scriptEng.tempValue[2] = (1) ? (scriptEng.tempValue[2] | (1 << 2)) : (scriptEng.tempValue[2] & ~(1 << 2));
    }
    scriptEng.tempValue[0] += 16;
    CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 6);
    if (CheckResult() == 3) {
        scriptEng.tempValue[2] = (1) ? (scriptEng.tempValue[2] | (1 << 3)) : (scriptEng.tempValue[2] & ~(1 << 3));
    }
    if (scriptEng.tempValue[2] > 0) {
        scriptEng.tempValue[3] = pSpeed();
        scriptEng.tempValue[3] += 0x10000;
        if (self->values[6] != 32) {
            PlaySfx(globalSFXCount + 2, 0);
        }
        self->values[6] = 32;
        switch (scriptEng.tempValue[2]) {
            case 1:
            pScreenXPos() = scriptEng.tempValue[3];
            pScreenYPos() = scriptEng.tempValue[3];
            break;
            case 2:
            pScreenXPos() = scriptEng.tempValue[3];
            pScreenYPos() = scriptEng.tempValue[3];
            pScreenXPos() = -pScreenXPos();
            break;
            case 3:
            pScreenXPos() = 0;
            pScreenYPos() = scriptEng.tempValue[3];
            break;
            case 4:
            pScreenXPos() = scriptEng.tempValue[3];
            pScreenYPos() = scriptEng.tempValue[3];
            pScreenYPos() = -pScreenYPos();
            break;
            case 5:
            pScreenXPos() = scriptEng.tempValue[3];
            pScreenYPos() = 0;
            break;
            case 6:
            case 7:
            pScreenXPos() = scriptEng.tempValue[3];
            pScreenYPos() = scriptEng.tempValue[3];
            break;
            case 8:
            case 14:
            case 15:
            pScreenXPos() = scriptEng.tempValue[3];
            pScreenYPos() = scriptEng.tempValue[3];
            pScreenXPos() = -pScreenXPos();
            pScreenYPos() = -pScreenYPos();
            break;
            case 9:
            case 11:
            pScreenXPos() = scriptEng.tempValue[3];
            pScreenYPos() = scriptEng.tempValue[3];
            pScreenXPos() = -pScreenXPos();
            break;
            case 10:
            pScreenXPos() = scriptEng.tempValue[3];
            pScreenYPos() = 0;
            pScreenXPos() = -pScreenXPos();
            break;
            case 12:
            pScreenXPos() = 0;
            pScreenYPos() = scriptEng.tempValue[3];
            pScreenYPos() = -pScreenYPos();
            break;
            case 13:
            pScreenXPos() = scriptEng.tempValue[3];
            pScreenYPos() = scriptEng.tempValue[3];
            pScreenYPos() = -pScreenYPos();
            break;
        }
    }
}

void O_Special_Sonic::Sonic_HandleTileInteractions()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = pXPos();
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[1] = self->values[0];
    scriptEng.tempValue[1] >>= 16;
    Sonic_HandleBumperInteraction();
    scriptEng.tempValue[0] = pXPos();
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[1] = self->values[0];
    scriptEng.tempValue[1] >>= 16;
    CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 6);
    switch (CheckResult()) {
        case 1:
        objectEntityList[3].type = TypeNameID("Dust Puff");
        objectEntityList[3].drawOrder = 4;
        if (objectEntityList[4].values[5] == 0) {
            if (pSpeed() > 0x28000) {
                pSpeed() = 0x28000;
            }
        } else {
            if (pSpeed() > 0x50000) {
                pSpeed() = 0x50000;
            }
        }
        break;
        case 2:
        objectEntityList[3].type = TypeNameID("WaterSplash");
        objectEntityList[3].drawOrder = 4;
        objectEntityList[3].values[5] = 0x57FE;
        if (objectEntityList[4].values[5] > 0) {
            if (pSpeed() > 0x50000) {
                pSpeed() = 0x50000;
            }
        }
        break;
        case 4:
        self->state = 6;
        self->values[6] = 136;
        self->frame = 54;
        self->values[1] = 54;
        self->values[2] = 76;
        self->animationSpeed = 40;
        self->values[3] = 0;
        pSpeed() = 0x10000;
        if (objectEntityList[4].values[3] > 0) {
            PlaySfx(4, 0);
            scriptEng.tempValue[0] = objectEntityList[4].values[3];
            objectEntityList[4].values[3] >>= 1;
            scriptEng.tempValue[0] -= objectEntityList[4].values[3];
            if (scriptEng.tempValue[0] > 8) {
                scriptEng.tempValue[0] = 8;
            }
            if (objectEntityList[4].values[3] == 0) {
                objectEntityList[4].values[4] = -1;
            }
            while (scriptEng.tempValue[0] > 0) {
                CreateTempObject(TypeNameID("Ring"), 0, pXPos(), 0);
                objectEntityList[scriptEng.arrayPosition[2]].priority = 1;
                objectEntityList[scriptEng.arrayPosition[2]].values[0] = self->values[0];
                scriptEng.tempValue[1] = rand() % 64;
                scriptEng.tempValue[1] -= 32;
                scriptEng.tempValue[1] <<= 10;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = scriptEng.tempValue[1];
                scriptEng.tempValue[1] = Sin512(pAngle());
                scriptEng.tempValue[1] *= 96;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] += scriptEng.tempValue[1];
                scriptEng.tempValue[1] = rand() % 64;
                scriptEng.tempValue[1] += 32;
                scriptEng.tempValue[1] <<= 12;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[1];
                scriptEng.tempValue[1] = rand() % 64;
                scriptEng.tempValue[1] -= 32;
                scriptEng.tempValue[1] <<= 10;
                objectEntityList[scriptEng.arrayPosition[2]].values[3] = scriptEng.tempValue[1];
                scriptEng.tempValue[1] = Cos512(pAngle());
                scriptEng.tempValue[1] *= 96;
                objectEntityList[scriptEng.arrayPosition[2]].values[3] += scriptEng.tempValue[1];
                scriptEng.tempValue[0]--;
            }
        }
        break;
        case 5:
        self->state = 11;
        self->values[6] = 0;
        self->frame = 39;
        self->values[1] = 39;
        self->values[2] = 42;
        self->animationSpeed = 80;
        self->values[3] = 0;
        pYVel() = 0x8C000;
        PlaySfx(11, 0);
        break;
        case 6:
        self->state = 5;
        self->values[6] = 0;
        self->frame = 48;
        self->values[1] = 48;
        self->values[2] = 53;
        self->animationSpeed = 24;
        self->values[3] = 0;
        pYVel() = 0x28000;
        PlaySfx(globalSFXCount + 6, 0);
        break;
        case 7:
        self->values[6] = 40;
        pScreenXPos() = -0xC0000;
        pScreenYPos() = 0;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 1);
        if (CheckResult() == 1) {
            pScreenXPos() = -pScreenXPos();
        } else {
            if (CheckResult() == 3) {
                pScreenXPos() = -pScreenXPos();
            }
        }
        if (self->state != 4) {
            PlaySfx(globalSFXCount + 3, 0);
        }
        self->state = 4;
        self->frame = 43;
        self->values[1] = 43;
        self->values[2] = 47;
        self->animationSpeed = 24;
        self->values[3] = 0;
        break;
        case 8:
        self->values[6] = 40;
        pScreenXPos() = 0xC0000;
        pScreenYPos() = 0;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 1);
        if (CheckResult() == 1) {
            pScreenXPos() = -pScreenXPos();
        } else {
            if (CheckResult() == 3) {
                pScreenXPos() = -pScreenXPos();
            }
        }
        if (self->state != 4) {
            PlaySfx(globalSFXCount + 3, 0);
        }
        self->state = 4;
        self->frame = 43;
        self->values[1] = 43;
        self->values[2] = 47;
        self->animationSpeed = 24;
        self->values[3] = 0;
        break;
        case 9:
        self->values[6] = 40;
        pScreenXPos() = 0;
        pScreenYPos() = -0xC0000;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 1);
        if (CheckResult() == 2) {
            pScreenYPos() = -pScreenYPos();
        } else {
            if (CheckResult() == 3) {
                pScreenYPos() = -pScreenYPos();
            }
        }
        if (self->state != 4) {
            PlaySfx(globalSFXCount + 3, 0);
        }
        self->state = 4;
        self->frame = 43;
        self->values[1] = 43;
        self->values[2] = 47;
        self->animationSpeed = 24;
        self->values[3] = 0;
        break;
        case 10:
        self->values[6] = 40;
        pScreenXPos() = 0;
        pScreenYPos() = 0xC0000;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 1);
        if (CheckResult() == 2) {
            pScreenYPos() = -pScreenYPos();
        } else {
            if (CheckResult() == 3) {
                pScreenYPos() = -pScreenYPos();
            }
        }
        if (self->state != 4) {
            PlaySfx(globalSFXCount + 3, 0);
        }
        self->state = 4;
        self->frame = 43;
        self->values[1] = 43;
        self->values[2] = 47;
        self->animationSpeed = 24;
        self->values[3] = 0;
        break;
        case 11:
        if (self->values[6] != 16) {
            PlaySfx(globalSFXCount + 4, 0);
        }
        self->values[6] = 16;
        pScreenXPos() = -0x80000;
        pScreenYPos() = 0;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 1);
        if (CheckResult() == 1) {
            pScreenXPos() = -pScreenXPos();
        } else {
            if (CheckResult() == 3) {
                pScreenXPos() = -pScreenXPos();
            }
        }
        break;
        case 12:
        if (self->values[6] != 16) {
            PlaySfx(globalSFXCount + 4, 0);
        }
        self->values[6] = 16;
        pScreenXPos() = 0x80000;
        pScreenYPos() = 0;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 1);
        if (CheckResult() == 1) {
            pScreenXPos() = -pScreenXPos();
        } else {
            if (CheckResult() == 3) {
                pScreenXPos() = -pScreenXPos();
            }
        }
        break;
        case 13:
        if (self->values[6] != 16) {
            PlaySfx(globalSFXCount + 4, 0);
        }
        self->values[6] = 16;
        pScreenXPos() = 0;
        pScreenYPos() = -0x80000;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 1);
        if (CheckResult() == 2) {
            pScreenYPos() = -pScreenYPos();
        } else {
            if (CheckResult() == 3) {
                pScreenYPos() = -pScreenYPos();
            }
        }
        break;
        case 14:
        if (self->values[6] != 16) {
            PlaySfx(globalSFXCount + 4, 0);
        }
        self->values[6] = 16;
        pScreenXPos() = 0;
        pScreenYPos() = 0x80000;
        CheckResult() = Get16x16TileInfo_Script(scriptEng.tempValue[0], scriptEng.tempValue[1], 1);
        if (CheckResult() == 2) {
            pScreenYPos() = -pScreenYPos();
        } else {
            if (CheckResult() == 3) {
                pScreenYPos() = -pScreenYPos();
            }
        }
        break;
    }
}

const Native::NativeFunctionDef O_Special_Sonic::funcs[6] = {
    { "Sonic_ProcessPlayer", O_Special_Sonic::Sonic_ProcessPlayer },
    { "Sonic_HandlePause", O_Special_Sonic::Sonic_HandlePause },
    { "Sonic_HandleMovement", O_Special_Sonic::Sonic_HandleMovement },
    { "Sonic_ProcessAnimation", O_Special_Sonic::Sonic_ProcessAnimation },
    { "Sonic_HandleBumperInteraction", O_Special_Sonic::Sonic_HandleBumperInteraction },
    { "Sonic_HandleTileInteractions", O_Special_Sonic::Sonic_HandleTileInteractions },
};

#endif // RETRO_USE_NATIVE_OBJECTS
