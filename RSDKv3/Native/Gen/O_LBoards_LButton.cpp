#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_LBoards_LButton.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LButton.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_LBoards_LButton::ObjectStartup()
{
    LoadSpriteSheet("LBoards/Leaderboards.gif");
    AddSpriteFrame(0, 0, 64, 20, 135, 34);
    AddSpriteFrame(0, 0, 64, 20, 135, 55);
    AddSpriteFrame(0, 0, 48, 20, 200, 34);
    AddSpriteFrame(0, 0, 48, 20, 200, 55);
    AddSpriteFrame(0, 0, 48, 20, 249, 34);
    AddSpriteFrame(0, 0, 48, 20, 249, 55);
    AddSpriteFrame(0, 0, 24, 32, 223, 92);
    AddSpriteFrame(0, 0, 24, 32, 248, 92);
    AddSpriteFrame(0, 0, 24, 32, 273, 92);
    AddSpriteFrame(0, 0, 24, 32, 298, 92);
}

void O_LBoards_LButton::ObjectMain()
{
    Entity *self = Self();

    if (Engine.message == 2) {
        self->values[1] = 0;
    }
    scriptEng.tempValue[0] = self->XPos;
    scriptEng.tempValue[0] >>= 16;
    scriptEng.tempValue[1] = scriptEng.tempValue[0];
    scriptEng.tempValue[2] = self->YPos;
    scriptEng.tempValue[2] >>= 16;
    scriptEng.tempValue[3] = scriptEng.tempValue[2];
    switch (self->propertyValue) {
        case 0:
        scriptEng.tempValue[1] += 64;
        scriptEng.tempValue[2] -= 8;
        scriptEng.tempValue[3] += 24;
        break;
        case 1:
        scriptEng.tempValue[1] += 48;
        scriptEng.tempValue[2] -= 8;
        scriptEng.tempValue[3] += 24;
        break;
        case 2:
        scriptEng.tempValue[1] += 48;
        scriptEng.tempValue[2] -= 8;
        scriptEng.tempValue[3] += 24;
        break;
        case 3:
        scriptEng.tempValue[0] -= 8;
        scriptEng.tempValue[1] += 32;
        scriptEng.tempValue[2] -= 8;
        scriptEng.tempValue[3] += 40;
        break;
        case 4:
        scriptEng.tempValue[0] -= 8;
        scriptEng.tempValue[1] += 32;
        scriptEng.tempValue[2] -= 8;
        scriptEng.tempValue[3] += 40;
        break;
    }
    if (objectEntityList[0].state == 2) {
        CheckTouchRect_Script(scriptEng.tempValue[0], scriptEng.tempValue[2], scriptEng.tempValue[1], scriptEng.tempValue[3]);
    } else {
        CheckResult() = -1;
    }
    if (CheckResult() > -1) {
        self->values[1] = 1;
    } else {
        CheckTouchRect_Script(0, 0, SCREEN_XSIZE, SCREEN_YSIZE);
        if (CheckResult() < 0) {
            if (self->values[1] == 1) {
                switch (self->propertyValue) {
                    case 0:
                    objectEntityList[0].state = 4;
                    StopMusic();
                    PlaySfx(27, 0);
                    break;
                    case 1:
                    objectEntityList[0].state = 3;
                    objectEntityList[32].state = 10;
                    PlaySfx(23, 0);
                    break;
                    case 2:
                    objectEntityList[0].state = 3;
                    objectEntityList[32].state = 7;
                    PlaySfx(23, 0);
                    break;
                    case 3:
                    objectEntityList[0].state = 3;
                    objectEntityList[32].state = 4;
                    PlaySfx(23, 0);
                    break;
                    case 4:
                    objectEntityList[0].state = 3;
                    objectEntityList[32].state = 1;
                    PlaySfx(23, 0);
                    break;
                }
                self->values[1] = 0;
            }
        } else {
            self->values[1] = 0;
        }
    }
}

void O_LBoards_LButton::ObjectDraw()
{
    Entity *self = Self();

    scriptEng.tempValue[0] = self->propertyValue;
    scriptEng.tempValue[0] <<= 1;
    scriptEng.tempValue[0] += self->values[1];
    DrawSprite_Frame(scriptEng.tempValue[0]);
}

#endif // RETRO_USE_NATIVE_OBJECTS
