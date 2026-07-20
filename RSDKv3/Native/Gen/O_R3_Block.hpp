#ifndef O_R3_BLOCK_H
#define O_R3_BLOCK_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R3_Block {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R3_BLOCK_H
