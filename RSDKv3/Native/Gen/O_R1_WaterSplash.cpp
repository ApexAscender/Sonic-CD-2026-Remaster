#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_WaterSplash.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterSplash.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_WaterSplash::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-16, -16, 32, 16, 166, 51);
    AddSpriteFrame(-16, -64, 32, 64, 148, 101);
    AddSpriteFrame(-16, -48, 32, 48, 115, 101);
    AddSpriteFrame(-16, -32, 32, 32, 107, 68);
    AddSpriteFrame(-16, -32, 32, 32, 140, 68);
}

void O_R1_WaterSplash::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_TOUCH, -16, 0, 16, 32);
        if (CheckResult() == 1) {
            self->values[0] = 4;
            self->state = 1;
            self->drawOrder = 4;
            self->frame = 0;
        }
    }
}

void O_R1_WaterSplash::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] > 0) {
            self->values[0]--;
        } else {
            self->state = 2;
            PlaySfx(globalSFXCount + 3, 0);
        }
        break;
        case 2:
        DrawSprite_Frame(self->frame);
        self->values[0]++;
        if (self->values[0] > 4) {
            self->values[0] = 0;
            self->frame++;
            if (self->frame > 4) {
                self->state = 0;
            }
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
