#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_NoGripArea.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from NoGripArea.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_NoGripArea::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->values[0] == 0) {
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            if (pAnimation() == GVar("ANI_CLIMBING")) {
                CallScriptFunctionNamed("Player_Unstick", scriptSub);
            }
            if (pAnimation() == GVar("ANI_GLIDING")) {
                self->values[0] = 1;
                CallScriptFunctionNamed("Player_ForceNoGrip", scriptSub);
            }
        }
    } else {
        PlayerObjectCollision(C_TOUCH, -16, -16, 16, 32);
        if (CheckResult() == 0) {
            self->values[0] = 0;
            scriptEng.tempValue[0] = 0;
            scriptEng.arrayPosition[0] = 32;
            while (scriptEng.arrayPosition[0] < 1056) {
                if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("NoGripArea")) {
                    if (objectEntityList[scriptEng.arrayPosition[0]].values[0] == 1) {
                        scriptEng.tempValue[0] = 1;
                    }
                }
                scriptEng.arrayPosition[0]++;
            }
            if (scriptEng.tempValue[0] == 0) {
                CallScriptFunctionNamed("Player_ForceGrip", scriptSub);
            }
        }
    }
}

void O_R7_NoGripArea::ObjectDraw()
{
    Entity *self = Self();

    if (debugMode == 1) {
        scriptEng.tempValue[0] = (objectEntityList[objectLoop].XPos >> 16);
        scriptEng.tempValue[0] -= 16;
        scriptEng.tempValue[0] -= xScrollOffset;
        scriptEng.tempValue[1] = (objectEntityList[objectLoop].YPos >> 16);
        scriptEng.tempValue[1] -= 16;
        scriptEng.tempValue[1] -= yScrollOffset;
        if (self->values[0] == 1) {
            DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], 32, 48, 0, 96, 48, 255);
        } else {
            DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], 32, 32, 0, 96, 48, 255);
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
