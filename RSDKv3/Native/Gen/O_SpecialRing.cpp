#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_SpecialRing.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpecialRing.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_SpecialRing::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Items2.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Items2_t.gif");
    }
    SetupMenu_Script(0, 0, 0, 0);
    LoadTextFile_Script(0, "Data/Game/Credits_Console.txt", 0);
    CheckResult() = GetTextInfo_Script(0, 2, 0, 0);
    if (CheckResult() > 1) {
        scriptEng.arrayPosition[0] = 32;
        while (scriptEng.arrayPosition[0] < 1056) {
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Special Ring")) {
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 1;
            }
            scriptEng.arrayPosition[0]++;
        }
    }
    if (CheckResult() > 1) {
        AddSpriteFrame(-32, -32, 64, 64, 83, 1);
        AddSpriteFrame(-24, -32, 48, 64, 148, 1);
        AddSpriteFrame(-12, -32, 24, 64, 197, 1);
        AddSpriteFrame(-24, -32, 48, 64, 101, 66);
        AddSpriteFrame(0, -32, 32, 64, 222, 1);
        AddSpriteFrame(-16, -32, 48, 64, 150, 66);
        AddSpriteFrame(-24, -32, 56, 64, 199, 66);
        AddSpriteFrame(-32, -32, 64, 64, 191, 131);
        AddSpriteFrame(-24, -32, 56, 64, 199, 66);
        AddSpriteFrame(-16, -32, 48, 64, 150, 66);
        AddSpriteFrame(0, -32, 32, 64, 222, 1);
        AddSpriteFrame(-32, -32, 64, 64, 126, 131);
    } else {
        AddSpriteFrame(-32, -32, 64, 64, 83, 1);
        AddSpriteFrame(-28, -32, 56, 64, 199, 131);
        AddSpriteFrame(-24, -32, 48, 64, 148, 1);
        AddSpriteFrame(-16, -32, 32, 64, 223, 66);
        AddSpriteFrame(-12, -32, 24, 64, 197, 1);
        AddSpriteFrame(-16, -32, 32, 64, 223, 66);
        AddSpriteFrame(-24, -32, 48, 64, 148, 1);
        AddSpriteFrame(-28, -32, 56, 64, 199, 131);
        AddSpriteFrame(0, -32, 32, 64, 222, 1);
        AddSpriteFrame(-16, -32, 48, 64, 101, 66);
        AddSpriteFrame(-24, -32, 56, 64, 150, 66);
        AddSpriteFrame(0, -32, 32, 64, 156, 131);
        AddSpriteFrame(-24, -32, 56, 64, 150, 66);
        AddSpriteFrame(-16, -32, 48, 64, 101, 66);
        AddSpriteFrame(0, -32, 32, 64, 222, 1);
        AddSpriteFrame(-32, -32, 32, 64, 124, 131);
    }
    if (GVar("SpecialStage.TimeStones") >= 0x7F) {
        scriptEng.arrayPosition[0] = 32;
        while (scriptEng.arrayPosition[0] < 1056) {
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Special Ring")) {
                ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("Blank Object"), 0, 0, 0);
            }
            scriptEng.arrayPosition[0]++;
        }
    }
    if (GVar("Options.GameMode") > 1) {
        scriptEng.arrayPosition[0] = 32;
        while (scriptEng.arrayPosition[0] < 1056) {
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Special Ring")) {
                ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("BlankObject"), 0, 0, 0);
            }
            scriptEng.arrayPosition[0]++;
        }
    }
    if (Engine.trialMode == 1) {
        scriptEng.arrayPosition[0] = 32;
        while (scriptEng.arrayPosition[0] < 1056) {
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Special Ring")) {
                ResetObjectEntity(scriptEng.arrayPosition[0], TypeNameID("BlankObject"), 0, 0, 0);
            }
            scriptEng.arrayPosition[0]++;
        }
    }
}

void O_SpecialRing::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (PlayerValue(0) > 49) {
            PlayerObjectCollision(C_TOUCH, -16, -16, 16, 16);
            if (CheckResult() == 1) {
                objectEntityList[0].type = TypeNameID("Blank Object");
                objectEntityList[1].type = TypeNameID("Blank Object");
                pControlMode() = -1;
                pDirection() = 0;
                ResetObjectEntity(2, TypeNameID("Blank Object"), 0, 0, 0);
                self->drawOrder = 4;
                self->state = 1;
                if (self->values[7] != 0) {
                    self->frame = 16;
                } else {
                    self->frame = 32;
                }
                StopSfx(24);
                StopSfx(25);
                PlaySfx(18, 0);
                pLeft() = 0;
                pRight() = 0;
                HapticEffect_Script(40, 0, 0, 0);
            }
        }
    }
}

void O_SpecialRing::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (PlayerValue(0) > 49) {
            scriptEng.tempValue[0] = self->frame;
            if (self->values[7] != 0) {
                scriptEng.tempValue[0] >>= 3;
                DrawSprite_Frame(scriptEng.tempValue[0]);
            } else {
                scriptEng.tempValue[0] >>= 2;
                if (scriptEng.tempValue[0] > 3) {
                    self->direction = 1;
                } else {
                    self->direction = 0;
                }
                DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            }
            self->frame++;
            if (self->frame > 31) {
                self->frame = 0;
            }
        }
        break;
        case 1:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 2;
        if (self->values[7] != 0) {
            scriptEng.tempValue[0] = self->frame;
            scriptEng.tempValue[0] >>= 2;
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            self->frame++;
            if (self->frame > 31) {
                self->direction = 1;
            }
            if (self->frame > 47) {
                ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            }
        } else {
            if (scriptEng.tempValue[0] > 11) {
                self->direction = 1;
            } else {
                self->direction = 0;
            }
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            CheckResult() = (scriptEng.tempValue[0] == 11);
            if (CheckResult() == 1) {
                self->direction = 1;
                DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
            } else {
                if (scriptEng.tempValue[0] == 15) {
                    self->direction = 1;
                    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
                }
            }
            self->frame++;
            if (self->frame > 63) {
                ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            }
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
