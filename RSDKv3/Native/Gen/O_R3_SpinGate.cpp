#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_SpinGate.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from SpinGate.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_SpinGate::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects2.gif");
    AddSpriteFrame(-16, -8, 32, 16, 18, 50);
    AddSpriteFrame(-16, -16, 32, 32, 51, 0);
    AddSpriteFrame(-16, -16, 32, 32, 84, 0);
    AddSpriteFrame(-16, -16, 32, 32, 51, 0);
}

void O_R3_SpinGate::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        if (self->values[0] < 96) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state = 0;
        }
    }
}

void O_R3_SpinGate::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
        if (CheckResult() == 1) {
            if (self->values[1] == 0) {
                self->state = 1;
                self->values[2]++;
                self->values[2] &= 3;
                self->values[1] = 1;
                switch (self->values[2]) {
                    case 0:
                    objectEntityList[objectLoop + 1].type = TypeNameID("Blank Object");
                    objectEntityList[objectLoop + 2].type = TypeNameID("Blank Object");
                    objectEntityList[objectLoop + 3].type = TypeNameID("Blank Object");
                    break;
                    case 1:
                    objectEntityList[objectLoop + 1].type = TypeNameID("Gate Light");
                    break;
                    case 2:
                    objectEntityList[objectLoop + 2].type = TypeNameID("Gate Light");
                    break;
                    case 3:
                    objectEntityList[objectLoop + 3].type = TypeNameID("Gate Light");
                    break;
                }
            }
        } else {
            self->values[1] = 0;
        }
    }
}

void O_R3_SpinGate::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->values[0];
    scriptEng.tempValue[0] >>= 2;
    scriptEng.tempValue[0] &= 3;
    switch (scriptEng.tempValue[0]) {
        case 0:
        case 1:
        case 2:
        DrawSprite_Frame(scriptEng.tempValue[0]);
        break;
        case 3:
        self->direction = 2;
        DrawSpriteFX_Script(3, FX_FLIP, self->XPos, self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
