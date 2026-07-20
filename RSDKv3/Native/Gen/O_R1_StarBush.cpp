#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_StarBush.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from StarBush.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_StarBush::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects2.gif");
    AddSpriteFrame(-24, -20, 48, 40, 115, 131);
    AddSpriteFrame(-12, -12, 24, 24, 1, 229);
    AddSpriteFrame(-24, -20, 48, 40, 115, 131);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Star Bush")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 0) {
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
            }
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 2) {
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_StarBush::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        DrawSprite_FrameXY(0, self->values[0], self->YPos);
    } else {
        DrawSprite_Frame(self->propertyValue);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
