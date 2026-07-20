#ifndef O_PAUSEMENU_H
#define O_PAUSEMENU_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_PauseMenu {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_PAUSEMENU_H
