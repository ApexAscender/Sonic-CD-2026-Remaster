#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Anton.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Anton.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Anton::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(-12, -19, 24, 32, 1, 1);
    AddSpriteFrame(-12, -20, 24, 32, 1, 1);
    AddSpriteFrame(-12, -19, 24, 32, 26, 1);
    AddSpriteFrame(-12, -20, 24, 32, 26, 1);
    AddSpriteFrame(-8, 4, 16, 16, 1, 34);
    AddSpriteFrame(-8, 4, 16, 16, 18, 34);
    AddSpriteFrame(14, -4, 8, 8, 35, 34);
    AddSpriteFrame(18, -5, 8, 8, 35, 34);
}

void O_R1_Anton::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        self->frame += 2;
        switch (self->state) {
            case 0:
            self->XPos -= 0x10000;
            self->values[0]--;
            if (self->values[0] == -128) {
                self->state = 1;
                self->direction = 1;
            }
            ObjectTileGrip_Script(0, 0, 20, 0);
            if (CheckResult() == 0) {
                self->state = 1;
                self->values[0] = -128;
                self->direction = 1;
            }
            break;
            case 1:
            self->XPos += 0x10000;
            self->values[0]++;
            if (self->values[0] == 128) {
                self->state = 0;
                self->direction = 0;
            }
            ObjectTileGrip_Script(0, 0, 20, 0);
            if (CheckResult() == 0) {
                self->state = 0;
                self->values[0] = 128;
                self->direction = 0;
            }
            break;
        }
    } else {
        self->frame++;
        switch (self->state) {
            case 0:
            self->XPos -= 0x8000;
            self->values[0]--;
            if (self->values[0] == -256) {
                self->state = 1;
                self->direction = 1;
            }
            ObjectTileGrip_Script(0, 0, 20, 0);
            if (CheckResult() == 0) {
                self->state = 1;
                self->values[0] = -256;
                self->direction = 1;
            }
            break;
            case 1:
            self->XPos += 0x8000;
            self->values[0]++;
            if (self->values[0] == 256) {
                self->state = 0;
                self->direction = 0;
            }
            ObjectTileGrip_Script(0, 0, 20, 0);
            if (CheckResult() == 0) {
                self->state = 0;
                self->values[0] = 256;
                self->direction = 0;
            }
            break;
        }
    }
    self->frame &= 15;
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R1_Anton::ObjectPlayerInteraction()
{
    PlayerObjectCollision(C_TOUCH, -12, -18, 12, 20);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    }
}

void O_R1_Anton::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 3;
    if (self->propertyValue == 0) {
        scriptEng.tempValue[0] += 4;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] -= 4;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] += 6;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    } else {
        scriptEng.tempValue[0] += 4;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] -= 2;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0] += 4;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
