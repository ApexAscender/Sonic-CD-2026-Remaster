#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R3_PinballBomb.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from PinballBomb.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R3_PinballBomb::ObjectStartup()
{
    LoadSpriteSheet("R3/Objects2.gif");
    AddSpriteFrame(-12, -12, 24, 24, 232, 0);
    AddSpriteFrame(-8, -8, 16, 16, 130, 67);
}

void O_R3_PinballBomb::ObjectMain()
{
    Entity *self = Self();

    self->values[2] += 0x2000;
    if (self->values[2] > 0x40000) {
        self->drawOrder = 3;
    }
    self->XPos += self->values[1];
    self->YPos += self->values[2];
    self->values[0]++;
    self->values[0] &= 3;
    if (self->values[1] > 0) {
        ObjectTileCollision_Script(1, 8, 0, 0);
    } else {
        ObjectTileCollision_Script(2, -8, 0, 0);
    }
    if (CheckResult() == 1) {
        self->values[1] = -self->values[1];
    }
    ObjectTileCollision_Script(0, 0, 8, 0);
    if (CheckResult() == 1) {
        self->values[2] = -self->values[2];
        self->values[2] >>= 1;
        if (self->values[3] < 1) {
            self->values[3]++;
        } else {
            PlaySfx(22, 0);
            ResetObjectEntity(objectLoop, TypeNameID("Explosion"), 0, self->XPos, self->YPos);
        }
    }
}

void O_R3_PinballBomb::ObjectPlayerInteraction()
{
    Entity *self = Self();

    PlayerObjectCollision(C_TOUCH, -8, -8, 8, 8);
    if (CheckResult() == 1) {
        PlaySfx(22, 0);
        HapticEffect_Script(96, 0, 0, 0);
        ResetObjectEntity(objectLoop, TypeNameID("Explosion"), 0, self->XPos, self->YPos);
        self->priority = 1;
        scriptEng.tempValue[0] = pXPos();
        scriptEng.tempValue[0] -= self->XPos;
        scriptEng.tempValue[1] = pYPos();
        scriptEng.tempValue[1] -= self->YPos;
        scriptEng.tempValue[2] = ArcTanLookup(scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[0] = Cos256(scriptEng.tempValue[2]);
        scriptEng.tempValue[1] = Sin256(scriptEng.tempValue[2]);
        scriptEng.tempValue[0] *= 0x700;
        scriptEng.tempValue[1] *= 0x700;
        pXVel() = scriptEng.tempValue[0];
        pYVel() = scriptEng.tempValue[1];
        pSpeed() = pXVel();
        pGravity() = 1;
        pTimer() = 0;
    }
}

void O_R3_PinballBomb::ObjectDraw()
{
    Entity *self = Self();

    if (self->values[0] == 0) {
        DrawSprite_Frame(0);
    } else {
        DrawSprite_Frame(1);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
