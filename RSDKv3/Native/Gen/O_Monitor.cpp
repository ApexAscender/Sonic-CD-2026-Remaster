#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Monitor.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from Monitor.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Monitor::ObjectStartup()
{
    LoadSpriteSheet("Global/Items.gif");
    AddSpriteFrame(-16, -16, 32, 32, 51, 67);
    AddSpriteFrame(-16, -16, 32, 32, 18, 1);
    AddSpriteFrame(-16, -16, 32, 32, 18, 34);
    AddSpriteFrame(-16, -16, 32, 32, 18, 67);
    AddSpriteFrame(-16, -16, 32, 32, 18, 100);
    AddSpriteFrame(-16, -16, 32, 32, 18, 133);
    AddSpriteFrame(-16, -16, 32, 32, 18, 166);
    AddSpriteFrame(-16, -16, 32, 32, 51, 100);
    AddSpriteFrame(-16, -16, 32, 32, 51, 133);
    AddSpriteFrame(-16, -16, 32, 32, 51, 1);
    AddSpriteFrame(-16, -16, 32, 32, 51, 34);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Monitor")) {
            if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue > 9) {
                objectEntityList[scriptEng.arrayPosition[0]].propertyValue -= 10;
                objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 1;
                objectEntityList[scriptEng.arrayPosition[0]].values[2] = 1;
            }
        }
        scriptEng.arrayPosition[0]++;
    }
    if (playerListPos == 1) {
        scriptEng.arrayPosition[0] = 32;
        while (scriptEng.arrayPosition[0] < 1056) {
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Monitor")) {
                if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 5) {
                    objectEntityList[scriptEng.arrayPosition[0]].propertyValue = 7;
                }
            }
            scriptEng.arrayPosition[0]++;
        }
    }
    if (GVar("Options.GameMode") == 2) {
        scriptEng.arrayPosition[0] = 32;
        while (scriptEng.arrayPosition[0] < 1056) {
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Monitor")) {
                if (objectEntityList[scriptEng.arrayPosition[0]].propertyValue == 5) {
                    objectEntityList[scriptEng.arrayPosition[0]].type = TypeNameID("Blank Object");
                }
            }
            scriptEng.arrayPosition[0]++;
        }
    }
}

void O_Monitor::ObjectMain()
{
    Entity *self = Self();

    if (self->state == 1) {
        self->values[1] += 0x3800;
        self->YPos += self->values[1];
        if (self->values[1] >= 0) {
            ObjectTileCollision_Script(0, 0, 16, 0);
            if (CheckResult() == 1) {
                self->values[1] = 0;
                self->state = 0;
            }
        }
    }
}

void O_Monitor::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (pCollisionPlane() == self->values[2]) {
        scriptEng.tempValue[0] = 0;
        if (pGravity() == 1) {
            if (pYVel() < 0) {
                scriptEng.tempValue[0] = 1;
            }
        }
        if (scriptEng.tempValue[0] == 0) {
            CheckResult() = 0;
            if (pAnimation() == GVar("ANI_JUMPING")) {
                CheckResult() = 1;
            }
            if (CheckResult() == 1) {
                PlayerObjectCollision(C_TOUCH, -16, -14, 16, 16);
                if (CheckResult() == 1) {
                    self->state = 0;
                    CreateTempObject(TypeNameID("Smoke Puff"), 0, self->XPos, self->YPos);
                    objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
                    pYVel() = -pYVel();
                    if (pYVel() > -0x20000) {
                        pYVel() = -0x20000;
                    }
                    self->type = TypeNameID("Broken Monitor");
                    self->priority = 1;
                    self->alpha = 255;
                    self->values[0] = self->YPos;
                    self->values[1] = -0x30000;
                    PlaySfx(8, 0);
                    HapticEffect_Script(16, 0, 0, 0);
                }
            } else {
                PlayerObjectCollision(C_BOX, -15, -14, 15, 16);
            }
        } else {
            PlayerObjectCollision(C_BOX, -15, -16, 15, 16);
            if (CheckResult() == 4) {
                self->state = 1;
                self->values[1] = -0x20000;
                pYVel() = 0x20000;
            }
        }
    }
}

void O_Monitor::ObjectDraw()
{
    Entity *self = Self();

    self->frame++;
    if (self->frame > 17) {
        self->frame = 0;
    }
    switch (self->frame) {
        case 0:
        case 1:
        DrawSprite_Frame(0);
        break;
        case 6:
        case 7:
        DrawSprite_Frame(9);
        break;
        case 12:
        case 13:
        DrawSprite_Frame(10);
        break;
        default:
        DrawSprite_Frame(self->propertyValue);
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
