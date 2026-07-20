#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_AirBubble.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from AirBubble.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_AirBubble::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-4, -4, 8, 8, 212, 61);
    AddSpriteFrame(-4, -4, 8, 8, 212, 70);
    AddSpriteFrame(-4, -4, 8, 8, 246, 18);
    AddSpriteFrame(-8, -8, 16, 16, 116, 181);
    AddSpriteFrame(-8, -8, 16, 16, 116, 198);
    AddSpriteFrame(-16, -16, 32, 32, 148, 194);
    AddSpriteFrame(-16, -16, 32, 32, 181, 201);
}

void O_R4_AirBubble::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        self->values[0]++;
        if (self->values[0] > 15) {
            self->values[0] = 0;
            if (self->frame == 6) {
                self->type = TypeNameID("Blank Object");
            }
            if (self->frame < self->propertyValue) {
                self->frame++;
            }
        }
        self->YPos += self->values[3];
        if (pAnimation() == GVar("ANI_FANROTATE")) {
            if (self->propertyValue < 3) {
                self->values[2] += 0x40000;
            }
        }
        if (pAnimation() == GVar("ANI_CLINGING")) {
            if (self->propertyValue < 3) {
                self->values[2] += 0x40000;
            }
        }
        if (self->frame < 6) {
            self->XPos = Sin512(self->values[1]);
            self->XPos <<= 9;
            self->XPos += self->values[2];
            self->values[1] += 4;
            self->values[1] &= 511;
        }
        if ((objectEntityList[objectLoop].YPos >> 16) < waterLevel) {
            if (self->propertyValue == 5) {
                self->frame = 6;
                self->propertyValue = 6;
                self->values[0] = 0;
                self->values[3] = 0;
            } else {
                if (self->propertyValue < 5) {
                    self->type = TypeNameID("Blank Object");
                }
            }
        }
    } else {
        if (self->values[0] < 20) {
            self->values[0]++;
            pAnimation() = GVar("ANI_BREATHING");
        } else {
            self->type = TypeNameID("Blank Object");
            pAnimation() = GVar("ANI_WALKING");
            pAnimationSpeed() = 20;
        }
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R4_AirBubble::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->frame == 5) {
        PlayerObjectCollision(C_TOUCH, -4, -4, 4, 4);
        if (CheckResult() == 1) {
            self->frame = 6;
            self->state = 1;
            self->values[0] = 0;
            self->values[3] = 0;
            pYVel() = 0;
            pXVel() = 0;
            pSpeed() = 0;
            pAnimation() = GVar("ANI_BREATHING");
            GVar("Player.AirTimer") = 0;
            PlaySfx(globalSFXCount + 6, 0);
        }
    }
}

void O_R4_AirBubble::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
