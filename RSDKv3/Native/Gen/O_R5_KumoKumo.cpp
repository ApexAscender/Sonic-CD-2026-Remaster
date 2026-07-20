#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_KumoKumo.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from KumoKumo.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_KumoKumo::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-28, -20, 56, 36, 199, 1);
    AddSpriteFrame(-28, -16, 56, 32, 199, 38);
    AddSpriteFrame(-28, -28, 56, 52, 142, 1);
    AddSpriteFrame(-28, -20, 56, 36, 199, 71);
    AddSpriteFrame(-28, -16, 56, 32, 199, 108);
    AddSpriteFrame(-28, -28, 56, 52, 142, 54);
}

void O_R5_KumoKumo::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[1] += 0x4000;
        self->YPos += self->values[1];
        if (self->values[1] > 0) {
            ObjectTileCollision_Script(0, 0, 24, 0);
            if (CheckResult() == 1) {
                self->YPos += 0x80000;
                self->frame = 0;
                self->drawOrder = 3;
                if (self->propertyValue == 0) {
                    self->state = 1;
                } else {
                    self->state = 2;
                    self->direction = 1;
                }
            }
        }
        break;
        case 1:
        if (self->values[0] < 180) {
            self->values[0]++;
            self->frame++;
            self->frame &= 15;
        } else {
            self->YPos -= 0x80000;
            self->values[0] = 0;
            self->values[1] = -0x80000;
            self->YPos += self->values[1];
            self->values[1] += 0x4000;
            self->state = 0;
        }
        break;
        case 2:
        if (self->values[0] < 180) {
            self->values[0]++;
            self->frame++;
            self->frame &= 31;
        } else {
            self->YPos -= 0x80000;
            self->values[0] = 0;
            self->values[1] = -0x50000;
            self->YPos += self->values[1];
            self->state = 0;
        }
        break;
        case 3:
        if (self->values[0] < 62) {
            self->values[0]++;
        } else {
            CreateTempObject(TypeNameID("Kumo Kumo Web"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            if (self->direction == 0) {
                objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x30000;
            } else {
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x80000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x30000;
            }
            self->YPos -= 0x80000;
            self->values[0] = 0;
            self->values[1] = -0x80000;
            self->YPos += self->values[1];
            self->values[1] += 0x4000;
            self->state = 0;
            self->drawOrder = 4;
            PlaySfx(globalSFXCount + 2, 0);
        }
        break;
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R5_KumoKumo::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -24, -16, 24, 16);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
    if (self->state == 1) {
        if (self->direction == 0) {
            PlayerObjectCollision(C_TOUCH, -64, -32, 0, 16);
            if (CheckResult() == 1) {
                self->direction = 1;
                self->state = 3;
                self->frame = 0;
                self->values[0] = 0;
            }
        } else {
            PlayerObjectCollision(C_TOUCH, 0, -32, 64, 16);
            if (CheckResult() == 1) {
                self->direction = 0;
                self->state = 3;
                self->frame = 0;
                self->values[0] = 0;
            }
        }
    }
}

void O_R5_KumoKumo::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->propertyValue == 0) {
            DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        } else {
            DrawSpriteFX_Script(5, FX_FLIP, self->XPos, self->YPos);
        }
        break;
        case 1:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 2:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 4;
        scriptEng.tempValue[0] += 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 3:
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
