#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_PathSwap.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PathSwap.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_PathSwap::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-24, -15, 48, 40, 109, 18);
    AddSpriteFrame(-24, -11, 48, 36, 158, 22);
    AddSpriteFrame(-24, -7, 48, 32, 207, 26);
    AddSpriteFrame(-24, -11, 48, 36, 158, 63);
    AddSpriteFrame(-24, -15, 48, 40, 109, 59);
    AddSpriteFrame(-24, -11, 48, 36, 158, 63);
    AddSpriteFrame(-24, -7, 48, 32, 207, 26);
    AddSpriteFrame(-24, -11, 48, 36, 158, 22);
    GVar("PathSwap_Flag") = 0;
    GVar("PathSwap_Frame") = 0;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Path Swap")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = (objectEntityList[scriptEng.arrayPosition[0]].XPos >> 16);
            objectEntityList[scriptEng.arrayPosition[0]].values[1] >>= 8;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] <<= 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[0]].values[3]++;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = (objectEntityList[scriptEng.arrayPosition[0]].YPos >> 16);
            objectEntityList[scriptEng.arrayPosition[0]].values[2] >>= 8;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] <<= 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
            objectEntityList[scriptEng.arrayPosition[0]].values[4]++;
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = stageLayouts[0].tiles[objectEntityList[scriptEng.arrayPosition[0]].values[1] + 0x100 * objectEntityList[scriptEng.arrayPosition[0]].values[2]];
            objectEntityList[scriptEng.arrayPosition[0]].values[6] = objectEntityList[scriptEng.arrayPosition[0]].values[5];
            objectEntityList[scriptEng.arrayPosition[0]].values[6] += 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R7_PathSwap::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        if (self->values[0] < 39) {
            self->values[0]++;
        } else {
            self->state = 0;
            self->values[0] = 0;
            self->priority = 0;
        }
        GVar("PathSwap_Frame") = self->values[0];
        GVar("PathSwap_Frame") /= 5;
    }
    if (GVar("PathSwap_Flag") == 0) {
        scriptEng.tempValue[0] = self->values[5];
    } else {
        scriptEng.tempValue[0] = self->values[6];
    }
    if (self->propertyValue != 1) {
        stageLayouts[0].tiles[self->values[1] + 0x100 * self->values[2]] = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        stageLayouts[0].tiles[self->values[3] + 0x100 * self->values[2]] = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        stageLayouts[0].tiles[self->values[1] + 0x100 * self->values[4]] = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        stageLayouts[0].tiles[self->values[3] + 0x100 * self->values[4]] = scriptEng.tempValue[0];
    }
}

void O_R7_PathSwap::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue < 2) {
        if (self->state == 0) {
            if (GVar("PathSwap_Frame") == 0) {
                PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
                if (CheckResult() == 1) {
                    if (self->values[7] == 0) {
                        self->state = 1;
                        self->priority = 1;
                        self->values[7] = 1;
                        GVar("PathSwap_Flag")++;
                        GVar("PathSwap_Flag") &= 1;
                        HapticEffect_Script(19, 0, 0, 0);
                    }
                } else {
                    self->values[7] = 0;
                }
            }
        }
    }
}

void O_R7_PathSwap::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue < 2) {
        DrawSprite_Frame(GVar("PathSwap_Frame"));
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
