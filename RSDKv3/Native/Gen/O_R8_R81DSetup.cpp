#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_R81DSetup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R81DSetup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_R81DSetup::ObjectStartup()
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
    while (scriptEng.tempValue[0] < 6) {
        LoadPalette("R81D_PalCycle.act", scriptEng.tempValue[0], 160, scriptEng.tempValue[1], scriptEng.tempValue[2]);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 32;
        scriptEng.tempValue[2] += 32;
    }
}

void O_R8_R81DSetup::ObjectMain()
{
    Entity *self = Self();

    self->rotation++;
    self->rotation %= 144;
    scriptEng.tempValue[0] = self->values[2];
    scriptEng.tempValue[0] %= 7;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[2];
        scriptEng.tempValue[0] /= 7;
        scriptEng.tempValue[0] <<= 1;
        scriptEng.tempValue[0] += 600;
        Copy16x16Tile(444, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(445, scriptEng.tempValue[0]);
    }
    self->values[2]++;
    self->values[2] %= 28;
    scriptEng.tempValue[0] = self->values[3];
    scriptEng.tempValue[0] &= 3;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[3];
        scriptEng.tempValue[0] >>= 2;
        scriptEng.tempValue[0] <<= 1;
        scriptEng.tempValue[0] += 608;
        Copy16x16Tile(446, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(447, scriptEng.tempValue[0]);
    }
    self->values[3]++;
    self->values[3] &= 15;
    scriptEng.tempValue[0] = self->values[4];
    scriptEng.tempValue[0] %= 5;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[4];
        scriptEng.tempValue[0] /= 5;
        scriptEng.tempValue[0] <<= 2;
        scriptEng.tempValue[0] += 616;
        Copy16x16Tile(448, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(449, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(450, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(451, scriptEng.tempValue[0]);
    }
    self->values[4]++;
    self->values[4] %= 20;
    scriptEng.tempValue[0] = self->values[5];
    scriptEng.tempValue[0] &= 7;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[5];
        scriptEng.tempValue[0] >>= 3;
        scriptEng.tempValue[0] += 632;
        Copy16x16Tile(452, scriptEng.tempValue[0]);
    }
    self->values[5]++;
    self->values[5] %= 56;
    self->values[0]++;
    if (self->values[0] == 5) {
        self->values[0] = 0;
        if (self->values[1] > 2) {
            self->values[1] = 1;
        } else {
            self->values[1]++;
        }
        self->values[1] %= 3;
        if (self->values[1] == 0) {
            switch (self->animationTimer) {
                case 3:
                self->values[1] += 3;
                break;
                case 4:
                self->values[1] += 4;
                break;
                case 5:
                self->values[1] += 5;
                break;
            }
            self->animationTimer++;
            self->animationTimer %= 6;
        }
    }
    SetActivePalette(self->values[1], 0, SCREEN_YSIZE);
}

#endif // RETRO_USE_NATIVE_OBJECTS
