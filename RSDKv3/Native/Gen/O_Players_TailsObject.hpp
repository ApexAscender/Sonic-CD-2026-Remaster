#ifndef O_PLAYERS_TAILSOBJECT_H
#define O_PLAYERS_TAILSOBJECT_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Players_TailsObject {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_PLAYERS_TAILSOBJECT_H
