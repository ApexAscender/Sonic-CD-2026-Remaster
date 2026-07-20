#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_DPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from DPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_DPlatform::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-32, -16, 64, 32, 101, 109);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Diag Platform")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue > 1) {
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = -0x1800;
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue -= 2;
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].values[6] = 0x1800;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_DPlatform::ObjectMain()
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
    self->values[2] -= self->values[1];
    self->values[4] = Cos512(self->values[5]);
    self->values[4] = -self->values[4];
    self->values[4] *= self->values[6];
    self->values[4] += self->YPos;
    self->values[4] &= 0xFFFF0000;
    self->values[4] -= self->values[3];
}

void O_R1_DPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    self->XPos = self->values[1];
    scriptEng.tempValue[1] = self->YPos;
    self->YPos = self->values[3];
    PlayerObjectCollision(C_PLATFORM, -32, -9, 32, 12);
    if (CheckResult() == 1) {
        pXPos() += self->values[2];
        pYPos() += self->values[4];
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
}

void O_R1_DPlatform::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = Cos512(self->values[5]);
    self->values[1] *= 0x1800;
    self->values[1] += self->XPos;
    self->values[1] &= 0xFFFF0000;
    self->values[3] = Cos512(self->values[5]);
    self->values[3] = -self->values[3];
    self->values[3] *= self->values[6];
    self->values[3] += self->YPos;
    self->values[3] &= 0xFFFF0000;
    DrawSprite_FrameXY(0, self->values[1], self->values[3]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
