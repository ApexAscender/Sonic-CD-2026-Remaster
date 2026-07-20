#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_MovingWall.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MovingWall.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_MovingWall::ObjectStartup()
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
    AddSpriteFrame(-32, -64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, -64, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, -32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, 0, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(-32, 32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    AddSpriteFrame(0, 32, 32, 32, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Moving Wall")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_MovingWall::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (pControlMode() > -1) {
            if (self->values[0] < 384) {
                self->values[0]++;
                self->XPos += 0x8000;
            } else {
                self->priority = 0;
                self->propertyValue = 1;
            }
        }
    }
}

void O_R4_MovingWall::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_BOX, -32, -64, 32, 64);
    if (CheckResult() == 3) {
        if (self->values[0] == 383) {
            pXPos() += 0x10000;
        }
    }
}

void O_R4_MovingWall::ObjectDraw()
{
    DrawSprite_Frame(0);
    DrawSprite_Frame(1);
    DrawSprite_Frame(2);
    DrawSprite_Frame(3);
    DrawSprite_Frame(4);
    DrawSprite_Frame(5);
    DrawSprite_Frame(6);
    DrawSprite_Frame(7);
}

#endif // RETRO_USE_NATIVE_OBJECTS
