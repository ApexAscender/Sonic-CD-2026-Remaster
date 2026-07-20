#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Mission_EggmanSignPost.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from EggmanSignPost.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Mission_EggmanSignPost::ObjectStartup()
{
    LoadSpriteSheet("Global/Items2.gif");
    AddSpriteFrame(-12, -12, 24, 24, 0, 150);
    AddSpriteFrame(-24, -44, 48, 32, 34, 99);
    AddSpriteFrame(-16, -44, 32, 32, 1, 183);
    AddSpriteFrame(-4, -44, 8, 32, 25, 150);
    AddSpriteFrame(-16, -44, 32, 32, 1, 216);
    AddSpriteFrame(-24, -44, 48, 32, 34, 132);
    AddSpriteFrame(-16, -44, 32, 32, 1, 183);
    AddSpriteFrame(-4, -44, 8, 32, 25, 150);
    AddSpriteFrame(-16, -44, 32, 32, 1, 216);
}

void O_Mission_EggmanSignPost::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        scriptEng.arrayPosition[0] = 32;
        while (scriptEng.arrayPosition[0] < 1056) {
            if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Eggman Jetpack")) {
                self->values[3] = scriptEng.arrayPosition[0];
                self->state = 1;
                scriptEng.arrayPosition[0] = 2000;
            }
            scriptEng.arrayPosition[0]++;
        }
        break;
        case 1:
        scriptEng.arrayPosition[0] = self->values[3];
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Blank Object")) {
            self->frame = 1;
            self->values[0] = 16;
            self->state = 2;
            self->priority = 3;
        }
        break;
        case 2:
        self->XPos = xScrollOffset;
        self->XPos += SCREEN_CENTERX;
        self->XPos <<= 16;
        self->YPos = yScrollOffset;
        self->YPos <<= 16;
        self->state = 3;
        break;
        case 3:
        self->YPos += self->values[2];
        self->values[2] += 0xC00;
        ObjectTileCollision_Script(0, 0, 8, 0);
        if (CheckResult() == 1) {
            self->values[0] = 4;
            self->state = 4;
        }
        self->values[1]++;
        if (self->values[1] == 2) {
            self->values[1] = 0;
            self->frame++;
            if (self->frame == 5) {
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x140000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
            if (self->frame == 9) {
                self->frame = 1;
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x140000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
        }
        break;
        case 4:
        masterVolume -= 2;
        self->values[1]++;
        if (self->values[1] == 2) {
            self->values[1] = 0;
            self->frame++;
            if (self->frame == 5) {
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x140000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            }
            if (self->frame == 9) {
                scriptEng.tempValue[0] = rand() % 48;
                scriptEng.tempValue[0] <<= 16;
                scriptEng.tempValue[0] += self->XPos;
                scriptEng.tempValue[0] -= 0x180000;
                scriptEng.tempValue[1] = rand() % 32;
                scriptEng.tempValue[1] <<= 16;
                scriptEng.tempValue[1] += self->YPos;
                scriptEng.tempValue[1] -= 0x140000;
                CreateTempObject(TypeNameID("Ring Sparkle"), 0, scriptEng.tempValue[0], scriptEng.tempValue[1]);
                self->values[0]--;
                if (self->values[0] == 0) {
                    self->frame = 5;
                    self->state = 5;
                } else {
                    self->frame = 1;
                }
            }
        }
        break;
        case 5:
        ResetObjectEntity(self->values[3], TypeNameID("Sign Post"), 0, self->XPos, self->YPos);
        self->values[2] = 1;
        self->frame = 1;
        self->values[0] = 16;
        self->priority = 3;
        self->state = 6;
        break;
        case 6:
        if (objectEntityList[scriptEng.arrayPosition[0]].state == 2) {
            PlayMusic(1);
            self->state = 4;
            objectEntityList[30].type = TypeNameID("ActFinish");
            objectEntityList[30].drawOrder = 6;
            objectEntityList[30].priority = 1;
            self->state = 7;
        }
        break;
        case 7:
        CheckResult() = (pState() == PlayerStateID("Player_State_Ground"));
        scriptEng.tempValue[0] = CheckResult();
        CheckResult() = (PlayerOutOfBounds() == 1);
        scriptEng.tempValue[0] |= CheckResult();
        scriptEng.tempValue[1] = xScrollOffset;
        scriptEng.tempValue[1] += SCREEN_XSIZE;
        scriptEng.tempValue[1] += 32;
        CheckResult() = ((pXPos() >> 16) > scriptEng.tempValue[1]);
        scriptEng.tempValue[0] |= CheckResult();
        if (scriptEng.tempValue[0] == 1) {
            pControlMode() = -1;
            pJumpHold() = 0;
            pRight() = 0;
            pLeft() = 0;
            pUp() = 0;
            pDown() = 0;
            if (pState() == PlayerStateID("Player_State_Ground")) {
                pXVel() = 0;
                pYVel() = 0;
            }
            pSpeed() = 0;
            cameraEnabled = 0;
        }
        break;
    }
}

void O_Mission_EggmanSignPost::ObjectDraw()
{
    Entity *self = Self();

    if (self->state > 2) {
        if (self->state < 5) {
            DrawSprite_Frame(0);
            DrawSprite_Frame(self->frame);
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
