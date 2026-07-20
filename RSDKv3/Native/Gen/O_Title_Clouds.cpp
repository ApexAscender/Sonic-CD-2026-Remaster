#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Title_Clouds.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Clouds.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Title_Clouds::ObjectStartup()
{
    LoadSpriteSheet("Title/Clouds.gif");
    vertexCount = 0;
    faceCount = 0;
    scriptEng.arrayPosition[0] = vertexCount;
    scriptEng.arrayPosition[1] = faceCount;
    MatrixTranslateXYZM(MAT_WORLD, 0, 0, 0);
    MatrixRotateXYZM(MAT_WORLD, 0, 0, 0);
    MatrixRotateXYZM(MAT_VIEW, 8, 0, 0);
    scriptEng.arrayPosition[0] = 0;
    scriptEng.arrayPosition[1] = 0;
    scriptEng.tempValue[2] = 0;
    scriptEng.tempValue[3] = 0;
    scriptEng.tempValue[4] = 0;
    scriptEng.tempValue[5] = 0;
    while (scriptEng.tempValue[3] < 10) {
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = -0x2000;
        scriptEng.tempValue[4] = 0;
        while (scriptEng.tempValue[0] < 16) {
            vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[1];
            vertexBuffer[scriptEng.arrayPosition[0]].y = 0;
            vertexBuffer[scriptEng.arrayPosition[0]].z = scriptEng.tempValue[2];
            vertexBuffer[scriptEng.arrayPosition[0]].u = scriptEng.tempValue[4];
            vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[5];
            scriptEng.arrayPosition[0]++;
            scriptEng.tempValue[2] += 512;
            vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[1];
            vertexBuffer[scriptEng.arrayPosition[0]].y = 0;
            vertexBuffer[scriptEng.arrayPosition[0]].z = scriptEng.tempValue[2];
            vertexBuffer[scriptEng.arrayPosition[0]].u = scriptEng.tempValue[4];
            vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[5];
            vertexBuffer[scriptEng.arrayPosition[0]].v += 63;
            scriptEng.arrayPosition[0]++;
            scriptEng.tempValue[2] -= 512;
            scriptEng.tempValue[1] += 1024;
            vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[1];
            vertexBuffer[scriptEng.arrayPosition[0]].y = 0;
            vertexBuffer[scriptEng.arrayPosition[0]].z = scriptEng.tempValue[2];
            vertexBuffer[scriptEng.arrayPosition[0]].u = scriptEng.tempValue[4];
            vertexBuffer[scriptEng.arrayPosition[0]].u += 63;
            vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[5];
            scriptEng.arrayPosition[0]++;
            scriptEng.tempValue[2] += 512;
            vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[1];
            vertexBuffer[scriptEng.arrayPosition[0]].y = 0;
            vertexBuffer[scriptEng.arrayPosition[0]].z = scriptEng.tempValue[2];
            vertexBuffer[scriptEng.arrayPosition[0]].u = scriptEng.tempValue[4];
            vertexBuffer[scriptEng.arrayPosition[0]].u += 63;
            vertexBuffer[scriptEng.arrayPosition[0]].v = scriptEng.tempValue[5];
            vertexBuffer[scriptEng.arrayPosition[0]].v += 63;
            scriptEng.tempValue[4] += 64;
            scriptEng.tempValue[4] &= 255;
            scriptEng.tempValue[2] -= 512;
            scriptEng.arrayPosition[0] -= 3;
            faceBuffer[scriptEng.arrayPosition[1]].a = scriptEng.arrayPosition[0];
            faceBuffer[scriptEng.arrayPosition[1]].b = scriptEng.arrayPosition[0];
            faceBuffer[scriptEng.arrayPosition[1]].b += 2;
            faceBuffer[scriptEng.arrayPosition[1]].c = scriptEng.arrayPosition[0];
            faceBuffer[scriptEng.arrayPosition[1]].c += 1;
            faceBuffer[scriptEng.arrayPosition[1]].d = scriptEng.arrayPosition[0];
            faceBuffer[scriptEng.arrayPosition[1]].d += 3;
            faceBuffer[scriptEng.arrayPosition[1]].flags = 0;
            scriptEng.arrayPosition[0] += 4;
            scriptEng.arrayPosition[1]++;
            scriptEng.tempValue[0]++;
            vertexCount += 4;
            faceCount++;
        }
        scriptEng.tempValue[5] += 64;
        scriptEng.tempValue[5] &= 255;
        scriptEng.tempValue[2] += 512;
        scriptEng.tempValue[3]++;
    }
}

void O_Title_Clouds::ObjectDraw()
{
    Entity *self = Self();

    self->values[0] += 8;
    self->values[0] &= 0x7FF;
    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] = -scriptEng.tempValue[0];
    MatrixTranslateXYZM(MAT_WORLD, -512, 720, scriptEng.tempValue[0]);
    Draw3DScene_Script();
}

#endif // RETRO_USE_NATIVE_OBJECTS
