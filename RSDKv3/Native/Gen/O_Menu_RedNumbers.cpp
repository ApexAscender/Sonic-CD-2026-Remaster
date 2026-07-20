#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_RedNumbers.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RedNumbers.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_RedNumbers::ObjectStartup()
{
    LoadSpriteSheet("Menu/MetalSonic.gif");
    AddSpriteFrame(-24, -24, 48, 48, 68, 258);
    AddSpriteFrame(-24, -24, 48, 48, 118, 258);
    AddSpriteFrame(-24, -24, 48, 48, 68, 308);
    AddSpriteFrame(-24, -24, 48, 48, 118, 308);
    AddSpriteFrame(-24, -24, 48, 48, 168, 308);
}

void O_Menu_RedNumbers::ObjectDraw()
{
    Entity *self = Self();

    self->scale = 160;
    DrawSpriteFX_Script(self->propertyValue, FX_SCALE, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
