#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_RPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_RPlatform::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-32, -16, 64, 32, 100, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("R Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R3_RPlatform::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->YPos = self->values[4];
        self->state = 6;
        self->values[1] = 0;
    }
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
        if (self->values[3] > -0x40000) {
            self->values[3] -= 0x1000;
        } else {
            self->state++;
        }
        self->values[2] = self->values[3];
        break;
        case 3:
        if (self->values[5] < 36) {
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
        case 6:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        }
        break;
    }
    self->values[0] = 0;
}

void O_R3_RPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_PLATFORM, -32, -16, 32, 12);
    if (CheckResult() == 1) {
        self->values[0] = 1;
        pYPos() += self->values[2];
    }
}

void O_R3_RPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
