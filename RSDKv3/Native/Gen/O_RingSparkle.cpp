#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_RingSparkle.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RingSparkle.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_RingSparkle::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-8, -8, 16, 16, 1, 202);
    AddSpriteFrame(-8, -8, 16, 16, 18, 202);
    AddSpriteFrame(-8, -8, 16, 16, 1, 219);
    AddSpriteFrame(-8, -8, 16, 16, 18, 219);
}

void O_RingSparkle::ObjectMain()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] == 6) {
        self->values[0] = 0;
        self->frame++;
        if (self->frame == 4) {
            self->type = TypeNameID("Blank Object");
            self->frame = 0;
        }
    }
}

void O_RingSparkle::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
