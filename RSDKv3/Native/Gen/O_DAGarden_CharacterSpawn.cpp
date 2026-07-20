#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_DAGarden_CharacterSpawn.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from CharacterSpawn.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_DAGarden_CharacterSpawn::ObjectMain()
{
    Entity *self = Self();

    switch (self->state) {
        case 0:
        CreateTempObject(TypeNameID("Tails Biplane"), 0, self->XPos, self->YPos);
        self->values[0] = 380;
        self->state++;
        break;
        case 1:
        if (self->values[0] > 0) {
            self->values[0]--;
        } else {
            self->values[0] = rand() % 480;
            self->values[0] += 240;
            CharacterSpawn_SpawnSetup();
        }
        break;
    }
}

void O_DAGarden_CharacterSpawn::CharacterSpawn_SpawnBlueBird()
{
    scriptEng.tempValue[4] = rand() % 64;
    scriptEng.tempValue[4] -= 32;
    scriptEng.tempValue[4] += 120;
    scriptEng.tempValue[5] = 0;
    while (scriptEng.tempValue[1] > 1) {
        scriptEng.tempValue[2] = rand() % 64;
        scriptEng.tempValue[2] -= 32;
        scriptEng.tempValue[2] += scriptEng.tempValue[0];
        scriptEng.tempValue[2] <<= 16;
        scriptEng.tempValue[3] = rand() % 96;
        scriptEng.tempValue[3] -= 48;
        scriptEng.tempValue[3] += scriptEng.tempValue[4];
        scriptEng.tempValue[3] <<= 16;
        CreateTempObject(TypeNameID("Blue Bird"), 0, scriptEng.tempValue[2], scriptEng.tempValue[3]);
        if (scriptEng.tempValue[0] < SCREEN_CENTERX) {
            objectEntityList[scriptEng.arrayPosition[2]].direction = 0;
        } else {
            objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
        }
        objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[5];
        scriptEng.tempValue[5] += 8;
        objectEntityList[scriptEng.arrayPosition[2]].propertyValue = rand() % 10;
        objectEntityList[scriptEng.arrayPosition[2]].propertyValue += 3;
        scriptEng.tempValue[1]--;
    }
    scriptEng.tempValue[2] = rand() % 64;
    scriptEng.tempValue[2] -= 32;
    scriptEng.tempValue[2] += scriptEng.tempValue[0];
    scriptEng.tempValue[2] <<= 16;
    scriptEng.tempValue[3] = rand() % 96;
    scriptEng.tempValue[3] -= 48;
    scriptEng.tempValue[3] += scriptEng.tempValue[4];
    scriptEng.tempValue[3] <<= 16;
    CreateTempObject(TypeNameID("Slow Bird"), 0, scriptEng.tempValue[2], scriptEng.tempValue[3]);
    if (scriptEng.tempValue[0] < SCREEN_CENTERX) {
        objectEntityList[scriptEng.arrayPosition[2]].direction = 0;
    } else {
        objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
    }
    objectEntityList[scriptEng.arrayPosition[2]].values[2] = scriptEng.tempValue[5];
    scriptEng.tempValue[5] += 8;
    objectEntityList[scriptEng.arrayPosition[2]].propertyValue = rand() % 10;
    objectEntityList[scriptEng.arrayPosition[2]].propertyValue += 3;
    scriptEng.tempValue[1]--;
}

void O_DAGarden_CharacterSpawn::CharacterSpawn_SpawnShootStar()
{
    while (scriptEng.tempValue[1] > 0) {
        scriptEng.tempValue[2] = rand() % 256;
        scriptEng.tempValue[2] -= 64;
        scriptEng.tempValue[2] += SCREEN_CENTERX;
        scriptEng.tempValue[2] <<= 16;
        scriptEng.tempValue[3] = rand() % 80;
        scriptEng.tempValue[3] -= 96;
        scriptEng.tempValue[3] <<= 16;
        scriptEng.tempValue[4] = rand() % 10;
        if (scriptEng.tempValue[4] > 5) {
            CreateTempObject(TypeNameID("Shooting Star"), 6, scriptEng.tempValue[2], scriptEng.tempValue[3]);
        } else {
            CreateTempObject(TypeNameID("Shooting Star"), 0, scriptEng.tempValue[2], scriptEng.tempValue[3]);
        }
        scriptEng.tempValue[1]--;
    }
}

void O_DAGarden_CharacterSpawn::CharacterSpawn_SpawnSetup()
{
    Entity *self = Self();

    switch (self->values[1]) {
        case 0:
        scriptEng.tempValue[0] = SCREEN_XSIZE;
        scriptEng.tempValue[0] += 96;
        scriptEng.tempValue[1] = 8;
        CharacterSpawn_SpawnBlueBird();
        self->values[1]++;
        break;
        case 1:
        scriptEng.tempValue[0] = SCREEN_XSIZE;
        scriptEng.tempValue[0] += 48;
        scriptEng.tempValue[0] <<= 16;
        CreateTempObject(TypeNameID("Tails Biplane"), 0, scriptEng.tempValue[0], self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
        self->values[1]++;
        break;
        case 2:
        if (self->values[2] == 0) {
            scriptEng.tempValue[0] = 0;
            scriptEng.tempValue[0] -= 96;
            scriptEng.tempValue[1] = 6;
            CharacterSpawn_SpawnBlueBird();
        } else {
            scriptEng.tempValue[1] = 3;
            CharacterSpawn_SpawnShootStar();
        }
        self->values[1]++;
        break;
        case 3:
        scriptEng.tempValue[0] = rand() % 320;
        scriptEng.tempValue[0] -= 160;
        scriptEng.tempValue[0] += SCREEN_CENTERX;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[1] = rand() % 64;
        if (scriptEng.tempValue[1] > 40) {
            CreateTempObject(TypeNameID("Metal Sonic"), 0, scriptEng.tempValue[0], 0x10C0000);
        } else {
            CreateTempObject(TypeNameID("Metal Sonic"), 0, scriptEng.tempValue[0], -0x400000);
        }
        self->values[1]++;
        break;
        case 4:
        CreateTempObject(TypeNameID("Tails Biplane"), 0, self->XPos, self->YPos);
        self->values[1]++;
        break;
        case 5:
        if (self->values[2] == 0) {
            scriptEng.tempValue[0] = 0;
            scriptEng.tempValue[0] -= 96;
            scriptEng.tempValue[1] = 4;
            CharacterSpawn_SpawnBlueBird();
        } else {
            scriptEng.tempValue[1] = 4;
            CharacterSpawn_SpawnShootStar();
        }
        self->values[1]++;
        break;
        case 6:
        scriptEng.tempValue[0] = SCREEN_XSIZE;
        scriptEng.tempValue[0] += 48;
        scriptEng.tempValue[0] <<= 16;
        CreateTempObject(TypeNameID("UFO"), 3, scriptEng.tempValue[0], self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
        self->values[1]++;
        break;
        case 7:
        scriptEng.tempValue[0] = SCREEN_XSIZE;
        scriptEng.tempValue[0] += 48;
        scriptEng.tempValue[0] <<= 16;
        CreateTempObject(TypeNameID("Dr Eggman"), 6, scriptEng.tempValue[0], 0xC00000);
        objectEntityList[scriptEng.arrayPosition[2]].direction = 0;
        self->values[1]++;
        break;
        case 8:
        scriptEng.tempValue[0] = rand() % 320;
        scriptEng.tempValue[0] -= 160;
        scriptEng.tempValue[0] += SCREEN_CENTERX;
        scriptEng.tempValue[0] <<= 16;
        scriptEng.tempValue[1] = rand() % 64;
        if (scriptEng.tempValue[1] > 40) {
            CreateTempObject(TypeNameID("Metal Sonic"), 0, scriptEng.tempValue[0], 0x10C0000);
        } else {
            CreateTempObject(TypeNameID("Metal Sonic"), 0, scriptEng.tempValue[0], -0x400000);
        }
        self->values[1]++;
        break;
        case 9:
        if (self->values[2] == 0) {
            scriptEng.tempValue[0] = SCREEN_XSIZE;
            scriptEng.tempValue[0] += 96;
            scriptEng.tempValue[1] = 8;
            CharacterSpawn_SpawnBlueBird();
        } else {
            scriptEng.tempValue[1] = 2;
            CharacterSpawn_SpawnShootStar();
        }
        self->values[1]++;
        break;
        case 10:
        scriptEng.tempValue[0] = SCREEN_XSIZE;
        scriptEng.tempValue[0] += 48;
        scriptEng.tempValue[0] <<= 16;
        CreateTempObject(TypeNameID("Tails Biplane"), 0, scriptEng.tempValue[0], self->YPos);
        objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
        self->values[1]++;
        break;
        case 11:
        CreateTempObject(TypeNameID("UFO"), 0, self->XPos, self->YPos);
        CreateTempObject(TypeNameID("UFO"), 3, self->XPos, self->YPos);
        self->values[1]++;
        break;
        case 12:
        scriptEng.tempValue[0] = -48;
        scriptEng.tempValue[0] <<= 16;
        CreateTempObject(TypeNameID("Dr Eggman"), 6, scriptEng.tempValue[0], 0xC00000);
        objectEntityList[scriptEng.arrayPosition[2]].direction = 1;
        self->values[1] = 0;
        break;
    }
}

const Native::NativeFunctionDef O_DAGarden_CharacterSpawn::funcs[3] = {
    { "CharacterSpawn_SpawnBlueBird", O_DAGarden_CharacterSpawn::CharacterSpawn_SpawnBlueBird },
    { "CharacterSpawn_SpawnShootStar", O_DAGarden_CharacterSpawn::CharacterSpawn_SpawnShootStar },
    { "CharacterSpawn_SpawnSetup", O_DAGarden_CharacterSpawn::CharacterSpawn_SpawnSetup },
};

#endif // RETRO_USE_NATIVE_OBJECTS
