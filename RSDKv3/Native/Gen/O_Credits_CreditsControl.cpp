#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Credits_CreditsControl.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CreditsControl.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Credits_CreditsControl::ObjectStartup()
{
    if (GVar("Options.Soundtrack") == 0) {
        SetMusicTrack_Script("JP/TimeAttack.ogg", 0, 100512);
    } else {
        SetMusicTrack_Script("US/DAGarden.ogg", 0, 117382);
    }
    LoadTextFile_Script(0, "Data/Game/Credits_Mobile.txt", 0);
    cameraEnabled = 0;
    objectEntityList[0].type = TypeNameID("Credits Control");
    objectEntityList[0].priority = 1;
    scriptEng.tempValue[1] = GetTextInfo_Script(0, 2, 0, 0);
    scriptEng.arrayPosition[0] = 32;
    while (objectEntityList[scriptEng.arrayPosition[0]].type != TypeNameID("Blank Object")) {
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[2] = 0x1000000;
    scriptEng.tempValue[3] = 0x1000000;
    while (scriptEng.tempValue[0] < scriptEng.tempValue[1]) {
        scriptEng.tempValue[4] = GetTextInfo_Script(0, 0, scriptEng.tempValue[0], 1);
        scriptEng.tempValue[5] = GetTextInfo_Script(0, 1, scriptEng.tempValue[0], 0);
        if (scriptEng.tempValue[5] == 0) {
            scriptEng.tempValue[3] += 0x160000;
        } else {
            if (scriptEng.tempValue[4] == 48) {
                ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Text Font 1"), 0, scriptEng.tempValue[2], scriptEng.tempValue[3]);
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = scriptEng.tempValue[0];
                scriptEng.arrayPosition[0]++;
                scriptEng.tempValue[3] += 0x160000;
            } else {
                if (scriptEng.tempValue[4] == 49) {
                    ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Text Font 2"), 0, scriptEng.tempValue[2], scriptEng.tempValue[3]);
                    objectEntityList[scriptEng.arrayPosition[0]].values[1] = scriptEng.tempValue[0];
                    scriptEng.arrayPosition[0]++;
                    scriptEng.tempValue[3] += 0xE0000;
                } else {
                    if (scriptEng.tempValue[4] == 50) {
                        ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Text Font 3"), 0, scriptEng.tempValue[2], scriptEng.tempValue[3]);
                        objectEntityList[scriptEng.arrayPosition[0]].values[1] = scriptEng.tempValue[0];
                        scriptEng.arrayPosition[0]++;
                        scriptEng.tempValue[3] += 0xE0000;
                    }
                }
            }
        }
        scriptEng.tempValue[0]++;
    }
    scriptEng.tempValue[3] -= 0xE0000;
    objectEntityList[0].values[3] = scriptEng.tempValue[3];
    objectEntityList[0].values[3] >>= 15;
}

void O_Credits_CreditsControl::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        yScrollOffset = self->values[2];
        scriptEng.tempValue[0] = 256;
        scriptEng.tempValue[0] -= SCREEN_CENTERX;
        xScrollOffset = scriptEng.tempValue[0];
        self->drawOrder = 0;
        if (self->values[0] < 8) {
            self->values[0]++;
        } else {
            self->values[0] = 254;
            PlayMusic(0);
            self->state++;
        }
        SetFade(0, 0, 0, 255);
        break;
        case 1:
        if (self->values[0] > 0) {
            SetFade(0, 0, 0, self->values[0]);
            self->values[0] -= 8;
        } else {
            self->state++;
        }
        break;
        case 2:
        self->values[2]++;
        if (keyDown.A == 1) {
            self->values[2]++;
        }
        if (keyDown.C == 1) {
            self->values[2]++;
        }
        scriptEng.tempValue[0] = self->values[2];
        scriptEng.tempValue[0] >>= 1;
        yScrollOffset = scriptEng.tempValue[0];
        if (self->values[2] > self->values[3]) {
            self->state = 3;
            self->values[0] = 0;
        }
        if (keyPress.start == 1) {
            self->state = 3;
            self->values[0] = 0;
        }
        if (keyPress.B == 1) {
            self->state = 3;
            self->values[0] = 0;
        }
        CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
        if (CheckResult() > -1) {
            self->state = 3;
            self->values[0] = 0;
        }
        break;
        case 3:
        if (self->values[0] < 320) {
            self->values[0] += 8;
            masterVolume -= 2;
        } else {
            StopMusic();
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

void O_Credits_CreditsControl::ObjectDraw()
{
    DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 0, 255);
}

#endif // RETRO_USE_NATIVE_OBJECTS
