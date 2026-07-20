#ifndef O_YELLOWSPRING_H
#define O_YELLOWSPRING_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_YellowSpring {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_YELLOWSPRING_H
