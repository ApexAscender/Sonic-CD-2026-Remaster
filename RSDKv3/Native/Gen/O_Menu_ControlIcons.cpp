#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_ControlIcons.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ControlIcons.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_ControlIcons::ObjectStartup()
{
    LoadSpriteSheet("Menu/MetalSonic.gif");
    AddSpriteFrame(-32, -32, 64, 64, 129, 1);
    AddSpriteFrame(-32, -32, 64, 64, 129, 68);
    AddSpriteFrame(-32, -32, 64, 64, 129, 135);
    AddSpriteFrame(-24, -24, 48, 48, 129, 202);
    AddSpriteFrame(-24, -24, 48, 48, 196, 1);
}

void O_Menu_ControlIcons::ObjectDraw()
{
    Entity *self = Self();

    self->scale = 224;
    DrawSpriteFX_Script(self->propertyValue, FX_SCALE, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
