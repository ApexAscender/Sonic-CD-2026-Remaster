#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_UFO.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from UFO.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_UFO::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/Objects.gif");
    AddSpriteFrame(-12, -12, 24, 24, 354, 804);
    AddSpriteFrame(-12, -12, 24, 24, 379, 804);
    AddSpriteFrame(-12, -12, 24, 24, 404, 804);
    AddSpriteFrame(-12, -12, 24, 24, 354, 829);
    AddSpriteFrame(-12, -12, 24, 24, 379, 829);
    AddSpriteFrame(-12, -12, 24, 24, 404, 829);
}

void O_DAGarden_UFO::ObjectMain()
{
    Entity *self = Self();

    if (self->direction == 0) {
        self->XPos += self->values[4];
    } else {
        self->XPos -= self->values[4];
    }
    switch (self->state) {
        case 0:
        case 3:
        self->frame = 0;
        self->values[3] += 8;
        self->values[3] &= 511;
        self->YPos = Sin512(self->values[3]);
        self->YPos <<= 9;
        self->YPos += self->values[1];
        break;
        case 1:
        self->YPos += self->values[2];
        self->frame = 1;
        self->values[1] = self->YPos;
        if (self->YPos > 0xD00000) {
            self->state = 2;
        }
        break;
        case 2:
        self->YPos -= self->values[2];
        self->frame = 2;
        self->values[1] = self->YPos;
        if (self->YPos < 0x200000) {
            self->state = 1;
        }
        break;
    }
    if (self->values[0] > 0) {
        self->values[0]--;
    } else {
        self->values[1] = self->YPos;
        self->state = rand() % 3;
        self->values[0] = rand() % 90;
        self->values[4] = rand() % 6;
        self->values[4]++;
        self->values[4] <<= 14;
        self->values[2] = rand() % 6;
        self->values[2]++;
        self->values[2] <<= 15;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_DAGarden_UFO::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] += self->propertyValue;
    DrawSprite_Frame(scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
