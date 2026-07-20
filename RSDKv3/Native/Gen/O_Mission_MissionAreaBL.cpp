#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_MissionAreaBL.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MissionAreaBL.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_MissionAreaBL::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("MissionAreaBL")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Mission_MissionAreaBL::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        newXBoundary1 = self->XPos;
        newXBoundary1 >>= 16;
        newXBoundary1 -= 16;
        newYBoundary2 = self->YPos;
        newYBoundary2 >>= 16;
        self->state = 1;
    }
    if (stageMode == 1) {
        if (pYPos() > self->YPos) {
            CheckResult() = (pState() == PlayerStateID("Player_State_Death"));
            scriptEng.tempValue[0] = CheckResult();
            CheckResult() = (pState() == PlayerStateID("Player_State_Drown"));
            CheckResult() |= scriptEng.tempValue[0];
            if (CheckResult() == 0) {
                pYVel() = 0;
                pSpeed() = 0;
                pYPos() = self->YPos;
                GVar("game.forceKillPlayer") = 1;
            }
            self->priority = 5;
        }
        if (pXPos() < self->XPos) {
            pXVel() = 0;
            pSpeed() = 0;
            pXPos() = self->XPos;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
