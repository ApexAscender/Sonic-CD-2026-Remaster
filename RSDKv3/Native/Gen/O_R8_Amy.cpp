#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_Amy.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Amy.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_Amy::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects3.gif");
    AddSpriteFrame(-16, -20, 32, 40, 124, 174);
    AddSpriteFrame(-16, -20, 32, 40, 157, 174);
    AddSpriteFrame(-16, -20, 32, 40, 190, 174);
    AddSpriteFrame(-16, -20, 32, 40, 223, 174);
    AddSpriteFrame(-16, -20, 32, 40, 138, 215);
    AddSpriteFrame(-16, -20, 32, 40, 171, 215);
    AddSpriteFrame(-13, -20, 26, 40, 204, 215);
    AddSpriteFrame(-12, -20, 24, 40, 231, 215);
}

void O_R8_Amy::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->frame = self->values[0];
        self->frame >>= 2;
        self->values[0]++;
        self->values[0] %= 24;
        self->XPos += 0x14000;
        ObjectTileGrip_Script(0, 0, 19, 0);
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 1].XPos;
        scriptEng.tempValue[0] -= 0x600000;
        if (self->XPos > scriptEng.tempValue[0]) {
            self->frame = 6;
            self->XPos = scriptEng.tempValue[0];
            self->values[2] = -0x30000;
            self->state++;
        }
        break;
        case 1:
        self->values[2] += 0x4000;
        self->YPos += self->values[2];
        ObjectTileCollision_Script(0, 0, 19, 0);
        if (self->values[2] > 0) {
            self->frame = 7;
        }
        if (CheckResult() == 1) {
            self->frame = 6;
            self->values[2] = -0x30000;
            self->state++;
        }
        break;
        case 2:
        self->values[2] += 0x4000;
        self->YPos += self->values[2];
        ObjectTileCollision_Script(0, 0, 19, 0);
        if (self->values[2] > 0) {
            self->frame = 7;
        }
        if (CheckResult() == 1) {
            self->values[2] = 0;
            self->state++;
        }
        break;
        case 3:
        self->frame = self->values[0];
        self->frame >>= 2;
        self->values[0]++;
        self->values[0] %= 24;
        self->XPos += 0x14000;
        ObjectTileGrip_Script(0, 0, 19, 0);
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 1].XPos;
        scriptEng.tempValue[0] -= 0x100000;
        if (self->XPos > scriptEng.tempValue[0]) {
            objectEntityList[objectLoop + 1].type = TypeNameID("FadeScreen");
            self->state++;
        }
        break;
        case 4:
        self->frame = self->values[0];
        self->frame >>= 2;
        self->values[0]++;
        self->values[0] %= 24;
        self->XPos += 0x14000;
        ObjectTileGrip_Script(0, 0, 19, 0);
        break;
    }
}

void O_R8_Amy::ObjectDraw()
{
    Entity *self = Self();

    if (playerListPos == 0) {
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
