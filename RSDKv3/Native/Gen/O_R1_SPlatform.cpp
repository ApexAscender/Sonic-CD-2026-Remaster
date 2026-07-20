#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_SPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_SPlatform::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 190, 101);
}

void O_R1_SPlatform::ObjectMain()
{
    Entity *self = Self();

    if (self->values[0] == 1) {
        if (self->values[1] < 16) {
            self->values[1]++;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                self->values[2] = 0x10000;
            } else {
                self->values[2] = 0;
            }
        } else {
            self->values[2] = 0;
        }
    } else {
        if (self->values[1] > 0) {
            self->values[1]--;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                self->values[2] = -0x10000;
            } else {
                self->values[2] = 0;
            }
        } else {
            self->values[2] = 0;
        }
    }
    self->values[0] = 0;
}

void O_R1_SPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_PLATFORM, -16, -9, 16, 12);
    if (CheckResult() == 1) {
        self->values[0] = 1;
        pYPos() += self->values[2];
    }
}

void O_R1_SPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
