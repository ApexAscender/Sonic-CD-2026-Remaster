#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_Boss_Bumper.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Boss_Bumper.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_Boss_Bumper::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects3.gif");
    AddSpriteFrame(-14, -16, 24, 32, 99, 26);
    AddSpriteFrame(-18, -16, 24, 32, 99, 26);
    AddSpriteFrame(-18, -16, 24, 32, 99, 26);
}

void O_R1_Boss_Bumper::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->state = 1;
        case 1:
        scriptEng.arrayPosition[0] = self->values[0];
        self->XPos = objectEntityList[scriptEng.arrayPosition[0]].XPos;
        self->XPos -= 0x130000;
        self->YPos = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        if (objectEntityList[scriptEng.arrayPosition[0]].frame != 0) {
            if (objectEntityList[scriptEng.arrayPosition[0]].frame == 1) {
                self->XPos += 0x80000;
            } else {
                self->XPos += 0x100000;
            }
        }
        break;
        case 2:
        self->values[2] -= 0x500;
        self->XPos += self->values[2];
        self->values[5] += 0x1800;
        self->YPos += self->values[5];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
            self->priority = 0;
        }
        break;
    }
}

void O_R1_Boss_Bumper::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 2) {
        if (pAnimation() != GVar("ANI_HURT")) {
            scriptEng.arrayPosition[0] = self->values[0];
            if (objectEntityList[scriptEng.arrayPosition[0]].frame == 0) {
                PlayerObjectCollision(C_TOUCH, -10, -16, 14, 16);
                if (CheckResult() == 1) {
                    pSpeed() = -0x40000;
                    pXVel() = -0x40000;
                    if (self->frame == 0) {
                        PlaySfx(11, 0);
                    }
                    self->frame = 2;
                    HapticEffect_Script(10, 0, 0, 0);
                }
            }
        }
    }
}

void O_R1_Boss_Bumper::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->frame);
    if (self->frame > 0) {
        self->frame--;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
