#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_BGFX_R11A.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGFX_R11A.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_BGFX_R11A::ObjectDraw()
{
    if (yScrollOffset > 512) {
        scriptEng.tempValue[0] = yScrollOffset;
        scriptEng.tempValue[0] -= 512;
        scriptEng.tempValue[0] <<= 15;
        scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        stageLayouts[1].scrollPos = scriptEng.tempValue[0];
    } else {
        stageLayouts[1].scrollPos = 0;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
