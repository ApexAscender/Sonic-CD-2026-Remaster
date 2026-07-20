#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BossSpikes.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossSpikes.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BossSpikes::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects2.gif");
    if (objectEntityList[24].propertyValue < 3) {
        AddSpriteFrame(-24, -32, 48, 64, 125, 191);
    } else {
        AddSpriteFrame(-24, -32, 48, 64, 76, 191);
    }
}

void O_R5_BossSpikes::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (pXPos() > self->XPos) {
            objectEntityList[objectLoop + 3].values[2] = xBoundary2;
            newXBoundary1 = (objectEntityList[objectLoop].XPos >> 16);
            newXBoundary1 += 328;
            newXBoundary1 -= SCREEN_CENTERX;
            newXBoundary2 = newXBoundary1;
            newXBoundary2 += SCREEN_CENTERX;
            objectEntityList[objectLoop + 3].values[1] = newXBoundary2;
            objectEntityList[objectLoop + 3].values[1] += 160;
            objectEntityList[objectLoop + 3].values[1] <<= 16;
            newXBoundary2 += SCREEN_CENTERX;
            newYBoundary2 = (objectEntityList[objectLoop].YPos >> 16);
            self->state = 1;
            self->priority = 1;
            ResetObjectEntity(19, TypeNameID("Blank Object"), 0, 0, 0);
            SetActivePalette(0, 0, SCREEN_YSIZE);
        }
        break;
        case 1:
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 0x300000;
        if (pXPos() > scriptEng.tempValue[0]) {
            self->state = 2;
        }
        break;
        case 2:
        if (self->values[0] < 64) {
            self->values[0] += 2;
            self->YPos -= 0x20000;
        } else {
            self->values[0] = 0;
            self->state = 3;
        }
        break;
        case 3:
        if (self->values[0] < 192) {
            self->values[0] += 2;
            self->XPos += 0x20000;
        } else {
            self->values[0] = 0;
            self->state = 4;
            self->priority = 0;
        }
        break;
    }
}

void O_R5_BossSpikes::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 2) {
        PlayerObjectCollision(C_BOX, -24, -32, 0, 32);
    } else {
        PlayerObjectCollision(C_TOUCH, -64, -32, 0, 32);
        if (CheckResult() == 1) {
            pXPos() = pCollisionRight();
            pXPos() <<= 16;
            pXPos() += self->XPos;
        }
    }
    PlayerObjectCollision(C_TOUCH, 0, -32, 24, 32);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
        if (pState() == PlayerStateID("Player_State_GotHit")) {
            objectEntityList[objectLoop + 6].values[3] = 0xC000;
        }
    }
}

void O_R5_BossSpikes::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
