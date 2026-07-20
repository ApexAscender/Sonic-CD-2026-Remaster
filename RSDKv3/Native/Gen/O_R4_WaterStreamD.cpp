#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_WaterStreamD.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from WaterStreamD.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_WaterStreamD::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Water Stream D")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].propertyValue;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] <<= 3;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = -objectEntityList[scriptEng.arrayPosition[0]].values[1];
            objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 0;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_WaterStreamD::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (objectEntityList[objectLoop - 1].propertyValue == 1) {
        self->propertyValue = 1;
        PlayerObjectCollision(C_TOUCH, -32, self->values[1], 32, self->values[2]);
        if (CheckResult() == 1) {
            if (pState() != PlayerStateID("Player_State_Hurt")) {
                if (pState() != PlayerStateID("Player_State_Death")) {
                    if (pState() != PlayerStateID("Player_State_Drown")) {
                        if (pState() != PlayerStateID("Player_State_Static")) {
                            pState() = PlayerStateID("Player_State_WaterCurrent");
                            pAnimation() = GVar("ANI_FANROTATE");
                            if (pLeft() == 0) {
                                if (pRight() == 0) {
                                    if (pXPos() < self->XPos) {
                                        pXPos() += 0x10000;
                                    }
                                    if (pXPos() > self->XPos) {
                                        pXPos() -= 0x10000;
                                    }
                                }
                            }
                            pYVel() = 0x40000;
                            if (GVar("Player.WaterStream") == 0) {
                                pXVel() = 0;
                                pSpeed() = 0;
                                GVar("Player.WaterStream") = 1;
                            }
                        }
                    }
                }
            }
        } else {
            if (pState() == PlayerStateID("Player_State_WaterCurrent")) {
                if (GVar("Player.WaterStream") == 0) {
                    pState() = PlayerStateID("Player_State_Air");
                    pControlMode() = 0;
                    pAnimation() = GVar("ANI_WALKING");
                }
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
