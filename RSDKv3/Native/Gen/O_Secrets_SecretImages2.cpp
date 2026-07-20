#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Secrets_SecretImages2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SecretImages2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Secrets_SecretImages2::ObjectStartup()
{
    LoadSpriteSheet("Secrets/DD_R2.gif");
    AddSpriteFrame(-160, -120, 320, 240, 0, 0);
    LoadPalette("DDZ_Pal.act", 1, 0, 0, 256);
}

void O_Secrets_SecretImages2::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 8) {
            self->values[0]++;
        } else {
            self->values[0] = 288;
            SetActivePalette(1, 0, SCREEN_YSIZE);
            self->state++;
        }
        SetFade(0, 0, 0, 255);
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0] -= 16;
        } else {
            PlayMusic(GVar("Options.Soundtrack"));
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
        break;
        case 4:
        if (self->values[0] < 288) {
            self->values[0] += 8;
            masterVolume -= 5;
        } else {
            SetActivePalette(0, 0, SCREEN_YSIZE);
            StopMusic();
            GVar("Options.GameMode") = 0;
            activeStageList = 0;
            stageListPosition = 3;
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

void O_Secrets_SecretImages2::ObjectDraw()
{
    DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 224, 224, 224, 255);
    DrawSprite_ScreenXY(0, SCREEN_CENTERX, SCREEN_CENTERY);
}

#endif // RETRO_USE_NATIVE_OBJECTS
