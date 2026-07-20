#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_StatueBomb.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from StatueBomb.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_StatueBomb::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 43, 67);
    AddSpriteFrame(-8, -8, 16, 16, 60, 67);
}

void O_R6_StatueBomb::ObjectMain()
{
    Entity *self = Self();

    self->values[1] += 1024;
    self->YPos += self->values[1];
    if (self->YPos >= self->values[2]) {
        self->YPos = self->values[2];
        self->type = TypeNameID("Blank Object");
        CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
        PlaySfx(22, 0);
    }
}

void O_R6_StatueBomb::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R6_StatueBomb::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] >>= 1;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->values[0]++;
    self->values[0] &= 3;
}

#endif // RETRO_USE_NATIVE_OBJECTS
