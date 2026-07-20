#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Secrets_TailsUnlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TailsUnlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Secrets_TailsUnlock::ObjectStartup()
{
    LoadSpriteSheet("Secrets/SecretImages.gif");
    AddSpriteFrame(-117, -36, 234, 64, 0, 900);
}

void O_Secrets_TailsUnlock::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 16) {
            self->values[0]++;
        } else {
            if (debugMode == 0) {
                SetAchievement(7, 100);
            }
            self->values[0] = 288;
            self->state++;
        }
        SetFade(0, 0, 0, 255);
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            PlaySfx(globalSFXCount + 41, 0);
            self->state++;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 2:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 3:
        if (keyPress.A == 1) {
            self->state++;
        }
        if (keyPress.B == 1) {
            self->state++;
        }
        if (keyPress.C == 1) {
            self->state++;
        }
        if (keyPress.start == 1) {
            self->state++;
        }
        CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
        if (CheckResult() > -1) {
            self->state++;
        }
        if (self->values[0] < 300) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 4;
        }
        break;
        case 4:
        if (self->values[0] < 288) {
            self->values[0] += 8;
        } else {
            if (Engine.gameMode == 8) {
                Engine.gameMode = 1;
                activeStageList = 0;
                stageListPosition = 1;
                stageMode = STAGEMODE_LOAD;
            }
            activeStageList = 0;
            stageListPosition = 1;
            stageMode = STAGEMODE_LOAD;
        }
        scriptEng.tempValue[0] = self->values[0];
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        SetFade(0, 0, 0, scriptEng.tempValue[0]);
        break;
    }
}

void O_Secrets_TailsUnlock::ObjectDraw()
{
    DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 0, 255);
    DrawSprite_ScreenXY(0, SCREEN_CENTERX, SCREEN_CENTERY);
}

#endif // RETRO_USE_NATIVE_OBJECTS
