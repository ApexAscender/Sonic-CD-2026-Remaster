#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_Buzzsaw.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Buzzsaw.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_Buzzsaw::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-33, -36, 66, 68, 67, 127);
    AddSpriteFrame(-33, -36, 66, 68, 190, 154);
    AddSpriteFrame(-53, -53, 26, 26, 158, 43);
    AddSpriteFrame(-73, -73, 26, 26, 158, 43);
    AddSpriteFrame(-93, -93, 26, 26, 158, 43);
    AddSpriteFrame(-113, -113, 26, 26, 158, 43);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Buzzsaw")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue > 127) {
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue -= 128;
                objectEntityList[scriptEng.arrayPosition[0]].direction = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 74;
                objectEntityList[scriptEng.arrayPosition[0]].state = 2;
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].direction = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            }
            switch (objectEntityList[scriptEng.arrayPosition[0]].direction) {
                case 0:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x10000;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x10000;
                break;
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = -0x10000;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x10000;
                break;
                case 2:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x10000;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -0x10000;
                break;
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = -0x10000;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -0x10000;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_Buzzsaw::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 1:
        if (self->values[0] < 74) {
            self->values[0]++;
            self->values[3]++;
            self->XPos += self->values[1];
            self->YPos += self->values[2];
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 3:
        if (self->values[0] < 74) {
            self->values[0]++;
            self->values[3]--;
            self->XPos -= self->values[1];
            self->YPos -= self->values[2];
        } else {
            self->values[0] = 0;
            self->state = 0;
        }
        break;
    }
    if (self->values[4] > 0) {
        self->values[4]--;
    } else {
        PlaySfx(globalSFXCount + 1, 0);
        self->values[4] += 48;
    }
}

void O_R8_Buzzsaw::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -24, -24, 24, 24);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_Hit", scriptSub);
    }
}

void O_R8_Buzzsaw::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 1;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    self->frame++;
    self->frame &= 3;
    scriptEng.tempValue[0] = self->values[3];
    scriptEng.tempValue[0] /= 20;
    switch (scriptEng.tempValue[0]) {
        case 0:
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        break;
        case 1:
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        break;
        case 2:
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
        break;
        case 3:
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(5, FX_FLIP, self->XPos, self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
