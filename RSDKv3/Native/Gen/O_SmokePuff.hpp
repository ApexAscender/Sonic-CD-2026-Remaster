#ifndef O_SMOKEPUFF_H
#define O_SMOKEPUFF_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_SmokePuff {
void ObjectStartup();
void ObjectDraw();
}

#endif
#endif // O_SMOKEPUFF_H
