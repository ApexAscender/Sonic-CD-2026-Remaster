#ifndef O_R6_MOVINGBLOCKS2_H
#define O_R6_MOVINGBLOCKS2_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R6_MovingBlocks2 {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void MovingBlocks_HandleMovement();
extern const Native::NativeFunctionDef funcs[1];
}

#endif
#endif // O_R6_MOVINGBLOCKS2_H
