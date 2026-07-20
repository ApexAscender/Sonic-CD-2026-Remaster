#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BataPyon.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BataPyon.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BataPyon::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-16, -18, 32, 40, 34, 134);
    AddSpriteFrame(-16, -18, 32, 56, 67, 167);
    AddSpriteFrame(-16, -18, 32, 40, 34, 175);
    AddSpriteFrame(-16, -18, 32, 56, 100, 167);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Bata Pyon")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = -0xA000;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0x80000;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_BataPyon::ObjectMain()
{
    Entity *self = Self();

    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->state = 7;
        self->direction = 0;
        self->XPos = self->values[3];
        self->YPos = self->values[4];
        self->values[1] = -0xA000;
        self->values[2] = 0x80000;
        self->values[5] = 0;
    }
    switch (self->state) {
        case 0:
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        self->values[2] += 0x2000;
        ObjectTileCollision_Script(3, 0, -18, 0);
        if (CheckResult() == 1) {
            self->values[2] = 0;
        }
        if (self->values[2] > 0) {
            ObjectTileCollision_Script(0, 0, 20, 0);
            if (CheckResult() == 1) {
                if (self->propertyValue == 0) {
                    self->state = 1;
                    self->priority = 1;
                    self->values[5]++;
                    if (self->values[5] == 8) {
                        self->values[5] = 0;
                        self->direction++;
                        self->direction &= 1;
                        self->values[1] = -self->values[1];
                    }
                } else {
                    self->state = 2;
                    self->priority = 1;
                    self->values[5]++;
                    if (self->values[5] == 4) {
                        self->values[5] = 0;
                        self->direction++;
                        self->direction &= 1;
                        self->values[1] = -self->values[1];
                    }
                }
            }
        }
        if (self->values[1] > 0) {
            ObjectTileCollision_Script(1, 16, 0, 0);
            if (CheckResult() == 1) {
                self->values[5] = 0;
                self->direction = 0;
                self->values[1] = -self->values[1];
            }
        } else {
            ObjectTileCollision_Script(2, -16, 0, 0);
            if (CheckResult() == 1) {
                self->values[5] = 0;
                self->direction = 1;
                self->values[1] = -self->values[1];
            }
        }
        self->frame = self->propertyValue;
        self->frame <<= 1;
        if (self->values[2] < 0) {
            self->frame++;
        }
        break;
        case 1:
        self->XPos += self->values[1];
        self->YPos -= 0x120000;
        self->values[2] = -0x60000;
        self->state = 0;
        self->frame = self->propertyValue;
        self->frame <<= 1;
        if (self->values[2] < 0) {
            self->frame++;
        }
        break;
        case 2:
        if (self->values[0] < 3) {
            self->values[0]++;
        } else {
            self->state++;
            self->frame = 3;
            self->YPos -= 0x120000;
        }
        break;
        case 3:
        if (self->values[0] < 6) {
            self->values[0]++;
        } else {
            self->state++;
            self->frame = 2;
            self->YPos += 0x120000;
        }
        break;
        case 4:
        if (self->values[0] < 10) {
            self->values[0]++;
        } else {
            self->state++;
            self->frame = 3;
            self->YPos -= 0x120000;
        }
        break;
        case 5:
        if (self->values[0] < 15) {
            self->values[0]++;
        } else {
            self->state++;
            self->frame = 2;
            self->YPos += 0x120000;
        }
        break;
        case 6:
        if (self->values[0] < 20) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->frame = 3;
            self->YPos -= 0x120000;
            self->values[2] = -0x50000;
            self->state = 0;
        }
        break;
        case 7:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        }
        break;
    }
    CallScriptFunctionNamed("StageSetup_CheckGoodFuture", scriptSub);
}

void O_R6_BataPyon::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 7) {
        PlayerObjectCollision(C_TOUCH, -14, -12, 14, 12);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_BadnikBreak", scriptSub);
        }
    }
}

void O_R6_BataPyon::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 7) {
        DrawSpriteFX_Script(self->frame, FX_FLIP, self->XPos, self->YPos);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
