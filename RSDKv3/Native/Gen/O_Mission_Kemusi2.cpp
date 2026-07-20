#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_Kemusi2.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Kemusi2.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_Kemusi2::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects.gif");
    AddSpriteFrame(-8, -16, 16, 24, 125, 75);
    AddSpriteFrame(-8, -16, 16, 24, 125, 50);
    AddSpriteFrame(-8, -16, 16, 24, 67, 150);
    AddSpriteFrame(-8, -8, 16, 16, 52, 1);
}

void O_Mission_Kemusi2::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->values[1] = self->XPos;
        self->values[1] += 0xC0000;
        self->values[2] = self->XPos;
        self->values[2] += 0x180000;
        self->values[3] = self->XPos;
        self->values[3] += 0x240000;
        self->values[4] = self->YPos;
        self->values[5] = self->YPos;
        self->values[6] = self->YPos;
        self->scale = self->XPos;
        self->scale -= 0x400000;
        self->rotation = self->XPos;
        self->rotation += 0x400000;
        self->state = 1;
        break;
        case 1:
        scriptEng.tempValue[0] = ((self->values[7] >> 0) & 1);
        scriptEng.tempValue[1] = ((self->values[7] >> 1) & 1);
        scriptEng.tempValue[2] = ((self->values[7] >> 2) & 1);
        scriptEng.tempValue[3] = ((self->values[7] >> 3) & 1);
        if (scriptEng.tempValue[0] == 0) {
            ObjectTileCollision_Script(0, 0, 8, 0);
            if (CheckResult() == 0) {
                self->YPos += 0x10000;
            } else {
                scriptEng.tempValue[0] = CheckResult();
            }
        }
        scriptEng.tempValue[4] = self->XPos;
        scriptEng.tempValue[5] = self->YPos;
        if (scriptEng.tempValue[1] == 0) {
            self->XPos = self->values[1];
            self->YPos = self->values[4];
            ObjectTileCollision_Script(0, 0, 8, 0);
            if (CheckResult() == 0) {
                self->values[4] += 0x10000;
            } else {
                scriptEng.tempValue[1] = CheckResult();
                self->values[4] = self->YPos;
            }
        }
        if (scriptEng.tempValue[2] == 0) {
            self->XPos = self->values[2];
            self->YPos = self->values[5];
            ObjectTileCollision_Script(0, 0, 8, 0);
            if (CheckResult() == 0) {
                self->values[5] += 0x10000;
            } else {
                scriptEng.tempValue[2] = CheckResult();
                self->values[5] = self->YPos;
            }
        }
        if (scriptEng.tempValue[3] == 0) {
            self->XPos = self->values[3];
            self->YPos = self->values[6];
            ObjectTileCollision_Script(0, 0, 8, 0);
            if (CheckResult() == 0) {
                self->values[6] += 0x10000;
            } else {
                scriptEng.tempValue[3] = CheckResult();
                self->values[6] = self->YPos;
            }
        }
        self->XPos = scriptEng.tempValue[4];
        self->YPos = scriptEng.tempValue[5];
        scriptEng.tempValue[4] = scriptEng.tempValue[0];
        scriptEng.tempValue[4] += scriptEng.tempValue[1];
        scriptEng.tempValue[4] += scriptEng.tempValue[2];
        scriptEng.tempValue[4] += scriptEng.tempValue[3];
        if (scriptEng.tempValue[4] == 4) {
            if (self->propertyValue == 0) {
                self->state = 3;
            } else {
                self->state = 5;
            }
            self->values[7] = 0;
        } else {
            self->values[7] = (scriptEng.tempValue[0]) ? (self->values[7] | (1 << 0)) : (self->values[7] & ~(1 << 0));
            self->values[7] = (scriptEng.tempValue[1]) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
            self->values[7] = (scriptEng.tempValue[2]) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
            self->values[7] = (scriptEng.tempValue[3]) ? (self->values[7] | (1 << 3)) : (self->values[7] & ~(1 << 3));
        }
        break;
        case 2:
        if (self->values[0] < 9) {
            self->values[0]++;
            scriptEng.tempValue[0] = ((self->values[7] >> 0) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->XPos -= 0x20000;
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    if (self->XPos < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 0)) : (self->values[7] & ~(1 << 0));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 0)) : (self->values[7] & ~(1 << 0));
                }
            } else {
                self->XPos += 0x20000;
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    if (self->XPos > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 0)) : (self->values[7] & ~(1 << 0));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 0)) : (self->values[7] & ~(1 << 0));
                }
            }
            scriptEng.tempValue[1] = self->XPos;
            scriptEng.tempValue[2] = self->YPos;
            scriptEng.tempValue[0] = ((self->values[7] >> 1) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[1] -= 0x15554;
                self->XPos = self->values[1];
                self->YPos = self->values[4];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[4] = self->YPos;
                    if (self->values[1] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                }
            } else {
                self->values[1] += 0x15554;
                self->XPos = self->values[1];
                self->YPos = self->values[4];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[4] = self->YPos;
                    if (self->values[1] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                }
            }
            scriptEng.tempValue[0] = ((self->values[7] >> 2) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[2] -= 0xAAA8;
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[5] = self->YPos;
                    if (self->values[2] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                }
            } else {
                self->values[2] += 0xAAA8;
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[5] = self->YPos;
                    if (self->values[2] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                }
            }
            self->XPos = scriptEng.tempValue[1];
            self->YPos = scriptEng.tempValue[2];
        } else {
            if (self->values[7] == 0) {
                self->values[1] = self->XPos;
                self->values[1] += 0xC0000;
                self->values[2] = self->XPos;
                self->values[2] += 0x180000;
                self->values[3] = self->XPos;
                self->values[3] += 0x240000;
            }
            if (self->values[7] == 15) {
                self->values[1] = self->XPos;
                self->values[1] -= 0xC0000;
                self->values[2] = self->XPos;
                self->values[2] -= 0x180000;
                self->values[3] = self->XPos;
                self->values[3] -= 0x240000;
            }
            self->values[0] = 0;
            self->state = 3;
        }
        break;
        case 3:
        if (self->values[0] < 9) {
            self->values[0]++;
            scriptEng.tempValue[1] = self->XPos;
            scriptEng.tempValue[2] = self->YPos;
            scriptEng.tempValue[0] = ((self->values[7] >> 1) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[1] -= 0xAAA8;
                self->XPos = self->values[1];
                self->YPos = self->values[4];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[4] = self->YPos;
                    if (self->values[1] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                }
            } else {
                self->values[1] += 0xAAA8;
                self->XPos = self->values[1];
                self->YPos = self->values[4];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[4] = self->YPos;
                    if (self->values[1] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                }
            }
            scriptEng.tempValue[0] = ((self->values[7] >> 2) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[2] -= 0x15554;
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[5] = self->YPos;
                    if (self->values[2] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                }
            } else {
                self->values[2] += 0x15554;
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[5] = self->YPos;
                    if (self->values[2] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                }
            }
            scriptEng.tempValue[0] = ((self->values[7] >> 3) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[3] -= 0x20000;
                self->XPos = self->values[3];
                self->YPos = self->values[6];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[6] = self->YPos;
                    if (self->values[3] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 3)) : (self->values[7] & ~(1 << 3));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 3)) : (self->values[7] & ~(1 << 3));
                }
            } else {
                self->values[3] += 0x20000;
                self->XPos = self->values[3];
                self->YPos = self->values[6];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[6] = self->YPos;
                    if (self->values[3] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 3)) : (self->values[7] & ~(1 << 3));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 3)) : (self->values[7] & ~(1 << 3));
                }
            }
            self->XPos = scriptEng.tempValue[1];
            self->YPos = scriptEng.tempValue[2];
        } else {
            self->values[0] = 0;
            self->state = 2;
        }
        break;
        case 4:
        if (self->values[0] < 9) {
            self->values[0]++;
            scriptEng.tempValue[0] = ((self->values[7] >> 0) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->XPos -= 0x10000;
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    if (self->XPos < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 0)) : (self->values[7] & ~(1 << 0));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 0)) : (self->values[7] & ~(1 << 0));
                }
            } else {
                self->XPos += 0x10000;
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    if (self->XPos > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 0)) : (self->values[7] & ~(1 << 0));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 0)) : (self->values[7] & ~(1 << 0));
                }
            }
            scriptEng.tempValue[1] = self->XPos;
            scriptEng.tempValue[2] = self->YPos;
            scriptEng.tempValue[0] = ((self->values[7] >> 1) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[1] -= 0xAAAA;
                self->XPos = self->values[1];
                self->YPos = self->values[4];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[4] = self->YPos;
                    if (self->values[1] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                }
            } else {
                self->values[1] += 0xAAAA;
                self->XPos = self->values[1];
                self->YPos = self->values[4];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[4] = self->YPos;
                    if (self->values[1] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                }
            }
            scriptEng.tempValue[0] = ((self->values[7] >> 2) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[2] -= 0x5554;
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[5] = self->YPos;
                    if (self->values[2] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                }
            } else {
                self->values[2] += 0x5554;
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[5] = self->YPos;
                    if (self->values[2] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                }
            }
            self->XPos = scriptEng.tempValue[1];
            self->YPos = scriptEng.tempValue[2];
        } else {
            if (self->values[7] == 0) {
                self->values[1] = self->XPos;
                self->values[1] += 0xC0000;
                self->values[2] = self->XPos;
                self->values[2] += 0x180000;
                self->values[3] = self->XPos;
                self->values[3] += 0x240000;
            }
            if (self->values[7] == 15) {
                self->values[1] = self->XPos;
                self->values[1] -= 0xC0000;
                self->values[2] = self->XPos;
                self->values[2] -= 0x180000;
                self->values[3] = self->XPos;
                self->values[3] -= 0x240000;
            }
            self->values[0] = 0;
            self->state = 5;
        }
        break;
        case 5:
        if (self->values[0] < 36) {
            self->values[0]++;
            scriptEng.tempValue[1] = self->XPos;
            scriptEng.tempValue[2] = self->YPos;
            scriptEng.tempValue[0] = ((self->values[7] >> 1) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[1] -= 0x5554;
                self->XPos = self->values[1];
                self->YPos = self->values[4];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[4] = self->YPos;
                    if (self->values[1] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                }
            } else {
                self->values[1] += 0x5554;
                self->XPos = self->values[1];
                self->YPos = self->values[4];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[4] = self->YPos;
                    if (self->values[1] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 1)) : (self->values[7] & ~(1 << 1));
                }
            }
            scriptEng.tempValue[0] = ((self->values[7] >> 2) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[2] -= 0xAAA8;
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[5] = self->YPos;
                    if (self->values[2] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                }
            } else {
                self->values[2] += 0xAAA8;
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[5] = self->YPos;
                    if (self->values[2] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 2)) : (self->values[7] & ~(1 << 2));
                }
            }
            scriptEng.tempValue[0] = ((self->values[7] >> 3) & 1);
            if (scriptEng.tempValue[0] == 0) {
                self->values[3] -= 0x10000;
                self->XPos = self->values[3];
                self->YPos = self->values[6];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[6] = self->YPos;
                    if (self->values[3] < self->scale) {
                        self->values[7] = (1) ? (self->values[7] | (1 << 3)) : (self->values[7] & ~(1 << 3));
                    }
                } else {
                    self->values[7] = (1) ? (self->values[7] | (1 << 3)) : (self->values[7] & ~(1 << 3));
                }
            } else {
                self->values[3] += 0x10000;
                self->XPos = self->values[3];
                self->YPos = self->values[6];
                ObjectTileGrip_Script(0, 0, 8, 0);
                if (CheckResult() == 1) {
                    self->values[6] = self->YPos;
                    if (self->values[3] > self->rotation) {
                        self->values[7] = (0) ? (self->values[7] | (1 << 3)) : (self->values[7] & ~(1 << 3));
                    }
                } else {
                    self->values[7] = (0) ? (self->values[7] | (1 << 3)) : (self->values[7] & ~(1 << 3));
                }
            }
            self->XPos = scriptEng.tempValue[1];
            self->YPos = scriptEng.tempValue[2];
        } else {
            self->values[0] = 0;
            self->state = 4;
        }
        break;
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_Mission_Kemusi2::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_ENEMY, -8, -10, 8, 8);
    if (CheckResult() == 1) {
        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
    } else {
        scriptEng.tempValue[1] = self->XPos;
        scriptEng.tempValue[2] = self->YPos;
        if (self->propertyValue == 0) {
            self->XPos = self->values[1];
            self->YPos = self->values[4];
            PlayerObjectCollision(C_ENEMY, -8, -10, 8, 8);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            } else {
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                PlayerObjectCollision(C_ENEMY, -8, -10, 8, 8);
                if (CheckResult() == 1) {
                    CallScriptFunctionNamed("Player_Hit", scriptSub);
                } else {
                    self->XPos = self->values[3];
                    self->YPos = self->values[6];
                    PlayerObjectCollision(C_ENEMY, -8, -10, 8, 8);
                    if (CheckResult() == 1) {
                        CallScriptFunctionNamed("Player_Hit", scriptSub);
                    }
                }
            }
        } else {
            self->XPos = self->values[1];
            self->YPos = self->values[4];
            PlayerObjectCollision(C_ENEMY, -8, -8, 8, 8);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
            } else {
                self->XPos = self->values[2];
                self->YPos = self->values[5];
                PlayerObjectCollision(C_ENEMY, -8, -8, 8, 8);
                if (CheckResult() == 1) {
                    CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
                } else {
                    self->XPos = self->values[3];
                    self->YPos = self->values[6];
                    PlayerObjectCollision(C_ENEMY, -8, -8, 8, 8);
                    if (CheckResult() == 1) {
                        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
                    }
                }
            }
        }
        self->XPos = scriptEng.tempValue[1];
        self->YPos = scriptEng.tempValue[2];
    }
}

void O_Mission_Kemusi2::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        self->direction = ((self->values[7] >> 3) & 1);
        DrawSpriteFX_Script(2, FX_FLIP, self->values[3], self->values[6]);
        self->direction = ((self->values[7] >> 2) & 1);
        DrawSpriteFX_Script(2, FX_FLIP, self->values[2], self->values[5]);
        self->direction = ((self->values[7] >> 1) & 1);
        DrawSpriteFX_Script(2, FX_FLIP, self->values[1], self->values[4]);
    } else {
        self->direction = ((self->values[7] >> 3) & 1);
        DrawSpriteFX_Script(3, FX_FLIP, self->values[3], self->values[6]);
        self->direction = ((self->values[7] >> 2) & 1);
        DrawSpriteFX_Script(3, FX_FLIP, self->values[2], self->values[5]);
        self->direction = ((self->values[7] >> 1) & 1);
        DrawSpriteFX_Script(3, FX_FLIP, self->values[1], self->values[4]);
    }
    self->direction = ((self->values[7] >> 0) & 1);
    switch (self->state) {
        case 0:
        case 1:
        case 3:
        case 5:
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        break;
        case 2:
        case 4:
        DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
