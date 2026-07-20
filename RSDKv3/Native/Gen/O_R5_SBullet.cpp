#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_SBullet.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SBullet.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_SBullet::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 67, 27);
    AddSpriteFrame(-8, -8, 16, 16, 133, 127);
}

void O_R5_SBullet::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
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

void O_R5_SBullet::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -6, -6, 6, 6);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R5_SBullet::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 1;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->frame++;
    self->frame &= 3;
}

#endif // RETRO_USE_NATIVE_OBJECTS
