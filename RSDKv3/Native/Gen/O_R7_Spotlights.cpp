#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_Spotlights.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Spotlights.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_Spotlights::ObjectStartup()
{
    MatrixTranslateXYZM(MAT_WORLD, 0, 0, 0);
    MatrixTranslateXYZM(MAT_VIEW, 0, 0, 0);
    faceBuffer[0].a = 0;
    faceBuffer[0].b = 1;
    faceBuffer[0].c = 2;
    faceBuffer[0].d = 3;
    faceBuffer[0].flags = 3;
    faceBuffer[1].a = 4;
    faceBuffer[1].b = 5;
    faceBuffer[1].c = 6;
    faceBuffer[1].d = 7;
    faceBuffer[1].flags = 3;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Spotlights")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 5;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = SCREEN_CENTERX;
            switch (objectEntityList[24].propertyValue) {
                case 0:
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 128;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] <<= 16;
                scriptEng.tempValue[0] = 224;
                scriptEng.tempValue[0] <<= 8;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] += scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[0]].values[2] += 128;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 224;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] <<= 16;
                scriptEng.tempValue[0] = 224;
                scriptEng.tempValue[0] <<= 8;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] += scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[0]].values[3] += 0;
                break;
                case 2:
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 192;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] <<= 16;
                scriptEng.tempValue[0] = 128;
                scriptEng.tempValue[0] <<= 8;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] += scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[0]].values[2] += 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] <<= 16;
                scriptEng.tempValue[0] = 192;
                scriptEng.tempValue[0] <<= 8;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] += scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[0]].values[3] += 224;
                break;
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 224;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] <<= 16;
                scriptEng.tempValue[0] = 64;
                scriptEng.tempValue[0] <<= 8;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] += scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[0]].values[2] += 128;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 224;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] <<= 16;
                scriptEng.tempValue[0] = 128;
                scriptEng.tempValue[0] <<= 8;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] += scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[0]].values[3] += 192;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
    xScrollOffset = pXPos();
    xScrollOffset >>= 16;
    xScrollOffset -= SCREEN_CENTERX;
}

void O_R7_Spotlights::ObjectMain()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = GVar("Oscillation");
    scriptEng.tempValue[0] <<= 2;
    scriptEng.tempValue[1] = Sin512(scriptEng.tempValue[0]);
    scriptEng.tempValue[1] >>= 5;
    scriptEng.tempValue[1] += 64;
    scriptEng.tempValue[2] = Cos512(scriptEng.tempValue[0]);
    scriptEng.tempValue[2] >>= 5;
    scriptEng.tempValue[2] += 64;
    self->values[4] = scriptEng.tempValue[1];
    self->values[4] <<= 24;
    self->values[4] += self->values[2];
    self->values[5] = scriptEng.tempValue[2];
    self->values[5] <<= 24;
    self->values[5] += self->values[3];
    scriptEng.tempValue[0] = xScrollOffset;
    scriptEng.tempValue[0] += SCREEN_CENTERX;
    if (scriptEng.tempValue[0] > self->values[1]) {
        scriptEng.tempValue[0] -= self->values[1];
        if (scriptEng.tempValue[0] > 440) {
            self->values[1] += 880;
            self->values[0]++;
            if (self->values[0] > 4) {
                self->values[0] = 0;
            }
        }
    } else {
        scriptEng.tempValue[0] -= self->values[1];
        if (scriptEng.tempValue[0] < -440) {
            self->values[1] -= 880;
            self->values[0]--;
            if (self->values[0] < 0) {
                self->values[0] = 4;
            }
        }
    }
    self->XPos = self->values[1];
    self->XPos -= xScrollOffset;
    switch (self->values[0]) {
        case 0:
        self->drawOrder = 5;
        vertexCount = 8;
        faceCount = 2;
        self->XPos -= 48;
        faceBuffer[0].colour = self->values[4];
        faceBuffer[1].colour = self->values[4];
        scriptEng.tempValue[0] = GVar("Oscillation");
        scriptEng.tempValue[0] <<= 1;
        self->rotation = Sin512(scriptEng.tempValue[0]);
        if (self->rotation > 0) {
            self->rotation = -self->rotation;
        }
        self->rotation /= 10;
        self->rotation += 512;
        scriptEng.arrayPosition[0] = 0;
        scriptEng.tempValue[0] = -16;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 16;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = -8;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 8;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        self->XPos += 96;
        scriptEng.tempValue[0] = GVar("Oscillation");
        scriptEng.tempValue[0] <<= 1;
        self->rotation = Sin512(scriptEng.tempValue[0]);
        self->rotation /= 10;
        self->rotation += 512;
        scriptEng.tempValue[0] = -16;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 16;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = -8;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 8;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        break;
        case 1:
        self->drawOrder = 2;
        vertexCount = 4;
        faceCount = 1;
        faceBuffer[0].colour = self->values[4];
        scriptEng.tempValue[0] = GVar("Oscillation");
        scriptEng.tempValue[0] <<= 1;
        self->rotation = Sin512(scriptEng.tempValue[0]);
        self->rotation >>= 3;
        self->rotation += 512;
        scriptEng.arrayPosition[0] = 0;
        scriptEng.tempValue[0] = -16;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 16;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = -8;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 8;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        break;
        case 2:
        self->drawOrder = 5;
        vertexCount = 8;
        faceCount = 2;
        faceBuffer[0].colour = self->values[5];
        faceBuffer[1].colour = self->values[5];
        self->XPos -= 48;
        faceBuffer[0].colour = self->values[5];
        faceBuffer[1].colour = self->values[5];
        scriptEng.tempValue[0] = GVar("Oscillation");
        scriptEng.tempValue[0] <<= 1;
        self->rotation = Sin512(scriptEng.tempValue[0]);
        self->rotation >>= 4;
        self->rotation += 500;
        scriptEng.arrayPosition[0] = 0;
        scriptEng.tempValue[0] = -20;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 20;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = -10;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 10;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        self->XPos += 96;
        scriptEng.tempValue[0] = GVar("Oscillation");
        scriptEng.tempValue[0] += 32;
        scriptEng.tempValue[0] <<= 1;
        self->rotation = Sin512(scriptEng.tempValue[0]);
        self->rotation >>= 3;
        self->rotation += 508;
        scriptEng.tempValue[0] = -16;
        scriptEng.tempValue[1] = -420;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 16;
        scriptEng.tempValue[1] = -420;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = -8;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 8;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        break;
        case 3:
        self->drawOrder = 5;
        vertexCount = 4;
        faceCount = 1;
        faceBuffer[0].colour = self->values[4];
        scriptEng.tempValue[0] = 512;
        scriptEng.tempValue[0] -= GVar("Oscillation");
        scriptEng.tempValue[0] *= 3;
        self->rotation = Sin512(scriptEng.tempValue[0]);
        self->rotation /= 12;
        self->rotation += 520;
        scriptEng.arrayPosition[0] = 0;
        scriptEng.tempValue[0] = -12;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 12;
        scriptEng.tempValue[1] = -384;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = -4;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 4;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        break;
        case 4:
        self->drawOrder = 2;
        vertexCount = 8;
        faceCount = 2;
        self->XPos -= 48;
        faceBuffer[0].colour = self->values[4];
        faceBuffer[1].colour = self->values[5];
        scriptEng.tempValue[0] = GVar("Oscillation");
        scriptEng.tempValue[0] += 64;
        scriptEng.tempValue[0] <<= 2;
        self->rotation = Sin512(scriptEng.tempValue[0]);
        self->rotation /= 20;
        self->rotation += 496;
        scriptEng.arrayPosition[0] = 0;
        scriptEng.tempValue[0] = -14;
        scriptEng.tempValue[1] = -420;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 14;
        scriptEng.tempValue[1] = -420;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = -4;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 4;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        self->XPos += 96;
        scriptEng.tempValue[0] = GVar("Oscillation");
        scriptEng.tempValue[0] <<= 1;
        self->rotation = Sin512(scriptEng.tempValue[0]);
        self->rotation >>= 4;
        self->rotation += 520;
        scriptEng.tempValue[0] = -24;
        scriptEng.tempValue[1] = -420;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 24;
        scriptEng.tempValue[1] = -420;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = -16;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0] = 16;
        scriptEng.tempValue[1] = 0;
        Spotlights_UpdateCorner();
        scriptEng.arrayPosition[0]++;
        break;
    }
}

void O_R7_Spotlights::ObjectDraw()
{
    Draw3DScene_Script();
}

void O_R7_Spotlights::Spotlights_UpdateCorner()
{
    Entity *self = Self();

    scriptEng.tempValue[2] = Sin512(self->rotation);
    scriptEng.tempValue[2] *= scriptEng.tempValue[1];
    scriptEng.tempValue[3] = Cos512(self->rotation);
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    vertexBuffer[scriptEng.arrayPosition[0]].x = scriptEng.tempValue[2];
    vertexBuffer[scriptEng.arrayPosition[0]].x -= scriptEng.tempValue[3];
    vertexBuffer[scriptEng.arrayPosition[0]].x >>= 9;
    vertexBuffer[scriptEng.arrayPosition[0]].x += self->XPos;
    scriptEng.tempValue[2] = Cos512(self->rotation);
    scriptEng.tempValue[2] *= scriptEng.tempValue[1];
    scriptEng.tempValue[3] = Sin512(self->rotation);
    scriptEng.tempValue[3] *= scriptEng.tempValue[0];
    vertexBuffer[scriptEng.arrayPosition[0]].y = scriptEng.tempValue[2];
    vertexBuffer[scriptEng.arrayPosition[0]].y += scriptEng.tempValue[3];
    vertexBuffer[scriptEng.arrayPosition[0]].y >>= 9;
    vertexBuffer[scriptEng.arrayPosition[0]].y += 256;
}

const Native::NativeFunctionDef O_R7_Spotlights::funcs[1] = {
    { "Spotlights_UpdateCorner", O_R7_Spotlights::Spotlights_UpdateCorner },
};

#endif // RETRO_USE_NATIVE_OBJECTS
