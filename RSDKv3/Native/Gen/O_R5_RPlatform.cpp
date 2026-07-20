#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_RPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_RPlatform::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 1, 1);
    AddSpriteFrame(-8, -8, 16, 16, 18, 1);
    AddSpriteFrame(-32, -8, 64, 16, 1, 208);
}

void O_R5_RPlatform::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 1:
        self->values[0] -= 2;
        if (self->values[0] < 0) {
            self->values[0] += 512;
        }
        break;
        case 2:
        self->values[5] += 2;
        self->values[5] &= 511;
        self->values[0] = Sin512(self->values[5]);
        self->values[0] >>= 2;
        self->values[0] += 128;
        break;
        case 3:
        self->values[5] += 2;
        self->values[5] &= 511;
        self->values[0] = Sin512(self->values[5]);
        self->values[0] = -self->values[0];
        self->values[0] >>= 2;
        self->values[0] += 384;
        self->values[0] &= 511;
        break;
    }
    scriptEng.tempValue[1] = 96;
    self->values[3] = Cos512(self->values[0]);
    self->values[3] *= scriptEng.tempValue[1];
    self->values[3] <<= 7;
    self->values[3] += self->XPos;
    self->values[3] &= 0xFFFF0000;
    self->values[3] -= self->values[1];
    self->values[4] = Sin512(self->values[0]);
    self->values[4] *= scriptEng.tempValue[1];
    self->values[4] <<= 7;
    self->values[4] += self->YPos;
    self->values[4] &= 0xFFFF0000;
    self->values[4] -= self->values[2];
}

void O_R5_RPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = self->YPos;
    self->XPos = self->values[1];
    self->YPos = self->values[2];
    PlayerObjectCollision(C_PLATFORM, -32, -8, 32, 8);
    if (CheckResult() == 1) {
        pXPos() += self->values[3];
        pYPos() += self->values[4];
        if (GVar("ConveyorBelt_Flag") == 0) {
            pXPos() += GVar("ConveyorBelt_Speed");
        } else {
            pXPos() -= GVar("ConveyorBelt_Speed");
        }
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
}

void O_R5_RPlatform::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(0);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 16;
    while (scriptEng.tempValue[0] < 5) {
        scriptEng.tempValue[2] = Cos512(self->values[0]);
        scriptEng.tempValue[2] *= scriptEng.tempValue[1];
        scriptEng.tempValue[2] <<= 7;
        scriptEng.tempValue[2] += self->XPos;
        scriptEng.tempValue[3] = Sin512(self->values[0]);
        scriptEng.tempValue[3] *= scriptEng.tempValue[1];
        scriptEng.tempValue[3] <<= 7;
        scriptEng.tempValue[3] += self->YPos;
        DrawSprite_FrameXY(1, scriptEng.tempValue[2], scriptEng.tempValue[3]);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 16;
    }
    self->values[1] = Cos512(self->values[0]);
    self->values[1] *= scriptEng.tempValue[1];
    self->values[1] <<= 7;
    self->values[1] += self->XPos;
    self->values[1] &= 0xFFFF0000;
    self->values[2] = Sin512(self->values[0]);
    self->values[2] *= scriptEng.tempValue[1];
    self->values[2] <<= 7;
    self->values[2] += self->YPos;
    self->values[2] &= 0xFFFF0000;
    DrawSprite_FrameXY(2, self->values[1], self->values[2]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
