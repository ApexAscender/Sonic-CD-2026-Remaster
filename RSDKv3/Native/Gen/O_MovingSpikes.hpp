#ifndef O_MOVINGSPIKES_H
#define O_MOVINGSPIKES_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_MovingSpikes {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_MOVINGSPIKES_H
