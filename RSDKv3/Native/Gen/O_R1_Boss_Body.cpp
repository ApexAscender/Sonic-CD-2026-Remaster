#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Boss_Body.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Boss_Body.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Boss_Body::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-36, -32, 72, 64, 1, 1);
    AddSpriteFrame(0, 8, 24, 24, 99, 1);
}

void O_R1_Boss_Body::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        BossBody_RestoreNormalSpeed();
        self->values[6] = self->XPos;
        self->values[6] -= 0x7A0000;
        self->values[7] = self->XPos;
        self->values[7] -= 0x320000;
        self->state = 1;
        break;
        case 1:
        scriptEng.arrayPosition[0] = self->values[2];
        objectEntityList[scriptEng.arrayPosition[0]].state = 8;
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        objectEntityList[scriptEng.arrayPosition[1]].state = 2;
        scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
        objectEntityList[scriptEng.arrayPosition[0]].state = 5;
        scriptEng.arrayPosition[0] = self->values[1];
        BossBody_SetLegPosSaveTrue();
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 4) & 1);
        if (scriptEng.tempValue[0] == 0) {
            self->YPos += 0x18000;
            scriptEng.arrayPosition[0] = self->values[0];
            objectEntityList[scriptEng.arrayPosition[0]].YPos += 0x18000;
        } else {
            self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
        }
        break;
        case 2:
        scriptEng.arrayPosition[0] = self->values[2];
        objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 0));
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
        if (scriptEng.tempValue[0] == 1) {
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 0));
            if (objectEntityList[scriptEng.arrayPosition[0]].state != 6) {
                if (objectEntityList[scriptEng.arrayPosition[0]].state != 5) {
                    objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                    BossBody_SetLegPosSaveFalse();
                    scriptEng.arrayPosition[0] = self->values[1];
                    BossBody_SwitchLeg_Revert();
                    scriptEng.arrayPosition[0] = self->values[2];
                    objectEntityList[scriptEng.arrayPosition[0]].state = 4;
                    BossBody_SetLegPosSaveFalse();
                    scriptEng.arrayPosition[0] = self->values[2];
                    BossBody_SwitchLeg();
                    scriptEng.arrayPosition[0] = self->values[2];
                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                    objectEntityList[scriptEng.arrayPosition[1]].state = 1;
                    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
                    objectEntityList[scriptEng.arrayPosition[0]].state = 2;
                    self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
                } else {
                    objectEntityList[scriptEng.arrayPosition[0]].state = 7;
                }
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].state = 5;
            }
        }
        break;
        case 3:
        scriptEng.tempValue[0] = ((self->values[4] >> 1) & 1);
        if (scriptEng.tempValue[0] == 0) {
            self->values[4] = (1) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
            BossBody_MoveRArmToFront();
        }
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
        if (scriptEng.tempValue[0] == 1) {
            scriptEng.arrayPosition[0] = self->values[2];
            scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
            if (scriptEng.tempValue[0] == 1) {
                self->values[4] = (0) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
                self->values[4] = (1) ? (self->values[4] | (1 << 6)) : (self->values[4] & ~(1 << 6));
                self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
            }
        }
        break;
        case 4:
        scriptEng.arrayPosition[0] = self->values[1];
        CheckResult() = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
        scriptEng.arrayPosition[0] = self->values[2];
        scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
        CheckResult() &= scriptEng.tempValue[0];
        if (CheckResult() == 1) {
            scriptEng.arrayPosition[0] = self->values[1];
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 0));
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
            scriptEng.arrayPosition[0] = self->values[2];
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 0));
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
            if (self->XPos < self->values[6]) {
                self->values[5] = 1;
            }
            self->values[5]--;
            if (self->values[5] == 0) {
                self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
                self->values[4] = (0) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
            } else {
                scriptEng.tempValue[0] = ((self->values[4] >> 6) & 1);
                if (scriptEng.tempValue[0] == 0) {
                    self->values[4] = (1) ? (self->values[4] | (1 << 6)) : (self->values[4] & ~(1 << 6));
                    scriptEng.arrayPosition[0] = self->values[1];
                    objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                    BossBody_SetLegPosSaveFalse();
                    scriptEng.arrayPosition[0] = self->values[1];
                    BossBody_SwitchLeg_Revert();
                    scriptEng.arrayPosition[0] = self->values[1];
                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                    objectEntityList[scriptEng.arrayPosition[1]].state = 4;
                    scriptEng.arrayPosition[0] = self->values[2];
                    objectEntityList[scriptEng.arrayPosition[0]].state = 4;
                    BossBody_SetLegPosSaveTrue();
                    scriptEng.arrayPosition[0] = self->values[2];
                    BossBody_SwitchLeg();
                    scriptEng.arrayPosition[0] = self->values[2];
                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                    objectEntityList[scriptEng.arrayPosition[1]].state = 3;
                    BossBody_MoveRArmToFront();
                } else {
                    self->values[4] = (0) ? (self->values[4] | (1 << 6)) : (self->values[4] & ~(1 << 6));
                    scriptEng.arrayPosition[0] = self->values[1];
                    objectEntityList[scriptEng.arrayPosition[0]].state = 4;
                    BossBody_SetLegPosSaveTrue();
                    scriptEng.arrayPosition[0] = self->values[1];
                    BossBody_SwitchLeg();
                    scriptEng.arrayPosition[0] = self->values[1];
                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                    objectEntityList[scriptEng.arrayPosition[1]].state = 3;
                    scriptEng.arrayPosition[0] = self->values[2];
                    objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                    BossBody_SetLegPosSaveFalse();
                    scriptEng.arrayPosition[0] = self->values[2];
                    BossBody_SwitchLeg_Revert();
                    scriptEng.arrayPosition[0] = self->values[2];
                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                    objectEntityList[scriptEng.arrayPosition[1]].state = 4;
                    BossBody_MoveLArmToFront();
                }
            }
        }
        break;
        case 5:
        scriptEng.arrayPosition[0] = self->values[1];
        CheckResult() = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
        scriptEng.arrayPosition[0] = self->values[2];
        scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
        CheckResult() &= scriptEng.tempValue[0];
        if (CheckResult() == 1) {
            scriptEng.tempValue[0] = ((self->values[4] >> 1) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[4] = (1) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
                BossBody_RestoreNormalSpeed();
            } else {
                scriptEng.arrayPosition[0] = self->values[1];
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 0));
                scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
                scriptEng.arrayPosition[0] = self->values[2];
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 0));
                scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
                if (self->XPos >= self->values[7]) {
                    self->values[5] = 1;
                }
                self->values[5]--;
                if (self->values[5] == 0) {
                    self->values[4] = (0) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
                    self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
                } else {
                    scriptEng.tempValue[0] = ((self->values[4] >> 6) & 1);
                    if (scriptEng.tempValue[0] == 0) {
                        self->values[4] = (1) ? (self->values[4] | (1 << 6)) : (self->values[4] & ~(1 << 6));
                        scriptEng.arrayPosition[0] = self->values[1];
                        objectEntityList[scriptEng.arrayPosition[0]].state = 11;
                        BossBody_SetLegPosSaveTrue();
                        scriptEng.arrayPosition[0] = self->values[1];
                        BossBody_SwitchLeg();
                        scriptEng.arrayPosition[0] = self->values[1];
                        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                        objectEntityList[scriptEng.arrayPosition[1]].state = 4;
                        scriptEng.arrayPosition[0] = self->values[2];
                        objectEntityList[scriptEng.arrayPosition[0]].state = 9;
                        BossBody_SetLegPosSaveFalse();
                        scriptEng.arrayPosition[0] = self->values[2];
                        BossBody_SwitchLeg_Revert();
                        scriptEng.arrayPosition[0] = self->values[2];
                        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                        objectEntityList[scriptEng.arrayPosition[1]].state = 3;
                        BossBody_MoveRArmToFront();
                    } else {
                        self->values[4] = (0) ? (self->values[4] | (1 << 6)) : (self->values[4] & ~(1 << 6));
                        scriptEng.arrayPosition[0] = self->values[1];
                        objectEntityList[scriptEng.arrayPosition[0]].state = 9;
                        BossBody_SetLegPosSaveFalse();
                        scriptEng.arrayPosition[0] = self->values[1];
                        BossBody_SwitchLeg_Revert();
                        scriptEng.arrayPosition[0] = self->values[1];
                        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                        objectEntityList[scriptEng.arrayPosition[1]].state = 3;
                        scriptEng.arrayPosition[0] = self->values[2];
                        objectEntityList[scriptEng.arrayPosition[0]].state = 11;
                        BossBody_SetLegPosSaveTrue();
                        scriptEng.arrayPosition[0] = self->values[2];
                        BossBody_SwitchLeg();
                        scriptEng.arrayPosition[0] = self->values[2];
                        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                        objectEntityList[scriptEng.arrayPosition[1]].state = 4;
                        BossBody_MoveLArmToFront();
                    }
                }
            }
        }
        break;
        case 6:
        scriptEng.tempValue[0] = ((self->values[4] >> 1) & 1);
        if (scriptEng.tempValue[0] == 0) {
            self->values[4] = (1) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
            BossBody_HandleCharge();
        }
        scriptEng.tempValue[0] = ((self->values[4] >> 6) & 1);
        if (scriptEng.tempValue[0] == 1) {
            scriptEng.arrayPosition[0] = self->values[1];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].state = 5;
            scriptEng.arrayPosition[0] = self->values[2];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].state = 6;
        } else {
            scriptEng.arrayPosition[0] = self->values[2];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].state = 5;
            scriptEng.arrayPosition[0] = self->values[1];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].state = 6;
        }
        scriptEng.arrayPosition[0] = self->values[1];
        CheckResult() = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
        scriptEng.arrayPosition[0] = self->values[2];
        scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[0]].values[4] >> 0) & 1);
        CheckResult() &= scriptEng.tempValue[0];
        if (CheckResult() == 1) {
            scriptEng.arrayPosition[0] = self->values[1];
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 0));
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
            scriptEng.arrayPosition[0] = self->values[2];
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 0));
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
            self->values[5]--;
            if (self->values[5] == 0) {
                self->values[4] = (0) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
                self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
            } else {
                scriptEng.tempValue[0] = ((self->values[4] >> 6) & 1);
                if (scriptEng.tempValue[0] == 0) {
                    self->values[4] = (1) ? (self->values[4] | (1 << 6)) : (self->values[4] & ~(1 << 6));
                    scriptEng.arrayPosition[0] = self->values[1];
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 1)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 1));
                    BossBody_SetLegPosSaveTrue();
                    scriptEng.arrayPosition[0] = self->values[1];
                    BossBody_SwitchLeg();
                    scriptEng.arrayPosition[0] = self->values[1];
                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                    objectEntityList[scriptEng.arrayPosition[1]].state = 5;
                    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
                    objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                    scriptEng.arrayPosition[0] = self->values[2];
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 1)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 1));
                    objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                    BossBody_SetLegPosSaveFalse();
                    scriptEng.arrayPosition[0] = self->values[2];
                    BossBody_SwitchLeg_Revert();
                    scriptEng.arrayPosition[0] = self->values[2];
                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                    objectEntityList[scriptEng.arrayPosition[1]].state = 6;
                    BossBody_SetArmsToCharge();
                } else {
                    self->values[4] = (0) ? (self->values[4] | (1 << 6)) : (self->values[4] & ~(1 << 6));
                    scriptEng.arrayPosition[0] = self->values[2];
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 1)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 1));
                    BossBody_SetLegPosSaveTrue();
                    scriptEng.arrayPosition[0] = self->values[2];
                    BossBody_SwitchLeg();
                    scriptEng.arrayPosition[0] = self->values[2];
                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                    objectEntityList[scriptEng.arrayPosition[1]].state = 5;
                    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
                    objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                    scriptEng.arrayPosition[0] = self->values[1];
                    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 1)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 1));
                    objectEntityList[scriptEng.arrayPosition[0]].state = 1;
                    BossBody_SetLegPosSaveFalse();
                    scriptEng.arrayPosition[0] = self->values[1];
                    BossBody_SwitchLeg_Revert();
                    scriptEng.arrayPosition[0] = self->values[1];
                    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                    objectEntityList[scriptEng.arrayPosition[1]].state = 6;
                    BossBody_SetArmsToCharge();
                }
            }
        }
        break;
        case 7:
        if (self->values[3] == 0) {
            self->YPos += 0x20000;
            ObjectTileCollision_Script(0, 0, 30, 0);
            self->values[3] = CheckResult();
            objectEntityList[objectLoop - 1].YPos = self->YPos;
        }
        break;
        case 8:
        self->values[5]--;
        if (self->values[5] == 0) {
            BossBody_RestoreNormalSpeed();
            self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
            self->values[4] = (0) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
        }
        break;
    }
}

void O_R1_Boss_Body::ObjectDraw()
{
    DrawSprite_Frame(0);
    DrawSprite_Frame(1);
}

void O_R1_Boss_Body::BossBody_RestoreNormalSpeed()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0x8000;
    objectEntityList[scriptEng.arrayPosition[1]].values[5] = 0x4000;
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x4000;
    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0x8000;
    scriptEng.arrayPosition[0] = self->values[2];
    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 2;
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0x8000;
    objectEntityList[scriptEng.arrayPosition[1]].values[5] = 0x4000;
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x4000;
    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0x8000;
    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 7));
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 7));
    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[2];
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 7));
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 7));
}

void O_R1_Boss_Body::BossBody_SetLegPosSaveTrue()
{
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 5)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 5));
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 5)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 5));
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 5)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 5));
}

void O_R1_Boss_Body::BossBody_SetLegPosSaveFalse()
{
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 5)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 5));
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 5)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 5));
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 5)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 5));
}

void O_R1_Boss_Body::BossBody_SwitchLeg()
{
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 4)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 4));
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 4)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 4));
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 4)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 4));
}

void O_R1_Boss_Body::BossBody_SwitchLeg_Revert()
{
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 4)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 4));
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 4)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 4));
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 4)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 4));
}

void O_R1_Boss_Body::BossBody_MoveRArmToFront()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[2];
    if (objectEntityList[scriptEng.arrayPosition[0]].state < 5) {
        objectEntityList[scriptEng.arrayPosition[0]].state = 3;
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        objectEntityList[scriptEng.arrayPosition[1]].state = 3;
        objectEntityList[scriptEng.arrayPosition[1]].frame = 0;
    }
    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    if (objectEntityList[scriptEng.arrayPosition[0]].state < 5) {
        objectEntityList[scriptEng.arrayPosition[0]].state = 1;
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        objectEntityList[scriptEng.arrayPosition[1]].state = 4;
        objectEntityList[scriptEng.arrayPosition[1]].frame = 0;
    }
}

void O_R1_Boss_Body::BossBody_MoveLArmToFront()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[2];
    if (objectEntityList[scriptEng.arrayPosition[0]].state < 5) {
        objectEntityList[scriptEng.arrayPosition[0]].state = 1;
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        objectEntityList[scriptEng.arrayPosition[1]].state = 4;
        objectEntityList[scriptEng.arrayPosition[1]].frame = 0;
    }
    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    if (objectEntityList[scriptEng.arrayPosition[0]].state < 5) {
        objectEntityList[scriptEng.arrayPosition[0]].state = 3;
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        objectEntityList[scriptEng.arrayPosition[1]].state = 3;
        objectEntityList[scriptEng.arrayPosition[1]].frame = 0;
    }
}

void O_R1_Boss_Body::BossBody_HandleCharge()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 8;
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0x10000;
    objectEntityList[scriptEng.arrayPosition[1]].values[5] = 0x8000;
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0xC000;
    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0x18000;
    scriptEng.arrayPosition[0] = self->values[2];
    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 8;
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[2] = 0x10000;
    objectEntityList[scriptEng.arrayPosition[1]].values[5] = 0x8000;
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0xC000;
    objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0x18000;
    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 7));
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 7));
    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[2];
    objectEntityList[scriptEng.arrayPosition[0]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[0]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[0]].values[4] & ~(1 << 7));
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 7));
}

void O_R1_Boss_Body::BossBody_SetArmsToCharge()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[2];
    if (objectEntityList[scriptEng.arrayPosition[0]].state < 5) {
        objectEntityList[scriptEng.arrayPosition[0]].state = 1;
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        objectEntityList[scriptEng.arrayPosition[1]].state = 5;
        objectEntityList[scriptEng.arrayPosition[1]].frame = 1;
    }
    scriptEng.arrayPosition[0] = self->values[0];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
    scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
    if (objectEntityList[scriptEng.arrayPosition[0]].state < 5) {
        objectEntityList[scriptEng.arrayPosition[0]].state = 1;
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        objectEntityList[scriptEng.arrayPosition[1]].state = 5;
        objectEntityList[scriptEng.arrayPosition[1]].frame = 1;
    }
}

const Native::NativeFunctionDef O_R1_Boss_Body::funcs[9] = {
    { "BossBody_RestoreNormalSpeed", O_R1_Boss_Body::BossBody_RestoreNormalSpeed },
    { "BossBody_SetLegPosSaveTrue", O_R1_Boss_Body::BossBody_SetLegPosSaveTrue },
    { "BossBody_SetLegPosSaveFalse", O_R1_Boss_Body::BossBody_SetLegPosSaveFalse },
    { "BossBody_SwitchLeg", O_R1_Boss_Body::BossBody_SwitchLeg },
    { "BossBody_SwitchLeg_Revert", O_R1_Boss_Body::BossBody_SwitchLeg_Revert },
    { "BossBody_MoveRArmToFront", O_R1_Boss_Body::BossBody_MoveRArmToFront },
    { "BossBody_MoveLArmToFront", O_R1_Boss_Body::BossBody_MoveLArmToFront },
    { "BossBody_HandleCharge", O_R1_Boss_Body::BossBody_HandleCharge },
    { "BossBody_SetArmsToCharge", O_R1_Boss_Body::BossBody_SetArmsToCharge },
};

#endif // RETRO_USE_NATIVE_OBJECTS
