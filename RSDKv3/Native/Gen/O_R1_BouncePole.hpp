#ifndef O_R1_BOUNCEPOLE_H
#define O_R1_BOUNCEPOLE_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_BouncePole {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R1_BOUNCEPOLE_H
