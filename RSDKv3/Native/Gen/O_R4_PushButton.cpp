#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_PushButton.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PushButton.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_PushButton::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-16, -8, 32, 16, 130, 35);
    AddSpriteFrame(-16, -8, 32, 16, 130, 52);
}

void O_R4_PushButton::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (pYVel() >= 0) {
            PlayerObjectCollision(C_BOX, -16, -8, 16, 8);
            if (CheckResult() == 1) {
                self->propertyValue = 1;
                pYPos() += 0x80000;
                PlaySfx(globalSFXCount + 8, 0);
            } else {
                self->propertyValue = 0;
            }
        } else {
            self->propertyValue = 0;
        }
    } else {
        PlayerObjectCollision(C_TOUCH, -16, -2, 16, 8);
        if (CheckResult() == 1) {
            if (pYVel() > -1) {
                self->propertyValue = 1;
                pGravity() = 0;
                pYVel() = 0;
                pYPos() = pCollisionBottom();
                pYPos() = -pYPos();
                pYPos() <<= 16;
                pYPos() += self->YPos;
            }
        } else {
            self->propertyValue = 0;
            if (pYVel() > -1) {
                pGravity() = 0;
                pYVel() = 0;
                pYPos() = pCollisionBottom();
                pYPos() = -pYPos();
                pYPos() -= 8;
                pYPos() <<= 16;
                pYPos() += self->YPos;
            }
        }
    }
}

void O_R4_PushButton::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS
