#ifndef O_R5_STATICPLATFORM_H
#define O_R5_STATICPLATFORM_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R5_StaticPlatform {
void ObjectStartup();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R5_STATICPLATFORM_H
