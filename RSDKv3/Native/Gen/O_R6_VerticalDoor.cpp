#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_VerticalDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VerticalDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_VerticalDoor::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-8, -32, 16, 64, 239, 1);
}

void O_R6_VerticalDoor::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (objectEntityList[objectLoop + 1].propertyValue == 1) {
            self->state = 1;
        }
        if (self->values[0] > 0) {
            self->values[0] -= 0x40000;
            self->YPos += 0x40000;
        }
    } else {
        if (self->values[0] < 0x400000) {
            self->values[0] += 0x40000;
            self->YPos -= 0x40000;
        }
    }
}

void O_R6_VerticalDoor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (self->state == 1) {
            PlayerObjectCollision(C_BOX, -8, -32, 8, 32);
            PlayerObjectCollision(C_TOUCH, -64, -128, -32, 128);
            if (CheckResult() == 1) {
                self->state = 0;
            }
        } else {
            PlayerObjectCollision(C_BOX, -8, -32, 8, 64);
        }
    } else {
        if (self->state == 1) {
            PlayerObjectCollision(C_BOX, -8, -32, 8, 32);
            PlayerObjectCollision(C_TOUCH, 32, -128, 64, 128);
            if (CheckResult() == 1) {
                self->state = 0;
            }
        } else {
            PlayerObjectCollision(C_BOX, -8, -32, 8, 64);
        }
    }
}

void O_R6_VerticalDoor::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
