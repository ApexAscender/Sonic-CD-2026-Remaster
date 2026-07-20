#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TAttack_Records.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Records.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TAttack_Records::ObjectStartup()
{
    LoadSpriteSheet("TAttack/TimeAttack.gif");
    AddSpriteFrame(0, 0, 8, 16, 136, 638);
    AddSpriteFrame(0, 0, 8, 16, 145, 638);
    AddSpriteFrame(0, 0, 8, 16, 154, 638);
    AddSpriteFrame(0, 0, 8, 16, 163, 638);
    AddSpriteFrame(0, 0, 8, 16, 172, 638);
    AddSpriteFrame(0, 0, 8, 16, 181, 638);
    AddSpriteFrame(0, 0, 8, 16, 190, 638);
    AddSpriteFrame(0, 0, 8, 16, 199, 638);
    AddSpriteFrame(0, 0, 8, 16, 208, 638);
    AddSpriteFrame(0, 0, 8, 16, 217, 638);
    AddSpriteFrame(0, 0, 8, 16, 226, 638);
    AddSpriteFrame(0, 0, 8, 16, 235, 638);
    AddSpriteFrame(0, 0, 8, 16, 244, 638);
    AddSpriteFrame(0, 0, 8, 16, 253, 638);
    AddSpriteFrame(0, 0, 8, 16, 262, 638);
    AddSpriteFrame(0, 0, 8, 16, 280, 638);
    AddSpriteFrame(0, 0, 8, 16, 289, 638);
    AddSpriteFrame(0, 0, 8, 16, 298, 638);
    AddSpriteFrame(0, 0, 8, 16, 307, 638);
    AddSpriteFrame(0, 0, 8, 16, 316, 638);
    AddSpriteFrame(0, 0, 8, 16, 325, 638);
    AddSpriteFrame(0, 0, 8, 16, 334, 638);
    AddSpriteFrame(0, 0, 8, 16, 343, 638);
    AddSpriteFrame(0, 0, 8, 16, 352, 638);
    AddSpriteFrame(0, 0, 8, 16, 361, 638);
    AddSpriteFrame(0, 0, 8, 16, 361, 638);
    AddSpriteFrame(0, 0, 8, 16, 370, 638);
    AddSpriteFrame(0, 0, 8, 16, 379, 638);
    AddSpriteFrame(0, 0, 8, 16, 388, 638);
    AddSpriteFrame(0, 0, 8, 16, 397, 638);
    AddSpriteFrame(0, 0, 8, 16, 406, 638);
    AddSpriteFrame(0, 0, 8, 16, 415, 638);
    AddSpriteFrame(0, 0, 8, 16, 424, 638);
    AddSpriteFrame(0, 0, 8, 16, 433, 638);
    AddSpriteFrame(0, 0, 8, 16, 442, 638);
    AddSpriteFrame(0, 0, 8, 16, 451, 638);
    AddSpriteFrame(-32, 17, 64, 32, 1, 731);
    AddSpriteFrame(-32, 17, 65, 32, 66, 731);
    AddSpriteFrame(-30, 17, 60, 32, 132, 731);
    AddSpriteFrame(-35, 17, 70, 32, 193, 731);
    AddSpriteFrame(-38, 17, 77, 32, 264, 731);
    AddSpriteFrame(-34, 17, 68, 32, 342, 731);
    AddSpriteFrame(-32, 17, 64, 32, 1, 764);
    AddSpriteFrame(-32, 17, 64, 32, 1, 764);
    AddSpriteFrame(-20, 49, 38, 16, 368, 593);
    AddSpriteFrame(-20, 49, 40, 15, 366, 610);
    AddSpriteFrame(-20, 49, 40, 15, 422, 655);
    AddSpriteFrame(-60, 0, 224, 192, 81, 831);
    AddSpriteFrame(-60, 0, 44, 8, 306, 864);
    AddSpriteFrame(-16, 0, 40, 8, 350, 864);
    AddSpriteFrame(24, 0, 28, 8, 390, 864);
    AddSpriteFrame(-60, 0, 112, 8, 306, 855);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Records")) {
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] += 76;
            scriptEng.tempValue[0] <<= 16;
            objectEntityList[scriptEng.arrayPosition[0]].XPos = scriptEng.tempValue[0];
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_TAttack_Records::ObjectMain()
{
    Entity *self = Self();

    self->YPos = self->propertyValue;
    self->YPos *= 192;
    self->YPos -= objectEntityList[0].values[4];
    if (self->YPos < -384) {
        self->YPos += 576;
    }
    self->YPos += 224;
    self->YPos <<= 16;
}

void O_TAttack_Records::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(47);
    switch (self->propertyValue) {
        case 0:
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 1].propertyValue;
        scriptEng.tempValue[0] += 36;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSprite_Frame(44);
        break;
        case 1:
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 2].propertyValue;
        scriptEng.tempValue[0] += 36;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSprite_Frame(45);
        break;
        case 2:
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 3].propertyValue;
        scriptEng.tempValue[0] += 36;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        DrawSprite_Frame(46);
        break;
    }
    scriptEng.arrayPosition[0] = scriptEng.tempValue[0];
    scriptEng.arrayPosition[0] -= 36;
    scriptEng.arrayPosition[0] *= 18;
    scriptEng.tempValue[0] = self->propertyValue;
    scriptEng.tempValue[0] *= 6;
    scriptEng.arrayPosition[0] += scriptEng.tempValue[0];
    scriptEng.arrayPosition[0] += 48;
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[1] >>= 16;
    scriptEng.tempValue[1] += 97;
    Records_DrawRecords();
    scriptEng.tempValue[1] += 24;
    scriptEng.arrayPosition[0] += 2;
    Records_DrawRecords();
    scriptEng.tempValue[1] += 24;
    scriptEng.arrayPosition[0] += 2;
    Records_DrawRecords();
    switch (objectEntityList[0].state) {
        case 7:
        switch (objectEntityList[0].values[5]) {
            case 0:
            DrawSprite_Frame(48);
            break;
            case 1:
            DrawSprite_Frame(49);
            break;
            case 2:
            DrawSprite_Frame(50);
            break;
        }
        break;
        case 10:
        scriptEng.tempValue[0] = objectEntityList[0].values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        if (scriptEng.tempValue[0] == 0) {
            DrawSprite_Frame(50);
        }
        break;
        case 11:
        DrawSprite_Frame(50);
        break;
        case 13:
        scriptEng.tempValue[0] = objectEntityList[0].values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        if (scriptEng.tempValue[0] == 0) {
            DrawSprite_Frame(48);
        }
        break;
    }
}

void O_TAttack_Records::Records_DrawRecords()
{
    Entity *self = Self();

    self->values[1] = saveRAM[scriptEng.arrayPosition[0]];
    self->values[1] /= 6000;
    self->values[2] = saveRAM[scriptEng.arrayPosition[0]];
    self->values[2] /= 100;
    self->values[2] %= 60;
    self->values[3] = saveRAM[scriptEng.arrayPosition[0]];
    self->values[3] %= 100;
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[0] -= 16;
    DrawNumbers_Script(26, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[1], 2, 8, 1);
    scriptEng.tempValue[0] += 24;
    DrawNumbers_Script(26, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[2], 2, 8, 1);
    scriptEng.tempValue[0] += 24;
    DrawNumbers_Script(26, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[3], 2, 8, 1);
}

const Native::NativeFunctionDef O_TAttack_Records::funcs[1] = {
    { "Records_DrawRecords", O_TAttack_Records::Records_DrawRecords },
};

#endif // RETRO_USE_NATIVE_OBJECTS
