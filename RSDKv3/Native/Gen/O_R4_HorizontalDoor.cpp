#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_HorizontalDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HorizontalDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_HorizontalDoor::ObjectStartup()
{
    if (objectEntityList[24].propertyValue < 2) {
        LoadSpriteSheet("R4/Objects.gif");
        AddSpriteFrame(-64, -8, 128, 16, 18, 69);
    } else {
        LoadSpriteSheet("R4/Objects3.gif");
        AddSpriteFrame(-64, -8, 128, 16, 62, 211);
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Horizontal Door")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 3;
            objectEntityList[scriptEng.arrayPosition[0]].direction = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_HorizontalDoor::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (self->values[0] > 0) {
            self->values[0] -= 0x80000;
            if (self->direction == 0) {
                self->XPos += 0x80000;
            } else {
                self->XPos -= 0x80000;
            }
        }
        if (objectEntityList[objectLoop - 1].propertyValue == 1) {
            self->propertyValue = 1;
        }
        break;
        case 1:
        if (self->values[0] < 0x800000) {
            self->values[0] += 0x80000;
            if (self->direction == 0) {
                self->XPos -= 0x80000;
            } else {
                self->XPos += 0x80000;
            }
        }
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] -= 0x300000;
        if (pYPos() < scriptEng.tempValue[0]) {
            self->propertyValue = 0;
        }
        break;
    }
}

void O_R4_HorizontalDoor::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_BOX, -64, -8, 64, 8);
    if (CheckResult() > 0) {
        pCollisionMode() = 0;
    }
}

void O_R4_HorizontalDoor::ObjectDraw()
{
    DrawSprite_Frame(0);
}

void O_R4_HorizontalDoor::HorizontalDoor_CheckClose()
{
}

const Native::NativeFunctionDef O_R4_HorizontalDoor::funcs[1] = {
    { "HorizontalDoor_CheckClose", O_R4_HorizontalDoor::HorizontalDoor_CheckClose },
};

#endif // RETRO_USE_NATIVE_OBJECTS
