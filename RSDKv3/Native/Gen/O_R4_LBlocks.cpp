#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_LBlocks.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LBlocks.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_LBlocks::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects3.gif");
    AddSpriteFrame(-8, -8, 16, 16, 67, 46);
    AddSpriteFrame(-16, -16, 32, 32, 34, 34);
    AddSpriteFrame(-48, -16, 32, 32, 1, 34);
    AddSpriteFrame(-16, -48, 32, 32, 34, 1);
    AddSpriteFrame(-22, -22, 44, 44, 157, 1);
    AddSpriteFrame(-44, -44, 44, 44, 112, 1);
    AddSpriteFrame(-44, 0, 44, 44, 202, 1);
    AddSpriteFrame(-16, -16, 32, 32, 34, 1);
    AddSpriteFrame(-48, -16, 32, 32, 1, 1);
    AddSpriteFrame(-16, 16, 32, 32, 34, 34);
    AddSpriteFrame(-22, -22, 44, 44, 112, 1);
    AddSpriteFrame(-44, 0, 44, 44, 67, 1);
    AddSpriteFrame(0, 0, 44, 44, 157, 1);
    AddSpriteFrame(-16, -16, 32, 32, 1, 1);
    AddSpriteFrame(-16, 16, 32, 32, 1, 34);
    AddSpriteFrame(16, -16, 32, 32, 34, 1);
    AddSpriteFrame(-22, -22, 44, 44, 67, 1);
    AddSpriteFrame(0, -44, 44, 44, 112, 1);
    AddSpriteFrame(0, 0, 44, 44, 202, 1);
    AddSpriteFrame(-16, -16, 32, 32, 1, 34);
    AddSpriteFrame(-16, -48, 32, 32, 1, 1);
    AddSpriteFrame(16, -16, 32, 32, 34, 34);
    AddSpriteFrame(-22, -22, 44, 44, 202, 1);
    AddSpriteFrame(-44, -44, 44, 44, 67, 1);
    AddSpriteFrame(0, -44, 44, 44, 157, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("L Blocks")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] <<= 3;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_LBlocks::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] < 14) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 3;
            PlaySfx(globalSFXCount + 8, 0);
        }
        break;
        case 2:
        if (self->values[0] < 14) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 4;
            PlaySfx(globalSFXCount + 8, 0);
        }
        break;
        case 3:
        if (self->values[0] < 8) {
            self->values[0]++;
            self->values[1]++;
        } else {
            self->values[0] = 0;
            self->state = 0;
            PlaySfx(globalSFXCount + 8, 0);
        }
        break;
        case 4:
        if (self->values[0] < 8) {
            self->values[0]++;
            self->values[1]--;
        } else {
            self->values[0] = 0;
            self->state = 0;
            PlaySfx(globalSFXCount + 8, 0);
        }
        break;
    }
}

void O_R4_LBlocks::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_BOX, -16, -16, 16, 16);
    if (self->state == 0) {
        scriptEng.tempValue[1] = CheckResult();
    } else {
        scriptEng.tempValue[1] = 1;
    }
    if (self->state < 3) {
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] >>= 3;
        switch (scriptEng.tempValue[0]) {
            case 0:
            PlayerObjectCollision(C_BOX, -16, -48, 16, -16);
            PlayerObjectCollision(C_BOX, -48, -16, -16, 16);
            if (CheckResult() == 1) {
                if (scriptEng.tempValue[1] == 0) {
                    self->state = 1;
                }
            }
            break;
            case 1:
            PlayerObjectCollision(C_BOX, -16, 16, 16, 48);
            PlayerObjectCollision(C_BOX, -48, -16, -16, 16);
            if (CheckResult() == 1) {
                if (scriptEng.tempValue[1] == 0) {
                    self->state = 1;
                }
            }
            break;
            case 2:
            PlayerObjectCollision(C_BOX, -16, 16, 16, 48);
            PlayerObjectCollision(C_BOX, 16, -16, 48, 16);
            if (CheckResult() == 1) {
                if (scriptEng.tempValue[1] == 0) {
                    self->state = 2;
                }
            }
            break;
            case 3:
            PlayerObjectCollision(C_BOX, -16, -48, 16, -16);
            PlayerObjectCollision(C_BOX, 16, -16, 48, 16);
            if (CheckResult() == 1) {
                if (scriptEng.tempValue[1] == 0) {
                    self->state = 2;
                }
            }
            break;
        }
    }
}

void O_R4_LBlocks::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[1];
    if (self->state == 4) {
        scriptEng.tempValue[0] += 3;
    }
    scriptEng.tempValue[0] >>= 2;
    scriptEng.tempValue[0] *= 3;
    scriptEng.tempValue[0]++;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    scriptEng.tempValue[0]++;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    scriptEng.tempValue[0]++;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
