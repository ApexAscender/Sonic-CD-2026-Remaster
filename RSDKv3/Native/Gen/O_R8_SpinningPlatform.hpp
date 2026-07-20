#ifndef O_R8_SPINNINGPLATFORM_H
#define O_R8_SPINNINGPLATFORM_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_SpinningPlatform {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R8_SPINNINGPLATFORM_H
