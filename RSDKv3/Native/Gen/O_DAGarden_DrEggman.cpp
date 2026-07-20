#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_DrEggman.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from DrEggman.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_DrEggman::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/Objects.gif");
    AddSpriteFrame(-24, -20, 48, 40, 267, 705);
    AddSpriteFrame(-24, -20, 48, 40, 316, 705);
    AddSpriteFrame(8, 0, 24, 24, 265, 746);
    AddSpriteFrame(8, 0, 24, 24, 290, 746);
    AddSpriteFrame(8, 0, 24, 24, 315, 746);
    AddSpriteFrame(8, 0, 24, 24, 340, 746);
    AddSpriteFrame(8, 0, 0, 0, 265, 746);
    AddSpriteFrame(8, 0, 0, 0, 265, 746);
}

void O_DAGarden_DrEggman::ObjectMain()
{
    Entity *self = Self();

    if (self->direction == 1) {
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
        self->YPos <<= 11;
        self->YPos += self->values[1];
        self->values[1] -= 0x4000;
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_DAGarden_DrEggman::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] >>= 1;
    scriptEng.tempValue[0] += 2;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    self->animationTimer++;
    self->animationTimer %= 12;
    scriptEng.tempValue[0] = self->animationSpeed;
    scriptEng.tempValue[0] >>= 5;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    self->animationSpeed++;
    self->animationSpeed &= 63;
}

#endif // RETRO_USE_NATIVE_OBJECTS
