#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_LampPost.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LampPost.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_LampPost::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-8, -40, 16, 64, 1, 137);
    AddSpriteFrame(-8, -24, 16, 48, 1, 153);
    AddSpriteFrame(-8, -8, 16, 16, 1, 137);
    AddSpriteFrame(-8, -8, 16, 16, 1, 236);
    AddSpriteFrame(-8, -8, 16, 16, 18, 236);
    if (GVar("Warp.XPos") == 0) {
        if (objectEntityList[24].propertyValue == 0) {
            if (GVar("LampPost.Check") > 31) {
                scriptEng.arrayPosition[0] = GVar("LampPost.Check");
                pXPos() = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                pXPos() += GVar("LampPost.Side");
                pYPos() = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                stageMilliseconds = GVar("Rec_Milliseconds");
                stageSeconds = GVar("Rec_Seconds");
                stageMinutes = GVar("Rec_Minutes");
            }
        }
    }
}

void O_LampPost::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_TOUCH, -8, -32, 8, 32);
        if (CheckResult() == 1) {
            GVar("LampPost.Check") = objectLoop;
            if (pXPos() < self->XPos) {
                GVar("LampPost.Side") = -0x180000;
                ObjectTileCollision_Script(2, -24, 0, 0);
                if (CheckResult() == 1) {
                    GVar("LampPost.Side") = 0;
                }
            } else {
                GVar("LampPost.Side") = 0x180000;
                ObjectTileCollision_Script(1, 24, 0, 0);
                if (CheckResult() == 1) {
                    GVar("LampPost.Side") = 0;
                }
            }
            GVar("Rec_Milliseconds") = stageMilliseconds;
            GVar("Rec_Seconds") = stageSeconds;
            GVar("Rec_Minutes") = stageMinutes;
            self->state = 1;
            self->values[0] = 384;
            PlaySfx(9, 0);
            HapticEffect_Script(20, 0, 0, 0);
        }
    }
}

void O_LampPost::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        DrawSprite_Frame(0);
        break;
        case 1:
        DrawSprite_Frame(1);
        scriptEng.tempValue[0] = Cos512(self->values[0]);
        scriptEng.tempValue[0] <<= 10;
        scriptEng.tempValue[1] = Sin512(self->values[0]);
        scriptEng.tempValue[1] <<= 10;
        scriptEng.tempValue[0] += self->XPos;
        scriptEng.tempValue[1] += self->YPos;
        scriptEng.tempValue[1] -= 0x180000;
        DrawSprite_FrameXY(2, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        self->values[0] += 16;
        if (self->values[0] > 896) {
            self->values[0] = 0;
            self->state = 2;
        }
        break;
        case 2:
        DrawSprite_Frame(1);
        self->values[0]++;
        if (self->values[0] == 8) {
            self->values[0] = 0;
        }
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] -= 0x200000;
        if (self->values[0] > 3) {
            DrawSprite_FrameXY(4, self->XPos, scriptEng.tempValue[0]);
        } else {
            DrawSprite_FrameXY(3, self->XPos, scriptEng.tempValue[0]);
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
