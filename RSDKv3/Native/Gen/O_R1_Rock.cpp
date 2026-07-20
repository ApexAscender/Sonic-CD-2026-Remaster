#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Rock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Rock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Rock::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-20, -16, 40, 32, 216, 1);
}

void O_R1_Rock::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_BOX, -14, -15, 14, 16);
}

void O_R1_Rock::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
