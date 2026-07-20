#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Title_Start.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Start.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Title_Start::ObjectStartup()
{
    LoadSpriteSheet("Title/Title.gif");
    switch (Engine.language) {
        case 0:
        case 5:
        AddSpriteFrame(-43, 0, 87, 11, 106, 103);
        AddSpriteFrame(-56, 0, 117, 11, 106, 91);
        break;
        case 1:
        AddSpriteFrame(-60, 0, 120, 11, 391, 387);
        AddSpriteFrame(-94, 0, 189, 11, 322, 399);
        break;
        case 2:
        AddSpriteFrame(-44, 0, 88, 11, 270, 411);
        AddSpriteFrame(-76, 0, 152, 11, 359, 411);
        break;
        case 3:
        AddSpriteFrame(-52, -2, 106, 13, 405, 373);
        AddSpriteFrame(-87, 0, 175, 11, 336, 423);
        break;
        case 4:
        AddSpriteFrame(-43, 0, 87, 11, 274, 435);
        AddSpriteFrame(-74, 0, 149, 11, 362, 435);
        break;
    }
    AddSpriteFrame(-48, 0, 97, 11, 414, 361);
    AddSpriteFrame(-88, -8, 88, 8, 423, 311);
}

void O_Title_Start::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        CheckTouchRect_Script(0, 0, SCREEN_XSIZE, 240);
        if (keyPress.start == 1) {
            CheckResult() = 0;
        }
        if (CheckResult() > -1) {
            self->state = 1;
            StopMusic();
            PlaySfx(27, 0);
            HapticEffect_Script(31, 0, 0, 0);
        } else {
            self->values[3]++;
            if (self->values[3] == 1550) {
                self->state = 4;
            }
        }
        if (RETRO_GAMEPLATFORMID == 6) {
            if (keyPress.B == 1) {
                Engine.Callback(7);
            }
        }
        break;
        case 1:
        self->values[0] += 4;
        if (self->values[0] == 384) {
            stageListPosition = 1;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 2:
        self->values[0] += 4;
        if (self->values[0] == 384) {
            GVar("Options.GameMode") = 0;
            stageListPosition = 3;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 3:
        self->values[0] += 4;
        if (self->values[0] == 384) {
            GVar("Options.GameMode") = 0;
            stageListPosition = 4;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
        case 4:
        self->values[0] += 4;
        if (self->values[0] == 384) {
            Engine.hapticsEnabled = 0;
            GVar("Fade_Colour") = 0x000000;
            GVar("Player.Score") = 0;
            GVar("Player.Lives") = 3;
            GVar("Player.ScoreBonus") = 50000;
            GVar("Transporter_Destroyed") = 0;
            GVar("MetalSonic_Destroyed") = 0;
            GVar("Good_Future") = 0;
            GVar("Options.GameMode") = 0;
            GVar("Options.AttractMode") = 1;
            if (RETRO_GAMEPLATFORMID == 5) {
                if (Engine.trialMode == 1) {
                    GVar("Options.DemoNumber") = 0;
                }
            }
            switch (GVar("Options.DemoNumber")) {
                case 0:
                activeStageList = 1;
                stageListPosition = 0;
                break;
                case 1:
                activeStageList = 3;
                stageListPosition = 0;
                break;
                case 2:
                activeStageList = 1;
                stageListPosition = 28;
                break;
                case 3:
                activeStageList = 3;
                stageListPosition = 5;
                break;
                case 4:
                activeStageList = 1;
                stageListPosition = 64;
                break;
            }
            GVar("Options.DemoNumber")++;
            GVar("Options.DemoNumber") %= 5;
            stageMode = STAGEMODE_LOAD;
        }
        SetFade(0, 0, 0, self->values[0]);
        break;
    }
}

void O_Title_Start::ObjectDraw()
{
    Entity *self = Self();

    self->animationTimer++;
    if (self->animationTimer > 59) {
        self->animationTimer = 0;
    }
    if (self->animationTimer > 29) {
        DrawSprite_Frame(0);
    }
}

void O_Title_Start::TouchStart_HandleCheatCodes()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = 0;
    if (keyPress.up == 1) {
        scriptEng.tempValue[0] = 1;
    }
    if (keyPress.down == 1) {
        scriptEng.tempValue[0] = 2;
    }
    if (keyPress.left == 1) {
        scriptEng.tempValue[0] = 3;
    }
    if (keyPress.right == 1) {
        scriptEng.tempValue[0] = 4;
    }
    if (keyPress.A == 1) {
        scriptEng.tempValue[0] = 5;
    }
    if (keyPress.B == 1) {
        scriptEng.tempValue[0] = 6;
    }
    if (keyPress.C == 1) {
        scriptEng.tempValue[0] = 7;
    }
    switch (self->values[1]) {
        case 0:
        if (scriptEng.tempValue[0] == 1) {
            self->values[1]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[1] = 0;
            }
        }
        break;
        case 1:
        if (scriptEng.tempValue[0] == 2) {
            self->values[1]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[1] = 0;
            }
        }
        break;
        case 2:
        if (scriptEng.tempValue[0] == 2) {
            self->values[1]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[1] = 0;
            }
        }
        break;
        case 3:
        if (scriptEng.tempValue[0] == 3) {
            self->values[1]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[1] = 0;
            }
        }
        break;
        case 4:
        if (scriptEng.tempValue[0] == 4) {
            self->values[1]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[1] = 0;
            }
        }
        break;
        case 5:
        if (scriptEng.tempValue[0] == 6) {
            self->values[1] = 0;
            self->state = 2;
            StopMusic();
            PlaySfx(1, 0);
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[1] = 0;
            }
        }
        break;
    }
    switch (self->values[2]) {
        case 0:
        if (scriptEng.tempValue[0] == 2) {
            self->values[2]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[2] = 0;
            }
        }
        break;
        case 1:
        if (scriptEng.tempValue[0] == 2) {
            self->values[2]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[2] = 0;
            }
        }
        break;
        case 2:
        if (scriptEng.tempValue[0] == 2) {
            self->values[2]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[2] = 0;
            }
        }
        break;
        case 3:
        if (scriptEng.tempValue[0] == 3) {
            self->values[2]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[2] = 0;
            }
        }
        break;
        case 4:
        if (scriptEng.tempValue[0] == 4) {
            self->values[2]++;
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[2] = 0;
            }
        }
        break;
        case 5:
        if (scriptEng.tempValue[0] == 5) {
            self->values[2] = 0;
            self->state = 3;
            StopMusic();
            PlaySfx(1, 0);
        } else {
            if (scriptEng.tempValue[0] != 0) {
                self->values[2] = 0;
            }
        }
        break;
    }
}

const Native::NativeFunctionDef O_Title_Start::funcs[1] = {
    { "TouchStart_HandleCheatCodes", O_Title_Start::TouchStart_HandleCheatCodes },
};

#endif // RETRO_USE_NATIVE_OBJECTS
