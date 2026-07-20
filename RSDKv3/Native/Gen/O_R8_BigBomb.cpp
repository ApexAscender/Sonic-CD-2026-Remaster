#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_BigBomb.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BigBomb.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_BigBomb::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-20, -20, 40, 40, 67, 82);
    AddSpriteFrame(-27, 3, 48, 24, 109, 35);
    AddSpriteFrame(-4, -44, 8, 24, 176, 18);
    AddSpriteFrame(-20, -22, 40, 40, 67, 82);
    AddSpriteFrame(-12, 3, 32, 24, 150, 85);
    AddSpriteFrame(-4, -46, 8, 24, 176, 18);
    AddSpriteFrame(-20, -20, 40, 40, 67, 82);
    AddSpriteFrame(-27, 3, 48, 24, 109, 35);
    AddSpriteFrame(-4, -44, 8, 24, 176, 18);
    AddSpriteFrame(-20, -22, 40, 40, 67, 82);
    AddSpriteFrame(-20, 3, 48, 24, 109, 60);
    AddSpriteFrame(-4, -46, 8, 24, 176, 18);
    AddSpriteFrame(-20, -20, 40, 40, 67, 82);
    AddSpriteFrame(-20, 3, 40, 24, 109, 85);
    AddSpriteFrame(-4, -44, 8, 24, 176, 18);
    AddSpriteFrame(-4, -44, 8, 24, 158, 18);
    AddSpriteFrame(-4, -44, 8, 24, 167, 18);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("BigBomb")) {
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_BigBomb::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        self->priority = 1;
        ObjectTileCollision_Script(0, 0, 27, 0);
        if (CheckResult() == 1) {
            if (self->propertyValue == 1) {
                self->state = 3;
                self->direction = 1;
                self->animation = 0;
            } else {
                self->state = 1;
                self->animation = 1;
                self->values[3] = self->XPos;
                self->values[3] -= 0xC0000;
                self->values[4] = self->XPos;
                self->values[4] += 0xC0000;
            }
        } else {
            self->YPos += 0x10000;
        }
        break;
        case 1:
        self->XPos -= 0xA000;
        if (self->XPos < self->values[3]) {
            self->direction = 1;
            self->state = 2;
        }
        ObjectTileGrip_Script(0, 0, 27, 0);
        PlayerObjectCollision(C_TOUCH, -96, -128, 96, 27);
        if (CheckResult() == 1) {
            self->state = 5;
            self->animation = 2;
        }
        break;
        case 2:
        self->XPos += 0xA000;
        if (self->XPos > self->values[4]) {
            self->direction = 0;
            self->state = 1;
        }
        ObjectTileGrip_Script(0, 0, 27, 0);
        PlayerObjectCollision(C_TOUCH, -96, -128, 96, 27);
        if (CheckResult() == 1) {
            self->state = 5;
            self->animation = 2;
        }
        break;
        case 3:
        PlayerObjectCollision(C_TOUCH, -96, -128, 96, 27);
        if (CheckResult() == 1) {
            self->animation = 1;
            self->state++;
        }
        break;
        case 4:
        self->XPos += 0x20000;
        ObjectTileGrip_Script(0, 24, 27, 0);
        if (CheckResult() == 0) {
            self->state = 5;
            self->animation = 2;
        }
        break;
        case 5:
        if (self->values[0] < 30) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->animation = 3;
            self->animationTimer = 0;
            self->values[5] = self->YPos;
            self->state++;
        }
        break;
        case 6:
        if (self->values[0] < 120) {
            self->values[0]++;
            self->values[5] += 0x4000;
        } else {
            CreateTempObject(TypeNameID("BB Fireball"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x30000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x62000;
            CreateTempObject(TypeNameID("BB Fireball"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x52000;
            CreateTempObject(TypeNameID("BB Fireball"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x42000;
            CreateTempObject(TypeNameID("BB Fireball"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x32000;
            CreateTempObject(TypeNameID("BB Fireball"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x10000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x42000;
            CreateTempObject(TypeNameID("BB Fireball"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x20000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x52000;
            CreateTempObject(TypeNameID("BB Fireball"), 0, self->XPos, self->YPos);
            objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x30000;
            objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x62000;
            CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
            ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, 0, 0);
            PlaySfx(globalSFXCount + 5, 0);
            HapticEffect_Script(77, 0, 0, 0);
        }
        break;
    }
}

void O_R8_BigBomb::ObjectPlayerInteraction()
{
    if (pCollisionPlane() == 0) {
        PlayerObjectCollision(C_TOUCH, -18, -18, 18, 18);
        if (CheckResult() == 1) {
            CallScriptFunctionNamed("Player_Hit", scriptSub);
        }
    }
}

void O_R8_BigBomb::ObjectDraw()
{
    Entity *self = Self();

    switch (self->animation) {
        case 0:
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(2, FX_FLIP, self->XPos, self->YPos);
        break;
        case 1:
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] /= 20;
        scriptEng.tempValue[0] *= 3;
        scriptEng.tempValue[0] += 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0]++;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0]++;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        self->animationTimer++;
        self->animationTimer %= 80;
        break;
        case 2:
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] /= 20;
        scriptEng.tempValue[0] *= 3;
        scriptEng.tempValue[0] += 3;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0]++;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        scriptEng.tempValue[0]++;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->YPos);
        break;
        case 3:
        scriptEng.tempValue[0] = self->animationTimer;
        scriptEng.tempValue[0] /= 3;
        scriptEng.tempValue[0] += 15;
        DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->XPos, self->values[5]);
        self->animationTimer++;
        self->animationTimer %= 6;
        DrawSpriteFX_Script(0, FX_FLIP, self->XPos, self->YPos);
        DrawSpriteFX_Script(1, FX_FLIP, self->XPos, self->YPos);
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
