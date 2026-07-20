#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_CLedge1.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CLedge1.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_CLedge1::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects2.gif");
    AddSpriteFrame(-40, -40, 80, 80, 1, 1);
    scriptEng.tempValue[1] = 1;
    while (scriptEng.tempValue[1] < 80) {
        scriptEng.tempValue[0] = 65;
        while (scriptEng.tempValue[0] > 0) {
            AddSpriteFrame(-8, -8, 16, 16, scriptEng.tempValue[1], scriptEng.tempValue[0]);
            scriptEng.tempValue[0] -= 16;
        }
        scriptEng.tempValue[1] += 16;
    }
}

void O_R1_CLedge1::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        if (self->values[0] > 0) {
            self->values[0]--;
        } else {
            self->values[1] += 0x5000;
            self->YPos += self->values[1];
        }
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
        break;
        case 2:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        }
        break;
    }
}

void O_R1_CLedge1::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (self->state == 0) {
            PlayerObjectCollision(C_PLATFORM, -40, -24, 40, -8);
            if (CheckResult() == 1) {
                self->priority = 0;
                self->type = TypeNameID("Blank Object");
                scriptEng.tempValue[0] = 1;
                scriptEng.tempValue[1] = 0;
                scriptEng.tempValue[4] = self->XPos;
                scriptEng.tempValue[4] -= 0x200000;
                while (scriptEng.tempValue[1] < 5) {
                    scriptEng.tempValue[2] = 0;
                    scriptEng.tempValue[5] = self->YPos;
                    scriptEng.tempValue[5] += 0x200000;
                    switch (scriptEng.tempValue[1]) {
                        case 0:
                        scriptEng.tempValue[3] = 10;
                        break;
                        case 1:
                        scriptEng.tempValue[3] = 22;
                        break;
                        case 2:
                        scriptEng.tempValue[3] = 34;
                        break;
                        case 3:
                        scriptEng.tempValue[3] = 46;
                        break;
                        case 4:
                        scriptEng.tempValue[3] = 58;
                        break;
                    }
                    while (scriptEng.tempValue[2] < 5) {
                        CreateTempObject(TypeNameID("Crumble Ledge 1"), scriptEng.tempValue[0], scriptEng.tempValue[4], scriptEng.tempValue[5]);
                        objectEntityList[scriptEng.arrayPosition[2]].values[0] = scriptEng.tempValue[3];
                        objectEntityList[scriptEng.arrayPosition[2]].state = 1;
                        scriptEng.tempValue[3] += 5;
                        scriptEng.tempValue[0]++;
                        scriptEng.tempValue[2]++;
                        scriptEng.tempValue[5] -= 0x100000;
                    }
                    scriptEng.tempValue[3] -= 8;
                    scriptEng.tempValue[1]++;
                    scriptEng.tempValue[4] += 0x100000;
                }
                PlaySfx(globalSFXCount + 0, 0);
            }
        }
        break;
        case 4:
        case 9:
        case 14:
        case 19:
        case 24:
        if (self->values[0] > 0) {
            PlayerObjectCollision(C_PLATFORM, -8, -8, 8, 8);
        }
        break;
    }
}

void O_R1_CLedge1::ObjectDraw()
{
    Entity *self = Self();

    if (self->state < 2) {
        DrawSprite_Frame(self->propertyValue);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
