#ifndef O_ATTRACTMODE_H
#define O_ATTRACTMODE_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_AttractMode {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_ATTRACTMODE_H
