#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_SmokePuff.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SmokePuff.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_SmokePuff::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Items2.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Items2_t.gif");
    }
    AddSpriteFrame(-16, -8, 32, 16, 1, 1);
    AddSpriteFrame(-16, -16, 32, 32, 1, 18);
    AddSpriteFrame(-16, -16, 32, 32, 1, 51);
    AddSpriteFrame(-24, -24, 48, 48, 34, 1);
    AddSpriteFrame(-24, -24, 48, 48, 34, 50);
}

void O_SmokePuff::ObjectDraw()
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
