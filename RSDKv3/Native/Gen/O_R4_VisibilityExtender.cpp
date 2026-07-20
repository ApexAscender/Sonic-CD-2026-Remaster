#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_VisibilityExtender.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VisibilityExtender.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_VisibilityExtender::ObjectMain()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = objectLoop;
    scriptEng.arrayPosition[0] -= self->propertyValue;
    objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
}

#endif // RETRO_USE_NATIVE_OBJECTS
