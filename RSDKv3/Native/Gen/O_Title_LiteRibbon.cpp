#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Title_LiteRibbon.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LiteRibbon.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Title_LiteRibbon::ObjectStartup()
{
    LoadSpriteSheet("Title/Title.gif");
    AddSpriteFrame(0, 0, 84, 84, 427, 226);
}

void O_Title_LiteRibbon::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
