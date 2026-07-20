#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R1_InvBlock.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from InvBlock.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R1_InvBlock::ObjectStartup()
{
    LoadSpriteSheet("R1/Objects.gif");
    AddSpriteFrame(0, 0, 4, 4, 68, 162);
    AddSpriteFrame(-12, -12, 24, 24, 93, 142);
    AddSpriteFrame(-12, -12, 24, 24, 93, 142);
    AddSpriteFrame(-12, -12, 24, 24, 93, 142);
    AddSpriteFrame(-12, -12, 24, 24, 93, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 118, 142);
    AddSpriteFrame(-12, -12, 24, 24, 118, 142);
    AddSpriteFrame(-12, -12, 24, 24, 118, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 143, 142);
    AddSpriteFrame(-12, -12, 24, 24, 143, 142);
    AddSpriteFrame(-12, -12, 24, 24, 143, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    AddSpriteFrame(-12, -12, 24, 24, 168, 142);
    AddSpriteFrame(-12, -12, 24, 24, 168, 142);
    AddSpriteFrame(-12, -12, 24, 24, 168, 142);
    AddSpriteFrame(-12, -12, 24, 24, 68, 142);
    scriptEng.arrayPosition[0] = 32;
    while (scriptEng.arrayPosition[0] < 1056) {
        if (objectEntityList[scriptEng.arrayPosition[0]].type == TypeNameID("Invisible Block")) {
            objectEntityList[scriptEng.arrayPosition[0]].values[2] = objectEntityList[scriptEng.arrayPosition[0]].YPos;
        }
        scriptEng.arrayPosition[0]++;
    }
}

void O_R1_InvBlock::ObjectPlayerInteraction()
{
    Entity *self = Self();

    if (self->state < 2) {
        PlayerObjectCollision(C_PLATFORM, -12, -12, 12, 12);
        self->values[0] = CheckResult();
    }
    if (objectEntityList[24].propertyValue > 1) {
        switch (self->state) {
            case 0:
            if (self->values[0] == 1) {
                self->state = 1;
                self->priority = 1;
                pYPos() += 0x20000;
            }
            break;
            case 1:
            if (self->values[0] == 1) {
                pYPos() += 0x20000;
            }
            break;
        }
    }
}

void O_R1_InvBlock::ObjectDraw()
{
    Entity *self = Self();

    switch (self->state) {
        case 1:
        self->YPos += 0x20000;
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 2;
            self->YPos = self->values[2];
        }
        break;
        case 2:
        if (GetObjectOutOfBounds(objectLoop) == 1) {
            self->state = 0;
            self->priority = 0;
        }
        break;
    }
    switch (objectEntityList[24].propertyValue) {
        case 0:
        if (self->values[0] == 1) {
            if (self->frame < 24) {
                self->frame++;
            }
        } else {
            if (self->frame > 0) {
                self->frame--;
            }
        }
        DrawSprite_Frame(self->frame);
        break;
        case 1:
        DrawSprite_Frame(5);
        break;
        case 2:
        case 3:
        if (self->state < 2) {
            DrawSprite_Frame(5);
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
