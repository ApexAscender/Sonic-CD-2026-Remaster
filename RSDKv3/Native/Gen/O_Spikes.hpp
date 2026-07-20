#ifndef O_SPIKES_H
#define O_SPIKES_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Spikes {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_SPIKES_H
