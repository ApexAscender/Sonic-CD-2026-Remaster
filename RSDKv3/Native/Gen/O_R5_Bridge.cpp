#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_Bridge.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Bridge.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_Bridge::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    switch (objectEntityList[24].propertyValue) {
        case 0:
        AddSpriteFrame(-8, -8, 16, 16, 35, 1);
        break;
        case 1:
        AddSpriteFrame(-8, -8, 16, 16, 67, 174);
        break;
        case 2:
        AddSpriteFrame(-8, -8, 16, 16, 83, 174);
        break;
        case 3:
        AddSpriteFrame(-8, -8, 16, 16, 83, 158);
        break;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Bridge")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[6] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[6] <<= 19;
            objectEntityList[scriptEng.arrayPosition[0]].values[7] = objectEntityList[scriptEng.arrayPosition[0]].values[6];
            objectEntityList[scriptEng.arrayPosition[0]].values[6] = -objectEntityList[scriptEng.arrayPosition[0]].values[6];
            objectEntityList[scriptEng.arrayPosition[0]].values[6] += objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[7] += objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = -1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R5_Bridge::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pXPos() > self->values[6]) {
        if (pXPos() < self->values[7]) {
            if (activePlayer == self->values[5]) {
                self->values[2] = pXPos();
                self->values[2] -= self->values[6];
                scriptEng.tempValue[0] = self->values[2];
                scriptEng.tempValue[0] >>= 8;
                scriptEng.tempValue[1] = self->values[7];
                scriptEng.tempValue[1] -= self->values[6];
                scriptEng.tempValue[2] = scriptEng.tempValue[1];
                scriptEng.tempValue[2] >>= 16;
                scriptEng.tempValue[0] /= scriptEng.tempValue[2];
                self->values[3] = Sin512(scriptEng.tempValue[0]);
                scriptEng.tempValue[1] >>= 13;
                self->values[3] *= scriptEng.tempValue[1];
                scriptEng.tempValue[0] = self->YPos;
                scriptEng.tempValue[0] -= 0x300000;
                if (pYPos() > scriptEng.tempValue[0]) {
                    if (pYVel() >= 0) {
                        scriptEng.tempValue[2] = pCollisionBottom();
                        scriptEng.tempValue[2] = -scriptEng.tempValue[2];
                        scriptEng.tempValue[2] <<= 16;
                        scriptEng.tempValue[2] += self->values[4];
                        scriptEng.tempValue[2] -= 0x80000;
                        self->values[0]++;
                        pYPos() = self->YPos;
                        pYPos() += scriptEng.tempValue[2];
                        pGravity() = 0;
                        pYVel() = 0;
                        Plr()->flailing[0] = 1;
                        Plr()->flailing[2] = 1;
                        Plr()->flailing[1] = 1;
                    }
                }
            } else {
                if (pYVel() >= 0) {
                    scriptEng.tempValue[0] = pXPos();
                    scriptEng.tempValue[0] -= self->values[6];
                    if (scriptEng.tempValue[0] > self->values[2]) {
                        scriptEng.tempValue[0] = self->values[7];
                        scriptEng.tempValue[0] -= pXPos();
                        scriptEng.tempValue[3] = self->values[7];
                        scriptEng.tempValue[3] -= self->values[6];
                        scriptEng.tempValue[3] -= self->values[2];
                        scriptEng.tempValue[1] = scriptEng.tempValue[0];
                        scriptEng.tempValue[1] <<= 7;
                        scriptEng.tempValue[1] /= scriptEng.tempValue[3];
                    } else {
                        scriptEng.tempValue[1] = scriptEng.tempValue[0];
                        scriptEng.tempValue[1] <<= 7;
                        scriptEng.tempValue[1] /= self->values[2];
                    }
                    scriptEng.tempValue[2] = Sin512(scriptEng.tempValue[1]);
                    scriptEng.tempValue[2] *= self->values[4];
                    scriptEng.tempValue[2] >>= 9;
                    scriptEng.tempValue[2] -= 0x80000;
                    if (pYVel() < 0x8000) {
                        scriptEng.tempValue[3] = scriptEng.tempValue[2];
                        scriptEng.tempValue[3] >>= 16;
                        scriptEng.tempValue[4] = scriptEng.tempValue[3];
                        scriptEng.tempValue[3] -= 8;
                    } else {
                        scriptEng.tempValue[3] = scriptEng.tempValue[2];
                        scriptEng.tempValue[3] >>= 16;
                        scriptEng.tempValue[4] = scriptEng.tempValue[3];
                        scriptEng.tempValue[4] += 8;
                    }
                    PlayerObjectCollision(C_TOUCH, -1024, scriptEng.tempValue[3], 1024, scriptEng.tempValue[4]);
                    if (CheckResult() == 1) {
                        self->values[0]++;
                        pYPos() = pCollisionBottom();
                        pYPos() = -pYPos();
                        pYPos() <<= 16;
                        pYPos() += self->YPos;
                        pYPos() += scriptEng.tempValue[2];
                        Plr()->flailing[0] = 1;
                        Plr()->flailing[2] = 1;
                        Plr()->flailing[1] = 1;
                        if (pYVel() < 256) {
                            self->values[1] = 128;
                        }
                        pGravity() = 0;
                        pYVel() = 0;
                        if (activePlayer == 0) {
                            self->values[5] = 0;
                        }
                    }
                }
            }
        }
    }
}

void O_R5_Bridge::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = self->values[6];
    scriptEng.tempValue[1] += 0x80000;
    scriptEng.tempValue[4] = 0x80000;
    scriptEng.tempValue[5] = self->values[2];
    scriptEng.tempValue[5] >>= 20;
    while (scriptEng.tempValue[0] < scriptEng.tempValue[5]) {
        scriptEng.tempValue[3] = scriptEng.tempValue[4];
        scriptEng.tempValue[3] <<= 7;
        scriptEng.tempValue[3] /= self->values[2];
        scriptEng.tempValue[2] = Sin512(scriptEng.tempValue[3]);
        scriptEng.tempValue[2] *= self->values[4];
        scriptEng.tempValue[2] >>= 9;
        scriptEng.tempValue[2] += self->YPos;
        DrawSprite_FrameXY(0, scriptEng.tempValue[1], scriptEng.tempValue[2]);
        scriptEng.tempValue[1] += 0x100000;
        scriptEng.tempValue[4] += 0x100000;
        scriptEng.tempValue[0]++;
    }
    scriptEng.tempValue[2] = self->values[4];
    scriptEng.tempValue[2] += self->YPos;
    DrawSprite_FrameXY(0, scriptEng.tempValue[1], scriptEng.tempValue[2]);
    scriptEng.tempValue[1] += 0x100000;
    scriptEng.tempValue[0]++;
    scriptEng.tempValue[5] = self->values[7];
    scriptEng.tempValue[5] -= self->values[6];
    scriptEng.tempValue[5] -= self->values[2];
    scriptEng.tempValue[1] = self->values[7];
    scriptEng.tempValue[1] -= 0x80000;
    scriptEng.tempValue[4] = 0x80000;
    while (scriptEng.tempValue[0] < self->propertyValue) {
        scriptEng.tempValue[3] = scriptEng.tempValue[4];
        scriptEng.tempValue[3] <<= 7;
        scriptEng.tempValue[3] /= scriptEng.tempValue[5];
        scriptEng.tempValue[2] = Sin512(scriptEng.tempValue[3]);
        scriptEng.tempValue[2] *= self->values[4];
        scriptEng.tempValue[2] >>= 9;
        scriptEng.tempValue[2] += self->YPos;
        DrawSprite_FrameXY(0, scriptEng.tempValue[1], scriptEng.tempValue[2]);
        scriptEng.tempValue[1] -= 0x100000;
        scriptEng.tempValue[4] += 0x100000;
        scriptEng.tempValue[0]++;
    }
    if (self->values[0] > 0) {
        if (self->values[1] < 128) {
            self->values[1] += 8;
        }
    } else {
        if (self->values[1] > 0) {
            self->values[1] -= 8;
            self->values[5] = -1;
        } else {
            self->values[3] = 0;
        }
    }
    self->values[4] = self->values[3];
    self->values[4] *= self->values[1];
    self->values[4] >>= 7;
    self->values[0] = 0;
}

#endif // RETRO_USE_NATIVE_OBJECTS
