#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_WaterStreamC.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterStreamC.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_WaterStreamC::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream C")) {
            switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                case 0:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 192;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -96;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 96;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -96;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 96;
                break;
                case 1:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 64;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -96;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 96;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -96;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 96;
                break;
                case 2:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 192;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -128;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 128;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -128;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 128;
                break;
                case 3:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 64;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -128;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 128;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -128;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 128;
                break;
                case 4:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 64;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -160;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -96;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 64;
                break;
                case 5:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 192;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 96;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -96;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0;
                break;
                case 6:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 64;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -96;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 96;
                break;
                case 7:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 64;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -96;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -96;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0;
                break;
                case 8:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 192;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 128;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -128;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 0;
                break;
                case 9:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 64;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = -128;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -128;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 128;
                break;
                case 10:
                objectEntityList[scriptEng.arrayPosition[0]].values[1] = 192;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 0;
                objectEntityList[scriptEng.arrayPosition[0]].values[3] = 128;
                objectEntityList[scriptEng.arrayPosition[0]].values[4] = -128;
                objectEntityList[scriptEng.arrayPosition[0]].values[5] = 128;
                break;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_WaterStreamC::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (objectEntityList[objectLoop - 1].propertyValue == 1) {
        self->propertyValue = 1;
        PlayerObjectCollision(C_TOUCH, self->values[2], self->values[4], self->values[3], self->values[5]);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Hurt")) {
                if (pState() != PlayerStateID("Player_State_Death")) {
                    if (pState() != PlayerStateID("Player_State_Drown")) {
                        if (pState() != PlayerStateID("Player_State_Static")) {
                            GVar("Player.WaterStream") = 1;
                            pState() = PlayerStateID("Player_State_WaterCurrent");
                            pAnimation() = GVar("ANI_FANROTATE");
                            scriptEng.tempValue[0] = pXPos();
                            scriptEng.tempValue[0] -= self->XPos;
                            scriptEng.tempValue[1] = pYPos();
                            scriptEng.tempValue[1] -= self->YPos;
                            scriptEng.tempValue[2] = ArcTanLookup(scriptEng.tempValue[0], scriptEng.tempValue[1]);
                            scriptEng.tempValue[2] += self->values[1];
                            pXVel() = Cos256(scriptEng.tempValue[2]);
                            pYVel() = Sin256(scriptEng.tempValue[2]);
                            pXVel() <<= 10;
                            pYVel() <<= 10;
                            pSpeed() = pXVel();
                        }
                    }
                }
            }
        } else {
            if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                if (GVar("Player.WaterStream") == 0) {
                    if (pLeft() == 1) {
                        pXVel() = -0x20000;
                    }
                    if (pRight() == 1) {
                        pXVel() = 0x20000;
                    }
                    pSpeed() = pXVel();
                    pState() = PlayerStateID("Player_State_Air");
                    pControlMode() = 0;
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
