#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_BossSpark.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossSpark.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_BossSpark::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects3.gif");
    AddSpriteFrame(-8, -4, 16, 8, 238, 67);
    AddSpriteFrame(-8, -4, 16, 8, 238, 76);
}

void O_R8_BossSpark::ObjectMain()
{
    Entity *self = Self();

    self->values[2] += 0x1000;
    self->YPos += self->values[2];
    if (self->alpha > 0) {
        self->alpha -= 8;
    } else {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R8_BossSpark::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] >>= 2;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, self->YPos);
    self->animationTimer++;
    self->animationTimer &= 7;
}

#endif // RETRO_USE_NATIVE_OBJECTS
