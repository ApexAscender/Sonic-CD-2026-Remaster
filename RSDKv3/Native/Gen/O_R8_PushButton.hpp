#ifndef O_R8_PUSHBUTTON_H
#define O_R8_PUSHBUTTON_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_PushButton {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R8_PUSHBUTTON_H
