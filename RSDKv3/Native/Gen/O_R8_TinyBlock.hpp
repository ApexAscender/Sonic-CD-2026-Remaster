#ifndef O_R8_TINYBLOCK_H
#define O_R8_TINYBLOCK_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_TinyBlock {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R8_TINYBLOCK_H
