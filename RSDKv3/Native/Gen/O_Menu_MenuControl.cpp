#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_MenuControl.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MenuControl.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_MenuControl::ObjectStartup()
{
    SetMusicTrack_Script("JP/SpecialStage.ogg", 0, 1);
    SetMusicTrack_Script("US/SpecialStage.ogg", 1, 270972);
    objectEntityList[0].type = TypeNameID("Menu Control");
    objectEntityList[0].values[1] = 32;
    objectEntityList[0].values[3] = 1;
    objectEntityList[0].values[2] = 0;
}

void O_Menu_MenuControl::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->state = 1;
        self->values[0] = 384;
        SetFade(0, 0, 0, 255);
        PlayMusic(GVar("Options.Soundtrack"));
        if (Engine.frameSkipTimer > -1) {
            Engine.frameSkipTimer = -1;
        }
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0] -= 8;
        } else {
            self->state = 6;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 2:
        CheckResult() = 1;
        if (CheckResult() == 1) {
            if (keyPress.up == 1) {
                self->values[3]--;
                if (self->values[3] < 1) {
                    self->values[3] = 1;
                } else {
                    PlaySfx(23, 0);
                }
            }
            if (keyPress.down == 1) {
                self->values[3]++;
                if (self->values[3] > objectEntityList[1].values[2]) {
                    self->values[3] = objectEntityList[1].values[2];
                } else {
                    PlaySfx(23, 0);
                }
            }
            scriptEng.tempValue[0] = self->values[3];
            scriptEng.tempValue[0] -= self->values[4];
            if (scriptEng.tempValue[0] < 1) {
                self->values[4]--;
                self->direction = 3;
            }
            if (scriptEng.tempValue[0] > 4) {
                self->values[4]++;
                self->direction = 0;
            }
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] -= 32;
            scriptEng.tempValue[1] = self->values[4];
            scriptEng.tempValue[1] *= -60;
            scriptEng.tempValue[1] -= scriptEng.tempValue[0];
            scriptEng.tempValue[1] += self->direction;
            scriptEng.tempValue[1] >>= 2;
            self->values[1] += scriptEng.tempValue[1];
        } else {
            if (Engine.message == 2) {
                self->values[3] = 0;
                self->values[2] = 0;
            }
            if (self->values[2] > 0) {
                self->values[3] = self->values[2];
            } else {
                self->values[3] = 0;
            }
            if (objectEntityList[1].values[2] > 4) {
                CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
                if (CheckResult() > -1) {
                    scriptEng.arrayPosition[0] = CheckResult();
                    if (self->values[5] == 0) {
                        self->values[5] = 1;
                        objectEntityList[1].values[0] = self->values[1];
                        self->values[6] = touchY[scriptEng.arrayPosition[0]];
                    } else {
                        scriptEng.tempValue[0] = touchY[scriptEng.arrayPosition[0]];
                        scriptEng.tempValue[0] -= self->values[6];
                        scriptEng.tempValue[0] += objectEntityList[1].values[0];
                        objectEntityList[1].values[6] = objectEntityList[1].values[5];
                        objectEntityList[1].values[5] = objectEntityList[1].values[4];
                        objectEntityList[1].values[4] = self->values[7];
                        self->values[7] = scriptEng.tempValue[0];
                        self->values[7] -= self->values[1];
                        self->values[1] = scriptEng.tempValue[0];
                    }
                    scriptEng.tempValue[0] = self->values[7];
                    scriptEng.tempValue[0] >>= 2;
                    if (scriptEng.tempValue[0] != 0) {
                        self->values[3] = 0;
                        self->values[2] = 0;
                    }
                } else {
                    if (self->values[5] == 1) {
                        self->values[5] = 0;
                        self->values[6] = self->values[1];
                        self->values[6] <<= 8;
                        self->values[7] += objectEntityList[1].values[4];
                        self->values[7] += objectEntityList[1].values[5];
                        self->values[7] += objectEntityList[1].values[6];
                        self->values[7] >>= 2;
                        self->values[7] <<= 7;
                        if (self->values[7] == 0) {
                            if (self->values[3] == 0) {
                                self->values[7] = 1;
                            }
                        }
                    }
                    if (self->values[7] != 0) {
                        self->values[6] += self->values[7];
                        if (self->values[6] < objectEntityList[1].values[3]) {
                            self->values[6] = objectEntityList[1].values[3];
                            self->values[7] = 0;
                        }
                        if (self->values[6] > 0x5A00) {
                            self->values[6] = 0x5A00;
                            self->values[7] = 0;
                        }
                        if (self->values[7] > 0) {
                            self->values[7] -= 32;
                            if (self->values[7] < 0) {
                                self->values[7] = 0;
                            }
                        } else {
                            self->values[7] += 32;
                            if (self->values[7] > 0) {
                                self->values[7] = 0;
                            }
                        }
                        self->values[1] = self->values[6];
                        self->values[1] >>= 8;
                        if (self->values[7] == 0) {
                            self->values[4] = self->values[1];
                            self->values[4] -= 32;
                            self->values[4] /= -60;
                            if (self->values[4] < 0) {
                                self->values[4] = 0;
                            }
                            scriptEng.tempValue[0] = objectEntityList[1].values[2];
                            scriptEng.tempValue[0] -= 4;
                            if (self->values[4] > scriptEng.tempValue[0]) {
                                self->values[4] = scriptEng.tempValue[0];
                            }
                        }
                    } else {
                        scriptEng.tempValue[0] = self->values[1];
                        scriptEng.tempValue[0] -= 32;
                        objectEntityList[1].values[1] = self->values[4];
                        objectEntityList[1].values[1] *= -60;
                        objectEntityList[1].values[1] -= scriptEng.tempValue[0];
                        objectEntityList[1].values[1] >>= 2;
                        if (objectEntityList[1].values[1] < -4) {
                            objectEntityList[1].values[1] = -4;
                        }
                        if (objectEntityList[1].values[1] > 4) {
                            objectEntityList[1].values[1] = 4;
                        }
                        self->values[1] += objectEntityList[1].values[1];
                    }
                }
            }
        }
        break;
        case 3:
        break;
        case 4:
        if (self->values[0] < 320) {
            self->values[0] += 8;
        } else {
            stageListPosition = 2;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 5:
        if (self->values[0] < 320) {
            self->values[0] += 8;
        } else {
            LoadVideo_Script("Opening");
            activeStageList = 1;
            stageListPosition = 0;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 6:
        if (objectEntityList[34].state == 2) {
            self->state = 2;
        }
        break;
        case 7:
        if (self->values[0] < 320) {
            self->values[0] += 8;
        } else {
            stageListPosition = 9;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 8:
        if (self->values[0] < 320) {
            self->values[0] += 8;
        } else {
            stageListPosition = 10;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
