#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Special_HWBackG_S1.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from HWBackG_S1.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Special_HWBackG_S1::ObjectStartup()
{
    MatrixTranslateXYZM(MAT_WORLD, 0, 0, 0);
    MatrixTranslateXYZM(MAT_VIEW, 0, 0, 0);
    activeTileLayers[0] = 3;
    LoadSpriteSheet("Special/SSBG1.gif");
    objectEntityList[31].type = TypeNameID("HW Background");
    objectEntityList[31].priority = 1;
    objectEntityList[31].drawOrder = 0;
    objectEntityList[31].values[1] = 0;
    objectEntityList[31].values[2] = 128;
    objectEntityList[31].values[3] = 0;
    objectEntityList[31].values[4] = 128;
    scriptEng.arrayPosition[0] = 0;
    scriptEng.tempValue[0] = 0;
    while (scriptEng.arrayPosition[0] < 6) {
        faceBuffer[scriptEng.arrayPosition[0]].a = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        faceBuffer[scriptEng.arrayPosition[0]].b = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        faceBuffer[scriptEng.arrayPosition[0]].c = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        faceBuffer[scriptEng.arrayPosition[0]].d = scriptEng.tempValue[0];
        scriptEng.tempValue[0]++;
        faceBuffer[scriptEng.arrayPosition[0]].flags = 1;
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.arrayPosition[0] = 0;
    while (scriptEng.arrayPosition[0] < 24) {
        vertexBuffer[scriptEng.arrayPosition[0]].z = 1;
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.arrayPosition[0] = 0;
    while (scriptEng.tempValue[0] < 128) {
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] -= 19;
        scriptEng.tempValue[0] += 128;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0] += 3;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[0];
        scriptEng.arrayPosition[0]++;
        CopyPalette(0, 1);
        LoadPalette("SS1H_PalCycle.act", 1, 208, 0, 32);
    }
}

void O_Special_HWBackG_S1::ObjectDraw()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] > 5) {
        self->values[0] = 0;
        self->frame++;
        self->frame &= 31;
        if (self->frame > 15) {
            SetActivePalette(1, 0, SCREEN_YSIZE);
        } else {
            SetActivePalette(0, 0, SCREEN_YSIZE);
        }
        self->values[1] = self->frame;
        self->values[1] &= 3;
        self->values[1] <<= 7;
        self->values[2] = self->values[1];
        self->values[2] += 127;
        self->values[3] = self->frame;
        self->values[3] &= 15;
        self->values[3] >>= 2;
        self->values[3] <<= 7;
        self->values[4] = self->values[3];
        self->values[4] += 127;
    }
    self->values[5]++;
    self->values[5] &= 1023;
    scriptEng.tempValue[4] = self->values[5];
    scriptEng.tempValue[4] >>= 1;
    scriptEng.tempValue[1] = self->values[3];
    scriptEng.arrayPosition[0] = 0;
    scriptEng.tempValue[3] = Sin512(scriptEng.tempValue[4]);
    scriptEng.tempValue[3] >>= 2;
    scriptEng.tempValue[3] -= 128;
    scriptEng.tempValue[4] += 256;
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
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
    vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
    scriptEng.arrayPosition[0]++;
    scriptEng.tempValue[3] += 128;
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
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
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
    vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
    scriptEng.arrayPosition[0]++;
    scriptEng.tempValue[3] += 128;
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
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
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
    vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
    scriptEng.arrayPosition[0]++;
    scriptEng.tempValue[3] += 128;
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
    vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
    scriptEng.arrayPosition[0] -= 19;
    scriptEng.tempValue[1] += 128;
    scriptEng.tempValue[3] = Sin512(scriptEng.tempValue[4]);
    scriptEng.tempValue[3] >>= 2;
    scriptEng.tempValue[3] -= 128;
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
    vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
    scriptEng.arrayPosition[0]++;
    scriptEng.tempValue[3] += 128;
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
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
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
    vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
    scriptEng.arrayPosition[0]++;
    scriptEng.tempValue[3] += 128;
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
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
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[1];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
    vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[3];
    scriptEng.arrayPosition[0]++;
    scriptEng.tempValue[3] += 128;
    vertexBuffer[scriptEng.arrayPosition[0]].u = self->values[2];
    vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[1];
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
    vertexCount = 24;
    faceCount = 6;
    Draw3DScene_Script();
}

#endif // RETRO_USE_NATIVE_OBJECTS
