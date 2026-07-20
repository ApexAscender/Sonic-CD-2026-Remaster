#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_ButtonBlocks1.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ButtonBlocks1.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_ButtonBlocks1::ObjectStartup()
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
    AddSpriteFrame(0, -64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, 32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, 32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Button Blocks 1")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] -= 0x800000;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_ButtonBlocks1::ObjectMain()
{
    Entity *self = Self();

    if (objectEntityList[objectLoop + 1].propertyValue == 1) {
        if (self->values[2] > -0x10000) {
            self->values[2] -= 0x200;
        }
        self->YPos += self->values[2];
        if (self->YPos < self->values[3]) {
            self->YPos = self->values[3];
            self->values[2] = 0;
        }
    } else {
        if (self->values[2] < 0x10000) {
            self->values[2] += 0x200;
        }
        self->YPos += self->values[2];
        if (self->YPos > self->values[1]) {
            self->YPos = self->values[1];
            self->values[2] = 0;
        }
    }
    objectEntityList[objectLoop + 1].XPos = self->XPos;
    objectEntityList[objectLoop + 1].XPos += 0x100000;
    objectEntityList[objectLoop + 1].YPos = self->YPos;
    objectEntityList[objectLoop + 1].YPos -= 0x480000;
}

void O_R4_ButtonBlocks1::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_BOX, -32, -1, 0, 64);
    switch (CheckResult()) {
        case 1:
        pYPos() += 0x10000;
        break;
        case 4:
        if (pGravity() == 0) {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
    }
    PlayerObjectCollision(C_BOX, 0, -73, 32, 64);
    switch (CheckResult()) {
        case 1:
        pYPos() += 0x10000;
        break;
        case 4:
        if (pGravity() == 0) {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
    }
}

void O_R4_ButtonBlocks1::ObjectDraw()
{
    DrawSprite_Frame(0);
    DrawSprite_Frame(1);
    DrawSprite_Frame(2);
    DrawSprite_Frame(3);
    DrawSprite_Frame(4);
    DrawSprite_Frame(5);
}

#endif // RETRO_USE_NATIVE_OBJECTS
