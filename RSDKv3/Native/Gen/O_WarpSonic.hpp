#ifndef O_WARPSONIC_H
#define O_WARPSONIC_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_WarpSonic {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_WARPSONIC_H
