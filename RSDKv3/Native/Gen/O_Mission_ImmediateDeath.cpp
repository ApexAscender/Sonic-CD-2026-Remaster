#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_ImmediateDeath.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ImmediateDeath.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_ImmediateDeath::ObjectStartup()
{
    GVar("game.missionFunctionNo") = 8;
    GVar("game.missionValue") = 0;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("ImmediateDeath")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 5;
        }
        scriptEng.arrayPosition[0]++;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
