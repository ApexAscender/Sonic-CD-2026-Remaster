#ifndef O_R8_SPIKEBARRIER_H
#define O_R8_SPIKEBARRIER_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_SpikeBarrier {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R8_SPIKEBARRIER_H
