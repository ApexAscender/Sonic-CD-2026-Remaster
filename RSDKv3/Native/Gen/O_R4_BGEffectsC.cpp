#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_BGEffectsC.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BGEffectsC.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_BGEffectsC::ObjectStartup()
{
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BGEffects")) {
            objectEntityList[scriptEng.arrayPosition[0]].priority = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 5;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 0;
        }
        scriptEng.arrayPosition[0]++;
    }
    scriptEng.arrayPosition[0] = 0;
    BGEffects_Deform_Left();
    scriptEng.arrayPosition[0] = 128;
    BGEffects_Deform_Left();
    scriptEng.arrayPosition[0] = 160;
    BGEffects_Deform_Right();
    scriptEng.arrayPosition[0] = 256;
    while (scriptEng.arrayPosition[0] < 576) {
        scriptEng.arrayPosition[1] = scriptEng.arrayPosition[0];
        scriptEng.arrayPosition[1] -= 256;
        bgDeformationData1[scriptEng.arrayPosition[0]] = bgDeformationData1[scriptEng.arrayPosition[1]];
        scriptEng.arrayPosition[0]++;
    }
    SetLayerDeformation(3, 128, 4, 0, 0, 0);
    LoadPalette("R4C_WaterPal.act", 7, 0, 0, 256);
}

void O_R4_BGEffectsC::ObjectDraw()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] > 1) {
        stageLayouts[0].deformationOffsetW++;
        stageLayouts[1].deformationOffsetW++;
        self->values[0] = 0;
    }
    scriptEng.tempValue[0] = waterLevel;
    scriptEng.tempValue[0] -= yScrollOffset;
    if (scriptEng.tempValue[0] < 0) {
        scriptEng.tempValue[0] = 0;
    }
    if (scriptEng.tempValue[0] > SCREEN_YSIZE) {
        scriptEng.tempValue[0] = SCREEN_YSIZE;
    }
    SetActivePalette(objectEntityList[19].values[1], 0, scriptEng.tempValue[0]);
    SetActivePalette(7, scriptEng.tempValue[0], SCREEN_YSIZE);
}

void O_R4_BGEffectsC::BGEffects_Deform_Left()
{
    bgDeformationData1[scriptEng.arrayPosition[0]] = 1;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 1;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 2;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 2;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 3;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 3;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 3;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 3;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 2;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 2;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 1;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = 1;
    scriptEng.arrayPosition[0]++;
}

void O_R4_BGEffectsC::BGEffects_Deform_Right()
{
    bgDeformationData1[scriptEng.arrayPosition[0]] = -1;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -1;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -2;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -2;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -3;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -3;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -3;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -3;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -2;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -2;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -1;
    scriptEng.arrayPosition[0]++;
    bgDeformationData1[scriptEng.arrayPosition[0]] = -1;
    scriptEng.arrayPosition[0]++;
}

const Native::NativeFunctionDef O_R4_BGEffectsC::funcs[2] = {
    { "BGEffects_Deform_Left", O_R4_BGEffectsC::BGEffects_Deform_Left },
    { "BGEffects_Deform_Right", O_R4_BGEffectsC::BGEffects_Deform_Right },
};

#endif // RETRO_USE_NATIVE_OBJECTS
