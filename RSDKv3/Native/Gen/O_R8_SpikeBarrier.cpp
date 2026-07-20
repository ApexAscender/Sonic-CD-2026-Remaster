#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_SpikeBarrier.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpikeBarrier.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_SpikeBarrier::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-16, -76, 32, 152, 190, 1);
    AddSpriteFrame(-16, -76, 32, 152, 223, 1);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Spike Barrier")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].values[2];
            objectEntityList[scriptEng.arrayPosition[0]].values[1] -= 0x800000;
            objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_SpikeBarrier::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 0) {
        self->XPos -= 0x5000;
        if (self->XPos <= self->values[1]) {
            self->state = 1;
            self->direction = 0;
        }
    } else {
        self->XPos += 0x5000;
        if (self->XPos >= self->values[2]) {
            self->state = 0;
            self->direction = 1;
        }
    }
}

void O_R8_SpikeBarrier::ObjectPlayerInteraction()
{
    if (pCollisionPlane() == 0) {
        PlayerObjectCollision(C_TOUCH, -14, -76, 14, 76);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
    }
}

void O_R8_SpikeBarrier::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] >>= 1;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
    self->values[0]++;
    self->values[0] &= 3;
}

#endif // RETRO_USE_NATIVE_OBJECTS
