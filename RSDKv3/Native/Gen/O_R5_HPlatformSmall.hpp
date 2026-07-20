#ifndef O_R5_HPLATFORMSMALL_H
#define O_R5_HPLATFORMSMALL_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R5_HPlatformSmall {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R5_HPLATFORMSMALL_H
