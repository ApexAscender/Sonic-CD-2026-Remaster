#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_Players_TailsObject.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TailsObject.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_Players_TailsObject::ObjectStartup()
{
    if (playerListPos == 1) {
        LoadSpriteSheet("Players/Tails1.gif");
        objectEntityList[1].type = TypeNameID("Tails Object");
        objectEntityList[1].drawOrder = 8;
        objectEntityList[1].priority = 1;
        AddSpriteFrame(-22, -8, 16, 24, 82, 199);
        AddSpriteFrame(-26, -8, 20, 24, 99, 199);
        AddSpriteFrame(-26, -8, 20, 24, 120, 199);
        AddSpriteFrame(-26, -8, 20, 24, 141, 199);
        AddSpriteFrame(-26, -8, 20, 24, 162, 199);
        AddSpriteFrame(-35, -8, 24, 16, 231, 166);
        AddSpriteFrame(-35, -8, 24, 16, 231, 183);
        AddSpriteFrame(-35, -8, 24, 16, 231, 200);
        AddSpriteFrame(-25, 9, 20, 16, 235, 217);
        AddSpriteFrame(-25, 9, 18, 16, 237, 234);
        AddSpriteFrame(-25, 9, 20, 16, 216, 234);
        AddSpriteFrame(-30, -6, 24, 16, 231, 166);
        AddSpriteFrame(-30, -6, 24, 16, 231, 183);
        AddSpriteFrame(-30, -6, 24, 16, 231, 200);
    }
}

void O_Players_TailsObject::ObjectMain()
{
    scriptEng.arrayPosition[0] = PlrEntity()->drawOrder;
    drawListEntries[scriptEng.arrayPosition[0]].listSize = 2;
    scriptEng.tempValue[0] = drawListEntries[scriptEng.arrayPosition[0]].entityRefs[0];
    drawListEntries[scriptEng.arrayPosition[0]].entityRefs[0] = objectLoop;
    drawListEntries[scriptEng.arrayPosition[0]].entityRefs[1] = scriptEng.tempValue[0];
}

void O_Players_TailsObject::ObjectDraw()
{
    Entity *self = Self();

    if (self->values[1] != pAnimation()) {
        if (pAnimation() > 4) {
            self->frame = 0;
        }
        if (self->values[1] > 4) {
            self->frame = 0;
        }
        self->values[1] = pAnimation();
    }
    self->direction = pDirection();
    switch (self->values[1]) {
        case 0:
        if (pFrame() == 0) {
            scriptEng.tempValue[0] = self->frame;
            scriptEng.tempValue[0] >>= 3;
            if (pVisible() == 1) {
                DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, pXPos(), pYPos());
            }
            self->frame++;
            self->frame %= 40;
        }
        break;
        case 1:
        case 3:
        case 4:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 3;
        if (pVisible() == 1) {
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, pXPos(), pYPos());
        }
        self->frame++;
        self->frame %= 40;
        break;
        case 7:
        case 9:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 2;
        scriptEng.tempValue[0] += 11;
        if (pVisible() == 1) {
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, pXPos(), pYPos());
        }
        self->frame++;
        self->frame %= 12;
        break;
        case 10:
        case 43:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] >>= 2;
        CheckResult() = (pXVel() == 0);
        scriptEng.tempValue[1] = CheckResult();
        CheckResult() = (pYVel() == 0);
        scriptEng.tempValue[1] &= CheckResult();
        if (scriptEng.tempValue[1] == 0) {
            self->rotation = ArcTanLookup(pXVel(), pYVel());
            self->rotation += 16;
            self->rotation &= 255;
            self->rotation >>= 5;
            switch (self->rotation) {
                case 0:
                case 8:
                scriptEng.tempValue[0] += 5;
                self->rotation = 0;
                break;
                case 1:
                scriptEng.tempValue[0] += 8;
                if (self->direction == 0) {
                    self->rotation = 64;
                } else {
                    self->rotation = 0;
                }
                break;
                case 2:
                scriptEng.tempValue[0] += 5;
                self->rotation = 64;
                break;
                case 3:
                scriptEng.tempValue[0] += 8;
                if (self->direction == 0) {
                    self->rotation = 128;
                } else {
                    self->rotation = 64;
                }
                break;
                case 4:
                scriptEng.tempValue[0] += 5;
                self->rotation = 128;
                break;
                case 5:
                scriptEng.tempValue[0] += 8;
                if (self->direction == 0) {
                    self->rotation = 192;
                } else {
                    self->rotation = 128;
                }
                break;
                case 6:
                scriptEng.tempValue[0] += 5;
                self->rotation = 192;
                break;
                case 7:
                scriptEng.tempValue[0] += 8;
                if (self->direction == 0) {
                    self->rotation = 0;
                } else {
                    self->rotation = 192;
                }
                break;
            }
            if (self->direction == 1) {
                self->rotation += 128;
            }
        } else {
            scriptEng.tempValue[0] += 5;
            self->rotation = 0;
        }
        self->rotation <<= 1;
        if (pVisible() == 1) {
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_ROTATE, pXPos(), pYPos());
        }
        self->frame++;
        self->frame %= 12;
        break;
        case 17:
        scriptEng.tempValue[0] = self->frame;
        scriptEng.tempValue[0] /= 10;
        scriptEng.tempValue[0] += 11;
        if (pVisible() == 1) {
            DrawSpriteFX_Script(scriptEng.tempValue[0], FX_FLIP, pXPos(), pYPos());
        }
        self->frame++;
        self->frame %= 30;
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
