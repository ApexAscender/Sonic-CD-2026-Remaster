#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_FPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_FPlatform::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-32, -16, 64, 32, 101, 109);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Fall Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_FPlatform::ObjectMain()
{
    Entity *self = Self();

    if (self->values[0] == 1) {
        if (self->state == 0) {
            self->state = 1;
        }
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
    self->values[0] = 0;
    if (self->propertyValue == 0) {
        switch (self->state) {
            case 1:
            if (self->values[3] < 30) {
                self->values[3]++;
            } else {
                self->values[4] = 0;
                self->values[3] = 0;
                self->state = 2;
                self->priority = 1;
            }
            break;
            case 2:
            if (self->values[4] < 0x40000) {
                self->values[4] += 0x2000;
            }
            self->values[2] += self->values[4];
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->YPos = self->values[5];
                self->state = 3;
                self->values[4] = 0;
            }
            break;
            case 3:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
            }
            break;
        }
    }
}

void O_R1_FPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 3) {
        PlayerObjectCollision(C_PLATFORM, -32, -9, 32, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pYPos() += self->values[2];
        }
    }
}

void O_R1_FPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    if (self->state < 3) {
        DrawSprite_Frame(0);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
