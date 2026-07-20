#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_BossWaterTrigger.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossWaterTrigger.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_BossWaterTrigger::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water")) {
            scriptEng.tempValue[0] = scriptEng.arrayPosition[0];
        }
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BossWaterTrigger")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = scriptEng.tempValue[0];
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_BossWaterTrigger::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (pXPos() > self->XPos) {
            if (GVar("Stage.NewWaterLevel") > 0x4940000) {
                GVar("Stage.NewWaterLevel") = 0x4940000;
                scriptEng.arrayPosition[0] = self->values[0];
                objectEntityList[scriptEng.arrayPosition[0]].YPos = yScrollOffset;
                objectEntityList[scriptEng.arrayPosition[0]].YPos += 256;
                objectEntityList[scriptEng.arrayPosition[0]].YPos <<= 16;
                yBoundary2 = 1496;
            }
        } else {
            if (GVar("Stage.NewWaterLevel") < 0xC000000) {
                GVar("Stage.NewWaterLevel") = 0xC000000;
                newYBoundary2 = 2304;
            }
            scriptEng.arrayPosition[0] = self->values[0];
            scriptEng.tempValue[0] = yScrollOffset;
            scriptEng.tempValue[0] += 256;
            scriptEng.tempValue[0] <<= 16;
            if (objectEntityList[scriptEng.arrayPosition[0]].YPos >= scriptEng.tempValue[0]) {
                objectEntityList[scriptEng.arrayPosition[0]].YPos = 0xC000000;
            }
        }
        break;
        case 1:
        if (pXPos() > self->XPos) {
            newYBoundary2 = 1448;
        } else {
            newYBoundary2 = 1496;
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
