#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DeathEvent.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from DeathEvent.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DeathEvent::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Display.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Display_t.gif");
    }
    AddSpriteFrame(-32, 0, 64, 16, 0, 189);
    AddSpriteFrame(-28, 0, 56, 16, 65, 189);
    AddSpriteFrame(-32, 0, 64, 16, 122, 189);
}

void O_DeathEvent::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        case 1:
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 40;
        if (self->values[1] < scriptEng.tempValue[0]) {
            self->values[1] += 16;
            if (self->values[1] > scriptEng.tempValue[0]) {
                self->values[1] = scriptEng.tempValue[0];
            }
        }
        scriptEng.tempValue[0] += 80;
        if (self->values[2] > scriptEng.tempValue[0]) {
            self->values[2] -= 16;
            if (self->values[2] < scriptEng.tempValue[0]) {
                self->values[2] = scriptEng.tempValue[0];
            }
        }
        if (self->values[3] < 288) {
            self->values[3] += 4;
        } else {
            if (self->state == 0) {
                activeStageList = 0;
                stageListPosition = 0;
                GVar("LampPost.Check") = 0;
                GVar("Transporter_Destroyed") = 0;
                GVar("MetalSonic_Destroyed") = 0;
                if (GVar("Options.GameMode") == 1) {
                    scriptEng.arrayPosition[1] = GVar("Options.SaveSlot");
                    scriptEng.arrayPosition[1] <<= 3;
                    scriptEng.arrayPosition[1]++;
                    if (saveRAM[scriptEng.arrayPosition[1]] < 3) {
                        saveRAM[scriptEng.arrayPosition[1]] = 3;
                    }
                    CheckResult() = WriteSaveRAMData();
                }
            }
            if (self->state == 1) {
                GVar("Rec_Milliseconds") = 0;
                GVar("Rec_Seconds") = 0;
                GVar("Rec_Minutes") = 0;
            }
            stageMode = STAGEMODE_LOAD;
        }
        if (self->values[3] > 0) {
            masterVolume -= 2;
            SetFade(0, 0, 0, self->values[3]);
        } else {
            if (keyPress.A == 1) {
                self->values[3] = 0;
            }
            if (keyPress.B == 1) {
                self->values[3] = 0;
            }
            if (keyPress.C == 1) {
                self->values[3] = 0;
            }
        }
        break;
        case 2:
        if (self->values[3] < 288) {
            masterVolume -= 2;
            self->values[3] += 4;
        } else {
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[3]);
        break;
        case 3:
        if (self->values[3] < 288) {
            masterVolume -= 2;
            self->values[3] += 4;
        } else {
            GVar("TimeAttack.Result") = 0;
            GVar("LampPost.Check") = 0;
            activeStageList = 0;
            stageListPosition = 2;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[3]);
        break;
    }
}

void O_DeathEvent::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        DrawSprite_ScreenXY(0, self->values[1], 96);
        DrawSprite_ScreenXY(2, self->values[2], 96);
        break;
        case 1:
        DrawSprite_ScreenXY(1, self->values[1], 96);
        DrawSprite_ScreenXY(2, self->values[2], 96);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
