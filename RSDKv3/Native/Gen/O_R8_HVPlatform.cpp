#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_HVPlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HVPlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_HVPlatform::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 140, 123);
    AddSpriteFrame(-56, -8, 16, 16, 75, 200);
    AddSpriteFrame(-40, -8, 16, 16, 75, 200);
    AddSpriteFrame(-24, -8, 16, 16, 75, 200);
    AddSpriteFrame(8, -8, 16, 16, 75, 200);
    AddSpriteFrame(24, -8, 16, 16, 75, 200);
    AddSpriteFrame(40, -8, 16, 16, 75, 200);
    AddSpriteFrame(-8, -56, 16, 16, 75, 200);
    AddSpriteFrame(-8, -40, 16, 16, 75, 200);
    AddSpriteFrame(-8, -24, 16, 16, 75, 200);
    AddSpriteFrame(-8, 8, 16, 16, 75, 200);
    AddSpriteFrame(-8, 24, 16, 16, 75, 200);
    AddSpriteFrame(-8, 40, 16, 16, 75, 200);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("HV Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].state = 12;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_HVPlatform::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 8:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 1:
        case 2:
        case 3:
        case 9:
        case 10:
        case 11:
        if (self->values[0] < 5) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 4:
        case 12:
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 5:
        case 6:
        case 7:
        case 13:
        case 14:
        case 15:
        if (self->values[0] < 5) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
            self->state &= 15;
        }
        break;
    }
}

void O_R8_HVPlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 8:
        PlayerObjectCollision(C_BOX, -8, -8, 8, 8);
        break;
        case 1:
        case 7:
        PlayerObjectCollision(C_BOX, -24, -8, 24, 8);
        break;
        case 2:
        case 6:
        PlayerObjectCollision(C_BOX, -40, -8, 40, 8);
        break;
        case 3:
        case 4:
        case 5:
        PlayerObjectCollision(C_BOX, -56, -8, 56, 8);
        break;
        case 9:
        case 15:
        PlayerObjectCollision(C_BOX, -8, -24, 8, 24);
        break;
        case 10:
        case 14:
        PlayerObjectCollision(C_BOX, -8, -40, 8, 40);
        break;
        case 11:
        case 12:
        case 13:
        PlayerObjectCollision(C_BOX, -8, -56, 8, 56);
        break;
    }
}

void O_R8_HVPlatform::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(0);
    switch (self->state) {
        case 1:
        case 7:
        DrawSprite_Frame(3);
        DrawSprite_Frame(4);
        break;
        case 2:
        case 6:
        DrawSprite_Frame(2);
        DrawSprite_Frame(3);
        DrawSprite_Frame(4);
        DrawSprite_Frame(5);
        break;
        case 3:
        case 4:
        case 5:
        DrawSprite_Frame(1);
        DrawSprite_Frame(2);
        DrawSprite_Frame(3);
        DrawSprite_Frame(4);
        DrawSprite_Frame(5);
        DrawSprite_Frame(6);
        break;
        case 9:
        case 15:
        DrawSprite_Frame(9);
        DrawSprite_Frame(10);
        break;
        case 10:
        case 14:
        DrawSprite_Frame(8);
        DrawSprite_Frame(9);
        DrawSprite_Frame(10);
        DrawSprite_Frame(11);
        break;
        case 11:
        case 12:
        case 13:
        DrawSprite_Frame(7);
        DrawSprite_Frame(8);
        DrawSprite_Frame(9);
        DrawSprite_Frame(10);
        DrawSprite_Frame(11);
        DrawSprite_Frame(12);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
