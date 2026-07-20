#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_FireTrail.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FireTrail.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_FireTrail::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-24, -32, 32, 32, 207, 59);
    AddSpriteFrame(-16, -16, 24, 16, 199, 1);
    AddSpriteFrame(-24, -32, 32, 32, 207, 59);
    AddSpriteFrame(-16, -16, 24, 16, 199, 1);
}

void O_R7_FireTrail::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    self->values[0]++;
    if (self->values[0] > 3) {
        self->values[0] = 0;
        self->frame++;
        if (self->frame > 3) {
            self->type = TypeNameID("Blank Object");
            self->frame = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
