#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_PaletteAni_D.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PaletteAni_D.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_PaletteAni_D::ObjectStartup()
{
    objectEntityList[19].type = TypeNameID("PaletteAnimation");
    objectEntityList[19].priority = 1;
    scriptEng.tempValue[0] = 1;
    while (scriptEng.tempValue[0] < 6) {
        RotatePalette(181, 183, 1);
        RotatePalette(172, 174, 0);
        RotatePalette(192, 197, 0);
        CopyPalette(0, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
    }
    RotatePalette(181, 183, 1);
    RotatePalette(172, 174, 0);
    RotatePalette(192, 197, 0);
}

void O_R1_PaletteAni_D::ObjectMain()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] == 8) {
        self->values[0] = 0;
        self->values[1]++;
        self->values[1] %= 6;
        SetActivePalette(self->values[1], 0, 240);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
