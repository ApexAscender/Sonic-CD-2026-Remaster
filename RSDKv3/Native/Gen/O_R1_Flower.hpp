#ifndef O_R1_FLOWER_H
#define O_R1_FLOWER_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_Flower {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_R1_FLOWER_H
