#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_Decorations.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Decorations.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_Decorations::ObjectStartup()
{
    LoadSpriteSheet("Menu/MetalSonic.gif");
    AddSpriteFrame(-32, -64, 64, 128, 191, 384);
    AddSpriteFrame(-32, -64, 64, 128, 125, 384);
    AddSpriteFrame(-32, -64, 64, 128, 59, 384);
    AddSpriteFrame(-32, -20, 64, 39, 157, 343);
    AddSpriteFrame(-20, -32, 39, 64, 114, 275);
    AddSpriteFrame(-32, -32, 64, 64, 49, 317);
}

void O_Menu_Decorations::ObjectDraw()
{
    Entity *self = Self();

    self->scale = 128;
    DrawSpriteFX_Script(self->propertyValue, FX_SCALE, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
