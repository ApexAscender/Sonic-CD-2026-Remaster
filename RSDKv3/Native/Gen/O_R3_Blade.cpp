#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_Blade.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Blade.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_Blade::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects.gif");
    AddSpriteFrame(-8, -8, 16, 16, 198, 68);
    AddSpriteFrame(-8, -8, 16, 16, 215, 68);
    AddSpriteFrame(-8, -8, 16, 16, 232, 68);
    AddSpriteFrame(-8, -8, 16, 16, 198, 85);
    AddSpriteFrame(-8, -8, 16, 16, 215, 85);
    AddSpriteFrame(-8, -8, 16, 16, 232, 85);
}

void O_R3_Blade::ObjectMain()
{
    Entity *self = Self();

    self->XPos += self->values[0];
    self->YPos += self->values[1];
    self->frame++;
    self->frame %= 24;
    switch (self->state) {
        case 0:
        scriptEng.arrayPosition[0] = self->values[2];
        if (objectEntityList[scriptEng.arrayPosition[0]].type != TypeNameID("Kama Kama")) {
            self->type = TypeNameID("Blank Object");
        }
        if (self->propertyValue > 0) {
            self->propertyValue--;
        } else {
            self->state = 1;
            PlaySfx(globalSFXCount + 5, 0);
            if (self->direction == 0) {
                self->values[0] = -0x30000;
            } else {
                self->values[0] = 0x30000;
            }
        }
        break;
        case 2:
        self->values[1] += 0x3000;
        break;
    }
    if (GetObjectOutOfBounds(objectLoop) == 1) {
        self->type = TypeNameID("Blank Object");
    } else {
        scriptEng.tempValue[0] = yScrollOffset;
        scriptEng.tempValue[0] -= 8;
        scriptEng.tempValue[0] <<= 16;
        if (self->YPos < scriptEng.tempValue[0]) {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R3_Blade::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 1) {
        PlayerObjectCollision(C_TOUCH, -8, -6, 8, 6);
        if (CheckResult() == 1) {
            CheckResult() = (pAnimation() == GVar("ANI_JUMPING"));
            scriptEng.tempValue[0] = CheckResult();
            CheckResult() = (pAnimation() == GVar("ANI_SPINDASH"));
            scriptEng.tempValue[0] |= CheckResult();
            if (scriptEng.tempValue[0] == 1) {
                self->state = 2;
                self->values[1] = -0x80000;
                if (self->direction == 0) {
                    if (pXVel() > 0x8000) {
                        self->values[0] = -self->values[0];
                    }
                } else {
                    if (pXVel() < -0x8000) {
                        self->values[0] = -self->values[0];
                    }
                }
            } else {
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
        }
    }
}

void O_R3_Blade::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->frame;
    scriptEng.tempValue[0] >>= 2;
    DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
}

#endif // RETRO_USE_NATIVE_OBJECTS
