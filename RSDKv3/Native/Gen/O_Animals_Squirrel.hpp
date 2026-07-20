#ifndef O_ANIMALS_SQUIRREL_H
#define O_ANIMALS_SQUIRREL_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_Animals_Squirrel {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
}

#endif
#endif // O_ANIMALS_SQUIRREL_H
