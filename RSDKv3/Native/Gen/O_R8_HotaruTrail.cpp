#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_HotaruTrail.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HotaruTrail.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_HotaruTrail::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects3.gif");
    AddSpriteFrame(-12, -10, 24, 24, 146, 133);
}

void O_R8_HotaruTrail::ObjectMain()
{
    Entity *self = Self();

    if (self->alpha > 0) {
        self->alpha -= 8;
    } else {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R8_HotaruTrail::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(0, FX_INK, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
