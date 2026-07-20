#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_RecoveryBarrier.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RecoveryBarrier.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_RecoveryBarrier::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects2.gif");
    AddSpriteFrame(-16, -8, 32, 16, 51, 33);
    AddSpriteFrame(-16, -8, 32, 16, 84, 33);
    AddSpriteFrame(-16, -8, 32, 16, 51, 50);
}

void O_R3_RecoveryBarrier::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->frame = 0;
        if (objectEntityList[objectLoop - 4].values[2] == 3) {
            self->state = 1;
        }
        break;
        case 1:
        self->frame = 1;
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->state = 2;
        }
        break;
        case 2:
        self->frame = 2;
        if (objectEntityList[objectLoop - 4].values[2] == 0) {
            self->state = 3;
        }
        break;
        case 3:
        self->frame = 3;
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->state = 0;
        }
        break;
    }
}

void O_R3_RecoveryBarrier::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 2) {
        PlayerObjectCollision(C_TOUCH, -16, -8, 16, 8);
        if (CheckResult() == 1) {
            pYVel() = -0x40000;
        }
    }
}

void O_R3_RecoveryBarrier::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
