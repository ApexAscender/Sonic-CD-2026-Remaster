#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_BossBomb.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossBomb.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_BossBomb::ObjectStartup()
{
    LoadSpriteSheet("R5/Objects2.gif");
    AddSpriteFrame(-12, -12, 24, 24, 75, 113);
    AddSpriteFrame(-8, -8, 16, 16, 131, 138);
}

void O_R5_BossBomb::ObjectMain()
{
    Entity *self = Self();

    if (self->propertyValue == 0) {
        if (self->state == 1) {
            self->YPos += 0x20000;
            ObjectTileCollision_Script(0, 0, 10, 0);
            if (CheckResult() == 1) {
                if (self->values[0] < 4) {
                    self->values[0]++;
                } else {
                    PlaySfx(globalSFXCount + 4, 0);
                    CreateTempObject(TypeNameID("Boss Bomb"), 1, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0xA000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x3000;
                    CreateTempObject(TypeNameID("Boss Bomb"), 1, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos -= 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0xA000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x3000;
                    CreateTempObject(TypeNameID("Boss Bomb"), 1, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = -0x14000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x24000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x1800;
                    CreateTempObject(TypeNameID("Boss Bomb"), 1, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].XPos += 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].YPos += 0x40000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[1] = 0x14000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[2] = -0x24000;
                    objectEntityList[scriptEng.arrayPosition[2]].values[3] = 0x1800;
                    self->state = 0;
                    self->values[0] = 0;
                    self->XPos = objectEntityList[objectLoop + 2].XPos;
                    self->YPos = objectEntityList[objectLoop + 2].YPos;
                    HapticEffect_Script(77, 0, 0, 0);
                }
            }
        }
    } else {
        self->XPos += self->values[1];
        self->values[2] += self->values[3];
        self->YPos += self->values[2];
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->type = TypeNameID("Blank Object");
        }
    }
}

void O_R5_BossBomb::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state == 1) {
        PlayerObjectCollision(C_TOUCH, -10, -10, 10, 10);
        if (CheckResult() == 1) {
            if (objectEntityList[0].values[0] == 0) {
                self->state = 0;
                CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
                self->XPos = objectEntityList[objectLoop + 2].XPos;
                self->YPos = objectEntityList[objectLoop + 2].YPos;
                PlaySfx(22, 0);
            }
            CallScriptFunctionNamed("Player_Hit", scriptSub);
            if (pState() == PlayerStateID("Player_State_GotHit")) {
                objectEntityList[objectLoop + 5].values[3] = 0xC000;
            }
        }
    } else {
        if (self->propertyValue == 1) {
            PlayerObjectCollision(C_TOUCH, -7, -7, 7, 7);
            if (CheckResult() == 1) {
                if (objectEntityList[0].values[0] == 0) {
                    self->state = 0;
                    CreateTempObject(TypeNameID("Explosion"), 0, self->XPos, self->YPos);
                    self->type = TypeNameID("Blank Object");
                    PlaySfx(22, 0);
                }
                CallScriptFunctionNamed("Player_Hit", scriptSub);
            }
        }
    }
}

void O_R5_BossBomb::ObjectDraw()
{
    Entity *self = Self();

    DrawSprite_Frame(self->propertyValue);
}

#endif // RETRO_USE_NATIVE_OBJECTS
