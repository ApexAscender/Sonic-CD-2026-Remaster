#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_VerticalDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VerticalDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_VerticalDoor::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-8, -64, 16, 128, 1, 69);
}

void O_R4_VerticalDoor::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (objectEntityList[objectLoop - 1].propertyValue == 0) {
            if (self->values[0] > 0) {
                self->values[0] -= 0x80000;
                self->YPos += 0x80000;
            }
        } else {
            if (self->values[0] < 0x800000) {
                self->values[0] += 0x80000;
                self->YPos -= 0x80000;
            }
        }
        break;
        case 1:
        if (objectEntityList[objectLoop - 1].propertyValue == 1) {
            self->state = 1;
        }
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 0x180000;
        if (pXPos() > scriptEng.tempValue[0]) {
            self->state = 0;
        }
        if (self->state == 0) {
            if (self->values[0] > 0) {
                self->values[0] -= 0x80000;
                self->YPos += 0x80000;
            }
        } else {
            if (self->values[0] < 0x800000) {
                self->values[0] += 0x80000;
                self->YPos -= 0x80000;
            }
        }
        break;
        case 2:
        if (objectEntityList[objectLoop - 1].propertyValue == 1) {
            self->state = 1;
        }
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 0x180000;
        if (pXPos() > scriptEng.tempValue[0]) {
            self->state = 0;
        }
        if (self->state == 0) {
            if (self->values[0] > 0) {
                self->values[0] -= 0x80000;
                self->YPos -= 0x80000;
            }
        } else {
            if (self->values[0] < 0x800000) {
                self->values[0] += 0x80000;
                self->YPos += 0x80000;
            }
        }
        break;
    }
}

void O_R4_VerticalDoor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = pYPos();
    PlayerObjectCollision(C_BOX, -8, -64, 8, 64);
    if (CheckResult() == 4) {
        pYPos() = scriptEng.tempValue[0];
    }
    PlayerObjectCollision(C_TOUCH, -8, -64, 8, 64);
    if (CheckResult() == 1) {
        if (pXPos() < self->XPos) {
            pXPos() = pCollisionLeft();
            pXPos() <<= 16;
            pXPos() += self->XPos;
            pXPos() -= 0x80000;
        } else {
            pXPos() = pCollisionRight();
            pXPos() <<= 16;
            pXPos() += self->XPos;
            pXPos() += 0x80000;
        }
    }
}

void O_R4_VerticalDoor::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
