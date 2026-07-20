#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_RDrumAnimator.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RDrumAnimator.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_RDrumAnimator::ObjectMain()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = GVar("RotatingDrum_Timer");
    scriptEng.tempValue[0] /= 10;
    scriptEng.tempValue[0] += 340;
    scriptEng.tempValue[0] += self->propertyValue;
    scriptEng.tempValue[1] = self->XPos;
    scriptEng.tempValue[1] >>= 23;
    scriptEng.tempValue[2] = self->YPos;
    scriptEng.tempValue[2] >>= 23;
    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = scriptEng.tempValue[0];
}

#endif // RETRO_USE_NATIVE_OBJECTS
