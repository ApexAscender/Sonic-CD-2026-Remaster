#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_R7CSetup.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R7CSetup.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_R7CSetup::ObjectStartup()
{
    objectEntityList[19].type = TypeNameID("R7 Setup");
    objectEntityList[19].priority = 1;
}

void O_R7_R7CSetup::ObjectMain()
{
    Entity *self = Self();

    if (self->values[2] > 0) {
        self->values[2]--;
    }
}

void O_R7_R7CSetup::ObjectPlayerInteraction()
{
    Entity *self = Self();

    scriptEng.tempValue[1] = pXPos();
    scriptEng.tempValue[1] >>= 23;
    scriptEng.tempValue[2] = pYPos();
    scriptEng.tempValue[2] >>= 23;
    scriptEng.tempValue[0] = stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]];
    switch (scriptEng.tempValue[0]) {
        case 16:
        case 17:
        case 18:
        case 19:
        R7Setup_GetLoopTileInfo();
        if (pCollisionMode() == 0) {
            if (scriptEng.tempValue[0] == 1001) {
                scriptEng.tempValue[1] &= 1022;
                scriptEng.tempValue[2] &= 1022;
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 20;
                scriptEng.tempValue[1]++;
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 21;
                scriptEng.tempValue[1]--;
                scriptEng.tempValue[2]++;
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 22;
                scriptEng.tempValue[1]++;
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 23;
            }
        } else {
            if (pSpeed() > 0) {
                if (scriptEng.tempValue[0] == 1003) {
                    scriptEng.tempValue[1] &= 1022;
                    scriptEng.tempValue[2] &= 1022;
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 20;
                    scriptEng.tempValue[1]++;
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 21;
                    scriptEng.tempValue[1]--;
                    scriptEng.tempValue[2]++;
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 22;
                    scriptEng.tempValue[1]++;
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 23;
                }
            }
        }
        break;
        case 20:
        case 21:
        case 22:
        case 23:
        R7Setup_GetLoopTileInfo();
        if (pCollisionMode() == 0) {
            if (scriptEng.tempValue[0] == 1000) {
                scriptEng.tempValue[1] &= 1022;
                scriptEng.tempValue[2] &= 1022;
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 16;
                scriptEng.tempValue[1]++;
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 17;
                scriptEng.tempValue[1]--;
                scriptEng.tempValue[2]++;
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 18;
                scriptEng.tempValue[1]++;
                stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 19;
            }
        } else {
            if (pSpeed() < 0) {
                if (scriptEng.tempValue[0] == 1002) {
                    scriptEng.tempValue[1] &= 1022;
                    scriptEng.tempValue[2] &= 1022;
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 16;
                    scriptEng.tempValue[1]++;
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 17;
                    scriptEng.tempValue[1]--;
                    scriptEng.tempValue[2]++;
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 18;
                    scriptEng.tempValue[1]++;
                    stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 19;
                }
            }
        }
        break;
        case 24:
        case 25:
        case 26:
        case 27:
        R7Setup_GetLoopTileInfo();
        if (scriptEng.tempValue[0] == 1001) {
            scriptEng.tempValue[1] &= 1022;
            scriptEng.tempValue[2] &= 1022;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 28;
            scriptEng.tempValue[1]++;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 29;
            scriptEng.tempValue[1]--;
            scriptEng.tempValue[2]++;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 30;
            scriptEng.tempValue[1]++;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 31;
        }
        break;
        case 28:
        case 29:
        case 30:
        case 31:
        R7Setup_GetLoopTileInfo();
        if (scriptEng.tempValue[0] == 1000) {
            scriptEng.tempValue[1] &= 1022;
            scriptEng.tempValue[2] &= 1022;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 24;
            scriptEng.tempValue[1]++;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 25;
            scriptEng.tempValue[1]--;
            scriptEng.tempValue[2]++;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 26;
            scriptEng.tempValue[1]++;
            stageLayouts[0].tiles[scriptEng.tempValue[1] + 0x100 * scriptEng.tempValue[2]] = 27;
        }
        break;
    }
    if (self->values[2] == 0) {
        scriptEng.tempValue[0] = pSpeed();
        if (scriptEng.tempValue[0] < 0) {
            scriptEng.tempValue[0] = -scriptEng.tempValue[0];
        }
        if (scriptEng.tempValue[0] > 0xA0000) {
            scriptEng.tempValue[3] = pXPos();
            scriptEng.tempValue[3] >>= 16;
            scriptEng.tempValue[4] = pYPos();
            scriptEng.tempValue[4] >>= 16;
            scriptEng.tempValue[4] += 8;
            scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[3], scriptEng.tempValue[4], 8);
            if (scriptEng.tempValue[0] == 1) {
                self->values[2] = 4;
                CreateTempObject(TypeNameID("Fire Trail"), 0, pXPos(), pYPos());
                if (pSpeed() < 0) {
                    objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
                } else {
                    objectEntityList[scriptEng.arrayPosition[2]].direction = 0;
                }
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                objectEntityList[scriptEng.arrayPosition[2]].YPos = ((objectEntityList[scriptEng.arrayPosition[2]].YPos >> 16) + (pCollisionBottom())) << 16;
            }
        }
    }
}

void O_R7_R7CSetup::R7Setup_GetLoopTileInfo()
{
    scriptEng.tempValue[3] = pXPos();
    scriptEng.tempValue[3] >>= 16;
    scriptEng.tempValue[3] &= 255;
    scriptEng.tempValue[3] += 0x3100;
    scriptEng.tempValue[0] -= 16;
    scriptEng.tempValue[0] >>= 2;
    scriptEng.tempValue[0] <<= 8;
    scriptEng.tempValue[4] = pYPos();
    scriptEng.tempValue[4] >>= 16;
    scriptEng.tempValue[4] &= 255;
    scriptEng.tempValue[4] += scriptEng.tempValue[0];
    scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[3], scriptEng.tempValue[4], 0);
}

const Native::NativeFunctionDef O_R7_R7CSetup::funcs[1] = {
    { "R7Setup_GetLoopTileInfo", O_R7_R7CSetup::R7Setup_GetLoopTileInfo },
};

#endif // RETRO_USE_NATIVE_OBJECTS
