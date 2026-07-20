#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_KabasiraShot.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from KabasiraShot.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_KabasiraShot::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 133, 100);
    AddSpriteFrame(-8, -6, 8, 8, 243, 101);
    AddSpriteFrame(-8, -8, 16, 16, 201, 100);
    AddSpriteFrame(4, -6, 8, 8, 240, 65);
}

void O_R7_KabasiraShot::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    self->YPos += self->values[2];
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R7_KabasiraShot::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -6, -6, 6, 6);
    if (CheckResult() == 1) {
        if (pAnimation() == GVar("ANI_JUMPING")) {
            ResetObjectEntity(objectLoop, TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            PlaySfx(22, 0);
        } else {
            if (pAnimation() == GVar("ANI_SPINDASH")) {
                ResetObjectEntity(objectLoop, TypeNameID("Explosion"), 0, self->XPos, self->YPos);
                PlaySfx(22, 0);
            } else {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
        }
    }
}

void O_R7_KabasiraShot::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        DrawSpriteFX_Script(0, FX_INK, self->XPos, self->YPos);
        DrawSpriteFX_Script(1, FX_INK, self->XPos, self->YPos);
    } else {
        DrawSpriteFX_Script(2, FX_INK, self->XPos, self->YPos);
        DrawSpriteFX_Script(3, FX_INK, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
