#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_BBFireball.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BBFireball.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_BBFireball::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-8, -8, 16, 16, 109, 110);
    AddSpriteFrame(-8, -8, 16, 16, 126, 110);
}

void O_R8_BBFireball::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    self->YPos += self->values[2];
    self->values[2] += 0x2000;
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_R8_BBFireball::ObjectPlayerInteraction()
{
    if (pCollisionPlane() == 0) {
        if (pState() != PlayerStateID("Player_State_Static")) {
            PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
        }
    }
}

void O_R8_BBFireball::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] >>= 1;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->animationTimer++;
    self->animationTimer &= 3;
}

#endif // RETRO_USE_NATIVE_OBJECTS
