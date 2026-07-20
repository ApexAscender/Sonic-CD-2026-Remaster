#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_VPlatformLarge.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VPlatformLarge.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_VPlatformLarge::ObjectStartup()
{
    switch (objectEntityList[24].propertyValue) {
        case 0:
        LoadSpriteSheet("R5/Objects.gif");
        AddSpriteFrame(-48, -16, 96, 32, 1, 84);
        AddSpriteFrame(-48, -16, 96, 16, 1, 191);
        break;
        case 1:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-48, -16, 96, 32, 1, 203);
        AddSpriteFrame(-48, -16, 96, 16, 159, 131);
        break;
        case 2:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-48, -16, 96, 32, 1, 203);
        AddSpriteFrame(-48, -16, 96, 16, 159, 165);
        break;
        case 3:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-48, -16, 96, 32, 1, 203);
        AddSpriteFrame(-48, -16, 96, 16, 159, 199);
        break;
    }
}

void O_R5_VPlatformLarge::ObjectMain()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] == 312) {
        self->values[0] = 0;
    }
    self->values[3] = self->values[0];
    self->values[3] <<= 6;
    self->values[3] /= 39;
    self->values[2] = Sin512(self->values[3]);
    switch (self->propertyValue) {
        case 0:
        case 2:
        self->values[2] *= 0x1800;
        self->values[2] += 0x300000;
        self->values[2] += self->YPos;
        self->values[2] &= 0xFFFF0000;
        self->values[2] -= self->values[1];
        break;
        case 3:
        case 5:
        self->values[2] *= -0x1800;
        self->values[2] -= 0x300000;
        self->values[2] += self->YPos;
        self->values[2] &= 0xFFFF0000;
        self->values[2] -= self->values[1];
        break;
        case 1:
        self->values[2] *= 0x1800;
        self->values[2] += 0x300000;
        self->values[2] += self->YPos;
        self->values[2] &= 0xFFFF0000;
        self->values[2] -= self->values[1];
        break;
        case 4:
        self->values[2] *= -0x1800;
        self->values[2] -= 0x300000;
        self->values[2] += self->YPos;
        self->values[2] &= 0xFFFF0000;
        self->values[2] -= self->values[1];
        break;
    }
}

void O_R5_VPlatformLarge::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    self->YPos = self->values[1];
    switch (self->propertyValue) {
        case 0:
        case 3:
        PlayerObjectCollision(C_PLATFORM, -48, -16, 48, 12);
        if (CheckResult() == 1) {
            pYPos() += self->values[2];
        }
        break;
        case 2:
        case 5:
        PlayerObjectCollision(C_PLATFORM, -48, -16, 48, 12);
        if (CheckResult() == 1) {
            pYPos() += self->values[2];
            if (GVar("ConveyorBelt_Flag") == 0) {
                pXPos() += GVar("ConveyorBelt_Speed");
            } else {
                pXPos() -= GVar("ConveyorBelt_Speed");
            }
        }
        break;
    }
    self->YPos = scriptEng.tempValue[0];
}

void O_R5_VPlatformLarge::ObjectDraw()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        case 1:
        self->values[1] = Sin512(self->values[3]);
        self->values[1] *= 0x1800;
        self->values[1] += 0x300000;
        self->values[1] += self->YPos;
        self->values[1] &= 0xFFFF0000;
        DrawSprite_FrameXY(0, self->XPos, self->values[1]);
        break;
        case 2:
        self->values[1] = Sin512(self->values[3]);
        self->values[1] *= 0x1800;
        self->values[1] += 0x300000;
        self->values[1] += self->YPos;
        self->values[1] &= 0xFFFF0000;
        DrawSprite_FrameXY(0, self->XPos, self->values[1]);
        DrawSprite_FrameXY(1, self->XPos, self->values[1]);
        break;
        case 3:
        case 4:
        self->values[1] = Sin512(self->values[3]);
        self->values[1] *= -0x1800;
        self->values[1] -= 0x300000;
        self->values[1] += self->YPos;
        self->values[1] &= 0xFFFF0000;
        DrawSprite_FrameXY(0, self->XPos, self->values[1]);
        break;
        case 5:
        self->values[1] = Sin512(self->values[3]);
        self->values[1] *= -0x1800;
        self->values[1] -= 0x300000;
        self->values[1] += self->YPos;
        self->values[1] &= 0xFFFF0000;
        DrawSprite_FrameXY(0, self->XPos, self->values[1]);
        DrawSprite_FrameXY(1, self->XPos, self->values[1]);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
