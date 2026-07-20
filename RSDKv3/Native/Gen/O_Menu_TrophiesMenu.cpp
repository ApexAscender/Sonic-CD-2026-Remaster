#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_TrophiesMenu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TrophiesMenu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_TrophiesMenu::ObjectStartup()
{
    LoadSpriteSheet("Menu/Trophies.gif");
    AddSpriteFrame(0, 0, 64, 64, 385, 385);
    LoadPalette("Trophies.act", 0, 0, 0, 256);
    LoadPalette("HelpPal1.act", 0, 0, 0, 32);
    LoadFontFile("Data/Game/HelpText.bin");
    if (GVar("Options.Soundtrack") == 0) {
        SetMusicTrack_Script("JP/DAGarden.ogg", 1, 1);
    } else {
        SetMusicTrack_Script("US/DAGarden.ogg", 1, 117382);
    }
    Engine.gameMode = 5;
    cameraEnabled = 0;
    objectEntityList[0].type = TypeNameID("Trophies Menu");
    objectEntityList[0].priority = 1;
    objectEntityList[0].drawOrder = 0;
    LoadTextFile_Script(0, "Data/Game/Trophies.txt", 1);
}

void O_Menu_TrophiesMenu::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        scriptEng.tempValue[0] = 256;
        scriptEng.tempValue[0] -= SCREEN_CENTERX;
        xScrollOffset = scriptEng.tempValue[0];
        PlayMusic(1);
        self->values[0] = 384;
        self->state++;
        SetFade(0, 0, 0, 255);
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            self->state++;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 2:
        if (GVar("Options.PhysicalControls") == 1) {
            if (keyDown.down == 1) {
                self->values[2] += 0x40000;
                if (self->values[2] > 0x1800000) {
                    self->values[2] = 0x1800000;
                }
            }
            if (keyDown.up == 1) {
                self->values[2] -= 0x40000;
                if (self->values[2] < 0) {
                    self->values[2] = 0;
                }
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
                GVar("Options.PhysicalControls") = 0;
            }
        } else {
            CheckTouchRect_Script(0, 48, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
                scriptEng.arrayPosition[0] = CheckResult();
                if (self->values[3] == 0) {
                    self->values[3] = 1;
                    objectEntityList[1].values[0] = self->values[2];
                    objectEntityList[1].values[0] >>= 16;
                    self->values[4] = touchY[scriptEng.arrayPosition[0]];
                } else {
                    scriptEng.tempValue[0] = self->values[4];
                    scriptEng.tempValue[0] -= touchY[scriptEng.arrayPosition[0]];
                    scriptEng.tempValue[0] += objectEntityList[1].values[0];
                    objectEntityList[1].values[6] = objectEntityList[1].values[5];
                    objectEntityList[1].values[5] = objectEntityList[1].values[4];
                    objectEntityList[1].values[4] = self->values[5];
                    self->values[5] = scriptEng.tempValue[0];
                    scriptEng.tempValue[1] = self->values[2];
                    scriptEng.tempValue[1] >>= 16;
                    self->values[5] -= scriptEng.tempValue[1];
                    self->values[2] = scriptEng.tempValue[0];
                    self->values[2] <<= 16;
                }
            } else {
                if (self->values[3] == 1) {
                    self->values[3] = 0;
                    self->values[5] += objectEntityList[1].values[4];
                    self->values[5] += objectEntityList[1].values[5];
                    self->values[5] += objectEntityList[1].values[6];
                    self->values[5] >>= 2;
                    self->values[5] <<= 16;
                }
                if (self->values[5] != 0) {
                    self->values[2] += self->values[5];
                    if (self->values[2] < 0) {
                        self->values[5] = 0;
                    }
                    if (self->values[2] > 0x1800000) {
                        self->values[5] = 0;
                    }
                    if (self->values[5] > 0) {
                        self->values[5] -= 0x2000;
                        if (self->values[5] < 0) {
                            self->values[5] = 0;
                        }
                    } else {
                        self->values[5] += 0x2000;
                        if (self->values[5] > 0) {
                            self->values[5] = 0;
                        }
                    }
                } else {
                    if (self->values[2] < 0) {
                        self->values[2] *= 224;
                        self->values[2] >>= 8;
                    }
                    if (self->values[2] > 0x1800000) {
                        self->values[2] -= 0x1800000;
                        self->values[2] *= 224;
                        self->values[2] >>= 8;
                        self->values[2] += 0x1800000;
                    }
                }
            }
            if (keyPress.up == 1) {
                GVar("Options.PhysicalControls") = 1;
            }
            if (keyPress.down == 1) {
                GVar("Options.PhysicalControls") = 1;
            }
        }
        if (keyPress.B == 1) {
            PlaySfx(26, 0);
            StopMusic();
            self->state = 5;
        }
        break;
        case 5:
        if (self->values[0] < 348) {
            self->values[0] += 8;
        } else {
            stageListPosition = 1;
            Engine.gameMode = 6;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
    }
}

void O_Menu_TrophiesMenu::ObjectDraw()
{
    Entity *self = Self();

    self->values[1]--;
    if (self->values[1] < -31) {
        self->values[1] += 32;
    }
    scriptEng.tempValue[1] = self->values[1];
    scriptEng.tempValue[1] >>= 1;
    while (scriptEng.tempValue[1] < SCREEN_YSIZE) {
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] >>= 1;
        while (scriptEng.tempValue[0] < SCREEN_XSIZE) {
            DrawSprite_ScreenXY(0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] += 64;
        }
        scriptEng.tempValue[1] += 64;
    }
    scriptEng.tempValue[0] = SCREEN_XSIZE;
    scriptEng.tempValue[0] -= 16;
    DrawRectangle(scriptEng.tempValue[0], 56, 4, 176, 128, 128, 128, 128);
    scriptEng.tempValue[1] = self->values[2];
    scriptEng.tempValue[1] >>= 16;
    if (scriptEng.tempValue[1] < 0) {
        scriptEng.tempValue[1] = 0;
    }
    if (scriptEng.tempValue[1] > 384) {
        scriptEng.tempValue[1] = 384;
    }
    scriptEng.tempValue[1] *= 160;
    scriptEng.tempValue[1] /= 384;
    scriptEng.tempValue[1] += 56;
    DrawRectangle(scriptEng.tempValue[0], scriptEng.tempValue[1], 4, 16, 0, 0, 0, 255);
}

#endif // RETRO_USE_NATIVE_OBJECTS
