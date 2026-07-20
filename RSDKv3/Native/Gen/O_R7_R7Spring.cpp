#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_R7Spring.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R7Spring.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_R7Spring::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-16, -16, 32, 16, 84, 1);
    AddSpriteFrame(0, -16, 16, 32, 117, 1);
    AddSpriteFrame(-16, -16, 16, 32, 175, 1);
    AddSpriteFrame(-16, 0, 32, 16, 84, 59);
    AddSpriteFrame(-8, -24, 32, 32, 84, 117);
    AddSpriteFrame(-24, -24, 32, 32, 117, 165);
    AddSpriteFrame(-8, -24, 32, 32, 84, 117);
    AddSpriteFrame(-24, -24, 32, 32, 117, 165);
    AddSpriteFrame(-16, -8, 32, 8, 84, 1);
    AddSpriteFrame(0, -16, 8, 32, 125, 1);
    AddSpriteFrame(-8, -16, 8, 32, 175, 1);
    AddSpriteFrame(-16, 0, 32, 8, 84, 67);
    AddSpriteFrame(-8, -24, 32, 32, 84, 150);
    AddSpriteFrame(-24, -24, 32, 32, 150, 165);
    AddSpriteFrame(-8, -24, 32, 32, 84, 150);
    AddSpriteFrame(-24, -24, 32, 32, 150, 165);
    AddSpriteFrame(-16, -40, 32, 40, 84, 18);
    AddSpriteFrame(0, -16, 40, 32, 134, 1);
    AddSpriteFrame(-24, -16, 40, 32, 192, 1);
    AddSpriteFrame(-16, 0, 32, 40, 84, 76);
    AddSpriteFrame(-8, -40, 48, 48, 117, 34);
    AddSpriteFrame(-40, -40, 48, 48, 166, 34);
    AddSpriteFrame(-8, -40, 48, 48, 117, 34);
    AddSpriteFrame(-40, -40, 48, 48, 166, 34);
}

void O_R7_R7Spring::ObjectDraw()
{
    Entity *self = Self();

    if (self->values[0] == 0) {
        DrawSpriteFX_Script(self->propertyValue, FX_FLIP, self->XPos, self->YPos);
    } else {
        self->values[0]++;
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] >>= 1;
        switch (scriptEng.tempValue[0]) {
            case 0:
            case 1:
            DrawSpriteFX_Script(self->propertyValue, FX_FLIP, self->XPos, self->YPos);
            break;
            case 2:
            case 6:
            scriptEng.tempValue[1] = self->propertyValue;
            scriptEng.tempValue[1] += 8;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            break;
            case 3:
            case 4:
            case 5:
            scriptEng.tempValue[1] = self->propertyValue;
            scriptEng.tempValue[1] += 16;
            DrawSpriteFX_Script(scriptEng.tempValue[1], FX_FLIP, self->XPos, self->YPos);
            break;
        }
        if (self->values[0] > 12) {
            self->values[0] = 0;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
