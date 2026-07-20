#ifndef O_TIMEWARP_H
#define O_TIMEWARP_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_TimeWarp {
void ObjectStartup();
void ObjectDraw();
}

#endif
#endif // O_TIMEWARP_H
