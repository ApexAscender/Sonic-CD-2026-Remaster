#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_Bomb.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Bomb.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_Bomb::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 223, 153);
    AddSpriteFrame(-8, -8, 16, 16, 240, 153);
}

void O_R3_Bomb::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
    if (self->values[0] < 240) {
        self->values[0]++;
    } else {
        self->type = TypeNameID("Blank Object");
        CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
        PlaySfx(22, 0);
    }
    if (self->values[0] > 120) {
        self->frame = self->values[0];
        self->frame &= 3;
        self->frame >>= 1;
    }
    ObjectTileGrip_Script(0, 0, 8, 0);
}

void O_R3_Bomb::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R3_Bomb::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
