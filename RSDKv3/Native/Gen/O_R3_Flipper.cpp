#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_Flipper.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Flipper.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_Flipper::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-32, -12, 64, 32, 100, 167);
    AddSpriteFrame(-32, -12, 64, 24, 67, 200);
    AddSpriteFrame(-32, -20, 64, 32, 132, 200);
    AddSpriteFrame(-32, -12, 64, 24, 67, 200);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Flipper")) {
            objectEntityList[scriptEng.arrayPosition[0]].direction = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_Flipper::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        self->frame = self->values[0];
        self->frame >>= 1;
        self->values[0]++;
        if (self->values[0] > 3) {
            self->values[0] = 6;
            self->state = 2;
        }
        break;
        case 2:
        self->frame = self->values[0];
        self->frame /= 3;
        self->values[0]++;
        if (self->values[0] > 12) {
            self->values[0] = 0;
            self->frame = 0;
            self->state = 0;
        }
        break;
    }
}

void O_R3_Flipper::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    if (self->direction == 0) {
        if (pYPos() > self->YPos) {
            if (pYVel() < 0) {
                PlayerObjectCollision(C_BOX, -32, -12, 28, 12);
            }
        }
        PlayerObjectCollision(C_PLATFORM, 20, -16, 32, 16);
        scriptEng.tempValue[0] = CheckResult();
        scriptEng.tempValue[1] = pXPos();
        scriptEng.tempValue[1] -= self->XPos;
        scriptEng.tempValue[1] >>= 16;
        scriptEng.tempValue[1] += 32;
        scriptEng.tempValue[1] += pCollisionRight();
        if (scriptEng.tempValue[1] >= 0) {
            if (scriptEng.tempValue[1] < 54) {
                scriptEng.tempValue[2] = scriptEng.tempValue[1];
                scriptEng.tempValue[2] /= -2;
                scriptEng.tempValue[2] += 10;
                PlayerObjectCollision(C_PLATFORM, -32, scriptEng.tempValue[2], 32, 16);
                scriptEng.tempValue[0] |= CheckResult();
            }
        }
        if (scriptEng.tempValue[0] == 1) {
            pCollisionMode() = 0;
            pYPos() += 0x40000;
            pXPos() -= 0x10000;
            if (pSpeed() < 0x4000) {
                if (pSpeed() > -0x4000) {
                    pSpeed() = -0x4000;
                }
            }
        } else {
            PlayerObjectCollision(C_TOUCH, -32, -24, 32, 16);
            if (CheckResult() == 1) {
                if (pYVel() < -0x40000) {
                    if (pJumpPress() == 1) {
                        pSpeed() = pXPos();
                        pSpeed() -= self->XPos;
                        pSpeed() >>= 2;
                        pYVel() = -0xE0000;
                        scriptEng.tempValue[2] = pSpeed();
                        scriptEng.tempValue[2] >>= 2;
                        if (scriptEng.tempValue[2] < 0) {
                            pYVel() += scriptEng.tempValue[2];
                        } else {
                            pYVel() -= scriptEng.tempValue[2];
                        }
                        self->state = 1;
                        StopSfx(0);
                        PlaySfx(globalSFXCount + 7, 0);
                        HapticEffect_Script(88, 0, 0, 0);
                    }
                }
            }
        }
    } else {
        if (pYPos() > self->YPos) {
            if (pYVel() < 0) {
                PlayerObjectCollision(C_BOX, -28, -12, 32, 12);
            }
        }
        PlayerObjectCollision(C_PLATFORM, -32, -16, -20, 16);
        scriptEng.tempValue[0] = CheckResult();
        scriptEng.tempValue[1] = pXPos();
        scriptEng.tempValue[1] -= self->XPos;
        scriptEng.tempValue[1] >>= 16;
        scriptEng.tempValue[1] += 32;
        scriptEng.tempValue[1] += pCollisionLeft();
        if (scriptEng.tempValue[1] >= 12) {
            if (scriptEng.tempValue[1] < 64) {
                scriptEng.tempValue[2] = scriptEng.tempValue[1];
                scriptEng.tempValue[2] /= 2;
                scriptEng.tempValue[2] -= 21;
                PlayerObjectCollision(C_PLATFORM, -32, scriptEng.tempValue[2], 32, 16);
                scriptEng.tempValue[0] |= CheckResult();
            }
        }
        if (scriptEng.tempValue[0] == 1) {
            pCollisionMode() = 0;
            pYPos() += 0x40000;
            pXPos() += 0x10000;
            if (pSpeed() > -0x4000) {
                if (pSpeed() < 0x4000) {
                    pSpeed() = 0x4000;
                }
            }
        } else {
            PlayerObjectCollision(C_TOUCH, -32, -24, 32, 16);
            if (CheckResult() == 1) {
                if (pYVel() < -0x40000) {
                    if (pJumpPress() == 1) {
                        pSpeed() = pXPos();
                        pSpeed() -= self->XPos;
                        pSpeed() >>= 2;
                        pYVel() = -0xE0000;
                        scriptEng.tempValue[2] = pSpeed();
                        scriptEng.tempValue[2] >>= 2;
                        if (scriptEng.tempValue[2] < 0) {
                            pYVel() += scriptEng.tempValue[2];
                        } else {
                            pYVel() -= scriptEng.tempValue[2];
                        }
                        self->state = 1;
                        StopSfx(0);
                        PlaySfx(globalSFXCount + 7, 0);
                    }
                }
            }
        }
    }
}

void O_R3_Flipper::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
