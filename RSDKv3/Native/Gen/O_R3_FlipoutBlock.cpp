#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_FlipoutBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FlipoutBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_FlipoutBlock::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-16, -16, 32, 32, 34, 1);
    AddSpriteFrame(-16, -16, 32, 32, 34, 1);
    AddSpriteFrame(-16, -16, 32, 32, 67, 1);
    AddSpriteFrame(-16, -16, 32, 32, 67, 1);
}

void O_R3_FlipoutBlock::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue > 1) {
        self->YPos += self->values[0];
    } else {
        self->YPos -= self->values[0];
    }
    PlayerObjectCollision(C_BOX, -15, -16, 16, 16);
    if (self->propertyValue > 1) {
        self->YPos -= self->values[0];
    } else {
        self->YPos += self->values[0];
    }
}

void O_R3_FlipoutBlock::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] += 0x480000;
    if (pXPos() > scriptEng.tempValue[0]) {
        if (self->values[0] < 0x200000) {
            self->values[0] += 0x80000;
        }
    }
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] -= 0x100000;
    if (pXPos() < scriptEng.tempValue[0]) {
        if (self->values[0] > 0) {
            self->values[0] -= 0x80000;
        }
    }
    scriptEng.tempValue[1] = self->propertyValue;
    scriptEng.tempValue[1] &= 1;
    scriptEng.tempValue[0] = self->YPos;
    if (self->propertyValue > 1) {
        scriptEng.tempValue[0] += self->values[0];
        if (scriptEng.tempValue[1] == 0) {
            objectEntityList[objectLoop + 1].YPos = self->YPos;
            objectEntityList[objectLoop + 1].YPos += self->values[0];
        }
    } else {
        scriptEng.tempValue[0] -= self->values[0];
        if (scriptEng.tempValue[1] == 0) {
            objectEntityList[objectLoop + 1].YPos = self->YPos;
            objectEntityList[objectLoop + 1].YPos -= self->values[0];
        }
    }
    DrawSprite_FrameXY(self->propertyValue, self->XPos, scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
