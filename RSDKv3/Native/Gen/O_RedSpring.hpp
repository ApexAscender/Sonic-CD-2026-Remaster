#ifndef O_REDSPRING_H
#define O_REDSPRING_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_RedSpring {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_REDSPRING_H
