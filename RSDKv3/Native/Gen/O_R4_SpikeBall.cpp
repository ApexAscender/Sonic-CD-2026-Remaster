#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_SpikeBall.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpikeBall.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_SpikeBall::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 221, 53);
}

void O_R4_SpikeBall::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R4_SpikeBall::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
