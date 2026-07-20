#ifndef O_R1_ROCK_H
#define O_R1_ROCK_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_Rock {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R1_ROCK_H
