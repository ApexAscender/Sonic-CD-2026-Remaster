#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_BurstSplash.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BurstSplash.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_BurstSplash::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects3.gif");
    AddSpriteFrame(-16, -16, 32, 32, 1, 117);
}

void O_R4_BurstSplash::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    self->YPos += self->values[2];
    self->values[2] += 0x1000;
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
    self->values[0]++;
    if (self->values[0] == 60) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R4_BurstSplash::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
    self->direction++;
    self->direction &= 3;
}

#endif // RETRO_USE_NATIVE_OBJECTS
