#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_Bumper.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Bumper.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_Bumper::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects3.gif");
    AddSpriteFrame(-16, -16, 32, 32, 100, 100);
    AddSpriteFrame(-12, -12, 24, 24, 1, 228);
    AddSpriteFrame(-20, -20, 40, 40, 1, 187);
    AddSpriteFrame(-12, -12, 24, 24, 1, 228);
    AddSpriteFrame(-20, -20, 40, 40, 1, 187);
    AddSpriteFrame(-20, -20, 40, 40, 1, 187);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Bumper")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[5] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_Bumper::ObjectMain()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 1:
        if (self->values[3] == 0) {
            if (self->values[2] < 0x300000) {
                self->values[2] += 0x10000;
            } else {
                self->values[3] = 1;
            }
        } else {
            if (self->values[2] > -0x300000) {
                self->values[2] -= 0x10000;
            } else {
                self->values[3] = 0;
            }
        }
        self->XPos = self->values[4];
        self->XPos += self->values[2];
        break;
        case 2:
        if (self->values[3] == 0) {
            if (self->values[2] < 0x300000) {
                self->values[2] += 0x10000;
            } else {
                self->values[3] = 1;
            }
        } else {
            if (self->values[2] > -0x300000) {
                self->values[2] -= 0x10000;
            } else {
                self->values[3] = 0;
            }
        }
        self->XPos = self->values[4];
        self->XPos += self->values[2];
        break;
        case 3:
        if (self->values[3] == 0) {
            if (self->values[2] < 0x300000) {
                self->values[2] += 0x10000;
            } else {
                self->values[3] = 1;
            }
        } else {
            if (self->values[2] > -0x300000) {
                self->values[2] -= 0x10000;
            } else {
                self->values[3] = 0;
            }
        }
        self->YPos = self->values[5];
        self->YPos += self->values[2];
        break;
        case 4:
        if (self->values[3] == 0) {
            if (self->values[2] < 0x300000) {
                self->values[2] += 0x10000;
            } else {
                self->values[3] = 1;
            }
        } else {
            if (self->values[2] > -0x300000) {
                self->values[2] -= 0x10000;
            } else {
                self->values[3] = 0;
            }
        }
        self->YPos = self->values[5];
        self->YPos -= self->values[2];
        break;
    }
    if (self->state > 0) {
        self->frame = self->values[0];
        self->frame /= 5;
        self->frame++;
        self->values[0]++;
        if (self->values[0] > 22) {
            self->values[0] = 0;
            self->state = 0;
            self->frame = 0;
        }
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->values[1] = 0;
        self->priority = 0;
    }
}

void O_R8_Bumper::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pAnimation() != GVar("ANI_HURT")) {
        PlayerObjectCollision(C_TOUCH, -14, -14, 14, 14);
        if (CheckResult() == 1) {
            if (self->state == 0) {
                PlaySfx(globalSFXCount + 3, 0);
                if (self->values[1] < 5) {
                    CreateTempObject(TypeNameID("Object Score"), 0, self->XPos, self->YPos);
                    GVar("Player.Score") += 100;
                    self->values[1]++;
                }
            }
            if (self->values[0] > 5) {
                PlaySfx(globalSFXCount + 3, 0);
                HapticEffect_Script(9, 0, 0, 0);
            }
            self->state = 1;
            self->priority = 1;
            scriptEng.tempValue[0] = pXPos();
            scriptEng.tempValue[0] -= self->XPos;
            scriptEng.tempValue[1] = pYPos();
            scriptEng.tempValue[1] -= self->YPos;
            scriptEng.tempValue[2] = ArcTanLookup(scriptEng.tempValue[0], scriptEng.tempValue[1]);
            scriptEng.tempValue[0] = Cos256(scriptEng.tempValue[2]);
            scriptEng.tempValue[1] = Sin256(scriptEng.tempValue[2]);
            if (pState() == PlayerStateID("Player_State_Fly")) {
                scriptEng.tempValue[0] <<= 10;
                scriptEng.tempValue[1] <<= 10;
            } else {
                scriptEng.tempValue[0] *= 0x700;
                scriptEng.tempValue[1] *= 0x700;
                pTimer() = 0;
            }
            pXVel() = scriptEng.tempValue[0];
            pYVel() = scriptEng.tempValue[1];
            pSpeed() = pXVel();
            pGravity() = 1;
        }
    }
}

void O_R8_Bumper::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
