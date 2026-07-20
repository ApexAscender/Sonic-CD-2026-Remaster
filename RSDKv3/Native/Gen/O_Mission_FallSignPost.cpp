#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_FallSignPost.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FallSignPost.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_FallSignPost::ObjectStartup()
{
    LoadSpriteSheet("Global/Items2.gif");
    AddSpriteFrame(-12, -12, 24, 24, 0, 150);
    AddSpriteFrame(-24, -44, 48, 32, 34, 99);
    AddSpriteFrame(-16, -44, 32, 32, 1, 183);
    AddSpriteFrame(-4, -44, 8, 32, 25, 150);
    AddSpriteFrame(-16, -44, 32, 32, 1, 216);
    AddSpriteFrame(-24, -44, 48, 32, 34, 132);
    AddSpriteFrame(-16, -44, 32, 32, 1, 183);
    AddSpriteFrame(-4, -44, 8, 32, 25, 150);
    AddSpriteFrame(-16, -44, 32, 32, 1, 216);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("FallSignPost")) {
            objectEntityList[scriptEng.arrayPosition[0]].frame = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = 16;
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Mission_FallSignPost::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        CheckResult() = (GVar("game.missionCondition") == GVar("MISSION_CONDITION_CLEAR"));
        scriptEng.tempValue[0] = CheckResult();
        CheckResult() = (yScrollOffset != 0);
        scriptEng.tempValue[0] &= CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            GVar("game.missionCondition") = 0;
            self->XPos = pXPos();
            self->XPos -= 0x80000;
            self->YPos = yScrollOffset;
            self->YPos += 24;
            self->YPos <<= 16;
            cameraStyle = 4;
            ObjectTileCollision_Script(0, 0, 8, 0);
            if (CheckResult() == 1) {
                self->values[5] = 1;
            }
            self->state = 1;
            PlaySfx(15, 0);
        }
        break;
        case 1:
        self->values[2]++;
        self->YPos += self->values[4];
        self->values[4] += 0xC00;
        ObjectTileCollision_Script(0, 0, 8, 0);
        if (CheckResult() == 1) {
            if (self->values[5] == 0) {
                self->values[0] = 4;
                self->state = 2;
            }
        } else {
            self->values[5] = 0;
        }
        scriptEng.tempValue[0] = yScrollOffset;
        scriptEng.tempValue[0] += SCREEN_YSIZE;
        scriptEng.tempValue[0] += 44;
        if ((objectEntityList[objectLoop].YPos >> 16) >= scriptEng.tempValue[0]) {
            self->values[0] = 4;
            self->state = 2;
        }
        self->values[1]++;
        if (self->values[1] == 2) {
            self->values[1] = 0;
            self->frame++;
            if (self->frame == 5) {
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x140000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
            if (self->frame == 9) {
                self->frame = 1;
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x140000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
        }
        break;
        case 2:
        self->values[2]++;
        if (timeEnabled == 1) {
            masterVolume -= 2;
        }
        self->values[1]++;
        if (self->values[1] == 2) {
            self->values[1] = 0;
            self->frame++;
            if (self->frame == 5) {
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x140000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
            if (self->frame == 9) {
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x140000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                self->values[0]--;
                if (self->values[0] == 0) {
                    self->frame = 5;
                    self->state = 3;
                } else {
                    self->frame = 1;
                }
            }
        }
        break;
        case 3:
        CheckResult() = (pState() == PlayerStateID("Player_State_Ground"));
        scriptEng.tempValue[0] = CheckResult();
        CheckResult() = (PlayerOutOfBounds() == 1);
        scriptEng.tempValue[0] |= CheckResult();
        scriptEng.tempValue[1] = xScrollOffset;
        scriptEng.tempValue[1] += SCREEN_XSIZE;
        scriptEng.tempValue[1] += 32;
        CheckResult() = ((pXPos() >> 16) > scriptEng.tempValue[1]);
        scriptEng.tempValue[0] |= CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            pControlMode() = -1;
            pJumpHold() = 0;
            pRight() = 0;
            pLeft() = 0;
            pUp() = 0;
            pDown() = 0;
            if (pState() == PlayerStateID("Player_State_Ground")) {
                pXVel() = 0;
                pYVel() = 0;
            }
            pSpeed() = 0;
            cameraEnabled = 0;
        }
        break;
    }
    CheckResult() = (self->values[2] > 60);
    scriptEng.tempValue[0] = CheckResult();
    CheckResult() = (objectEntityList[30].type == TypeNameID("Blank Object"));
    scriptEng.tempValue[0] &= CheckResult();
    if (scriptEng.tempValue[0] == 1) {
        Engine.Callback(NOTIFY_TOUCH_SIGNPOST);
        timeEnabled = 0;
        PlayMusic(1);
        objectEntityList[30].type = TypeNameID("ActFinish");
        objectEntityList[30].drawOrder = 6;
        objectEntityList[30].priority = 1;
    }
    if (timeEnabled == 0) {
        GVar("Player.AirTimer") = 0;
    }
}

void O_Mission_FallSignPost::ObjectDraw()
{
    Entity *self = Self();

    if (self->state > 0) {
        DrawSprite_Frame(0);
        DrawSprite_Frame(self->frame);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
