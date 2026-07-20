#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_HelpItems.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HelpItems.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_HelpItems::ObjectStartup()
{
    LoadSpriteSheet("Menu/MetalSonic.gif");
    AddSpriteFrame(-8, -8, 16, 16, 204, 184);
    AddSpriteFrame(-16, -15, 32, 30, 223, 183);
    AddSpriteFrame(-16, -15, 32, 30, 223, 216);
    AddSpriteFrame(-16, -15, 32, 30, 223, 249);
    AddSpriteFrame(-16, -15, 32, 30, 223, 282);
    AddSpriteFrame(-16, -15, 32, 30, 223, 315);
    AddSpriteFrame(-8, -32, 16, 64, 204, 201);
    AddSpriteFrame(-16, -32, 32, 64, 196, 52);
    AddSpriteFrame(-16, -32, 32, 64, 196, 117);
}

void O_Menu_HelpItems::ObjectDraw()
{
    Entity *self = Self();

    self->scale = 320;
    DrawSpriteFX_Script(self->propertyValue, FX_SCALE, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
