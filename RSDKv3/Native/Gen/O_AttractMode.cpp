#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_AttractMode.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from AttractMode.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_AttractMode::ObjectStartup()
{
    if (activeStageList == 1) {
        if (playerListPos == 0) {
            LoadSpriteSheet("Global/Display.gif");
        }
        if (playerListPos == 1) {
            LoadSpriteSheet("Global/Display_t.gif");
        }
        AddSpriteFrame(-17, -5, 34, 11, 1, 176);
    } else {
        LoadSpriteSheet("Special/Objects.gif");
        AddSpriteFrame(-17, -5, 34, 11, 83, 168);
    }
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Attract Mode")) {
            if (GVar("Options.AttractMode") == 1) {
                objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 6;
                switch (objectEntityList[scriptEng.arrayPosition[0]].propertyValue) {
                    case 0:
                    LoadTextFile_Script(0, "Data/Game/Demos/Key11a.bin", 0);
                    GVar("LampPost.Check") = 0;
                    break;
                    case 1:
                    LoadTextFile_Script(0, "Data/Game/Demos/Special1.bin", 0);
                    GVar("LampPost.Check") = 0;
                    break;
                    case 2:
                    LoadTextFile_Script(0, "Data/Game/Demos/Key43c.bin", 0);
                    pXPos() = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                    pYPos() = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                    GVar("LampPost.Check") = 33;
                    break;
                    case 3:
                    LoadTextFile_Script(0, "Data/Game/Demos/Special6.bin", 0);
                    GVar("LampPost.Check") = 0;
                    break;
                    case 4:
                    LoadTextFile_Script(0, "Data/Game/Demos/Key82a.bin", 0);
                    pXPos() = objectEntityList[scriptEng.arrayPosition[0]].XPos;
                    pYPos() = objectEntityList[scriptEng.arrayPosition[0]].YPos;
                    GVar("LampPost.Check") = 33;
                    break;
                }
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = GetTextInfo_Script(0, 1, 0, 0);
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            }
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_AttractMode::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (pControlMode() == 0) {
            self->state++;
            self->values[3] = self->values[2];
            self->values[3] -= 60;
        }
        break;
        case 1:
        scriptEng.tempValue[0] = GetTextInfo_Script(0, 0, 0, self->values[1]);
        pUp() = ((scriptEng.tempValue[0] >> 0) & 1);
        pDown() = ((scriptEng.tempValue[0] >> 1) & 1);
        pLeft() = ((scriptEng.tempValue[0] >> 2) & 1);
        pRight() = ((scriptEng.tempValue[0] >> 3) & 1);
        pJumpPress() = ((scriptEng.tempValue[0] >> 4) & 1);
        pJumpHold() = ((scriptEng.tempValue[0] >> 5) & 1);
        if (self->values[1] < self->values[2]) {
            self->values[1]++;
        } else {
            StopMusic();
            GVar("Options.AttractMode") = 0;
            activeStageList = 0;
            stageListPosition = 0;
            GVar("Transporter_Destroyed") = 0;
            GVar("MetalSonic_Destroyed") = 0;
            GVar("Good_Future") = 0;
            stageMode = STAGEMODE_LOAD;
            GVar("LampPost.Check") = 0;
            Engine.hapticsEnabled = saveRAM[40];
        }
        if (self->values[1] >= self->values[3]) {
            masterVolume -= 2;
            cameraEnabled = 0;
            scriptEng.tempValue[0] = self->values[1];
            scriptEng.tempValue[0] -= self->values[3];
            scriptEng.tempValue[0] <<= 3;
            if (scriptEng.tempValue[0] > 255) {
                scriptEng.tempValue[0] = 255;
            }
            SetFade(0, 0, 0, scriptEng.tempValue[0]);
        } else {
            if (keyPress.A == 1) {
                self->values[1] = self->values[3];
            }
            if (keyPress.B == 1) {
                self->values[1] = self->values[3];
            }
            if (keyPress.C == 1) {
                self->values[1] = self->values[3];
            }
            if (anyPress == 1) {
                self->values[1] = self->values[3];
            }
        }
        break;
    }
}

void O_AttractMode::ObjectDraw()
{
    Entity *self = Self();

    if (objectEntityList[20].type != TypeNameID("Title Card")) {
        self->animationTimer++;
        self->animationTimer %= 60;
        if (self->animationTimer > 29) {
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
