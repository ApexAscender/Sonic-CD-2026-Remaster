#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_BossBubble1.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossBubble1.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_BossBubble1::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-4, -4, 8, 8, 212, 61);
    AddSpriteFrame(-4, -4, 8, 8, 212, 70);
    AddSpriteFrame(-4, -4, 8, 8, 246, 18);
    AddSpriteFrame(-8, -8, 16, 16, 116, 181);
    AddSpriteFrame(-8, -8, 16, 16, 116, 198);
}

void O_R4_BossBubble1::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->frame < 4) {
            self->values[0]++;
            if (self->values[0] > 9) {
                if (self->frame < 3) {
                    self->values[0] = 0;
                }
                self->frame++;
            }
        }
        self->YPos -= 0x18000;
        self->XPos = Sin512(self->values[1]);
        self->XPos <<= self->values[4];
        self->XPos += self->values[2];
        self->values[1] += 4;
        self->values[1] &= 511;
        if (self->values[6] != 0) {
            scriptEng.arrayPosition[0] = self->values[5];
            scriptEng.tempValue[0] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            scriptEng.tempValue[0] += self->values[6];
            if (self->YPos < scriptEng.tempValue[0]) {
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] -= objectEntityList[scriptEng.arrayPosition[0]].XPos;
                if (scriptEng.tempValue[0] < 0) {
                    scriptEng.tempValue[0] = -scriptEng.tempValue[0];
                }
                scriptEng.tempValue[0] >>= 19;
                switch (scriptEng.tempValue[0]) {
                    case 0:
                    self->values[7] = 4;
                    break;
                    case 1:
                    self->values[7] = 5;
                    break;
                    case 2:
                    self->values[7] = 6;
                    break;
                    case 3:
                    self->values[7] = 7;
                    break;
                    case 4:
                    case 5:
                    case 6:
                    self->values[7] = 8;
                    break;
                }
                self->state = 1;
                self->values[1] = 0;
                self->values[2] = self->XPos;
                self->values[3] = self->YPos;
            }
        }
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
    } else {
        scriptEng.arrayPosition[0] = self->values[5];
        scriptEng.tempValue[0] = self->values[2];
        scriptEng.tempValue[0] -= objectEntityList[scriptEng.arrayPosition[0]].XPos;
        if (scriptEng.tempValue[0] < -0x1A0000) {
            scriptEng.tempValue[0] += 0x10000;
            self->values[2] += 0x10000;
        }
        if (scriptEng.tempValue[0] > 0x1A0000) {
            scriptEng.tempValue[0] -= 0x10000;
            self->values[2] -= 0x10000;
        }
        scriptEng.tempValue[0] >>= 8;
        scriptEng.tempValue[1] = self->values[3];
        scriptEng.tempValue[1] -= objectEntityList[scriptEng.arrayPosition[0]].YPos;
        if (scriptEng.tempValue[1] < -0x1A0000) {
            scriptEng.tempValue[1] += 0x10000;
            self->values[3] += 0x10000;
        }
        if (scriptEng.tempValue[1] > 0x1A0000) {
            scriptEng.tempValue[1] -= 0x10000;
            self->values[3] -= 0x10000;
        }
        scriptEng.tempValue[1] >>= 8;
        scriptEng.tempValue[2] = Sin512(self->values[1]);
        scriptEng.tempValue[2] *= scriptEng.tempValue[1];
        scriptEng.tempValue[3] = Cos512(self->values[1]);
        scriptEng.tempValue[3] *= scriptEng.tempValue[0];
        self->XPos = scriptEng.tempValue[2];
        self->XPos += scriptEng.tempValue[3];
        self->XPos >>= 1;
        self->XPos += objectEntityList[scriptEng.arrayPosition[0]].XPos;
        scriptEng.tempValue[2] = Cos512(self->values[1]);
        scriptEng.tempValue[2] *= scriptEng.tempValue[1];
        scriptEng.tempValue[3] = Sin512(self->values[1]);
        scriptEng.tempValue[3] *= scriptEng.tempValue[0];
        self->YPos = scriptEng.tempValue[2];
        self->YPos -= scriptEng.tempValue[3];
        self->YPos >>= 1;
        self->YPos += objectEntityList[scriptEng.arrayPosition[0]].YPos;
        self->values[1] += self->values[7];
        self->values[1] &= 511;
        if (objectEntityList[scriptEng.arrayPosition[0]].state == 4) {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R4_BossBubble1::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
