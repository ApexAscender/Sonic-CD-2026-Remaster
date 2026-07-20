#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_AppleTVIcons.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from AppleTVIcons.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_AppleTVIcons::ObjectStartup()
{
    LoadSpriteSheet("Menu/MetalSonic.gif");
    AddSpriteFrame(-32, -105, 64, 210, 1, 257);
    AddSpriteFrame(-32, -105, 64, 210, 1, 257);
    AddSpriteFrame(-93, -70, 186, 142, 68, 369);
}

void O_Menu_AppleTVIcons::ObjectDraw()
{
    Entity *self = Self();

    self->scale = 256;
    switch (self->propertyValue) {
        case 0:
        self->rotation = 0;
        break;
        case 1:
        self->rotation = 384;
        break;
        case 2:
        self->rotation = 0;
        break;
    }
    DrawSpriteFX_Script(self->propertyValue, FX_ROTOZOOM, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
