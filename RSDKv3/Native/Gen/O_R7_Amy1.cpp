#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R7_Amy1.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Amy1.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R7_Amy1::ObjectStartup()
{
    LoadSpriteSheet("R7/Objects2.gif");
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Amy 1")) {
            if (playerListPos == 0) {
                if (GVar("Options.GameMode") == 2) {
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                } else {
                    objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 4;
                }
            } else {
                objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
            }
        }
        scriptEng.arrayPosition[0]++;
    }
    AddSpriteFrame(-12, -20, 24, 40, 1, 170);
    AddSpriteFrame(-12, -20, 24, 40, 1, 211);
    AddSpriteFrame(-12, -20, 24, 40, 124, 109);
    AddSpriteFrame(-12, -20, 24, 40, 1, 211);
}

void O_R7_Amy1::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        self->YPos += self->values[2];
        self->values[2] += 0x2000;
        ObjectTileCollision_Script(0, 0, 19, 0);
        if (CheckResult() == 1) {
            ResetObjectEntity(objectLoop, TypeNameID("Amy 2"), 0, self->XPos, self->YPos);
            self->frame = 4;
            self->drawOrder = 4;
            self->values[3] = 0x3EA40000;
            self->values[4] = 0x40000000;
        }
    }
}

void O_R7_Amy1::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 0) {
        if (self->type == TypeNameID("Amy 1")) {
            PlayerObjectCollision(C_TOUCH, -8, -16, 8, 16);
            if (CheckResult() == 1) {
                pYVel() = -pYVel();
                pYVel() >>= 1;
                self->state = 1;
                self->frame >>= 3;
                CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
                timeEnabled = 0;
                PlaySfx(22, 0);
            }
        }
    }
}

void O_R7_Amy1::ObjectDraw()
{
    Entity *self = Self();

    if (self->state == 0) {
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 3;
        DrawSprite_Frame(scriptEng.tempValue[0]);
        self->frame++;
        self->frame &= 31;
    } else {
        DrawSprite_Frame(self->frame);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
