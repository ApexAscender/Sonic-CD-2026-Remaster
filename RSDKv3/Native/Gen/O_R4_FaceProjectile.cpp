#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_FaceProjectile.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FaceProjectile.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_FaceProjectile::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects2.gif");
    AddSpriteFrame(-16, -8, 32, 16, 152, 159);
}

void O_R4_FaceProjectile::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R4_FaceProjectile::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pYVel() > -0xE0000) {
        PlayerObjectCollision(C_TOUCH, -13, -8, 13, 8);
        if (CheckResult() == 1) {
            if (self->direction == 0) {
                if (pLeft() == 1) {
                    if (pSpeed() > -0x30000) {
                        pSpeed() = -0x30000;
                    }
                } else {
                    if (pRight() == 1) {
                        pSpeed() = -0x20000;
                    } else {
                        pSpeed() = -0x30000;
                    }
                }
            } else {
                if (pRight() == 1) {
                    if (pSpeed() < 0x30000) {
                        pSpeed() = 0x30000;
                    }
                } else {
                    if (pLeft() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = 0x30000;
                    }
                }
            }
        }
    }
}

void O_R4_FaceProjectile::ObjectDraw()
{
    Entity *self = Self();

    if (self->animationTimer > 9) {
        self->direction += 2;
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        self->direction -= 2;
    } else {
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
    }
    self->animationTimer++;
    self->animationTimer %= 20;
}

#endif // RETRO_USE_NATIVE_OBJECTS
