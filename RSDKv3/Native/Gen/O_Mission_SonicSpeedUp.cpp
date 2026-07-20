#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_SonicSpeedUp.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SonicSpeedUp.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_SonicSpeedUp::ObjectStartup()
{
    pAccel() = 0x1800;
    pAirAccel() = 0x3000;
    pTopSpeed() = 0xC0000;
}

#endif // RETRO_USE_NATIVE_OBJECTS
