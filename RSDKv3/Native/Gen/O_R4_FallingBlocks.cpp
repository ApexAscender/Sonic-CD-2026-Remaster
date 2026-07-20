#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_FallingBlocks.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FallingBlocks.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_FallingBlocks::ObjectStartup()
{
    switch (objectEntityList[24].propertyValue) {
        case 0:
        LoadSpriteSheet("R4/Objects.gif");
        scriptEng.tempValue[0] = 163;
        scriptEng.tempValue[1] = 1;
        scriptEng.tempValue[2] = 196;
        AddSpriteFrame(-16, -64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        AddSpriteFrame(-16, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        AddSpriteFrame(-16, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        break;
        case 1:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[0] = 1;
        scriptEng.tempValue[1] = 157;
        scriptEng.tempValue[2] = 34;
        AddSpriteFrame(-16, -64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        AddSpriteFrame(-16, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        AddSpriteFrame(-16, 0, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
        break;
        case 2:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[0] = 1;
        scriptEng.tempValue[1] = 190;
        scriptEng.tempValue[2] = 34;
        AddSpriteFrame(-16, -64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        AddSpriteFrame(-16, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        AddSpriteFrame(-16, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        break;
        case 3:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[0] = 1;
        scriptEng.tempValue[1] = 223;
        scriptEng.tempValue[2] = 34;
        AddSpriteFrame(-16, -64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        AddSpriteFrame(-16, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        AddSpriteFrame(-16, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        break;
    }
    scriptEng.tempValue[0] = objectScriptList[objectEntityList[objectLoop].type].spriteSheetID;
    LoadSpriteSheet("Global/Items3.gif");
    scriptEng.tempValue[1] = objectScriptList[objectEntityList[objectLoop].type].spriteSheetID;
    AddSpriteFrame(-16, 32, 32, 32, 50, 100);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Falling Blocks")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = scriptEng.tempValue[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = scriptEng.tempValue[1];
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_FallingBlocks::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_TOUCH, -16, -64, 16, 192);
        if (CheckResult() == 1) {
            self->priority = 1;
            self->values[1] = 0;
            self->values[3] = self->YPos;
            self->values[3] += 0x200000;
            self->state++;
        }
        break;
        case 1:
        self->values[1] += 0x2000;
        self->YPos += self->values[1];
        if (self->YPos >= self->values[3]) {
            self->YPos = self->values[3];
            self->values[1] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 3:
        self->values[1] += 0x2000;
        self->YPos += self->values[1];
        ObjectTileCollision_Script(0, 0, 32, 0);
        if (CheckResult() == 1) {
            self->state++;
        }
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->YPos = self->values[2];
        self->priority = 0;
        self->state = 0;
    }
}

void O_R4_FallingBlocks::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_BOX, -16, -64, 16, 62);
    if (CheckResult() == 4) {
        if (pGravity() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        } else {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
    }
}

void O_R4_FallingBlocks::ObjectDraw()
{
    Entity *self = Self();

    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[4];
    DrawSprite_FrameXY(0, self->XPos, self->YPos);
    DrawSprite_FrameXY(1, self->XPos, self->YPos);
    DrawSprite_FrameXY(2, self->XPos, self->YPos);
    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[5];
    DrawSprite_FrameXY(3, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
