#ifndef O_MISSION_PLATFORMBLOCK_H
#define O_MISSION_PLATFORMBLOCK_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Mission_PlatformBlock {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_MISSION_PLATFORMBLOCK_H
