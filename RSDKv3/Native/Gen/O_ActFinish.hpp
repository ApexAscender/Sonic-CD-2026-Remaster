#ifndef O_ACTFINISH_H
#define O_ACTFINISH_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_ActFinish {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_ACTFINISH_H
