#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_VOBlocks5.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VOBlocks5.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_VOBlocks5::ObjectStartup()
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
    AddSpriteFrame(-16, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
}

void O_R4_VOBlocks5::ObjectMain()
{
    Entity *self = Self();

    self->values[3] = self->propertyValue;
    self->values[3] <<= 1;
    self->values[3] += GVar("Oscillation");
    self->values[2] = Sin512(self->values[3]);
    self->values[2] <<= 14;
    self->values[2] += self->YPos;
    self->values[2] &= 0xFFFF0000;
    self->values[2] -= self->values[1];
}

void O_R4_VOBlocks5::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    self->YPos = self->values[1];
    PlayerObjectCollision(C_BOX, -16, -32, 16, 32);
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

void O_R4_VOBlocks5::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = Sin512(self->values[3]);
    self->values[1] <<= 14;
    self->values[1] += self->YPos;
    self->values[1] &= 0xFFFF0000;
    DrawSprite_FrameXY(0, self->XPos, self->values[1]);
    DrawSprite_FrameXY(1, self->XPos, self->values[1]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
