#ifndef O_R6_BOUNCEPLATFORM_H
#define O_R6_BOUNCEPLATFORM_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R6_BouncePlatform {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
}

#endif
#endif // O_R6_BOUNCEPLATFORM_H
