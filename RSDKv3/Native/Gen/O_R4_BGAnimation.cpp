#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_BGAnimation.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGAnimation.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_BGAnimation::ObjectStartup()
{
    objectEntityList[19].type = TypeNameID("Blank Object");
    objectEntityList[19].priority = 1;
    objectEntityList[19].values[2] = 534;
    CopyPalette(0, 1);
    CopyPalette(0, 2);
    CopyPalette(0, 3);
    CopyPalette(0, 4);
    CopyPalette(0, 5);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 0;
    scriptEng.tempValue[2] = 16;
    while (scriptEng.tempValue[0] < 6) {
        LoadPalette("R41A_PalCycle.act", scriptEng.tempValue[0], 176, scriptEng.tempValue[1], scriptEng.tempValue[2]);
        scriptEng.tempValue[0]++;
        scriptEng.tempValue[1] += 16;
        scriptEng.tempValue[2] += 16;
    }
}

void O_R4_BGAnimation::ObjectMain()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->state == 0) {
        if (self->values[0] == 5) {
            switch (self->frame) {
                case 0:
                case 6:
                self->values[1] = 0;
                break;
                case 1:
                self->values[1] = 1;
                break;
                case 2:
                self->values[1] = 2;
                break;
                case 3:
                self->values[1] = 3;
                break;
                case 4:
                self->values[1] = 4;
                break;
                case 5:
                self->values[1] = 5;
                break;
            }
        }
        if (self->values[0] == 9) {
            self->values[0] = 0;
            self->frame++;
            if (self->frame > 6) {
                self->frame = 0;
                self->state = 1;
            }
            scriptEng.tempValue[0] = self->values[2];
            switch (self->frame) {
                case 0:
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                if (scriptEng.tempValue[0] > 542) {
                    scriptEng.tempValue[0] = 534;
                }
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                break;
                case 1:
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 717);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 718);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 719);
                scriptEng.tempValue[0]++;
                if (scriptEng.tempValue[0] > 542) {
                    scriptEng.tempValue[0] = 534;
                }
                Copy16x16Tile(scriptEng.tempValue[0], 716);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 717);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 718);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 719);
                scriptEng.tempValue[0]++;
                break;
                case 2:
                Copy16x16Tile(scriptEng.tempValue[0], 720);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 721);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 722);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 723);
                scriptEng.tempValue[0]++;
                if (scriptEng.tempValue[0] > 542) {
                    scriptEng.tempValue[0] = 534;
                }
                Copy16x16Tile(scriptEng.tempValue[0], 720);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 721);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 722);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 723);
                scriptEng.tempValue[0]++;
                break;
                case 3:
                Copy16x16Tile(scriptEng.tempValue[0], 724);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 725);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 726);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 727);
                scriptEng.tempValue[0]++;
                if (scriptEng.tempValue[0] > 542) {
                    scriptEng.tempValue[0] = 534;
                }
                Copy16x16Tile(scriptEng.tempValue[0], 724);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 725);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 726);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 727);
                scriptEng.tempValue[0]++;
                break;
                case 4:
                Copy16x16Tile(scriptEng.tempValue[0], 728);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 729);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 730);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 731);
                scriptEng.tempValue[0]++;
                if (scriptEng.tempValue[0] > 542) {
                    scriptEng.tempValue[0] = 534;
                }
                Copy16x16Tile(scriptEng.tempValue[0], 728);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 729);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 730);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 731);
                scriptEng.tempValue[0]++;
                break;
                case 5:
                Copy16x16Tile(scriptEng.tempValue[0], 732);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 733);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 734);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 735);
                scriptEng.tempValue[0]++;
                if (scriptEng.tempValue[0] > 542) {
                    scriptEng.tempValue[0] = 534;
                }
                Copy16x16Tile(scriptEng.tempValue[0], 732);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 733);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 734);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 735);
                scriptEng.tempValue[0]++;
                break;
                case 6:
                Copy16x16Tile(scriptEng.tempValue[0], 736);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 737);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 738);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 739);
                scriptEng.tempValue[0]++;
                if (scriptEng.tempValue[0] > 542) {
                    scriptEng.tempValue[0] = 534;
                }
                Copy16x16Tile(scriptEng.tempValue[0], 736);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 737);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 738);
                scriptEng.tempValue[0]++;
                Copy16x16Tile(scriptEng.tempValue[0], 739);
                scriptEng.tempValue[0]++;
                break;
            }
        }
    } else {
        if (self->values[0] == 68) {
            self->values[0] = 0;
            self->state = 0;
            self->values[2] -= 4;
            if (self->values[2] < 534) {
                self->values[2] = 542;
            }
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
