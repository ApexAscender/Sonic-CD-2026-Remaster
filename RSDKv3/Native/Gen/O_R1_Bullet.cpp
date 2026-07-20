#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Bullet.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Bullet.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Bullet::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-4, -4, 8, 8, 166, 34);
    AddSpriteFrame(-4, -4, 8, 8, 175, 34);
    AddSpriteFrame(-6, -6, 12, 12, 101, 93);
    AddSpriteFrame(-6, -6, 12, 12, 114, 93);
}

void O_R1_Bullet::ObjectMain()
{
    Entity *self = Self();

    self->values[2] += 0x2000;
    self->XPos += self->values[1];
    self->YPos += self->values[2];
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
}

void O_R1_Bullet::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -4, -4, 4, 4);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R1_Bullet::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
    self->values[0]++;
    if (self->values[0] > 2) {
        self->values[0] = 0;
        self->frame++;
        self->frame &= 3;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
