#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_BossFloorControl.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from BossFloorControl.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_BossFloorControl::ObjectMain()
{
    Entity *self = Self();

    if (pState() == PlayerStateID("Player_State_Fly")) {
        if (pTimer() < 360) {
            pTimer() = 360;
        }
    }
    scriptEng.tempValue[0] = objectEntityList[objectLoop - 7].YPos;
    scriptEng.tempValue[0] += 0x800000;
    scriptEng.tempValue[0] -= pYPos();
    scriptEng.tempValue[0] >>= 25;
    if (scriptEng.tempValue[0] < self->values[6]) {
        switch (self->values[5]) {
            case 0:
            stageLayouts[0].tiles[20 + 0x100 * 9] = 500;
            stageLayouts[0].tiles[21 + 0x100 * 9] = 501;
            stageLayouts[0].tiles[22 + 0x100 * 9] = 506;
            case 1:
            stageLayouts[0].tiles[20 + 0x100 * 5] = 500;
            stageLayouts[0].tiles[21 + 0x100 * 5] = 501;
            stageLayouts[0].tiles[22 + 0x100 * 5] = 502;
            break;
        }
        self->values[6] = self->values[5];
    }
    switch (self->state) {
        case 1:
        if (self->values[0] < 90) {
            self->values[0]++;
        } else {
            self->values[5] = objectEntityList[objectLoop - 7].YPos;
            self->values[5] -= objectEntityList[objectLoop - 1].YPos;
            self->values[5] >>= 25;
            switch (self->values[5]) {
                case 0:
                self->values[4] = 0x58C0000;
                self->scale = 0;
                break;
                case 1:
                self->values[4] = 0x38C0000;
                self->scale = 0;
                break;
                case 2:
                self->values[4] = 0x18C0000;
                self->scale = 6;
                if (pXPos() > objectEntityList[objectLoop - 1].XPos) {
                    self->values[1] = 0xA00000;
                } else {
                    self->values[1] = -0xA00000;
                }
                break;
            }
            PlaySfx(globalSFXCount + 12, 0);
            HapticEffect_Script(77, 0, 0, 0);
            self->values[0] = 0;
            self->values[3] = 24;
            self->values[7] = 0;
            self->state++;
        }
        break;
        case 2:
        self->values[7]++;
        if (self->values[7] == 128) {
            FloorControl_SpawnPlatFarLeft();
        }
        if (self->values[7] == 148) {
            FloorControl_SpawnPlatLeft();
        }
        if (self->values[7] == 168) {
            FloorControl_SpawnPlatRight();
        }
        if (self->values[7] == 188) {
            FloorControl_SpawnPlatFarRight();
        }
        scriptEng.tempValue[0] = self->values[7];
        scriptEng.tempValue[0] &= 3;
        if (scriptEng.tempValue[0] == 0) {
            cameraShakeY = 2;
        }
        if (self->scale > 0) {
            scriptEng.tempValue[0] = self->values[7];
            scriptEng.tempValue[0] %= 35;
            if (scriptEng.tempValue[0] == 0) {
                self->scale--;
                CreateTempObject(TypeNameID("Boss Spike"), 0, 0xAC00000, self->values[4]);
                objectEntityList[scriptEng.arrayPosition[2]].XPos += self->values[1];
                if (self->values[1] > 0) {
                    self->values[1] -= 0x200000;
                } else {
                    self->values[1] += 0x200000;
                }
            }
        }
        self->values[0]++;
        if (self->values[0] == 16) {
            self->values[0] = 0;
            FloorControl_SpawnRubble();
            if (self->values[3] > 0) {
                self->values[3]--;
            } else {
                self->state++;
            }
        }
        break;
        case 3:
        if (self->values[0] == 30) {
            PlaySfx(globalSFXCount + 1, 0);
            self->values[5] = objectEntityList[objectLoop - 7].YPos;
            self->values[5] -= pYPos();
            self->values[5] >>= 25;
            if (self->values[6] < self->values[5]) {
                self->values[6] = self->values[5];
                CreateTempObject(TypeNameID("Electric Arc"), 0, objectEntityList[objectLoop - 1].XPos, objectEntityList[objectLoop - 6].YPos);
                scriptEng.tempValue[0] = self->values[5];
                scriptEng.tempValue[0] <<= 25;
                scriptEng.tempValue[0] += 0x20000;
                objectEntityList[scriptEng.arrayPosition[2]].YPos -= scriptEng.tempValue[0];
                objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
                objectEntityList[scriptEng.arrayPosition[2]].drawOrder = 4;
            }
        }
        self->values[0]++;
        if (self->values[0] == 60) {
            self->values[0] = 0;
            self->state++;
        }
        break;
        case 4:
        self->values[0]++;
        if (self->values[0] == 60) {
            self->values[0] = 0;
            self->state++;
            if (objectEntityList[24].propertyValue == 2) {
                Copy16x16Tile(739, 827);
            } else {
                Copy16x16Tile(810, 863);
            }
        } else {
            scriptEng.tempValue[0] = self->values[0];
            scriptEng.tempValue[0] >>= 1;
            scriptEng.tempValue[0] %= 5;
            if (objectEntityList[24].propertyValue == 2) {
                scriptEng.tempValue[0] += 826;
                Copy16x16Tile(739, scriptEng.tempValue[0]);
            } else {
                scriptEng.tempValue[0] += 862;
                Copy16x16Tile(810, scriptEng.tempValue[0]);
            }
        }
        break;
        case 5:
        self->values[0]++;
        if (self->values[0] == 420) {
            self->values[0] = 0;
            self->state = 3;
        }
        break;
    }
}

void O_R6_BossFloorControl::FloorControl_SpawnRubble()
{
    Entity *self = Self();

    CreateTempObject(TypeNameID("Floor Rubble"), 0, objectEntityList[objectLoop - 1].XPos, self->values[4]);
    objectEntityList[scriptEng.arrayPosition[2]].XPos = rand() % 160;
    objectEntityList[scriptEng.arrayPosition[2]].XPos -= 80;
    objectEntityList[scriptEng.arrayPosition[2]].XPos <<= 16;
    objectEntityList[scriptEng.arrayPosition[2]].XPos += objectEntityList[objectLoop - 1].XPos;
    objectEntityList[scriptEng.arrayPosition[2]].values[1] = rand() % 0x500;
    scriptEng.tempValue[0] = objectEntityList[scriptEng.arrayPosition[2]].values[1];
    objectEntityList[scriptEng.arrayPosition[2]].values[1] -= 0x280;
    objectEntityList[scriptEng.arrayPosition[2]].values[1] <<= 8;
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = 0x10000;
    objectEntityList[scriptEng.arrayPosition[2]].values[3] = 2048;
    scriptEng.tempValue[0] &= 4095;
    objectEntityList[scriptEng.arrayPosition[2]].values[3] += scriptEng.tempValue[0];
}

void O_R6_BossFloorControl::FloorControl_SpawnPlatFarLeft()
{
    Entity *self = Self();

    switch (self->values[5]) {
        case 0:
        scriptEng.arrayPosition[0] = 2;
        break;
        case 1:
        scriptEng.arrayPosition[0] = 5;
        break;
        case 2:
        scriptEng.arrayPosition[0] = 11;
        break;
    }
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type = TypeNameID("Boss Platform");
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos = self->values[4];
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 0;
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 2816;
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[5] = objectLoop;
}

void O_R6_BossFloorControl::FloorControl_SpawnPlatLeft()
{
    Entity *self = Self();

    switch (self->values[5]) {
        case 0:
        scriptEng.arrayPosition[0] = 3;
        break;
        case 1:
        scriptEng.arrayPosition[0] = 6;
        break;
        case 2:
        scriptEng.arrayPosition[0] = 12;
        break;
    }
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type = TypeNameID("Boss Platform");
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos = self->values[4];
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 0;
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 2816;
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[5] = objectLoop;
}

void O_R6_BossFloorControl::FloorControl_SpawnPlatRight()
{
    Entity *self = Self();

    switch (self->values[5]) {
        case 0:
        scriptEng.arrayPosition[0] = 1;
        break;
        case 1:
        scriptEng.arrayPosition[0] = 7;
        break;
        case 2:
        scriptEng.arrayPosition[0] = 10;
        break;
    }
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type = TypeNameID("Boss Platform");
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos = self->values[4];
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 0;
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 2816;
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[5] = objectLoop;
}

void O_R6_BossFloorControl::FloorControl_SpawnPlatFarRight()
{
    Entity *self = Self();

    switch (self->values[5]) {
        case 0:
        scriptEng.arrayPosition[0] = 4;
        break;
        case 1:
        scriptEng.arrayPosition[0] = 8;
        break;
        case 2:
        scriptEng.arrayPosition[0] = 9;
        break;
    }
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].type = TypeNameID("Boss Platform");
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].YPos = self->values[4];
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[2] = 0;
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[3] = 2816;
    objectEntityList[objectLoop + scriptEng.arrayPosition[0]].values[5] = objectLoop;
}

const Native::NativeFunctionDef O_R6_BossFloorControl::funcs[5] = {
    { "FloorControl_SpawnRubble", O_R6_BossFloorControl::FloorControl_SpawnRubble },
    { "FloorControl_SpawnPlatFarLeft", O_R6_BossFloorControl::FloorControl_SpawnPlatFarLeft },
    { "FloorControl_SpawnPlatLeft", O_R6_BossFloorControl::FloorControl_SpawnPlatLeft },
    { "FloorControl_SpawnPlatRight", O_R6_BossFloorControl::FloorControl_SpawnPlatRight },
    { "FloorControl_SpawnPlatFarRight", O_R6_BossFloorControl::FloorControl_SpawnPlatFarRight },
};

#endif // RETRO_USE_NATIVE_OBJECTS
