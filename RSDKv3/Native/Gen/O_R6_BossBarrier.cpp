#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BossBarrier.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossBarrier.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BossBarrier::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects2.gif");
    AddSpriteFrame(-16, -32, 32, 32, 173, 223);
    AddSpriteFrame(-16, 0, 32, 32, 173, 223);
    AddSpriteFrame(16, -6, 16, 32, 239, 183);
}

void O_R6_BossBarrier::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = pXPos();
        scriptEng.tempValue[0] -= self->XPos;
        if (scriptEng.tempValue[0] > 0x600000) {
            self->state = 1;
        }
        break;
        case 1:
        if (self->values[0] < 0x400000) {
            self->values[0] += 0x20000;
            self->YPos += 0x20000;
        }
        scriptEng.tempValue[0] = pXPos();
        scriptEng.tempValue[0] -= self->XPos;
        if (scriptEng.tempValue[0] > 0x800000) {
            self->state = 2;
            CreateTempObject(TypeNameID("Fade Music"), 0, self->XPos, self->YPos);
            newXBoundary1 = (objectEntityList[objectLoop].XPos >> 16);
            newXBoundary1 -= 16;
            newXBoundary2 = newXBoundary1;
            newXBoundary2 += 448;
            objectEntityList[objectLoop + 1].type = TypeNameID("Boss Camera");
            objectEntityList[objectLoop + 1].priority = 1;
            objectEntityList[objectLoop + 1].values[0] = -1;
            objectEntityList[objectLoop + 7].state = 1;
            objectEntityList[objectLoop + 7].priority = 1;
            objectEntityList[objectLoop + 8].type = TypeNameID("Floor Control");
            objectEntityList[objectLoop + 8].priority = 1;
            objectEntityList[objectLoop + 8].values[6] = -1;
        }
        break;
        case 2:
        if (self->values[0] < 0x400000) {
            self->values[0] += 0x20000;
            self->YPos += 0x20000;
        } else {
            self->state = 3;
        }
        break;
    }
}

void O_R6_BossBarrier::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->values[0] < 0x400000) {
        PlayerObjectCollision(C_BOX, -16, -32, 16, 32);
    } else {
        PlayerObjectCollision(C_BOX, -16, -32, 16, 64);
    }
}

void O_R6_BossBarrier::ObjectDraw()
{
    DrawSprite_Frame(0);
    DrawSprite_Frame(1);
    DrawSprite_Frame(2);
}

#endif // RETRO_USE_NATIVE_OBJECTS
