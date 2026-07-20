#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_DestroyedMobile.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from DestroyedMobile.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_DestroyedMobile::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects2.gif");
    AddSpriteFrame(-64, 0, 128, 32, 66, 98);
}

void O_R6_DestroyedMobile::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_PLATFORM, -64, 0, 64, 32);
}

void O_R6_DestroyedMobile::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
