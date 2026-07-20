#ifndef O_R8_SPIKEPUZZLE_H
#define O_R8_SPIKEPUZZLE_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R8_SpikePuzzle {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void SpikePuzzle_Reset();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R8_SPIKEPUZZLE_H
