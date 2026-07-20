#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_SmallBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SmallBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_SmallBlock::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-16, -16, 32, 32, 157, 223);
}

void O_R8_SmallBlock::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
}

void O_R8_SmallBlock::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
