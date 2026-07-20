#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_BreakSpikes.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BreakSpikes.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_BreakSpikes::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-16, -16, 32, 32, 50, 1);
    AddSpriteFrame(-16, -16, 8, 32, 50, 1);
    AddSpriteFrame(-8, -16, 8, 32, 50, 1);
    AddSpriteFrame(0, -16, 8, 32, 50, 1);
    AddSpriteFrame(8, -16, 8, 32, 50, 1);
}

void O_R7_BreakSpikes::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] -= 0x140000;
        scriptEng.arrayPosition[0] = GVar("MetalSonic_EntityNo");
        if (objectEntityList[scriptEng.arrayPosition[0]].XPos > scriptEng.tempValue[0]) {
            PlaySfx(globalSFXCount + 7, 0);
            HapticEffect_Script(96, 0, 0, 0);
            CreateTempObject(TypeNameID("Break Spikes"), 1, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x8000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x3000;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 254;
            CreateTempObject(TypeNameID("Break Spikes"), 2, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x3000;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 254;
            CreateTempObject(TypeNameID("Break Spikes"), 3, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x18000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x2000;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 254;
            CreateTempObject(TypeNameID("Break Spikes"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x4000;
            objectEntityList[scriptEng.arrayPosition[2]].inkEffect = 2;
            objectEntityList[scriptEng.arrayPosition[2]].alpha = 254;
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
        }
        scriptEng.arrayPosition[0] = 0;
    } else {
        if (self->alpha > 0) {
            self->alpha -= 2;
        }
        self->XPos += self->values[1];
        self->YPos += self->values[2];
        self->values[2] += self->values[3];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R7_BreakSpikes::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        PlayerObjectCollision(C_BOX, -16, -15, 16, 16);
        if (pYVel() > -1) {
            if (PlayerValue(4) == 0) {
                PlayerObjectCollision(C_TOUCH, -15, -16, 15, -12);
                if (CheckResult() == 1) {
                    pState() = PlayerStateID("Player_State_GotHit");
                    GVar("Player.HeavyMetalFlag") = 0;
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

void O_R7_BreakSpikes::ObjectDraw()
{
    Entity *self = Self();

    DrawSpriteFX_Script(self->propertyValue, FX_INK, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
