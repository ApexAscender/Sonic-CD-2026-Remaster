#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_Scarab.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Scarab.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_Scarab::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-24, -12, 24, 24, 107, 206);
    AddSpriteFrame(-32, -12, 32, 24, 132, 206);
    AddSpriteFrame(-32, -12, 56, 24, 165, 206);
    AddSpriteFrame(-32, -12, 56, 24, 165, 231);
    AddSpriteFrame(-24, -12, 24, 24, 107, 206);
    AddSpriteFrame(-32, -12, 32, 16, 67, 240);
    AddSpriteFrame(-32, -12, 56, 24, 165, 206);
    AddSpriteFrame(-40, -12, 64, 24, 100, 231);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Scarab")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 0:
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x6000;
                objectEntityList[scriptEng.arrayPosition[0]].animationSpeed = 2;
                objectEntityList[scriptEng.arrayPosition[0]].direction = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -0xA0000;
                break;
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x6000;
                objectEntityList[scriptEng.arrayPosition[0]].animationSpeed = 2;
                objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0xA0000;
                break;
                case 2:
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 4;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x3000;
                objectEntityList[scriptEng.arrayPosition[0]].animationSpeed = 1;
                objectEntityList[scriptEng.arrayPosition[0]].direction = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -0x50000;
                break;
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 4;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x3000;
                objectEntityList[scriptEng.arrayPosition[0]].animationSpeed = 1;
                objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0x50000;
                break;
                case 4:
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 0x6000;
                objectEntityList[scriptEng.arrayPosition[0]].animationSpeed = 2;
                objectEntityList[scriptEng.arrayPosition[0]].direction = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = -0xA0000;
                objectEntityList[scriptEng.arrayPosition[0]].values[7] = 1;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_Scarab::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->priority = 1;
        if (self->values[0] < 60) {
            self->values[0]++;
            self->XPos += self->values[1];
        } else {
            self->values[0] = 0;
            self->state = 1;
        }
        ObjectTileGrip_Script(0, 0, 12, 0);
        if (self->values[1] > 0) {
            scriptEng.tempValue[0] = self->XPos;
            scriptEng.tempValue[0] -= self->values[2];
            if (scriptEng.tempValue[0] > 0x400000) {
                self->values[1] = -self->values[1];
            }
        } else {
            scriptEng.tempValue[0] = self->values[2];
            scriptEng.tempValue[0] -= self->XPos;
            if (scriptEng.tempValue[0] > 0x400000) {
                self->values[1] = -self->values[1];
            }
        }
        self->animationTimer += self->animationSpeed;
        self->animationTimer %= 40;
        break;
        case 1:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 0;
        }
        break;
    }
    if (self->values[4] > 0) {
        if (pState() == PlayerStateID("Player_State_Death")) {
            self->values[4] = 0;
        } else {
            if (self->direction == 0) {
                pXPos() = self->XPos;
                pXPos() -= 0x180000;
                pYPos() = self->YPos;
                pYPos() -= 0x30000;
            } else {
                pXPos() = self->XPos;
                pXPos() += 0x180000;
                pYPos() = self->YPos;
                pYPos() -= 0x30000;
            }
            self->values[4]--;
            if (self->values[4] == 0) {
                pState() = PlayerStateID("Player_State_Roll");
                pSpeed() = self->values[5];
                pXVel() = pSpeed();
            }
        }
    }
    if (self->values[7] == 1) {
        if (objectEntityList[objectLoop + 1].type == TypeNameID("Monitor")) {
            objectEntityList[objectLoop + 1].XPos = self->XPos;
            objectEntityList[objectLoop + 1].XPos -= 0x180000;
            objectEntityList[objectLoop + 1].YPos = self->YPos;
            objectEntityList[objectLoop + 1].YPos -= 0x40000;
        } else {
            objectEntityList[objectLoop + 1].type = TypeNameID("Blank Object");
            self->values[7] = 0;
        }
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[1] = self->YPos;
        self->XPos = self->values[2];
        self->YPos = self->values[3];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->priority = 0;
            self->state = 0;
            self->values[0] = 0;
            self->animationTimer = 0;
            if (self->values[1] < 0) {
                self->values[1] = -self->values[1];
            }
        } else {
            self->XPos = scriptEng.tempValue[0];
            self->YPos = scriptEng.tempValue[1];
        }
    }
}

void O_R8_Scarab::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 2) {
        if (self->values[4] == 0) {
            if (self->direction == 0) {
                PlayerObjectCollision(C_TOUCH, -32, -12, -12, 12);
                if (CheckResult() == 1) {
                    if (self->values[6] == 0) {
                        self->values[4] = 120;
                        pAnimation() = GVar("ANI_JUMPING");
                        pState() = PlayerStateID("Player_State_Static");
                        pSpeed() = 0;
                        pXVel() = 0;
                        pYVel() = 0;
                        pXPos() = self->XPos;
                        pXPos() -= 0x180000;
                        pYPos() = self->YPos;
                        pYPos() -= 0x30000;
                        pDirection() = 0;
                        if (GVar("Warp.Destination") > 0) {
                            if (GVar("Warp.Timer") > 99) {
                                if (GVar("Warp.Timer") < 220) {
                                    GVar("Warp.Destination") = 0;
                                }
                            }
                            GVar("Warp.Timer") = 0;
                        }
                        self->values[6] = 1;
                    }
                } else {
                    self->values[6] = 0;
                    PlayerObjectCollision(C_TOUCH, -12, -12, 20, 12);
                    if (CheckResult() == 1) {
                        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
                    }
                }
            } else {
                PlayerObjectCollision(C_TOUCH, 12, -12, 32, 12);
                if (CheckResult() == 1) {
                    if (self->values[6] == 0) {
                        self->values[4] = 120;
                        pAnimation() = GVar("ANI_JUMPING");
                        pState() = PlayerStateID("Player_State_Static");
                        pSpeed() = 0;
                        pXVel() = 0;
                        pYVel() = 0;
                        pXPos() = self->XPos;
                        pXPos() += 0x180000;
                        pYPos() = self->YPos;
                        pYPos() -= 0x30000;
                        pDirection() = 1;
                        if (GVar("Warp.Destination") > 0) {
                            if (GVar("Warp.Timer") > 99) {
                                if (GVar("Warp.Timer") < 220) {
                                    GVar("Warp.Destination") = 0;
                                }
                            }
                            GVar("Warp.Timer") = 0;
                        }
                        self->values[6] = 1;
                    }
                } else {
                    self->values[6] = 0;
                    PlayerObjectCollision(C_TOUCH, -20, -12, 12, 12);
                    if (CheckResult() == 1) {
                        CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
                    }
                }
            }
        }
    }
}

void O_R8_Scarab::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 2) {
        if (self->drawOrder == 3) {
            self->frame = self->animationTimer;
            self->frame /= 20;
            self->frame += objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
            self->frame += 2;
            drawListEntries[4].entityRefs[drawListEntries[4].listSize] = objectLoop;
            drawListEntries[4].listSize++;
            self->drawOrder = 4;
        } else {
            DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
            self->drawOrder = 3;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
