#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_Eggman2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Eggman2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_Eggman2::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects2.gif");
    AddSpriteFrame(-32, -28, 64, 56, 51, 58);
    AddSpriteFrame(-32, -28, 64, 56, 189, 58);
    AddSpriteFrame(-32, -28, 48, 16, 1, 67);
    AddSpriteFrame(-32, -28, 48, 16, 1, 84);
    AddSpriteFrame(-32, -28, 48, 16, 1, 101);
    AddSpriteFrame(-32, -28, 48, 16, 1, 118);
    AddSpriteFrame(-32, -28, 48, 16, 50, 118);
    AddSpriteFrame(4, -44, 16, 16, 207, 35);
    AddSpriteFrame(4, -44, 1, 1, 207, 35);
    AddSpriteFrame(4, -44, 16, 16, 224, 35);
    AddSpriteFrame(4, -44, 1, 1, 207, 35);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Eggman Part 2")) {
            scriptEng.tempValue[0] = 160;
            scriptEng.tempValue[0] -= SCREEN_CENTERX;
            objectEntityList[scriptEng.arrayPosition[0]].XPos = ((objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16) + (scriptEng.tempValue[0])) << 16;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_Eggman2::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        newXBoundary1 = (objectEntityList[objectLoop].XPos >> 16);
        newXBoundary1 -= 96;
        newXBoundary1 -= SCREEN_CENTERX;
        newXBoundary2 = newXBoundary1;
        newXBoundary2 += SCREEN_CENTERX;
        newXBoundary2 += SCREEN_CENTERX;
        PlayerObjectCollision(C_TOUCH, -80, -256, 64, 256);
        if (CheckResult() == 1) {
            self->state = 1;
            objectEntityList[objectLoop + 17].XPos = self->XPos;
            objectEntityList[objectLoop + 17].XPos -= 0x600000;
            objectEntityList[objectLoop + 17].YPos = self->YPos;
            CreateTempObject(TypeNameID("Fade Music"), 0, self->XPos, self->YPos);
        }
        break;
        case 1:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[2] = 0;
            self->state = 2;
        }
        break;
        case 2:
        if (self->values[0] < 320) {
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] %= 20;
            if (scriptEng.tempValue[0] == 0) {
                PlaySfx(globalSFXCount + 7, 0);
            }
            if (self->values[1] > 0) {
                self->values[1]--;
            } else {
                self->values[1] = 10;
                CreateTempObject(TypeNameID("Boss Bubble 1"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].XPos = rand() % 28;
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 14;
                objectEntityList[scriptEng.arrayPosition[2]].XPos <<= 16;
                objectEntityList[scriptEng.arrayPosition[2]].XPos += self->XPos;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectEntityList[scriptEng.arrayPosition[2]].XPos;
                objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x9C0000;
                objectEntityList[scriptEng.arrayPosition[2]].values[4] = rand() % 4;
                objectEntityList[scriptEng.arrayPosition[2]].values[4] += 9;
                objectEntityList[scriptEng.arrayPosition[2]].values[5] = objectLoop;
                if (self->values[2] == 1) {
                    objectEntityList[scriptEng.arrayPosition[2]].values[6] = rand() % 32;
                    objectEntityList[scriptEng.arrayPosition[2]].values[6] -= 16;
                    objectEntityList[scriptEng.arrayPosition[2]].values[6] <<= 16;
                } else {
                    objectEntityList[scriptEng.arrayPosition[2]].values[6] = 0;
                }
                self->values[2]++;
                self->values[2] &= 1;
            }
            self->values[0]++;
        } else {
            self->state = 3;
            self->values[0] = 0;
        }
        break;
        case 3:
        if (self->values[0] < 180) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[5] = 0;
            self->rotation = 256;
            self->values[4] = 16;
            self->values[6] = 32;
            self->values[3] = 0x1000;
            self->state = 4;
            scriptEng.arrayPosition[0] = 1;
            while (scriptEng.arrayPosition[0] < 17) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type = TypeNameID("Boss Bubble 2");
                scriptEng.arrayPosition[0]++;
            }
            EggBubble_HandleBubbleMovement();
        }
        break;
        case 4:
        self->values[5] += 8;
        self->values[5] &= 511;
        if (self->values[3] < 0x3000) {
            self->values[3] += 0x60;
        } else {
            self->state = 5;
        }
        EggBubble_HandleBubbleMovement();
        break;
        case 5:
        self->values[5] += 2;
        self->values[5] &= 511;
        if (self->values[0] < 20) {
            self->values[0]++;
        } else {
            self->state = 6;
            objectEntityList[objectLoop + 17].values[5] = 0;
        }
        EggBubble_HandleBubbleMovement();
        break;
        case 6:
        self->XPos = Cos512(objectEntityList[objectLoop + 17].values[5]);
        self->XPos *= 0x3000;
        self->XPos += objectEntityList[objectLoop + 17].XPos;
        self->YPos = Sin512(objectEntityList[objectLoop + 17].values[5]);
        self->YPos *= 0x2000;
        self->YPos += objectEntityList[objectLoop + 17].YPos;
        if (objectEntityList[objectLoop + 17].values[5] == 12) {
            EggBubble_FireBullet();
        }
        if (objectEntityList[objectLoop + 17].values[5] < 256) {
            objectEntityList[objectLoop + 17].values[5] += 2;
        } else {
            self->state = 7;
        }
        self->values[5] += 2;
        self->values[5] &= 511;
        EggBubble_HandleBubbleMovement();
        break;
        case 7:
        self->values[5] += 8;
        self->values[5] &= 511;
        EggBubble_HandleBubbleTurn();
        if (self->rotation == 128) {
            self->direction = 1;
        }
        if (self->rotation > 0) {
            self->rotation -= 2;
        } else {
            EggBubble_CheckShieldCondition();
            if (CheckResult() == 1) {
                self->state = 10;
                self->values[0] = 0;
            } else {
                self->state = 8;
            }
        }
        break;
        case 8:
        self->XPos = Cos512(objectEntityList[objectLoop + 17].values[5]);
        self->XPos *= 0x3000;
        self->XPos += objectEntityList[objectLoop + 17].XPos;
        self->YPos = Sin512(objectEntityList[objectLoop + 17].values[5]);
        self->YPos *= 0x2000;
        self->YPos += objectEntityList[objectLoop + 17].YPos;
        if (objectEntityList[objectLoop + 17].values[5] == 244) {
            EggBubble_FireBullet();
        }
        if (objectEntityList[objectLoop + 17].values[5] > 0) {
            objectEntityList[objectLoop + 17].values[5] -= 2;
        } else {
            self->state = 9;
        }
        self->values[5] += 2;
        self->values[5] &= 511;
        EggBubble_HandleBubbleMovement();
        break;
        case 9:
        self->values[5] += 8;
        self->values[5] &= 511;
        EggBubble_HandleBubbleTurn();
        if (self->rotation == 128) {
            self->direction = 0;
        }
        if (self->rotation < 256) {
            self->rotation += 2;
        } else {
            EggBubble_CheckShieldCondition();
            if (CheckResult() == 1) {
                self->state = 12;
                self->values[0] = 0;
            } else {
                self->state = 6;
            }
        }
        break;
        case 10:
        self->XPos += 0x10000;
        if (self->values[0] < 20) {
            self->values[0]++;
            self->values[5] += 2;
            self->values[5] &= 511;
            EggBubble_HandleBubbleMovement();
            if (self->values[0] == 20) {
                self->values[7] = 1;
            }
        } else {
            if (self->values[3] > 0xC00) {
                self->values[3] -= 0x100;
            } else {
                self->state = 11;
                EggBubble_CheckBubbleAmount();
                EggBubble_FireBullet();
            }
            self->values[5] += 8;
            self->values[5] &= 511;
            EggBubble_HandleBubbleMovement();
        }
        break;
        case 11:
        self->XPos += 0x10000;
        if (self->values[3] < 0x3000) {
            self->values[3] += 0x60;
            self->values[5] += 8;
        } else {
            self->values[5] += 2;
        }
        scriptEng.tempValue[0] = objectEntityList[objectLoop + 17].XPos;
        scriptEng.tempValue[0] += 0x600000;
        if (self->XPos > scriptEng.tempValue[0]) {
            self->XPos = scriptEng.tempValue[0];
            objectEntityList[objectLoop + 17].values[5] = 0;
            self->state = 9;
        }
        self->values[5] &= 511;
        EggBubble_HandleBubbleMovement();
        break;
        case 12:
        self->XPos -= 0x10000;
        if (self->values[0] < 20) {
            self->values[0]++;
            self->values[5] += 2;
            self->values[5] &= 511;
            EggBubble_HandleBubbleMovement();
            if (self->values[0] == 20) {
                self->values[7] = 1;
            }
        } else {
            if (self->values[3] > 0xC00) {
                self->values[3] -= 0x100;
            } else {
                self->state = 13;
                EggBubble_CheckBubbleAmount();
                EggBubble_FireBullet();
            }
            self->values[5] += 8;
            self->values[5] &= 511;
            EggBubble_HandleBubbleMovement();
        }
        break;
        case 13:
        self->XPos -= 0x10000;
        if (self->values[3] < 0x3000) {
            self->values[3] += 0x60;
            self->values[5] += 8;
        } else {
            self->values[5] += 2;
        }
        scriptEng.tempValue[0] = objectEntityList[objectLoop + 17].XPos;
        scriptEng.tempValue[0] -= 0x600000;
        if (self->XPos < scriptEng.tempValue[0]) {
            self->XPos = scriptEng.tempValue[0];
            objectEntityList[objectLoop + 17].values[5] = 256;
            self->state = 7;
        }
        self->values[5] &= 511;
        EggBubble_HandleBubbleMovement();
        break;
        case 14:
        if (self->values[0] < 70) {
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 0) {
                scriptEng.tempValue[0] = rand() % 80;
                scriptEng.tempValue[0] -= 40;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[1] = rand() % 56;
                scriptEng.tempValue[1] -= 28;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                PlaySfx(22, 0);
            }
            self->values[0]++;
        } else {
            self->state = 15;
            self->values[7] = 3;
            self->values[0] = 0;
            self->direction = 1;
            EggBubble_DestroyBubbles();
            GVar("Player.Score") += 1000;
        }
        break;
        case 15:
        if (self->values[0] < 70) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->priority = 1;
            self->state = 16;
            self->values[7] = 4;
            self->frame = 0;
            GVar("Stage.NewWaterLevel") = 0x8000000;
            CreateTempObject(TypeNameID("Fade Music"), 1, self->XPos, self->YPos);
        }
        break;
        case 16:
        self->XPos += 0x1C000;
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 17;
            self->values[7] = 5;
        }
        break;
        case 17:
        if (self->values[0] < 60) {
            xBoundary2 += 4;
            self->values[0]++;
        } else {
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            newXBoundary2 = 3840;
        }
        break;
    }
}

void O_R4_Eggman2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state > 4) {
        if (self->state < 14) {
            PlayerObjectCollision(C_TOUCH, -24, -16, 24, 16);
            if (CheckResult() == 1) {
                CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
                scriptEng.tempValue[0] = CheckResult();
                CheckResult() = (pAnimation() == GVar("ANI_SPINDASH"));
                scriptEng.tempValue[0] |= CheckResult();
                scriptEng.arrayPosition[0] = Plr()->entityNo;
                scriptEng.arrayPosition[0] += 2;
                if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Invincibility")) {
                    scriptEng.tempValue[0] = 1;
                }
                if (scriptEng.tempValue[0] == 1) {
                    pXVel() = -pXVel();
                    pSpeed() = -pSpeed();
                    pXVel() >>= 1;
                    pSpeed() >>= 1;
                    pYVel() = pYPos();
                    pYVel() -= self->YPos;
                    pYVel() >>= 3;
                    self->state = 14;
                    self->values[7] = 2;
                    self->values[0] = 0;
                } else {
                    if (PlayerValue(4) == 0) {
                        pState() = PlayerStateID("Player_State_GotHit");
                        if (pXPos() > self->XPos) {
                            pSpeed() = 0x20000;
                        } else {
                            pSpeed() = -0x20000;
                        }
                    }
                    self->values[7] = 1;
                }
            }
        }
    }
    if (self->state < 17) {
        scriptEng.tempValue[0] = pCollisionRight();
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += pXPos();
        scriptEng.tempValue[1] = xBoundary2;
        scriptEng.tempValue[1] <<= 16;
        if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
            pXVel() = 0;
            pSpeed() = 0;
            pXPos() = scriptEng.tempValue[1];
            scriptEng.tempValue[0] = pCollisionRight();
            scriptEng.tempValue[0] <<= 16;
            pXPos() -= scriptEng.tempValue[0];
        }
    }
}

void O_R4_Eggman2::ObjectDraw()
{
    Entity *self = Self();

    switch (self->values[7]) {
        case 0:
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        break;
        case 1:
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] &= 15;
        scriptEng.tempValue[0] >>= 3;
        scriptEng.tempValue[0] += 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        if (self->frame < 112) {
            self->frame++;
        } else {
            self->frame = 0;
            self->values[7] = 0;
        }
        break;
        case 2:
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(5, FX_FLIP, self->XPos, self->YPos);
        break;
        case 3:
        DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(6, FX_FLIP, self->XPos, self->YPos);
        break;
        case 4:
        DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(6, FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 2;
        scriptEng.tempValue[0] += 7;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        self->frame++;
        self->frame &= 15;
        break;
    }
}

void O_R4_Eggman2::EggBubble_HandleBubbleMovement()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 1;
    scriptEng.tempValue[0] = self->values[5];
    while (scriptEng.arrayPosition[0] <= self->values[4]) {
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].state < 3) {
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].drawOrder = 3;
            scriptEng.tempValue[1] = Cos512(scriptEng.tempValue[0]);
            scriptEng.tempValue[1] *= self->values[3];
            scriptEng.tempValue[1] >>= 1;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].XPos = Cos512(self->rotation);
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].XPos *= scriptEng.tempValue[1];
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].XPos >>= 9;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].XPos += self->XPos;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos = Sin512(scriptEng.tempValue[0]);
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos *= self->values[3];
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos >>= 1;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos += self->YPos;
        }
        scriptEng.tempValue[0] += self->values[6];
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_Eggman2::EggBubble_HandleBubbleTurn()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 1;
    scriptEng.tempValue[0] = self->values[5];
    while (scriptEng.arrayPosition[0] <= self->values[4]) {
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].state < 3) {
            if (scriptEng.tempValue[0] < 128) {
                objectEntityList[objectLoop + scriptEng.arrayPosition[0]].drawOrder = 3;
            } else {
                if (scriptEng.tempValue[0] > 383) {
                    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].drawOrder = 3;
                } else {
                    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].drawOrder = 2;
                }
            }
            scriptEng.tempValue[1] = Cos512(scriptEng.tempValue[0]);
            scriptEng.tempValue[1] *= self->values[3];
            scriptEng.tempValue[1] >>= 1;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].XPos = Cos512(self->rotation);
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].XPos *= scriptEng.tempValue[1];
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].XPos >>= 9;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].XPos += self->XPos;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos = Sin512(scriptEng.tempValue[0]);
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos *= self->values[3];
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos >>= 1;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos += self->YPos;
        }
        scriptEng.tempValue[0] += self->values[6];
        scriptEng.tempValue[0] &= 511;
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_Eggman2::EggBubble_CheckShieldCondition()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 1;
    scriptEng.tempValue[0] = 0;
    while (scriptEng.arrayPosition[0] <= self->values[4]) {
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type == TypeNameID("Boss Bubble 2")) {
            scriptEng.tempValue[0]++;
        }
        scriptEng.arrayPosition[0]++;
    }
    CheckResult() = 0;
    switch (scriptEng.tempValue[0]) {
        case 3:
        if (self->values[4] > 4) {
            CheckResult() = 1;
        }
        break;
        case 4:
        case 5:
        case 6:
        case 7:
        if (scriptEng.tempValue[0] < self->values[4]) {
            CheckResult() = 1;
        }
        break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        scriptEng.tempValue[1] = self->values[4];
        scriptEng.tempValue[1] -= scriptEng.tempValue[0];
        if (scriptEng.tempValue[1] > 1) {
            CheckResult() = 1;
        }
        break;
    }
}

void O_R4_Eggman2::EggBubble_CheckBubbleAmount()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 1;
    scriptEng.tempValue[0] = 0;
    while (scriptEng.arrayPosition[0] <= self->values[4]) {
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type == TypeNameID("Boss Bubble 2")) {
            scriptEng.tempValue[0]++;
        }
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.arrayPosition[0] = 1;
    while (scriptEng.arrayPosition[0] <= self->values[4]) {
        if (scriptEng.arrayPosition[0] <= scriptEng.tempValue[0]) {
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type = TypeNameID("Boss Bubble 2");
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].state = 2;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[0] = 0;
        } else {
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
        }
        scriptEng.arrayPosition[0]++;
    }
    self->values[4] = scriptEng.tempValue[0];
    self->values[6] = 512;
    self->values[6] /= self->values[4];
}

void O_R4_Eggman2::EggBubble_DestroyBubbles()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = 1;
    while (scriptEng.arrayPosition[0] <= self->values[4]) {
        if (objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type == TypeNameID("Boss Bubble 2")) {
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].state = 3;
            objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[0] = 0;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_Eggman2::EggBubble_FireBullet()
{
    Entity *self = Self();

    if (self->direction == 0) {
        CreateTempObject(TypeNameID("Boss Bullet"), 0, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].values[5] = objectLoop;
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 2;
        CreateTempObject(TypeNameID("Boss Bullet"), 1, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].values[5] = objectLoop;
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 2;
        CreateTempObject(TypeNameID("Boss Bullet"), 2, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].values[5] = objectLoop;
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 2;
        CreateTempObject(TypeNameID("Boss Bullet"), 3, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].values[5] = objectLoop;
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 2;
    } else {
        CreateTempObject(TypeNameID("Boss Bullet"), 4, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].values[5] = objectLoop;
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 2;
        CreateTempObject(TypeNameID("Boss Bullet"), 5, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].values[5] = objectLoop;
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 2;
        CreateTempObject(TypeNameID("Boss Bullet"), 6, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].values[5] = objectLoop;
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 2;
        CreateTempObject(TypeNameID("Boss Bullet"), 7, self->XPos, self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].values[5] = objectLoop;
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 2;
    }
}

const Native::NativeFunctionDef O_R4_Eggman2::funcs[6] = {
    { "EggBubble_HandleBubbleMovement", O_R4_Eggman2::EggBubble_HandleBubbleMovement },
    { "EggBubble_HandleBubbleTurn", O_R4_Eggman2::EggBubble_HandleBubbleTurn },
    { "EggBubble_CheckShieldCondition", O_R4_Eggman2::EggBubble_CheckShieldCondition },
    { "EggBubble_CheckBubbleAmount", O_R4_Eggman2::EggBubble_CheckBubbleAmount },
    { "EggBubble_DestroyBubbles", O_R4_Eggman2::EggBubble_DestroyBubbles },
    { "EggBubble_FireBullet", O_R4_Eggman2::EggBubble_FireBullet },
};

#endif // RETRO_USE_NATIVE_OBJECTS
