#ifndef O_RINGSPARKLE_H
#define O_RINGSPARKLE_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_RingSparkle {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_RINGSPARKLE_H
