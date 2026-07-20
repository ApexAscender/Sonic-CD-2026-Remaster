#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_MultiDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MultiDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_MultiDoor::ObjectStartup()
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
    AddSpriteFrame(-16, -64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, 32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, -64, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, -32, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, 0, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, 32, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
}

void O_R4_MultiDoor::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[1] = self->YPos;
        if (objectEntityList[objectLoop - 1].propertyValue == 1) {
            self->state++;
        }
        if (objectEntityList[objectLoop + 1].propertyValue == 1) {
            self->state++;
        }
        break;
        case 1:
        if (self->values[0] < 128) {
            self->values[0]++;
            self->YPos += 0x10000;
            self->values[1] -= 0x10000;
        } else {
            self->state++;
        }
        break;
    }
}

void O_R4_MultiDoor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_BOX, -32, -65, 0, 64);
    if (CheckResult() == 1) {
        pYPos() += 0x10000;
    }
    PlayerObjectCollision(C_BOX, 32, -65, 64, 64);
    if (CheckResult() == 1) {
        pYPos() += 0x10000;
    }
    scriptEng.tempValue[0] = self->YPos;
    self->YPos = self->values[1];
    PlayerObjectCollision(C_BOX, -64, -64, -32, 64);
    PlayerObjectCollision(C_BOX, 0, -64, 32, 64);
    self->YPos = scriptEng.tempValue[0];
}

void O_R4_MultiDoor::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] -= 0x300000;
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->values[1]);
    DrawSprite_FrameXY(1, scriptEng.tempValue[0], self->values[1]);
    DrawSprite_FrameXY(2, scriptEng.tempValue[0], self->values[1]);
    DrawSprite_FrameXY(3, scriptEng.tempValue[0], self->values[1]);
    scriptEng.tempValue[0] += 0x200000;
    DrawSprite_FrameXY(4, scriptEng.tempValue[0], self->YPos);
    DrawSprite_FrameXY(5, scriptEng.tempValue[0], self->YPos);
    DrawSprite_FrameXY(6, scriptEng.tempValue[0], self->YPos);
    DrawSprite_FrameXY(7, scriptEng.tempValue[0], self->YPos);
    scriptEng.tempValue[0] += 0x200000;
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->values[1]);
    DrawSprite_FrameXY(1, scriptEng.tempValue[0], self->values[1]);
    DrawSprite_FrameXY(2, scriptEng.tempValue[0], self->values[1]);
    DrawSprite_FrameXY(3, scriptEng.tempValue[0], self->values[1]);
    scriptEng.tempValue[0] += 0x200000;
    DrawSprite_FrameXY(4, scriptEng.tempValue[0], self->YPos);
    DrawSprite_FrameXY(5, scriptEng.tempValue[0], self->YPos);
    DrawSprite_FrameXY(6, scriptEng.tempValue[0], self->YPos);
    DrawSprite_FrameXY(7, scriptEng.tempValue[0], self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
