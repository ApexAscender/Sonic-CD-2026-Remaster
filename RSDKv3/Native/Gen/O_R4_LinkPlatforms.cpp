#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_LinkPlatforms.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LinkPlatforms.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_LinkPlatforms::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 180, 52);
    AddSpriteFrame(-32, -8, 64, 16, 147, 69);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Link Platforms")) {
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 112;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 16;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 32;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 48;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 96;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 80;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 64;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 128;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
                break;
                case 2:
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 112;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 16;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 32;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 48;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 96;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 80;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 64;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -2;
                scriptEng.arrayPosition[0]++;
                objectEntityList[scriptEng.arrayPosition[0]].values[0] = 128;
                objectEntityList[scriptEng.arrayPosition[0]].frame = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -2;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_LinkPlatforms::ObjectMain()
{
    Entity *self = Self();

    self->values[0] += self->values[5];
    if (self->values[0] < 0) {
        self->values[0] += 512;
    }
    self->values[0] &= 511;
    scriptEng.tempValue[1] = 96;
    self->values[3] = Cos512(self->values[0]);
    self->values[3] *= scriptEng.tempValue[1];
    self->values[3] <<= 7;
    self->values[3] += self->XPos;
    self->values[3] &= 0xFFFF0000;
    self->values[3] -= self->values[1];
    self->values[4] = Sin512(self->values[0]);
    self->values[4] *= scriptEng.tempValue[1];
    self->values[4] <<= 7;
    self->values[4] += self->YPos;
    self->values[4] &= 0xFFFF0000;
    self->values[4] -= self->values[2];
}

void O_R4_LinkPlatforms::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->frame == 1) {
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        self->XPos = self->values[1];
        self->YPos = self->values[2];
        PlayerObjectCollision(C_PLATFORM, -32, -8, 32, 8);
        if (CheckResult() == 1) {
            pXPos() += self->values[3];
            pYPos() += self->values[4];
        }
        self->XPos = scriptEng.tempValue[0];
        self->YPos = scriptEng.tempValue[1];
    }
}

void O_R4_LinkPlatforms::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[1] = 96;
    self->values[1] = Cos512(self->values[0]);
    self->values[1] *= scriptEng.tempValue[1];
    self->values[1] <<= 7;
    self->values[1] += self->XPos;
    self->values[1] &= 0xFFFF0000;
    self->values[2] = Sin512(self->values[0]);
    self->values[2] *= scriptEng.tempValue[1];
    self->values[2] <<= 7;
    self->values[2] += self->YPos;
    self->values[2] &= 0xFFFF0000;
    DrawSprite_FrameXY(self->frame, self->values[1], self->values[2]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
