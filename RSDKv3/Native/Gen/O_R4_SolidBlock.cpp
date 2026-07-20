#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_SolidBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SolidBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_SolidBlock::ObjectStartup()
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
    AddSpriteFrame(-16, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, -16, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, -16, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-16, 0, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, -32, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, 0, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    AddSpriteFrame(0, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-64, -16, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(32, -16, 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[1]);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Solid Block")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_SolidBlock::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        case 1:
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
        break;
        case 2:
        PlayerObjectCollision(C_BOX, -32, -16, 32, 16);
        break;
        case 3:
        PlayerObjectCollision(C_BOX, -16, -32, 16, 32);
        break;
        case 4:
        PlayerObjectCollision(C_BOX, -32, -32, 32, 32);
        break;
        case 5:
        PlayerObjectCollision(C_BOX, -64, -16, 64, 16);
        break;
    }
}

void O_R4_SolidBlock::ObjectDraw()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        case 1:
        DrawSprite_Frame(self->propertyValue);
        break;
        case 2:
        DrawSprite_Frame(2);
        DrawSprite_Frame(3);
        break;
        case 3:
        DrawSprite_Frame(4);
        DrawSprite_Frame(5);
        break;
        case 4:
        DrawSprite_Frame(6);
        DrawSprite_Frame(7);
        DrawSprite_Frame(8);
        DrawSprite_Frame(9);
        break;
        case 5:
        DrawSprite_Frame(2);
        DrawSprite_Frame(10);
        DrawSprite_Frame(11);
        DrawSprite_Frame(3);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
