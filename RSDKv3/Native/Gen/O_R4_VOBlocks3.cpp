#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_VOBlocks3.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VOBlocks3.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_VOBlocks3::ObjectStartup()
{
    switch (objectEntityList[24].propertyValue) {
        case 0:
        LoadSpriteSheet("R4/Objects.gif");
        scriptEng.tempValue[0] = 163;
        scriptEng.tempValue[1] = 1;
        scriptEng.tempValue[2] = 196;
        break;
        case 1:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[0] = 1;
        scriptEng.tempValue[1] = 157;
        scriptEng.tempValue[2] = 34;
        break;
        case 2:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[0] = 1;
        scriptEng.tempValue[1] = 190;
        scriptEng.tempValue[2] = 34;
        break;
        case 3:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[0] = 1;
        scriptEng.tempValue[1] = 223;
        scriptEng.tempValue[2] = 34;
        break;
    }
    AddSpriteFrame(-32, -96, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, -96, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, -64, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(0, -64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, -32, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(0, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, 0, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, 32, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(0, 32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, 64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, 64, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
}

void O_R4_VOBlocks3::ObjectMain()
{
    Entity *self = Self();

    self->values[3] = GVar("Oscillation");
    self->values[3] += self->propertyValue;
    self->values[3] <<= 1;
    self->values[2] = Sin512(self->values[3]);
    self->values[2] *= 0x2800;
    self->values[2] += self->YPos;
    self->values[2] &= 0xFFFF0000;
    self->values[2] -= self->values[1];
}

void O_R4_VOBlocks3::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    self->YPos = self->values[1];
    PlayerObjectCollision(C_BOX, -32, -96, 32, 96);
    switch (CheckResult()) {
        case 1:
        pYPos() += self->values[2];
        break;
        case 4:
        if (pGravity() == 0) {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
        break;
    }
    self->YPos = scriptEng.tempValue[0];
}

void O_R4_VOBlocks3::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = Sin512(self->values[3]);
    self->values[1] *= 0x2800;
    self->values[1] += self->YPos;
    self->values[1] &= 0xFFFF0000;
    DrawSprite_FrameXY(0, self->XPos, self->values[1]);
    DrawSprite_FrameXY(1, self->XPos, self->values[1]);
    DrawSprite_FrameXY(2, self->XPos, self->values[1]);
    DrawSprite_FrameXY(3, self->XPos, self->values[1]);
    DrawSprite_FrameXY(4, self->XPos, self->values[1]);
    DrawSprite_FrameXY(5, self->XPos, self->values[1]);
    DrawSprite_FrameXY(6, self->XPos, self->values[1]);
    DrawSprite_FrameXY(7, self->XPos, self->values[1]);
    DrawSprite_FrameXY(8, self->XPos, self->values[1]);
    DrawSprite_FrameXY(9, self->XPos, self->values[1]);
    DrawSprite_FrameXY(10, self->XPos, self->values[1]);
    DrawSprite_FrameXY(11, self->XPos, self->values[1]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
