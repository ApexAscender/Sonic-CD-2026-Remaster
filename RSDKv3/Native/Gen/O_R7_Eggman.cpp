#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_Eggman.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Eggman.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_Eggman::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects2.gif");
    AddSpriteFrame(-40, -24, 72, 72, 91, 1);
    AddSpriteFrame(-24, -9, 24, 16, 164, 1);
    AddSpriteFrame(22, 27, 8, 8, 75, 99);
    AddSpriteFrame(-32, 8, 16, 24, 176, 142);
    AddSpriteFrame(-68, -10, 40, 16, 66, 133);
    AddSpriteFrame(-60, -10, 32, 16, 66, 116);
    AddSpriteFrame(-68, -10, 40, 16, 124, 150);
    AddSpriteFrame(-60, -10, 32, 16, 66, 150);
    AddSpriteFrame(-63, 30, 32, 16, 66, 150);
    AddSpriteFrame(-55, 30, 24, 16, 99, 150);
    AddSpriteFrame(-63, 30, 32, 16, 66, 116);
    AddSpriteFrame(-55, 30, 24, 16, 99, 116);
    AddSpriteFrame(-8, 0, 16, 32, 91, 74);
    AddSpriteFrame(-8, 0, 16, 32, 108, 74);
}

void O_R7_Eggman::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        xBoundary2 = (objectEntityList[objectLoop].XPos >> 16);
        xBoundary2 -= 64;
        scriptEng.tempValue[0] = xBoundary2;
        scriptEng.tempValue[0] -= SCREEN_XSIZE;
        newXBoundary1 = scriptEng.tempValue[0];
        PlayerObjectCollision(C_TOUCH, -256, -256, 0, 256);
        if (CheckResult() == 1) {
            CreateTempObject(TypeNameID("Fade Music"), 0, self->XPos, self->YPos);
            self->direction = 1;
            self->priority = 1;
            self->state++;
        }
        break;
        case 1:
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->animation = 1;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 140) {
            self->XPos -= 0x60000;
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->direction = 0;
            self->state++;
        }
        break;
        case 3:
        if (self->values[0] < 160) {
            self->XPos += 0x60000;
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->direction = 1;
            self->state++;
        }
        break;
        case 4:
        if (self->values[0] < 47) {
            self->XPos -= 0x60000;
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->animation = 0;
            self->state++;
        }
        break;
        case 5:
        if (self->values[0] < 94) {
            self->values[0]++;
            if (self->values[0] == 30) {
                objectEntityList[objectLoop + 1].state = 1;
                objectEntityList[objectLoop + 1].animation = 2;
                objectEntityList[objectLoop + 1].values[0] = 0;
            }
            if (self->values[0] == 90) {
                self->values[2] = 1;
            }
        } else {
            self->values[0] = 0;
            self->animation = 1;
            self->values[5] = -0x60000;
            self->state++;
        }
        break;
        case 6:
        self->XPos -= 0x20000;
        if (self->values[0] < 6) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 0;
            self->state++;
        }
        break;
        case 7:
        self->XPos -= 0x20000;
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 1;
            self->state++;
        }
        break;
        case 8:
        self->XPos -= 0x20000;
        if (self->values[0] < 10) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 0;
            self->state++;
        }
        break;
        case 9:
        self->XPos -= 0x20000;
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 1;
            self->state++;
        }
        break;
        case 10:
        self->XPos -= 0x20000;
        if (self->values[0] < 10) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 0;
            self->state++;
        }
        R7Eggman_FollowGround();
        break;
        case 11:
        self->XPos -= 0x20000;
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            if (objectEntityList[24].propertyValue == 2) {
                if (GVar("Options.Soundtrack") == 0) {
                    SetMusicTrack_Script("JP/R7D.ogg", 0, 1);
                } else {
                    SetMusicTrack_Script("US/R7D.ogg", 0, 92324);
                }
            }
            CreateTempObject(TypeNameID("Fade Music"), 2, self->XPos, self->YPos);
            objectEntityList[objectLoop - 2].state = 1;
            objectEntityList[objectLoop - 1].state = 3;
            objectEntityList[objectLoop - 1].values[0] = 0x400000;
            objectEntityList[objectLoop - 1].YPos -= 0x400000;
            self->values[0] = 0;
            self->direction = 0;
            self->values[2] = 1;
            self->values[5] = 0x60000;
            self->values[1] = 0x20000;
            self->state++;
        }
        R7Eggman_FollowGround();
        break;
        case 12:
        self->XPos += self->values[1];
        scriptEng.tempValue[0] = (objectEntityList[objectLoop].XPos >> 16);
        scriptEng.tempValue[0] -= 16;
        if (xBoundary2 < 16352) {
            scriptEng.tempValue[1] = pXVel();
            scriptEng.tempValue[1] >>= 16;
            xBoundary2 += 6;
            xBoundary2 += scriptEng.tempValue[1];
        }
        if (xBoundary1 < scriptEng.tempValue[0]) {
            xBoundary1 = scriptEng.tempValue[0];
        }
        if (self->values[0] < 360) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            xBoundary2 = (objectEntityList[objectLoop - 1].XPos >> 16);
            xBoundary2 += 112;
            self->state++;
        }
        R7Eggman_FollowGround();
        break;
        case 13:
        scriptEng.tempValue[0] = self->values[1];
        self->values[6]++;
        self->values[6] &= 0x3FFF;
        scriptEng.tempValue[1] = self->values[6];
        scriptEng.tempValue[1] >>= 4;
        self->values[1] += scriptEng.tempValue[1];
        if (self->values[1] > 0x50000) {
            self->values[1] = 0x50000;
        }
        scriptEng.tempValue[1] = xScrollOffset;
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] -= self->XPos;
        if (scriptEng.tempValue[1] > 0) {
            scriptEng.tempValue[1] >>= 7;
            if (scriptEng.tempValue[1] > 0x40000) {
                scriptEng.tempValue[1] = 0x40000;
            }
            scriptEng.tempValue[0] += scriptEng.tempValue[1];
        }
        if (scriptEng.tempValue[0] > 0x50000) {
            scriptEng.tempValue[0] = 0x50000;
        }
        if (scriptEng.tempValue[0] > 0x30000) {
            scriptEng.tempValue[0] -= 0x30000;
            self->XPos += 0x30000;
            R7Eggman_FollowGround();
            self->XPos += scriptEng.tempValue[0];
            R7Eggman_FollowGround();
        } else {
            self->XPos += scriptEng.tempValue[0];
            R7Eggman_FollowGround();
        }
        scriptEng.tempValue[0] = (objectEntityList[objectLoop].XPos >> 16);
        scriptEng.tempValue[0] -= 16;
        if (xBoundary1 < scriptEng.tempValue[0]) {
            xBoundary1 = scriptEng.tempValue[0];
            if (xBoundary1 > 15840) {
                xBoundary1 = 15840;
            }
        }
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 1].XPos;
        scriptEng.tempValue[0] -= 0x220000;
        if (self->XPos > scriptEng.tempValue[0]) {
            self->XPos = scriptEng.tempValue[0];
            self->animation = 0;
            self->values[1] = 0;
            self->state++;
        }
        break;
        case 14:
        if (pAnimation() != GVar("ANI_DYING")) {
            if (self->values[0] < 50) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->values[2] = 0;
                self->state++;
            }
        }
        break;
        case 15:
        if (self->values[0] < 20) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 1;
            self->state++;
        }
        break;
        case 16:
        if (self->values[0] < 20) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 0;
            self->state++;
        }
        break;
        case 17:
        if (self->values[0] < 20) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 1;
            self->state++;
        }
        break;
        case 18:
        if (self->values[0] < 20) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 0;
            self->state++;
        }
        break;
        case 19:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 20:
        self->YPos += 0x20000;
        if (self->values[0] < 42) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 0;
            self->state++;
        }
        break;
        case 21:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            GVar("Player.Score") += 1000;
            self->values[0] = 0;
            self->animation = 1;
            self->state++;
        }
        break;
        case 22:
        self->XPos += 0x60000;
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
            self->priority = 0;
            if (objectEntityList[24].propertyValue == 2) {
                if (GVar("Options.Soundtrack") == 0) {
                    SetMusicTrack_Script("JP/R7C.ogg", 0, 103060);
                } else {
                    SetMusicTrack_Script("US/R7C.ogg", 0, 136670);
                }
                CreateTempObject(TypeNameID("Fade Music"), 1, self->XPos, self->YPos);
            }
            newXBoundary2 = 16352;
        }
        break;
    }
    if (self->values[2] == 1) {
        if (self->values[3] == 0) {
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos += self->values[5];
            objectEntityList[scriptEng.arrayPosition[2]].YPos += 0xB00000;
            scriptEng.arrayPosition[0] = self->values[4];
            self->values[4] = (scriptEng.arrayPosition[2]);
            self->values[3] = 8;
            if (objectEntityList[scriptEng.arrayPosition[0]].drawOrder == 3) {
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                scriptEng.tempValue[0] = rand() % 4;
                CreateTempObject(TypeNameID("Debris"), scriptEng.tempValue[0], self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].XPos += self->values[5];
                objectEntityList[scriptEng.arrayPosition[2]].YPos += 0xB00000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 6;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 16;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] -= 0x28000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] += self->values[1];
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = rand() % 3;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] += 2;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] <<= 16;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = -objectEntityList[scriptEng.arrayPosition[2]].values[2];
            }
        } else {
            scriptEng.arrayPosition[0] = self->values[4];
            objectEntityList[scriptEng.arrayPosition[0]].XPos = self->XPos;
            objectEntityList[scriptEng.arrayPosition[0]].XPos += self->values[5];
            objectEntityList[scriptEng.arrayPosition[0]].YPos = self->YPos;
            objectEntityList[scriptEng.arrayPosition[0]].YPos += 0xB00000;
            self->values[3]--;
        }
    } else {
        if (self->values[3] > 0) {
            scriptEng.arrayPosition[0] = self->values[4];
            objectEntityList[scriptEng.arrayPosition[0]].XPos = self->XPos;
            objectEntityList[scriptEng.arrayPosition[0]].XPos += self->values[5];
            objectEntityList[scriptEng.arrayPosition[0]].YPos = self->YPos;
            objectEntityList[scriptEng.arrayPosition[0]].YPos += 0xB00000;
            self->values[3]--;
        }
    }
}

void O_R7_Eggman::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->values[2] == 1) {
        if (self->state < 12) {
            PlayerObjectCollision(C_TOUCH, -12, 48, 12, 176);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
        } else {
            if (pXPos() < self->XPos) {
                pXPos() = self->XPos;
                if (GVar("Player.RCollisionFlag") == 1) {
                    CallScriptFunctionNamed("Player_Kill", scriptSub);
                }
            }
            GVar("Player.RCollisionFlag") = 0;
            if (self->state < 14) {
                PlayerObjectCollision(C_TOUCH, -12, 48, 12, 176);
            } else {
                PlayerObjectCollision(C_TOUCH, -64, -256, 16, 176);
            }
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_Kill", scriptSub);
            }
        }
    }
    if (pYPos() < self->YPos) {
        if (pXPos() < 0xE000000) {
            if (pState() == PlayerStateID("Player_State_Fly")) {
                if (pTimer() < 470) {
                    pTimer() = 470;
                }
            }
        }
        if (pXPos() > 0x38900000) {
            if (pState() == PlayerStateID("Player_State_Fly")) {
                if (pTimer() < 470) {
                    pTimer() = 470;
                }
            }
        }
    }
}

void O_R7_Eggman::ObjectDraw()
{
    Entity *self = Self();

    switch (self->animation) {
        case 0:
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] /= 6;
        if (scriptEng.tempValue[0] == 1) {
            DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        }
        if (self->values[2] == 1) {
            scriptEng.tempValue[0] = self->animationTimer;
            scriptEng.tempValue[0] &= 3;
            scriptEng.tempValue[0] >>= 1;
            scriptEng.tempValue[0] += 12;
            scriptEng.tempValue[1] = self->XPos;
            scriptEng.tempValue[2] = self->YPos;
            scriptEng.tempValue[2] += 0x300000;
            DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
            if (self->direction == 0) {
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] += 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] += 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] += 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
            } else {
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] -= 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] -= 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] -= 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
            }
        }
        self->animationTimer++;
        self->animationTimer %= 12;
        break;
        case 1:
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] &= 1;
        if (scriptEng.tempValue[0] == 1) {
            self->frame++;
            self->frame &= 3;
        }
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] += 4;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] += 4;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] /= 6;
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        if (scriptEng.tempValue[0] == 1) {
            DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        }
        if (self->values[2] == 1) {
            scriptEng.tempValue[0] = self->animationTimer;
            scriptEng.tempValue[0] &= 3;
            scriptEng.tempValue[0] >>= 1;
            scriptEng.tempValue[0] += 12;
            scriptEng.tempValue[1] = self->XPos;
            scriptEng.tempValue[2] = self->YPos;
            scriptEng.tempValue[2] += 0x300000;
            DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
            if (self->direction == 0) {
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] += 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] += 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] += 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
            } else {
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] -= 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] -= 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
                scriptEng.tempValue[2] += 0x200000;
                scriptEng.tempValue[1] -= 0x20000;
                DrawSprite_FrameXY(scriptEng.tempValue[0], scriptEng.tempValue[1], scriptEng.tempValue[2]);
            }
        }
        self->animationTimer++;
        self->animationTimer %= 12;
        break;
    }
}

void O_R7_Eggman::R7Eggman_FollowGround()
{
    Entity *self = Self();

    self->YPos -= 0x200000;
    ObjectTileGrip_Script(0, 6, 176, 0);
    if (CheckResult() == 0) {
        self->YPos += 0x100000;
        ObjectTileGrip_Script(0, 6, 176, 0);
        if (CheckResult() == 0) {
            self->YPos += 0x100000;
            ObjectTileGrip_Script(0, 6, 176, 0);
            if (CheckResult() == 0) {
                self->YPos += 0x100000;
            }
        }
    }
}

const Native::NativeFunctionDef O_R7_Eggman::funcs[1] = {
    { "R7Eggman_FollowGround", O_R7_Eggman::R7Eggman_FollowGround },
};

#endif // RETRO_USE_NATIVE_OBJECTS
