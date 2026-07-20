#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_R81BSetup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R81BSetup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_R81BSetup::ObjectStartup()
{
    objectEntityList[19].type = TypeNameID("R8 Setup");
    objectEntityList[19].priority = 1;
    CopyPalette(0, 1);
    CopyPalette(0, 2);
    CopyPalette(0, 3);
    CopyPalette(0, 4);
    CopyPalette(0, 5);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 0;
    scriptEng.tempValue[2] = 32;
    while (scriptEng.tempValue[0] < 3) {
        LoadPalette("R81B_PalCycle.act", scriptEng.tempValue[0], 160, scriptEng.tempValue[1], scriptEng.tempValue[2]);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 32;
        scriptEng.tempValue[2] += 32;
    }
}

void O_R8_R81BSetup::ObjectMain()
{
    Entity *self = Self();

    self->rotation++;
    self->rotation %= 144;
    self->values[0]++;
    if (self->values[0] == 5) {
        self->values[0] = 0;
        self->values[1]++;
        self->values[1] %= 3;
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += 639;
    }
    SetActivePalette(self->values[1], 0, SCREEN_YSIZE);
}

#endif // RETRO_USE_NATIVE_OBJECTS
