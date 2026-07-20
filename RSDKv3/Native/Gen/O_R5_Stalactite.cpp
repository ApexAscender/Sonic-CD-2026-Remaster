#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_Stalactite.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Stalactite.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_Stalactite::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    switch (objectEntityList[24].propertyValue) {
        case 0:
        AddSpriteFrame(-8, -24, 16, 48, 172, 207);
        break;
        case 1:
        AddSpriteFrame(-8, -24, 16, 48, 189, 207);
        break;
        case 2:
        AddSpriteFrame(-8, -24, 16, 48, 172, 207);
        break;
        case 3:
        AddSpriteFrame(-8, -24, 16, 48, 155, 207);
        break;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Stalactite")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R5_Stalactite::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] < 0x80000) {
            self->values[0] += 0x4000;
        }
        self->YPos += self->values[0];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 2;
            self->YPos = self->values[1];
        }
        break;
        case 2:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->priority = 0;
            self->state = 0;
        }
        break;
    }
}

void O_R5_Stalactite::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_TOUCH, -4, 0, 4, 96);
        if (CheckResult() == 1) {
            self->priority = 1;
            self->values[0] = 0;
            self->state = 1;
        }
        case 1:
        PlayerObjectCollision(C_TOUCH, -8, -24, 8, 20);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
        break;
    }
}

void O_R5_Stalactite::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        DrawSprite_Frame(0);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
