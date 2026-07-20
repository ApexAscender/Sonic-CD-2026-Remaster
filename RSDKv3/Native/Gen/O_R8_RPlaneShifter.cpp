#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_RPlaneShifter.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from RPlaneShifter.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_RPlaneShifter::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-40, -8, 80, 16, 1, 200);
    AddSpriteFrame(-40, -8, 80, 16, 1, 217);
    AddSpriteFrame(-40, -184, 80, 16, 1, 200);
    AddSpriteFrame(-40, -184, 80, 16, 1, 217);
    AddSpriteFrame(-4, -40, 8, 32, 100, 35);
    AddSpriteFrame(-4, -72, 8, 32, 100, 35);
    AddSpriteFrame(-4, -104, 8, 32, 100, 35);
    AddSpriteFrame(-4, -136, 8, 32, 100, 35);
    AddSpriteFrame(-4, -168, 8, 32, 100, 35);
}

void O_R8_RPlaneShifter::ObjectMain()
{
    Entity *self = Self();

    if (pObjectInteractions() == 1) {
        if (self->propertyValue == 0) {
            switch (self->state) {
                case 1:
                if (self->values[1] < 256) {
                    self->values[1] += 8;
                } else {
                    self->state = 0;
                    pState() = PlayerStateID("Player_State_Ground");
                    pFrame() = 0;
                    PlrEntity()->drawOrder = 2;
                    pCollisionPlane() = 1;
                }
                scriptEng.tempValue[0] = self->values[1];
                scriptEng.tempValue[0] >>= 6;
                switch (scriptEng.tempValue[0]) {
                    case 0:
                    pFrame() = 1;
                    break;
                    case 1:
                    pFrame() = 2;
                    break;
                    case 2:
                    pFrame() = 3;
                    break;
                    case 3:
                    pFrame() = 0;
                    pDirection() = 1;
                    break;
                }
                self->animationTimer++;
                self->animationTimer %= 6;
                break;
                case 2:
                if (self->values[1] > 0) {
                    self->values[1] -= 8;
                } else {
                    self->state = 0;
                    pState() = PlayerStateID("Player_State_Ground");
                    pFrame() = 0;
                    PlrEntity()->drawOrder = 4;
                    pCollisionPlane() = 0;
                }
                scriptEng.tempValue[0] = self->values[1];
                scriptEng.tempValue[0] >>= 6;
                switch (scriptEng.tempValue[0]) {
                    case 0:
                    pFrame() = 0;
                    pDirection() = 1;
                    break;
                    case 1:
                    pFrame() = 4;
                    break;
                    case 2:
                    pFrame() = 0;
                    break;
                    case 3:
                    pFrame() = 1;
                    break;
                }
                self->animationTimer++;
                self->animationTimer %= 6;
                break;
                case 3:
                if (self->values[1] > 256) {
                    self->values[1] -= 8;
                } else {
                    self->state = 0;
                    pState() = PlayerStateID("Player_State_Ground");
                    pFrame() = 0;
                    PlrEntity()->drawOrder = 2;
                    pCollisionPlane() = 1;
                }
                scriptEng.tempValue[0] = 512;
                scriptEng.tempValue[0] -= self->values[1];
                scriptEng.tempValue[0] >>= 6;
                switch (scriptEng.tempValue[0]) {
                    case 0:
                    pFrame() = 1;
                    break;
                    case 1:
                    pFrame() = 2;
                    break;
                    case 2:
                    pFrame() = 3;
                    break;
                    case 3:
                    pFrame() = 0;
                    pDirection() = 0;
                    break;
                }
                self->animationTimer++;
                self->animationTimer %= 6;
                break;
                case 4:
                if (self->values[1] < 512) {
                    self->values[1] += 8;
                } else {
                    self->values[1] = 0;
                    self->state = 0;
                    pState() = PlayerStateID("Player_State_Ground");
                    pFrame() = 0;
                    PlrEntity()->drawOrder = 4;
                    pCollisionPlane() = 0;
                }
                scriptEng.tempValue[0] = 512;
                scriptEng.tempValue[0] -= self->values[1];
                scriptEng.tempValue[0] >>= 6;
                switch (scriptEng.tempValue[0]) {
                    case 0:
                    pFrame() = 0;
                    pDirection() = 0;
                    break;
                    case 1:
                    pFrame() = 4;
                    break;
                    case 2:
                    pFrame() = 0;
                    break;
                    case 3:
                    pFrame() = 1;
                    break;
                }
                self->animationTimer++;
                self->animationTimer %= 6;
                break;
            }
            objectEntityList[objectLoop + 1].XPos = Sin512(self->values[1]);
            objectEntityList[objectLoop + 1].XPos *= 0xC00;
            objectEntityList[objectLoop + 1].XPos += self->XPos;
            objectEntityList[objectLoop + 1].YPos = self->YPos;
            if (self->values[1] > 128) {
                if (self->values[1] < 384) {
                    objectEntityList[objectLoop + 1].drawOrder = 1;
                } else {
                    objectEntityList[objectLoop + 1].drawOrder = 4;
                }
            } else {
                objectEntityList[objectLoop + 1].drawOrder = 4;
            }
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] += 170;
            scriptEng.tempValue[0] &= 511;
            objectEntityList[objectLoop + 2].XPos = Sin512(scriptEng.tempValue[0]);
            objectEntityList[objectLoop + 2].XPos *= 0xC00;
            objectEntityList[objectLoop + 2].XPos += self->XPos;
            objectEntityList[objectLoop + 2].YPos = self->YPos;
            if (scriptEng.tempValue[0] > 128) {
                if (scriptEng.tempValue[0] < 384) {
                    objectEntityList[objectLoop + 2].drawOrder = 1;
                } else {
                    objectEntityList[objectLoop + 2].drawOrder = 4;
                }
            } else {
                objectEntityList[objectLoop + 2].drawOrder = 4;
            }
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] += 341;
            scriptEng.tempValue[0] &= 511;
            objectEntityList[objectLoop + 3].XPos = Sin512(scriptEng.tempValue[0]);
            objectEntityList[objectLoop + 3].XPos *= 0xC00;
            objectEntityList[objectLoop + 3].XPos += self->XPos;
            objectEntityList[objectLoop + 3].YPos = self->YPos;
            if (scriptEng.tempValue[0] > 128) {
                if (scriptEng.tempValue[0] < 384) {
                    objectEntityList[objectLoop + 3].drawOrder = 1;
                } else {
                    objectEntityList[objectLoop + 3].drawOrder = 4;
                }
            } else {
                objectEntityList[objectLoop + 3].drawOrder = 4;
            }
        }
    }
}

void O_R8_RPlaneShifter::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        PlayerObjectCollision(C_PLATFORM, -40, -8, 40, 24);
        scriptEng.tempValue[1] = CheckResult();
        PlayerObjectCollision(C_BOX, -40, -184, 40, -168);
        PlayerObjectCollision(C_TOUCH, -4, -48, 4, 8);
        if (CheckResult() == 1) {
            if (self->values[2] == 0) {
                if (scriptEng.tempValue[1] == 1) {
                    self->values[2] = 1;
                    pState() = PlayerStateID("Player_State_Static");
                    pAnimation() = GVar("ANI_STOPPED");
                    pXPos() = self->XPos;
                    pSpeed() = 0;
                    pXVel() = 0;
                    pYVel() = 0;
                    pTrackScroll() = 0;
                    if (pDirection() == 0) {
                        if (pCollisionPlane() == 0) {
                            self->state = 1;
                            self->values[1] = 0;
                        } else {
                            self->state = 2;
                            self->values[1] = 256;
                        }
                    } else {
                        if (pCollisionPlane() == 0) {
                            self->state = 3;
                            self->values[1] = 512;
                        } else {
                            self->state = 4;
                            self->values[1] = 256;
                        }
                    }
                }
            }
        } else {
            self->values[2] = 0;
        }
    }
}

void O_R8_RPlaneShifter::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] /= 3;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 2;
        DrawSprite_Frame(scriptEng.tempValue[0]);
    } else {
        DrawSprite_Frame(4);
        DrawSprite_Frame(5);
        DrawSprite_Frame(6);
        DrawSprite_Frame(7);
        DrawSprite_Frame(8);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
