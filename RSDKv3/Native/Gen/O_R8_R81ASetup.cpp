#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_R81ASetup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R81ASetup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_R81ASetup::ObjectStartup()
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
        LoadPalette("R81A_PalCycle.act", scriptEng.tempValue[0], 160, scriptEng.tempValue[1], scriptEng.tempValue[2]);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 32;
        scriptEng.tempValue[2] += 32;
    }
}

void O_R8_R81ASetup::ObjectMain()
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
    if (self->values[6] == 0) {
        switch (self->frame) {
            case 0:
            self->values[6] = 44;
            self->frame++;
            Copy16x16Tile(440, 484);
            Copy16x16Tile(441, 485);
            Copy16x16Tile(442, 486);
            Copy16x16Tile(443, 487);
            break;
            case 1:
            self->values[6] = 4;
            self->frame++;
            Copy16x16Tile(440, 488);
            Copy16x16Tile(441, 489);
            Copy16x16Tile(442, 490);
            Copy16x16Tile(443, 491);
            break;
            case 2:
            self->values[6] = 13;
            self->frame++;
            Copy16x16Tile(440, 492);
            Copy16x16Tile(441, 493);
            Copy16x16Tile(442, 494);
            Copy16x16Tile(443, 495);
            break;
            case 3:
            self->values[6] = 4;
            self->frame++;
            Copy16x16Tile(440, 496);
            Copy16x16Tile(441, 497);
            Copy16x16Tile(442, 498);
            Copy16x16Tile(443, 499);
            break;
            case 4:
            self->values[6] = 4;
            if (self->values[7] < 4) {
                self->frame = 1;
                self->values[7]++;
            } else {
                self->values[7] = 0;
                self->frame = 0;
            }
            Copy16x16Tile(440, 484);
            Copy16x16Tile(441, 485);
            Copy16x16Tile(442, 486);
            Copy16x16Tile(443, 487);
            break;
        }
        self->values[6]--;
    } else {
        self->values[6]--;
    }
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
