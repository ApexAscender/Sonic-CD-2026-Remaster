#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TAttack_SpecialIcon.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpecialIcon.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TAttack_SpecialIcon::ObjectStartup()
{
    LoadSpriteSheet("TAttack/TimeAttack.gif");
    AddSpriteFrame(0, 0, 6, 8, 330, 577);
    AddSpriteFrame(0, 0, 6, 8, 337, 577);
    AddSpriteFrame(0, 0, 6, 8, 344, 577);
    AddSpriteFrame(0, 0, 6, 8, 351, 577);
    AddSpriteFrame(0, 0, 6, 8, 330, 586);
    AddSpriteFrame(0, 0, 6, 8, 337, 586);
    AddSpriteFrame(0, 0, 6, 8, 344, 586);
    AddSpriteFrame(0, 0, 6, 8, 351, 586);
    AddSpriteFrame(0, 0, 6, 8, 330, 595);
    AddSpriteFrame(0, 0, 6, 8, 337, 595);
    AddSpriteFrame(-34, -45, 68, 90, 1, 609);
    AddSpriteFrame(-32, 15, 64, 16, 66, 764);
    AddSpriteFrame(-32, 15, 64, 16, 131, 764);
    AddSpriteFrame(-32, 15, 64, 16, 196, 764);
    AddSpriteFrame(-32, 15, 64, 16, 261, 764);
    AddSpriteFrame(-32, 15, 64, 16, 66, 780);
    AddSpriteFrame(-32, 15, 64, 16, 131, 780);
    AddSpriteFrame(-32, 15, 64, 16, 196, 780);
    AddSpriteFrame(-32, 15, 64, 16, 265, 593);
    AddSpriteFrame(-32, 31, 64, 13, 70, 638);
    AddSpriteFrame(-32, 31, 64, 13, 70, 652);
    AddSpriteFrame(-35, -46, 70, 92, 441, 860);
    AddSpriteFrame(-29, -22, 56, 21, 223, 679);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Special Icon")) {
            objectEntityList[scriptEng.arrayPosition[0]].frame = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].frame += 11;
            objectEntityList[scriptEng.arrayPosition[0]].rotation = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].rotation <<= 8;
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue > 3) {
                objectEntityList[scriptEng.arrayPosition[0]].rotation += 256;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_TAttack_SpecialIcon::ObjectMain()
{
}

void O_TAttack_SpecialIcon::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(10);
    self->rotation++;
    self->rotation &= 511;
    scriptEng.tempValue[0] = Cos512(self->rotation);
    scriptEng.tempValue[0] >>= 4;
    scriptEng.tempValue[1] = Sin512(self->rotation);
    scriptEng.tempValue[1] >>= 4;
    switch (self->propertyValue) {
        case 0:
        scriptEng.tempValue[0] += 64;
        scriptEng.tempValue[1] += 364;
        break;
        case 1:
        scriptEng.tempValue[0] += 192;
        scriptEng.tempValue[1] += 364;
        break;
        case 2:
        scriptEng.tempValue[0] += 320;
        scriptEng.tempValue[1] += 364;
        break;
        case 3:
        scriptEng.tempValue[0] += 448;
        scriptEng.tempValue[1] += 364;
        break;
        case 4:
        scriptEng.tempValue[0] += 64;
        scriptEng.tempValue[1] += 508;
        break;
        case 5:
        scriptEng.tempValue[0] += 192;
        scriptEng.tempValue[1] += 508;
        break;
        case 6:
        scriptEng.tempValue[0] += 320;
        scriptEng.tempValue[1] += 508;
        break;
    }
    if (self->propertyValue < 7) {
        vertexBuffer[0].x = self->XPos;
        vertexBuffer[0].x >>= 16;
        vertexBuffer[0].x -= 32;
        vertexBuffer[0].u = scriptEng.tempValue[0];
        vertexBuffer[0].u -= 32;
        vertexBuffer[0].y = self->YPos;
        vertexBuffer[0].y >>= 16;
        vertexBuffer[0].y -= 43;
        vertexBuffer[0].v = scriptEng.tempValue[1];
        vertexBuffer[0].v -= 43;
        vertexBuffer[1].x = self->XPos;
        vertexBuffer[1].x >>= 16;
        vertexBuffer[1].x += 31;
        vertexBuffer[1].u = scriptEng.tempValue[0];
        vertexBuffer[1].u += 31;
        vertexBuffer[1].y = vertexBuffer[0].y;
        vertexBuffer[1].v = vertexBuffer[0].v;
        vertexBuffer[2].x = vertexBuffer[0].x;
        vertexBuffer[2].u = vertexBuffer[0].u;
        vertexBuffer[2].y = self->YPos;
        vertexBuffer[2].y >>= 16;
        vertexBuffer[2].y += 24;
        vertexBuffer[2].v = scriptEng.tempValue[1];
        vertexBuffer[2].v += 24;
        vertexBuffer[3].x = vertexBuffer[1].x;
        vertexBuffer[3].u = vertexBuffer[1].u;
        vertexBuffer[3].y = vertexBuffer[2].y;
        vertexBuffer[3].v = vertexBuffer[2].v;
        Draw3DScene_Script();
        DrawSprite_Frame(19);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[0] -= 24;
        scriptEng.tempValue[1] = self->YPos;
        scriptEng.tempValue[1] >>= 16;
        scriptEng.tempValue[1] += 34;
        DrawNumbers_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[1], 2, 6, 1);
        scriptEng.tempValue[0] += 16;
        DrawNumbers_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[2], 2, 6, 1);
        scriptEng.tempValue[0] += 19;
        DrawNumbers_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[3], 2, 6, 1);
    } else {
        DrawSprite_Frame(20);
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] >>= 16;
        scriptEng.tempValue[0] -= 18;
        scriptEng.tempValue[1] = self->YPos;
        scriptEng.tempValue[1] >>= 16;
        scriptEng.tempValue[1] += 34;
        DrawNumbers_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[1], 3, 6, 1);
        scriptEng.tempValue[0] += 16;
        DrawNumbers_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[2], 2, 6, 1);
        scriptEng.tempValue[0] += 19;
        DrawNumbers_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[3], 2, 6, 1);
        DrawSprite_Frame(22);
    }
    DrawSprite_Frame(self->frame);
    if (self->state == 1) {
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        if (scriptEng.tempValue[0] == 0) {
            if (objectEntityList[0].values[3] == self->propertyValue) {
                DrawSprite_Frame(21);
            }
        }
        self->values[0]++;
        if (self->values[0] == 30) {
            self->values[0] = 0;
            self->state = 0;
            if (self->propertyValue == 7) {
                objectEntityList[0].state = 4;
            } else {
                objectEntityList[0].state = 5;
                objectEntityList[0].values[2] = -1;
            }
        }
    } else {
        if (objectEntityList[0].state == 2) {
            if (objectEntityList[0].values[3] == self->propertyValue) {
                DrawSprite_Frame(21);
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
