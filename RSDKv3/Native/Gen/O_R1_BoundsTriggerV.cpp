#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_BoundsTriggerV.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BoundsTriggerV.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_BoundsTriggerV::ObjectStartup()
{
}

void O_R1_BoundsTriggerV::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
    if (CheckResult() == 1) {
        switch (self->propertyValue) {
            case 0:
            newYBoundary2 = 0x500;
            newXBoundary1 = 0x820;
            break;
        }
    }
}

void O_R1_BoundsTriggerV::ObjectDraw()
{
    if (debugMode == 1) {
        scriptEng.tempValue[0] = (objectEntityList[objectLoop].XPos >> 16);
        scriptEng.tempValue[0] -= 16;
        scriptEng.tempValue[0] -= xScrollOffset;
        scriptEng.tempValue[1] = (objectEntityList[objectLoop].YPos >> 16);
        scriptEng.tempValue[1] -= 16;
        scriptEng.tempValue[1] -= yScrollOffset;
        DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], 32, 32, 0, 96, 48, 255);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
