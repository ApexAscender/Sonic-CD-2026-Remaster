#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Animals_R7_Rabbit.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R7_Rabbit.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Animals_R7_Rabbit::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects.gif");
    AddSpriteFrame(-8, -12, 16, 24, 1, 232);
    AddSpriteFrame(-8, -12, 16, 24, 18, 232);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Rabbit")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[0] = -0x50000;
            objectEntityList[scriptEng.arrayPosition[0]].direction = 0;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_Animals_R7_Rabbit::ObjectMain()
{
    Entity *self = Self();

    self->YPos += self->values[0];
    self->values[0] += 0x2C00;
    switch (self->state) {
        case 0:
        self->XPos += 0x10000;
        if (self->values[0] > 0x40000) {
            ObjectTileCollision_Script(0, 0, 8, 0);
            if (CheckResult() == 1) {
                self->values[0] = -0x50000;
                self->values[1]++;
                if (self->values[1] == 2) {
                    self->values[1] = 0;
                    self->state = 1;
                    self->direction = 1;
                }
            }
        }
        break;
        case 1:
        self->XPos -= 0x10000;
        if (self->values[0] > 0x40000) {
            ObjectTileCollision_Script(0, 0, 8, 0);
            if (CheckResult() == 1) {
                self->values[0] = -0x50000;
                self->values[1]++;
                if (self->values[1] == 2) {
                    self->values[1] = 0;
                    self->state = 0;
                    self->direction = 0;
                }
            }
        }
        break;
    }
}

void O_Animals_R7_Rabbit::ObjectDraw()
{
    Entity *self = Self();

    if (GVar("MetalSonic_Destroyed") == 1) {
        if (self->values[0] < 0) {
            DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        } else {
            DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        }
    } else {
        if (objectEntityList[24].propertyValue == 2) {
            if (self->values[0] < 0) {
                DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
            } else {
                DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
