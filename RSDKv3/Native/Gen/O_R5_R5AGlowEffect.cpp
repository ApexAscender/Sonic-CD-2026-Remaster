#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_R5AGlowEffect.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R5AGlowEffect.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_R5AGlowEffect::ObjectStartup()
{
    objectEntityList[21].type = TypeNameID("Glow Effect");
    objectEntityList[21].priority = 1;
    objectEntityList[21].drawOrder = 0;
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 0;
    scriptEng.tempValue[2] = 16;
    while (scriptEng.tempValue[0] < 5) {
        LoadPalette("R5A_GlowEffect.act", scriptEng.tempValue[0], 176, scriptEng.tempValue[1], scriptEng.tempValue[2]);
        scriptEng.tempValue[1] += 16;
        scriptEng.tempValue[2] += 16;
        scriptEng.tempValue[0]++;
    }
}

void O_R5_R5AGlowEffect::ObjectDraw()
{
    Entity *self = Self();

    if (activeTileLayers[0] == 1) {
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] /= 6;
        switch (scriptEng.tempValue[0]) {
            case 0:
            SetActivePalette(0, 0, SCREEN_YSIZE);
            break;
            case 1:
            SetActivePalette(0, 0, SCREEN_YSIZE);
            break;
            case 2:
            SetActivePalette(0, 0, SCREEN_YSIZE);
            break;
            case 3:
            SetActivePalette(0, 0, SCREEN_YSIZE);
            break;
            case 4:
            case 8:
            SetActivePalette(1, 0, SCREEN_YSIZE);
            break;
            case 5:
            case 7:
            SetActivePalette(2, 0, SCREEN_YSIZE);
            break;
            case 6:
            SetActivePalette(3, 0, SCREEN_YSIZE);
            break;
        }
        self->values[0]++;
        self->values[0] %= 54;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
