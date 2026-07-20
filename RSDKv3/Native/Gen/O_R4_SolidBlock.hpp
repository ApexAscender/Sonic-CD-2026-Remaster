#ifndef O_R4_SOLIDBLOCK_H
#define O_R4_SOLIDBLOCK_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R4_SolidBlock {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R4_SOLIDBLOCK_H
