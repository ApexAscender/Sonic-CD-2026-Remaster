#include "RetroEngine.hpp"

#if RETRO_USE_NATIVE_OBJECTS

#include "NativeScriptOps.hpp"

// Every function here is a faithful copy of the matching FUNC_* / VAR_* case in
// Script.cpp — same math, same globals, same quirks. Do not "improve" behaviour
// here; fidelity to the interpreter is the contract with the transpiled objects.

namespace Native
{
byte scriptSub = SUB_MAIN;

// -----------------------------------------------------------------------------
//  Cross-object function dispatch
// -----------------------------------------------------------------------------
#define NATIVE_FUNCTION_MAX (0x800)
static const NativeFunctionDef *nativeFuncs[NATIVE_FUNCTION_MAX];
static int nativeFuncCount = 0;

void ClearActiveFunctions() { nativeFuncCount = 0; }

void AddActiveFunctions(const NativeFunctionDef *defs, int count)
{
    for (int i = 0; i < count && nativeFuncCount < NATIVE_FUNCTION_MAX; ++i) nativeFuncs[nativeFuncCount++] = &defs[i];
}

int ScriptFuncID(const char *name)
{
    for (int f = 0; f < scriptFunctionCount; ++f) {
        if (StrComp(scriptFunctionList[f].name, name))
            return f;
    }
    return -1;
}

void CallScriptFunctionNamed(const char *name, byte sub)
{
    // native first — once the defining object is converted its functions
    // route here without touching the interpreter. Later-bound objects win on
    // duplicate names, matching the text compiler's overwrite-on-redefine.
    for (int i = nativeFuncCount - 1; i >= 0; --i) {
        if (StrComp(nativeFuncs[i]->name, name)) {
            byte prev = scriptSub;
            scriptSub = sub;
            nativeFuncs[i]->fn();
            scriptSub = prev;
            return;
        }
    }
    // interpreted function by name (names exist when scripts were text-parsed)
    for (int f = 0; f < scriptFunctionCount; ++f) {
        if (StrComp(scriptFunctionList[f].name, name)) {
            CallScriptFunction(f, sub);
            return;
        }
    }
    PrintLog("CallScriptFunctionNamed: unresolved '%s'", name);
}

// -----------------------------------------------------------------------------
//  Variable helpers
// -----------------------------------------------------------------------------
int GetHapticsEnabled()
{
#if RETRO_USE_HAPTICS
    return Engine.hapticsEnabled;
#else
    return 0;
#endif
}

int GetObjectOutOfBounds(int index)
{
    int pos = objectEntityList[index].XPos >> 16;
    if (pos <= xScrollOffset - OBJECT_BORDER_X1 || pos >= OBJECT_BORDER_X2 + xScrollOffset)
        return 1;
    pos = objectEntityList[index].YPos >> 16;
    return pos <= yScrollOffset - OBJECT_BORDER_Y1 || pos >= yScrollOffset + OBJECT_BORDER_Y2;
}

int PlayerOutOfBounds()
{
    int pos = playerList[activePlayer].XPos >> 16;
    if (pos <= xScrollOffset - OBJECT_BORDER_X1 || pos >= OBJECT_BORDER_X2 + xScrollOffset)
        return 1;
    pos = playerList[activePlayer].YPos >> 16;
    return pos <= yScrollOffset - OBJECT_BORDER_Y1 || pos >= yScrollOffset + OBJECT_BORDER_Y2;
}

// -----------------------------------------------------------------------------
//  Audio
// -----------------------------------------------------------------------------
void SetMusicTrack_Script(const char *path, int slot, int loopExtra)
{
    // engine takes char*; the arg is a string literal we never mutate
    if (loopExtra <= 1)
        SetMusicTrack(const_cast<char *>(path), slot, loopExtra, 0);
    else
        SetMusicTrack(const_cast<char *>(path), slot, true, loopExtra);
}

// -----------------------------------------------------------------------------
//  Collision
// -----------------------------------------------------------------------------
void ObjectTileCollision_Script(int side, int xOff, int yOff, int plane)
{
    switch (side) {
        default: break;
        case CSIDE_FLOOR: ObjectFloorCollision(xOff, yOff, plane); break;
        case CSIDE_LWALL: ObjectLWallCollision(xOff, yOff, plane); break;
        case CSIDE_RWALL: ObjectRWallCollision(xOff, yOff, plane); break;
        case CSIDE_ROOF: ObjectRoofCollision(xOff, yOff, plane); break;
    }
}

void ObjectTileGrip_Script(int side, int xOff, int yOff, int plane)
{
    switch (side) {
        default: break;
        case CSIDE_FLOOR: ObjectFloorGrip(xOff, yOff, plane); break;
        case CSIDE_LWALL: ObjectLWallGrip(xOff, yOff, plane); break;
        case CSIDE_RWALL: ObjectRWallGrip(xOff, yOff, plane); break;
        case CSIDE_ROOF: ObjectRoofGrip(xOff, yOff, plane); break;
        case CSIDE_ENTITY: ObjectEntityGrip(xOff, yOff, plane); break;
    }
}

void PlayerTileCollision_Script()
{
    Player *player = &playerList[activePlayer];
    if (player->tileCollisions) {
        ProcessPlayerTileCollisions(player);
    }
    else {
        player->XPos += player->XVelocity;
        player->YPos += player->YVelocity;
    }
}

void CheckTouchRect_Script(int x1, int y1, int x2, int y2)
{
    scriptEng.checkResult = -1;
#if !RETRO_USE_ORIGINAL_CODE
    AddDebugHitbox(H_TYPE_FINGER, NULL, x1, y1, x2, y2);
#endif
    for (int f = 0; f < touches; ++f) {
        if (touchDown[f] && touchX[f] > x1 && touchX[f] < x2 && touchY[f] > y1 && touchY[f] < y2) {
            scriptEng.checkResult = f;
        }
    }
}

// -----------------------------------------------------------------------------
//  Entities / players
// -----------------------------------------------------------------------------
void BindPlayerToObject_Script(int playerID, int entityNo)
{
    ObjectScript *scriptInfo = &objectScriptList[objectEntityList[objectLoop].type];

    playerList[playerID].animationFile = scriptInfo->animFile;
    playerList[playerID].boundEntity   = &objectEntityList[entityNo];
    playerList[playerID].entityNo      = entityNo;
}

void ProcessAnimation_Script()
{
    Entity *entity = &objectEntityList[objectLoop];
    ProcessObjectAnimation(&objectScriptList[entity->type], entity);
}

void DrawObjectAnimation_Script()
{
    Entity *entity = &objectEntityList[objectLoop];
    DrawObjectAnimation(&objectScriptList[entity->type], entity, (entity->XPos >> 16) - xScrollOffset, (entity->YPos >> 16) - yScrollOffset);
}

void DrawPlayerAnimation_Script()
{
    Entity *entity = &objectEntityList[objectLoop];
    Player *player = &playerList[activePlayer];
    if (player->visible) {
        if (cameraTarget == activePlayer)
            DrawObjectAnimation(&objectScriptList[entity->type], entity, player->screenXPos, player->screenYPos);
        else
            DrawObjectAnimation(&objectScriptList[entity->type], entity, (player->XPos >> 16) - xScrollOffset, (player->YPos >> 16) - yScrollOffset);
    }
}

// -----------------------------------------------------------------------------
//  Drawing
// -----------------------------------------------------------------------------
static inline ObjectScript *CurScript() { return &objectScriptList[objectEntityList[objectLoop].type]; }

void DrawSprite_FrameXY(int frameID, int xpos, int ypos)
{
    ObjectScript *scriptInfo = CurScript();
    SpriteFrame *frame       = &scriptFrames[scriptInfo->frameListOffset + frameID];
    DrawSprite((xpos >> 16) - xScrollOffset + frame->pivotX, (ypos >> 16) - yScrollOffset + frame->pivotY, frame->width, frame->height, frame->sprX,
               frame->sprY, scriptInfo->spriteSheetID);
}

void DrawSprite_ScreenXY(int frameID, int xpos, int ypos)
{
    ObjectScript *scriptInfo = CurScript();
    SpriteFrame *frame       = &scriptFrames[scriptInfo->frameListOffset + frameID];
    DrawSprite(xpos + frame->pivotX, ypos + frame->pivotY, frame->width, frame->height, frame->sprX, frame->sprY, scriptInfo->spriteSheetID);
}

// FUNC_DRAWSPRITEFX — xpos/ypos are world (fixed-point) coords.
void DrawSpriteFX_Script(int frameID, int fx, int xpos, int ypos)
{
    ObjectScript *scriptInfo = CurScript();
    Entity *entity           = &objectEntityList[objectLoop];
    SpriteFrame *spriteFrame = &scriptFrames[scriptInfo->frameListOffset + frameID];
    int x                    = (xpos >> 16) - xScrollOffset;
    int y                    = (ypos >> 16) - yScrollOffset;

    switch (fx) {
        default: break;
        case FX_SCALE:
            DrawSpriteScaled(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, entity->scale, entity->scale, spriteFrame->width,
                             spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, scriptInfo->spriteSheetID);
            break;
        case FX_ROTATE:
            DrawSpriteRotated(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, spriteFrame->sprX, spriteFrame->sprY,
                              spriteFrame->width, spriteFrame->height, entity->rotation, scriptInfo->spriteSheetID);
            break;
        case FX_ROTOZOOM:
            DrawSpriteRotozoom(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, spriteFrame->sprX, spriteFrame->sprY,
                               spriteFrame->width, spriteFrame->height, entity->rotation, entity->scale, scriptInfo->spriteSheetID);
            break;
        case FX_INK:
            switch (entity->inkEffect) {
                case INK_NONE:
                    DrawSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                               spriteFrame->sprY, scriptInfo->spriteSheetID);
                    break;
                case INK_BLEND:
                    DrawBlendedSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                                      spriteFrame->sprY, scriptInfo->spriteSheetID);
                    break;
                case INK_ALPHA:
                    DrawAlphaBlendedSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height,
                                           spriteFrame->sprX, spriteFrame->sprY, entity->alpha, scriptInfo->spriteSheetID);
                    break;
                case INK_ADD:
                    DrawAdditiveBlendedSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height,
                                              spriteFrame->sprX, spriteFrame->sprY, entity->alpha, scriptInfo->spriteSheetID);
                    break;
                case INK_SUB:
                    DrawSubtractiveBlendedSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height,
                                                 spriteFrame->sprX, spriteFrame->sprY, entity->alpha, scriptInfo->spriteSheetID);
                    break;
            }
            break;
        case FX_TINT:
            if (entity->inkEffect == INK_ALPHA) {
                DrawScaledTintMask(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, entity->scale, entity->scale,
                                   spriteFrame->width, spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, scriptInfo->spriteSheetID);
            }
            else {
                DrawSpriteScaled(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, entity->scale, entity->scale,
                                 spriteFrame->width, spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, scriptInfo->spriteSheetID);
            }
            break;
        case FX_FLIP:
            switch (entity->direction) {
                default:
                case FLIP_NONE:
                    DrawSpriteFlipped(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                                      spriteFrame->sprY, FLIP_NONE, scriptInfo->spriteSheetID);
                    break;
                case FLIP_X:
                    DrawSpriteFlipped(x - spriteFrame->width - spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height,
                                      spriteFrame->sprX, spriteFrame->sprY, FLIP_X, scriptInfo->spriteSheetID);
                    break;
                case FLIP_Y:
                    DrawSpriteFlipped(x + spriteFrame->pivotX, y - spriteFrame->height - spriteFrame->pivotY, spriteFrame->width,
                                      spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, FLIP_Y, scriptInfo->spriteSheetID);
                    break;
                case FLIP_XY:
                    DrawSpriteFlipped(x - spriteFrame->width - spriteFrame->pivotX, y - spriteFrame->height - spriteFrame->pivotY,
                                      spriteFrame->width, spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, FLIP_XY,
                                      scriptInfo->spriteSheetID);
                    break;
            }
            break;
    }
}

// FUNC_DRAWSPRITESCREENFX — xpos/ypos are screen coords.
void DrawSpriteScreenFX_Script(int frameID, int fx, int x, int y)
{
    ObjectScript *scriptInfo = CurScript();
    Entity *entity           = &objectEntityList[objectLoop];
    SpriteFrame *spriteFrame = &scriptFrames[scriptInfo->frameListOffset + frameID];

    switch (fx) {
        default: break;
        case FX_SCALE:
            DrawSpriteScaled(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, entity->scale, entity->scale, spriteFrame->width,
                             spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, scriptInfo->spriteSheetID);
            break;
        case FX_ROTATE:
            DrawSpriteRotated(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, spriteFrame->sprX, spriteFrame->sprY,
                              spriteFrame->width, spriteFrame->height, entity->rotation, scriptInfo->spriteSheetID);
            break;
        case FX_ROTOZOOM:
            DrawSpriteRotozoom(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, spriteFrame->sprX, spriteFrame->sprY,
                               spriteFrame->width, spriteFrame->height, entity->rotation, entity->scale, scriptInfo->spriteSheetID);
            break;
        case FX_INK:
            switch (entity->inkEffect) {
                case INK_NONE:
                    DrawSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                               spriteFrame->sprY, scriptInfo->spriteSheetID);
                    break;
                case INK_BLEND:
                    DrawBlendedSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                                      spriteFrame->sprY, scriptInfo->spriteSheetID);
                    break;
                case INK_ALPHA:
                    DrawAlphaBlendedSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height,
                                           spriteFrame->sprX, spriteFrame->sprY, entity->alpha, scriptInfo->spriteSheetID);
                    break;
                case INK_ADD:
                    DrawAdditiveBlendedSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height,
                                              spriteFrame->sprX, spriteFrame->sprY, entity->alpha, scriptInfo->spriteSheetID);
                    break;
                case INK_SUB:
                    DrawSubtractiveBlendedSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height,
                                                 spriteFrame->sprX, spriteFrame->sprY, entity->alpha, scriptInfo->spriteSheetID);
                    break;
            }
            break;
        case FX_TINT:
            if (entity->inkEffect == INK_ALPHA) {
                DrawScaledTintMask(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, entity->scale, entity->scale,
                                   spriteFrame->width, spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, scriptInfo->spriteSheetID);
            }
            else {
                DrawSpriteScaled(entity->direction, x, y, -spriteFrame->pivotX, -spriteFrame->pivotY, entity->scale, entity->scale,
                                 spriteFrame->width, spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, scriptInfo->spriteSheetID);
            }
            break;
        case FX_FLIP:
            switch (entity->direction) {
                default:
                case FLIP_NONE:
                    DrawSpriteFlipped(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                                      spriteFrame->sprY, FLIP_NONE, scriptInfo->spriteSheetID);
                    break;
                case FLIP_X:
                    DrawSpriteFlipped(x - spriteFrame->width - spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height,
                                      spriteFrame->sprX, spriteFrame->sprY, FLIP_X, scriptInfo->spriteSheetID);
                    break;
                case FLIP_Y:
                    DrawSpriteFlipped(x + spriteFrame->pivotX, y - spriteFrame->height - spriteFrame->pivotY, spriteFrame->width,
                                      spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, FLIP_Y, scriptInfo->spriteSheetID);
                    break;
                case FLIP_XY:
                    DrawSpriteFlipped(x - spriteFrame->width - spriteFrame->pivotX, y - spriteFrame->height - spriteFrame->pivotY,
                                      spriteFrame->width, spriteFrame->height, spriteFrame->sprX, spriteFrame->sprY, FLIP_XY,
                                      scriptInfo->spriteSheetID);
                    break;
            }
            break;
    }
}

void DrawNumbers_Script(int frame, int x, int y, int value, int digits, int digitWidth, int alignRight)
{
    ObjectScript *scriptInfo = CurScript();
    SpriteFrame *spriteFrame = nullptr;
    int i                    = 10;
    if (alignRight) {
        while (digits > 0) {
            int frameID = value % i / (i / 10) + frame;
            spriteFrame = &scriptFrames[scriptInfo->frameListOffset + frameID];
            DrawSprite(spriteFrame->pivotX + x, spriteFrame->pivotY + y, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                       spriteFrame->sprY, scriptInfo->spriteSheetID);
            x -= digitWidth;
            i *= 10;
            --digits;
        }
    }
    else {
        int extra = 10;
        if (value)
            extra = 10 * value;
        while (digits > 0) {
            if (extra >= i) {
                int frameID = value % i / (i / 10) + frame;
                spriteFrame = &scriptFrames[scriptInfo->frameListOffset + frameID];
                DrawSprite(spriteFrame->pivotX + x, spriteFrame->pivotY + y, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                           spriteFrame->sprY, scriptInfo->spriteSheetID);
            }
            x -= digitWidth;
            i *= 10;
            --digits;
        }
    }
}

void DrawActName_Script(int frame, int x, int y, int mode, int capitalize, int spaceWidth, int spacing)
{
    ObjectScript *scriptInfo = CurScript();
    SpriteFrame *spriteFrame = nullptr;
    int charID               = 0;

    switch (mode) {
        default: break;
        case 0: // Draw Word 1 (aligned from the right)
            charID = 0;
            for (charID = 0;; ++charID) {
                int nextChar = titleCardText[charID + 1];
                if (nextChar == '-' || !nextChar)
                    break;
            }

            while (charID >= 0) {
                int character = titleCardText[charID];
                if (character == ' ')
                    character = -1;
                if (character == '-')
                    character = 0;
                if (character >= '0' && character <= '9')
                    character -= 22;
                if (character > '9' && character < 'f')
                    character -= 'A';

                if (character <= -1) {
                    x -= spaceWidth + spacing;
                }
                else {
                    character += frame;
                    spriteFrame = &scriptFrames[scriptInfo->frameListOffset + character];
                    x -= spriteFrame->width + spacing;
                    DrawSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                               spriteFrame->sprY, scriptInfo->spriteSheetID);
                }
                charID--;
            }
            break;

        case 1: // Draw Word 1
            charID = 0;
            if (capitalize == 1 && titleCardText[charID] != 0) {
                int character = titleCardText[charID];
                if (character == ' ')
                    character = -1;
                if (character == '-')
                    character = 0;
                if (character >= '0' && character <= '9')
                    character -= 22;
                if (character > '9' && character < 'f')
                    character -= 'A';

                if (character <= -1) {
                    x += spaceWidth + spacing;
                }
                else {
                    character += frame;
                    spriteFrame = &scriptFrames[scriptInfo->frameListOffset + character];
                    DrawSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                               spriteFrame->sprY, scriptInfo->spriteSheetID);
                    x += spriteFrame->width + spacing;
                }
                frame += 26;
                charID++;
            }

            while (titleCardText[charID] != 0 && titleCardText[charID] != '-') {
                int character = titleCardText[charID];
                if (character == ' ')
                    character = -1;
                if (character == '-')
                    character = 0;
                if (character > '/' && character < ':')
                    character -= 22;
                if (character > '9' && character < 'f')
                    character -= 'A';

                if (character <= -1) {
                    x += spaceWidth + spacing;
                }
                else {
                    character += frame;
                    spriteFrame = &scriptFrames[scriptInfo->frameListOffset + character];
                    DrawSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                               spriteFrame->sprY, scriptInfo->spriteSheetID);
                    x += spriteFrame->width + spacing;
                }
                charID++;
            }
            break;

        case 2: // Draw Word 2
            charID = titleCardWord2;
            if (capitalize == 1 && titleCardText[charID] != 0) {
                int character = titleCardText[charID];
                if (character == ' ')
                    character = 0;
                if (character == '-')
                    character = 0;
                if (character >= '0' && character <= '9')
                    character -= 22;
                if (character > '9' && character < 'f')
                    character -= 'A';

                if (character <= -1) {
                    x += spaceWidth + spacing;
                }
                else {
                    character += frame;
                    spriteFrame = &scriptFrames[scriptInfo->frameListOffset + character];
                    DrawSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                               spriteFrame->sprY, scriptInfo->spriteSheetID);
                    x += spriteFrame->width + spacing;
                }
                frame += 26;
                charID++;
            }

            while (titleCardText[charID] != 0) {
                int character = titleCardText[charID];
                if (character == ' ')
                    character = -1;
                if (character == '-')
                    character = 0;
                if (character >= '0' && character <= '9')
                    character -= 22;
                if (character > '9' && character < 'f')
                    character -= 'A';

                if (character <= -1) {
                    x += spaceWidth + spacing;
                }
                else {
                    character += frame;
                    spriteFrame = &scriptFrames[scriptInfo->frameListOffset + character];
                    DrawSprite(x + spriteFrame->pivotX, y + spriteFrame->pivotY, spriteFrame->width, spriteFrame->height, spriteFrame->sprX,
                               spriteFrame->sprY, scriptInfo->spriteSheetID);
                    x += spriteFrame->width + spacing;
                }
                charID++;
            }
            break;
    }
}

void EditFrame_Script(int frameID, int px, int py, int w, int h, int sx, int sy)
{
    ObjectScript *scriptInfo = CurScript();
    if (scriptInfo->mobile) {
        SpriteFrame *spriteFrame = &scriptFrames[scriptInfo->frameListOffset + frameID];
        spriteFrame->pivotX      = px;
        spriteFrame->pivotY      = py;
        spriteFrame->width       = w;
        spriteFrame->height      = h;
        spriteFrame->sprX        = sx;
        spriteFrame->sprY        = sy;
    }
    // else: "SetEditorIcon" no-op, same as the PC interpreter
}

void LoadAnimation_Script(const char *path) { CurScript()->animFile = AddAnimationFile(path); }

int GetAnimationByName(const char *name)
{
    AnimationFile *animFile = CurScript()->animFile;
    int result              = -1;
    int id                  = 0;
    while (result == -1) {
        SpriteAnimation *anim = &animationList[animFile->aniListOffset + id];
        if (StrComp(name, anim->name))
            result = id;
        else if (++id == animFile->animCount)
            result = 0;
    }
    return result;
}

// -----------------------------------------------------------------------------
//  Tiles
// -----------------------------------------------------------------------------
int Get16x16TileInfo_Script(int x, int y, int infoType)
{
    int cx    = x >> 7;
    int cy    = y >> 7;
    int tile  = stageLayouts[0].tiles[cx + (cy << 8)] << 6;
    tile += ((x & 0x7F) >> 4) + 8 * ((y & 0x7F) >> 4);
    int index = tiles128x128.tileIndex[tile];
    switch (infoType) {
        case TILEINFO_INDEX: return tiles128x128.tileIndex[tile];
        case TILEINFO_DIRECTION: return tiles128x128.direction[tile];
        case TILEINFO_VISUALPLANE: return tiles128x128.visualPlane[tile];
        case TILEINFO_SOLIDITYA: return tiles128x128.collisionFlags[0][tile];
        case TILEINFO_SOLIDITYB: return tiles128x128.collisionFlags[1][tile];
        case TILEINFO_FLAGSA: return collisionMasks[0].flags[index];
        case TILEINFO_ANGLEA: return (int)collisionMasks[0].angles[index];
        case TILEINFO_FLAGSB: return collisionMasks[1].flags[index];
        case TILEINFO_ANGLEB: return (int)collisionMasks[1].angles[index];
        default: break;
    }
    return 0;
}

void Set16x16TileInfo_Script(int value, int x, int y, int infoType)
{
    int cx   = x >> 7;
    int cy   = y >> 7;
    int tile = stageLayouts[0].tiles[cx + (cy << 8)] << 6;
    tile += ((x & 0x7F) >> 4) + 8 * ((y & 0x7F) >> 4);
    switch (infoType) {
        case TILEINFO_INDEX:
            tiles128x128.tileIndex[tile] = value;
            if (renderType == RENDER_SW)
                tiles128x128.gfxDataPos[tile] = value << 8;
            else if (renderType == RENDER_HW)
                tiles128x128.gfxDataPos[tile] = (value << 2) & 0x3FFFC;
            break;
        case TILEINFO_DIRECTION: tiles128x128.direction[tile] = value; break;
        case TILEINFO_VISUALPLANE: tiles128x128.visualPlane[tile] = value; break;
        case TILEINFO_SOLIDITYA: tiles128x128.collisionFlags[0][tile] = value; break;
        case TILEINFO_SOLIDITYB: tiles128x128.collisionFlags[1][tile] = value; break;
        case TILEINFO_FLAGSA: collisionMasks[1].flags[tiles128x128.tileIndex[tile]] = value; break;
        case TILEINFO_ANGLEA: collisionMasks[1].angles[tiles128x128.tileIndex[tile]] = value; break;
        default: break;
    }
}

// -----------------------------------------------------------------------------
//  Menus / text
// -----------------------------------------------------------------------------
void SetupMenu_Script(int menuID, int rowStart, int selectionCount, int alignment)
{
    TextMenu *menu = &gameMenu[menuID];
    SetupTextMenu(menu, rowStart);
    menu->selectionCount = selectionCount;
    menu->alignment      = alignment;
}

void AddMenuEntry_Script(int menuID, const char *text, int highlight)
{
    TextMenu *menu                       = &gameMenu[menuID];
    menu->entryHighlight[menu->rowCount] = highlight;
    AddTextMenuEntry(menu, text);
}

void EditMenuEntry_Script(int menuID, const char *text, int rowID, int highlight)
{
    TextMenu *menu = &gameMenu[menuID];
    EditTextMenuEntry(menu, text, rowID);
    menu->entryHighlight[rowID] = highlight;
}

void DrawMenu_Script(int menuID, int x, int y)
{
    textMenuSurfaceNo = CurScript()->spriteSheetID;
    DrawTextMenu(&gameMenu[menuID], x, y);
}

void LoadTextFile_Script(int menuID, const char *path, int mapCode) { LoadTextFile(&gameMenu[menuID], path, mapCode != 0); }

void DrawText_Script(int menuID, int x, int y, int scaleX, int scaleY, int rowStart, int rowCount)
{
    textMenuSurfaceNo = CurScript()->spriteSheetID;
    DrawBitmapText(&gameMenu[menuID], x, y, scaleX, scaleY, rowStart, rowCount);
}

int GetTextInfo_Script(int menuID, int infoType, int rowID, int charID)
{
    TextMenu *menu = &gameMenu[menuID];
    switch (infoType) {
        case TEXTINFO_TEXTDATA: return menu->textData[menu->entryStart[rowID] + charID];
        case TEXTINFO_TEXTSIZE: return menu->entrySize[rowID];
        case TEXTINFO_ROWCOUNT: return menu->rowCount;
        default: break;
    }
    return 0;
}

void GetVersionNumber_Script(int menuID, int highlight)
{
    TextMenu *menu                       = &gameMenu[menuID];
    menu->entryHighlight[menu->rowCount] = highlight;
    AddTextMenuEntry(menu, Engine.gameVersion);
}

// -----------------------------------------------------------------------------
//  System
// -----------------------------------------------------------------------------
void LoadOnlineMenu_Script(int menuID)
{
    switch (menuID) {
        default: break;
        case ONLINEMENU_ACHIEVEMENTS: LoadAchievementsMenu(); break;
        case ONLINEMENU_LEADERBOARDS: LoadLeaderboardsMenu(); break;
    }
}

void HapticEffect_Script(int id, int a, int b, int c)
{
#if RETRO_USE_HAPTICS
    if (id != -1)
        QueueHapticEffect(id);
    else
        PlayHaptics(a, b, c);
#endif
}

void LoadVideo_Script(const char *path)
{
    PauseSound();
    if (FindStringToken(path, ".rsv", 1) <= -1)
        PlayVideoFile(const_cast<char *>(path)); // engine takes char*; literal, never mutated
    else
        CurScript()->spriteSheetID = AddGraphicsFile(path);
    ResumeSound();
}

// -----------------------------------------------------------------------------
//  3D
// -----------------------------------------------------------------------------
void Draw3DScene_Script()
{
    TransformVertexBuffer();
    Sort3DDrawList();
    Draw3DScene(CurScript()->spriteSheetID);
}

static inline Matrix *ScriptMat(int m)
{
    switch (m) {
        default:
        case MAT_WORLD: return &matWorld;
        case MAT_VIEW: return &matView;
        case MAT_TEMP: return &matTemp;
    }
}

void SetIdentityMatrixM(int m) { SetIdentityMatrix(ScriptMat(m)); }
void MatrixMultiplyM(int a, int b) { MatrixMultiply(ScriptMat(a), ScriptMat(b)); }
void MatrixTranslateXYZM(int m, int x, int y, int z) { MatrixTranslateXYZ(ScriptMat(m), x, y, z); }
void MatrixScaleXYZM(int m, int x, int y, int z) { MatrixScaleXYZ(ScriptMat(m), x, y, z); }
void MatrixRotateXM(int m, int angle) { MatrixRotateX(ScriptMat(m), angle); }
void MatrixRotateYM(int m, int angle) { MatrixRotateY(ScriptMat(m), angle); }
void MatrixRotateZM(int m, int angle) { MatrixRotateZ(ScriptMat(m), angle); }
void MatrixRotateXYZM(int m, int x, int y, int z) { MatrixRotateXYZ(ScriptMat(m), x, y, z); }
void TransformVerticesM(int m, int startIndex, int endIndex) { TransformVerticies(ScriptMat(m), startIndex, endIndex); }
} // namespace Native

#endif // RETRO_USE_NATIVE_OBJECTS
