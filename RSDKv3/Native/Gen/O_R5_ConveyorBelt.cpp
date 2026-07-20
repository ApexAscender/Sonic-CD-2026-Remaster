#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_ConveyorBelt.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ConveyorBelt.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_ConveyorBelt::ObjectStartup()
{
    objectEntityList[19].type = TypeNameID("ConveyorBelt");
    objectEntityList[19].priority = 1;
    objectEntityList[19].drawOrder = 1;
    CopyPalette(0, 1);
    CopyPalette(0, 2);
    CopyPalette(0, 3);
    CopyPalette(0, 4);
    CopyPalette(0, 5);
    scriptEng.tempValue[0] = 0;
    scriptEng.tempValue[1] = 0;
    scriptEng.tempValue[2] = 16;
    GVar("ConveyorBelt_Flag") = 0;
    GVar("ConveyorBelt_Frame") = 0;
    switch (objectEntityList[24].propertyValue) {
        case 0:
        GVar("ConveyorBelt_Speed") = 0x10000;
        while (scriptEng.tempValue[0] < 6) {
            LoadPalette("R5A_PalCycle.act", scriptEng.tempValue[0], 160, scriptEng.tempValue[1], scriptEng.tempValue[2]);
            scriptEng.tempValue[1] += 16;
            scriptEng.tempValue[2] += 16;
            LoadPalette("R5A_PalCycle.act", scriptEng.tempValue[0], 192, scriptEng.tempValue[1], scriptEng.tempValue[2]);
            scriptEng.tempValue[1] += 16;
            scriptEng.tempValue[2] += 16;
            scriptEng.tempValue[0]++;
        }
        break;
        case 1:
        GVar("ConveyorBelt_Speed") = 0x8000;
        while (scriptEng.tempValue[0] < 6) {
            LoadPalette("R5B_PalCycle.act", scriptEng.tempValue[0], 160, scriptEng.tempValue[1], scriptEng.tempValue[2]);
            scriptEng.tempValue[1] += 16;
            scriptEng.tempValue[2] += 16;
            scriptEng.tempValue[0]++;
        }
        break;
        case 2:
        GVar("ConveyorBelt_Speed") = 0x20000;
        while (scriptEng.tempValue[0] < 6) {
            LoadPalette("R5C_PalCycle.act", scriptEng.tempValue[0], 160, scriptEng.tempValue[1], scriptEng.tempValue[2]);
            scriptEng.tempValue[1] += 16;
            scriptEng.tempValue[2] += 16;
            scriptEng.tempValue[0]++;
        }
        break;
        case 3:
        GVar("ConveyorBelt_Speed") = 0x20000;
        while (scriptEng.tempValue[0] < 6) {
            LoadPalette("R5D_PalCycle.act", scriptEng.tempValue[0], 160, scriptEng.tempValue[1], scriptEng.tempValue[2]);
            scriptEng.tempValue[1] += 16;
            scriptEng.tempValue[2] += 16;
            scriptEng.tempValue[0]++;
        }
        break;
    }
}

void O_R5_ConveyorBelt::ObjectPlayerInteraction()
{
    if (pGravity() == 0) {
        if (pState() != PlayerStateID("Player_State_TubeRoll")) {
            scriptEng.tempValue[1] = pXPos();
            scriptEng.tempValue[1] >>= 16;
            scriptEng.tempValue[1] += pCollisionRight();
            scriptEng.tempValue[2] = pYPos();
            scriptEng.tempValue[2] >>= 16;
            scriptEng.tempValue[2] += pCollisionBottom();
            scriptEng.tempValue[2] += 2;
            scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[1], scriptEng.tempValue[2], 8);
            if (scriptEng.tempValue[0] == 1) {
                if (GVar("ConveyorBelt_Flag") == 0) {
                    pXPos() += GVar("ConveyorBelt_Speed");
                } else {
                    pXPos() -= GVar("ConveyorBelt_Speed");
                }
            } else {
                scriptEng.tempValue[1] = pXPos();
                scriptEng.tempValue[1] >>= 16;
                scriptEng.tempValue[1] += pCollisionLeft();
                scriptEng.tempValue[0] = Get16x16TileInfo_Script(scriptEng.tempValue[1], scriptEng.tempValue[2], 8);
                if (scriptEng.tempValue[0] == 1) {
                    if (GVar("ConveyorBelt_Flag") == 0) {
                        pXPos() += GVar("ConveyorBelt_Speed");
                    } else {
                        pXPos() -= GVar("ConveyorBelt_Speed");
                    }
                }
            }
        }
    }
}

void O_R5_ConveyorBelt::ObjectDraw()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] == 5) {
        self->values[0] = 0;
        self->values[1]++;
        self->values[1] %= 3;
    }
    scriptEng.tempValue[0] = self->values[1];
    scriptEng.tempValue[0] += GVar("ConveyorBelt_Flag");
    SetActivePalette(scriptEng.tempValue[0], 0, 240);
}

#endif // RETRO_USE_NATIVE_OBJECTS
