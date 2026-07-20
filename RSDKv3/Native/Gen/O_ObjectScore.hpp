#ifndef O_OBJECTSCORE_H
#define O_OBJECTSCORE_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_ObjectScore {
void ObjectStartup();
void ObjectDraw();
}

#endif
#endif // O_OBJECTSCORE_H
