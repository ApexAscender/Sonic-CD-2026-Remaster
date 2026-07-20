#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R8_BossCurtain.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossCurtain.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R8_BossCurtain::ObjectStartup()
{
    LoadSpriteSheet("R8/Objects2.gif");
    AddSpriteFrame(-8, -96, 16, 32, 134, 187);
    AddSpriteFrame(-8, -64, 16, 32, 134, 187);
    AddSpriteFrame(-8, -32, 16, 32, 134, 187);
    AddSpriteFrame(-8, 0, 16, 32, 134, 187);
    AddSpriteFrame(-8, 32, 16, 32, 134, 187);
    AddSpriteFrame(-8, 64, 16, 32, 134, 187);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Boss Curtain")) {
            objectEntityList[scriptEng.arrayPosition[0]].direction = 1;
            objectEntityList[scriptEng.arrayPosition[0]].drawOrder = 2;
            objectEntityList[scriptEng.arrayPosition[0]].alpha = 224;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] -= 0x80000;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].XPos;
            objectEntityList[scriptEng.arrayPosition[0]].values[2] += 0x80000;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R8_BossCurtain::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        if (pXPos() > self->XPos) {
            if (objectEntityList[24].propertyValue > 1) {
                if (GVar("Options.Soundtrack") == 0) {
                    SetMusicTrack_Script("JP/FinalBoss.ogg", 4, 1);
                } else {
                    SetMusicTrack_Script("US/FinalBoss.ogg", 4, 1);
                }
            }
            self->state++;
        }
        break;
        case 1:
        if (self->values[0] < 240) {
            self->values[0]++;
            if (self->values[0] == 140) {
                CreateTempObject(TypeNameID("Fade Music"), 0, self->XPos, self->YPos);
            }
        } else {
            self->values[0] = 0;
            objectEntityList[19].values[1] = 0;
            scriptEng.arrayPosition[0] = objectLoop;
            scriptEng.arrayPosition[0] -= 3;
            objectEntityList[objectLoop - 3].type = TypeNameID("Egg Mobile");
            objectEntityList[objectLoop - 7].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 7].values[7] = scriptEng.arrayPosition[0];
            objectEntityList[objectLoop - 6].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 6].values[7] = scriptEng.arrayPosition[0];
            objectEntityList[objectLoop - 5].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 5].values[7] = scriptEng.arrayPosition[0];
            objectEntityList[objectLoop - 4].type = TypeNameID("Boss Wing");
            objectEntityList[objectLoop - 4].values[7] = scriptEng.arrayPosition[0];
            objectEntityList[objectLoop - 2].values[0] = 4;
            objectEntityList[objectLoop - 2].values[6] = self->XPos;
            objectEntityList[objectLoop - 2].values[4] = self->XPos;
            objectEntityList[objectLoop - 2].values[4] -= 0x7C0000;
            objectEntityList[objectLoop - 2].values[5] = self->XPos;
            objectEntityList[objectLoop - 2].values[5] += 0x7C0000;
            objectEntityList[objectLoop - 3].values[4] = 0x1000;
            objectEntityList[objectLoop - 2].values[1] = ScriptFuncID("Helper1Controller_FourWings");
            objectEntityList[objectLoop - 1].values[6] = xBoundary2;
            self->state++;
        }
        break;
        case 2:
        if (self->alpha > 0) {
            self->alpha -= 4;
        }
        self->values[1] -= 0x20000;
        self->values[2] += 0x20000;
        scriptEng.tempValue[1] = self->values[1];
        scriptEng.tempValue[1] >>= 16;
        scriptEng.tempValue[1] += 7;
        scriptEng.tempValue[3] = self->values[2];
        scriptEng.tempValue[3] >>= 16;
        scriptEng.tempValue[3] -= 7;
        scriptEng.tempValue[2] = (objectEntityList[objectLoop].YPos >> 16);
        scriptEng.tempValue[2] -= 92;
        scriptEng.tempValue[0] = 0;
        while (scriptEng.tempValue[0] < 12) {
            Set16x16TileInfo_Script(0, scriptEng.tempValue[1], scriptEng.tempValue[2], 0);
            scriptEng.tempValue[1] -= 16;
            Set16x16TileInfo_Script(395, scriptEng.tempValue[1], scriptEng.tempValue[2], 0);
            scriptEng.tempValue[1] += 16;
            Set16x16TileInfo_Script(0, scriptEng.tempValue[3], scriptEng.tempValue[2], 0);
            scriptEng.tempValue[3] += 16;
            Set16x16TileInfo_Script(395, scriptEng.tempValue[3], scriptEng.tempValue[2], 0);
            scriptEng.tempValue[3] -= 16;
            scriptEng.tempValue[2] += 16;
            scriptEng.tempValue[0]++;
        }
        if (self->values[0] < 120) {
            self->values[0]++;
        } else {
            self->values[0] = 0;
            self->state++;
            if (SCREEN_XSIZE > 320) {
                ResetObjectEntity(objectLoop, TypeNameID("Forcefield"), 240, self->XPos, self->YPos);
            } else {
                ResetObjectEntity(objectLoop, TypeNameID("Blank Object"), 0, self->XPos, self->YPos);
            }
        }
        break;
    }
}

void O_R8_BossCurtain::ObjectPlayerInteraction()
{
    scriptEng.tempValue[0] = pCollisionRight();
    scriptEng.tempValue[0] <<= 16;
    scriptEng.tempValue[0] += pXPos();
    scriptEng.tempValue[1] = xBoundary2;
    scriptEng.tempValue[1] <<= 16;
    if (scriptEng.tempValue[0] > scriptEng.tempValue[1]) {
        pXVel() = 0;
        pSpeed() = 0;
        pXPos() = scriptEng.tempValue[1];
        scriptEng.tempValue[0] = pCollisionRight();
        scriptEng.tempValue[0] <<= 16;
        pXPos() -= scriptEng.tempValue[0];
    }
}

void O_R8_BossCurtain::ObjectDraw()
{
    Entity *self = Self();

    if (self->drawOrder == 2) {
        DrawRectangle(0, 0, SCREEN_XSIZE, SCREEN_YSIZE, 0, 0, 0, self->alpha);
        drawListEntries[3].entityRefs[drawListEntries[3].listSize] = objectLoop;
        drawListEntries[3].listSize++;
        self->drawOrder = 3;
    } else {
        scriptEng.tempValue[0] = 0;
        while (scriptEng.tempValue[0] < 6) {
            DrawSprite_FrameXY(scriptEng.tempValue[0], self->values[1], self->YPos);
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, self->values[2], self->YPos);
            scriptEng.tempValue[0]++;
        }
        self->drawOrder = 2;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
