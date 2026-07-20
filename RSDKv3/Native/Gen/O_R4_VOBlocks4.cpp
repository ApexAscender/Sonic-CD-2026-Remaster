#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_VOBlocks4.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VOBlocks4.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_VOBlocks4::ObjectStartup()
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
    AddSpriteFrame(-16, 0, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    scriptEng.tempValue[0] = objectScriptList[objectEntityList[objectLoop].type].spriteSheetID;
    LoadSpriteSheet("Global/Items3.gif");
    scriptEng.tempValue[1] = objectScriptList[objectEntityList[objectLoop].type].spriteSheetID;
    AddSpriteFrame(-16, 32, 32, 32, 50, 100);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("VOBlocks4")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = scriptEng.tempValue[0];
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = scriptEng.tempValue[1];
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_VOBlocks4::ObjectMain()
{
    Entity *self = Self();

    self->values[3] = GVar("Oscillation");
    self->values[3] += self->propertyValue;
    self->values[3] <<= 1;
    self->values[2] = Sin512(self->values[3]);
    self->values[2] <<= 13;
    self->values[2] += self->YPos;
    self->values[2] &= 0xFFFF0000;
    self->values[2] -= self->values[1];
}

void O_R4_VOBlocks4::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    self->YPos = self->values[1];
    PlayerObjectCollision(C_BOX, -16, -64, 16, 62);
    if (CheckResult() == 4) {
        if (pGravity() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        } else {
            CallScriptFunctionNamed("Player_Kill", scriptSub);
        }
    }
    self->YPos = scriptEng.tempValue[0];
}

void O_R4_VOBlocks4::ObjectDraw()
{
    Entity *self = Self();

    self->values[1] = Sin512(self->values[3]);
    self->values[1] <<= 13;
    self->values[1] += self->YPos;
    self->values[1] &= 0xFFFF0000;
    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[4];
    DrawSprite_FrameXY(0, self->XPos, self->values[1]);
    DrawSprite_FrameXY(1, self->XPos, self->values[1]);
    DrawSprite_FrameXY(2, self->XPos, self->values[1]);
    objectScriptList[objectEntityList[objectLoop].type].spriteSheetID = self->values[5];
    DrawSprite_FrameXY(3, self->XPos, self->values[1]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
