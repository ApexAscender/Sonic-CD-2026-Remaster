#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Secrets_SoundTest.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SoundTest.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Secrets_SoundTest::ObjectStartup()
{
    LoadSpriteSheet("Secrets/SecretMenus.gif");
    AddSpriteFrame(0, 0, 8, 16, 1, 49);
    AddSpriteFrame(0, 0, 8, 16, 10, 49);
    AddSpriteFrame(0, 0, 8, 16, 19, 49);
    AddSpriteFrame(0, 0, 8, 16, 28, 49);
    AddSpriteFrame(0, 0, 8, 16, 1, 66);
    AddSpriteFrame(0, 0, 8, 16, 10, 66);
    AddSpriteFrame(0, 0, 8, 16, 19, 66);
    AddSpriteFrame(0, 0, 8, 16, 28, 66);
    AddSpriteFrame(0, 0, 8, 16, 1, 83);
    AddSpriteFrame(0, 0, 8, 16, 10, 83);
    AddSpriteFrame(0, 0, 56, 16, 136, 83);
    AddSpriteFrame(0, 0, 56, 16, 136, 100);
    AddSpriteFrame(0, 0, 48, 16, 193, 83);
    AddSpriteFrame(0, 0, 48, 16, 193, 100);
    AddSpriteFrame(0, 0, 8, 16, 19, 83);
    AddSpriteFrame(0, 0, 224, 48, 0, 0);
    AddSpriteFrame(-40, 0, 96, 16, 136, 49);
    AddSpriteFrame(-10, -10, 20, 20, 136, 117);
    AddSpriteFrame(-10, -10, 20, 20, 136, 138);
    AddSpriteFrame(-10, -10, 20, 20, 157, 117);
    AddSpriteFrame(-10, -10, 20, 20, 157, 138);
    AddSpriteFrame(-20, -10, 40, 20, 200, 201);
    AddSpriteFrame(-20, -10, 40, 20, 200, 222);
    AddSpriteFrame(-20, -10, 40, 20, 159, 201);
    AddSpriteFrame(-20, -10, 40, 20, 159, 222);
    AddSpriteFrame(-20, -10, 40, 20, 200, 159);
    AddSpriteFrame(-20, -10, 40, 20, 200, 180);
}

void O_Secrets_SoundTest::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 8) {
            self->values[0]++;
        } else {
            self->values[0] = 254;
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
        if (self->values[6] > 0) {
            self->values[6]--;
        }
        if (self->values[1] == 0) {
            if (keyPress.up == 1) {
                self->values[2] = 0;
                self->values[3]--;
                if (self->values[3] < 0) {
                    self->values[3] = 69;
                }
            } else {
                if (keyPress.down == 1) {
                    self->values[2] = 0;
                    self->values[3]++;
                    if (self->values[3] > 69) {
                        self->values[3] = 0;
                    }
                }
            }
            if (keyDown.up == 1) {
                self->values[2]++;
                if (self->values[2] == 8) {
                    self->values[2] = 0;
                    self->values[3]--;
                    if (self->values[3] < 0) {
                        self->values[3] = 69;
                    }
                }
            } else {
                if (keyDown.down == 1) {
                    self->values[2]++;
                    if (self->values[2] == 8) {
                        self->values[2] = 0;
                        self->values[3]++;
                        if (self->values[3] > 69) {
                            self->values[3] = 0;
                        }
                    }
                }
            }
            if (keyPress.left == 1) {
                self->values[1] = 1;
            }
            if (keyPress.right == 1) {
                self->values[1] = 1;
            }
            scriptEng.tempValue[0] = keyPress.A;
            scriptEng.tempValue[0] |= keyPress.B;
            scriptEng.tempValue[0] |= keyPress.C;
            if (scriptEng.tempValue[0] == 1) {
                SoundTest_CheckSecret();
                if (self->state == 2) {
                    scriptEng.tempValue[2] = self->values[3];
                    if (scriptEng.tempValue[2] >= 28) {
                        scriptEng.tempValue[2] += 1;
                    }
                    PlaySfx(scriptEng.tempValue[2], 0);
                    StopMusic();
                }
            }
        } else {
            if (keyPress.up == 1) {
                self->values[2] = 0;
                self->values[4]--;
                if (self->values[4] < 0) {
                    self->values[4] = 37;
                }
            } else {
                if (keyPress.down == 1) {
                    self->values[2] = 0;
                    self->values[4]++;
                    if (self->values[4] > 37) {
                        self->values[4] = 0;
                    }
                }
            }
            if (keyDown.up == 1) {
                self->values[2]++;
                if (self->values[2] == 8) {
                    self->values[2] = 0;
                    self->values[4]--;
                    if (self->values[4] < 0) {
                        self->values[4] = 37;
                    }
                }
            } else {
                if (keyDown.down == 1) {
                    self->values[2]++;
                    if (self->values[2] == 8) {
                        self->values[2] = 0;
                        self->values[4]++;
                        if (self->values[4] > 37) {
                            self->values[4] = 0;
                        }
                    }
                }
            }
            if (keyPress.left == 1) {
                self->values[1] = 0;
            }
            if (keyPress.right == 1) {
                self->values[1] = 0;
            }
            scriptEng.tempValue[0] = keyPress.A;
            scriptEng.tempValue[0] |= keyPress.B;
            scriptEng.tempValue[0] |= keyPress.C;
            if (scriptEng.tempValue[0] == 1) {
                if (self->values[6] == 0) {
                    SoundTest_CheckSecret();
                    if (self->state == 2) {
                        SoundTest_PlayTrack();
                        self->values[6] = 60;
                    }
                }
            }
        }
        if (keyPress.start == 1) {
            SoundTest_CheckSecret();
            if (self->state == 2) {
                StopMusic();
                self->state++;
            }
        }
        break;
        case 3:
        if (self->values[0] < 288) {
            self->values[0] += 8;
        } else {
            GVar("Options.GameMode") = 0;
            stageListPosition = 1;
            stageMode = STAGEMODE_LOAD;
        }
        scriptEng.tempValue[0] = self->values[0];
        if (scriptEng.tempValue[0] > 255) {
            scriptEng.tempValue[0] = 255;
        }
        SetFade(0, 0, 0, scriptEng.tempValue[0]);
        break;
        case 4:
        if (self->values[0] < 288) {
            self->values[0] += 16;
        } else {
            self->type = TypeNameID("Blank Object");
            if (self->values[7] > 4) {
                CreateTempObject(TypeNameID("Secret Image 2"), 0, self->XPos, self->YPos);
            } else {
                CreateTempObject(TypeNameID("Secret Image"), self->values[7], self->XPos, self->YPos);
            }
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 5:
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
            PlaySfx(19, 0);
        }
        break;
        case 6:
        if (self->values[0] < 1024) {
            self->values[0] += 8;
        } else {
            self->type = TypeNameID("Blank Object");
            GVar("Fade_Colour") = 208;
            GVar("Fade_Colour") <<= 16;
            scriptEng.tempValue[0] = 255;
            scriptEng.tempValue[0] <<= 8;
            GVar("Fade_Colour") += scriptEng.tempValue[0];
            GVar("Fade_Colour") += 224;
            GVar("Options.GameMode") = 0;
            activeStageList = 3;
            stageListPosition = 7;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(208, 255, 224, self->values[0]);
        break;
    }
}

void O_Secrets_SoundTest::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    while (scriptEng.tempValue[0] < 240) {
        scriptEng.tempValue[1] = 0;
        while (scriptEng.tempValue[1] < SCREEN_XSIZE) {
            DrawSprite_ScreenXY(15, scriptEng.tempValue[1], scriptEng.tempValue[0]);
            scriptEng.tempValue[1] += 224;
        }
        scriptEng.tempValue[0] += 48;
    }
    DrawSprite_ScreenXY(16, SCREEN_CENTERX, 64);
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 118;
    if (self->values[1] == 0) {
        DrawSprite_ScreenXY(11, scriptEng.tempValue[0], 96);
    } else {
        DrawSprite_ScreenXY(10, scriptEng.tempValue[0], 96);
    }
    scriptEng.tempValue[0] += 56;
    scriptEng.tempValue[1] = self->values[3];
    scriptEng.tempValue[1] /= 10;
    DrawSprite_ScreenXY(scriptEng.tempValue[1], scriptEng.tempValue[0], 96);
    scriptEng.tempValue[0] += 8;
    scriptEng.tempValue[1] = self->values[3];
    scriptEng.tempValue[1] %= 10;
    DrawSprite_ScreenXY(scriptEng.tempValue[1], scriptEng.tempValue[0], 96);
    scriptEng.tempValue[0] += 102;
    if (self->values[1] == 1) {
        DrawSprite_ScreenXY(13, scriptEng.tempValue[0], 96);
    } else {
        DrawSprite_ScreenXY(12, scriptEng.tempValue[0], 96);
    }
    scriptEng.tempValue[0] += 48;
    scriptEng.tempValue[1] = self->values[4];
    scriptEng.tempValue[1] /= 10;
    DrawSprite_ScreenXY(scriptEng.tempValue[1], scriptEng.tempValue[0], 96);
    scriptEng.tempValue[0] += 8;
    scriptEng.tempValue[1] = self->values[4];
    scriptEng.tempValue[1] %= 10;
    DrawSprite_ScreenXY(scriptEng.tempValue[1], scriptEng.tempValue[0], 96);
}

void O_Secrets_SoundTest::SoundTest_PlayTrack()
{
    Entity *self = Self();

    StopMusic();
    switch (self->values[4]) {
        case 0:
        SetMusicTrack_Script("JP/R1A.ogg", 0, 142428);
        SetMusicTrack_Script("US/R1A.ogg", 1, 153038);
        break;
        case 1:
        SetMusicTrack_Script("R1B.ogg", 0, 354890);
        SetMusicTrack_Script("R1B.ogg", 1, 354890);
        break;
        case 2:
        SetMusicTrack_Script("JP/R1C.ogg", 0, 142902);
        SetMusicTrack_Script("US/R1C.ogg", 1, 152346);
        break;
        case 3:
        SetMusicTrack_Script("JP/R1D.ogg", 0, 1);
        SetMusicTrack_Script("US/R1D.ogg", 1, 774998);
        break;
        case 4:
        SetMusicTrack_Script("JP/R3A.ogg", 0, 358725);
        SetMusicTrack_Script("US/R3A.ogg", 1, 1);
        break;
        case 5:
        SetMusicTrack_Script("R3B.ogg", 0, 166278);
        SetMusicTrack_Script("R3B.ogg", 1, 166278);
        break;
        case 6:
        SetMusicTrack_Script("JP/R3C.ogg", 0, 1);
        SetMusicTrack_Script("US/R3C.ogg", 1, 173494);
        break;
        case 7:
        SetMusicTrack_Script("JP/R3D.ogg", 0, 717648);
        SetMusicTrack_Script("US/R3D.ogg", 1, 1);
        break;
        case 8:
        SetMusicTrack_Script("JP/R4A.ogg", 0, 1);
        SetMusicTrack_Script("US/R4A.ogg", 1, 415148);
        break;
        case 9:
        SetMusicTrack_Script("R4B.ogg", 0, 1);
        SetMusicTrack_Script("R4B.ogg", 1, 1);
        break;
        case 10:
        SetMusicTrack_Script("JP/R4C.ogg", 0, 1);
        SetMusicTrack_Script("US/R4C.ogg", 1, 1);
        break;
        case 11:
        SetMusicTrack_Script("JP/R4D.ogg", 0, 1);
        SetMusicTrack_Script("US/R4D.ogg", 1, 145616);
        break;
        case 12:
        SetMusicTrack_Script("JP/R5A.ogg", 0, 1);
        SetMusicTrack_Script("US/R5A.ogg", 1, 1);
        break;
        case 13:
        SetMusicTrack_Script("R5B.ogg", 0, 619562);
        SetMusicTrack_Script("R5B.ogg", 1, 619562);
        break;
        case 14:
        SetMusicTrack_Script("JP/R5C.ogg", 0, 367046);
        SetMusicTrack_Script("US/R5C.ogg", 1, 705830);
        break;
        case 15:
        SetMusicTrack_Script("JP/R5D.ogg", 0, 1);
        SetMusicTrack_Script("US/R5D.ogg", 1, 93672);
        break;
        case 16:
        SetMusicTrack_Script("JP/R6A.ogg", 0, 1);
        SetMusicTrack_Script("US/R6A.ogg", 1, 926048);
        break;
        case 17:
        SetMusicTrack_Script("R6B.ogg", 0, 1);
        SetMusicTrack_Script("R6B.ogg", 1, 1);
        break;
        case 18:
        SetMusicTrack_Script("JP/R6C.ogg", 0, 1);
        SetMusicTrack_Script("US/R6C.ogg", 1, 181704);
        break;
        case 19:
        SetMusicTrack_Script("JP/R6D.ogg", 0, 1);
        SetMusicTrack_Script("US/R6D.ogg", 1, 45355);
        break;
        case 20:
        SetMusicTrack_Script("JP/R7A.ogg", 0, 1);
        SetMusicTrack_Script("US/R7A.ogg", 1, 617728);
        break;
        case 21:
        SetMusicTrack_Script("R7B.ogg", 0, 730678);
        SetMusicTrack_Script("R7B.ogg", 1, 730678);
        break;
        case 22:
        SetMusicTrack_Script("JP/R7C.ogg", 0, 103060);
        SetMusicTrack_Script("US/R7C.ogg", 1, 136670);
        break;
        case 23:
        SetMusicTrack_Script("JP/R7D.ogg", 0, 1);
        SetMusicTrack_Script("US/R7D.ogg", 1, 92324);
        break;
        case 24:
        SetMusicTrack_Script("JP/R8A.ogg", 0, 146030);
        SetMusicTrack_Script("US/R8A.ogg", 1, 1);
        break;
        case 25:
        SetMusicTrack_Script("R8B.ogg", 0, 145748);
        SetMusicTrack_Script("R8B.ogg", 1, 145748);
        break;
        case 26:
        SetMusicTrack_Script("JP/R8C.ogg", 0, 1);
        SetMusicTrack_Script("US/R8C.ogg", 1, 1);
        break;
        case 27:
        SetMusicTrack_Script("JP/R8D.ogg", 0, 1);
        SetMusicTrack_Script("US/R8D.ogg", 1, 563962);
        break;
        case 28:
        SetMusicTrack_Script("JP/Boss.ogg", 0, 1);
        SetMusicTrack_Script("US/Boss.ogg", 1, 196526);
        break;
        case 29:
        SetMusicTrack_Script("JP/FinalBoss.ogg", 0, 1);
        SetMusicTrack_Script("US/FinalBoss.ogg", 1, 1);
        break;
        case 30:
        SetMusicTrack_Script("JP/TitleScreen.ogg", 0, 0);
        SetMusicTrack_Script("US/TitleScreen.ogg", 1, 0);
        break;
        case 31:
        SetMusicTrack_Script("JP/ZoneComplete.ogg", 0, 0);
        SetMusicTrack_Script("US/ZoneComplete.ogg", 1, 0);
        break;
        case 32:
        SetMusicTrack_Script("JP/SpeedShoes.ogg", 0, 0);
        SetMusicTrack_Script("US/SpeedShoes.ogg", 1, 0);
        break;
        case 33:
        SetMusicTrack_Script("JP/Invincibility.ogg", 0, 0);
        SetMusicTrack_Script("US/Invincibility.ogg", 1, 0);
        break;
        case 34:
        SetMusicTrack_Script("JP/GameOver.ogg", 0, 0);
        SetMusicTrack_Script("US/GameOver.ogg", 1, 0);
        break;
        case 35:
        SetMusicTrack_Script("JP/SpecialStage.ogg", 0, 1);
        SetMusicTrack_Script("US/SpecialStage.ogg", 1, 270972);
        break;
        case 36:
        SetMusicTrack_Script("JP/DAGarden.ogg", 0, 1);
        SetMusicTrack_Script("US/DAGarden.ogg", 1, 117382);
        break;
        case 37:
        SetMusicTrack_Script("JP/TimeAttack.ogg", 0, 100512);
        SetMusicTrack_Script("US/DAGarden.ogg", 1, 117382);
        break;
    }
    PlayMusic(GVar("Options.Soundtrack"));
}

void O_Secrets_SoundTest::SoundTest_CheckSecret()
{
    Entity *self = Self();

    if (self->values[3] == 4) {
        if (self->values[4] == 21) {
            StopMusic();
            SetMusicTrack_Script("JP/FinalBoss.ogg", 0, 1);
            SetMusicTrack_Script("US/FinalBoss.ogg", 1, 1);
            self->values[7] = 0;
            self->state = 4;
        }
    }
    if (self->values[3] == 12) {
        if (self->values[4] == 25) {
            StopMusic();
            SetMusicTrack_Script("JP/Boss.ogg", 0, 1);
            SetMusicTrack_Script("US/Boss.ogg", 1, 196526);
            self->values[7] = 1;
            self->state = 4;
        }
    }
    if (self->values[3] == 11) {
        if (self->values[4] == 9) {
            StopMusic();
            SetMusicTrack_Script("JP/R1C.ogg", 0, 142902);
            SetMusicTrack_Script("US/R1C.ogg", 1, 152346);
            self->values[7] = 2;
            self->state = 4;
        }
    }
    if (self->values[3] == 3) {
        if (self->values[4] == 1) {
            StopMusic();
            SetMusicTrack_Script("JP/R8A.ogg", 0, 146030);
            SetMusicTrack_Script("US/R8A.ogg", 1, 1);
            self->values[7] = 3;
            self->state = 4;
        }
    }
    if (self->values[3] == 12) {
        if (self->values[4] == 11) {
            StopMusic();
            SetMusicTrack_Script("JP/R5C.ogg", 0, 367046);
            SetMusicTrack_Script("US/R5C.ogg", 1, 705830);
            debugMode = 1;
            self->values[7] = 4;
            self->state = 4;
        }
    }
    if (self->values[3] == 32) {
        if (self->values[4] == 8) {
            StopMusic();
            SetMusicTrack_Script("JP/R5C.ogg", 0, 367046);
            SetMusicTrack_Script("US/R5C.ogg", 1, 705830);
            playerListPos = 1;
            self->values[7] = 5;
            self->state = 4;
        }
    }
    if (self->values[3] == 7) {
        if (self->values[4] == 7) {
            StopMusic();
            PlaySfx(globalSFXCount + 41, 0);
            self->state = 5;
            SetupMenu_Script(0, 0, 3, 1);
            AddMenuEntry_Script(0, "WELCOME TO THE SECRET SPECIAL STAGE", 1);
            CreateTempObject(TypeNameID("Message Text"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos = (SCREEN_CENTERX) << 16;
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos = (152) << 16;
        }
    }
}

const Native::NativeFunctionDef O_Secrets_SoundTest::funcs[2] = {
    { "SoundTest_PlayTrack", O_Secrets_SoundTest::SoundTest_PlayTrack },
    { "SoundTest_CheckSecret", O_Secrets_SoundTest::SoundTest_CheckSecret },
};

#endif // RETRO_USE_NATIVE_OBJECTS
