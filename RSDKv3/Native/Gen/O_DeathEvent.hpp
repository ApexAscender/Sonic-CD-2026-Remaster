#ifndef O_DEATHEVENT_H
#define O_DEATHEVENT_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_DeathEvent {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_DEATHEVENT_H
