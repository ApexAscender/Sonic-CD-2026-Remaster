#ifndef O_R4_SOLIDBARRIER_H
#define O_R4_SOLIDBARRIER_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_SolidBarrier {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R4_SOLIDBARRIER_H
