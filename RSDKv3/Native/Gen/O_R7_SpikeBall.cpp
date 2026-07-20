#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_SpikeBall.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpikeBall.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_SpikeBall::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 1, 199);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Spike Ball")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 1) {
                objectEntityList[scriptEng.arrayPosition[0]].state = 4;
                switch (objectEntityList[24].propertyValue) {
                    case 0:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x20000;
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = 16;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = -16;
                    objectEntityList[scriptEng.arrayPosition[0]].values[6] = 40;
                    break;
                    case 1:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x40000;
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = 8;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = -8;
                    objectEntityList[scriptEng.arrayPosition[0]].values[6] = 60;
                    break;
                    case 2:
                    case 3:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = 32;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = -32;
                    objectEntityList[scriptEng.arrayPosition[0]].values[6] = 20;
                    break;
                }
            } else {
                switch (objectEntityList[24].propertyValue) {
                    case 0:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x20000;
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = 24;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = -24;
                    objectEntityList[scriptEng.arrayPosition[0]].values[6] = 40;
                    break;
                    case 1:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x40000;
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = 12;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = -12;
                    objectEntityList[scriptEng.arrayPosition[0]].values[6] = 60;
                    break;
                    case 2:
                    case 3:
                    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x10000;
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = 48;
                    objectEntityList[scriptEng.arrayPosition[0]].values[5] = -48;
                    objectEntityList[scriptEng.arrayPosition[0]].values[6] = 20;
                    break;
                }
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_SpikeBall::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[1] < self->values[4]) {
            self->values[1]++;
            self->XPos += self->values[2];
        } else {
            self->state++;
        }
        break;
        case 1:
        if (self->values[0] < self->values[6]) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[1] > self->values[5]) {
            self->values[1]--;
            self->XPos -= self->values[2];
        } else {
            self->state++;
        }
        break;
        case 3:
        if (self->values[0] < self->values[6]) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 0;
        }
        break;
        case 4:
        if (self->values[1] < self->values[4]) {
            self->values[1]++;
            self->YPos += self->values[2];
        } else {
            self->state++;
        }
        break;
        case 5:
        if (self->values[0] < self->values[6]) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 6:
        if (self->values[1] > self->values[5]) {
            self->values[1]--;
            self->YPos -= self->values[2];
        } else {
            self->state++;
        }
        break;
        case 7:
        if (self->values[0] < self->values[6]) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 4;
        }
        break;
    }
}

void O_R7_SpikeBall::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R7_SpikeBall::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
