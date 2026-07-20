#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_RPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_RPlatform::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(0, -24, 32, 16, 130, 35);
    AddSpriteFrame(0, -24, 32, 16, 130, 52);
    AddSpriteFrame(-8, -8, 16, 16, 163, 52);
    AddSpriteFrame(-8, -8, 16, 16, 180, 52);
    AddSpriteFrame(-32, -8, 64, 16, 147, 69);
}

void O_R4_RPlatform::ObjectMain()
{
    Entity *self = Self();

    self->values[0] += 2;
    self->values[0] &= 511;
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

void O_R4_RPlatform::ObjectPlayerInteraction()
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
    }
    if (self->propertyValue == 0) {
        PlayerObjectCollision(C_BOX, 0, -24, 32, 0);
        if (CheckResult() == 1) {
            if (self->propertyValue == 0) {
                PlaySfx(globalSFXCount + 8, 0);
            }
            self->propertyValue = 1;
            pYPos() += 0x80000;
            pXPos() += self->values[3];
            pYPos() += self->values[4];
        } else {
            self->propertyValue = 0;
        }
    } else {
        PlayerObjectCollision(C_BOX, 0, -16, 32, 0);
        if (CheckResult() == 1) {
            self->propertyValue = 1;
            pXPos() += self->values[3];
            pYPos() += self->values[4];
        } else {
            self->propertyValue = 0;
        }
    }
    self->XPos = scriptEng.tempValue[0];
    self->YPos = scriptEng.tempValue[1];
}

void O_R4_RPlatform::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(2);
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
        DrawSprite_FrameXY(3, scriptEng.tempValue[2], scriptEng.tempValue[3]);
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
    DrawSprite_FrameXY(4, self->values[1], self->values[2]);
    DrawSprite_FrameXY(self->propertyValue, self->values[1], self->values[2]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
