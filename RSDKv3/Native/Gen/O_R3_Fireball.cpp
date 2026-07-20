#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_Fireball.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Fireball.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_Fireball::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 230, 1);
    AddSpriteFrame(-8, -8, 16, 16, 230, 18);
}

void O_R3_Fireball::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    if (self->values[1] > 0) {
        self->values[1] += 0x1000;
    } else {
        self->values[1] -= 0x1000;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    } else {
        scriptEng.tempValue[0] = yScrollOffset;
        scriptEng.tempValue[0] -= 8;
        scriptEng.tempValue[0] <<= 16;
        if (self->YPos < scriptEng.tempValue[0]) {
            self->type = TypeNameID("Blank Object");
        }
    }
    if (self->values[0] > 0) {
        self->values[0]--;
        if (self->values[0] < 32) {
            self->alpha = self->values[0];
            self->alpha <<= 3;
        }
    } else {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R3_Fireball::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -8, -6, 8, 6);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R3_Fireball::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->frame, FX_INK, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
