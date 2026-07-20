#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_Amy2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Amy2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_Amy2::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects2.gif");
    AddSpriteFrame(-11, -20, 22, 40, 34, 208);
    AddSpriteFrame(-11, -20, 22, 40, 57, 208);
    AddSpriteFrame(-11, -20, 22, 40, 34, 208);
    AddSpriteFrame(-11, -20, 22, 40, 126, 167);
    AddSpriteFrame(-15, -20, 30, 40, 68, 167);
    AddSpriteFrame(-10, -20, 21, 40, 149, 109);
    AddSpriteFrame(-13, -20, 26, 40, 99, 167);
    AddSpriteFrame(-10, -20, 21, 40, 149, 109);
    AddSpriteFrame(-12, -20, 24, 40, 181, 208);
    AddSpriteFrame(-13, -20, 26, 40, 80, 208);
    AddSpriteFrame(-12, -20, 24, 40, 107, 208);
}

void O_R7_Amy2::ObjectMain()
{
    Entity *self = Self();

    if (pXPos() < self->XPos) {
        self->direction = 1;
    } else {
        self->direction = 0;
    }
    if (self->values[7] < 600) {
        self->values[7]++;
    } else {
        if (self->values[7] == 600) {
            self->values[7] = 601;
            pLeft() = 0;
            pRight() = 0;
            pUp() = 0;
            pDown() = 0;
            pControlMode() = -1;
            CreateTempObject(TypeNameID("Fade Music"), 3, self->XPos, self->YPos);
        }
    }
    switch (self->state) {
        case 0:
        self->values[0]++;
        switch (self->frame) {
            case 4:
            case 6:
            if (self->values[0] == 4) {
                self->values[0] = 0;
                self->frame++;
            }
            break;
            case 5:
            case 7:
            if (self->values[0] == 3) {
                self->values[0] = 0;
                self->frame++;
            }
            break;
        }
        if (self->frame > 7) {
            self->frame = 4;
        }
        if (self->direction == 0) {
            if (self->values[1] < 0x20000) {
                self->values[1] += 0x2000;
            }
            PlayerObjectCollision(C_TOUCH, -32, -360, 4, 360);
            if (CheckResult() == 1) {
                if (pGravity() == 0) {
                    if (pDirection() == self->direction) {
                        PlayerObjectCollision(C_TOUCH, -32, -20, 4, 20);
                        if (CheckResult() == 1) {
                            if (pAnimation() == GVar("ANI_SPINDASH")) {
                                self->state = 3;
                                self->frame = 9;
                                self->values[2] = -0x40000;
                                self->values[5] = 1;
                                self->values[1] = -0x10000;
                            } else {
                                if (self->values[7] < 600) {
                                    self->values[7] = 601;
                                    pLeft() = 0;
                                    pRight() = 0;
                                    pUp() = 0;
                                    pDown() = 0;
                                    pControlMode() = -1;
                                    CreateTempObject(TypeNameID("Fade Music"), 3, self->XPos, self->YPos);
                                }
                                HapticEffect_Script(52, 0, 0, 0);
                                self->state = 2;
                                self->frame = 8;
                                self->values[0] = 0;
                                pState() = PlayerStateID("Player_State_Hugged");
                                PlaySfx(globalSFXCount + 8, 0);
                                SetAchievement(1, 100);
                            }
                        } else {
                            self->state = 1;
                            self->frame = 0;
                            self->values[0] = 0;
                            self->values[1] = 0;
                        }
                    } else {
                    }
                }
            }
            if (self->XPos < self->values[4]) {
                self->XPos += self->values[1];
            } else {
                self->values[1] = 0;
                self->XPos = self->values[4];
                self->state = 4;
                self->frame = 0;
                self->values[0] = 0;
            }
        } else {
            if (self->values[1] > -0x20000) {
                self->values[1] -= 0x2000;
            }
            PlayerObjectCollision(C_TOUCH, -4, -360, 32, 360);
            if (CheckResult() == 1) {
                if (pGravity() == 0) {
                    if (pDirection() == self->direction) {
                        PlayerObjectCollision(C_TOUCH, -32, -20, 4, 20);
                        if (CheckResult() == 1) {
                            if (pAnimation() == GVar("ANI_SPINDASH")) {
                                self->state = 3;
                                self->frame = 9;
                                self->values[2] = -0x40000;
                                self->values[5] = 1;
                                self->values[1] = 0x10000;
                            } else {
                                if (self->values[7] < 600) {
                                    self->values[7] = 601;
                                    pLeft() = 0;
                                    pRight() = 0;
                                    pUp() = 0;
                                    pDown() = 0;
                                    pControlMode() = -1;
                                    CreateTempObject(TypeNameID("Fade Music"), 3, self->XPos, self->YPos);
                                }
                                self->state = 2;
                                self->frame = 8;
                                self->values[0] = 0;
                                pState() = PlayerStateID("Player_State_Hugged");
                                PlaySfx(globalSFXCount + 8, 0);
                                SetAchievement(1, 100);
                                HapticEffect_Script(52, 0, 0, 0);
                            }
                        } else {
                            self->state = 1;
                            self->frame = 0;
                            self->values[0] = 0;
                            self->values[1] = 0;
                        }
                    } else {
                    }
                }
            }
            if (self->XPos > self->values[3]) {
                self->XPos += self->values[1];
            } else {
                self->values[1] = 0;
                self->XPos = self->values[3];
                self->state = 5;
                self->frame = 0;
                self->values[0] = 0;
            }
        }
        break;
        case 1:
        self->values[0]++;
        if (self->values[0] == 12) {
            self->values[0] = 0;
            self->frame++;
        }
        if (self->frame > 3) {
            self->frame = 0;
        }
        PlayerObjectCollision(C_TOUCH, -4, -360, 4, 360);
        if (CheckResult() == 0) {
            if (pGravity() == 0) {
                self->state = 0;
                self->frame = 4;
                self->values[0] = 0;
            }
        } else {
            if (pGravity() == 1) {
                self->state = 0;
                self->frame = 4;
                self->values[0] = 0;
            }
        }
        break;
        case 2:
        pSpeed() = 0;
        pXVel() = 0;
        pDirection() = self->direction;
        break;
        case 3:
        if (self->values[2] > 0) {
            self->frame = 10;
        }
        if (self->values[1] > 0) {
            self->values[1] -= 0x800;
        }
        if (self->values[1] < 0) {
            self->values[1] += 0x800;
        }
        self->XPos += self->values[1];
        if (self->values[5] == 0) {
            if (self->values[0] == 16) {
                self->state = 0;
                self->frame = 4;
                self->values[0] = 0;
            } else {
                self->values[0]++;
            }
        }
        break;
        case 4:
        self->values[0]++;
        if (self->values[0] == 12) {
            self->values[0] = 0;
            self->frame++;
        }
        if (self->frame > 3) {
            self->frame = 0;
        }
        if (self->direction == 1) {
            self->state = 0;
            self->frame = 4;
            self->values[0] = 0;
        }
        break;
        case 5:
        self->values[0]++;
        if (self->values[0] == 12) {
            self->values[0] = 0;
            self->frame++;
        }
        if (self->frame > 3) {
            self->frame = 0;
        }
        if (self->direction == 0) {
            self->state = 0;
            self->frame = 4;
            self->values[0] = 0;
        }
        break;
    }
    self->values[6]++;
    if (self->state == 7) {
        if (self->values[6] > 15) {
            CreateTempObject(TypeNameID("Love Heart"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (6)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 255;
            self->values[6] = 0;
        }
    } else {
        if (self->values[6] > 41) {
            CreateTempObject(TypeNameID("Love Heart"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) - (6)) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 255;
            self->values[6] = 0;
        }
    }
    if (self->values[5] == 0) {
        ObjectTileGrip_Script(0, 0, 19, 0);
    } else {
        self->values[2] += 0x4000;
        self->YPos += self->values[2];
        ObjectTileCollision_Script(0, 0, 19, 0);
        if (CheckResult() == 1) {
            self->values[2] = 0;
            self->values[5] = 0;
        }
    }
}

void O_R7_Amy2::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
