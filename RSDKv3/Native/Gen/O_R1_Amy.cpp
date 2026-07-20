#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Amy.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Amy.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Amy::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-11, -20, 22, 40, 34, 208);
    AddSpriteFrame(-11, -20, 22, 40, 57, 208);
    AddSpriteFrame(-11, -20, 22, 40, 34, 208);
    AddSpriteFrame(-11, -20, 22, 40, 126, 167);
    AddSpriteFrame(-15, -20, 30, 40, 68, 167);
    AddSpriteFrame(-10, -20, 21, 40, 166, 101);
    AddSpriteFrame(-13, -20, 26, 40, 99, 167);
    AddSpriteFrame(-10, -20, 21, 40, 166, 101);
    AddSpriteFrame(-12, -20, 24, 40, 181, 208);
    AddSpriteFrame(-13, -20, 26, 40, 80, 208);
    AddSpriteFrame(-12, -20, 24, 40, 107, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-12, -20, 22, 40, 158, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    AddSpriteFrame(-14, -20, 25, 40, 132, 208);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Amy Rose")) {
            if (playerListPos != 0) {
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            } else {
                if (GVar("Options.GameMode") == 2) {
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                } else {
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] -= 0x1400000;
                    objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                    objectEntityList[scriptEng.arrayPosition[0]].values[3] += 0x400000;
                    objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
                }
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_Amy::ObjectMain()
{
    Entity *self = Self();

    self->priority = 1;
    if (pXPos() < self->XPos) {
        self->direction = 1;
    } else {
        self->direction = 0;
    }
    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = self->values[6];
        scriptEng.tempValue[0] /= 10;
        scriptEng.tempValue[0] += 11;
        self->frame = scriptEng.tempValue[0];
        self->values[6]++;
        if (self->values[6] > 139) {
            self->values[6] = 0;
        }
        PlayerObjectCollision(C_TOUCH, -96, -360, 96, 360);
        if (CheckResult() == 1) {
            self->values[0] = 0;
            self->state = 1;
            self->frame = 4;
            self->values[6] = 0;
        }
        break;
        case 1:
        self->values[6]++;
        switch (self->frame) {
            case 4:
            case 6:
            if (self->values[6] == 4) {
                self->values[6] = 0;
                self->frame++;
            }
            break;
            case 5:
            case 7:
            if (self->values[6] == 3) {
                self->values[6] = 0;
                self->frame++;
            }
            break;
        }
        if (self->frame > 7) {
            self->frame = 4;
        }
        if (self->direction == 0) {
            if (self->values[0] < 0x20000) {
                self->values[0] += 0x1000;
            }
            PlayerObjectCollision(C_TOUCH, -32, -360, 4, 360);
            if (CheckResult() == 1) {
                if (pGravity() == 0) {
                    if (pDirection() == self->direction) {
                        PlayerObjectCollision(C_TOUCH, -32, -20, 4, 20);
                        if (CheckResult() == 1) {
                            CheckResult() = (pAnimation() == GVar("ANI_SPINDASH"));
                            scriptEng.tempValue[0] = CheckResult();
                            CheckResult() = (objectEntityList[2].type == TypeNameID("Blue Shield"));
                            scriptEng.tempValue[0] |= CheckResult();
                            if (scriptEng.tempValue[0] == 1) {
                                self->state = 8;
                                self->frame = 9;
                                self->values[1] = -0x40000;
                                self->values[5] = 1;
                                self->values[0] = -0x10000;
                            } else {
                                self->values[4] = 1;
                                self->state = 7;
                                self->frame = 8;
                                self->values[6] = 0;
                                pState() = PlayerStateID("Player_State_Hugged");
                                PlaySfx(globalSFXCount + 3, 0);
                                HapticEffect_Script(52, 0, 0, 0);
                                if (debugMode == 0) {
                                    SetAchievement(1, 100);
                                }
                            }
                        } else {
                            self->state = 6;
                            self->frame = 0;
                            self->values[6] = 0;
                            self->values[0] = 0;
                        }
                    } else {
                        self->state = 6;
                        self->frame = 0;
                        self->values[6] = 0;
                        self->values[0] = 0;
                    }
                }
            }
            if (self->XPos < self->values[3]) {
                self->XPos += self->values[0];
            } else {
                self->values[0] = 0;
                self->XPos = self->values[3];
                if (self->values[4] == 1) {
                    self->state = 4;
                } else {
                    self->state = 2;
                    self->frame = 0;
                    self->values[6] = 0;
                }
            }
        } else {
            if (self->values[0] > -0x20000) {
                self->values[0] -= 0x1000;
            }
            PlayerObjectCollision(C_TOUCH, -4, -360, 32, 360);
            if (CheckResult() == 1) {
                if (pGravity() == 0) {
                    if (pDirection() == self->direction) {
                        PlayerObjectCollision(C_TOUCH, -32, -20, 4, 20);
                        if (CheckResult() == 1) {
                            CheckResult() = (pAnimation() == GVar("ANI_SPINDASH"));
                            scriptEng.tempValue[0] = CheckResult();
                            CheckResult() = (objectEntityList[2].type == TypeNameID("Blue Shield"));
                            scriptEng.tempValue[0] |= CheckResult();
                            if (scriptEng.tempValue[0] == 1) {
                                self->state = 8;
                                self->frame = 9;
                                self->values[1] = -0x40000;
                                self->values[5] = 1;
                                self->values[0] = 0x10000;
                            } else {
                                self->values[4] = 1;
                                self->state = 7;
                                self->frame = 8;
                                self->values[6] = 0;
                                pState() = PlayerStateID("Player_State_Hugged");
                                PlaySfx(globalSFXCount + 3, 0);
                                HapticEffect_Script(52, 0, 0, 0);
                                if (debugMode == 0) {
                                    SetAchievement(1, 100);
                                }
                            }
                        } else {
                            self->state = 6;
                            self->frame = 0;
                            self->values[6] = 0;
                            self->values[0] = 0;
                        }
                    } else {
                        self->state = 6;
                        self->frame = 0;
                        self->values[6] = 0;
                        self->values[0] = 0;
                    }
                }
            }
            if (self->XPos > self->values[2]) {
                self->XPos += self->values[0];
            } else {
                self->values[0] = 0;
                self->XPos = self->values[2];
                if (self->values[4] == 1) {
                    self->state = 5;
                } else {
                    self->state = 3;
                    self->frame = 0;
                    self->values[6] = 0;
                }
            }
        }
        break;
        case 2:
        self->values[6]++;
        if (self->values[6] == 12) {
            self->values[6] = 0;
            self->frame++;
        }
        if (self->frame > 3) {
            self->frame = 0;
        }
        if (self->direction == 1) {
            self->state = 1;
            self->frame = 4;
            self->values[6] = 0;
        }
        break;
        case 3:
        self->values[6]++;
        if (self->values[6] == 12) {
            self->values[6] = 0;
            self->frame++;
        }
        if (self->frame > 3) {
            self->frame = 0;
        }
        if (self->direction == 0) {
            self->state = 1;
            self->frame = 4;
            self->values[6] = 0;
        }
        break;
        case 4:
        if (self->values[6] < 8) {
            self->frame = 0;
        } else {
            if (self->values[6] > 47) {
                if (self->values[5] == 0) {
                    if (self->values[6] < 120) {
                        self->values[1] = -0x40000;
                        self->values[5] = 1;
                        self->frame = 9;
                    } else {
                        self->values[6] = 0;
                    }
                } else {
                    if (self->values[1] > 0) {
                        self->frame = 0;
                    }
                }
            } else {
                scriptEng.tempValue[0] = self->values[6];
                scriptEng.tempValue[0] -= 8;
                scriptEng.tempValue[0] %= 20;
                scriptEng.tempValue[0] /= 10;
                self->frame = scriptEng.tempValue[0];
                self->frame += 9;
            }
        }
        if (self->values[5] == 0) {
            if (self->direction == 1) {
                self->state = 1;
                self->frame = 4;
                self->values[6] = 0;
            }
        }
        self->values[6]++;
        break;
        case 5:
        if (self->values[6] < 8) {
            self->frame = 0;
        } else {
            if (self->values[6] > 47) {
                if (self->values[5] == 0) {
                    if (self->values[6] < 120) {
                        self->values[1] = -0x40000;
                        self->values[5] = 1;
                        self->frame = 9;
                    } else {
                        self->values[6] = 0;
                    }
                } else {
                    if (self->values[1] > 0) {
                        self->frame = 0;
                    }
                }
            } else {
                scriptEng.tempValue[0] = self->values[6];
                scriptEng.tempValue[0] -= 8;
                scriptEng.tempValue[0] %= 20;
                scriptEng.tempValue[0] /= 10;
                self->frame = scriptEng.tempValue[0];
                self->frame += 9;
            }
        }
        if (self->values[5] == 0) {
            if (self->direction == 0) {
                self->state = 1;
                self->frame = 4;
                self->values[6] = 0;
            }
        }
        self->values[6]++;
        break;
        case 6:
        self->values[6]++;
        if (self->values[6] == 12) {
            self->values[6] = 0;
            self->frame++;
        }
        if (self->frame > 3) {
            self->frame = 0;
        }
        PlayerObjectCollision(C_TOUCH, -4, -360, 4, 360);
        if (CheckResult() == 0) {
            if (pGravity() == 0) {
                self->state = 1;
                self->frame = 4;
                self->values[6] = 0;
            }
        } else {
            if (pGravity() == 1) {
                self->state = 1;
                self->frame = 4;
                self->values[6] = 0;
            }
        }
        break;
        case 7:
        pSpeed() = 0;
        pXVel() = 0;
        pDirection() = self->direction;
        if (pAnimation() == GVar("ANI_JUMPING")) {
            self->state = 8;
            self->frame = 9;
            self->values[1] = -0x40000;
            self->values[5] = 1;
            if (self->direction == 0) {
                self->values[0] = -0x10000;
            } else {
                self->values[0] = 0x10000;
            }
        }
        break;
        case 8:
        if (self->values[1] > 0) {
            self->frame = 10;
        }
        if (self->values[0] > 0) {
            self->values[0] -= 0x800;
        }
        if (self->values[0] < 0) {
            self->values[0] += 0x800;
        }
        self->XPos += self->values[0];
        if (self->values[5] == 0) {
            if (self->values[6] == 16) {
                self->state = 1;
                self->frame = 4;
                self->values[6] = 0;
            } else {
                self->values[6]++;
            }
        }
        if (self->XPos > self->values[3]) {
            self->XPos = self->values[3];
        }
        break;
    }
    self->values[7]++;
    if (self->state == 7) {
        if (self->values[7] > 15) {
            CreateTempObject(TypeNameID("Love Heart"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (6)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 255;
            self->values[7] = 0;
        }
    } else {
        if (self->values[7] > 41) {
            CreateTempObject(TypeNameID("Love Heart"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (6)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 255;
            self->values[7] = 0;
        }
    }
    if (self->values[5] == 0) {
        ObjectTileGrip_Script(0, 0, 19, 0);
    } else {
        self->values[1] += 0x4000;
        self->YPos += self->values[1];
        ObjectTileCollision_Script(0, 0, 19, 0);
        if (CheckResult() == 1) {
            self->values[1] = 0;
            self->values[5] = 0;
        }
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->priority = 0;
        self->state = 0;
        self->values[4] = 0;
    }
}

void O_R1_Amy::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
