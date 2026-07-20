#ifndef O_TIMEWARPFIX_H
#define O_TIMEWARPFIX_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_TimeWarpFix {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
}

#endif
#endif // O_TIMEWARPFIX_H
