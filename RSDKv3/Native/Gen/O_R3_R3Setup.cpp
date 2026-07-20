#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_R3Setup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R3Setup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_R3Setup::ObjectStartup()
{
    objectEntityList[29].type = TypeNameID("R3 Setup");
    objectEntityList[29].priority = 1;
    objectEntityList[29].drawOrder = 0;
    SetLayerDeformation(2, 128, 6, 0, 0, 0);
    SetLayerDeformation(1, 64, 4, 0, 0, 0);
    waterLevel = 1472;
    if (objectEntityList[24].propertyValue == 1) {
        GVar("RotatingDrum_Timer") = 1;
    } else {
        GVar("RotatingDrum_Timer") = 0;
    }
}

void O_R3_R3Setup::ObjectMain()
{
    Entity *self = Self();

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
    if (objectEntityList[24].propertyValue != 1) {
        GVar("RotatingDrum_Timer")++;
        GVar("RotatingDrum_Timer") %= 20;
    }
}

void O_R3_R3Setup::ObjectPlayerInteraction()
{
    scriptEng.tempValue[2] = pXPos();
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[4] = scriptEng.tempValue[2];
    scriptEng.tempValue[2] -= 8;
    scriptEng.tempValue[4] += 8;
    scriptEng.tempValue[3] = pYPos();
    scriptEng.tempValue[3] >>= 16;
    if (pYVel() >= 0) {
        scriptEng.tempValue[3] += pCollisionBottom();
        scriptEng.tempValue[3] -= 2;
    } else {
        scriptEng.tempValue[3] += pCollisionTop();
        scriptEng.tempValue[3] += 2;
    }
    scriptEng.tempValue[5] = scriptEng.tempValue[3];
    scriptEng.tempValue[7] = 0;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 6);
    switch (scriptEng.tempValue[0]) {
        case 1:
        scriptEng.tempValue[7] = 1;
        break;
        case 3:
        scriptEng.tempValue[7] = 3;
        scriptEng.tempValue[6] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 1);
        break;
        case 5:
        scriptEng.tempValue[7] = 2;
        break;
    }
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[4], scriptEng.tempValue[5], 6);
    switch (scriptEng.tempValue[0]) {
        case 1:
        scriptEng.tempValue[7] = 1;
        break;
        case 3:
        scriptEng.tempValue[7] = 3;
        scriptEng.tempValue[6] = Get16x16TileInfo_Script(scriptEng.tempValue[4], scriptEng.tempValue[5], 1);
        break;
        case 5:
        scriptEng.tempValue[7] = 2;
        break;
    }
    switch (scriptEng.tempValue[7]) {
        case 1:
        if (pYVel() >= 0) {
            pGravity() = 1;
            PlaySfx(globalSFXCount + 1, 0);
            HapticEffect_Script(11, 0, 0, 0);
            if (pState() == PlayerStateID("Player_State_Fly")) {
                pYVel() = -0x40000;
            } else {
                pYVel() = -0x70000;
            }
            if (pState() == PlayerStateID("Player_State_Hurt")) {
                pState() = PlayerStateID("Player_State_Air");
                pTimer() = 0;
            }
        } else {
            if (pGravity() == 1) {
                pYVel() = 0x40000;
                PlaySfx(globalSFXCount + 1, 0);
            }
        }
        break;
        case 2:
        if (pGravity() == 1) {
            PlaySfx(globalSFXCount + 6, 0);
            HapticEffect_Script(11, 0, 0, 0);
            if (pYVel() >= 0) {
                pYVel() = -0x40000;
            } else {
                pYVel() = 0x40000;
            }
        }
        break;
        case 3:
        if (pGravity() == 1) {
            PlaySfx(globalSFXCount + 1, 0);
            HapticEffect_Script(11, 0, 0, 0);
            if (pYVel() >= 0) {
                if (pState() == PlayerStateID("Player_State_Fly")) {
                    pYVel() = -0x40000;
                } else {
                    pYVel() = -0x70000;
                }
            } else {
                pYVel() = 0x40000;
            }
            if (scriptEng.tempValue[6] == 0) {
                if (pXVel() > 0) {
                    pXVel() = -pXVel();
                    pXVel() *= 5;
                    pXVel() >>= 2;
                    if (pXVel() > -0x20000) {
                        pXVel() = -0x20000;
                    }
                } else {
                    if (pXVel() > -0x20000) {
                        pXVel() = -0x20000;
                    }
                }
            } else {
                if (pXVel() < 0) {
                    pXVel() = -pXVel();
                    pXVel() *= 5;
                    pXVel() >>= 2;
                    if (pXVel() < 0x20000) {
                        pXVel() = 0x20000;
                    }
                } else {
                    if (pXVel() < 0x20000) {
                        pXVel() = 0x20000;
                    }
                }
            }
            pSpeed() = pXVel();
        }
        break;
    }
    scriptEng.tempValue[3] = pYPos();
    scriptEng.tempValue[3] >>= 16;
    scriptEng.tempValue[5] = scriptEng.tempValue[3];
    scriptEng.tempValue[3] -= 6;
    scriptEng.tempValue[5] += 6;
    scriptEng.tempValue[2] = pXPos();
    scriptEng.tempValue[2] >>= 16;
    if (pXVel() > 0) {
        scriptEng.tempValue[2] += 8;
    } else {
        scriptEng.tempValue[2] -= 8;
    }
    scriptEng.tempValue[4] = scriptEng.tempValue[2];
    scriptEng.tempValue[7] = 0;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[2], scriptEng.tempValue[3], 6);
    switch (scriptEng.tempValue[0]) {
        case 3:
        scriptEng.tempValue[7] = 1;
        break;
        case 5:
        scriptEng.tempValue[7] = 2;
        break;
        case 7:
        scriptEng.tempValue[7] = 1;
        break;
    }
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[4], scriptEng.tempValue[5], 6);
    switch (scriptEng.tempValue[0]) {
        case 3:
        scriptEng.tempValue[7] = 1;
        break;
        case 5:
        scriptEng.tempValue[7] = 2;
        break;
        case 7:
        scriptEng.tempValue[7] = 1;
        break;
    }
    switch (scriptEng.tempValue[7]) {
        case 1:
        if (pXVel() > 0) {
            pXVel() = -0x50000;
        } else {
            pXVel() = 0x50000;
        }
        pSpeed() = pXVel();
        PlaySfx(globalSFXCount + 1, 0);
        break;
        case 2:
        if (pXVel() > 0) {
            pXVel() = -0x40000;
        } else {
            pXVel() = 0x40000;
        }
        pSpeed() = pXVel();
        PlaySfx(globalSFXCount + 6, 0);
        HapticEffect_Script(11, 0, 0, 0);
        break;
    }
}

void O_R3_R3Setup::ObjectDraw()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] > 3) {
        stageLayouts[0].deformationOffsetW++;
        stageLayouts[1].deformationOffset++;
        self->values[0] = 0;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
