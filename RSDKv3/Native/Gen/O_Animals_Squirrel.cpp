#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Animals_Squirrel.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Squirrel.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Animals_Squirrel::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-10, -8, 24, 16, 150, 35);
    AddSpriteFrame(-10, -8, 24, 16, 150, 52);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Squirrel")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = -0x50000;
            objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Animals_Squirrel::ObjectMain()
{
    Entity *self = Self();

    self->YPos += self->values[0];
    self->values[0] += 0x2800;
    switch (self->state) {
        case 0:
        self->XPos += 0x10000;
        if (self->values[0] > 0) {
            ObjectTileCollision_Script(0, 0, 8, 0);
            if (CheckResult() == 1) {
                self->direction = 0;
                self->values[0] = -0x50000;
                self->state = 1;
            }
        }
        break;
        case 1:
        self->XPos -= 0x10000;
        if (self->values[0] > 0) {
            ObjectTileCollision_Script(0, 0, 8, 0);
            if (CheckResult() == 1) {
                self->direction = 1;
                self->values[0] = -0x50000;
                self->state = 0;
            }
        }
        break;
    }
}

void O_Animals_Squirrel::ObjectDraw()
{
    Entity *self = Self();

    if (GVar("MetalSonic_Destroyed") == 1) {
        if (self->values[0] < 0) {
            DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        } else {
            DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        }
    }
    if (objectEntityList[24].propertyValue == 2) {
        if (self->values[0] < 0) {
            DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        } else {
            DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
