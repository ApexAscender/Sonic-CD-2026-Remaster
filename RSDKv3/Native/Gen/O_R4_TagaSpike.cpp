#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_TagaSpike.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TagaSpike.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_TagaSpike::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(0, 0, 8, 8, 206, 52);
}

void O_R4_TagaSpike::ObjectMain()
{
    Entity *self = Self();

    self->values[2] += 0x2000;
    self->XPos += self->values[1];
    self->YPos += self->values[2];
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R4_TagaSpike::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, 0, 0, 4, 4);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R4_TagaSpike::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
