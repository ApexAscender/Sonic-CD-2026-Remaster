#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Boss_Face.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Boss_Face.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Boss_Face::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-28, -24, 40, 16, 206, 1);
    AddSpriteFrame(-28, -24, 40, 16, 206, 18);
    AddSpriteFrame(-28, -24, 40, 16, 206, 35);
    AddSpriteFrame(-28, -40, 40, 32, 124, 1);
    AddSpriteFrame(-28, -24, 40, 16, 206, 52);
    AddSpriteFrame(-28, -40, 40, 32, 165, 1);
    AddSpriteFrame(-28, -24, 40, 16, 206, 69);
}

void O_R1_Boss_Face::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->animation = -1;
        self->priority = 1;
        self->values[1] = objectLoop;
        self->values[1] += 1;
        self->values[2] = objectLoop;
        self->values[2] += 8;
        self->values[5] = (objectEntityList[objectLoop + 1].XPos >> 16);
        self->values[6] = self->values[5];
        self->values[6] += 320;
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 160;
        scriptEng.tempValue[0] >>= 1;
        self->values[6] += scriptEng.tempValue[0];
        self->values[7] = xBoundary2;
        self->scale = yBoundary2;
        newXBoundary2 = self->values[6];
        self->state = 1;
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[5];
        if (SCREEN_CENTERX > 160) {
            scriptEng.tempValue[0] += 180;
        } else {
            scriptEng.tempValue[0] += 160;
        }
        scriptEng.tempValue[0] <<= 16;
        if (pXPos() > scriptEng.tempValue[0]) {
            scriptEng.tempValue[0] = self->YPos;
            scriptEng.tempValue[0] += 0xC00000;
            if (pYPos() > scriptEng.tempValue[0]) {
                newXBoundary1 = self->values[5];
                yBoundary2 = pYPos();
                yBoundary2 >>= 16;
                yBoundary2 += 160;
                if (yBoundary2 < 256) {
                    yBoundary2 = 256;
                }
                self->state = 6;
            }
        }
        break;
        case 2:
        if (self->rotation > 0) {
            self->rotation--;
        }
        if (objectEntityList[objectLoop + 1].state > 2) {
            if (self->direction > 0) {
                self->direction--;
            } else {
                self->animation = 0;
            }
        }
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
        if (scriptEng.tempValue[0] == 1) {
            if (objectEntityList[scriptEng.arrayPosition[0]].state == 6) {
                self->YPos = objectEntityList[objectLoop + 15].values[0];
                objectEntityList[objectLoop + 1].YPos = objectEntityList[objectLoop + 15].values[1];
                objectEntityList[objectLoop + 2].YPos = objectEntityList[objectLoop + 15].values[2];
                objectEntityList[objectLoop + 3].values[7] = objectEntityList[objectLoop + 15].values[3];
                objectEntityList[objectLoop + 3].YPos = objectEntityList[objectLoop + 15].YPos;
                objectEntityList[objectLoop + 4].values[7] = objectEntityList[objectLoop + 15].values[4];
                objectEntityList[objectLoop + 5].YPos = objectEntityList[objectLoop + 15].values[5];
                objectEntityList[objectLoop + 6].values[7] = objectEntityList[objectLoop + 15].values[6];
                objectEntityList[objectLoop + 7].values[7] = objectEntityList[objectLoop + 15].values[7];
                scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 6) & 1);
                if (scriptEng.tempValue[0] == 0) {
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 6)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 6));
                } else {
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 6)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 6));
                }
            }
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 0));
            if (self->values[0] == 2) {
                self->values[4] = (1) ? (self->values[4] | (1 << 3)) : (self->values[4] & ~(1 << 3));
            }
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 1)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 1));
            self->values[0] += 2;
            R1_EGGMAN_Oscillation();
            if (scriptEng.tempValue[0] < 0) {
                self->values[0] = 6;
            }
            R1_EGGMAN_Oscillation();
            if (scriptEng.tempValue[0] == 6) {
                objectEntityList[objectLoop + 15].values[0] = self->YPos;
                objectEntityList[objectLoop + 15].values[1] = objectEntityList[objectLoop + 1].YPos;
                objectEntityList[objectLoop + 15].values[2] = objectEntityList[objectLoop + 2].YPos;
                objectEntityList[objectLoop + 15].values[3] = objectEntityList[objectLoop + 3].values[7];
                objectEntityList[objectLoop + 15].YPos = objectEntityList[objectLoop + 3].YPos;
                objectEntityList[objectLoop + 15].values[4] = objectEntityList[objectLoop + 4].values[7];
                objectEntityList[objectLoop + 15].values[5] = objectEntityList[objectLoop + 5].YPos;
                objectEntityList[objectLoop + 15].values[6] = objectEntityList[objectLoop + 6].values[7];
                objectEntityList[objectLoop + 15].values[7] = objectEntityList[objectLoop + 7].values[7];
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].state == 5) {
                if (scriptEng.tempValue[0] == 4) {
                    scriptEng.tempValue[1] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 6) & 1);
                    if (scriptEng.tempValue[1] == 0) {
                        objectEntityList[scriptEng.arrayPosition[0]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 6)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 6));
                    } else {
                        objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 6)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 6));
                    }
                }
            }
            objectEntityList[scriptEng.arrayPosition[0]].state = scriptEng.tempValue[0];
            self->values[0]++;
            R1_EGGMAN_Oscillation();
            self->values[0]--;
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = scriptEng.tempValue[0];
        }
        break;
        case 3:
        if (self->rotation < 160) {
            self->rotation++;
            scriptEng.tempValue[0] = self->rotation;
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                scriptEng.tempValue[0] = rand() % 128;
                scriptEng.tempValue[0] -= 64;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[1] = rand() % 64;
                scriptEng.tempValue[1] -= 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                PlaySfx(22, 0);
            }
            if (self->rotation == 94) {
                scriptEng.tempValue[0] = objectLoop;
                scriptEng.tempValue[0]++;
                GVar("Player.Score") += 1000;
                ResetObjectEntity(scriptEng.tempValue[0], TypeNameID("Eggman Jetpack"), 0, self->XPos, self->YPos);
                self->animation = 3;
                HapticEffect_Script(76, 0, 0, 0);
            }
        }
        break;
        case 4:
        break;
        case 5:
        if (self->rotation < 120) {
            masterVolume--;
            yBoundary2 += 4;
            xBoundary2 += 6;
            self->rotation++;
        } else {
            yBoundary2 = self->scale;
            xBoundary2 = self->values[7];
            PlayMusic(0);
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 6:
        if (yBoundary2 > (objectEntityList[objectLoop + 1].YPos >> 16)) {
            yBoundary2 -= 2;
            yBoundary1 += 2;
        } else {
            yBoundary2 = (objectEntityList[objectLoop + 1].YPos >> 16);
            scriptEng.tempValue[0] = (objectEntityList[objectLoop + 1].YPos >> 16);
            scriptEng.tempValue[0] -= SCREEN_YSIZE;
            if (scriptEng.tempValue[0] < 0) {
                scriptEng.tempValue[0] = 0;
            }
            newYBoundary1 = scriptEng.tempValue[0];
            self->rotation = 0;
            self->state = 7;
        }
        break;
        case 7:
        if (self->rotation < 120) {
            if (self->rotation < 100) {
                masterVolume--;
            } else {
                if (self->rotation == 100) {
                    PlayMusic(4);
                }
            }
            self->rotation++;
        } else {
            self->rotation = 0;
            self->state = 2;
            self->animation = 1;
            scriptEng.arrayPosition[0] = objectLoop;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Body"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] += 5;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Leg Joint"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 3;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Leg"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 4;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Foot"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 3;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 1;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Leg Joint"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 6;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Leg"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 5;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 7;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Foot"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 6;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 1;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Shoulder"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 9;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] += 12;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Arm Joint"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 8;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 10;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Arm"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 9;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 11;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Bumper"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 10;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 1;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Arm Joint"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 8;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 13;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Arm"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 12;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 14;
            scriptEng.arrayPosition[0]++;
            ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Boss Bumper"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] += 13;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectLoop;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 1;
            scriptEng.arrayPosition[0]++;
        }
        break;
    }
}

void O_R1_Boss_Face::ObjectPlayerInteraction()
{
    Entity *self = Self();

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
    if (self->state > 1) {
        if (pAnimation() != GVar("ANI_HURT")) {
            if (self->values[3] < 3) {
                PlayerObjectCollision(C_TOUCH, -28, -28, 28, 28);
                if (CheckResult() == 1) {
                    CheckResult() = 0;
                    if (pAnimation() == GVar("ANI_JUMPING")) {
                        CheckResult() = 1;
                    }
                    if (CheckResult() == 1) {
                        pXVel() = pXPos();
                        pXVel() -= self->XPos;
                        pXVel() >>= 3;
                        pSpeed() = pXVel();
                        pYVel() = pYPos();
                        pYVel() -= self->YPos;
                        pYVel() >>= 3;
                        if (self->rotation == 0) {
                            if (objectEntityList[objectLoop + 1].state != 1) {
                                PlaySfx(22, 0);
                                HapticEffect_Script(75, 0, 0, 0);
                                switch (self->values[3]) {
                                    case 0:
                                    self->values[3]++;
                                    self->rotation = 30;
                                    self->animation = 2;
                                    self->direction = 120;
                                    scriptEng.arrayPosition[0] = self->values[2];
                                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
                                    objectEntityList[scriptEng.arrayPosition[1]].state = 5;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0x10000;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[5] = 0x20000;
                                    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0x10000;
                                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[1]].state = 2;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[5] = -0x18000;
                                    break;
                                    case 1:
                                    self->values[3]++;
                                    self->rotation = 30;
                                    self->animation = 2;
                                    self->direction = 120;
                                    scriptEng.arrayPosition[0] = self->values[2];
                                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[1]].state = 5;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0x10000;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[5] = 0x20000;
                                    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0x10000;
                                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[1]].state = 2;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[5] = -0x18000;
                                    break;
                                    case 2:
                                    self->values[3]++;
                                    self->state = 3;
                                    self->animation = 2;
                                    scriptEng.arrayPosition[0] = self->values[1];
                                    objectEntityList[scriptEng.arrayPosition[0]].state = 7;
                                    scriptEng.arrayPosition[0] = self->values[2];
                                    objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = -0x10000;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = -0x20000;
                                    scriptEng.arrayPosition[0] = self->values[1];
                                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[1]].state = 12;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[5] = -0x28000;
                                    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[0]].state = 7;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = -0x20000;
                                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[1]].state = 6;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[5] = -0x23000;
                                    scriptEng.arrayPosition[0] = self->values[1];
                                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
                                    objectEntityList[scriptEng.arrayPosition[1]].state = 12;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[5] = -0x28000;
                                    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[0]].state = 7;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = -0x20000;
                                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                                    objectEntityList[scriptEng.arrayPosition[1]].state = 6;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0;
                                    objectEntityList[scriptEng.arrayPosition[1]].values[5] = -0x23000;
                                    break;
                                }
                            }
                        }
                    } else {
                        if (PlayerValue(4) == 0) {
                            self->animation = 1;
                            self->direction = 180;
                            pState() = PlayerStateID("Player_State_GotHit");
                            if (pXPos() > self->XPos) {
                                pSpeed() = 0x20000;
                            } else {
                                pSpeed() = -0x20000;
                            }
                        }
                    }
                }
            }
        }
    }
}

void O_R1_Boss_Face::ObjectDraw()
{
    Entity *self = Self();

    switch (self->animation) {
        case 0:
        DrawSprite_Frame(0);
        break;
        case 1:
        if (self->inkEffect < 8) {
            self->inkEffect = 8;
        } else {
            if (self->inkEffect > 23) {
                self->inkEffect = 8;
            }
        }
        self->frame = self->inkEffect;
        self->frame >>= 3;
        self->inkEffect++;
        DrawSprite_Frame(self->frame);
        break;
        case 2:
        if (self->inkEffect < 12) {
            self->inkEffect = 12;
        } else {
            if (self->inkEffect > 27) {
                self->inkEffect = 12;
            }
        }
        self->frame = self->inkEffect;
        self->frame >>= 2;
        self->inkEffect++;
        DrawSprite_Frame(self->frame);
        break;
    }
}

void O_R1_Boss_Face::R1_EGGMAN_Oscillation()
{
    Entity *self = Self();

    switch (self->values[0]) {
        case 0:
        scriptEng.tempValue[0] = 1;
        break;
        case 1:
        scriptEng.tempValue[0] = 0;
        break;
        case 2:
        scriptEng.tempValue[0] = 2;
        break;
        case 3:
        scriptEng.tempValue[0] = 0;
        break;
        case 4:
        scriptEng.tempValue[0] = 3;
        break;
        case 5:
        scriptEng.tempValue[0] = 0;
        break;
        case 6:
        scriptEng.tempValue[0] = 4;
        break;
        case 7:
        scriptEng.tempValue[0] = 5;
        break;
        case 8:
        scriptEng.tempValue[0] = 5;
        break;
        case 9:
        scriptEng.tempValue[0] = 6;
        break;
        case 10:
        scriptEng.tempValue[0] = 6;
        break;
        case 11:
        scriptEng.tempValue[0] = 10;
        break;
        case 12:
        scriptEng.tempValue[0] = 4;
        break;
        case 13:
        scriptEng.tempValue[0] = 10;
        break;
        case 14:
        scriptEng.tempValue[0] = 8;
        break;
        case 15:
        scriptEng.tempValue[0] = 50;
        break;
        case 16:
        scriptEng.tempValue[0] = 5;
        break;
        case 17:
        scriptEng.tempValue[0] = 10;
        break;
        case 18:
        case 19:
        scriptEng.tempValue[0] = -1;
        break;
    }
}

const Native::NativeFunctionDef O_R1_Boss_Face::funcs[1] = {
    { "R1_EGGMAN_Oscillation", O_R1_Boss_Face::R1_EGGMAN_Oscillation },
};

#endif // RETRO_USE_NATIVE_OBJECTS
