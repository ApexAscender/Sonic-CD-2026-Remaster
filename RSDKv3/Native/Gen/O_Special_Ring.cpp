#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_Ring.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Ring.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_Ring::ObjectStartup()
{
    LoadSpriteSheet("Special/Objects.gif");
    AddSpriteFrame(-10, -24, 20, 24, 52, 59);
    AddSpriteFrame(-7, -24, 15, 24, 73, 59);
    AddSpriteFrame(-4, -24, 9, 24, 89, 59);
    AddSpriteFrame(-7, -24, 15, 24, 99, 59);
    AddSpriteFrame(-9, -4, 18, 8, 83, 117);
}

void O_Special_Ring::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    self->YPos += self->values[2];
    self->values[0] += self->values[3];
    self->values[2] -= 0x2000;
    if (self->YPos < 0) {
        self->YPos = 0;
        self->values[2] = -self->values[2];
    }
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] -= stageLayouts[0].XPos;
    scriptEng.tempValue[0] >>= 8;
    scriptEng.tempValue[1] = self->values[0];
    scriptEng.tempValue[1] -= stageLayouts[0].ZPos;
    scriptEng.tempValue[1] >>= 8;
    scriptEng.tempValue[2] = Sin512(stageLayouts[0].angle);
    scriptEng.tempValue[2] *= scriptEng.tempValue[1];
    scriptEng.tempValue[3] = Cos512(stageLayouts[0].angle);
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    self->values[6] = scriptEng.tempValue[2];
    self->values[6] -= scriptEng.tempValue[3];
    self->values[6] >>= 9;
    scriptEng.tempValue[2] = Cos512(stageLayouts[0].angle);
    scriptEng.tempValue[2] *= scriptEng.tempValue[1];
    scriptEng.tempValue[3] = Sin512(stageLayouts[0].angle);
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    self->values[5] = scriptEng.tempValue[2];
    self->values[5] += scriptEng.tempValue[3];
    self->values[5] >>= 9;
    self->values[4]++;
    if (self->values[4] == 160) {
        self->type = TypeNameID("Blank Object");
    }
}

void O_Special_Ring::ObjectDraw()
{
    Entity *self = Self();

    if (self->values[5] > 256) {
        self->scale = 0xC00000;
        self->scale /= self->values[5];
        scriptEng.tempValue[0] = 768;
        scriptEng.tempValue[0] -= self->scale;
        scriptEng.tempValue[0] /= 6;
        scriptEng.tempValue[1] = self->values[5];
        scriptEng.tempValue[1] >>= 12;
        if (scriptEng.tempValue[0] > 0) {
            self->scale += scriptEng.tempValue[0];
            self->scale -= scriptEng.tempValue[1];
        }
        scriptEng.tempValue[0] = self->values[6];
        scriptEng.tempValue[0] *= 192;
        scriptEng.tempValue[0] /= self->values[5];
        scriptEng.tempValue[0] += SCREEN_CENTERX;
        scriptEng.tempValue[1] = stageLayouts[0].YPos;
        scriptEng.tempValue[1] -= self->YPos;
        scriptEng.tempValue[1] >>= 8;
        scriptEng.tempValue[1] *= 96;
        scriptEng.tempValue[1] /= self->values[5];
        scriptEng.tempValue[1] += 128;
        scriptEng.tempValue[2] = self->values[4];
        scriptEng.tempValue[2] &= 31;
        scriptEng.tempValue[2] >>= 3;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[2], FX_SCALE, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[1] = stageLayouts[0].YPos;
        scriptEng.tempValue[1] >>= 8;
        scriptEng.tempValue[1] *= 96;
        scriptEng.tempValue[1] /= self->values[5];
        scriptEng.tempValue[1] += 128;
        DrawSpriteScreenFX_Script(4, FX_SCALE, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
