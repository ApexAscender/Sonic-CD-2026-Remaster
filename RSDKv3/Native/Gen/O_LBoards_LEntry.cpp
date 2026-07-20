#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_LBoards_LEntry.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LEntry.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_LBoards_LEntry::ObjectStartup()
{
    LoadSpriteSheet("LBoards/Leaderboards.gif");
    LoadTextFile_Script(0, "Data/Game/LeaderboardText.txt", 0);
    GVar("Leaderboard.ID") = 0;
    LoadOnlineMenu_Script(1);
    AddSpriteFrame(0, 0, 8, 10, 118, 298);
    scriptEng.tempValue[1] = 254;
    while (scriptEng.tempValue[1] < 308) {
        scriptEng.tempValue[0] = 127;
        while (scriptEng.tempValue[0] < 253) {
            AddSpriteFrame(-3, -5, 8, 10, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] += 9;
        }
        scriptEng.tempValue[1] += 11;
    }
    AddSpriteFrame(0, 0, 8, 10, 118, 298);
    scriptEng.tempValue[1] = 254;
    while (scriptEng.tempValue[1] < 308) {
        scriptEng.tempValue[0] = 1;
        while (scriptEng.tempValue[0] < 127) {
            AddSpriteFrame(-3, -5, 8, 10, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] += 9;
        }
        scriptEng.tempValue[1] += 11;
    }
    AddSpriteFrame(0, -10, 232, 21, 1, 309);
    AddSpriteFrame(0, -10, 232, 21, 1, 232);
}

void O_LBoards_LEntry::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        break;
        case 1:
        self->values[5] = self->XPos;
        self->priority = 1;
        self->state++;
        break;
        case 2:
        self->XPos -= 0x300000;
        if (self->values[0] < 25) {
            self->values[0]++;
            if (self->propertyValue < 4) {
                if (self->values[0] == 5) {
                    objectEntityList[objectLoop + 1].state = 1;
                    if (self->propertyValue == 1) {
                        GVar("Leaderboard.ID")++;
                        GVar("Leaderboard.ID") %= 22;
                        LoadOnlineMenu_Script(1);
                    }
                }
            }
        } else {
            self->values[0] = 0;
            objectEntityList[objectLoop].XPos = (SCREEN_XSIZE) << 16;
            self->XPos += 0x100000;
            self->state++;
        }
        break;
        case 3:
        self->XPos -= 0x300000;
        if (self->XPos < self->values[5]) {
            self->XPos = self->values[5];
            self->state = 0;
            if (self->propertyValue == 4) {
                objectEntityList[0].state = 2;
            }
        }
        break;
        case 4:
        self->values[5] = self->XPos;
        self->priority = 1;
        self->state++;
        break;
        case 5:
        self->XPos += 0x300000;
        if (self->values[0] < 25) {
            self->values[0]++;
            if (self->propertyValue < 4) {
                if (self->values[0] == 5) {
                    objectEntityList[objectLoop + 1].state = 4;
                    if (self->propertyValue == 2) {
                        GVar("Leaderboard.ID")--;
                        if (GVar("Leaderboard.ID") < 0) {
                            GVar("Leaderboard.ID") = 21;
                        }
                        LoadOnlineMenu_Script(1);
                    }
                }
            }
        } else {
            self->values[0] = 0;
            objectEntityList[objectLoop].XPos = (-232) << 16;
            self->XPos -= 0x100000;
            self->state++;
        }
        break;
        case 6:
        self->XPos += 0x300000;
        if (self->XPos > self->values[5]) {
            self->XPos = self->values[5];
            self->state = 0;
            if (self->propertyValue == 4) {
                objectEntityList[0].state = 2;
            }
        }
        break;
        case 7:
        if (self->values[4] < 95) {
            self->values[4] += 5;
        }
        self->alpha = 255;
        self->state++;
        break;
        case 8:
        self->inkEffect = 2;
        self->alpha = 224;
        self->state++;
        break;
        case 9:
        if (self->alpha > 0) {
            self->alpha -= 32;
            if (self->propertyValue < 4) {
                if (self->alpha == 128) {
                    objectEntityList[objectLoop + 1].state = 7;
                }
            }
        } else {
            self->state = 0;
            if (self->propertyValue == 4) {
                objectEntityList[0].state = 2;
            }
        }
        break;
        case 10:
        if (self->values[4] > 0) {
            self->values[4] -= 5;
        }
        self->alpha = 255;
        self->state++;
        break;
        case 11:
        self->inkEffect = 2;
        self->alpha = 224;
        self->state++;
        break;
        case 12:
        if (self->alpha > 0) {
            self->alpha -= 32;
            if (self->propertyValue < 4) {
                if (self->alpha == 128) {
                    objectEntityList[objectLoop + 1].state = 10;
                }
            }
        } else {
            self->state = 0;
            if (self->propertyValue == 4) {
                objectEntityList[0].state = 2;
            }
        }
        break;
    }
}

void O_LBoards_LEntry::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(142);
    self->values[3] = self->propertyValue;
    self->values[3] += self->values[4];
    scriptEng.arrayPosition[0] = 0;
    scriptEng.tempValue[1] = GetTextInfo_Script(0, 1, self->values[3], 0);
    scriptEng.tempValue[2] = self->XPos;
    scriptEng.tempValue[2] += 0x80000;
    scriptEng.tempValue[3] = 0;
    while (scriptEng.tempValue[3] < 4) {
        scriptEng.tempValue[0] = GetTextInfo_Script(0, 0, self->values[3], scriptEng.arrayPosition[0]);
        switch (scriptEng.tempValue[0]) {
            default:
            self->frame = 0;
            if (scriptEng.tempValue[0] > 47) {
                if (scriptEng.tempValue[0] < 58) {
                    self->frame = scriptEng.tempValue[0];
                    self->frame -= 15;
                }
            }
            if (self->frame > 0) {
                self->frame += 71;
                DrawSprite_FrameXY(self->frame, scriptEng.tempValue[2], self->YPos);
            }
            break;
            case 34:
            DrawSprite_FrameXY(100, scriptEng.tempValue[2], self->YPos);
            break;
            case 39:
            DrawSprite_FrameXY(99, scriptEng.tempValue[2], self->YPos);
            break;
            case 46:
            DrawSprite_FrameXY(98, scriptEng.tempValue[2], self->YPos);
            break;
        }
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[3]++;
        scriptEng.tempValue[2] += 0x80000;
    }
    scriptEng.tempValue[1] -= 4;
    while (scriptEng.tempValue[1] > 0) {
        scriptEng.tempValue[0] = GetTextInfo_Script(0, 0, self->values[3], scriptEng.arrayPosition[0]);
        switch (scriptEng.tempValue[0]) {
            default:
            self->frame = 0;
            if (scriptEng.tempValue[0] > 64) {
                if (scriptEng.tempValue[0] < 91) {
                    self->frame = scriptEng.tempValue[0];
                    self->frame -= 64;
                }
            }
            if (scriptEng.tempValue[0] > 96) {
                if (scriptEng.tempValue[0] < 123) {
                    self->frame = scriptEng.tempValue[0];
                    self->frame -= 54;
                }
            }
            if (scriptEng.tempValue[0] > 47) {
                if (scriptEng.tempValue[0] < 58) {
                    self->frame = scriptEng.tempValue[0];
                    self->frame -= 15;
                }
            }
            if (self->frame > 0) {
                DrawSprite_FrameXY(self->frame, scriptEng.tempValue[2], self->YPos);
            }
            break;
            case 34:
            DrawSprite_FrameXY(29, scriptEng.tempValue[2], self->YPos);
            break;
            case 39:
            DrawSprite_FrameXY(28, scriptEng.tempValue[2], self->YPos);
            break;
            case 45:
            DrawSprite_FrameXY(69, scriptEng.tempValue[2], self->YPos);
            break;
            case 46:
            DrawSprite_FrameXY(27, scriptEng.tempValue[2], self->YPos);
            break;
        }
        scriptEng.arrayPosition[0]++;
        scriptEng.tempValue[1]--;
        scriptEng.tempValue[2] += 0x80000;
    }
    if (self->state > 6) {
        DrawSpriteFX_Script(143, FX_INK, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
