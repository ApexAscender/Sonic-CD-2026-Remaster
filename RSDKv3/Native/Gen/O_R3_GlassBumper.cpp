#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_GlassBumper.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from GlassBumper.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_GlassBumper::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects3.gif");
    switch (objectEntityList[24].propertyValue) {
        case 0:
        AddSpriteFrame(-16, -16, 32, 32, 66, 1);
        AddSpriteFrame(-16, -16, 32, 32, 99, 1);
        break;
        case 1:
        AddSpriteFrame(-16, -16, 32, 32, 66, 34);
        AddSpriteFrame(-16, -16, 32, 32, 99, 34);
        break;
        case 2:
        AddSpriteFrame(-16, -16, 32, 32, 66, 67);
        AddSpriteFrame(-16, -16, 32, 32, 99, 67);
        break;
        case 3:
        AddSpriteFrame(-16, -16, 32, 32, 66, 100);
        AddSpriteFrame(-16, -16, 32, 32, 99, 100);
        break;
    }
}

void O_R3_GlassBumper::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        self->values[0]++;
        if (self->values[0] > 15) {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R3_GlassBumper::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pAnimation() != GVar("ANI_HURT")) {
        if (self->state == 0) {
            PlayerObjectCollision(C_TOUCH, -14, -14, 14, 14);
            if (CheckResult() == 1) {
                PlaySfx(globalSFXCount + 8, 0);
                HapticEffect_Script(10, 0, 0, 0);
                CreateTempObject(TypeNameID("Object Score"), 0, self->XPos, self->YPos);
                GVar("Player.Score") += 100;
                self->state = 1;
                self->priority = 1;
                scriptEng.tempValue[0] = pXPos();
                scriptEng.tempValue[0] -= self->XPos;
                scriptEng.tempValue[1] = pYPos();
                scriptEng.tempValue[1] -= self->YPos;
                scriptEng.tempValue[2] = ArcTanLookup(scriptEng.tempValue[0], scriptEng.tempValue[1]);
                scriptEng.tempValue[0] = Cos256(scriptEng.tempValue[2]);
                scriptEng.tempValue[1] = Sin256(scriptEng.tempValue[2]);
                scriptEng.tempValue[0] *= 0x700;
                scriptEng.tempValue[1] *= 0x700;
                pXVel() = scriptEng.tempValue[0];
                pYVel() = scriptEng.tempValue[1];
                pSpeed() = pXVel();
                pGravity() = 1;
                pTimer() = 0;
                scriptEng.tempValue[0] = (objectEntityList[objectLoop].XPos >> 16);
                scriptEng.tempValue[1] = (objectEntityList[objectLoop].YPos >> 16);
                scriptEng.tempValue[0] -= 8;
                scriptEng.tempValue[1] -= 8;
                Set16x16TileInfo_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], 0);
                scriptEng.tempValue[0] += 16;
                Set16x16TileInfo_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], 0);
                scriptEng.tempValue[0] -= 16;
                scriptEng.tempValue[1] += 16;
                Set16x16TileInfo_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], 0);
                scriptEng.tempValue[0] += 16;
                Set16x16TileInfo_Script(0, scriptEng.tempValue[0], scriptEng.tempValue[1], 0);
            }
        }
    }
}

void O_R3_GlassBumper::ObjectDraw()
{
    Entity *self = Self();

    if (self->state == 1) {
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] >>= 3;
        DrawSprite_Frame(scriptEng.tempValue[0]);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
