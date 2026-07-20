#ifndef O_R4_BLOCKROWSB_H
#define O_R4_BLOCKROWSB_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_BlockRowsB {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R4_BLOCKROWSB_H
