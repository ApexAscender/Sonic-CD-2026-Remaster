#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TAttack_SRecords.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SRecords.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TAttack_SRecords::ObjectStartup()
{
    LoadSpriteSheet("TAttack/TimeAttack.gif");
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
    AddSpriteFrame(-26, 17, 54, 32, 1, 797);
    AddSpriteFrame(-20, 49, 38, 16, 368, 593);
    AddSpriteFrame(-20, 49, 40, 15, 366, 610);
    AddSpriteFrame(-20, 49, 40, 15, 422, 655);
    AddSpriteFrame(-20, 49, 40, 15, 422, 671);
    AddSpriteFrame(-20, 49, 40, 15, 422, 731);
    AddSpriteFrame(-20, 49, 40, 15, 422, 747);
    AddSpriteFrame(-20, 49, 40, 15, 422, 763);
    AddSpriteFrame(-60, 0, 224, 192, 81, 831);
    AddSpriteFrame(-36, 0, 44, 8, 306, 864);
    AddSpriteFrame(8, 0, 28, 8, 390, 864);
    AddSpriteFrame(-60, 0, 112, 8, 306, 846);
}

void O_TAttack_SRecords::ObjectMain()
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

void O_TAttack_SRecords::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(18);
    DrawSprite_Frame(10);
    switch (self->propertyValue) {
        case 0:
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 1].propertyValue;
        scriptEng.tempValue[0] += 11;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 1:
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 2].propertyValue;
        scriptEng.tempValue[0] += 11;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 2:
        scriptEng.tempValue[0] = objectEntityList[objectLoop - 3].propertyValue;
        scriptEng.tempValue[0] += 11;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
    }
    scriptEng.arrayPosition[0] = scriptEng.tempValue[0];
    scriptEng.arrayPosition[0] -= 11;
    scriptEng.arrayPosition[0] *= 18;
    scriptEng.tempValue[0] = self->propertyValue;
    scriptEng.tempValue[0] *= 6;
    scriptEng.arrayPosition[0] += scriptEng.tempValue[0];
    scriptEng.arrayPosition[0] += 49;
    scriptEng.tempValue[1] = self->YPos;
    scriptEng.tempValue[1] >>= 16;
    scriptEng.tempValue[1] += 97;
    SRecords_DrawRecords();
    scriptEng.tempValue[1] += 24;
    scriptEng.arrayPosition[0] += 2;
    SRecords_DrawRecords();
    scriptEng.tempValue[1] += 24;
    scriptEng.arrayPosition[0] += 2;
    SRecords_DrawRecords();
    DrawSprite_Frame(21);
    switch (objectEntityList[0].state) {
        case 7:
        switch (objectEntityList[0].values[5]) {
            case 0:
            DrawSprite_Frame(19);
            break;
            case 2:
            DrawSprite_Frame(20);
            break;
        }
        break;
        case 10:
        scriptEng.tempValue[0] = objectEntityList[0].values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        if (scriptEng.tempValue[0] == 0) {
            DrawSprite_Frame(20);
        }
        break;
        case 11:
        DrawSprite_Frame(20);
        break;
        case 13:
        scriptEng.tempValue[0] = objectEntityList[0].values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        if (scriptEng.tempValue[0] == 0) {
            DrawSprite_Frame(19);
        }
        break;
    }
}

void O_TAttack_SRecords::SRecords_DrawRecords()
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
    DrawNumbers_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[1], 2, 8, 1);
    scriptEng.tempValue[0] += 24;
    DrawNumbers_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[2], 2, 8, 1);
    scriptEng.tempValue[0] += 24;
    DrawNumbers_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], self->values[3], 2, 8, 1);
}

const Native::NativeFunctionDef O_TAttack_SRecords::funcs[1] = {
    { "SRecords_DrawRecords", O_TAttack_SRecords::SRecords_DrawRecords },
};

#endif // RETRO_USE_NATIVE_OBJECTS
