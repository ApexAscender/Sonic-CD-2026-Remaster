#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_EggmanStatue.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from EggmanStatue.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_EggmanStatue::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects3.gif");
    AddSpriteFrame(-20, -28, 40, 56, 81, 181);
}

void O_R6_EggmanStatue::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        if (scriptEng.tempValue[0] == 0) {
            scriptEng.tempValue[0] = rand() % 32;
            scriptEng.tempValue[0] -= 16;
            scriptEng.tempValue[0] <<= 16;
            scriptEng.tempValue[0] += self->XPos;
            scriptEng.tempValue[1] = rand() % 48;
            scriptEng.tempValue[1] -= 24;
            scriptEng.tempValue[1] <<= 16;
            scriptEng.tempValue[1] += self->YPos;
            CreateTempObject(TypeNameID("Explosion"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            PlaySfx(22, 0);
        }
        self->values[0]++;
        if (self->values[0] == 40) {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        self->values[0]++;
        if (self->values[0] == 60) {
            self->values[0] = 0;
            EggmanStatue_HandleBombDrop();
            self->type = TypeNameID("Blank Object");
        }
        break;
    }
}

void O_R6_EggmanStatue::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
        scriptEng.tempValue[0] = CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            PlayerObjectCollision(C_TOUCH, -16, -24, 16, 24);
            if (CheckResult() == 1) {
                self->state = 1;
            }
        }
    }
}

void O_R6_EggmanStatue::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 2) {
        DrawSprite_Frame(0);
    }
}

void O_R6_EggmanStatue::EggmanStatue_HandleBombDrop()
{
    Entity *self = Self();

    scriptEng.tempValue[2] = self->YPos;
    scriptEng.tempValue[2] += 0x260000;
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x180000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xE00000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x80000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x600000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x80000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xA00000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x180000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x1200000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x280000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x1200000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x380000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x600000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x480000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x600000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x580000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x1200000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x680000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x600000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
    CreateTempObject(TypeNameID("Statue Bomb"), 0, self->XPos, self->YPos);
    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x780000;
    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xE00000;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[2];
}

const Native::NativeFunctionDef O_R6_EggmanStatue::funcs[1] = {
    { "EggmanStatue_HandleBombDrop", O_R6_EggmanStatue::EggmanStatue_HandleBombDrop },
};

#endif // RETRO_USE_NATIVE_OBJECTS
