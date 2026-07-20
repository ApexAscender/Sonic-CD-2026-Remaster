#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_FloorRubble.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from FloorRubble.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_FloorRubble::ObjectStartup()
{
    LoadSpriteSheet("R6/Objects2.gif");
    AddSpriteFrame(-8, -8, 16, 16, 165, 191);
    AddSpriteFrame(-8, -8, 16, 16, 181, 191);
    AddSpriteFrame(-4, -4, 8, 8, 165, 191);
    AddSpriteFrame(-4, -4, 8, 8, 173, 191);
    AddSpriteFrame(-4, -4, 8, 8, 165, 199);
    AddSpriteFrame(-4, -4, 8, 8, 173, 199);
}

void O_R6_FloorRubble::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[1];
    self->values[2] += self->values[3];
    self->YPos += self->values[2];
    if (self->propertyValue == 0) {
        ObjectTileCollision_Script(0, 0, 8, 0);
        if (CheckResult() == 1) {
            self->type = TypeNameID("Blank Object");
            CreateTempObject(TypeNameID("Floor Rubble"), 2, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x28000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x3000;
            CreateTempObject(TypeNameID("Floor Rubble"), 3, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x28000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x3000;
            CreateTempObject(TypeNameID("Floor Rubble"), 4, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x1C000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x3000;
            CreateTempObject(TypeNameID("Floor Rubble"), 5, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x40000;
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x1C000;
            objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x3000;
        }
    } else {
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R6_FloorRubble::ObjectDraw()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        scriptEng.tempValue[0] = self->values[0];
        scriptEng.tempValue[0] /= 10;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->values[0]++;
        self->values[0] %= 20;
    } else {
        DrawSprite_Frame(self->propertyValue);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
