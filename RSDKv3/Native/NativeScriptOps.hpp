#ifndef NATIVE_SCRIPT_OPS_H
#define NATIVE_SCRIPT_OPS_H

// =============================================================================
//  Script-opcode bridge for transpiled objects (retroscript2cpp output).
// -----------------------------------------------------------------------------
//  Every helper here reproduces the exact body of the matching FUNC_* opcode in
//  Script.cpp (same math, same globals, same quirks). Transpiled code calls
//  these so it behaves identically to the interpreted script it replaces.
// =============================================================================

#if RETRO_USE_NATIVE_OBJECTS

namespace Native
{
// Current ScriptSubs context (SUB_MAIN/...): set by ProcessNativeObject before
// dispatching into a native sub, so CallScriptFunction* calls made from native
// code inherit the caller's sub — same as the interpreter's function calls.
extern byte scriptSub;

// --- cross-object function dispatch (hybrid) --------------------------------
// Each transpiled object carries a table of its public script functions. At
// stage load InitNativeObjects() collects the tables of the objects bound in
// THIS stage into the active set (scripts' function names are per-stage: R1
// and R3 both have a NoGripArea with same-named functions — a global registry
// would cross-wire zones). CallScriptFunctionNamed routes to the active native
// function when present, else to the interpreted function of the same name
// (text-script mode), else logs and no-ops.
struct NativeFunctionDef {
    const char *name;
    void (*fn)();
};
void ClearActiveFunctions();
void AddActiveFunctions(const NativeFunctionDef *defs, int count);
void CallScriptFunctionNamed(const char *name, byte sub);

// Runtime function-ID of a script function by name (index into
// scriptFunctionList), or -1 if not loaded. Mirrors how the RSDK compiler bakes
// a function name used as a value into its ID; scripts store the ID and later
// CallFunction(storedID). Populated in both text and bytecode modes.
int ScriptFuncID(const char *name);

// --- misc variable helpers ---------------------------------------------------
int GetHapticsEnabled();
int GetObjectOutOfBounds(int index); // VAR_OBJECTOUTOFBOUNDS
int PlayerOutOfBounds();             // VAR_PLAYEROUTOFBOUNDS

// --- audio -------------------------------------------------------------------
void SetMusicTrack_Script(const char *path, int slot, int loopExtra); // FUNC_SETMUSICTRACK

// --- collision ---------------------------------------------------------------
void ObjectTileCollision_Script(int side, int xOff, int yOff, int plane); // FUNC_OBJECTTILECOLLISION
void ObjectTileGrip_Script(int side, int xOff, int yOff, int plane);      // FUNC_OBJECTTILEGRIP
void PlayerTileCollision_Script();                                        // FUNC_PLAYERTILECOLLISION
void CheckTouchRect_Script(int x1, int y1, int x2, int y2);               // FUNC_CHECKTOUCHRECT

// --- entities / players ------------------------------------------------------
void BindPlayerToObject_Script(int playerID, int entityNo); // FUNC_BINDPLAYERTOOBJECT
void ProcessAnimation_Script();                             // FUNC_PROCESSANIMATION
void DrawObjectAnimation_Script();                          // FUNC_DRAWOBJECTANIMATION
void DrawPlayerAnimation_Script();                          // FUNC_DRAWPLAYERANIMATION

// --- drawing -----------------------------------------------------------------
void DrawSprite_FrameXY(int frameID, int xpos, int ypos);            // FUNC_DRAWSPRITEXY (world coords)
void DrawSprite_ScreenXY(int frameID, int xpos, int ypos);           // FUNC_DRAWSPRITESCREENXY
void DrawSpriteFX_Script(int frameID, int fx, int xpos, int ypos);   // FUNC_DRAWSPRITEFX (all FX modes)
void DrawSpriteScreenFX_Script(int frameID, int fx, int xpos, int ypos); // FUNC_DRAWSPRITESCREENFX
void DrawNumbers_Script(int frame, int x, int y, int value, int digits, int digitWidth, int alignRight); // FUNC_DRAWNUMBERS
void DrawActName_Script(int frame, int x, int y, int mode, int capitalize, int spaceWidth, int spacing); // FUNC_DRAWACTNAME
void EditFrame_Script(int frameID, int px, int py, int w, int h, int sx, int sy); // FUNC_EDITFRAME
void LoadAnimation_Script(const char *path);                         // FUNC_LOADANIMATION
int  GetAnimationByName(const char *name);                           // FUNC_GETANIMATIONBYNAME

// --- tiles -------------------------------------------------------------------
int  Get16x16TileInfo_Script(int x, int y, int infoType);            // FUNC_GET16X16TILEINFO
void Set16x16TileInfo_Script(int value, int x, int y, int infoType); // FUNC_SET16X16TILEINFO

// --- menus / text ------------------------------------------------------------
void SetupMenu_Script(int menuID, int rowStart, int selectionCount, int alignment); // FUNC_SETUPMENU
void AddMenuEntry_Script(int menuID, const char *text, int highlight);              // FUNC_ADDMENUENTRY
void EditMenuEntry_Script(int menuID, const char *text, int rowID, int highlight);  // FUNC_EDITMENUENTRY
void DrawMenu_Script(int menuID, int x, int y);                                     // FUNC_DRAWMENU
void LoadTextFile_Script(int menuID, const char *path, int mapCode);                // FUNC_LOADTEXTFILE
void DrawText_Script(int menuID, int x, int y, int scaleX, int scaleY, int rowStart, int rowCount); // FUNC_DRAWTEXT
int  GetTextInfo_Script(int menuID, int infoType, int rowID, int charID);           // FUNC_GETTEXTINFO
void GetVersionNumber_Script(int menuID, int highlight);                            // FUNC_GETVERSIONNUMBER

// --- system ------------------------------------------------------------------
void LoadOnlineMenu_Script(int menuID);                       // FUNC_LOADONLINEMENU
void HapticEffect_Script(int id, int a, int b, int c);        // FUNC_HAPTICEFFECT
void LoadVideo_Script(const char *path);                      // FUNC_LOADVIDEO

// --- 3D ------------------------------------------------------------------
void Draw3DScene_Script();                                    // FUNC_DRAW3DSCENE
void SetIdentityMatrixM(int m);                               // FUNC_SETIDENTITYMATRIX
void MatrixMultiplyM(int a, int b);                           // FUNC_MATRIXMULTIPLY
void MatrixTranslateXYZM(int m, int x, int y, int z);         // FUNC_MATRIXTRANSLATEXYZ
void MatrixScaleXYZM(int m, int x, int y, int z);             // FUNC_MATRIXSCALEXYZ
void MatrixRotateXM(int m, int angle);                        // FUNC_MATRIXROTATEX
void MatrixRotateYM(int m, int angle);                        // FUNC_MATRIXROTATEY
void MatrixRotateZM(int m, int angle);                        // FUNC_MATRIXROTATEZ
void MatrixRotateXYZM(int m, int x, int y, int z);            // FUNC_MATRIXROTATEXYZ
void TransformVerticesM(int m, int startIndex, int endIndex); // FUNC_TRANSFORMVERTICES
} // namespace Native

#endif // RETRO_USE_NATIVE_OBJECTS
#endif // !NATIVE_SCRIPT_OPS_H
