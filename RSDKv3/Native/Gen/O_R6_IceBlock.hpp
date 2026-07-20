#ifndef O_R6_ICEBLOCK_H
#define O_R6_ICEBLOCK_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R6_IceBlock {
void ObjectStartup();
void ObjectMain();
void ObjectDraw();
void IceBlock_CreateIceChunks();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R6_ICEBLOCK_H
