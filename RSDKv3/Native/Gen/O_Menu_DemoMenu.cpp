#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_DemoMenu.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from DemoMenu.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_DemoMenu::ObjectStartup()
{
    LoadSpriteSheet("Menu/MenuGfx1_EN.gif");
    AddSpriteFrame(0, 0, 68, 90, 321, 1);
    AddSpriteFrame(0, 0, 68, 90, 321, 92);
    AddSpriteFrame(0, 0, 68, 90, 321, 183);
    AddSpriteFrame(0, 0, 36, 13, 219, 440);
    AddSpriteFrame(61, 0, 30, 5, 219, 434);
    AddSpriteFrame(0, 0, 66, 14, 211, 349);
    AddSpriteFrame(17, 0, 22, 4, 169, 435);
    AddSpriteFrame(-1, -1, 70, 92, 321, 274);
    AddSpriteFrame(-1, -1, 0, 0, 325, 279);
    AddSpriteFrame(0, -10, 8, 13, 258, 418);
    AddSpriteFrame(2, 2, 64, 58, 1, 1);
    AddSpriteFrame(0, 0, 6, 8, 244, 400);
    AddSpriteFrame(0, 0, 6, 8, 251, 400);
    AddSpriteFrame(0, 0, 6, 8, 258, 400);
    AddSpriteFrame(0, 0, 6, 8, 265, 400);
    AddSpriteFrame(0, 0, 6, 8, 244, 409);
    AddSpriteFrame(0, 0, 6, 8, 251, 409);
    AddSpriteFrame(0, 0, 6, 8, 258, 409);
    AddSpriteFrame(0, 0, 6, 8, 265, 409);
    AddSpriteFrame(0, 0, 6, 8, 244, 418);
    AddSpriteFrame(0, 0, 6, 8, 251, 418);
    AddSpriteFrame(0, 0, 8, 16, 154, 400);
    AddSpriteFrame(0, 0, 8, 16, 163, 400);
    AddSpriteFrame(0, 0, 8, 16, 172, 400);
    AddSpriteFrame(0, 0, 8, 16, 181, 400);
    AddSpriteFrame(0, 0, 8, 16, 190, 400);
    AddSpriteFrame(0, 0, 8, 16, 199, 400);
    AddSpriteFrame(0, 0, 8, 16, 208, 400);
    AddSpriteFrame(0, 0, 8, 16, 217, 400);
    AddSpriteFrame(0, 0, 8, 16, 226, 400);
    AddSpriteFrame(0, 0, 8, 16, 235, 400);
    AddSpriteFrame(0, 0, 8, 16, 154, 417);
    AddSpriteFrame(0, 0, 8, 16, 163, 417);
    AddSpriteFrame(0, 0, 8, 16, 172, 417);
    AddSpriteFrame(0, 0, 8, 16, 181, 417);
    AddSpriteFrame(0, 0, 8, 16, 190, 417);
    AddSpriteFrame(0, 0, 8, 16, 199, 417);
    AddSpriteFrame(0, 0, 8, 16, 208, 417);
    AddSpriteFrame(0, 0, 8, 16, 217, 417);
    AddSpriteFrame(0, 0, 8, 16, 226, 417);
    AddSpriteFrame(0, 0, 8, 16, 235, 417);
}

void O_Menu_DemoMenu::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (GVar("Options.PhysicalControls") == 0) {
            self->values[1] = -1;
        } else {
            self->values[1] = 0;
        }
        if (self->values[0] == 0) {
            self->values[3] = 9000;
            self->values[2] = saveRAM[48];
            self->values[2] += saveRAM[49];
            if (self->values[2] == 0) {
                saveRAM[48] = 60000;
                saveRAM[49] = 60000;
                self->values[2] = 120000;
            }
        }
        if (self->values[0] < 256) {
            self->alpha = self->values[0];
            self->values[0] += 6;
        } else {
            self->values[0] = 0;
            self->alpha = 255;
            self->state++;
        }
        break;
        case 1:
        if (GVar("Options.PhysicalControls") == 1) {
            if (keyPress.left == 1) {
                self->values[1]--;
                if (self->values[1] < 0) {
                    self->values[1] = 2;
                }
                PlaySfx(23, 0);
            }
            if (keyPress.right == 1) {
                self->values[1]++;
                if (self->values[1] > 2) {
                    self->values[1] = 0;
                }
                PlaySfx(23, 0);
            }
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            if (CheckResult() > -1) {
                GVar("Options.PhysicalControls") = 0;
                self->values[1] = -1;
            }
        } else {
            CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
            scriptEng.tempValue[3] = CheckResult();
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] -= 113;
            scriptEng.tempValue[1] = SCREEN_CENTERX;
            scriptEng.tempValue[1] -= 45;
            CheckTouchRect_Script(scriptEng.tempValue[0], 67, scriptEng.tempValue[1], 157);
            if (CheckResult() > -1) {
                self->values[1] = 0;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 0) {
                        keyPress.start = 1;
                    }
                } else {
                    if (self->values[1] == 0) {
                        self->values[1] = -1;
                    }
                }
            }
            scriptEng.tempValue[0] = SCREEN_CENTERX;
            scriptEng.tempValue[0] -= 35;
            scriptEng.tempValue[1] = SCREEN_CENTERX;
            scriptEng.tempValue[1] += 35;
            CheckTouchRect_Script(scriptEng.tempValue[0], 67, scriptEng.tempValue[1], 157);
            if (CheckResult() > -1) {
                self->values[1] = 1;
            } else {
                if (scriptEng.tempValue[3] < 0) {
                    if (self->values[1] == 1) {
                        keyPress.start = 1;
                    }
                } else {
                    if (self->values[1] == 1) {
                        self->values[1] = -1;
                    }
                }
            }
            if (self->values[2] <= self->values[3]) {
                scriptEng.tempValue[0] = SCREEN_CENTERX;
                scriptEng.tempValue[0] += 45;
                scriptEng.tempValue[1] = SCREEN_CENTERX;
                scriptEng.tempValue[1] += 113;
                CheckTouchRect_Script(scriptEng.tempValue[0], 67, scriptEng.tempValue[1], 157);
                if (CheckResult() > -1) {
                    self->values[1] = 2;
                } else {
                    if (scriptEng.tempValue[3] < 0) {
                        if (self->values[1] == 2) {
                            keyPress.start = 1;
                        }
                    } else {
                        if (self->values[1] == 2) {
                            self->values[1] = -1;
                        }
                    }
                }
            }
            CallScriptFunctionNamed("MenuHeading_CheckTouchBack", scriptSub);
            if (keyPress.left == 1) {
                self->values[1] = 1;
                GVar("Options.PhysicalControls") = 1;
            }
            if (keyPress.right == 1) {
                self->values[1] = 0;
                GVar("Options.PhysicalControls") = 1;
            }
        }
        CheckResult() = 0;
        if (self->values[1] > -1) {
            if (keyPress.start == 1) {
                if (self->values[1] == 2) {
                    if (self->values[2] <= self->values[3]) {
                        CheckResult() = 1;
                    }
                } else {
                    CheckResult() = 1;
                }
            }
            if (keyPress.A == 1) {
                if (self->values[1] == 2) {
                    if (self->values[2] <= self->values[3]) {
                        CheckResult() = 1;
                    }
                } else {
                    CheckResult() = 1;
                }
            }
        }
        if (CheckResult() == 1) {
            self->state++;
            StopMusic();
            PlaySfx(27, 0);
        }
        if (keyPress.B == 1) {
            self->values[0] = 248;
            self->state = 3;
            PlaySfx(globalSFXCount + 1, 0);
        }
        break;
        case 2:
        if (self->animationTimer < 30) {
            self->animationTimer++;
        } else {
            self->animationTimer = 0;
            self->state = 4;
        }
        break;
        case 3:
        if (self->values[0] > 0) {
            self->alpha = self->values[0];
            self->values[0] -= 8;
        } else {
            self->type = TypeNameID("Blank Object");
            objectEntityList[objectLoop - 1].state = 3;
            objectEntityList[34].state = 1;
            objectEntityList[35].state = 1;
            objectEntityList[36].state = 1;
            objectEntityList[37].state = 1;
            objectEntityList[38].state = 1;
            objectEntityList[39].state = 1;
            objectEntityList[40].state = 1;
            objectEntityList[41].state = 1;
            objectEntityList[42].state = 1;
            objectEntityList[33].state = 1;
            objectEntityList[33].propertyValue = 5;
        }
        break;
        case 4:
        if (self->values[0] < 320) {
            self->values[0] += 8;
        } else {
            GVar("Options.GameMode") = 3;
            GVar("Player.Score") = 0;
            GVar("Player.Lives") = 3;
            GVar("Player.ScoreBonus") = 50000;
            GVar("Transporter_Destroyed") = 0;
            GVar("MetalSonic_Destroyed") = 0;
            GVar("TimeAttack.Round") = self->values[1];
            activeStageList = 1;
            switch (self->values[1]) {
                case 0:
                stageListPosition = 0;
                GVar("Good_Future") = 0;
                break;
                case 1:
                stageListPosition = 34;
                GVar("Good_Future") = 0;
                break;
                case 2:
                stageListPosition = 38;
                GVar("Good_Future") = 1;
                break;
            }
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
    }
}

void O_Menu_DemoMenu::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 113;
    DrawSpriteScreenFX_Script(0, FX_INK, scriptEng.tempValue[0], 57);
    scriptEng.tempValue[2] = 33;
    scriptEng.tempValue[3] = 267;
    DemoMenu_StagePortraitMovement();
    DrawSpriteScreenFX_Script(10, FX_INK, scriptEng.tempValue[0], 57);
    DrawSpriteScreenFX_Script(6, FX_INK, scriptEng.tempValue[0], 134);
    scriptEng.tempValue[1] = saveRAM[48];
    DemoMenu_StageTimeRecord();
    scriptEng.tempValue[0] += 78;
    DrawSpriteScreenFX_Script(1, FX_INK, scriptEng.tempValue[0], 57);
    scriptEng.tempValue[2] = 33;
    scriptEng.tempValue[3] = 396;
    DemoMenu_StagePortraitMovement();
    DrawSpriteScreenFX_Script(10, FX_INK, scriptEng.tempValue[0], 57);
    DrawSpriteScreenFX_Script(6, FX_INK, scriptEng.tempValue[0], 134);
    scriptEng.tempValue[1] = saveRAM[49];
    DemoMenu_StageTimeRecord();
    scriptEng.tempValue[0] += 78;
    DrawSpriteScreenFX_Script(2, FX_INK, scriptEng.tempValue[0], 57);
    scriptEng.tempValue[2] = 321;
    scriptEng.tempValue[3] = 399;
    DemoMenu_StagePortraitMovement();
    DrawSpriteScreenFX_Script(10, FX_INK, scriptEng.tempValue[0], 57);
    self->rotation += 129;
    self->rotation &= 511;
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[1] = self->animationTimer;
    scriptEng.tempValue[1] &= 3;
    scriptEng.tempValue[1] >>= 1;
    scriptEng.tempValue[1] += 7;
    switch (self->values[1]) {
        case 0:
        scriptEng.tempValue[0] -= 113;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], 57);
        break;
        case 1:
        scriptEng.tempValue[0] -= 35;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], 57);
        break;
        case 2:
        scriptEng.tempValue[0] += 43;
        DrawSpriteScreenFX_Script(scriptEng.tempValue[1], FX_INK, scriptEng.tempValue[0], 57);
        break;
    }
    if (self->values[2] > self->values[3]) {
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] += 97;
        DrawSpriteScreenFX_Script(9, FX_INK, scriptEng.tempValue[0], 128);
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 113;
        DrawSpriteScreenFX_Script(3, FX_INK, scriptEng.tempValue[0], 155);
        DrawSpriteScreenFX_Script(4, FX_INK, scriptEng.tempValue[0], 155);
        scriptEng.tempValue[0] += 44;
        self->frame = 21;
        scriptEng.tempValue[1] = self->values[2];
        DemoMenu_StageTotalTimeRecord();
        scriptEng.tempValue[0] += 114;
        DrawSpriteScreenFX_Script(5, FX_INK, scriptEng.tempValue[0], 154);
        scriptEng.tempValue[0] += 11;
        self->frame = 31;
        scriptEng.tempValue[1] = self->values[3];
        DemoMenu_StageTotalTimeRecord();
    } else {
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] -= 113;
        DrawSpriteScreenFX_Script(3, FX_INK, scriptEng.tempValue[0], 155);
        DrawSpriteScreenFX_Script(4, FX_INK, scriptEng.tempValue[0], 155);
        scriptEng.tempValue[0] += 44;
        self->frame = 21;
        scriptEng.tempValue[1] = self->values[2];
        DemoMenu_StageTotalTimeRecord();
    }
}

void O_Menu_DemoMenu::DemoMenu_StageTimeRecord()
{
    scriptEng.tempValue[4] = scriptEng.tempValue[0];
    scriptEng.tempValue[4] += 4;
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] /= 6000;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] /= 10;
    scriptEng.tempValue[3] += 11;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 136);
    scriptEng.tempValue[4] += 6;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] %= 10;
    scriptEng.tempValue[3] += 11;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 136);
    scriptEng.tempValue[4] += 11;
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] /= 100;
    scriptEng.tempValue[2] %= 60;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] /= 10;
    scriptEng.tempValue[3] += 11;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 136);
    scriptEng.tempValue[4] += 6;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] %= 10;
    scriptEng.tempValue[3] += 11;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 136);
    scriptEng.tempValue[4] += 13;
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] %= 100;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] /= 10;
    scriptEng.tempValue[3] += 11;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 136);
    scriptEng.tempValue[4] += 6;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] %= 10;
    scriptEng.tempValue[3] += 11;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 136);
}

void O_Menu_DemoMenu::DemoMenu_StageTotalTimeRecord()
{
    Entity *self = Self();

    scriptEng.tempValue[4] = scriptEng.tempValue[0];
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] /= 6000;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] /= 10;
    scriptEng.tempValue[3] += self->frame;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 155);
    scriptEng.tempValue[4] += 8;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] %= 10;
    scriptEng.tempValue[3] += self->frame;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 155);
    scriptEng.tempValue[4] += 15;
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] /= 100;
    scriptEng.tempValue[2] %= 60;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] /= 10;
    scriptEng.tempValue[3] += self->frame;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 155);
    scriptEng.tempValue[4] += 8;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] %= 10;
    scriptEng.tempValue[3] += self->frame;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 155);
    scriptEng.tempValue[4] += 17;
    scriptEng.tempValue[2] = scriptEng.tempValue[1];
    scriptEng.tempValue[2] %= 100;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] /= 10;
    scriptEng.tempValue[3] += self->frame;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 155);
    scriptEng.tempValue[4] += 8;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    scriptEng.tempValue[3] %= 10;
    scriptEng.tempValue[3] += self->frame;
    DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_INK, scriptEng.tempValue[4], 155);
}

void O_Menu_DemoMenu::DemoMenu_StagePortraitMovement()
{
    Entity *self = Self();

    scriptEng.tempValue[4] = Cos512(self->rotation);
    scriptEng.tempValue[4] >>= 4;
    scriptEng.tempValue[4] += scriptEng.tempValue[2];
    scriptEng.tempValue[5] = Sin512(self->rotation);
    scriptEng.tempValue[5] *= 3;
    scriptEng.tempValue[5] >>= 6;
    scriptEng.tempValue[5] += scriptEng.tempValue[3];
    self->rotation += 128;
    self->rotation &= 511;
    EditFrame_Script(10, 2, 2, 64, 58, scriptEng.tempValue[4], scriptEng.tempValue[5]);
}

const Native::NativeFunctionDef O_Menu_DemoMenu::funcs[3] = {
    { "DemoMenu_StageTimeRecord", O_Menu_DemoMenu::DemoMenu_StageTimeRecord },
    { "DemoMenu_StageTotalTimeRecord", O_Menu_DemoMenu::DemoMenu_StageTotalTimeRecord },
    { "DemoMenu_StagePortraitMovement", O_Menu_DemoMenu::DemoMenu_StagePortraitMovement },
};

#endif // RETRO_USE_NATIVE_OBJECTS
