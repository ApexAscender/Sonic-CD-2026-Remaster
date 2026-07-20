#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_SpikeDebris.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpikeDebris.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_SpikeDebris::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-8, -8, 16, 16, 50, 1);
    AddSpriteFrame(-8, -8, 16, 16, 66, 1);
    AddSpriteFrame(-8, -8, 16, 16, 50, 17);
    AddSpriteFrame(-8, -8, 16, 16, 66, 17);
    AddSpriteFrame(-8, -8, 16, 16, 50, 34);
    AddSpriteFrame(-8, -8, 16, 16, 66, 34);
    AddSpriteFrame(-8, -8, 16, 16, 50, 50);
    AddSpriteFrame(-8, -8, 16, 16, 66, 50);
    AddSpriteFrame(-8, -8, 16, 16, 50, 67);
    AddSpriteFrame(-8, -8, 16, 16, 66, 67);
    AddSpriteFrame(-8, -8, 16, 16, 50, 83);
    AddSpriteFrame(-8, -8, 16, 16, 66, 83);
}

void O_R3_SpikeDebris::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[0];
    self->YPos += self->values[1];
    self->values[1] += 0x4000;
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R3_SpikeDebris::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS
