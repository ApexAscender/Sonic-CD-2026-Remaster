#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_PaletteAni_A.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PaletteAni_A.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_PaletteAni_A::ObjectStartup()
{
    objectEntityList[19].type = TypeNameID("PaletteAnimation");
    objectEntityList[19].priority = 1;
    CopyPalette(0, 1);
    CopyPalette(0, 2);
    CopyPalette(0, 3);
    CopyPalette(0, 4);
    CopyPalette(0, 5);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 0;
    scriptEng.tempValue[2] = 32;
    while (scriptEng.tempValue[0] < 6) {
        LoadPalette("R3A_PalCycle.act", scriptEng.tempValue[0], 160, scriptEng.tempValue[1], scriptEng.tempValue[2]);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 32;
        scriptEng.tempValue[2] += 32;
    }
}

void O_R3_PaletteAni_A::ObjectMain()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] == 3) {
        self->values[0] = 0;
        self->values[1]++;
        self->values[1] %= 6;
        SetActivePalette(self->values[1], 0, 240);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
