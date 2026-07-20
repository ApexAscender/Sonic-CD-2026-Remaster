#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_ObjectScore.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from ObjectScore.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_ObjectScore::ObjectStartup()
{
    LoadSpriteSheet("Global/Items3.gif");
    AddSpriteFrame(-6, -4, 12, 8, 0, 246);
    AddSpriteFrame(-7, -4, 13, 8, 20, 246);
    AddSpriteFrame(-7, -4, 13, 8, 33, 246);
    AddSpriteFrame(-8, -4, 16, 8, 0, 246);
}

void O_ObjectScore::ObjectDraw()
{
    Entity *self = Self();

    if (self->state == 0) {
        DrawSprite_Frame(self->propertyValue);
        self->YPos -= 0x20000;
        self->values[0]++;
        if (self->values[0] == 24) {
            self->type = TypeNameID("Blank Object");
            if (objectEntityList[26].type == TypeNameID("Object Score")) {
                if (objectEntityList[26].values[0] < 3) {
                    objectEntityList[26].values[0]++;
                }
            } else {
                objectEntityList[26].type = TypeNameID("Object Score");
                objectEntityList[26].values[0] = 1;
            }
            objectEntityList[26].state = 1;
            objectEntityList[26].values[1] = pGravity();
            objectEntityList[26].priority = 1;
        }
    } else {
        if (self->values[1] != pGravity()) {
            ResetObjectEntity(26, TypeNameID("Blank Object"), 0, 0, 0);
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
