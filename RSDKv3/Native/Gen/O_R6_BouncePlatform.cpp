#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BouncePlatform.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BouncePlatform.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BouncePlatform::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects.gif");
    AddSpriteFrame(-32, -16, 64, 32, 132, 43);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Bounce Platform")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[4] = 0x1000;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R6_BouncePlatform::ObjectMain()
{
    Entity *self = Self();

    self->values[1] = self->YPos;
    self->values[2] += self->values[4];
    self->YPos += self->values[2];
    ObjectTileCollision_Script(0, 0, 16, 0);
    if (CheckResult() == 1) {
        if (self->values[4] == 0x1000) {
            PlaySfx(globalSFXCount + 3, 0);
        }
        if (objectEntityList[19].scale == 1) {
            self->values[2] = -0x60000;
            self->values[4] = 0x1000;
        } else {
            self->values[2] = -0x20000;
            self->values[4] = 0x1488;
        }
    }
    self->values[3] = self->YPos;
    self->values[3] -= self->values[1];
}

void O_R6_BouncePlatform::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->YPos;
    self->YPos = self->values[1];
    scriptEng.tempValue[1] = self->XPos;
    scriptEng.tempValue[1] -= pXPos();
    if (scriptEng.tempValue[1] < 0) {
        scriptEng.tempValue[1] = -scriptEng.tempValue[1];
    }
    if (scriptEng.tempValue[1] > 0x280000) {
        PlayerObjectCollision(C_BOX, -32, -16, 32, 16);
    }
    PlayerObjectCollision(C_PLATFORM, -32, -18, 32, 16);
    if (CheckResult() == 1) {
        pYPos() += self->values[3];
        pYPos() += 0x20000;
    }
    self->YPos = scriptEng.tempValue[0];
}

void O_R6_BouncePlatform::ObjectDraw()
{
    DrawSprite_Frame(0);
}

#endif // RETRO_USE_NATIVE_OBJECTS
