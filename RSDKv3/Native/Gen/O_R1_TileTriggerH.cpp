#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_TileTriggerH.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TileTriggerH.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_TileTriggerH::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Tile Trigger H")) {
            scriptEng.arrayPosition[1] = scriptEng.arrayPosition[0];
            scriptEng.arrayPosition[1]++;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] <<= 3;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = -objectEntityList[scriptEng.arrayPosition[0]].values[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[0] -= 8;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] += 8;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = (objectEntityList[scriptEng.arrayPosition[1]].XPos >> 16);
            objectEntityList[scriptEng.arrayPosition[0]].values[2] >>= 7;
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
            objectEntityList[scriptEng.arrayPosition[0]].values[4]++;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = (objectEntityList[scriptEng.arrayPosition[1]].YPos >> 16);
            objectEntityList[scriptEng.arrayPosition[0]].values[3] >>= 7;
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = objectEntityList[scriptEng.arrayPosition[0]].values[3];
            objectEntityList[scriptEng.arrayPosition[0]].values[5]++;
            objectEntityList[scriptEng.arrayPosition[0]].values[6] = stageLayouts[0].tiles[objectEntityList[scriptEng.arrayPosition[0]].values[2] + 0x100 * objectEntityList[scriptEng.arrayPosition[0]].values[3]];
            objectEntityList[scriptEng.arrayPosition[0]].values[7] = objectEntityList[scriptEng.arrayPosition[0]].values[6];
            objectEntityList[scriptEng.arrayPosition[0]].values[7] += 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_TileTriggerH::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, self->values[0], -12, self->values[1], 12);
    if (CheckResult() == 1) {
        if (objectEntityList[objectLoop + 1].propertyValue == 0) {
            scriptEng.tempValue[0] = self->values[6];
        } else {
            scriptEng.tempValue[0] = self->values[7];
        }
        stageLayouts[0].tiles[self->values[2] + 0x100 * self->values[3]] = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        stageLayouts[0].tiles[self->values[4] + 0x100 * self->values[3]] = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        stageLayouts[0].tiles[self->values[2] + 0x100 * self->values[5]] = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        stageLayouts[0].tiles[self->values[4] + 0x100 * self->values[5]] = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
