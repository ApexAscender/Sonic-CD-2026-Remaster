#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_SonicAmy.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SonicAmy.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_SonicAmy::ObjectStartup()
{
    LoadSpriteSheet("Menu/SonicAmy.gif");
    AddSpriteFrame(-127, -127, 254, 254, 1, 1);
}

void O_Menu_SonicAmy::ObjectDraw()
{
    Entity *self = Self();

    self->scale = self->propertyValue;
    self->scale <<= 1;
    DrawSpriteFX_Script(0, FX_SCALE, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
