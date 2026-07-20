#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_WarpSonic.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WarpSonic.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_WarpSonic::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Items3.gif");
        AddSpriteFrame(-14, -22, 29, 44, 116, 211);
        AddSpriteFrame(-11, -22, 20, 44, 146, 211);
        AddSpriteFrame(-11, -22, 25, 44, 167, 211);
        AddSpriteFrame(-13, -22, 25, 44, 193, 211);
        AddSpriteFrame(-8, -22, 20, 44, 219, 211);
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Players/Tails2.gif");
        AddSpriteFrame(-17, -22, 24, 48, 1, 1);
        AddSpriteFrame(-11, -22, 24, 48, 26, 1);
        AddSpriteFrame(-13, -22, 24, 48, 51, 1);
        AddSpriteFrame(-7, -22, 24, 48, 76, 1);
        AddSpriteFrame(-10, -22, 21, 48, 101, 1);
    }
}

void O_WarpSonic::ObjectMain()
{
    Entity *self = Self();

    objectEntityList[2].values[3] = objectEntityList[2].values[2];
    objectEntityList[2].values[2] = objectEntityList[2].values[1];
    objectEntityList[2].values[1] = objectEntityList[2].values[0];
    objectEntityList[2].values[0] = objectEntityList[1].values[7];
    objectEntityList[1].values[7] = objectEntityList[1].values[6];
    objectEntityList[1].values[6] = objectEntityList[1].values[5];
    objectEntityList[1].values[5] = objectEntityList[1].values[4];
    objectEntityList[1].values[4] = objectEntityList[1].values[3];
    objectEntityList[1].values[3] = objectEntityList[1].values[2];
    objectEntityList[1].values[2] = objectEntityList[1].values[1];
    objectEntityList[1].values[1] = objectEntityList[1].values[0];
    objectEntityList[1].values[0] = self->YPos;
    switch (self->state) {
        case 0:
        self->YPos -= 0x80000;
        if (self->YPos < 0x780000) {
            self->YPos = 0x780000;
            self->state = 1;
            self->values[1] = 0;
        }
        break;
        case 1:
        self->values[1]++;
        if (self->values[1] == 60) {
            HapticEffect_Script(9, 0, 0, 0);
        }
        if (self->values[1] == 120) {
            self->values[1] = 0;
            self->state = 2;
            objectEntityList[0].state = 4;
        }
        break;
        case 2:
        self->YPos -= 0x80000;
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
    self->values[2]++;
    if (self->values[2] == 4) {
        self->values[2] = 0;
        scriptEng.tempValue[0] = rand() % 32;
        scriptEng.tempValue[0] -= 16;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += self->XPos;
        scriptEng.tempValue[1] = rand() % 32;
        scriptEng.tempValue[1] -= 16;
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] += self->YPos;
        CreateTempObject(TypeNameID("Warp Star"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        objectEntityList[scriptEng.arrayPosition[2]].state = 2;
        objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 32;
        objectEntityList[scriptEng.arrayPosition[2]].values[1] += 16;
    }
}

void O_WarpSonic::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0]++;
    if (scriptEng.tempValue[0] > 4) {
        scriptEng.tempValue[0] = 0;
    }
    if (self->YPos < 0x1040000) {
        self->inkEffect = 2;
        self->alpha = 160;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, objectEntityList[1].values[3]);
        self->alpha = 128;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, objectEntityList[1].values[7]);
        self->alpha = 96;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_INK, self->XPos, objectEntityList[2].values[3]);
    }
    DrawSprite_Frame(self->frame);
    self->values[0]++;
    if (self->values[0] > 2) {
        self->values[0] = 0;
        self->frame++;
        if (self->frame > 4) {
            self->frame = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
