#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_BGAnimation.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGAnimation.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_BGAnimation::ObjectStartup()
{
    activeTileLayers[0] = 9;
    LoadSpriteSheet("Menu/MenuGfx1_EN.gif");
    AddSpriteFrame(-160, -104, 320, 224, 0, 0);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BG Animation")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].inkEffect = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
    MatrixTranslateXYZM(MAT_WORLD, 0, 0, 0);
    MatrixRotateXYZM(MAT_VIEW, 0, 0, 0);
    vertexCount = 12;
    faceCount = 3;
    vertexBuffer[0].x = -0xC800;
    vertexBuffer[0].y = 0xC800;
    vertexBuffer[0].z = 256;
    vertexBuffer[1].x = 0xC00;
    vertexBuffer[1].y = 0xC800;
    vertexBuffer[1].z = 256;
    vertexBuffer[2].x = -0xC800;
    vertexBuffer[2].y = 0x3000;
    vertexBuffer[2].z = 256;
    vertexBuffer[3].x = 0xC00;
    vertexBuffer[3].y = 0x3000;
    vertexBuffer[3].z = 256;
    faceBuffer[0].a = 0;
    faceBuffer[0].b = 1;
    faceBuffer[0].c = 2;
    faceBuffer[0].d = 3;
    faceBuffer[0].flags = 2;
    faceBuffer[0].colour = 128;
    faceBuffer[0].colour <<= 16;
    scriptEng.tempValue[0] = 224;
    scriptEng.tempValue[0] <<= 8;
    faceBuffer[0].colour += scriptEng.tempValue[0];
    faceBuffer[0].colour += 64;
    faceBuffer[0].colour += 0x7F000000;
    vertexBuffer[4].x = -0xC800;
    vertexBuffer[4].y = 0x3000;
    vertexBuffer[4].z = 256;
    vertexBuffer[5].x = 0xC00;
    vertexBuffer[5].y = 0x3000;
    vertexBuffer[5].z = 256;
    vertexBuffer[6].x = -0xC800;
    vertexBuffer[6].y = -0xC800;
    vertexBuffer[6].z = 256;
    vertexBuffer[7].x = 0xC00;
    vertexBuffer[7].y = -0xC800;
    vertexBuffer[7].z = 256;
    faceBuffer[1].a = 4;
    faceBuffer[1].b = 5;
    faceBuffer[1].c = 6;
    faceBuffer[1].d = 7;
    faceBuffer[1].flags = 2;
    faceBuffer[1].colour = 224;
    faceBuffer[1].colour <<= 16;
    scriptEng.tempValue[0] = 160;
    scriptEng.tempValue[0] <<= 8;
    faceBuffer[1].colour += scriptEng.tempValue[0];
    faceBuffer[1].colour += 96;
    faceBuffer[1].colour += 0x7F000000;
    vertexBuffer[8].x = 0xB00;
    vertexBuffer[8].y = 0xC800;
    vertexBuffer[8].z = 256;
    vertexBuffer[9].x = 0xC800;
    vertexBuffer[9].y = 0xC800;
    vertexBuffer[9].z = 256;
    vertexBuffer[10].x = 0xB00;
    vertexBuffer[10].y = -0xC800;
    vertexBuffer[10].z = 256;
    vertexBuffer[11].x = 0xC800;
    vertexBuffer[11].y = -0xC800;
    vertexBuffer[11].z = 256;
    faceBuffer[2].a = 8;
    faceBuffer[2].b = 9;
    faceBuffer[2].c = 10;
    faceBuffer[2].d = 11;
    faceBuffer[2].flags = 2;
    faceBuffer[2].colour = 128;
    faceBuffer[2].colour <<= 16;
    scriptEng.tempValue[0] = 128;
    scriptEng.tempValue[0] <<= 8;
    faceBuffer[2].colour += scriptEng.tempValue[0];
    faceBuffer[2].colour += 224;
    faceBuffer[2].colour += 0x7F000000;
}

void O_Menu_BGAnimation::ObjectDraw()
{
    Entity *self = Self();

    self->values[0]++;
    self->values[0] &= 1023;
    self->values[1] = self->values[0];
    self->values[1] >>= 1;
    self->values[4] = Sin512(self->values[1]);
    self->values[4] += 0x5000;
    MatrixTranslateXYZM(MAT_WORLD, 0, 0, self->values[4]);
    scriptEng.tempValue[0] = self->values[1];
    MatrixRotateXYZM(MAT_VIEW, 0, 0, scriptEng.tempValue[0]);
    Draw3DScene_Script();
    self->values[2] = SCREEN_CENTERX;
    self->values[2] -= 4;
    DrawSpriteScreenFX_Script(0, FX_INK, self->values[2], SCREEN_CENTERY);
    self->values[3] = SCREEN_CENTERX;
    self->values[3] += 4;
    DrawSpriteScreenFX_Script(0, FX_INK, self->values[3], SCREEN_CENTERY);
}

#endif // RETRO_USE_NATIVE_OBJECTS
