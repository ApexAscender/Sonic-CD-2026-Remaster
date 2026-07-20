#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_DoublePlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from DoublePlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_DoublePlatform::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects3.gif");
    switch (objectEntityList[24].propertyValue) {
        case 0:
        AddSpriteFrame(-32, -16, 64, 32, 66, 98);
        AddSpriteFrame(96, -16, 64, 32, 66, 98);
        break;
        case 1:
        AddSpriteFrame(-32, -16, 64, 32, 66, 98);
        AddSpriteFrame(96, -16, 64, 32, 66, 98);
        break;
        case 2:
        AddSpriteFrame(-32, -16, 64, 32, 66, 98);
        AddSpriteFrame(96, -16, 64, 32, 66, 98);
        break;
        case 3:
        AddSpriteFrame(-32, -16, 64, 32, 131, 98);
        AddSpriteFrame(96, -16, 64, 32, 131, 98);
        break;
    }
}

void O_R5_DoublePlatform::ObjectMain()
{
    Entity *self = Self();

    self->values[0] += 2;
    self->values[0] &= 511;
    if (self->values[0] > 0) {
        self->values[3] = self->values[0];
        self->values[3] *= -0x4000;
        self->values[3] += self->XPos;
        self->values[3] &= 0xFFFF0000;
        self->values[3] -= self->values[1];
    } else {
        self->values[3] = 0;
    }
    self->values[4] = Cos512(self->values[0]);
    self->values[4] *= 0x3000;
    self->values[4] += self->YPos;
    self->values[4] &= 0xFFFF0000;
    self->values[4] -= self->values[2];
}

void O_R5_DoublePlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = self->YPos;
    self->XPos = self->values[1];
    self->YPos = self->values[2];
    PlayerObjectCollision(C_PLATFORM, -32, -16, 32, 16);
    if (CheckResult() == 1) {
        pXPos() += self->values[3];
        pYPos() += self->values[4];
    }
    PlayerObjectCollision(C_PLATFORM, 96, -16, 160, 16);
    if (CheckResult() == 1) {
        pXPos() += self->values[3];
        pYPos() += self->values[4];
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
}

void O_R5_DoublePlatform::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = self->values[0];
    self->values[1] *= -0x4000;
    self->values[1] += self->XPos;
    self->values[1] &= 0xFFFF0000;
    self->values[2] = Cos512(self->values[0]);
    self->values[2] *= 0x3000;
    self->values[2] += self->YPos;
    self->values[2] &= 0xFFFF0000;
    DrawSprite_FrameXY(0, self->values[1], self->values[2]);
    DrawSprite_FrameXY(1, self->values[1], self->values[2]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
