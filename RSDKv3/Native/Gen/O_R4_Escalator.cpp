#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_Escalator.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Escalator.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_Escalator::ObjectStartup()
{
    switch (objectEntityList[24].propertyValue) {
        case 0:
        case 1:
        LoadSpriteSheet("R4/Objects.gif");
        AddSpriteFrame(-16, -16, 32, 32, 130, 1);
        break;
        case 2:
        LoadSpriteSheet("R4/Objects3.gif");
        AddSpriteFrame(-16, -16, 32, 32, 1, 150);
        break;
        case 3:
        LoadSpriteSheet("R4/Objects3.gif");
        AddSpriteFrame(-16, -16, 32, 32, 1, 183);
        break;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Escalator")) {
            if (objectEntityList[24].propertyValue < 2) {
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x10000;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 160;
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x20000;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 80;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_Escalator::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] > 0) {
            self->values[0]--;
            self->XPos += self->values[2];
            self->YPos -= self->values[2];
        } else {
            self->state++;
        }
        break;
        case 2:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 3;
            self->XPos -= 0xA00000;
            self->YPos += 0xA00000;
        }
        break;
        case 3:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        }
        break;
    }
}

void O_R4_Escalator::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            self->state = 1;
            self->values[0] = self->values[3];
            self->priority = 1;
            pTileCollisions() = 0;
            self->values[1] = 1;
        } else {
            if (self->values[1] == 1) {
                pTileCollisions() = 1;
            }
            self->values[1] = 0;
        }
        break;
        case 1:
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            pXPos() += self->values[2];
            pTileCollisions() = 0;
            self->values[1] = 1;
            PlayerObjectCollision(C_BOX, 20, -32, 32, -16);
            pPushing() = 0;
        } else {
            if (self->values[1] == 1) {
                pTileCollisions() = 1;
            }
            self->values[1] = 0;
        }
        break;
        case 2:
        pPushing() = 0;
        PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
        if (CheckResult() == 1) {
            pTileCollisions() = 0;
            self->values[1] = 1;
        } else {
            if (self->values[1] == 1) {
                pTileCollisions() = 1;
            }
            self->values[1] = 0;
        }
        break;
    }
}

void O_R4_Escalator::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 3) {
        DrawSprite_Frame(0);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
