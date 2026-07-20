#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_BlockRowsA.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BlockRowsA.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_BlockRowsA::ObjectStartup()
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
}

void O_R4_BlockRowsA::ObjectMain()
{
    Entity *self = Self();

    self->values[1] += 0x8000;
    self->values[1] %= 0x900000;
    self->priority = 0;
}

void O_R4_BlockRowsA::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    self->XPos -= 0xA00000;
    self->XPos -= self->values[1];
    scriptEng.tempValue[1] = 0;
    scriptEng.tempValue[2] = 0;
    scriptEng.tempValue[3] = 0;
    while (scriptEng.tempValue[1] < 4) {
        PlayerObjectCollision(C_BOX, -32, -64, 32, 0);
        switch (CheckResult()) {
            case 1:
            pXPos() -= 0x8000;
            if (pSpeed() == 0) {
                if (self->values[2] == 0) {
                    self->values[2] = 1;
                    pXPos() &= 0xFFFF0000;
                    self->values[1] &= 0xFFFF0000;
                }
            } else {
                self->values[2] = 0;
            }
            break;
            case 2:
            scriptEng.tempValue[2] = 1;
            break;
            case 3:
            scriptEng.tempValue[3] = 1;
            break;
        }
        self->XPos += 0x900000;
        scriptEng.tempValue[1]++;
    }
    self->XPos = scriptEng.tempValue[0];
    self->XPos -= 0x1300000;
    self->XPos += self->values[1];
    scriptEng.tempValue[1] = 0;
    while (scriptEng.tempValue[1] < 4) {
        PlayerObjectCollision(C_BOX, -32, 0, 32, 64);
        switch (CheckResult()) {
            case 1:
            pXPos() += 0x8000;
            if (pSpeed() == 0) {
                if (self->values[2] == 0) {
                    self->values[2] = 1;
                    pXPos() &= 0xFFFF0000;
                    self->values[1] &= 0xFFFF0000;
                }
            } else {
                self->values[2] = 0;
            }
            break;
            case 2:
            scriptEng.tempValue[2] = 1;
            break;
            case 3:
            scriptEng.tempValue[3] = 1;
            break;
        }
        self->XPos += 0x900000;
        scriptEng.tempValue[1]++;
    }
    if (pGravity() == 1) {
        self->values[2] = 0;
    }
    self->XPos = scriptEng.tempValue[0];
    PlayerObjectCollision(C_BOX, -224, -128, -192, 128);
    switch (CheckResult()) {
        case 2:
        scriptEng.tempValue[2] = 1;
        break;
        case 3:
        scriptEng.tempValue[3] = 1;
        break;
    }
    PlayerObjectCollision(C_BOX, 192, -128, 224, 128);
    switch (CheckResult()) {
        case 2:
        scriptEng.tempValue[2] = 1;
        break;
        case 3:
        scriptEng.tempValue[3] = 1;
        break;
    }
    if (scriptEng.tempValue[2] == 1) {
        if (scriptEng.tempValue[3] == 1) {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
    }
}

void O_R4_BlockRowsA::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] -= 0xA00000;
    scriptEng.tempValue[0] -= self->values[1];
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[1] -= 0x200000;
    scriptEng.tempValue[2] = 0;
    while (scriptEng.tempValue[2] < 4) {
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        DrawSprite_FrameXY(1, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        DrawSprite_FrameXY(2, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        DrawSprite_FrameXY(3, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[0] += 0x900000;
        scriptEng.tempValue[2]++;
    }
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] -= 0x1300000;
    scriptEng.tempValue[0] += self->values[1];
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[1] += 0x200000;
    scriptEng.tempValue[2] = 0;
    while (scriptEng.tempValue[2] < 4) {
        DrawSprite_FrameXY(0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        DrawSprite_FrameXY(1, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        DrawSprite_FrameXY(2, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        DrawSprite_FrameXY(3, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[0] += 0x900000;
        scriptEng.tempValue[2]++;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
