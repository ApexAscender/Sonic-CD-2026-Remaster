#ifndef O_DUSTPUFF_H
#define O_DUSTPUFF_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_DustPuff {
void ObjectStartup();
void ObjectDraw();
}

#endif
#endif // O_DUSTPUFF_H
