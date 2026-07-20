#ifndef O_R6_TUBETRAPDOOR_H
#define O_R6_TUBETRAPDOOR_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R6_TubeTrapDoor {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R6_TUBETRAPDOOR_H
