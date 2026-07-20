#ifndef O_SECRETS_SECRETIMAGES_H
#define O_SECRETS_SECRETIMAGES_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Secrets_SecretImages {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_SECRETS_SECRETIMAGES_H
