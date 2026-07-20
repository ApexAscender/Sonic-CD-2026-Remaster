#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_R8Spikes.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R8Spikes.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_R8Spikes::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-16, -16, 32, 32, 50, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("R8 Spikes")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 1) {
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 1;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_R8Spikes::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pCollisionPlane() == self->propertyValue) {
        PlayerObjectCollision(C_BOX, -16, -12, 16, 16);
        if (pYVel() > -1) {
            if (PlayerValue(4) == 0) {
                PlayerObjectCollision(C_TOUCH, -15, -13, 15, -12);
                if (CheckResult() == 1) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    if (pXPos() > self->XPos) {
                        pSpeed() = 0x20000;
                    } else {
                        pSpeed() = -0x20000;
                    }
                }
            }
        }
    }
}

void O_R8_R8Spikes::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
