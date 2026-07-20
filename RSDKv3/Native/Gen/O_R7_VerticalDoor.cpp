#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_VerticalDoor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from VerticalDoor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_VerticalDoor::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    if (objectEntityList[24].propertyValue == 2) {
        AddSpriteFrame(-16, -32, 32, 32, 117, 219);
        AddSpriteFrame(-16, 0, 32, 32, 117, 219);
    } else {
        AddSpriteFrame(-16, -32, 32, 32, 1, 1);
        AddSpriteFrame(-16, 0, 32, 32, 1, 1);
    }
}

void O_R7_VerticalDoor::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] < 0x400000) {
            self->values[0] += 0x20000;
            self->YPos -= 0x20000;
        } else {
            self->state = 5;
        }
        break;
        case 2:
        if (self->values[0] > 0x00000) {
            self->values[0] -= 0x20000;
            self->YPos += 0x20000;
        } else {
            self->state = 6;
        }
        break;
        case 3:
        scriptEng.tempValue[0] = pCollisionRight();
        scriptEng.tempValue[0] += 16;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += self->XPos;
        if (pXPos() > scriptEng.tempValue[0]) {
            self->state = 2;
            PlaySfx(globalSFXCount + 3, 0);
        } else {
            if (objectEntityList[objectLoop + 2].XPos > self->XPos) {
                self->state = 4;
                PlaySfx(globalSFXCount + 3, 0);
            }
        }
        break;
        case 4:
        if (self->values[0] > 0x00000) {
            self->values[0] -= 0x20000;
            self->YPos += 0x20000;
        }
        break;
    }
}

void O_R7_VerticalDoor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        PlayerObjectCollision(C_BOX, -16, -32, 16, 64);
        break;
        case 1:
        case 5:
        PlayerObjectCollision(C_BOX, -16, -32, 16, 32);
        break;
        case 2:
        case 6:
        PlayerObjectCollision(C_BOX, -16, -32, 16, 128);
        scriptEng.tempValue[0] = pCollisionRight();
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += pXPos();
        scriptEng.tempValue[1] = xBoundary2;
        scriptEng.tempValue[1] <<= 16;
        if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
            pXVel() = 0;
            pSpeed() = 0;
            pXPos() = scriptEng.tempValue[1];
            scriptEng.tempValue[0] = pCollisionRight();
            scriptEng.tempValue[0] <<= 16;
            pXPos() -= scriptEng.tempValue[0];
        }
        break;
        case 3:
        PlayerObjectCollision(C_BOX, -16, -32, 16, 32);
        scriptEng.tempValue[0] = pCollisionRight();
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += pXPos();
        scriptEng.tempValue[1] = xBoundary2;
        scriptEng.tempValue[1] <<= 16;
        if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
            pXVel() = 0;
            pSpeed() = 0;
            pXPos() = scriptEng.tempValue[1];
            scriptEng.tempValue[0] = pCollisionRight();
            scriptEng.tempValue[0] <<= 16;
            pXPos() -= scriptEng.tempValue[0];
        }
        break;
        case 4:
        scriptEng.tempValue[0] = pCollisionRight();
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += pXPos();
        scriptEng.tempValue[1] = self->XPos;
        scriptEng.tempValue[1] -= 0x100000;
        if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
            pXVel() = 0;
            pSpeed() = 0;
            pXPos() = scriptEng.tempValue[1];
            scriptEng.tempValue[0] = pCollisionRight();
            scriptEng.tempValue[0] <<= 16;
            pXPos() -= scriptEng.tempValue[0];
        }
        break;
    }
}

void O_R7_VerticalDoor::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] >>= 1;
    scriptEng.tempValue[0] += self->YPos;
    DrawSprite_FrameXY(0, self->XPos, scriptEng.tempValue[0]);
    DrawSprite_Frame(1);
}

#endif // RETRO_USE_NATIVE_OBJECTS
