#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_LittlePlanet.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from LittlePlanet.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_LittlePlanet::ObjectStartup()
{
    LoadSpriteSheet("DAGarden/LittlePlanet.gif");
    AddSpriteFrame(-126, -126, 252, 252, 0, 0);
    AddSpriteFrame(95, -70, 16, 16, 256, 257);
    AddSpriteFrame(91, -75, 24, 24, 256, 274);
    AddSpriteFrame(92, -88, 32, 32, 256, 299);
    AddSpriteFrame(86, -92, 40, 40, 256, 332);
    AddSpriteFrame(85, -94, 40, 40, 256, 373);
    AddSpriteFrame(76, -90, 16, 16, 273, 257);
    AddSpriteFrame(75, -97, 24, 24, 281, 274);
    AddSpriteFrame(73, -104, 32, 32, 289, 299);
    AddSpriteFrame(76, -107, 32, 32, 297, 332);
    AddSpriteFrame(75, -110, 32, 32, 297, 365);
    AddSpriteFrame(-126, -126, 252, 252, 256, 0);
    AddSpriteFrame(95, -70, 16, 16, 330, 257);
    AddSpriteFrame(91, -75, 24, 24, 330, 274);
    AddSpriteFrame(92, -88, 32, 32, 330, 299);
    AddSpriteFrame(86, -92, 40, 40, 330, 332);
    AddSpriteFrame(85, -94, 40, 40, 330, 373);
    AddSpriteFrame(76, -90, 16, 16, 347, 257);
    AddSpriteFrame(75, -97, 24, 24, 355, 274);
    AddSpriteFrame(73, -104, 32, 32, 363, 299);
    AddSpriteFrame(76, -107, 32, 32, 371, 332);
    AddSpriteFrame(75, -110, 32, 32, 371, 365);
    AddSpriteFrame(-126, -126, 252, 252, 0, 256);
    AddSpriteFrame(95, -70, 16, 16, 404, 257);
    AddSpriteFrame(91, -75, 24, 24, 404, 274);
    AddSpriteFrame(92, -88, 32, 32, 404, 299);
    AddSpriteFrame(86, -92, 40, 40, 404, 332);
    AddSpriteFrame(85, -94, 40, 40, 404, 373);
    AddSpriteFrame(76, -90, 16, 16, 421, 257);
    AddSpriteFrame(75, -97, 24, 24, 429, 274);
    AddSpriteFrame(73, -104, 32, 32, 437, 299);
    AddSpriteFrame(76, -107, 32, 32, 445, 332);
    AddSpriteFrame(75, -110, 32, 32, 445, 365);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Little Planet")) {
            objectEntityList[scriptEng.arrayPosition[0]].XPos = 0;
            objectEntityList[scriptEng.arrayPosition[0]].YPos = 0;
            objectEntityList[scriptEng.arrayPosition[0]].values[1] = 384;
            objectEntityList[scriptEng.arrayPosition[0]].values[3] = -8;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_DAGarden_LittlePlanet::ObjectMain()
{
    Entity *self = Self();

    if (objectEntityList[0].state == 2) {
        if (keyDown.left == 1) {
            if (self->XPos > -0x400) {
                self->XPos--;
            }
        }
        if (keyDown.right == 1) {
            if (self->XPos < 0x400) {
                self->XPos++;
            }
        }
        if (keyDown.up == 1) {
            self->YPos--;
        }
        if (keyDown.down == 1) {
            self->YPos++;
        }
        if (keyDown.start == 1) {
            if (self->values[4] == 1) {
                if (self->values[3] < 256) {
                    self->values[3] += 2;
                }
            } else {
                if (self->values[3] > -256) {
                    self->values[3] -= 2;
                }
            }
        }
        if (keyPress.start == 1) {
            self->values[4]++;
            self->values[4] &= 1;
            self->values[3] = 0;
        }
        if (keyDown.C == 1) {
            if (self->values[5] == 0) {
                if (self->values[1] < 0x4000) {
                    self->values[1] += 8;
                }
            } else {
                if (self->values[1] > 48) {
                    self->values[1] -= 8;
                }
            }
        }
        if (keyPress.C == 1) {
            self->values[5]++;
            self->values[5] &= 1;
        }
        CheckTouchRect_Script(0, 32, SCREEN_XSIZE, 208);
        if (CheckResult() > -1) {
            if (self->values[7] != CheckResult()) {
                self->values[6] = 0;
            }
            scriptEng.arrayPosition[0] = CheckResult();
            if (self->values[6] == 0) {
                self->values[6] = 1;
                self->values[7] = CheckResult();
                objectEntityList[0].XPos = touchX[scriptEng.arrayPosition[0]];
                objectEntityList[0].YPos = touchY[scriptEng.arrayPosition[0]];
                objectEntityList[1].XPos = self->XPos;
                objectEntityList[1].YPos = self->YPos;
            } else {
                scriptEng.tempValue[0] = touchX[scriptEng.arrayPosition[0]];
                scriptEng.tempValue[0] -= objectEntityList[0].XPos;
                scriptEng.tempValue[0] *= self->values[1];
                scriptEng.tempValue[0] >>= 11;
                scriptEng.tempValue[0] += objectEntityList[1].XPos;
                scriptEng.tempValue[1] = scriptEng.tempValue[0];
                scriptEng.tempValue[1] -= self->XPos;
                if (scriptEng.tempValue[1] < 0) {
                    scriptEng.tempValue[1] = -scriptEng.tempValue[1];
                }
                if (scriptEng.tempValue[1] < 14) {
                    self->XPos = scriptEng.tempValue[0];
                }
                scriptEng.tempValue[0] = touchY[scriptEng.arrayPosition[0]];
                scriptEng.tempValue[0] -= objectEntityList[0].YPos;
                scriptEng.tempValue[0] *= self->values[1];
                scriptEng.tempValue[0] >>= 11;
                scriptEng.tempValue[0] += objectEntityList[1].YPos;
                scriptEng.tempValue[1] = scriptEng.tempValue[0];
                scriptEng.tempValue[1] -= self->YPos;
                if (scriptEng.tempValue[1] < 0) {
                    scriptEng.tempValue[1] = -scriptEng.tempValue[1];
                }
                if (scriptEng.tempValue[1] < 14) {
                    self->YPos = scriptEng.tempValue[0];
                }
            }
        } else {
            self->values[6] = 0;
        }
    }
    self->values[2] += self->values[3];
    if (self->values[2] < 0) {
        self->values[2] += 0x2000;
    }
    self->values[2] &= 0x1FFF;
    self->rotation = self->values[2];
    self->rotation >>= 4;
}

void O_DAGarden_LittlePlanet::ObjectDraw()
{
    Entity *self = Self();

    if (self->frame == 22) {
        DrawRectangle(0, 32, SCREEN_XSIZE, 176, 64, 64, 32, 176);
    }
    if (self->values[1] > 0) {
        scriptEng.tempValue[0] = self->XPos;
        scriptEng.tempValue[0] <<= 11;
        scriptEng.tempValue[0] /= self->values[1];
        scriptEng.tempValue[0] += SCREEN_CENTERX;
        scriptEng.tempValue[1] = self->YPos;
        scriptEng.tempValue[1] <<= 11;
        scriptEng.tempValue[1] /= self->values[1];
        scriptEng.tempValue[1] += 120;
        self->scale = 0x20000;
        self->scale /= self->values[1];
        DrawSpriteScreenFX_Script(self->frame, FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
        scriptEng.tempValue[2] = self->animationTimer;
        scriptEng.tempValue[2] >>= 3;
        scriptEng.tempValue[3] = self->frame;
        switch (scriptEng.tempValue[2]) {
            case 0:
            scriptEng.tempValue[3]++;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
            case 1:
            scriptEng.tempValue[3] += 2;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
            case 2:
            scriptEng.tempValue[3] += 3;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
            case 3:
            scriptEng.tempValue[3] += 4;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
            case 4:
            scriptEng.tempValue[3] += 5;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
            case 24:
            scriptEng.tempValue[3] += 6;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
            case 25:
            scriptEng.tempValue[3] += 7;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
            case 26:
            scriptEng.tempValue[3] += 8;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
            case 27:
            scriptEng.tempValue[3] += 9;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
            case 28:
            scriptEng.tempValue[3] += 10;
            DrawSpriteScreenFX_Script(scriptEng.tempValue[3], FX_ROTOZOOM, scriptEng.tempValue[0], scriptEng.tempValue[1]);
            break;
        }
        self->animationTimer++;
        self->animationTimer &= 511;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
