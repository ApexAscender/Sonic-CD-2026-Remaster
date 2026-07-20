#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_HPlatformMedium2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HPlatformMedium2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_HPlatformMedium2::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    switch (objectEntityList[24].propertyValue) {
        case 0:
        LoadSpriteSheet("R5/Objects.gif");
        AddSpriteFrame(-32, -16, 64, 32, 34, 51);
        AddSpriteFrame(-32, -16, 64, 16, 1, 208);
        break;
        case 1:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-32, -16, 64, 32, 34, 170);
        AddSpriteFrame(-32, -16, 64, 16, 159, 148);
        break;
        case 2:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-32, -16, 64, 32, 34, 170);
        AddSpriteFrame(-32, -16, 64, 16, 159, 182);
        break;
        case 3:
        LoadSpriteSheet("R5/Objects3.gif");
        AddSpriteFrame(-32, -16, 64, 32, 34, 170);
        AddSpriteFrame(-32, -16, 64, 16, 159, 216);
        break;
    }
}

void O_R5_HPlatformMedium2::ObjectMain()
{
    Entity *self = Self();

    self->values[6]++;
    if (self->values[6] == 312) {
        self->values[6] = 0;
    }
    self->values[5] = self->values[6];
    self->values[5] <<= 6;
    self->values[5] /= 39;
    self->values[4] = Sin512(self->values[5]);
    switch (self->propertyValue) {
        case 0:
        case 2:
        self->values[4] *= 0x1800;
        self->values[4] += 0x300000;
        self->values[4] += self->XPos;
        self->values[4] &= 0xFFFF0000;
        self->values[4] -= self->values[3];
        break;
        case 3:
        case 5:
        self->values[4] *= -0x1800;
        self->values[4] -= 0x300000;
        self->values[4] += self->XPos;
        self->values[4] &= 0xFFFF0000;
        self->values[4] -= self->values[3];
        break;
        case 1:
        self->values[4] *= 0x1800;
        self->values[4] += 0x300000;
        self->values[4] += self->XPos;
        self->values[4] &= 0xFFFF0000;
        objectEntityList[objectLoop + 1].XPos = self->values[4];
        objectEntityList[objectLoop + 1].XPos -= 0x100000;
        objectEntityList[objectLoop + 1].YPos = self->YPos;
        objectEntityList[objectLoop + 1].YPos -= 0x180000;
        objectEntityList[objectLoop + 2].XPos = self->values[4];
        objectEntityList[objectLoop + 2].XPos += 0x100000;
        objectEntityList[objectLoop + 2].YPos = self->YPos;
        objectEntityList[objectLoop + 2].YPos -= 0x180000;
        self->values[4] -= self->values[3];
        break;
        case 4:
        self->values[4] *= -0x1800;
        self->values[4] -= 0x300000;
        self->values[4] += self->XPos;
        self->values[4] &= 0xFFFF0000;
        objectEntityList[objectLoop + 1].XPos = self->values[4];
        objectEntityList[objectLoop + 1].XPos -= 0x100000;
        objectEntityList[objectLoop + 1].YPos = self->YPos;
        objectEntityList[objectLoop + 1].YPos -= 0x180000;
        objectEntityList[objectLoop + 2].XPos = self->values[4];
        objectEntityList[objectLoop + 2].XPos += 0x100000;
        objectEntityList[objectLoop + 2].YPos = self->YPos;
        objectEntityList[objectLoop + 2].YPos -= 0x180000;
        self->values[4] -= self->values[3];
        break;
    }
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

void O_R5_HPlatformMedium2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    self->XPos = self->values[3];
    switch (self->propertyValue) {
        case 0:
        case 3:
        PlayerObjectCollision(C_PLATFORM, -32, -16, 32, 12);
        if (CheckResult() == 1) {
            self->values[0] = 1;
            pXPos() += self->values[4];
            pYPos() += self->values[2];
        }
        break;
        case 2:
        case 5:
        if (self->values[7] == 0) {
            PlayerObjectCollision(C_PLATFORM, -32, -16, 32, 12);
            if (CheckResult() == 1) {
                self->values[0] = 1;
                pXPos() += self->values[4];
                pYPos() += self->values[2];
                if (GVar("ConveyorBelt_Flag") == 0) {
                    pXPos() += GVar("ConveyorBelt_Speed");
                } else {
                    pXPos() -= GVar("ConveyorBelt_Speed");
                }
                if (pAnimation() == GVar("ANI_FLAILINGLEFT")) {
                    self->values[7] = 30;
                }
                if (pAnimation() == GVar("ANI_FLAILINGRIGHT")) {
                    self->values[7] = 30;
                }
            }
        } else {
            self->values[7]--;
        }
        break;
    }
    self->XPos = scriptEng.tempValue[0];
}

void O_R5_HPlatformMedium2::ObjectDraw()
{
    Entity *self = Self();

    self->YPos += self->values[2];
    switch (self->propertyValue) {
        case 0:
        case 1:
        self->values[3] = Sin512(self->values[5]);
        self->values[3] *= 0x1800;
        self->values[3] += 0x300000;
        self->values[3] += self->XPos;
        self->values[3] &= 0xFFFF0000;
        DrawSprite_FrameXY(0, self->values[3], self->YPos);
        break;
        case 2:
        self->values[3] = Sin512(self->values[5]);
        self->values[3] *= 0x1800;
        self->values[3] += 0x300000;
        self->values[3] += self->XPos;
        self->values[3] &= 0xFFFF0000;
        DrawSprite_FrameXY(0, self->values[3], self->YPos);
        DrawSprite_FrameXY(1, self->values[3], self->YPos);
        break;
        case 3:
        case 4:
        self->values[3] = Sin512(self->values[5]);
        self->values[3] *= -0x1800;
        self->values[3] -= 0x300000;
        self->values[3] += self->XPos;
        self->values[3] &= 0xFFFF0000;
        DrawSprite_FrameXY(0, self->values[3], self->YPos);
        break;
        case 5:
        self->values[3] = Sin512(self->values[5]);
        self->values[3] *= -0x1800;
        self->values[3] -= 0x300000;
        self->values[3] += self->XPos;
        self->values[3] &= 0xFFFF0000;
        DrawSprite_FrameXY(0, self->values[3], self->YPos);
        DrawSprite_FrameXY(1, self->values[3], self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
