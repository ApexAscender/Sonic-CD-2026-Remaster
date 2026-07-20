#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_SignPost.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SignPost.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_SignPost::ObjectStartup()
{
    if (playerListPos == 0) {
        LoadSpriteSheet("Global/Items2.gif");
    }
    if (playerListPos == 1) {
        LoadSpriteSheet("Global/Items2_t.gif");
    }
    AddSpriteFrame(-12, -12, 24, 24, 0, 150);
    AddSpriteFrame(-24, -44, 48, 32, 34, 99);
    AddSpriteFrame(-16, -44, 32, 32, 1, 183);
    AddSpriteFrame(-4, -44, 8, 32, 25, 150);
    AddSpriteFrame(-16, -44, 32, 32, 1, 216);
    AddSpriteFrame(-24, -44, 48, 32, 34, 132);
    AddSpriteFrame(-16, -44, 32, 32, 1, 183);
    AddSpriteFrame(-4, -44, 8, 32, 25, 150);
    AddSpriteFrame(-16, -44, 32, 32, 1, 216);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Sign Post")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 3;
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue < 2) {
                scriptEng.tempValue[0] = stageLayouts[0].xsize;
                scriptEng.tempValue[0] -= 2;
                scriptEng.tempValue[1] = stageLayouts[0].xsize;
                scriptEng.tempValue[2] = (objectEntityList[scriptEng.arrayPosition[0]].YPos >> 16);
                scriptEng.tempValue[2] += 64;
                scriptEng.tempValue[2] >>= 7;
                scriptEng.tempValue[3] = stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[2]];
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = scriptEng.tempValue[3];
                scriptEng.tempValue[0]++;
                scriptEng.tempValue[1]++;
                scriptEng.tempValue[3] = stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[2]];
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = scriptEng.tempValue[3];
                if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 1) {
                    scriptEng.tempValue[0]--;
                    scriptEng.tempValue[1]--;
                    scriptEng.tempValue[2]--;
                    scriptEng.tempValue[3] = stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[2]];
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = scriptEng.tempValue[3];
                    scriptEng.tempValue[0]++;
                    scriptEng.tempValue[1]++;
                    scriptEng.tempValue[3] = stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[2]];
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = scriptEng.tempValue[3];
                }
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_SignPost::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->frame = 1;
        scriptEng.tempValue[0] = self->YPos;
        scriptEng.tempValue[0] += 0x600000;
        if (pYPos() < scriptEng.tempValue[0]) {
            newXBoundary1 = self->XPos;
            newXBoundary1 >>= 16;
            newXBoundary1 -= SCREEN_CENTERX;
            newXBoundary1 -= SCREEN_CENTERX;
            newXBoundary2 = self->XPos;
            newXBoundary2 >>= 16;
            newXBoundary2 += SCREEN_CENTERX;
            if (pXPos() > self->XPos) {
                newXBoundary1 = self->XPos;
                newXBoundary1 >>= 16;
                newXBoundary1 -= SCREEN_CENTERX;
                timeEnabled = 0;
                self->state = 1;
                self->values[0] = 8;
                PlaySfx(15, 0);
                HapticEffect_Script(50, 0, 0, 0);
            }
        }
        break;
        case 1:
        masterVolume--;
        self->values[1]++;
        if (self->values[1] == 2) {
            self->values[1] = 0;
            self->frame++;
            if (self->frame == 5) {
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x1C0000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                self->values[0]--;
                if (self->values[0] == 0) {
                    if (objectEntityList[0].type == TypeNameID("Blank Object")) {
                        self->state = 4;
                        if (self->propertyValue < 3) {
                            PlayMusic(1);
                        } else {
                            if (GetObjectOutOfBounds(objectLoop) == 0) {
                                PlayMusic(1);
                            }
                        }
                        objectEntityList[30].type = TypeNameID("ActFinish");
                        objectEntityList[30].drawOrder = 6;
                        objectEntityList[30].priority = 1;
                    } else {
                        pControlMode() = -1;
                        pUp() = 0;
                        pDown() = 0;
                        pLeft() = 0;
                        pJumpPress() = 0;
                        pJumpHold() = 0;
                        self->state = 2;
                    }
                }
            }
            if (self->frame == 9) {
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x1C0000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                self->frame = 1;
            }
        }
        scriptEng.tempValue[0] = 40;
        scriptEng.tempValue[0] += SCREEN_CENTERX;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += self->XPos;
        if (pXPos() > scriptEng.tempValue[0]) {
            pXPos() = scriptEng.tempValue[0];
            pSpeed() = 0;
            pXVel() = 0;
        }
        break;
        case 2:
        if (objectEntityList[0].type == TypeNameID("Blank Object")) {
            self->state = 4;
            if (self->propertyValue < 3) {
                PlayMusic(1);
            } else {
                if (GetObjectOutOfBounds(objectLoop) == 0) {
                    PlayMusic(1);
                }
            }
            objectEntityList[30].type = TypeNameID("ActFinish");
            objectEntityList[30].drawOrder = 6;
            objectEntityList[30].priority = 1;
        }
        if (pControlMode() == -1) {
            pRight() = 1;
        }
        scriptEng.tempValue[0] = SCREEN_CENTERX;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += self->XPos;
        if (pXPos() > scriptEng.tempValue[0]) {
            if (self->propertyValue < 3) {
                PlayMusic(1);
            } else {
                if (GetObjectOutOfBounds(objectLoop) == 0) {
                    PlayMusic(1);
                }
            }
            self->state = 3;
            objectEntityList[30].type = TypeNameID("ActFinish");
            objectEntityList[30].drawOrder = 6;
            objectEntityList[30].priority = 1;
        } else {
        }
        break;
        case 3:
        if (pControlMode() == -1) {
            pRight() = 1;
        }
        scriptEng.tempValue[0] = 40;
        scriptEng.tempValue[0] += SCREEN_CENTERX;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[0] += self->XPos;
        if (pXPos() > scriptEng.tempValue[0]) {
            pXPos() = scriptEng.tempValue[0];
            pSpeed() = 0;
            pXVel() = 0;
        }
        break;
        case 4:
        break;
    }
}

void O_SignPost::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(0);
    DrawSprite_Frame(self->frame);
}

#endif // RETRO_USE_NATIVE_OBJECTS
