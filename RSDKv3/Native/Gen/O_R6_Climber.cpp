#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_Climber.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Climber.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_Climber::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects3.gif");
    AddSpriteFrame(-24, -24, 48, 48, 1, 52);
    AddSpriteFrame(-24, -16, 48, 32, 174, 220);
    AddSpriteFrame(-24, -8, 48, 23, 122, 181);
    AddSpriteFrame(-56, -32, 32, 16, 223, 233);
    AddSpriteFrame(-56, -20, 32, 16, 223, 233);
    AddSpriteFrame(-56, -8, 32, 16, 223, 233);
    AddSpriteFrame(-56, 4, 32, 16, 223, 233);
    AddSpriteFrame(-56, 16, 32, 16, 223, 233);
    AddSpriteFrame(-6, 15, 12, 9, 197, 200);
    AddSpriteFrame(-6, 15, 12, 9, 210, 200);
    AddSpriteFrame(-6, 15, 12, 9, 197, 210);
    AddSpriteFrame(-6, 15, 12, 9, 210, 210);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Climber")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_Climber::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->values[2] == 1) {
            if (self->frame > 0) {
                self->YPos -= 0xC0000;
                self->frame--;
            } else {
                if (self->values[5] < 120) {
                    self->values[5]++;
                    if (self->values[5] == 60) {
                        self->values[4] = 1;
                    }
                } else {
                    self->values[5] = 0;
                    self->state = 1;
                    self->values[4] = 2;
                }
            }
        } else {
            if (self->frame < 4) {
                self->frame++;
                self->YPos -= 0xC0000;
            } else {
                if (self->values[5] < 120) {
                    self->values[5]++;
                    if (self->values[5] == 60) {
                        self->values[4] = 1;
                    }
                } else {
                    self->values[5] = 0;
                    self->state = 1;
                    self->values[4] = 2;
                }
            }
        }
    } else {
        self->YPos += 0x10000;
        if (self->values[2] == 0) {
            ObjectTileCollision_Script(0, -25, 32, 0);
        } else {
            ObjectTileCollision_Script(0, 25, 32, 0);
        }
    }
}

void O_R6_Climber::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->frame) {
        case 0:
        PlayerObjectCollision(C_PLATFORM, -56, -33, -24, -16);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 1) {
                self->values[2] = 0;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        PlayerObjectCollision(C_PLATFORM, 24, 15, 56, 32);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 0) {
                self->values[2] = 1;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        break;
        case 1:
        PlayerObjectCollision(C_PLATFORM, -56, -21, -24, -4);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 1) {
                self->values[2] = 0;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        PlayerObjectCollision(C_PLATFORM, 24, 3, 56, 20);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 0) {
                self->values[2] = 1;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        break;
        case 2:
        PlayerObjectCollision(C_PLATFORM, -56, -9, -24, 8);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 1) {
                self->values[2] = 0;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        PlayerObjectCollision(C_PLATFORM, 24, -9, 56, 8);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 0) {
                self->values[2] = 1;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        break;
        case 3:
        PlayerObjectCollision(C_PLATFORM, -56, 3, -24, 20);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 1) {
                self->values[2] = 0;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        PlayerObjectCollision(C_PLATFORM, 24, -21, 56, -4);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 0) {
                self->values[2] = 1;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        break;
        case 4:
        PlayerObjectCollision(C_PLATFORM, -56, 15, -24, 32);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 1) {
                self->values[2] = 0;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        PlayerObjectCollision(C_PLATFORM, 24, -33, 56, -16);
        if (CheckResult() == 1) {
            pYPos() += 0x10000;
            if (self->values[2] == 0) {
                self->values[2] = 1;
                self->state = 0;
                self->values[4] = 0;
                self->values[5] = 0;
            }
        }
        break;
    }
}

void O_R6_Climber::ObjectDraw()
{
    Entity *self = Self();

    switch (self->frame) {
        case 0:
        DrawSprite_Frame(0);
        DrawSprite_Frame(3);
        DrawSpriteFX_Script(7, FX_FLIP, self->XPos, self->YPos);
        break;
        case 1:
        DrawSprite_Frame(1);
        DrawSprite_Frame(4);
        DrawSpriteFX_Script(6, FX_FLIP, self->XPos, self->YPos);
        break;
        case 2:
        DrawSprite_Frame(2);
        DrawSprite_Frame(5);
        DrawSpriteFX_Script(5, FX_FLIP, self->XPos, self->YPos);
        break;
        case 3:
        DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        DrawSprite_Frame(6);
        DrawSpriteFX_Script(4, FX_FLIP, self->XPos, self->YPos);
        break;
        case 4:
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSprite_Frame(7);
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        break;
    }
    switch (self->values[4]) {
        case 0:
        scriptEng.tempValue[0] = self->values[3];
        scriptEng.tempValue[0] /= 3;
        scriptEng.tempValue[0] += 8;
        self->values[3]++;
        self->values[3] %= 6;
        break;
        case 1:
        scriptEng.tempValue[0] = self->values[3];
        scriptEng.tempValue[0] /= 3;
        scriptEng.tempValue[0] += 8;
        self->values[3]++;
        self->values[3] %= 12;
        break;
        case 2:
        scriptEng.tempValue[0] = self->values[3];
        scriptEng.tempValue[0] /= 3;
        scriptEng.tempValue[0] += 10;
        self->values[3]++;
        self->values[3] %= 6;
        break;
    }
    DrawSprite_Frame(scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
