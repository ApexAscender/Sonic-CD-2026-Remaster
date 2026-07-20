#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_WaterLevelTrigger.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterLevelTrigger.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_WaterLevelTrigger::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        GVar("Stage.NewWaterLevel") = 0x5340000;
        break;
        case 1:
        if (pXPos() > self->XPos) {
            GVar("Stage.NewWaterLevel") = 0x7800000;
        } else {
            GVar("Stage.NewWaterLevel") = 0x5340000;
        }
        break;
        case 2:
        PlayerObjectCollision(C_TOUCH, -128, -128, 128, 128);
        if (CheckResult() == 1) {
            GVar("Stage.NewWaterLevel") = 0x3C00000;
        }
        break;
        case 3:
        if (pXPos() > self->XPos) {
            GVar("Stage.NewWaterLevel") = 0x5000000;
        }
        break;
        case 4:
        if (pXPos() > self->XPos) {
            GVar("Stage.NewWaterLevel") = 0x1100000;
        } else {
            GVar("Stage.NewWaterLevel") = 0x1E00000;
        }
        break;
        case 5:
        if (pXPos() > self->XPos) {
            GVar("Stage.NewWaterLevel") = 0x2400000;
        } else {
            GVar("Stage.NewWaterLevel") = 0x1100000;
        }
        break;
        case 6:
        if (pXPos() > self->XPos) {
            GVar("Stage.NewWaterLevel") = 0x3900000;
        } else {
            GVar("Stage.NewWaterLevel") = 0x5100000;
        }
        break;
        case 7:
        if (pXPos() > self->XPos) {
            GVar("Stage.NewWaterLevel") = 0x4100000;
        } else {
            GVar("Stage.NewWaterLevel") = 0x3900000;
        }
        break;
        case 8:
        if (pXPos() > self->XPos) {
            GVar("Stage.NewWaterLevel") = 0x5000000;
        } else {
            GVar("Stage.NewWaterLevel") = 0x4100000;
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
