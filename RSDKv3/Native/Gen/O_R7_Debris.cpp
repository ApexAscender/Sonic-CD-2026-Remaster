#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_Debris.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Debris.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_Debris::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects3.gif");
    AddSpriteFrame(-4, -4, 8, 8, 162, 124);
    AddSpriteFrame(-4, -4, 8, 8, 171, 124);
    AddSpriteFrame(-4, -4, 8, 8, 180, 124);
    AddSpriteFrame(-4, -4, 8, 8, 189, 124);
    AddSpriteFrame(-4, -4, 8, 8, 109, 124);
    AddSpriteFrame(-4, -4, 8, 8, 118, 124);
    AddSpriteFrame(-4, -4, 8, 8, 127, 124);
    AddSpriteFrame(-4, -4, 8, 8, 136, 124);
    AddSpriteFrame(-8, -8, 16, 16, 145, 124);
}

void O_R7_Debris::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    self->YPos += self->values[2];
    self->values[2] += 0x2000;
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R7_Debris::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->propertyValue, FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
