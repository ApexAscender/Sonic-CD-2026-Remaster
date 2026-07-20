#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_ShootingFace.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ShootingFace.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_ShootingFace::ObjectStartup()
{
    LoadSpriteSheet("R4/Objects2.gif");
    AddSpriteFrame(-8, -16, 16, 32, 118, 151);
    AddSpriteFrame(-8, -16, 16, 32, 135, 151);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Shooting Face")) {
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R4_ShootingFace::ObjectMain()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] == 32) {
        self->values[0] = 0;
        CreateTempObject(TypeNameID("Face Projectile"), 0, self->XPos, self->YPos);
        if (self->propertyValue == 0) {
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x100000;
            objectEntityList[scriptEng.arrayPosition[2]].direction = 0;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x30000;
        } else {
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x100000;
            objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x30000;
        }
        objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x40000;
    }
}

void O_R4_ShootingFace::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS
