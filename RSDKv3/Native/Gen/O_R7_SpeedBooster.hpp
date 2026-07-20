#ifndef O_R7_SPEEDBOOSTER_H
#define O_R7_SPEEDBOOSTER_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R7_SpeedBooster {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R7_SPEEDBOOSTER_H
