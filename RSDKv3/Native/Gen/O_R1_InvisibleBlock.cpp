#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_InvisibleBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from InvisibleBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_InvisibleBlock::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (pState() != PlayerStateID("Player_State_LedgePullUp")) {
            if (pAnimation() == GVar("ANI_CLIMBING")) {
                PlayerObjectCollision(4, -16, -16, 16, 16);
            } else {
                PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
                if (pAnimation() == GVar("ANI_GLIDING")) {
                    switch (CheckResult()) {
                        case 2:
                        case 3:
                        PlayerObjectCollision(4, -16, -16, 16, 16);
                        CallScriptFunctionNamed("Player_ClimbBlock", scriptSub);
                        break;
                    }
                }
            }
        }
        break;
        case 1:
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
        break;
    }
}

void O_R1_InvisibleBlock::ObjectDraw()
{
    Entity *self = Self();

    if (debugMode == 1) {
        scriptEng.tempValue[0] = (objectEntityList[objectLoop].XPos >> 16);
        scriptEng.tempValue[0] -= 16;
        scriptEng.tempValue[0] -= xScrollOffset;
        scriptEng.tempValue[1] = (objectEntityList[objectLoop].YPos >> 16);
        scriptEng.tempValue[1] -= 16;
        scriptEng.tempValue[1] -= yScrollOffset;
        if (self->propertyValue == 0) {
            DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], 32, 32, 50, 96, 100, 150);
        } else {
            DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], 32, 32, 25, 48, 50, 200);
        }
        self->drawOrder = 5;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
