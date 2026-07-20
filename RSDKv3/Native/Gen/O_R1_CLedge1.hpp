#ifndef O_R1_CLEDGE1_H
#define O_R1_CLEDGE1_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R1_CLedge1 {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R1_CLEDGE1_H
