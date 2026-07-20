#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_Bomb2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Bomb2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_Bomb2::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 43, 67);
    AddSpriteFrame(-8, -8, 16, 16, 60, 67);
}

void O_Mission_Bomb2::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
    if (self->state == 0) {
        self->YPos += self->values[1];
        self->values[1] += 0x4000;
        ObjectTileCollision_Script(0, 0, 8, 0);
        if (CheckResult() == 1) {
            self->state = 1;
        }
    } else {
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            self->type = TypeNameID("Blank Object");
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            PlaySfx(22, 0);
        }
        if (self->values[0] > 60) {
            self->frame = self->values[0];
            self->frame &= 3;
            self->frame >>= 1;
        }
    }
}

void O_Mission_Bomb2::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_Mission_Bomb2::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
