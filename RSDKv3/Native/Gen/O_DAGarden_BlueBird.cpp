#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_BlueBird.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BlueBird.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_BlueBird::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/Objects.gif");
    AddSpriteFrame(-8, -9, 16, 16, 466, 577);
    AddSpriteFrame(-8, -8, 16, 16, 483, 577);
}

void O_DAGarden_BlueBird::ObjectMain()
{
    Entity *self = Self();

    if (self->direction == 0) {
        self->XPos += 0x8000;
    } else {
        self->XPos -= 0x8000;
    }
    switch (self->state) {
        case 0:
        self->values[1] = self->YPos;
        self->state++;
        break;
        case 1:
        self->values[2] += self->propertyValue;
        self->values[2] &= 511;
        self->YPos = Sin512(self->values[2]);
        self->YPos <<= 10;
        self->YPos += self->values[1];
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_DAGarden_BlueBird::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->animationSpeed;
    scriptEng.tempValue[0] >>= 3;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    self->animationSpeed++;
    self->animationSpeed &= 15;
}

#endif // RETRO_USE_NATIVE_OBJECTS
