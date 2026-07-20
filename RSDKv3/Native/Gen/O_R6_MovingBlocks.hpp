#ifndef O_R6_MOVINGBLOCKS_H
#define O_R6_MOVINGBLOCKS_H

#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS
#include "NativeScriptOps.hpp"

namespace O_R6_MovingBlocks {
void ObjectStartup();
void ObjectMain();
void ObjectPlayerInteraction();
void ObjectDraw();
void MovingBlocks_MoveType_1();
void MovingBlocks_MoveType_2();
void MovingBlocks_MoveType_3();
void MovingBlocks_MoveType_4();
void MovingBlocks_CrushCheck();
void MovingBlocks_CrushCheckTop();
extern const Native::NativeFunctionDef funcs[6];
}

#endif
#endif // O_R6_MOVINGBLOCKS_H
