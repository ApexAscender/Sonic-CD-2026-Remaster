#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_SolidBarrier.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SolidBarrier.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_SolidBarrier::ObjectStartup()
{
    switch (objectEntityList[24].propertyValue) {
        case 0:
        LoadSpriteSheet("R4/Objects.gif");
        scriptEng.tempValue[2] = 163;
        scriptEng.tempValue[3] = 1;
        break;
        case 1:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[2] = 1;
        scriptEng.tempValue[3] = 157;
        break;
        case 2:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[2] = 1;
        scriptEng.tempValue[3] = 190;
        break;
        case 3:
        LoadSpriteSheet("R4/Objects2.gif");
        scriptEng.tempValue[2] = 1;
        scriptEng.tempValue[3] = 223;
        break;
    }
    scriptEng.tempValue[0] = -64;
    scriptEng.tempValue[1] = -64;
    while (scriptEng.tempValue[1] < 64) {
        while (scriptEng.tempValue[0] < 64) {
            AddSpriteFrame(scriptEng.tempValue[0], scriptEng.tempValue[1], 32, 32, scriptEng.tempValue[2], scriptEng.tempValue[3]);
            scriptEng.tempValue[0] += 32;
        }
        scriptEng.tempValue[0] = -64;
        scriptEng.tempValue[1] += 32;
    }
}

void O_R4_SolidBarrier::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 1:
        PlayerObjectCollision(C_TOUCH, 112, -64, 256, 256);
        if (CheckResult() == 1) {
            self->propertyValue = 2;
        }
        break;
        case 2:
        if (self->values[0] < 64) {
            self->values[0] += 4;
            self->YPos += 0x40000;
        } else {
            self->propertyValue = 0;
        }
        break;
        case 3:
        if (self->values[0] < 128) {
            self->values[0] += 4;
            self->YPos += 0x40000;
        } else {
            self->propertyValue = 0;
        }
        break;
    }
}

void O_R4_SolidBarrier::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue > 1) {
        PlayerObjectCollision(C_BOX, -64, -64, 64, 128);
    } else {
        PlayerObjectCollision(C_BOX, -64, -64, 64, 64);
    }
}

void O_R4_SolidBarrier::ObjectDraw()
{
    scriptEng.tempValue[0] = 0;
    while (scriptEng.tempValue[0] < 16) {
        DrawSprite_Frame(scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
