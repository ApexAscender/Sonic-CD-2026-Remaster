#ifndef O_R3_ROTATINGDRUM_H
#define O_R3_ROTATINGDRUM_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R3_RotatingDrum {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R3_ROTATINGDRUM_H
