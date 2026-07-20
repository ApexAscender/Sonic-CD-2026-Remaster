#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Menu_MenuButton.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from MenuButton.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Menu_MenuButton::ObjectStartup()
{
    switch (Engine.language) {
        case 0:
        LoadSpriteSheet("Menu/MenuGfx2_EN.gif");
        break;
        case 1:
        LoadSpriteSheet("Menu/MenuGfx2_FR.gif");
        break;
        case 2:
        LoadSpriteSheet("Menu/MenuGfx2_IT.gif");
        break;
        case 3:
        LoadSpriteSheet("Menu/MenuGfx2_DE.gif");
        break;
        case 4:
        LoadSpriteSheet("Menu/MenuGfx2_ES.gif");
        break;
        case 5:
        LoadSpriteSheet("Menu/MenuGfx2_JP.gif");
        break;
    }
    objectEntityList[1].values[2] = 1;
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Menu Button")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].values[4];
        }
        scriptEng.arrayPosition[0]++;
    }
    switch (RETRO_GAMEPLATFORMID) {
        case 0:
        case 1:
        if (GVar("Options.DevMenuFlag") == 1) {
            objectEntityList[34].propertyValue = 1;
            objectEntityList[35].propertyValue = 2;
            objectEntityList[36].propertyValue = 5;
            objectEntityList[37].propertyValue = 10;
            objectEntityList[38].propertyValue = 6;
            objectEntityList[39].propertyValue = 9;
            objectEntityList[1].values[2] = 6;
        } else {
            if (Engine.trialMode == 1) {
                objectEntityList[34].propertyValue = 1;
                objectEntityList[35].propertyValue = 2;
                objectEntityList[36].propertyValue = 3;
                objectEntityList[37].propertyValue = 4;
                objectEntityList[38].propertyValue = 5;
                objectEntityList[39].propertyValue = 10;
                objectEntityList[40].propertyValue = 7;
                objectEntityList[41].propertyValue = 9;
                objectEntityList[1].values[2] = 8;
            } else {
                objectEntityList[34].propertyValue = 1;
                objectEntityList[35].propertyValue = 2;
                objectEntityList[36].propertyValue = 3;
                objectEntityList[37].propertyValue = 4;
                objectEntityList[38].propertyValue = 5;
                objectEntityList[39].propertyValue = 10;
                objectEntityList[40].propertyValue = 6;
                objectEntityList[41].propertyValue = 9;
                objectEntityList[1].values[2] = 8;
            }
        }
        break;
        case 2:
        if (Engine.trialMode == 1) {
            objectEntityList[34].propertyValue = 1;
            objectEntityList[35].propertyValue = 2;
            objectEntityList[36].propertyValue = 3;
            objectEntityList[37].propertyValue = 4;
            objectEntityList[38].propertyValue = 5;
            objectEntityList[39].propertyValue = 10;
            objectEntityList[40].propertyValue = 7;
            objectEntityList[41].propertyValue = 9;
            objectEntityList[1].values[2] = 8;
        } else {
            objectEntityList[34].propertyValue = 1;
            objectEntityList[35].propertyValue = 2;
            objectEntityList[36].propertyValue = 3;
            objectEntityList[37].propertyValue = 4;
            objectEntityList[38].propertyValue = 5;
            objectEntityList[39].propertyValue = 10;
            objectEntityList[40].propertyValue = 6;
            objectEntityList[41].propertyValue = 9;
            objectEntityList[1].values[2] = 8;
        }
        break;
        case 3:
        if (Engine.trialMode == 1) {
            objectEntityList[34].propertyValue = 1;
            objectEntityList[35].propertyValue = 2;
            objectEntityList[36].propertyValue = 3;
            objectEntityList[37].propertyValue = 4;
            objectEntityList[38].propertyValue = 5;
            objectEntityList[39].propertyValue = 10;
            objectEntityList[40].propertyValue = 7;
            objectEntityList[1].values[2] = 7;
        } else {
            objectEntityList[34].propertyValue = 1;
            objectEntityList[35].propertyValue = 2;
            objectEntityList[36].propertyValue = 3;
            objectEntityList[37].propertyValue = 4;
            objectEntityList[38].propertyValue = 5;
            objectEntityList[39].propertyValue = 10;
            objectEntityList[40].propertyValue = 6;
            objectEntityList[1].values[2] = 7;
        }
        break;
        case 5:
        if (Engine.trialMode == 1) {
            objectEntityList[34].propertyValue = 1;
            objectEntityList[35].propertyValue = 5;
            objectEntityList[36].propertyValue = 10;
            objectEntityList[37].propertyValue = 7;
            objectEntityList[38].propertyValue = 9;
            objectEntityList[1].values[2] = 5;
        } else {
            if (Engine.onlineActive == 1) {
                objectEntityList[34].propertyValue = 1;
                objectEntityList[35].propertyValue = 2;
                objectEntityList[36].propertyValue = 4;
                objectEntityList[37].propertyValue = 3;
                objectEntityList[38].propertyValue = 5;
                objectEntityList[39].propertyValue = 10;
                objectEntityList[40].propertyValue = 6;
                objectEntityList[41].propertyValue = 9;
                objectEntityList[1].values[2] = 8;
            } else {
                objectEntityList[34].propertyValue = 1;
                objectEntityList[35].propertyValue = 2;
                objectEntityList[36].propertyValue = 5;
                objectEntityList[37].propertyValue = 11;
                objectEntityList[38].propertyValue = 10;
                objectEntityList[39].propertyValue = 6;
                objectEntityList[40].propertyValue = 9;
                objectEntityList[1].values[2] = 7;
                objectEntityList[37].propertyValue = 10;
                objectEntityList[38].propertyValue = 6;
                objectEntityList[39].propertyValue = 9;
                objectEntityList[1].values[2] = 6;
            }
        }
        break;
        case 4:
        if (Engine.onlineActive == 1) {
            objectEntityList[34].propertyValue = 1;
            objectEntityList[35].propertyValue = 2;
            objectEntityList[36].propertyValue = 4;
            objectEntityList[37].propertyValue = 5;
            objectEntityList[38].propertyValue = 10;
            objectEntityList[39].propertyValue = 6;
            objectEntityList[1].values[2] = 6;
        } else {
            objectEntityList[34].propertyValue = 1;
            objectEntityList[35].propertyValue = 2;
            objectEntityList[36].propertyValue = 5;
            objectEntityList[37].propertyValue = 10;
            objectEntityList[38].propertyValue = 6;
            objectEntityList[1].values[2] = 5;
        }
        break;
        case 6:
        if (Engine.trialMode == 1) {
            objectEntityList[34].propertyValue = 1;
            objectEntityList[35].propertyValue = 5;
            objectEntityList[36].propertyValue = 10;
            objectEntityList[37].propertyValue = 11;
            objectEntityList[38].propertyValue = 9;
            objectEntityList[1].values[2] = 5;
        } else {
            if (Engine.onlineActive == 1) {
                objectEntityList[34].propertyValue = 1;
                objectEntityList[35].propertyValue = 2;
                objectEntityList[36].propertyValue = 4;
                objectEntityList[37].propertyValue = 3;
                objectEntityList[38].propertyValue = 5;
                objectEntityList[39].propertyValue = 10;
                objectEntityList[40].propertyValue = 6;
                objectEntityList[41].propertyValue = 9;
                objectEntityList[1].values[2] = 8;
            } else {
                objectEntityList[34].propertyValue = 1;
                objectEntityList[35].propertyValue = 2;
                objectEntityList[36].propertyValue = 5;
                objectEntityList[37].propertyValue = 11;
                objectEntityList[38].propertyValue = 10;
                objectEntityList[39].propertyValue = 6;
                objectEntityList[40].propertyValue = 9;
                objectEntityList[1].values[2] = 7;
            }
        }
        break;
    }
    scriptEng.arrayPosition[0] = 34;
    scriptEng.tempValue[0] = 0;
    while (scriptEng.tempValue[0] < objectEntityList[1].values[2]) {
        objectEntityList[scriptEng.arrayPosition[0]].values[5] = scriptEng.tempValue[0];
        objectEntityList[scriptEng.arrayPosition[0]].values[5]++;
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0]++;
    }
    while (scriptEng.tempValue[0] < 9) {
        objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[0]++;
    }
    objectEntityList[1].values[3] = objectEntityList[1].values[2];
    objectEntityList[1].values[3] *= -30;
    objectEntityList[1].values[3] <<= 8;
    AddSpriteFrame(0, -10, 144, 21, 259, 71);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 18;
    while (scriptEng.tempValue[0] < 2) {
        AddSpriteFrame(19, -7, 128, 16, 1, scriptEng.tempValue[1]);
        scriptEng.tempValue[1] += 17;
        scriptEng.tempValue[0]++;
    }
    if (RETRO_GAMEPLATFORMID == 3) {
        AddSpriteFrame(19, -7, 128, 16, 1, 513);
    } else {
        AddSpriteFrame(19, -7, 128, 16, 1, scriptEng.tempValue[1]);
    }
    scriptEng.tempValue[1] += 17;
    scriptEng.tempValue[0]++;
    if (Engine.onlineActive == 0) {
        AddSpriteFrame(19, -7, 128, 16, 130, 460);
    } else {
        AddSpriteFrame(19, -7, 128, 16, 1, scriptEng.tempValue[1]);
    }
    scriptEng.tempValue[1] += 17;
    scriptEng.tempValue[0]++;
    while (scriptEng.tempValue[0] < 6) {
        AddSpriteFrame(19, -7, 128, 16, 1, scriptEng.tempValue[1]);
        scriptEng.tempValue[1] += 17;
        scriptEng.tempValue[0]++;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 547;
    while (scriptEng.tempValue[0] < 4) {
        AddSpriteFrame(19, -7, 128, 16, 1, scriptEng.tempValue[1]);
        scriptEng.tempValue[1] += 17;
        scriptEng.tempValue[0]++;
    }
    AddSpriteFrame(19, -7, 128, 16, 162, 649);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 18;
    while (scriptEng.tempValue[0] < 2) {
        AddSpriteFrame(19, -7, 128, 16, 130, scriptEng.tempValue[1]);
        scriptEng.tempValue[1] += 17;
        scriptEng.tempValue[0]++;
    }
    if (RETRO_GAMEPLATFORMID == 3) {
        AddSpriteFrame(19, -7, 128, 16, 130, 513);
    } else {
        AddSpriteFrame(19, -7, 128, 16, 130, scriptEng.tempValue[1]);
    }
    scriptEng.tempValue[1] += 17;
    scriptEng.tempValue[0]++;
    while (scriptEng.tempValue[0] < 6) {
        AddSpriteFrame(19, -7, 128, 16, 130, scriptEng.tempValue[1]);
        scriptEng.tempValue[1] += 17;
        scriptEng.tempValue[0]++;
    }
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 547;
    while (scriptEng.tempValue[0] < 4) {
        AddSpriteFrame(19, -7, 128, 16, 130, scriptEng.tempValue[1]);
        scriptEng.tempValue[1] += 17;
        scriptEng.tempValue[0]++;
    }
    AddSpriteFrame(19, -7, 128, 16, 162, 666);
}

void O_Menu_MenuButton::ObjectMain()
{
    Entity *self = Self();

    self->values[2] = self->values[5];
    self->values[2]--;
    self->values[2] *= 60;
    self->values[2] += objectEntityList[0].values[1];
    scriptEng.tempValue[0] = SCREEN_CENTERX;
    scriptEng.tempValue[0] -= 160;
    self->values[1] = self->values[2];
    self->values[1] *= 54;
    self->values[1] /= 60;
    self->values[1] -= 16;
    self->values[1] += scriptEng.tempValue[0];
    switch (self->state) {
        case 0:
        if (self->values[0] < 60) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] -= self->XPos;
        scriptEng.tempValue[0] >>= 4;
        self->XPos += scriptEng.tempValue[0];
        scriptEng.tempValue[0] = self->values[2];
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] -= self->YPos;
        scriptEng.tempValue[0] >>= 4;
        self->YPos += scriptEng.tempValue[0];
        if (self->values[0] < 80) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 2:
        self->XPos = self->values[1];
        self->XPos <<= 16;
        self->YPos = self->values[2];
        self->YPos <<= 16;
        CheckResult() = 0;
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] -= 16;
            scriptEng.tempValue[1] = self->values[1];
            scriptEng.tempValue[1] += 176;
            scriptEng.tempValue[2] = self->values[2];
            scriptEng.tempValue[2] -= 20;
            scriptEng.tempValue[3] = self->values[2];
            scriptEng.tempValue[3] += 20;
            CheckTouchRect_Script(scriptEng.tempValue[0], scriptEng.tempValue[2], scriptEng.tempValue[1], scriptEng.tempValue[3]);
            if (CheckResult() > -1) {
                scriptEng.tempValue[0] = objectEntityList[0].values[7];
                scriptEng.tempValue[0] >>= 2;
                if (scriptEng.tempValue[0] == 0) {
                    if (objectEntityList[1].values[1] == 0) {
                        objectEntityList[0].values[2] = self->values[5];
                    }
                }
            } else {
                CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
                if (CheckResult() < 0) {
                    if (objectEntityList[0].values[2] == self->values[5]) {
                        if (objectEntityList[1].values[1] == 0) {
                            PlaySfx(27, 0);
                            objectEntityList[0].state = 3;
                            switch (self->propertyValue) {
                                case 1:
                                case 5:
                                case 6:
                                case 10:
                                objectEntityList[34].state = 4;
                                objectEntityList[34].values[0] = 0;
                                objectEntityList[35].state = 4;
                                objectEntityList[35].values[0] = 0;
                                objectEntityList[36].state = 4;
                                objectEntityList[36].values[0] = 0;
                                objectEntityList[37].state = 4;
                                objectEntityList[37].values[0] = 0;
                                objectEntityList[38].state = 4;
                                objectEntityList[38].values[0] = 0;
                                objectEntityList[39].state = 4;
                                objectEntityList[39].values[0] = 0;
                                objectEntityList[40].state = 4;
                                objectEntityList[40].values[0] = 0;
                                objectEntityList[41].state = 4;
                                objectEntityList[41].values[0] = 0;
                                objectEntityList[42].state = 4;
                                objectEntityList[42].values[0] = 0;
                                objectEntityList[43].state = 4;
                                objectEntityList[43].values[0] = 0;
                                break;
                                case 2:
                                if (Engine.trialMode == 0) {
                                    StopMusic();
                                    objectEntityList[34].state = 4;
                                    objectEntityList[34].values[0] = 0;
                                    objectEntityList[35].state = 4;
                                    objectEntityList[35].values[0] = 0;
                                    objectEntityList[36].state = 4;
                                    objectEntityList[36].values[0] = 0;
                                    objectEntityList[37].state = 4;
                                    objectEntityList[37].values[0] = 0;
                                    objectEntityList[38].state = 4;
                                    objectEntityList[38].values[0] = 0;
                                    objectEntityList[39].state = 4;
                                    objectEntityList[39].values[0] = 0;
                                    objectEntityList[40].state = 4;
                                    objectEntityList[40].values[0] = 0;
                                    objectEntityList[41].state = 4;
                                    objectEntityList[41].values[0] = 0;
                                    objectEntityList[42].state = 4;
                                    objectEntityList[42].values[0] = 0;
                                    objectEntityList[43].state = 4;
                                    objectEntityList[43].values[0] = 0;
                                }
                                break;
                            }
                            self->state = 3;
                        }
                    }
                } else {
                    if (objectEntityList[0].values[2] == self->values[5]) {
                        objectEntityList[0].values[2] = 0;
                    }
                }
            }
        } else {
            if (self->values[5] == objectEntityList[0].values[3]) {
                CheckResult() = 0;
                if (keyPress.start == 1) {
                    CheckResult() = 1;
                }
                if (keyPress.A == 1) {
                    CheckResult() = 1;
                }
                if (self->propertyValue == 3) {
                    if (Engine.onlineActive == 0) {
                        CheckResult() = 0;
                    }
                }
                if (CheckResult() == 1) {
                    PlaySfx(27, 0);
                    if (Engine.trialMode == 1) {
                        if (RETRO_GAMEPLATFORMID != 5) {
                            if (self->propertyValue == 1) {
                                StopMusic();
                            }
                        }
                    } else {
                        if (self->propertyValue == 2) {
                            StopMusic();
                        }
                    }
                    objectEntityList[0].state = 3;
                    switch (self->propertyValue) {
                        case 1:
                        case 5:
                        case 6:
                        case 10:
                        objectEntityList[34].state = 4;
                        objectEntityList[34].values[0] = 0;
                        objectEntityList[35].state = 4;
                        objectEntityList[35].values[0] = 0;
                        objectEntityList[36].state = 4;
                        objectEntityList[36].values[0] = 0;
                        objectEntityList[37].state = 4;
                        objectEntityList[37].values[0] = 0;
                        objectEntityList[38].state = 4;
                        objectEntityList[38].values[0] = 0;
                        objectEntityList[39].state = 4;
                        objectEntityList[39].values[0] = 0;
                        objectEntityList[40].state = 4;
                        objectEntityList[40].values[0] = 0;
                        objectEntityList[41].state = 4;
                        objectEntityList[41].values[0] = 0;
                        objectEntityList[42].state = 4;
                        objectEntityList[42].values[0] = 0;
                        objectEntityList[43].state = 4;
                        objectEntityList[43].values[0] = 0;
                        break;
                        case 2:
                        if (Engine.trialMode == 0) {
                            objectEntityList[34].state = 4;
                            objectEntityList[34].values[0] = 0;
                            objectEntityList[35].state = 4;
                            objectEntityList[35].values[0] = 0;
                            objectEntityList[36].state = 4;
                            objectEntityList[36].values[0] = 0;
                            objectEntityList[37].state = 4;
                            objectEntityList[37].values[0] = 0;
                            objectEntityList[38].state = 4;
                            objectEntityList[38].values[0] = 0;
                            objectEntityList[39].state = 4;
                            objectEntityList[39].values[0] = 0;
                            objectEntityList[40].state = 4;
                            objectEntityList[40].values[0] = 0;
                            objectEntityList[41].state = 4;
                            objectEntityList[41].values[0] = 0;
                            objectEntityList[42].state = 4;
                            objectEntityList[42].values[0] = 0;
                            objectEntityList[43].state = 4;
                            objectEntityList[43].values[0] = 0;
                        }
                        break;
                    }
                    self->state = 3;
                }
            }
        }
        if (RETRO_GAMEPLATFORMID == 6) {
            if (keyPress.B == 1) {
                Engine.Callback(7);
                self->state = 2;
                objectEntityList[0].state = 2;
                objectEntityList[0].values[2] = 0;
            }
        }
        break;
        case 3:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            switch (self->propertyValue) {
                case 1:
                if (Engine.trialMode == 0) {
                    objectEntityList[33].state = 1;
                    objectEntityList[33].propertyValue = 6;
                    MenuButton_SetupMenuWindow();
                    ResetObjectEntity(62, TypeNameID("Load Save Menu"), 0, 0, 0);
                    objectEntityList[62].inkEffect = 2;
                    objectEntityList[62].alpha = 0;
                    ResetObjectEntity(63, TypeNameID("Blank Object"), 0, 0, 0);
                    ResetObjectEntity(64, TypeNameID("Blank Object"), 0, 0, 0);
                    ResetObjectEntity(65, TypeNameID("Blank Object"), 0, 0, 0);
                    ResetObjectEntity(66, TypeNameID("Blank Object"), 0, 0, 0);
                    self->type = TypeNameID("Blank Object");
                    CheckResult() = ReadSaveRAMData();
                } else {
                    self->state = 5;
                    objectEntityList[0].state = 5;
                    objectEntityList[0].values[0] = 0;
                    GVar("Options.GameMode") = 0;
                    GVar("Player.Score") = 0;
                    GVar("Player.Lives") = 3;
                    GVar("Player.ScoreBonus") = 50000;
                    GVar("Transporter_Destroyed") = 0;
                    GVar("MetalSonic_Destroyed") = 0;
                    GVar("Good_Future") = 0;
                }
                break;
                case 2:
                if (Engine.trialMode == 0) {
                    self->state = 5;
                    objectEntityList[0].state = 4;
                    objectEntityList[0].values[0] = 0;
                } else {
                    self->state = 2;
                    objectEntityList[0].state = 2;
                    Engine.Callback(14);
                }
                break;
                case 3:
                if (RETRO_GAMEPLATFORMID != 6) {
                    LoadOnlineMenu_Script(0);
                    self->state = 2;
                    objectEntityList[0].state = 2;
                } else {
                    self->state = 5;
                    objectEntityList[0].state = 7;
                    objectEntityList[0].values[0] = 0;
                }
                break;
                case 4:
                if (RETRO_GAMEPLATFORMID != 6) {
                    LoadOnlineMenu_Script(1);
                    self->state = 2;
                    objectEntityList[0].state = 2;
                } else {
                    if (Engine.trialMode == 0) {
                        self->state = 5;
                        objectEntityList[0].state = 8;
                        objectEntityList[0].values[0] = 0;
                    } else {
                        self->state = 2;
                        objectEntityList[0].state = 2;
                        Engine.Callback(14);
                    }
                }
                break;
                case 5:
                objectEntityList[33].state = 1;
                objectEntityList[33].propertyValue = 7;
                MenuButton_SetupMenuWindow();
                ResetObjectEntity(62, TypeNameID("Options Menu C"), 0, 0, 0);
                objectEntityList[62].inkEffect = 2;
                objectEntityList[62].alpha = 0;
                ResetObjectEntity(63, TypeNameID("Blank Object"), 0, 0, 0);
                ResetObjectEntity(64, TypeNameID("Blank Object"), 0, 0, 0);
                ResetObjectEntity(65, TypeNameID("Blank Object"), 0, 0, 0);
                ResetObjectEntity(66, TypeNameID("Blank Object"), 0, 0, 0);
                self->type = TypeNameID("Blank Object");
                break;
                case 6:
                objectEntityList[33].state = 1;
                objectEntityList[33].propertyValue = 8;
                MenuButton_SetupMenuWindow();
                ResetObjectEntity(62, TypeNameID("Extras Menu"), 0, 0, 0);
                objectEntityList[62].inkEffect = 2;
                objectEntityList[62].alpha = 0;
                ResetObjectEntity(63, TypeNameID("Blank Object"), 0, 0, 0);
                ResetObjectEntity(64, TypeNameID("Blank Object"), 0, 0, 0);
                ResetObjectEntity(65, TypeNameID("Blank Object"), 0, 0, 0);
                ResetObjectEntity(66, TypeNameID("Blank Object"), 0, 0, 0);
                self->type = TypeNameID("Blank Object");
                break;
                case 7:
                Engine.Callback(8);
                self->state = 2;
                objectEntityList[0].state = 2;
                break;
                case 8:
                Engine.Callback(5);
                self->state = 2;
                objectEntityList[0].state = 2;
                break;
                case 9:
                Engine.Callback(7);
                Engine.gameMode = 3;
                self->state = 2;
                objectEntityList[0].state = 2;
                break;
                case 10:
                objectEntityList[33].state = 1;
                objectEntityList[33].propertyValue = 9;
                MenuButton_SetupMenuWindow();
                objectEntityList[61].state = 5;
                ResetObjectEntity(62, TypeNameID("Soundtrack Menu"), 0, 0, 0);
                objectEntityList[62].inkEffect = 2;
                objectEntityList[62].alpha = 0;
                ResetObjectEntity(63, TypeNameID("Blank Object"), 0, 0, 0);
                ResetObjectEntity(64, TypeNameID("Blank Object"), 0, 0, 0);
                ResetObjectEntity(65, TypeNameID("Blank Object"), 0, 0, 0);
                ResetObjectEntity(66, TypeNameID("Blank Object"), 0, 0, 0);
                self->type = TypeNameID("Blank Object");
                break;
            }
        }
        break;
        case 4:
        scriptEng.tempValue[0] = self->values[3];
        scriptEng.tempValue[0] -= self->XPos;
        scriptEng.tempValue[0] >>= 4;
        self->XPos += scriptEng.tempValue[0];
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] -= self->YPos;
        scriptEng.tempValue[0] >>= 4;
        self->YPos += scriptEng.tempValue[0];
        if (self->values[0] < 80) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 6;
        }
        break;
        case 5:
        case 6:
        break;
        case 7:
        if (self->propertyValue == 6) {
            if (objectEntityList[objectLoop - 1].state == 2) {
                self->state = 2;
                objectEntityList[0].state = 2;
            }
        } else {
            if (objectEntityList[objectLoop + 1].state == 2) {
                self->state = 2;
                objectEntityList[0].state = 2;
            }
        }
        break;
    }
}

void O_Menu_MenuButton::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(0);
    switch (self->state) {
        case 0:
        case 1:
        case 2:
        case 4:
        case 5:
        case 7:
        if (self->values[5] == objectEntityList[0].values[3]) {
            scriptEng.tempValue[0] = self->propertyValue;
            scriptEng.tempValue[0] += 11;
            DrawSprite_Frame(scriptEng.tempValue[0]);
        } else {
            DrawSprite_Frame(self->propertyValue);
        }
        break;
        case 3:
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 3;
        scriptEng.tempValue[0] >>= 1;
        if (scriptEng.tempValue[0] == 0) {
            scriptEng.tempValue[0] = self->propertyValue;
            scriptEng.tempValue[0] += 11;
            DrawSprite_Frame(scriptEng.tempValue[0]);
        }
        break;
    }
}

void O_Menu_MenuButton::MenuButton_SetupMenuWindow()
{
    Entity *self = Self();

    ResetObjectEntity(61, TypeNameID("Menu Window"), 0, self->XPos, self->YPos);
    objectEntityList[61].XPos += 0x480000;
    objectEntityList[61].values[1] = 144;
    objectEntityList[61].values[2] = 21;
    objectEntityList[61].values[3] = objectEntityList[61].XPos;
    objectEntityList[61].values[4] = objectEntityList[61].YPos;
    objectEntityList[61].values[5] = objectLoop;
}

const Native::NativeFunctionDef O_Menu_MenuButton::funcs[1] = {
    { "MenuButton_SetupMenuWindow", O_Menu_MenuButton::MenuButton_SetupMenuWindow },
};

#endif // RETRO_USE_NATIVE_OBJECTS
