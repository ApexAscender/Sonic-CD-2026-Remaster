#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_R82CSetup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R82CSetup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_R82CSetup::ObjectStartup()
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
        LoadPalette("R82C_PalCycle.act", scriptEng.tempValue[0], 160, scriptEng.tempValue[1], scriptEng.tempValue[2]);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 32;
        scriptEng.tempValue[2] += 32;
    }
}

void O_R8_R82CSetup::ObjectMain()
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
        Copy16x16Tile(490, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(491, scriptEng.tempValue[0]);
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
        Copy16x16Tile(492, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(493, scriptEng.tempValue[0]);
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
        Copy16x16Tile(494, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(495, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(496, scriptEng.tempValue[0]);
        scriptEng.tempValue[0]++;
        Copy16x16Tile(497, scriptEng.tempValue[0]);
    }
    self->values[4]++;
    self->values[4] %= 20;
    scriptEng.tempValue[0] = self->values[5];
    scriptEng.tempValue[0] &= 7;
    if (scriptEng.tempValue[0] == 0) {
        scriptEng.tempValue[0] = self->values[5];
        scriptEng.tempValue[0] >>= 3;
        scriptEng.tempValue[0] += 632;
        Copy16x16Tile(498, scriptEng.tempValue[0]);
    }
    self->values[5]++;
    self->values[5] %= 56;
    self->values[0]++;
    if (self->values[0] == 5) {
        self->values[0] = 0;
        self->values[1]++;
        self->values[1] %= 6;
        scriptEng.tempValue[0] = self->values[1];
        scriptEng.tempValue[0] += 639;
        Copy16x16Tile(499, scriptEng.tempValue[0]);
    }
    SetActivePalette(self->values[1], 0, SCREEN_YSIZE);
}

void O_R8_R82CSetup::ObjectPlayerInteraction()
{
    scriptEng.tempValue[1] = pXPos();
    scriptEng.tempValue[1] >>= 16;
    scriptEng.tempValue[1] += pCollisionRight();
    scriptEng.tempValue[2] = pYPos();
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[2] += pCollisionBottom();
    scriptEng.tempValue[2] += 2;
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[1], scriptEng.tempValue[2], 8);
    if (scriptEng.tempValue[0] == 1) {
        scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[1], scriptEng.tempValue[2], 1);
        if (scriptEng.tempValue[0] == 0) {
            pXPos() += 0x10000;
        } else {
            pXPos() -= 0x10000;
        }
    } else {
        scriptEng.tempValue[1] = pXPos();
        scriptEng.tempValue[1] >>= 16;
        scriptEng.tempValue[1] += pCollisionLeft();
        scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[1], scriptEng.tempValue[2], 8);
        if (scriptEng.tempValue[0] == 1) {
            scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[1], scriptEng.tempValue[2], 1);
            if (scriptEng.tempValue[0] == 0) {
                pXPos() += 0x10000;
            } else {
                pXPos() -= 0x10000;
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
