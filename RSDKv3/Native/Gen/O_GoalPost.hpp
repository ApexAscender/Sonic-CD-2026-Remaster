#ifndef O_GOALPOST_H
#define O_GOALPOST_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_GoalPost {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_GOALPOST_H
