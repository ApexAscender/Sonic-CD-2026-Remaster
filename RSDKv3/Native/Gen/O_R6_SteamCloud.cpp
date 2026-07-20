#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_SteamCloud.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SteamCloud.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_SteamCloud::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects2.gif");
    AddSpriteFrame(-12, -12, 24, 24, 228, 26);
    AddSpriteFrame(-16, -16, 32, 32, 165, 133);
    AddSpriteFrame(-16, -12, 32, 24, 165, 166);
}

void O_R6_SteamCloud::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    self->YPos += self->values[2];
    self->values[0]++;
    if (self->values[0] == 30) {
        self->type = TypeNameID("Blank Object");
    }
    self->frame = self->values[0];
    self->frame /= 10;
}

void O_R6_SteamCloud::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
