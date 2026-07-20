#ifndef O_SIGNPOST_H
#define O_SIGNPOST_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_SignPost {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_SIGNPOST_H
