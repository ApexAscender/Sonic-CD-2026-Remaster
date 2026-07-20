#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_BlockRowsB.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BlockRowsB.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_BlockRowsB::ObjectStartup()
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
    AddSpriteFrame(-32, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Block Rows B")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 3;
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x400000;
                break;
                case 2:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x800000;
                break;
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0xC00000;
                objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                break;
                case 4:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x800000;
                objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_BlockRowsB::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        self->values[1] += 0x8000;
        if (self->values[1] >= 0xC00000) {
            self->values[1] = 0xC00000;
            self->state = 1;
        }
    } else {
        self->values[1] -= 0x8000;
        if (self->values[1] <= 0) {
            self->values[1] = 0;
            self->state = 0;
        }
    }
}

void O_R4_BlockRowsB::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[1] = 0;
    scriptEng.tempValue[2] = 0;
    self->XPos -= 0x600000;
    self->XPos += self->values[1];
    PlayerObjectCollision(C_BOX, -32, -32, 32, 32);
    switch (CheckResult()) {
        case 1:
        if (self->state == 0) {
            pXPos() += 0x8000;
        } else {
            pXPos() -= 0x8000;
        }
        if (pSpeed() == 0) {
            if (self->values[2] == 0) {
                pXPos() &= 0xFFFF0000;
                self->values[1] &= 0xFFFF0000;
                self->values[2] = 1;
            }
        } else {
            self->values[2] = 0;
        }
        break;
        case 2:
        scriptEng.tempValue[1] = 1;
        break;
        case 3:
        scriptEng.tempValue[2] = 1;
        break;
    }
    self->XPos = scriptEng.tempValue[0];
    if (self->propertyValue > 1) {
        PlayerObjectCollision(C_BOX, -160, -32, -128, 32);
        if (CheckResult() == 3) {
            scriptEng.tempValue[2] = 1;
        }
    }
    PlayerObjectCollision(C_BOX, 128, -32, 160, 32);
    if (CheckResult() == 2) {
        scriptEng.tempValue[1] = 1;
    }
    if (scriptEng.tempValue[1] == 1) {
        if (scriptEng.tempValue[2] == 1) {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
    }
    if (pGravity() == 1) {
        self->values[2] = 0;
    }
}

void O_R4_BlockRowsB::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] -= 0x600000;
    scriptEng.tempValue[0] += self->values[1];
    DrawSprite_FrameXY(0, scriptEng.tempValue[0], self->YPos);
    DrawSprite_FrameXY(1, scriptEng.tempValue[0], self->YPos);
    DrawSprite_FrameXY(2, scriptEng.tempValue[0], self->YPos);
    DrawSprite_FrameXY(3, scriptEng.tempValue[0], self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
