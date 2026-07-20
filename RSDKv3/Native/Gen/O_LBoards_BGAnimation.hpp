#ifndef O_LBOARDS_BGANIMATION_H
#define O_LBOARDS_BGANIMATION_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_LBoards_BGAnimation {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_LBOARDS_BGANIMATION_H
