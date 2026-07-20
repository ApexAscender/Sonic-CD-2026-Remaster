#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_SmokePuff.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SmokePuff.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_SmokePuff::ObjectStartup()
{
    LoadSpriteSheet("Special/Objects.gif");
    AddSpriteFrame(-16, -8, 32, 16, 1, 134);
    AddSpriteFrame(-16, -16, 32, 32, 1, 151);
    AddSpriteFrame(-16, -16, 32, 32, 1, 184);
    AddSpriteFrame(-24, -24, 48, 48, 34, 134);
    AddSpriteFrame(-24, -24, 48, 48, 34, 183);
}

void O_Special_SmokePuff::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
    self->values[0]++;
    if (self->values[0] > 3) {
        self->values[0] = 0;
        self->frame++;
        if (self->frame > 4) {
            self->type = TypeNameID("Blank Object");
            self->frame = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
