#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_BoundaryAdjust.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BoundaryAdjust.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_BoundaryAdjust::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (pXPos() > self->XPos) {
            scriptEng.tempValue[0] = 3120;
            scriptEng.tempValue[0] -= SCREEN_CENTERX;
            newXBoundary1 = scriptEng.tempValue[0];
            scriptEng.tempValue[0] += SCREEN_XSIZE;
            newXBoundary2 = scriptEng.tempValue[0];
            scriptEng.tempValue[0] = (objectEntityList[objectLoop].YPos >> 16);
            scriptEng.tempValue[0] -= SCREEN_YSIZE;
            newYBoundary1 = scriptEng.tempValue[0];
            yBoundary2 = yScrollOffset;
            yBoundary2 += SCREEN_YSIZE;
            if (yBoundary2 < (objectEntityList[objectLoop].YPos >> 16)) {
                yBoundary2 = (objectEntityList[objectLoop].YPos >> 16);
            }
            self->state++;
        }
    } else {
        yBoundary2 -= 3;
        if (yBoundary2 <= (objectEntityList[objectLoop].YPos >> 16)) {
            yBoundary2 = (objectEntityList[objectLoop].YPos >> 16);
            self->type = TypeNameID("Blank Object");
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
