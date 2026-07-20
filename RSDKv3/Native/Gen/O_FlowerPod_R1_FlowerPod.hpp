#ifndef O_FLOWERPOD_R1_FLOWERPOD_H
#define O_FLOWERPOD_R1_FLOWERPOD_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_FlowerPod_R1_FlowerPod {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_FLOWERPOD_R1_FLOWERPOD_H
