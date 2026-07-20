#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_BossBubble2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossBubble2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_BossBubble2::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects2.gif");
    AddSpriteFrame(-8, -8, 16, 16, 99, 118);
    AddSpriteFrame(-12, -12, 24, 24, 116, 126);
    AddSpriteFrame(-16, -16, 32, 32, 222, 115);
    AddSpriteFrame(-16, -16, 32, 32, 189, 115);
    AddSpriteFrame(-16, -16, 32, 32, 156, 126);
}

void O_R4_BossBubble2::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 20) {
            self->values[0]++;
        } else {
            self->state++;
        }
        break;
        case 1:
        self->state++;
        break;
        case 2:
        break;
        case 3:
        if (self->values[0] < 22) {
            self->values[0]++;
        } else {
            self->state++;
        }
        break;
        case 4:
        if (self->values[0] < 42) {
            self->values[0]++;
        } else {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_R4_BossBubble2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 2) {
        CheckResult() = 0;
        if (pAnimation() == GVar("ANI_JUMPING")) {
            CheckResult() = 1;
        }
        if (CheckResult() == 1) {
            PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
            if (CheckResult() == 1) {
                self->state = 3;
                pSpeed() = -pSpeed();
                pXVel() = -pXVel();
                pYVel() = 0x40000;
                pAnimation() = GVar("ANI_BREATHING");
                GVar("Player.AirTimer") = 0;
                PlaySfx(globalSFXCount + 6, 0);
                HapticEffect_Script(19, 0, 0, 0);
            }
        }
        if (pAnimation() == GVar("ANI_FLYING")) {
            PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
            if (CheckResult() == 1) {
                self->state = 3;
                pSpeed() = -pSpeed();
                pXVel() = -pXVel();
                pYVel() = 0x40000;
                pAnimation() = GVar("ANI_BREATHING");
                pState() = PlayerStateID("Player_State_Air");
                GVar("Player.AirTimer") = 0;
                PlaySfx(globalSFXCount + 6, 0);
                HapticEffect_Script(19, 0, 0, 0);
            }
        }
    }
}

void O_R4_BossBubble2::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->state);
}

#endif // RETRO_USE_NATIVE_OBJECTS
