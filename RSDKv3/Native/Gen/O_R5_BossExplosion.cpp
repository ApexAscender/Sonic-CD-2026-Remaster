#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BossExplosion.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossExplosion.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BossExplosion::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Items2.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Items2_t.gif");
    }
    AddSpriteFrame(-16, -8, 32, 16, 1, 1);
    AddSpriteFrame(-16, -16, 32, 32, 1, 84);
    AddSpriteFrame(-16, -16, 32, 32, 1, 117);
    AddSpriteFrame(-24, -24, 48, 48, 34, 1);
    AddSpriteFrame(-24, -24, 48, 48, 34, 50);
}

void O_R5_BossExplosion::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
    self->YPos -= 0x30000;
    self->values[0]++;
    if (self->values[0] > 3) {
        self->values[0] = 0;
        self->frame++;
        if (self->frame > 4) {
            self->frame = 0;
            self->values[1]++;
            if (self->values[1] == 2) {
                self->type = TypeNameID("Blank Object");
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
