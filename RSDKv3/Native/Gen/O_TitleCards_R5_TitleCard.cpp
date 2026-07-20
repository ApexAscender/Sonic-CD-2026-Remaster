#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_TitleCards_R5_TitleCard.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R5_TitleCard.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_TitleCards_R5_TitleCard::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Display.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Display_t.gif");
    }
    if (GVar("Options.Soundtrack") == 0) {
        switch (objectEntityList[24].propertyValue) {
            case 0:
            SetMusicTrack_Script("JP/R5A.ogg", 0, 1);
            break;
            case 1:
            SetMusicTrack_Script("R5B.ogg", 0, 619562);
            break;
            case 2:
            SetMusicTrack_Script("JP/R5C.ogg", 0, 367046);
            break;
            case 3:
            SetMusicTrack_Script("JP/R5D.ogg", 0, 1);
            break;
        }
    } else {
        switch (objectEntityList[24].propertyValue) {
            case 0:
            SetMusicTrack_Script("US/R5A.ogg", 0, 1);
            break;
            case 1:
            SetMusicTrack_Script("R5B.ogg", 0, 619562);
            break;
            case 2:
            SetMusicTrack_Script("US/R5C.ogg", 0, 705830);
            break;
            case 3:
            SetMusicTrack_Script("US/R5D.ogg", 0, 93672);
            break;
        }
    }
    GVar("Flower_TypeNo") = TypeNameID("Flower");
    objectEntityList[20].type = TypeNameID("Title Card");
    if (GVar("Warp.XPos") > 0) {
        objectEntityList[20].values[3] = 256;
    } else {
        objectEntityList[20].values[3] = 384;
    }
    GVar("Player.RoofBarrier") = 1;
    objectEntityList[20].priority = 1;
    objectEntityList[20].drawOrder = 6;
    objectEntityList[20].values[0] = -216;
    objectEntityList[20].values[1] = 336;
    objectEntityList[20].values[7] = SCREEN_CENTERX;
    objectEntityList[20].values[7] -= 160;
    if (objectEntityList[20].values[7] > 3) {
        objectEntityList[20].values[7] -= 4;
    }
    objectEntityList[20].values[7] &= 248;
    objectEntityList[20].values[1] += objectEntityList[20].values[7];
    objectEntityList[20].values[1] += objectEntityList[20].values[7];
    objectEntityList[20].values[2] = 14;
    objectEntityList[20].values[2] += 8;
    objectEntityList[20].values[4] = GVar("Fade_Colour");
    objectEntityList[20].values[4] >>= 16;
    objectEntityList[20].values[5] = GVar("Fade_Colour");
    objectEntityList[20].values[5] &= 0x00FF00;
    objectEntityList[20].values[5] >>= 8;
    objectEntityList[20].values[6] = GVar("Fade_Colour");
    objectEntityList[20].values[6] &= 0x0000FF;
    AddSpriteFrame(0, 0, 32, 200, 223, 1);
    AddSpriteFrame(96, 96, 48, 48, 41, 1);
    AddSpriteFrame(96, 96, 48, 48, 90, 1);
    AddSpriteFrame(96, 96, 48, 48, 139, 1);
    AddSpriteFrame(64, 97, 48, 16, 41, 67);
    AddSpriteFrame(64, 81, 160, 16, 41, 50);
    AddSpriteFrame(16, 81, 160, 16, 41, 50);
    AddSpriteFrame(100, 32, 24, 48, 188, 1);
    AddSpriteFrame(0, 0, 20, 55, 100, 133);
    AddSpriteFrame(20, 32, 11, 23, 92, 108);
    AddSpriteFrame(32, 32, 11, 23, 43, 84);
    AddSpriteFrame(44, 32, 12, 23, 57, 108);
    AddSpriteFrame(56, 32, 10, 23, 81, 108);
    AddSpriteFrame(66, 32, 10, 23, 158, 108);
    AddSpriteFrame(0, 56, 20, 55, 100, 133);
    AddSpriteFrame(20, 56, 11, 23, 92, 108);
    AddSpriteFrame(32, 56, 11, 23, 43, 84);
    AddSpriteFrame(44, 56, 11, 23, 76, 84);
    AddSpriteFrame(56, 56, 12, 23, 57, 108);
    AddSpriteFrame(69, 56, 11, 23, 43, 84);
    AddSpriteFrame(81, 56, 11, 23, 187, 84);
    AddSpriteFrame(92, 56, 10, 23, 81, 108);
}

void O_TitleCards_R5_TitleCard::ObjectPlayerInteraction()
{
    pTimer() = 0;
}

void O_TitleCards_R5_TitleCard::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        pControlMode() = -1;
        pUp() = 0;
        pDown() = 0;
        pLeft() = 0;
        pRight() = 0;
        pJumpPress() = 0;
        pJumpHold() = 0;
        if (GVar("Warp.XPos") < 1) {
            pSpeed() = 0;
        }
        if (self->values[3] > 0) {
            if (self->values[3] == 256) {
                PlayMusic(0);
                if (GVar("Warp.XPos") > 0) {
                    pXPos() = GVar("Warp.XPos");
                    pYPos() = GVar("Warp.YPos");
                    pXVel() = GVar("Warp.XVelocity");
                    pYVel() = GVar("Warp.YVelocity");
                    pSpeed() = GVar("Warp.XVelocity");
                    pState() = GVar("Warp.State");
                    stageMilliseconds = GVar("Rec_Milliseconds");
                    stageSeconds = GVar("Rec_Seconds");
                    stageMinutes = GVar("Rec_Minutes");
                    objectEntityList[0].values[4] = 8000;
                }
                GVar("Warp.Timer") = 0;
                GVar("Warp.Frame") = 0;
            }
            SetFade(self->values[4], self->values[5], self->values[6], self->values[3]);
            self->values[3] -= 8;
        } else {
            GVar("Fade_Colour") = 0;
            CheckResult() = (GVar("Warp.XPos") == 0);
            scriptEng.tempValue[0] = CheckResult();
            CheckResult() = (GVar("LampPost.Check") < 32);
            scriptEng.tempValue[0] &= CheckResult();
            if (scriptEng.tempValue[0] == 1) {
                self->state = 1;
                self->values[3] = 0;
            } else {
                pControlMode() = 0;
                timeEnabled = 1;
                ResetObjectEntity(20, TypeNameID("Blank Object"), 0, 0, 0);
                GVar("Warp.XPos") = 0;
            }
        }
        break;
        case 1:
        scriptEng.tempValue[0] = 144;
        scriptEng.tempValue[0] += self->values[7];
        if (self->values[1] > scriptEng.tempValue[0]) {
            self->values[1] -= 8;
        } else {
            if (self->values[0] == 0) {
                self->state = 2;
            }
        }
        if (self->values[0] < 0) {
            self->values[0] += 8;
        }
        break;
        case 2:
        if (self->values[3] == 90) {
            self->state = 3;
        } else {
            self->values[3]++;
        }
        break;
        case 3:
        if (self->values[1] < 408) {
            self->values[1] += 16;
            self->values[0] -= 16;
        } else {
            pControlMode() = 0;
            timeEnabled = 1;
            ResetObjectEntity(20, TypeNameID("Blank Object"), 0, 0, 0);
            GVar("Warp.XPos") = 0;
        }
        break;
    }
    if (self->type > TypeNameID("Blank Object")) {
        scriptEng.tempValue[0] = 136;
        scriptEng.tempValue[0] += self->values[7];
        DrawSprite_ScreenXY(0, scriptEng.tempValue[0], self->values[0]);
        DrawSprite_ScreenXY(actID, self->values[1], 80);
        DrawSprite_ScreenXY(4, self->values[1], 80);
        DrawSprite_ScreenXY(5, self->values[1], 80);
        DrawSprite_ScreenXY(6, self->values[1], 80);
        DrawSprite_ScreenXY(7, self->values[1], 80);
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += 220;
        DrawRectangle(scriptEng.tempValue[0], 163, SCREEN_XSIZE, 9, 0, 0, 0, 255);
        scriptEng.tempValue[0] = 8;
        while (scriptEng.tempValue[0] < self->values[2]) {
            DrawSprite_ScreenXY(scriptEng.tempValue[0], self->values[1], 80);
            scriptEng.tempValue[0]++;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
