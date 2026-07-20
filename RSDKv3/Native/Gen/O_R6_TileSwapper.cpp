#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R6_TileSwapper.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from TileSwapper.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R6_TileSwapper::ObjectPlayerInteraction()
{
    Entity *self = Self();

    switch (self->propertyValue) {
        case 0:
        if (self->state == 0) {
            PlayerObjectCollision(C_TOUCH, 0, -64, 64, 64);
            if (CheckResult() == 1) {
                self->state = 1;
                self->priority = 1;
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] >>= 23;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] >>= 23;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 386;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 387;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 390;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 391;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 394;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 395;
            }
        } else {
            PlayerObjectCollision(C_TOUCH, 0, -64, 692, 64);
            if (CheckResult() == 0) {
                self->state = 0;
                self->priority = 0;
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] >>= 23;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] >>= 23;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 86;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 87;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 122;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 123;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 126;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 127;
            }
        }
        break;
        case 1:
        if (self->state == 0) {
            PlayerObjectCollision(C_TOUCH, -48, -64, -8, 64);
            if (CheckResult() == 1) {
                self->state = 1;
                self->priority = 1;
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] >>= 23;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] >>= 23;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 390;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 391;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 394;
            }
        } else {
            PlayerObjectCollision(C_TOUCH, 0, -64, 384, 64);
            if (CheckResult() == 0) {
                self->state = 0;
                self->priority = 0;
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] >>= 23;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] >>= 23;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 122;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 123;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 126;
            }
        }
        break;
        case 2:
        if (self->state == 0) {
            PlayerObjectCollision(C_TOUCH, -48, -64, -8, 64);
            if (CheckResult() == 1) {
                self->state = 1;
                self->priority = 1;
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] >>= 23;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] >>= 23;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 399;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 390;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 391;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 394;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 395;
            }
        } else {
            PlayerObjectCollision(C_TOUCH, 0, -64, 544, 64);
            if (CheckResult() == 0) {
                self->state = 0;
                self->priority = 0;
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] >>= 23;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] >>= 23;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 203;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 122;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 123;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 126;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 127;
            }
        }
        break;
        case 3:
        if (self->state == 0) {
            PlayerObjectCollision(C_TOUCH, 0, -64, 64, 64);
            if (CheckResult() == 1) {
                self->state = 1;
                self->priority = 1;
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] >>= 23;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] >>= 23;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 386;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 387;
            }
        } else {
            PlayerObjectCollision(C_TOUCH, 0, -64, 672, 64);
            if (CheckResult() == 0) {
                self->state = 0;
                self->priority = 0;
                scriptEng.tempValue[0] = self->XPos;
                scriptEng.tempValue[0] >>= 23;
                scriptEng.tempValue[1] = self->YPos;
                scriptEng.tempValue[1] >>= 23;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 86;
                scriptEng.tempValue[0]++;
                stageLayouts[0].tiles[scriptEng.tempValue[0] + 0x100 * scriptEng.tempValue[1]] = 87;
            }
        }
        break;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
