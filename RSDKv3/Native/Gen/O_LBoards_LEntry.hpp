#ifndef O_LBOARDS_LENTRY_H
#define O_LBOARDS_LENTRY_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_LBoards_LEntry {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_LBOARDS_LENTRY_H
