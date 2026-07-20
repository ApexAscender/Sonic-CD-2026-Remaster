#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_ConveyorWheel.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ConveyorWheel.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_ConveyorWheel::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -64, -64, 64, 64);
    if (CheckResult() == 1) {
        if (pGravity() == 0) {
            if (pSpeed() < 0x50000) {
                pSpeed() = 0x50000;
            } else {
                if (pSpeed() > 0x100000) {
                    pSpeed() = 0x100000;
                }
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
