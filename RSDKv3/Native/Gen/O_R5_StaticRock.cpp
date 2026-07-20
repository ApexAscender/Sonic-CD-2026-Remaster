#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_StaticRock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from StaticRock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_StaticRock::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 92, 18);
    AddSpriteFrame(0, 0, 0, 0, 1, 1);
    AddSpriteFrame(0, 0, 0, 0, 1, 1);
}

void O_R5_StaticRock::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
        break;
        case 1:
        PlayerObjectCollision(C_TOUCH, -16, -14, 16, 16);
        if (CheckResult() == 1) {
            if (pXPos() < self->XPos) {
                pXPos() = pCollisionLeft();
                pXPos() <<= 16;
                pXPos() += self->XPos;
                pXPos() -= 0x100000;
            } else {
                pXPos() = pCollisionRight();
                pXPos() <<= 16;
                pXPos() += self->XPos;
                pXPos() += 0x100000;
            }
        }
        break;
        case 2:
        if (pCollisionMode() == 1) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                pYPos() = pCollisionBottom();
                pYPos() <<= 16;
                pYPos() += self->YPos;
                pYPos() += 0x100000;
                pSpeed() = 0;
            }
        }
        if (pCollisionMode() == 3) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                pYPos() = pCollisionBottom();
                pYPos() <<= 16;
                pYPos() += self->YPos;
                pYPos() += 0x100000;
                pSpeed() = 0;
            }
        }
        break;
    }
}

void O_R5_StaticRock::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS
