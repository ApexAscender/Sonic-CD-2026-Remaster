#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BossBarrier2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossBarrier2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BossBarrier2::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects2.gif");
    AddSpriteFrame(-16, -48, 32, 32, 173, 223);
    AddSpriteFrame(-16, -16, 32, 32, 173, 223);
    AddSpriteFrame(-16, 16, 32, 32, 173, 223);
    AddSpriteFrame(-32, 10, 16, 32, 239, 216);
}

void O_R6_BossBarrier2::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        break;
        case 1:
        if (self->values[0] < 0x600000) {
            self->values[0] += 0x20000;
            self->YPos -= 0x20000;
        }
        scriptEng.tempValue[0] = pXPos();
        scriptEng.tempValue[0] -= self->XPos;
        break;
        case 2:
        if (self->values[0] < 0x600000) {
            self->values[0] += 0x20000;
            self->YPos -= 0x20000;
        } else {
            self->state = 0;
        }
        break;
    }
}

void O_R6_BossBarrier2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->values[0] < 1) {
        PlayerObjectCollision(C_BOX, -16, -48, 16, 64);
    } else {
        PlayerObjectCollision(C_BOX, -16, -48, 16, 48);
    }
}

void O_R6_BossBarrier2::ObjectDraw()
{
    DrawSprite_Frame(0);
    DrawSprite_Frame(1);
    DrawSprite_Frame(2);
    DrawSprite_Frame(3);
}

#endif // RETRO_USE_NATIVE_OBJECTS
