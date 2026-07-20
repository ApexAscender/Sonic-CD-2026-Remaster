#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_WaterBurst.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterBurst.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_WaterBurst::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects3.gif");
    AddSpriteFrame(-56, -80, 112, 32, 143, 46);
    AddSpriteFrame(-56, -80, 112, 32, 143, 79);
    AddSpriteFrame(-56, -80, 112, 32, 143, 112);
    AddSpriteFrame(-56, -80, 112, 32, 143, 145);
    AddSpriteFrame(-56, 48, 112, 32, 143, 46);
    AddSpriteFrame(-56, 48, 112, 32, 143, 79);
    AddSpriteFrame(-56, 48, 112, 32, 143, 112);
    AddSpriteFrame(-56, 48, 112, 32, 143, 145);
    AddSpriteFrame(-32, -64, 64, 32, 126, 178);
    AddSpriteFrame(-32, -64, 64, 32, 61, 178);
    AddSpriteFrame(-32, -64, 64, 32, 191, 178);
    AddSpriteFrame(-32, -64, 64, 32, 191, 211);
    AddSpriteFrame(-32, -32, 64, 32, 126, 178);
    AddSpriteFrame(-32, -32, 64, 32, 61, 178);
    AddSpriteFrame(-32, -32, 64, 32, 191, 178);
    AddSpriteFrame(-32, -32, 64, 32, 191, 211);
    AddSpriteFrame(-32, 0, 64, 32, 126, 178);
    AddSpriteFrame(-32, 0, 64, 32, 61, 178);
    AddSpriteFrame(-32, 0, 64, 32, 191, 178);
    AddSpriteFrame(-32, 0, 64, 32, 191, 211);
    AddSpriteFrame(-32, 32, 64, 32, 126, 178);
    AddSpriteFrame(-32, 32, 64, 32, 61, 178);
    AddSpriteFrame(-32, 32, 64, 32, 191, 178);
    AddSpriteFrame(-32, 32, 64, 32, 191, 211);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Burst")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[0]].priority = 3;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_WaterBurst::ObjectMain()
{
    Entity *self = Self();

    self->values[1]++;
    if (self->values[1] == 8) {
        scriptEng.tempValue[0] = rand() % 80;
        scriptEng.tempValue[0] -= 40;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += self->XPos;
        scriptEng.tempValue[1] = rand() % 16;
        scriptEng.tempValue[1] -= 8;
        scriptEng.tempValue[1] <<= 16;
        scriptEng.tempValue[1] += self->YPos;
        scriptEng.tempValue[1] -= 0x300000;
        CreateTempObject(TypeNameID("Burst Splash"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 10;
        objectEntityList[scriptEng.arrayPosition[2]].values[1] -= 5;
        objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 13;
        objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x20000;
        self->values[1] = 0;
    }
}

void O_R4_WaterBurst::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_PLATFORM, -48, -66, 48, -32);
    if (CheckResult() == 1) {
        pYPos() += 0x20000;
    }
    PlayerObjectCollision(C_TOUCH, -128, -24, 128, 400);
    if (CheckResult() == 1) {
        if (pState() != PlayerStateID("Player_State_Death")) {
            if (pState() != PlayerStateID("Player_State_Drown")) {
                pState() = PlayerStateID("Player_State_WaterCurrent");
                pAnimation() = GVar("ANI_FANROTATE");
                pControlMode() = -1;
                pLeft() = 0;
                pRight() = 0;
                pUp() = 0;
                pDown() = 0;
                pYVel() = -0x100000;
                pTimer() = 0;
            }
        }
        PlayerObjectCollision(C_TOUCH, -128, 48, 128, 332);
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->XPos;
            scriptEng.tempValue[0] -= pXPos();
            scriptEng.tempValue[0] >>= 2;
            if (scriptEng.tempValue[0] > 0x100000) {
                scriptEng.tempValue[0] = 0x100000;
            }
            if (scriptEng.tempValue[0] < -0x100000) {
                scriptEng.tempValue[0] = -0x100000;
            }
            pXPos() += scriptEng.tempValue[0];
        }
    } else {
        if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
            pState() = PlayerStateID("Player_State_Air");
            pControlMode() = 0;
            pAnimation() = GVar("ANI_BOUNCING");
            pXVel() = 0;
            pSpeed() = 0;
        }
    }
}

void O_R4_WaterBurst::ObjectDraw()
{
    Entity *self = Self();

    self->YPos = GVar("Stage.NewWaterLevel");
    self->YPos -= 0x300000;
    scriptEng.tempValue[0] = GVar("Oscillation");
    scriptEng.tempValue[0] <<= 2;
    scriptEng.tempValue[1] = Sin512(scriptEng.tempValue[0]);
    scriptEng.tempValue[1] <<= 9;
    self->YPos += scriptEng.tempValue[1];
    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] /= 3;
    scriptEng.tempValue[0] += 8;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    scriptEng.tempValue[0] += 4;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    scriptEng.tempValue[0] += 4;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    scriptEng.tempValue[0] += 4;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->values[0]++;
    self->values[0] %= 12;
    DrawSprite_Frame(self->frame);
    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] += 4;
    DrawSprite_Frame(scriptEng.tempValue[0]);
    self->frame++;
    self->frame &= 3;
}

#endif // RETRO_USE_NATIVE_OBJECTS
