#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Secrets_SecretImages.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SecretImages.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Secrets_SecretImages::ObjectStartup()
{
    LoadSpriteSheet("Secrets/SecretImages.gif");
    AddSpriteFrame(-160, -112, 320, 224, 0, 0);
    AddSpriteFrame(-160, -112, 320, 224, 0, 225);
    AddSpriteFrame(-160, -112, 320, 224, 0, 450);
    AddSpriteFrame(-160, -112, 320, 224, 0, 675);
    AddSpriteFrame(-160, -112, 160, 224, 321, 0);
    AddSpriteFrame(0, -112, 160, 224, 321, 225);
}

void O_Secrets_SecretImages::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 8) {
            self->values[0]++;
        } else {
            self->values[0] = 288;
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
            StopMusic();
            GVar("Options.GameMode") = 0;
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

void O_Secrets_SecretImages::ObjectDraw()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 0, 255);
        DrawSprite_ScreenXY(0, SCREEN_CENTERX, SCREEN_CENTERY);
        break;
        case 1:
        DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 0, 255);
        DrawSprite_ScreenXY(1, SCREEN_CENTERX, SCREEN_CENTERY);
        break;
        case 2:
        DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 238, 238, 204, 255);
        DrawSprite_ScreenXY(2, SCREEN_CENTERX, SCREEN_CENTERY);
        break;
        case 3:
        DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 0, 255);
        DrawSprite_ScreenXY(3, SCREEN_CENTERX, SCREEN_CENTERY);
        break;
        case 4:
        DrawRectangle(0, 0, SCREEN_CENTERX, SCREEN_YSIZE, 0, 34, 221, 255);
        DrawRectangle(SCREEN_CENTERX, 0, SCREEN_CENTERX, SCREEN_YSIZE, 0, 34, 204, 255);
        DrawSprite_ScreenXY(4, SCREEN_CENTERX, SCREEN_CENTERY);
        DrawSprite_ScreenXY(5, SCREEN_CENTERX, SCREEN_CENTERY);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
