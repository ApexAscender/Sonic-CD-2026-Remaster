#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R4_ButtonPrize.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ButtonPrize.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R4_ButtonPrize::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (objectEntityList[objectLoop - 1].propertyValue == 1) {
            switch (self->propertyValue) {
                case 0:
                objectEntityList[objectLoop - 1].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop + 1].type = TypeNameID("Moving Spikes");
                objectEntityList[objectLoop + 3].type = TypeNameID("Moving Spikes");
                objectEntityList[objectLoop + 5].type = TypeNameID("Moving Spikes");
                objectEntityList[objectLoop + 7].type = TypeNameID("Moving Spikes");
                objectEntityList[objectLoop + 9].type = TypeNameID("Moving Spikes");
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 1].XPos, objectEntityList[objectLoop - 1].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 3].XPos, objectEntityList[objectLoop + 3].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 5].XPos, objectEntityList[objectLoop + 5].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 7].XPos, objectEntityList[objectLoop + 7].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 9].XPos, objectEntityList[objectLoop + 9].YPos);
                break;
                case 1:
                objectEntityList[objectLoop - 3].type = TypeNameID("Object Score");
                objectEntityList[objectLoop - 3].propertyValue = 3;
                objectEntityList[objectLoop - 1].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop + 1].type = TypeNameID("Object Score");
                objectEntityList[objectLoop + 1].propertyValue = 3;
                objectEntityList[objectLoop + 3].type = TypeNameID("Object Score");
                objectEntityList[objectLoop + 3].propertyValue = 3;
                objectEntityList[objectLoop + 5].type = TypeNameID("Object Score");
                objectEntityList[objectLoop + 5].propertyValue = 3;
                objectEntityList[objectLoop + 7].type = TypeNameID("Object Score");
                objectEntityList[objectLoop + 7].propertyValue = 3;
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 3].XPos, objectEntityList[objectLoop - 3].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 1].XPos, objectEntityList[objectLoop - 1].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 3].XPos, objectEntityList[objectLoop + 3].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 5].XPos, objectEntityList[objectLoop + 5].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 7].XPos, objectEntityList[objectLoop + 7].YPos);
                GVar("Player.Score") += 5000;
                break;
                case 2:
                objectEntityList[objectLoop - 5].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop - 3].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop - 1].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop + 1].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop + 3].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop + 5].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop - 5].state = 1;
                objectEntityList[objectLoop - 3].state = 1;
                objectEntityList[objectLoop - 1].state = 1;
                objectEntityList[objectLoop + 1].state = 1;
                objectEntityList[objectLoop + 3].state = 1;
                objectEntityList[objectLoop + 5].state = 1;
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 5].XPos, objectEntityList[objectLoop - 5].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 3].XPos, objectEntityList[objectLoop - 3].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 1].XPos, objectEntityList[objectLoop - 1].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 3].XPos, objectEntityList[objectLoop + 3].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 5].XPos, objectEntityList[objectLoop + 5].YPos);
                break;
                case 3:
                objectEntityList[objectLoop - 7].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop - 5].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop - 3].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop - 1].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop + 1].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop + 3].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop - 7].state = 1;
                objectEntityList[objectLoop - 5].state = 1;
                objectEntityList[objectLoop - 3].state = 1;
                objectEntityList[objectLoop - 1].state = 1;
                objectEntityList[objectLoop + 1].state = 1;
                objectEntityList[objectLoop + 3].state = 1;
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 7].XPos, objectEntityList[objectLoop - 7].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 5].XPos, objectEntityList[objectLoop - 5].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 3].XPos, objectEntityList[objectLoop - 3].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 1].XPos, objectEntityList[objectLoop - 1].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 3].XPos, objectEntityList[objectLoop + 3].YPos);
                break;
                case 4:
                objectEntityList[objectLoop - 9].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop - 7].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop - 5].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop - 3].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop - 1].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop - 1].XPos += 0x200000;
                objectEntityList[objectLoop - 1].state = 2;
                objectEntityList[objectLoop + 1].type = TypeNameID("Blank Object");
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 9].XPos, objectEntityList[objectLoop - 9].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 7].XPos, objectEntityList[objectLoop - 7].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 5].XPos, objectEntityList[objectLoop - 5].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 3].XPos, objectEntityList[objectLoop - 3].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 1].XPos, objectEntityList[objectLoop - 1].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop + 1].XPos, objectEntityList[objectLoop + 1].YPos);
                break;
                case 5:
                objectEntityList[objectLoop - 11].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop - 9].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop - 7].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop - 5].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop - 3].type = TypeNameID("Blank Object");
                objectEntityList[objectLoop - 1].type = TypeNameID("Button Prize");
                objectEntityList[objectLoop - 1].state = 2;
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 11].XPos, objectEntityList[objectLoop - 11].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 9].XPos, objectEntityList[objectLoop - 9].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 7].XPos, objectEntityList[objectLoop - 7].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 5].XPos, objectEntityList[objectLoop - 5].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 3].XPos, objectEntityList[objectLoop - 3].YPos);
                CreateTempObject(TypeNameID("Explosion"), 0, objectEntityList[objectLoop - 1].XPos, objectEntityList[objectLoop - 1].YPos);
                break;
            }
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 1:
        self->values[0]++;
        if (self->values[0] == 60) {
            CreateTempObject(TypeNameID("Air Bubble"), 5, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectEntityList[scriptEng.arrayPosition[2]].XPos;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 256;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 1;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x8800;
        }
        if (self->values[0] == 120) {
            CreateTempObject(TypeNameID("Air Bubble"), 5, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = objectEntityList[scriptEng.arrayPosition[2]].XPos;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 256;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 1;
            objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = -0x8800;
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 2:
        self->values[0]++;
        if (self->values[0] == 360) {
            self->type = TypeNameID("Blank Object");
            self->priority = 0;
        }
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] &= 15;
        if (scriptEng.tempValue[0] == 0) {
            CreateTempObject(TypeNameID("Lose Ring"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0xB80000;
            objectEntityList[scriptEng.arrayPosition[2]].animationSpeed = 256;
            scriptEng.tempValue[1] = self->values[0];
            scriptEng.tempValue[1] >>= 4;
            scriptEng.tempValue[1] %= 10;
            switch (scriptEng.tempValue[1]) {
                case 0:
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0xA00000;
                break;
                case 1:
                case 9:
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x800000;
                break;
                case 2:
                case 8:
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x600000;
                break;
                case 3:
                case 7:
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x400000;
                break;
                case 4:
                case 6:
                objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x200000;
                break;
                case 5:
                break;
            }
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
