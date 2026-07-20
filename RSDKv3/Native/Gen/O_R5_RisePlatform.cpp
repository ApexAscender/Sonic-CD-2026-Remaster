#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_RisePlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RisePlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_RisePlatform::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 1, 51);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Rise Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].priority = 3;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R5_RisePlatform::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[2] = 0;
        if (self->values[0] == 1) {
            self->state = 1;
            self->priority = 1;
            self->values[3] = 0;
            self->values[5] = 0;
        }
        break;
        case 1:
        self->values[2] = self->values[3];
        if (self->values[5] < 8) {
            self->values[5]++;
        } else {
            self->values[5] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[3] > -0x50000) {
            self->values[3] -= 0x1000;
        } else {
            self->state++;
        }
        self->values[2] = self->values[3];
        break;
        case 3:
        if (self->values[5] < 80) {
            self->values[5]++;
        } else {
            self->values[5] = 0;
            self->state++;
        }
        self->values[2] = self->values[3];
        break;
        case 4:
        if (self->values[3] < 0) {
            self->values[3] += 0x1000;
        } else {
            self->state++;
        }
        self->values[2] = self->values[3];
        break;
        case 5:
        if (self->values[0] == 1) {
            if (self->values[1] < 16) {
                self->values[1]++;
                scriptEng.tempValue[0] = self->values[1];
                scriptEng.tempValue[0] &= 3;
                if (scriptEng.tempValue[0] == 3) {
                    self->values[2] = 0x10000;
                } else {
                    self->values[2] = 0;
                }
            } else {
                self->values[2] = 0;
            }
        } else {
            if (self->values[1] > 0) {
                self->values[1]--;
                scriptEng.tempValue[0] = self->values[1];
                scriptEng.tempValue[0] &= 3;
                if (scriptEng.tempValue[0] == 3) {
                    self->values[2] = -0x10000;
                } else {
                    self->values[2] = 0;
                }
            } else {
                self->values[2] = 0;
            }
        }
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        scriptEng.tempValue[0] = self->YPos;
        self->YPos = self->values[4];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->values[1] = 0;
            self->state = 0;
        } else {
            self->YPos = scriptEng.tempValue[0];
        }
    }
    self->values[0] = 0;
}

void O_R5_RisePlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_PLATFORM, -16, -16, 16, 12);
    if (CheckResult() == 1) {
        self->values[0] = 1;
        pYPos() += self->values[2];
    }
}

void O_R5_RisePlatform::ObjectDraw()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
