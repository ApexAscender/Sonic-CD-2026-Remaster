#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_MothSparkle.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MothSparkle.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_MothSparkle::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-8, -8, 16, 16, 1, 202);
    AddSpriteFrame(-8, -8, 16, 16, 18, 202);
    AddSpriteFrame(-8, -8, 16, 16, 1, 219);
    AddSpriteFrame(-8, -8, 16, 16, 18, 219);
}

void O_R3_MothSparkle::ObjectMain()
{
    Entity *self = Self();

    self->values[0]++;
    self->YPos += 0x10000;
    if (self->values[0] == 6) {
        self->values[0] = 0;
        self->frame++;
        self->frame &= 3;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R3_MothSparkle::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
