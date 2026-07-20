#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Kamemusi.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Kamemusi.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Kamemusi::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-16, -15, 32, 29, 223, 34);
    AddSpriteFrame(-16, -14, 32, 28, 223, 93);
    AddSpriteFrame(-16, -15, 32, 29, 223, 34);
    AddSpriteFrame(-16, -14, 32, 28, 223, 64);
    AddSpriteFrame(-16, -17, 32, 31, 223, 122);
}

void O_R1_Kamemusi::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->frame++;
            self->frame %= 60;
            self->XPos -= 0xAAAA;
            self->values[0]--;
            if (self->values[0] == -192) {
                self->state = 1;
                self->direction = 1;
            }
            ObjectTileGrip_Script(0, 0, 14, 0);
            if (CheckResult() == 0) {
                self->state = 1;
                self->values[0] = -192;
                self->direction = 1;
            }
            if (self->values[1] > -1) {
                PlayerObjectCollision(C_TOUCH, -64, -64, 64, 64);
                if (CheckResult() == 1) {
                    self->state = 2;
                    self->drawOrder = 4;
                }
            } else {
                self->values[1]++;
            }
            break;
            case 1:
            self->frame++;
            self->frame %= 60;
            self->XPos += 0xAAAA;
            self->values[0]++;
            if (self->values[0] == 192) {
                self->state = 0;
                self->direction = 0;
            }
            ObjectTileGrip_Script(0, 0, 14, 0);
            if (CheckResult() == 0) {
                self->state = 0;
                self->values[0] = 192;
                self->direction = 0;
            }
            if (self->values[1] > -1) {
                PlayerObjectCollision(C_TOUCH, -64, -64, 64, 64);
                if (CheckResult() == 1) {
                    self->state = 2;
                    self->drawOrder = 4;
                }
            } else {
                self->values[1]++;
            }
            break;
            case 2:
            if (self->values[1] == 60) {
                CreateTempObject(TypeNameID("Bullet"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x50000;
            }
            if (self->values[1] == 62) {
                CreateTempObject(TypeNameID("Bullet"), 0, self->XPos, self->YPos);
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x20000;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x50000;
                PlaySfx(globalSFXCount + 1, 0);
            }
            if (self->values[1] == 64) {
                self->state = self->direction;
                self->values[1] = -120;
                self->drawOrder = 3;
            } else {
                self->values[1]++;
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            self->frame++;
            self->frame %= 12;
            self->XPos -= 0x3800;
            self->values[0]--;
            if (self->values[0] == -384) {
                self->state = 1;
                self->direction = 1;
            }
            ObjectTileGrip_Script(0, 0, 14, 0);
            if (CheckResult() == 0) {
                self->state = 1;
                self->values[0] = -384;
                self->direction = 1;
            }
            if (self->values[1] == 82) {
                self->state = 2;
                self->values[1] = 0;
            } else {
                self->values[1]++;
            }
            break;
            case 1:
            self->frame++;
            self->frame %= 12;
            self->XPos += 0x3800;
            self->values[0]++;
            if (self->values[0] == 384) {
                self->state = 0;
                self->direction = 0;
            }
            ObjectTileGrip_Script(0, 0, 14, 0);
            if (CheckResult() == 0) {
                self->state = 0;
                self->values[0] = 384;
                self->direction = 0;
            }
            if (self->values[1] == 82) {
                self->state = 2;
                self->values[1] = 0;
            } else {
                self->values[1]++;
            }
            break;
            case 2:
            if (self->values[1] == 14) {
                self->state = self->direction;
                self->values[1] = 0;
            } else {
                self->values[1]++;
            }
            break;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R1_Kamemusi::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -16, -14, 16, 14);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
}

void O_R1_Kamemusi::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (self->state < 2) {
            scriptEng.tempValue[0] = self->frame;
            scriptEng.tempValue[0] /= 30;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        } else {
            DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
        }
    } else {
        if (self->state < 2) {
            scriptEng.tempValue[0] = self->frame;
            scriptEng.tempValue[0] /= 6;
            scriptEng.tempValue[0] += 2;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        } else {
            DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
