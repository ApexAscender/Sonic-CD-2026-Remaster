#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_MechaBu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MechaBu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_MechaBu::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-24, -16, 48, 32, 173, 140);
    AddSpriteFrame(-23, -17, 16, 24, 156, 177);
    AddSpriteFrame(-31, -32, 24, 32, 230, 1);
    AddSpriteFrame(-31, -32, 24, 32, 173, 173);
    AddSpriteFrame(-33, -8, 24, 16, 131, 177);
    AddSpriteFrame(-37, -16, 24, 32, 230, 1);
    AddSpriteFrame(-37, -16, 24, 32, 173, 173);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Mecha Bu")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_MechaBu::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        ObjectTileCollision_Script(0, 0, 15, 0);
        if (CheckResult() == 1) {
            self->state = 1;
        } else {
            self->YPos += 0x10000;
        }
        break;
        case 1:
        if (self->values[0] < 416) {
            self->values[0]++;
            self->XPos += 0x5000;
        } else {
            self->values[0] = 0;
            self->state = 2;
        }
        ObjectTileGrip_Script(0, 0, 15, 0);
        break;
        case 2:
        if (self->values[0] < 416) {
            self->values[0]++;
            self->XPos -= 0x5000;
        } else {
            self->values[0] = 0;
            self->state = 1;
        }
        ObjectTileGrip_Script(0, 0, 15, 0);
        break;
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R8_MechaBu::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 3) {
        PlayerObjectCollision(C_TOUCH, -16, -14, 16, 14);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
        if (self->type == TypeNameID("Mecha Bu")) {
            if (self->values[4] > 59) {
                PlayerObjectCollision(C_TOUCH, -30, -32, -8, 0);
                if (CheckResult() == 1) {
                    CallScriptFunctionNamed("Player_Hit", scriptSub);
                }
            } else {
                PlayerObjectCollision(C_TOUCH, -36, -16, -14, 16);
                if (CheckResult() == 1) {
                    CallScriptFunctionNamed("Player_Hit", scriptSub);
                }
            }
        }
    }
}

void O_R8_MechaBu::ObjectDraw()
{
    Entity *self = Self();

    self->values[5]++;
    if (self->values[5] == 48) {
        self->values[5] = 0;
        PlaySfx(globalSFXCount + 1, 0);
    }
    scriptEng.tempValue[0] = self->animationTimer;
    scriptEng.tempValue[0] /= 3;
    self->animationTimer++;
    self->animationTimer %= 6;
    if (self->propertyValue == 0) {
        if (self->values[4] > 59) {
            scriptEng.tempValue[0] += 5;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
        } else {
            scriptEng.tempValue[0] += 2;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
            DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        }
        self->values[4]++;
        self->values[4] %= 120;
    } else {
        scriptEng.tempValue[0] += 5;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
