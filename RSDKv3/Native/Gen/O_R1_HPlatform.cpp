#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_HPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_HPlatform::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-32, -16, 64, 32, 101, 109);
}

void O_R1_HPlatform::ObjectMain()
{
    Entity *self = Self();

    self->values[5] = GVar("Oscillation");
    self->values[5] <<= 1;
    if (self->propertyValue == 1) {
        self->values[5] += 256;
    }
    self->values[2] = Cos512(self->values[5]);
    self->values[2] *= 0x1800;
    self->values[2] += self->XPos;
    self->values[2] &= 0xFFFF0000;
    self->values[2] -= self->values[3];
    if (self->values[0] == 1) {
        if (self->values[1] < 16) {
            self->values[1]++;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                self->values[4] = 0x10000;
            } else {
                self->values[4] = 0;
            }
        } else {
            self->values[4] = 0;
        }
    } else {
        if (self->values[1] > 0) {
            self->values[1]--;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] &= 3;
            if (scriptEng.tempValue[0] == 3) {
                self->values[4] = -0x10000;
            } else {
                self->values[4] = 0;
            }
        } else {
            self->values[4] = 0;
        }
    }
    self->values[0] = 0;
}

void O_R1_HPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    self->XPos = self->values[3];
    PlayerObjectCollision(C_PLATFORM, -32, -9, 32, 12);
    if (CheckResult() == 1) {
        self->values[0] = 1;
        pXPos() += self->values[2];
        pYPos() += self->values[4];
    }
    self->XPos = scriptEng.tempValue[0];
}

void O_R1_HPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->values[3] = Cos512(self->values[5]);
    self->values[3] *= 0x1800;
    self->values[3] += self->XPos;
    self->values[3] &= 0xFFFF0000;
    self->YPos += self->values[4];
    DrawSprite_FrameXY(0, self->values[3], self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
