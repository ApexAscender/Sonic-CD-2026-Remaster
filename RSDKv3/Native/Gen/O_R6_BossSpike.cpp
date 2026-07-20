#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BossSpike.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossSpike.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BossSpike::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects2.gif");
    AddSpriteFrame(-4, -12, 8, 24, 228, 1);
}

void O_R6_BossSpike::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        self->YPos += 0x38000;
        ObjectTileCollision_Script(0, 0, 12, 0);
        if (CheckResult() == 1) {
            self->state = 1;
        }
    } else {
        self->values[0]++;
        if (self->values[0] == 64) {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R6_BossSpike::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_TOUCH, -4, -12, 4, 12);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
    }
}

void O_R6_BossSpike::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] &= 7;
    if (scriptEng.tempValue[0] < 4) {
        DrawSprite_Frame(0);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
