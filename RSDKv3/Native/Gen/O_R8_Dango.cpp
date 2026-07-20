#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_Dango.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Dango.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_Dango::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-16, -7, 32, 24, 1, 84);
    AddSpriteFrame(-16, -7, 32, 24, 1, 109);
    AddSpriteFrame(-16, -7, 32, 24, 34, 84);
    AddSpriteFrame(-16, -7, 32, 24, 34, 109);
    AddSpriteFrame(-16, -16, 32, 32, 34, 134);
    AddSpriteFrame(-16, -16, 32, 32, 1, 167);
    AddSpriteFrame(-16, -15, 32, 32, 34, 167);
    AddSpriteFrame(-16, -15, 32, 32, 124, 223);
    AddSpriteFrame(-16, -16, 32, 32, 1, 134);
    AddSpriteFrame(-16, -15, 32, 32, 34, 167);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Dango")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 0) {
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x6000;
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = -0x1000;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_Dango::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        switch (self->state) {
            case 0:
            self->priority = 1;
            self->frame = self->values[0];
            self->frame /= 10;
            self->values[0]++;
            self->values[0] %= 20;
            self->XPos += self->values[3];
            if (self->direction == 0) {
                ObjectTileGrip_Script(0, -5, 15, 0);
            } else {
                ObjectTileGrip_Script(0, 5, 15, 0);
            }
            if (CheckResult() == 0) {
                self->values[3] = -self->values[3];
                self->direction++;
                self->direction &= 1;
                self->values[4] = 0;
            } else {
                if (self->values[3] > 0) {
                    ObjectTileCollision_Script(1, 16, 8, 0);
                    if (CheckResult() == 1) {
                        self->values[3] = -self->values[3];
                        self->direction++;
                        self->direction &= 1;
                        self->values[4] = 0;
                    }
                } else {
                    ObjectTileCollision_Script(2, -16, 8, 0);
                    if (CheckResult() == 1) {
                        self->values[3] = -self->values[3];
                        self->direction++;
                        self->direction &= 1;
                        self->values[4] = 0;
                    }
                }
            }
            break;
            case 1:
            self->frame = 4;
            if (self->values[0] < 8) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 2:
            self->frame = 5;
            if (self->values[0] < 6) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 3:
            self->frame = self->animationTimer;
            self->frame /= 5;
            self->frame += 6;
            self->animationTimer++;
            self->animationTimer %= 10;
            if (self->values[0] < 34) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
                if (self->direction == 0) {
                    self->values[3] = -0x40000;
                } else {
                    self->values[3] = 0x40000;
                }
            }
            break;
            case 4:
            self->frame = self->animationTimer;
            self->frame /= 5;
            self->frame += 6;
            self->animationTimer++;
            self->animationTimer %= 10;
            self->XPos += self->values[3];
            if (self->direction == 0) {
                ObjectTileGrip_Script(0, -5, 15, 0);
            } else {
                ObjectTileGrip_Script(0, 5, 15, 0);
            }
            if (CheckResult() == 0) {
                self->state++;
                self->values[4]++;
            } else {
                if (self->values[3] > 0) {
                    ObjectTileCollision_Script(1, 16, 8, 0);
                    if (CheckResult() == 1) {
                        self->state++;
                        self->values[4]++;
                    }
                } else {
                    ObjectTileCollision_Script(2, -16, 8, 0);
                    if (CheckResult() == 1) {
                        self->state++;
                        self->values[4]++;
                    }
                }
            }
            break;
            case 5:
            self->frame = 5;
            if (self->values[0] < 6) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 6:
            self->frame = 4;
            if (self->values[0] < 8) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 7:
            self->frame = 0;
            if (self->values[0] < 16) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state = 0;
                if (self->values[4] > 7) {
                    self->direction++;
                    self->direction &= 1;
                    self->values[4] = 0;
                }
                if (self->direction == 0) {
                    self->values[3] = -0x6000;
                } else {
                    self->values[3] = 0x6000;
                }
            }
            break;
            case 8:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
            }
            break;
        }
    } else {
        switch (self->state) {
            case 0:
            self->priority = 1;
            self->frame = self->values[0];
            self->frame /= 30;
            self->frame += 2;
            self->values[0]++;
            self->values[0] %= 60;
            self->XPos += self->values[3];
            if (self->direction == 0) {
                ObjectTileGrip_Script(0, -5, 15, 0);
            } else {
                ObjectTileGrip_Script(0, 5, 15, 0);
            }
            if (CheckResult() == 0) {
                self->values[3] = -self->values[3];
                self->direction++;
                self->direction &= 1;
                self->values[4] = 0;
            } else {
                if (self->values[3] > 0) {
                    ObjectTileCollision_Script(1, 16, 8, 0);
                    if (CheckResult() == 1) {
                        self->values[3] = -self->values[3];
                        self->direction++;
                        self->direction &= 1;
                        self->values[4] = 0;
                    }
                } else {
                    ObjectTileCollision_Script(2, -16, 8, 0);
                    if (CheckResult() == 1) {
                        self->values[3] = -self->values[3];
                        self->direction++;
                        self->direction &= 1;
                        self->values[4] = 0;
                    }
                }
            }
            break;
            case 1:
            self->frame = 4;
            if (self->values[0] < 20) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 2:
            self->frame = 5;
            if (self->values[0] < 12) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 3:
            self->frame = self->animationTimer;
            self->frame /= 10;
            self->frame += 8;
            self->animationTimer++;
            self->animationTimer %= 20;
            if (self->values[0] < 96) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
                if (self->direction == 0) {
                    self->values[3] = -0x10000;
                } else {
                    self->values[3] = 0x10000;
                }
            }
            break;
            case 4:
            self->frame = self->animationTimer;
            self->frame /= 10;
            self->frame += 8;
            self->animationTimer++;
            self->animationTimer %= 20;
            self->XPos += self->values[3];
            if (self->direction == 0) {
                ObjectTileGrip_Script(0, -5, 15, 0);
            } else {
                ObjectTileGrip_Script(0, 5, 15, 0);
            }
            if (CheckResult() == 0) {
                self->state++;
                self->values[4]++;
            } else {
                if (self->values[3] > 0) {
                    ObjectTileCollision_Script(1, 16, 8, 0);
                    if (CheckResult() == 1) {
                        self->state++;
                        self->values[4]++;
                    }
                } else {
                    ObjectTileCollision_Script(2, -16, 8, 0);
                    if (CheckResult() == 1) {
                        self->state++;
                        self->values[4]++;
                    }
                }
            }
            break;
            case 5:
            self->frame = 5;
            if (self->values[0] < 12) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 6:
            self->frame = 4;
            if (self->values[0] < 20) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state++;
            }
            break;
            case 7:
            self->frame = 2;
            if (self->values[0] < 64) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->state = 0;
                if (self->values[4] > 7) {
                    self->direction++;
                    self->direction &= 1;
                    self->values[4] = 0;
                }
                if (self->direction == 0) {
                    self->values[3] = -0x1000;
                } else {
                    self->values[3] = 0x1000;
                }
            }
            break;
            case 8:
            if (GetObjectOutOfBounds(objectLoop) == 1) {
                self->state = 0;
                self->priority = 0;
            }
            break;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        self->XPos = self->values[1];
        self->YPos = self->values[2];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->priority = 0;
            self->state = 0;
            self->values[0] = 0;
            self->direction = 0;
            self->values[4] = 0;
            if (self->propertyValue == 0) {
                self->values[3] = -0x6000;
            } else {
                self->values[3] = -0x1000;
            }
        } else {
            self->XPos = scriptEng.tempValue[0];
            self->YPos = scriptEng.tempValue[1];
        }
    }
}

void O_R8_Dango::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->direction == 0) {
            PlayerObjectCollision(C_TOUCH, -112, -128, 0, 128);
        } else {
            PlayerObjectCollision(C_TOUCH, 0, -128, 112, 128);
        }
        if (CheckResult() == 1) {
            self->state = 1;
        }
    }
    switch (self->state) {
        case 0:
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
        PlayerObjectCollision(C_TOUCH, -14, -10, 14, 10);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
        break;
        case 3:
        PlayerObjectCollision(C_TOUCH, -14, -10, 14, 10);
        if (CheckResult() == 1) {
            CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
            scriptEng.tempValue[0] = CheckResult();
            CheckResult() = (pAnimation() == GVar("ANI_SPINDASH"));
            scriptEng.tempValue[0] |= CheckResult();
            if (scriptEng.tempValue[0] == 1) {
                pSpeed() = pXPos();
                pSpeed() -= self->XPos;
                pSpeed() >>= 2;
                pXVel() = pSpeed();
                if (pGravity() == 1) {
                    pYVel() = pYPos();
                    pYVel() -= self->YPos;
                    pYVel() >>= 2;
                }
            } else {
                CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
            }
        }
        break;
        case 4:
        PlayerObjectCollision(C_TOUCH, -14, -10, 14, 10);
        if (CheckResult() == 1) {
            CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
            scriptEng.tempValue[0] = CheckResult();
            CheckResult() = (pAnimation() == GVar("ANI_SPINDASH"));
            scriptEng.tempValue[0] |= CheckResult();
            if (scriptEng.tempValue[0] == 1) {
                self->values[3] = pXVel();
                pSpeed() = pXPos();
                pSpeed() -= self->XPos;
                pSpeed() >>= 2;
                pXVel() = pSpeed();
                if (pGravity() == 1) {
                    pYVel() = pYPos();
                    pYVel() -= self->YPos;
                    pYVel() >>= 2;
                } else {
                    pState() = PlayerStateID("Player_State_Roll");
                    pAnimation() = GVar("ANI_JUMPING");
                }
            } else {
                CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
            }
        }
        break;
    }
}

void O_R8_Dango::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 8) {
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
