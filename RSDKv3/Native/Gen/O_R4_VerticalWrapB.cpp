#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_VerticalWrapB.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VerticalWrapB.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_VerticalWrapB::ObjectMain()
{
    if (yScrollOffset > 2047) {
        pYPos() -= 0x8000000;
        yScrollOffset -= 2048;
    } else {
        if (yScrollOffset == 0) {
            pYPos() += 0x8000000;
            yScrollOffset += 2048;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
