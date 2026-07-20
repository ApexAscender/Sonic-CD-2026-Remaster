#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BombCarrier.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BombCarrier.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BombCarrier::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects2.gif");
    AddSpriteFrame(-16, -12, 32, 24, 33, 215);
    AddSpriteFrame(-16, -12, 32, 24, 100, 113);
    AddSpriteFrame(-16, 12, 32, 16, 33, 239);
    AddSpriteFrame(-16, 12, 32, 16, 1, 239);
}

void O_R5_BombCarrier::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] += 0x200000;
        if (pXPos() > scriptEng.tempValue[0]) {
            CreateTempObject(TypeNameID("Fade Music"), 0, 0, 0);
            self->state = 1;
        }
        break;
        case 2:
        if (objectEntityList[objectLoop + 3].state < 6) {
            if (self->values[0] < 180) {
                self->values[0]++;
            } else {
                self->state = 4;
                PlaySfx(globalSFXCount + 5, 0);
                if (objectEntityList[objectLoop + 4].state < 8) {
                    objectEntityList[objectLoop + 3].state = 1;
                } else {
                    objectEntityList[objectLoop + 3].state = 5;
                    objectEntityList[objectLoop + 3].values[0] = 0;
                    objectEntityList[objectLoop + 3].frame = 0;
                }
            }
        } else {
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
        }
        break;
        case 3:
        if (self->XPos < objectEntityList[objectLoop + 1].XPos) {
            self->XPos += 0x1E000;
        } else {
            self->state = 2;
            self->XPos = objectEntityList[objectLoop + 1].XPos;
            self->values[0] = 0;
            if (objectEntityList[objectLoop + 4].state > 8) {
                if (objectEntityList[objectLoop + 4].state > 9) {
                    ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
                }
                if (objectEntityList[objectLoop + 4].values[5] > 640) {
                    ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
                }
            }
        }
        break;
        case 4:
        if (self->XPos > pXPos()) {
            self->XPos -= 0xC000;
            if (self->XPos <= pXPos()) {
                self->state = 5;
                self->XPos = pXPos();
                if (objectEntityList[objectLoop + 4].state < 8) {
                    objectEntityList[objectLoop + 3].state = 0;
                }
                self->values[0] = 0;
            }
        } else {
            self->state = 5;
            self->XPos = pXPos();
            objectEntityList[objectLoop + 3].state = 0;
            self->values[0] = 0;
        }
        scriptEng.tempValue[0] = objectEntityList[objectLoop + 1].XPos;
        scriptEng.tempValue[0] -= 0x300000;
        if (self->XPos > scriptEng.tempValue[0]) {
            self->values[1] = 384;
        } else {
            self->values[1] += 8;
            self->values[1] &= 511;
        }
        objectEntityList[objectLoop - 1].XPos = self->XPos;
        objectEntityList[objectLoop - 1].YPos = Sin512(self->values[1]);
        objectEntityList[objectLoop - 1].YPos <<= 9;
        objectEntityList[objectLoop - 1].YPos += self->YPos;
        objectEntityList[objectLoop - 1].YPos += 0x1C0000;
        break;
        case 5:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->state = 6;
            self->values[0] = 0;
            objectEntityList[objectLoop - 1].state = 1;
        }
        self->values[1] += 8;
        self->values[1] &= 511;
        objectEntityList[objectLoop - 1].YPos = Sin512(self->values[1]);
        objectEntityList[objectLoop - 1].YPos <<= 9;
        objectEntityList[objectLoop - 1].YPos += self->YPos;
        objectEntityList[objectLoop - 1].YPos += 0x1C0000;
        break;
        case 6:
        if (self->values[0] < 90) {
            self->values[0]++;
        } else {
            self->state = 3;
        }
        break;
    }
}

void O_R5_BombCarrier::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 6:
        DrawSprite_Frame(0);
        break;
        case 4:
        case 5:
        DrawSprite_Frame(1);
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 2;
        scriptEng.tempValue[0] += 2;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->frame++;
        self->frame &= 7;
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
