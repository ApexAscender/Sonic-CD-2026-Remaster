#ifndef O_BLUESHIELD_H
#define O_BLUESHIELD_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_BlueShield {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_BLUESHIELD_H
