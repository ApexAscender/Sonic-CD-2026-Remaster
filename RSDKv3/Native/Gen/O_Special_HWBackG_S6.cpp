#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_HWBackG_S6.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HWBackG_S6.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_HWBackG_S6::ObjectStartup()
{
}

void O_Special_HWBackG_S6::ObjectDraw()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] > 3) {
        self->values[0] = 0;
        self->frame++;
        self->frame %= 12;
        self->values[1] = self->frame;
        self->values[1] &= 3;
        self->values[1] <<= 7;
        self->values[2] = self->values[1];
        self->values[2] += 127;
        self->values[3] = self->frame;
        self->values[3] >>= 2;
        self->values[3] <<= 7;
        self->values[4] = self->values[3];
        self->values[4] += 127;
    }
    self->values[5] += 2;
    self->values[5] &= 511;
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[4] = self->values[5];
    scriptEng.tempValue[1] = self->values[3];
    scriptEng.tempValue[2] = self->values[4];
    scriptEng.arrayPosition[0] = 0;
    while (scriptEng.tempValue[0] < 16) {
        scriptEng.tempValue[3] = Sin512(scriptEng.tempValue[4]);
        scriptEng.tempValue[3] /= 12;
        scriptEng.tempValue[3] -= 48;
        scriptEng.tempValue[4] += 56;
        scriptEng.tempValue[4] &= 511;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[3] += 128;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[2];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[3] += 128;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[2];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[3] += 128;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[2];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[3] += 128;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[2];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0] -= 11;
        scriptEng.tempValue[1] += 8;
        scriptEng.tempValue[2] -= 8;
        scriptEng.tempValue[3] = Sin512(scriptEng.tempValue[4]);
        scriptEng.tempValue[3] /= 12;
        scriptEng.tempValue[3] -= 48;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[3] += 128;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[2];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[3] += 128;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[2];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[3] += 128;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[2];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[3] += 128;
        vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
        vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[2];
        vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0]++;
    }
    vertexCount = 256;
    faceCount = 64;
    Draw3DScene_Script();
    DrawSprite_ScreenXY(0, 0, 0);
    DrawSprite_ScreenXY(0, 256, 0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
