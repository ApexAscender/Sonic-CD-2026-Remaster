#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_SkimmerBullet.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SkimmerBullet.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_SkimmerBullet::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-4, -4, 8, 8, 197, 52);
    AddSpriteFrame(-4, -4, 8, 8, 197, 60);
}

void O_R4_SkimmerBullet::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R4_SkimmerBullet::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -4, -4, 4, 4);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R4_SkimmerBullet::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
    self->values[0]++;
    if (self->values[0] > 5) {
        self->values[0] = 0;
        self->frame++;
        self->frame &= 1;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
