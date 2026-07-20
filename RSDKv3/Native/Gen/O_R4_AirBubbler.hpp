#ifndef O_R4_AIRBUBBLER_H
#define O_R4_AIRBUBBLER_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_AirBubbler {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_R4_AIRBUBBLER_H
