#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_BoundaryAdjust.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BoundaryAdjust.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_BoundaryAdjust::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (pXPos() > self->XPos) {
            newYBoundary2 = 520;
        } else {
            newYBoundary2 = 768;
        }
    } else {
        if (pXPos() < self->XPos) {
            newYBoundary2 = 520;
        } else {
            newYBoundary2 = 768;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
