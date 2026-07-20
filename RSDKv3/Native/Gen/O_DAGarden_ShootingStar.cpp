#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_ShootingStar.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ShootingStar.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_ShootingStar::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/Objects.gif");
    AddSpriteFrame(-4, -12, 9, 24, 387, 854);
    AddSpriteFrame(-9, -12, 19, 24, 397, 854);
    AddSpriteFrame(-12, -12, 24, 24, 417, 854);
    AddSpriteFrame(-12, -12, 24, 24, 442, 854);
    AddSpriteFrame(-12, -12, 24, 24, 467, 854);
    AddSpriteFrame(-10, -12, 19, 24, 492, 854);
    AddSpriteFrame(-4, -12, 9, 24, 387, 879);
    AddSpriteFrame(-9, -12, 19, 24, 397, 879);
    AddSpriteFrame(-12, -12, 24, 24, 417, 879);
    AddSpriteFrame(-12, -12, 24, 24, 442, 879);
    AddSpriteFrame(-12, -12, 24, 24, 467, 879);
    AddSpriteFrame(-10, -12, 19, 24, 492, 879);
}

void O_DAGarden_ShootingStar::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[1] = -0x14000;
        self->values[2] = 0x20000;
        self->state++;
        break;
        case 1:
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_DAGarden_ShootingStar::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->animationSpeed;
    scriptEng.tempValue[0] >>= 2;
    scriptEng.tempValue[0] += self->propertyValue;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    self->animationSpeed++;
    self->animationSpeed %= 24;
}

#endif // RETRO_USE_NATIVE_OBJECTS
