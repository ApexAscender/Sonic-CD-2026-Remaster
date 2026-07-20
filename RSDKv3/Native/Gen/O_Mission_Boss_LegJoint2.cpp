#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_Boss_LegJoint2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Boss_LegJoint2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_Boss_LegJoint2::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-8, -8, 16, 16, 74, 42);
}

void O_Mission_Boss_LegJoint2::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[2] = 88;
        scriptEng.tempValue[0] = 2;
        scriptEng.tempValue[0] *= self->propertyValue;
        scriptEng.tempValue[0] /= 10;
        self->values[5] = scriptEng.tempValue[0];
        self->state = 6;
        break;
        case 1:
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        if (objectEntityList[scriptEng.arrayPosition[1]].state != 3) {
            if (objectEntityList[scriptEng.arrayPosition[1]].state != 4) {
                objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
                objectEntityList[scriptEng.arrayPosition[1]].state = 3;
            }
        }
        scriptEng.tempValue[0] = 0;
        if (self->values[2] > 0) {
            self->values[2] -= self->values[5];
            if (self->values[2] > 0) {
                BossLegJoint2_HandleMovement();
                scriptEng.tempValue[0] = 1;
            }
        }
        if (scriptEng.tempValue[0] == 0) {
            self->values[2] = 0;
            if (objectEntityList[scriptEng.arrayPosition[1]].state != 4) {
                scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[1]].values[4] >> 0) & 1);
                if (scriptEng.tempValue[0] == 0) {
                    BossLegJoint2_HandleMovement();
                } else {
                    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
                    self->state = 2;
                    BossLegJoint2_HandleMovement();
                }
            } else {
                self->state = 2;
                BossLegJoint2_HandleMovement();
            }
        }
        break;
        case 2:
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        self->values[2] += self->values[5];
        if (self->values[2] >= 88) {
            self->values[2] = 88;
            self->state = 3;
            objectEntityList[scriptEng.arrayPosition[1]].state = 1;
        }
        BossLegJoint2_HandleMovement();
        break;
        case 3:
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[1]].values[4] >> 4) & 1);
        if (scriptEng.tempValue[0] == 1) {
            self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
        }
        BossLegJoint2_HandleMovement();
        break;
        case 4:
        scriptEng.tempValue[0] = ((self->values[4] >> 0) & 1);
        if (scriptEng.tempValue[0] == 0) {
            self->values[2] -= self->values[5];
            if (self->values[2] < 24) {
                self->values[2] = 24;
                self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
            }
        }
        BossLegJoint2_HandleMovement();
        break;
        case 5:
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        if (objectEntityList[scriptEng.arrayPosition[1]].state == 4) {
            if (self->values[2] == 0) {
                scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[1]].values[4] >> 0) & 1);
                if (scriptEng.tempValue[0] == 1) {
                    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
                    self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
                }
                BossLegJoint2_HandleMovement();
            } else {
                if (self->values[2] != 0) {
                    self->values[2] -= self->values[5];
                    if (self->values[2] < 0) {
                        self->values[2] = 0;
                    }
                }
                BossLegJoint2_HandleMovement();
            }
        } else {
            objectEntityList[scriptEng.arrayPosition[1]].state = 3;
            if (self->values[2] != 0) {
                self->values[2] -= self->values[5];
                if (self->values[2] < 0) {
                    self->values[2] = 0;
                }
            }
            BossLegJoint2_HandleMovement();
        }
        break;
        case 6:
        BossLegJoint2_HandleLanding();
        break;
        case 7:
        if (self->values[2] < 24) {
            self->values[2] += self->values[5];
            scriptEng.arrayPosition[0] = self->values[1];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 7));
            scriptEng.arrayPosition[0] = self->values[0];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
            scriptEng.arrayPosition[0] = objectEntityList[scriptEng.arrayPosition[1]].values[1];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[1]].values[4] = (1) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 7)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 7));
            BossLegJoint2_HandleLanding();
            if (self->values[2] > 24) {
                self->values[2] = 24;
            }
        } else {
            if (self->values[2] > 24) {
                scriptEng.arrayPosition[0] = self->values[1];
                scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                if (objectEntityList[scriptEng.arrayPosition[1]].state == 4) {
                    if (self->values[2] == 0) {
                        scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[1]].values[4] >> 0) & 1);
                        if (scriptEng.tempValue[0] == 1) {
                            objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
                            self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
                        }
                        BossLegJoint2_HandleMovement();
                    } else {
                        if (self->values[2] != 0) {
                            self->values[2] -= self->values[5];
                            if (self->values[2] < 0) {
                                self->values[2] = 0;
                            }
                        }
                        BossLegJoint2_HandleMovement();
                    }
                } else {
                    objectEntityList[scriptEng.arrayPosition[1]].state = 3;
                    if (self->values[2] != 0) {
                        self->values[2] -= self->values[5];
                        if (self->values[2] < 0) {
                            self->values[2] = 0;
                        }
                    }
                    BossLegJoint2_HandleMovement();
                }
                self->values[2] -= self->values[5];
                if (self->values[2] < 24) {
                    self->values[2] = 24;
                }
            } else {
                scriptEng.arrayPosition[0] = self->values[1];
                scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
                scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[1]].values[4] >> 0) & 1);
                if (scriptEng.tempValue[0] == 1) {
                    self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
                }
                BossLegJoint2_HandleMovement();
            }
        }
        break;
        case 8:
        scriptEng.arrayPosition[0] = self->values[0];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        self->XPos = objectEntityList[scriptEng.arrayPosition[1]].XPos;
        self->XPos -= 0xA0000;
        self->YPos = objectEntityList[scriptEng.arrayPosition[1]].YPos;
        self->values[2] = objectEntityList[scriptEng.arrayPosition[1]].values[2];
        break;
        case 9:
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        scriptEng.tempValue[1] = 0;
        if (objectEntityList[scriptEng.arrayPosition[1]].state != 3) {
            if (objectEntityList[scriptEng.arrayPosition[1]].state != 4) {
                objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
                objectEntityList[scriptEng.arrayPosition[1]].state = 3;
            } else {
                if (self->values[2] != 32) {
                    self->values[2] -= self->values[5];
                    if (self->values[2] > 0) {
                        scriptEng.tempValue[1] = 1;
                    }
                }
                if (scriptEng.tempValue[1] == 0) {
                    self->values[2] = 32;
                    objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
                    self->state = 10;
                }
            }
        }
        BossLegJoint2_HandleMovement();
        break;
        case 10:
        scriptEng.arrayPosition[0] = self->values[1];
        scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
        self->values[2] += self->values[5];
        if (self->values[2] >= 48) {
            self->values[2] = 48;
            self->state = 3;
            objectEntityList[scriptEng.arrayPosition[1]].state = 1;
        }
        BossLegJoint2_HandleMovement();
        break;
        case 11:
        scriptEng.tempValue[0] = ((self->values[4] >> 0) & 1);
        if (scriptEng.tempValue[0] == 0) {
            scriptEng.arrayPosition[0] = self->values[1];
            scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            if (objectEntityList[scriptEng.arrayPosition[1]].state != 1) {
                if (objectEntityList[scriptEng.arrayPosition[1]].state != 2) {
                    objectEntityList[scriptEng.arrayPosition[1]].state = 1;
                } else {
                    self->values[2] += self->values[5];
                    if (self->values[2] >= 80) {
                        self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
                    }
                }
            }
        }
        BossLegJoint2_HandleMovement();
        break;
        case 12:
        scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
        if (scriptEng.tempValue[0] == 0) {
            self->values[2] -= 0x600;
        } else {
            self->values[2] += 0x600;
        }
        self->XPos += self->values[2];
        self->values[5] += 0x1860;
        self->YPos += self->values[5];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
            self->priority = 0;
        }
        break;
    }
}

void O_Mission_Boss_LegJoint2::ObjectDraw()
{
    DrawSprite_Frame(0);
}

void O_Mission_Boss_LegJoint2::BossLegJoint2_JointRotation()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[0];
    self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
    self->XPos += 0xC0000;
    self->XPos += scriptEng.tempValue[7];
    if (self->drawOrder == 2) {
        self->XPos -= 0xA0000;
    }
    self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
    self->YPos += 0x140000;
    self->YPos += scriptEng.tempValue[6];
}

void O_Mission_Boss_LegJoint2::BossLegJoint2_HandleMovement()
{
    Entity *self = Self();

    scriptEng.tempValue[6] = Sin256(self->values[2]);
    scriptEng.tempValue[6] <<= 12;
    scriptEng.tempValue[7] = Cos256(self->values[2]);
    scriptEng.tempValue[7] <<= 12;
    scriptEng.tempValue[0] = ((self->values[4] >> 4) & 1);
    if (scriptEng.tempValue[0] == 0) {
        self->values[4] = (0) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
        BossLegJoint2_JointRotation();
    } else {
        scriptEng.tempValue[0] = ((self->values[4] >> 5) & 1);
        if (scriptEng.tempValue[0] == 0) {
            BossLegJoint2_JointRotation();
        } else {
            scriptEng.tempValue[0] = ((self->values[4] >> 1) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[4] = (1) ? (self->values[4] | (1 << 1)) : (self->values[4] & ~(1 << 1));
                self->values[6] = scriptEng.tempValue[6];
                self->values[7] = scriptEng.tempValue[7];
            } else {
                scriptEng.arrayPosition[0] = self->values[0];
                scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[0];
                scriptEng.tempValue[0] = scriptEng.tempValue[7];
                scriptEng.tempValue[0] -= self->values[7];
                self->values[7] = scriptEng.tempValue[7];
                objectEntityList[scriptEng.arrayPosition[0]].XPos -= scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[1]].XPos -= scriptEng.tempValue[0];
                scriptEng.tempValue[0] = scriptEng.tempValue[6];
                scriptEng.tempValue[0] -= self->values[6];
                self->values[6] = scriptEng.tempValue[6];
                objectEntityList[scriptEng.arrayPosition[0]].YPos -= scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[1]].YPos -= scriptEng.tempValue[0];
            }
        }
    }
}

void O_Mission_Boss_LegJoint2::BossLegJoint2_HandleLanding()
{
    Entity *self = Self();

    scriptEng.arrayPosition[0] = self->values[1];
    scriptEng.arrayPosition[1] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
    if (objectEntityList[scriptEng.arrayPosition[1]].state == 2) {
        if (self->values[2] >= 88) {
            scriptEng.tempValue[0] = ((objectEntityList[scriptEng.arrayPosition[1]].values[4] >> 0) & 1);
            if (scriptEng.tempValue[0] == 1) {
                objectEntityList[scriptEng.arrayPosition[1]].values[4] = (0) ? (objectEntityList[scriptEng.arrayPosition[1]].values[4] | (1 << 0)) : (objectEntityList[scriptEng.arrayPosition[1]].values[4] & ~(1 << 0));
                self->values[4] = (1) ? (self->values[4] | (1 << 0)) : (self->values[4] & ~(1 << 0));
            }
            BossLegJoint2_HandleMovement();
        }
    } else {
        objectEntityList[scriptEng.arrayPosition[1]].state = 1;
        if (self->values[2] < 88) {
            self->values[2] += self->values[5];
            if (self->values[2] > 88) {
                self->values[2] = 88;
            }
        }
        BossLegJoint2_HandleMovement();
    }
}

const Native::NativeFunctionDef O_Mission_Boss_LegJoint2::funcs[3] = {
    { "BossLegJoint2_JointRotation", O_Mission_Boss_LegJoint2::BossLegJoint2_JointRotation },
    { "BossLegJoint2_HandleMovement", O_Mission_Boss_LegJoint2::BossLegJoint2_HandleMovement },
    { "BossLegJoint2_HandleLanding", O_Mission_Boss_LegJoint2::BossLegJoint2_HandleLanding },
};

#endif // RETRO_USE_NATIVE_OBJECTS
