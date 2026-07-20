#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_RingReset.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RingReset.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_RingReset::ObjectStartup()
{
    GVar("game.missionFunctionNo") = 10;
    scriptEng.tempValue[0] = TypeNameID("Ring Reset");
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Ring")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = scriptEng.tempValue[0];
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Mission_RingReset::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        scriptEng.tempValue[0] = stageMinutes;
        scriptEng.tempValue[0] *= 60;
        scriptEng.tempValue[0] += stageSeconds;
        if (scriptEng.tempValue[0] >= self->values[0]) {
            self->type = TypeNameID("Ring");
            self->priority = 0;
            self->values[0] = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
