#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BossBackPanel.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossBackPanel.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BossBackPanel::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects2.gif");
    AddSpriteFrame(-16, -32, 32, 16, 174, 238);
    AddSpriteFrame(-16, -16, 32, 16, 174, 238);
}

void O_R5_BossBackPanel::ObjectDraw()
{
    DrawSprite_Frame(0);
    DrawSprite_Frame(1);
}

#endif // RETRO_USE_NATIVE_OBJECTS
