#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_R6DSetup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R6DSetup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_R6DSetup::ObjectStartup()
{
    objectEntityList[19].type = TypeNameID("R6 Setup");
    objectEntityList[19].priority = 1;
    objectEntityList[19].drawOrder = 2;
    scriptEng.tempValue[0] = 1;
    while (scriptEng.tempValue[0] < 3) {
        RotatePalette(161, 163, 0);
        CopyPalette(0, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
    }
    RotatePalette(161, 163, 0);
}

void O_R6_R6DSetup::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (self->values[0] < 240) {
            self->values[0]++;
        } else {
            PlaySfx(globalSFXCount + 1, 0);
            self->values[0] = 0;
            self->state = 1;
        }
        break;
        case 1:
        if (self->values[0] < 90) {
            self->values[0]++;
            self->frame++;
            self->frame &= 1;
        } else {
            self->values[0] = 0;
            self->frame = 2;
            self->state = 2;
        }
        break;
        case 2:
        if (self->values[0] < 120) {
            self->values[0]++;
            self->frame++;
            if (self->frame == 9) {
                self->frame = 2;
            }
        } else {
            self->values[0] = 0;
            self->frame = 0;
            self->state = 0;
            self->direction++;
            self->direction %= 3;
        }
        break;
    }
    switch (self->values[3]) {
        case 0:
        if (self->values[2] < 15) {
            self->values[2]++;
        } else {
            Copy16x16Tile(646, 841);
            Copy16x16Tile(809, 841);
            self->values[2] = 0;
            self->values[3]++;
        }
        break;
        case 1:
        if (self->values[2] < 4) {
            self->values[2]++;
        } else {
            Copy16x16Tile(646, 842);
            Copy16x16Tile(809, 842);
            self->values[2] = 0;
            self->values[3]++;
        }
        break;
        case 2:
        if (self->values[2] < 9) {
            self->values[2]++;
        } else {
            Copy16x16Tile(646, 843);
            Copy16x16Tile(809, 843);
            self->values[2] = 0;
            self->values[3]++;
        }
        break;
        case 3:
        if (self->values[2] < 4) {
            self->values[2]++;
        } else {
            Copy16x16Tile(646, 840);
            Copy16x16Tile(809, 840);
            self->values[2] = 0;
            self->values[3] = 0;
        }
        break;
    }
    scriptEng.tempValue[0] = self->values[4];
    scriptEng.tempValue[0] &= 1;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] >>= 1;
        scriptEng.tempValue[0] += 844;
        Copy16x16Tile(647, scriptEng.tempValue[0]);
    }
    self->values[4]++;
    self->values[4] %= 24;
    scriptEng.tempValue[0] = self->values[5];
    scriptEng.tempValue[0] %= 5;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[5];
        scriptEng.tempValue[0] /= 5;
        scriptEng.tempValue[0] += 856;
        Copy16x16Tile(648, scriptEng.tempValue[0]);
        scriptEng.tempValue[0] += 3;
        Copy16x16Tile(649, scriptEng.tempValue[0]);
    }
    self->values[5]++;
    self->values[5] %= 15;
    scriptEng.tempValue[0] = self->values[6];
    scriptEng.tempValue[0] &= 1;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[7];
        scriptEng.tempValue[0] += 862;
        self->values[7]++;
        self->values[7] %= 6;
        Copy16x16Tile(543, scriptEng.tempValue[0]);
    }
    self->values[6]++;
    self->values[6] &= 511;
    self->scale = 1;
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] >>= 1;
    SetActivePalette(scriptEng.tempValue[0], 0, 240);
    self->values[1]++;
    self->values[1] %= 6;
}

void O_R6_R6DSetup::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[2] = pXPos();
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[2] += pCollisionRight();
    scriptEng.tempValue[3] = pYPos();
    scriptEng.tempValue[3] >>= 16;
    scriptEng.tempValue[3] += pCollisionBottom();
    scriptEng.tempValue[3] += 2;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    scriptEng.tempValue[2] = pXPos();
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[2] += pCollisionLeft();
    scriptEng.tempValue[1] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    scriptEng.tempValue[0] |= scriptEng.tempValue[1];
    if (scriptEng.tempValue[0] == 1) {
        if (self->scale == 1) {
            if (pYVel() > -1) {
                pAnimation() = GVar("ANI_JUMPING");
                pGravity() = 1;
                pTimer() = 0;
                pYVel() = -0x160000;
                pState() = PlayerStateID("Player_State_Air");
                PlaySfx(globalSFXCount + 0, 0);
                HapticEffect_Script(60, 0, 0, 0);
            }
        }
    }
    scriptEng.tempValue[2] -= pCollisionLeft();
    scriptEng.tempValue[3] -= pCollisionBottom();
    scriptEng.tempValue[3] -= 2;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    switch (scriptEng.tempValue[0]) {
        case 2:
        if (PlayerValue(4) == 0) {
            pState() = PlayerStateID("Player_State_GotHit");
            if (pDirection() == 1) {
                pSpeed() = 0x20000;
            } else {
                pSpeed() = -0x20000;
            }
        }
        break;
        case 5:
        if (self->state == 2) {
            if (PlayerValue(4) == 0) {
                pState() = PlayerStateID("Player_State_GotHit");
                if (pDirection() == 1) {
                    pSpeed() = 0x20000;
                } else {
                    pSpeed() = -0x20000;
                }
            }
        }
        break;
        case 6:
        if (self->state == 2) {
            if (self->direction == 0) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
        case 7:
        if (self->state == 2) {
            if (self->direction == 1) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
        case 8:
        if (self->state == 2) {
            if (self->direction == 2) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
    }
    scriptEng.tempValue[3] -= 4;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    switch (scriptEng.tempValue[0]) {
        case 2:
        if (PlayerValue(4) == 0) {
            pState() = PlayerStateID("Player_State_GotHit");
            if (pDirection() == 1) {
                pSpeed() = 0x20000;
            } else {
                pSpeed() = -0x20000;
            }
        }
        break;
        case 5:
        if (self->state == 2) {
            if (PlayerValue(4) == 0) {
                pState() = PlayerStateID("Player_State_GotHit");
                if (pDirection() == 1) {
                    pSpeed() = 0x20000;
                } else {
                    pSpeed() = -0x20000;
                }
            }
        }
        break;
        case 6:
        if (self->state == 2) {
            if (self->direction == 0) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
        case 7:
        if (self->state == 2) {
            if (self->direction == 1) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
        case 8:
        if (self->state == 2) {
            if (self->direction == 2) {
                if (PlayerValue(4) == 0) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pDirection() == 1) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
        break;
    }
    scriptEng.tempValue[3] += 4;
    scriptEng.tempValue[3] += pCollisionTop();
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 8);
    if (scriptEng.tempValue[0] == 3) {
        scriptEng.tempValue[4] = scriptEng.tempValue[3];
        scriptEng.tempValue[4] &= 15;
        if (scriptEng.tempValue[4] < 8) {
            if (pState() != PlayerStateID("Player_State_HangBar")) {
                pState() = PlayerStateID("Player_State_HangBar");
                pYVel() = 0;
                pAnimation() = GVar("ANI_HANGING");
                scriptEng.tempValue[3] &= 0x7FF0;
                scriptEng.tempValue[3] += 4;
                scriptEng.tempValue[3] -= pCollisionTop();
                pYPos() = (scriptEng.tempValue[3]) << 16;
                PlaySfx(globalSFXCount + 2, 0);
                cameraAdjustY = 0;
            }
        }
    }
}

void O_R6_R6DSetup::ObjectDraw()
{
    Entity *self = Self();

    if (self->state == 2) {
        switch (self->frame) {
            case 2:
            DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 128, 0, 64, 64);
            break;
            case 3:
            DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 128, 0, 64, 32);
            break;
            case 4:
            DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 255, 128, 255, 32);
            break;
            case 5:
            DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 128, 0, 64, 64);
            break;
            case 6:
            DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 128, 0, 64, 32);
            break;
            case 7:
            DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 255, 128, 255, 32);
            break;
            case 8:
            DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 128, 0, 64, 32);
            break;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
