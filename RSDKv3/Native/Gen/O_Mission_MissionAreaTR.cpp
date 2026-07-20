#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_MissionAreaTR.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MissionAreaTR.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_MissionAreaTR::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("MissionAreaTR")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Mission_MissionAreaTR::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        newXBoundary2 = self->XPos;
        newXBoundary2 >>= 16;
        newXBoundary2 += 16;
        newYBoundary1 = self->YPos;
        newYBoundary1 >>= 16;
        self->state = 1;
    }
    if (stageMode == 1) {
        if (pYPos() < self->YPos) {
            pYVel() = 0;
            pSpeed() = 0;
            pYPos() = self->YPos;
        }
        if (pXPos() > self->XPos) {
            pXVel() = 0;
            pSpeed() = 0;
            pXPos() = self->XPos;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
