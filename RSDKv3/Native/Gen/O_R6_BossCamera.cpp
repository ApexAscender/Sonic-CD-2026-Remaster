#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BossCamera.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossCamera.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BossCamera::ObjectMain()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    scriptEng.tempValue[0] -= pYPos();
    scriptEng.tempValue[0] >>= 25;
    if (scriptEng.tempValue[0] != self->values[0]) {
        if (self->values[0] < scriptEng.tempValue[0]) {
            newYBoundary2 = scriptEng.tempValue[0];
            newYBoundary2 *= -512;
            newYBoundary2 += (objectEntityList[objectLoop].YPos >> 16);
            self->values[1] = newYBoundary2;
        } else {
            yBoundary2 = scriptEng.tempValue[0];
            yBoundary2 *= -512;
            yBoundary2 += (objectEntityList[objectLoop].YPos >> 16);
            self->values[1] = yBoundary2;
        }
        self->values[0] = scriptEng.tempValue[0];
    } else {
        if (self->values[1] < yBoundary2) {
            yBoundary2--;
            if (self->values[1] < yBoundary2) {
                yBoundary2--;
            }
            if (self->values[1] < yBoundary2) {
                yBoundary2--;
            }
            if (self->values[1] < yBoundary2) {
                yBoundary2--;
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
