#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_BossWing.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossWing.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_BossWing::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects3.gif");
    AddSpriteFrame(-24, -32, 48, 64, 156, 1);
    AddSpriteFrame(-16, -32, 32, 64, 205, 1);
    AddSpriteFrame(-8, -32, 16, 64, 238, 1);
    AddSpriteFrame(-8, -8, 16, 16, 90, 18);
}

void O_R8_BossWing::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        self->YPos -= self->values[2];
        break;
        case 2:
        self->YPos += self->values[2];
        if (self->values[0] < 30) {
            self->values[0]++;
            self->XPos += self->values[1];
        } else {
            if (self->rotation == 0) {
                ObjectTileCollision_Script(0, 0, 32, 0);
            } else {
                ObjectTileCollision_Script(0, 0, 16, 0);
            }
            if (CheckResult() == 1) {
                self->state = 3;
                self->values[0] = 0;
                PlaySfx(globalSFXCount + 8, 0);
                HapticEffect_Script(100, 0, 0, 0);
            } else {
                self->XPos += self->values[1];
            }
        }
        break;
        case 3:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->values[6] = self->frame;
            self->state++;
        }
        break;
        case 4:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 0;
            self->type = TypeNameID("Blank Object");
        }
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 1;
        if (scriptEng.tempValue[0] == 0) {
            self->frame = 5;
        } else {
            self->frame = self->values[6];
        }
        break;
        case 5:
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        self->rotation += 508;
        self->rotation &= 511;
        self->values[2] += 0x3000;
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            self->priority = 0;
            self->values[0] = 0;
            self->state = 0;
            self->type = TypeNameID("Blank Object");
        }
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 1;
        if (scriptEng.tempValue[0] == 0) {
            self->frame = 5;
        } else {
            self->frame = 0;
        }
        break;
    }
}

void O_R8_BossWing::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 4) {
        scriptEng.tempValue[0] = 0;
        scriptEng.tempValue[1] = self->XPos;
        scriptEng.tempValue[2] = self->YPos;
        PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
        scriptEng.tempValue[0] = CheckResult();
        self->XPos = Sin512(self->rotation);
        self->XPos *= -0x100000;
        self->XPos >>= 9;
        self->XPos += scriptEng.tempValue[1];
        self->YPos = Cos512(self->rotation);
        self->YPos *= 0x100000;
        self->YPos >>= 9;
        self->YPos += scriptEng.tempValue[2];
        PlayerObjectCollision(C_TOUCH, -10, -10, 10, 10);
        scriptEng.tempValue[0] |= CheckResult();
        self->XPos = Sin512(self->rotation);
        self->XPos *= 0x100000;
        self->XPos >>= 9;
        self->XPos += scriptEng.tempValue[1];
        self->YPos = Cos512(self->rotation);
        self->YPos *= -0x100000;
        self->YPos >>= 9;
        self->YPos += scriptEng.tempValue[2];
        PlayerObjectCollision(C_TOUCH, -15, -15, 15, 15);
        scriptEng.tempValue[0] |= CheckResult();
        self->XPos = scriptEng.tempValue[1];
        self->YPos = scriptEng.tempValue[2];
        if (scriptEng.tempValue[0] == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
            if (pState() == PlayerStateID("Player_State_GotHit")) {
                scriptEng.arrayPosition[0] = self->values[7];
                objectEntityList[scriptEng.arrayPosition[0]].animation = 2;
            }
        }
    }
}

void O_R8_BossWing::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[6] = self->XPos;
    scriptEng.tempValue[7] = self->YPos;
    if (self->rotation == 256) {
        scriptEng.tempValue[6] -= 0x10000;
    }
    if (self->rotation == 384) {
        scriptEng.tempValue[7] -= 0x10000;
    }
    switch (self->frame) {
        case 0:
        case 1:
        case 2:
        DrawSpriteFX_Script(self->frame, FX_ROTATE, scriptEng.tempValue[6], scriptEng.tempValue[7]);
        self->values[3] = Sin512(self->rotation);
        self->values[3] *= -0x200000;
        self->values[3] >>= 9;
        self->values[3] += self->XPos;
        self->values[4] = Cos512(self->rotation);
        self->values[4] *= 0x200000;
        self->values[4] >>= 9;
        self->values[4] += self->YPos;
        DrawSprite_FrameXY(3, self->values[3], self->values[4]);
        break;
        case 3:
        DrawSpriteFX_Script(0, FX_ROTATE, scriptEng.tempValue[6], scriptEng.tempValue[7]);
        break;
        case 4:
        DrawSpriteFX_Script(2, FX_ROTATE, scriptEng.tempValue[6], scriptEng.tempValue[7]);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
