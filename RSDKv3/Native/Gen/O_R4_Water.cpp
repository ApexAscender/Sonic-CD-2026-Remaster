#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_Water.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Water.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_Water::ObjectStartup()
{
    Entity *self = Self();

    LoadSpriteSheet("R4/Objects.gif");
    GVar("Player.AirTimer") = 0;
    scriptEng.tempValue[7] = -1;
    switch (actID) {
        case 1:
        switch (objectEntityList[24].propertyValue) {
            case 0:
            if (pXPos() > 0x5E00000) {
                scriptEng.tempValue[7] = 0x2640000;
            }
            break;
            case 2:
            case 3:
            if (pXPos() > 0x9100000) {
                scriptEng.tempValue[7] = 0x1100000;
            }
            break;
        }
        break;
        case 2:
        switch (objectEntityList[24].propertyValue) {
            case 0:
            if (pXPos() > 0x4B00000) {
                scriptEng.tempValue[7] = 0x5340000;
            }
            if (pXPos() > 0xC200000) {
                scriptEng.tempValue[7] = 0x7800000;
            }
            if (pXPos() > 0x13300000) {
                scriptEng.tempValue[7] = 0x5000000;
            }
            break;
            case 2:
            case 3:
            if (pXPos() > 0x4B00000) {
                scriptEng.tempValue[7] = 0x5100000;
            }
            if (pXPos() > 0x4100000) {
                scriptEng.tempValue[7] = 0x3900000;
            }
            if (pXPos() > 0x4100000) {
                scriptEng.tempValue[7] = 0x3900000;
            }
            break;
        }
        break;
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 5;
            objectEntityList[scriptEng.arrayPosition[0]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[0]].alpha = 160;
            if (scriptEng.tempValue[7] == -1) {
                GVar("Stage.NewWaterLevel") = objectEntityList[scriptEng.arrayPosition[0]].YPos;
            } else {
                GVar("Stage.NewWaterLevel") = scriptEng.tempValue[7];
                objectEntityList[scriptEng.arrayPosition[0]].YPos = scriptEng.tempValue[7];
            }
            if (pYPos() > GVar("Stage.NewWaterLevel")) {
                pYVel() >>= 2;
                pXVel() >>= 1;
                pSpeed() >>= 1;
                pTopSpeed() >>= 1;
                pAccel() >>= 1;
                pDecel() >>= 1;
                pAirAccel() >>= 1;
                pAirDecel() >>= 1;
                pGravityStrength() = 0x1000;
                pJumpStrength() = 0x38000;
                self->values[1] = 52;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
    AddSpriteFrame(0, -8, 128, 16, 1, 1);
    AddSpriteFrame(0, -8, 128, 16, 1, 18);
    AddSpriteFrame(0, -8, 128, 16, 1, 35);
    AddSpriteFrame(0, -8, 128, 16, 1, 52);
}

void O_R4_Water::ObjectMain()
{
    Entity *self = Self();

    GVar("Player.WaterStream") = 0;
    if (self->YPos < GVar("Stage.NewWaterLevel")) {
        self->YPos += 0x10000;
    }
    if (self->YPos > GVar("Stage.NewWaterLevel")) {
        self->YPos -= 0x10000;
    }
    scriptEng.tempValue[0] = GVar("Oscillation");
    scriptEng.tempValue[0] <<= 2;
    waterLevel = Sin512(scriptEng.tempValue[0]);
    waterLevel <<= 9;
    waterLevel += self->YPos;
    if (pGravityStrength() == 0x3800) {
        if (pYPos() > self->YPos) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                pYVel() >>= 2;
                if (self->YPos < GVar("Stage.NewWaterLevel")) {
                    pYVel() += 0x10000;
                }
                if (pState() == PlayerStateID("Player_State_Fly")) {
                    StopSfx(24);
                    StopSfx(25);
                }
                pXVel() >>= 1;
                pSpeed() >>= 1;
                pTopSpeed() >>= 1;
                pAccel() >>= 1;
                pDecel() >>= 1;
                pAirAccel() >>= 1;
                pAirDecel() >>= 1;
                pGravityStrength() = 0x1000;
                pJumpStrength() = 0x38000;
                pJumpCap() = -0x20000;
                CreateTempObject(TypeNameID("Water Splash"), 0, pXPos(), waterLevel);
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                PlaySfx(globalSFXCount + 0, 0);
                self->values[1] = 52;
                GVar("Player.AirTimer") = 0;
            }
        }
    } else {
        if (GVar("Player.AirTimer") == 0) {
            self->state = 0;
        }
        switch (self->state) {
            case 0:
            Water_CreateAirBubble();
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 360) {
                PlaySfx(globalSFXCount + 9, 0);
                self->state++;
            }
            break;
            case 1:
            Water_CreateAirBubble();
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 660) {
                PlaySfx(globalSFXCount + 9, 0);
                self->state++;
            }
            break;
            case 2:
            Water_CreateAirBubble();
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 960) {
                PlaySfx(globalSFXCount + 9, 0);
                self->state++;
            }
            break;
            case 3:
            Water_CreateAirBubble();
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 1080) {
                scriptEng.tempValue[0] = 0;
                Water_CreateCountBubble();
                self->state++;
            }
            break;
            case 4:
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 1200) {
                scriptEng.tempValue[0] = 1;
                Water_CreateCountBubble();
                self->state++;
            }
            break;
            case 5:
            Water_CreateAirBubble();
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 1320) {
                scriptEng.tempValue[0] = 2;
                Water_CreateCountBubble();
                self->state++;
            }
            break;
            case 6:
            Water_CreateAirBubble();
            scriptEng.tempValue[0] = GVar("Player.AirTimer");
            scriptEng.tempValue[0] &= 63;
            if (scriptEng.tempValue[0] == 0) {
                PlaySfx(globalSFXCount + 10, 0);
            }
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 1440) {
                scriptEng.tempValue[0] = 3;
                Water_CreateCountBubble();
                self->state++;
            }
            break;
            case 7:
            Water_CreateAirBubble();
            scriptEng.tempValue[0] = GVar("Player.AirTimer");
            scriptEng.tempValue[0] &= 63;
            if (scriptEng.tempValue[0] == 0) {
                PlaySfx(globalSFXCount + 10, 0);
            }
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 1560) {
                scriptEng.tempValue[0] = 4;
                Water_CreateCountBubble();
                self->state++;
            }
            break;
            case 8:
            Water_CreateAirBubble();
            scriptEng.tempValue[0] = GVar("Player.AirTimer");
            scriptEng.tempValue[0] &= 63;
            if (scriptEng.tempValue[0] == 0) {
                PlaySfx(globalSFXCount + 10, 0);
            }
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 1680) {
                scriptEng.tempValue[0] = 5;
                Water_CreateCountBubble();
                self->state++;
            }
            break;
            case 9:
            Water_CreateAirBubble();
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 1800) {
                if (pState() != PlayerStateID("Player_State_Death")) {
                    timeEnabled = 0;
                    cameraEnabled = 0;
                    pState() = PlayerStateID("Player_State_Drown");
                    pAnimation() = GVar("ANI_DROWNING");
                    pSpeed() = 0;
                    pXVel() = 0;
                    pYVel() = 0;
                    pTileCollisions() = 0;
                    pObjectInteractions() = 0;
                    PlrEntity()->drawOrder = 5;
                    self->values[1] = 2;
                    self->values[3] = 60;
                    PlaySfx(globalSFXCount + 7, 0);
                    self->state++;
                }
            }
            break;
            case 10:
            GVar("Player.AirTimer")++;
            if (GVar("Player.AirTimer") == 1860) {
                self->state++;
            }
            if (self->values[1] > 0) {
                self->values[1]--;
                if (self->values[2] > 0) {
                    self->values[2]--;
                } else {
                    scriptEng.tempValue[1] = rand() % 2;
                    scriptEng.tempValue[1] += 2;
                    CreateTempObject(TypeNameID("Air Bubble"), scriptEng.tempValue[1], pXPos(), pYPos());
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                    objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x8800;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x60000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 256;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectEntityList[scriptEng.arrayPosition[2]].XPos;
                    self->values[2] = 512;
                }
            } else {
                scriptEng.tempValue[0] = rand() % 4;
                if (scriptEng.tempValue[0] == 1) {
                    self->values[2] = 2;
                } else {
                    self->values[2] = 512;
                }
                self->values[1] = 6;
                scriptEng.tempValue[1] = rand() % 2;
                scriptEng.tempValue[1] += 2;
                CreateTempObject(TypeNameID("Air Bubble"), scriptEng.tempValue[1], pXPos(), pYPos());
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 5;
                objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x8800;
                objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x60000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 256;
                objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectEntityList[scriptEng.arrayPosition[2]].XPos;
            }
            break;
        }
        if (pYPos() < self->YPos) {
            if (pState() != PlayerStateID("Player_State_Death")) {
                pYVel() <<= 1;
                if (pYVel() < -0x100000) {
                    pYVel() = -0x100000;
                }
                if (pState() == PlayerStateID("Player_State_Fly")) {
                    if (pTimer() < 480) {
                        PlaySfx(24, 1);
                    } else {
                        PlaySfx(25, 1);
                    }
                }
                pTopSpeed() = 0x60000;
                pAccel() = 0xC00;
                pDecel() = 0xC00;
                pAirAccel() = 0x1800;
                pAirDecel() = 0x600;
                pGravityStrength() = 0x3800;
                pJumpStrength() = 0x68000;
                pJumpCap() = -0x40000;
                CreateTempObject(TypeNameID("Water Splash"), 0, pXPos(), waterLevel);
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                PlaySfx(globalSFXCount + 0, 0);
                GVar("Player.AirTimer") = 0;
            }
        }
    }
    waterLevel >>= 16;
}

void O_R4_Water::ObjectDraw()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] > 23) {
        self->values[0] = 0;
        self->frame++;
        self->frame &= 3;
    }
    scriptEng.tempValue[0] = xScrollOffset;
    scriptEng.tempValue[1] = Sin512(GVar("Oscillation"));
    scriptEng.tempValue[1] >>= 5;
    scriptEng.tempValue[0] += scriptEng.tempValue[1];
    scriptEng.tempValue[0] &= 63;
    scriptEng.tempValue[0] = -scriptEng.tempValue[0];
    scriptEng.tempValue[1] = waterLevel;
    scriptEng.tempValue[1] -= yScrollOffset;
    DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.tempValue[0] += 128;
    DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.tempValue[0] += 128;
    DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
    scriptEng.tempValue[0] += 128;
    DrawSpriteScreenFX_Script(self->frame, FX_INK, scriptEng.tempValue[0], scriptEng.tempValue[1]);
}

void O_R4_Water::Water_CreateAirBubble()
{
    Entity *self = Self();

    if (self->values[1] > 0) {
        self->values[1]--;
        if (self->values[2] > 0) {
            self->values[2]--;
        } else {
            CreateTempObject(TypeNameID("Air Bubble"), 2, pXPos(), pYPos());
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x8800;
            if (pDirection() == 0) {
                objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x60000;
            } else {
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x60000;
                objectEntityList[scriptEng.arrayPosition[2]].values[1] = 256;
            }
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectEntityList[scriptEng.arrayPosition[2]].XPos;
            self->values[2] = 512;
        }
    } else {
        scriptEng.tempValue[0] = rand() % 3;
        if (scriptEng.tempValue[0] == 1) {
            self->values[2] = rand() % 16;
            self->values[2] += 8;
        } else {
            self->values[2] = 512;
        }
        self->values[1] = 60;
        CreateTempObject(TypeNameID("Air Bubble"), 2, pXPos(), pYPos());
        objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
        objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x8800;
        if (pDirection() == 0) {
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x60000;
        } else {
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x60000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 256;
        }
        objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectEntityList[scriptEng.arrayPosition[2]].XPos;
    }
}

void O_R4_Water::Water_CreateCountBubble()
{
    CreateTempObject(TypeNameID("Countdown Bubble"), scriptEng.tempValue[0], pXPos(), pYPos());
    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
    objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x8800;
    if (pDirection() == 0) {
        objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x60000;
    } else {
        objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x60000;
        objectEntityList[scriptEng.arrayPosition[2]].values[1] = 256;
    }
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectEntityList[scriptEng.arrayPosition[2]].XPos;
}

const Native::NativeFunctionDef O_R4_Water::funcs[2] = {
    { "Water_CreateAirBubble", O_R4_Water::Water_CreateAirBubble },
    { "Water_CreateCountBubble", O_R4_Water::Water_CreateCountBubble },
};

#endif // RETRO_USE_NATIVE_OBJECTS
