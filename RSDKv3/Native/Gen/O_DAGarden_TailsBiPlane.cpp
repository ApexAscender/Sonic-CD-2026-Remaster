#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_TailsBiPlane.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TailsBiPlane.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_TailsBiPlane::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/Objects.gif");
    AddSpriteFrame(-24, -16, 48, 32, 365, 705);
    AddSpriteFrame(-24, -16, 48, 32, 414, 705);
    AddSpriteFrame(-24, -16, 48, 32, 463, 705);
    AddSpriteFrame(-24, -16, 48, 32, 365, 738);
    AddSpriteFrame(-24, -16, 48, 32, 414, 738);
    AddSpriteFrame(-24, -16, 48, 32, 463, 738);
    AddSpriteFrame(-24, -16, 48, 32, 365, 771);
    AddSpriteFrame(-24, -16, 48, 32, 414, 771);
    AddSpriteFrame(-24, -16, 48, 32, 463, 771);
}

void O_DAGarden_TailsBiPlane::ObjectMain()
{
    Entity *self = Self();

    if (self->direction == 0) {
        self->XPos += 0x10000;
    } else {
        self->XPos -= 0x10000;
    }
    switch (self->state) {
        case 0:
        case 3:
        self->frame = 0;
        break;
        case 1:
        self->YPos += 0x8000;
        self->frame = 3;
        break;
        case 2:
        self->YPos -= 0x8000;
        self->frame = 6;
        break;
    }
    if (self->values[0] > 0) {
        self->values[0]--;
    } else {
        self->state = rand() % 3;
        self->values[0] = rand() % 90;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_DAGarden_TailsBiPlane::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->animationSpeed;
    scriptEng.tempValue[0] >>= 1;
    scriptEng.tempValue[0] += self->frame;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    self->animationSpeed++;
    self->animationSpeed %= 6;
}

#endif // RETRO_USE_NATIVE_OBJECTS
