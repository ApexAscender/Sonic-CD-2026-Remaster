#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_Seesaw.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Seesaw.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_Seesaw::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects.gif");
    AddSpriteFrame(-40, -56, 40, 112, 66, 1);
    AddSpriteFrame(-40, -40, 40, 96, 107, 1);
    AddSpriteFrame(-24, -24, 24, 80, 123, 17);
    AddSpriteFrame(-40, -32, 40, 88, 148, 1);
    AddSpriteFrame(-40, -40, 40, 96, 189, 1);
    AddSpriteFrame(-40, -56, 80, 24, 175, 98);
    AddSpriteFrame(-40, -40, 80, 24, 175, 98);
    AddSpriteFrame(-40, -24, 80, 24, 175, 98);
    AddSpriteFrame(-40, 0, 80, 24, 175, 98);
    AddSpriteFrame(-40, 16, 80, 24, 175, 98);
    AddSpriteFrame(-16, -16, 32, 32, 1, 213);
    AddSpriteFrame(-24, -24, 48, 48, 1, 164);
    AddSpriteFrame(-28, -32, 56, 64, 1, 99);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Seesaw")) {
            objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = 10;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_Seesaw::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        switch (self->values[5]) {
            case 0:
            if (self->values[0] < 2) {
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->values[5]++;
                self->values[2] = 0x100000;
            }
            break;
            case 1:
            if (self->values[0] < 6) {
                self->values[0]++;
                self->frame = 1;
            } else {
                self->values[0] = 0;
                self->values[5]++;
                self->values[2] = 0x100000;
            }
            break;
            case 2:
            if (self->values[0] < 6) {
                self->values[0]++;
                self->frame = 2;
            } else {
                self->values[0] = 0;
                self->values[5]++;
                self->values[2] = 0x180000;
            }
            break;
            case 3:
            if (self->values[0] < 6) {
                self->values[0]++;
                self->frame = 3;
            } else {
                self->values[0] = 0;
                self->values[5]++;
                self->values[2] = 0x100000;
            }
            break;
            case 4:
            if (self->values[0] < 11) {
                self->values[0]++;
                self->frame = 4;
            } else {
                self->values[0] = 0;
                self->values[5]++;
            }
            break;
            case 5:
            if (self->values[6] == 0) {
                self->state = 2;
                self->values[5] = 0;
            }
            break;
        }
        self->values[3] += self->values[1];
        self->values[1] += 0x4000;
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] += 0x40000;
        if (self->values[3] > scriptEng.tempValue[0]) {
            self->values[3] = scriptEng.tempValue[0];
            self->frame = 4;
            self->state = 3;
        }
        if (self->values[1] > 0) {
            self->values[4] = 12;
        } else {
            if (self->values[1] > -0x90000) {
                self->values[4] = 11;
            }
        }
        break;
        case 2:
        switch (self->values[5]) {
            case 0:
            if (self->values[0] < 11) {
                self->frame = 3;
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->values[5]++;
            }
            break;
            case 1:
            if (self->values[0] < 11) {
                self->frame = 2;
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->values[5]++;
            }
            break;
            case 2:
            if (self->values[0] < 11) {
                self->frame = 1;
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->values[5]++;
            }
            break;
            case 3:
            if (self->values[0] < 11) {
                self->frame = 2;
                self->values[0]++;
            } else {
                self->values[0] = 0;
                self->values[5] = 0;
            }
            break;
        }
        self->values[3] += self->values[1];
        self->values[1] += 0x4000;
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] += 0x40000;
        if (self->values[3] > scriptEng.tempValue[0]) {
            self->values[3] = scriptEng.tempValue[0];
            self->frame = 4;
            self->state = 3;
        }
        if (self->values[1] > 0) {
            self->values[4] = 12;
        } else {
            if (self->values[1] > -0x90000) {
                self->values[4] = 11;
            }
        }
        if (self->values[6] == 1) {
            self->state = 1;
            self->values[0] = 0;
            self->values[5] = self->frame;
        }
        break;
    }
    self->values[6] = 0;
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 0;
        self->values[3] = self->YPos;
        self->values[4] = 10;
        self->frame = 0;
        self->values[0] = 0;
        self->values[5] = 0;
        self->values[2] = 0;
        self->priority = 0;
    }
}

void O_R8_Seesaw::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_PLATFORM, -40, -56, 40, -36);
        if (CheckResult() == 1) {
            self->state = 1;
            self->priority = 1;
            self->values[1] = -0xC0000;
        }
    } else {
        switch (self->frame) {
            case 0:
            PlayerObjectCollision(C_PLATFORM, -40, -56, 40, -36);
            break;
            case 1:
            PlayerObjectCollision(C_PLATFORM, -40, -40, 40, -20);
            break;
            case 2:
            PlayerObjectCollision(C_PLATFORM, -40, -24, 40, -4);
            break;
            case 3:
            PlayerObjectCollision(C_PLATFORM, -40, 0, 40, 20);
            break;
            case 4:
            PlayerObjectCollision(C_PLATFORM, -40, 16, 40, 36);
            break;
        }
        if (self->state < 3) {
            if (CheckResult() == 1) {
                self->values[6] = 1;
                if (self->values[2] > 0) {
                    pYPos() += self->values[2];
                    self->values[2] = 0;
                    self->frame++;
                }
            }
        }
        if (self->values[4] > 11) {
            scriptEng.tempValue[0] = self->YPos;
            self->YPos = self->values[3];
            PlayerObjectCollision(C_TOUCH, -24, -24, 24, 24);
            if (CheckResult() == 1) {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
            self->YPos = scriptEng.tempValue[0];
        }
    }
}

void O_R8_Seesaw::ObjectDraw()
{
    Entity *self = Self();

    if (self->drawOrder == 3) {
        if (self->values[4] < 11) {
            DrawSprite_FrameXY(self->values[4], self->XPos, self->values[3]);
            DrawSprite_Frame(self->frame);
            DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
        } else {
            DrawSprite_Frame(self->frame);
            DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
            DrawSprite_FrameXY(self->values[4], self->XPos, self->values[3]);
        }
        drawListEntries[4].entityRefs[drawListEntries[4].listSize] = objectLoop;
        drawListEntries[4].listSize++;
        self->drawOrder = 4;
    } else {
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] += 5;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->drawOrder = 3;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
