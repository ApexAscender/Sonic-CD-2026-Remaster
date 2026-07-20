#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_HOBlocks2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HOBlocks2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_HOBlocks2::ObjectStartup()
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
    AddSpriteFrame(-48, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(16, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
}

void O_R4_HOBlocks2::ObjectMain()
{
    Entity *self = Self();

    self->values[3] = GVar("Oscillation");
    self->values[3] += self->propertyValue;
    self->values[3] <<= 1;
    self->values[2] = Cos512(self->values[3]);
    self->values[2] <<= 12;
    self->values[2] += self->XPos;
    self->values[2] &= 0xFFFF0000;
    self->values[2] -= self->values[1];
    self->values[4] = 0;
}

void O_R4_HOBlocks2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    self->XPos = self->values[1];
    PlayerObjectCollision(C_BOX, -48, -16, 48, 16);
    switch (CheckResult()) {
        case 1:
        pXPos() += self->values[2];
        break;
        case 2:
        if (objectEntityList[objectLoop - 1].values[4] == 1) {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
        break;
        case 3:
        self->values[4] = 1;
        break;
    }
    self->XPos = scriptEng.tempValue[0];
}

void O_R4_HOBlocks2::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = Cos512(self->values[3]);
    self->values[1] <<= 12;
    self->values[1] += self->XPos;
    self->values[1] &= 0xFFFF0000;
    DrawSprite_FrameXY(0, self->values[1], self->YPos);
    DrawSprite_FrameXY(1, self->values[1], self->YPos);
    DrawSprite_FrameXY(2, self->values[1], self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
