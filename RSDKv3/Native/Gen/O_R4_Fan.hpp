#ifndef O_R4_FAN_H
#define O_R4_FAN_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_Fan {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_R4_FAN_H
