#ifndef NATIVE_OBJECT_H
#define NATIVE_OBJECT_H

// =============================================================================
//  Native Object Layer  (RSDKv3-Decompilation)
// -----------------------------------------------------------------------------
//  Lets hand-written C++ objects run in place of the RetroScript bytecode for a
//  given object type, WITHOUT removing the interpreter. Any object type that is
//  not registered here keeps running its script exactly as before, so we can
//  migrate the ~591 scripts one at a time and diff each against the live game.
//
//  Dispatch is intercepted at the top of ProcessScript(): if a native handler
//  is registered for (objectType, scriptSub) it runs and the interpreter is
//  skipped. The four subs mirror ScriptSubs: MAIN / PLAYERINTERACTION / DRAW /
//  SETUP, and share the engine's ambient state (objectLoop, activePlayer,
//  scriptEng.checkResult, scriptFrames, etc.), so a native object behaves
//  identically to the script it replaces.
// =============================================================================

#ifndef RETRO_USE_NATIVE_OBJECTS
#define RETRO_USE_NATIVE_OBJECTS (!RETRO_USE_ORIGINAL_CODE && 1)
#endif

#if RETRO_USE_NATIVE_OBJECTS

// One native object = up to four sub callbacks. Any may be null, in which case
// that sub falls back to the script (so you can port Draw first, Main later).
typedef void (*NativeObjectSub)();

namespace Native
{
struct NativeFunctionDef; // NativeScriptOps.hpp
}

struct NativeObjectHooks {
    // Script path as listed in GameConfig/StageConfig (e.g. "R1/Platform.txt").
    // This is the binding key: object NAMES repeat across stages ("Platform" in
    // several zones names different scripts), paths are unique.
    const char *scriptPath;
    const char *name; // display name (filename stem), for logs
    NativeObjectSub subMain;
    NativeObjectSub subPlayerInteraction;
    NativeObjectSub subDraw;
    NativeObjectSub subSetup;
    const Native::NativeFunctionDef *funcs; // public script functions of this object
    int funcCount;
};

// Per-type script path for the currently loading stage, recorded by
// LoadStageFiles as it reads GameConfig/StageConfig (works in bytecode mode
// too — the configs carry the paths even when scripts aren't text-parsed).
extern char objectScriptPaths[OBJECT_COUNT][0x40];

// Resolve registered script paths -> live type IDs and build the stage's
// active native-function set. Must run after object type names/paths are
// recorded and before ProcessStartupObjects(), i.e. once per stage.
void InitNativeObjects();

// Returns true if this (type, sub) was handled natively; false -> run the script.
bool ProcessNativeObject(int type, byte scriptSub);

// Returns true if this type has a native implementation for the given sub, so the
// engine can run it even with no bytecode loaded.
bool NativeObjectHasSub(int type, byte scriptSub);

// -----------------------------------------------------------------------------
//  Script-API bridge helpers
//  Thin, correctness-preserving wrappers so object code reads like the original
//  script. Each one reproduces the exact math of the matching FUNC_* opcode.
// -----------------------------------------------------------------------------
namespace Native
{
// --- current object ("Object.*") ---
inline Entity *Self() { return &objectEntityList[objectLoop]; }

// --- current player ("Player.*") ---
// Player.Speed/YVelocity/Gravity/... live on the Player struct, but Player.State,
// Player.Animation and Player.Direction live on the player's BOUND ENTITY. This
// split mirrors how VAR_PLAYER* resolves in Script.cpp.
inline Player *Plr() { return &playerList[activePlayer]; }
inline Entity *PlrEntity() { return playerList[activePlayer].boundEntity; }

// Player.ValueN is SPLIT across two arrays (see VAR_PLAYERVALUE* in Script.cpp):
//   Value0..7  -> boundEntity->values[0..7]   (the player entity)
//   Value8..15 -> Player::values[0..7]         (the Player struct)
// Always go through this accessor so the split can't be gotten wrong.
inline int &PlayerValue(int idx)
{
    return (idx < 8) ? playerList[activePlayer].boundEntity->values[idx] : playerList[activePlayer].values[idx - 8];
}

// --- "CheckResult" ---
inline int &CheckResult() { return scriptEng.checkResult; }

// PlayerObjectCollision(type, l, t, r, b) — mirrors FUNC_PLAYEROBJECTCOLLISION,
// including the PC-vs-mobile bytecode split for C_BOX2 / C_PLATFORM.
void PlayerObjectCollision(int type, int left, int top, int right, int bottom);

// DrawSpriteFX(frame, FX_FLIP, x, y) — mirrors FUNC_DRAWSPRITEFX's FX_FLIP path.
void DrawSpriteFX_Flip(int frameID, int xpos, int ypos);

// DrawSprite(frame) — single-arg form: draws a frame at the current object's
// position (mirrors FUNC_DRAWSPRITE). Used by transpiled objects.
void DrawSprite_Frame(int frameID);

// Global-variable lvalue by name (GameConfig globals like "Ring.Frame").
// Name lookup per access; returns a scratch ref if the name is unknown.
inline int &GVar(const char *name)
{
    static int scratch = 0;
    int id = GetGlobalVariableID(name);
    if (id < 0 || id >= GLOBALVAR_COUNT) {
        scratch = 0;
        return scratch;
    }
    return globalVariables[id];
}

// Resolve an object name ("Dust Puff") to its live type ID, matching how the
// script's TypeName[...] resolves. Spaces are stripped to match typeNames[].
// Returns 0 (blank object) if not found.
int TypeNameID(const char *name);

// Call a still-interpreted script function by ID (mirrors FUNC_CALLFUNCTION).
// Used for dynamic dispatch like CallFunction(Player.JumpAbility) during the
// hybrid phase, and temporarily suppresses the native-object hook so a native
// object that calls back into its own script functions can't recurse into itself.
void CallScriptFunction(int functionID, byte scriptSub);

// Spawn a temp entity into the rolling temp-slot ring (mirrors FUNC_CREATETEMPOBJECT).
// Returns the slot index (== script's TempObjectPos).
int CreateTempObject(int type, int propertyValue, int xpos, int ypos);

// Reset a specific entity slot (mirrors FUNC_RESETOBJECTENTITY).
void ResetObjectEntity(int slot, int type, int propertyValue, int xpos, int ypos);

// ObjectStartup helpers — mirror FUNC_LOADSPRITESHEET / FUNC_SPRITEFRAME. These
// depend on ProcessStartupObjects() having set frameListOffset before the call,
// which the SETUP hook guarantees.
void LoadSpriteSheet(const char *path);
// Named AddSpriteFrame (not SpriteFrame) to avoid clashing with the engine's
// `struct SpriteFrame`; behaviour matches the script's SpriteFrame() call.
void AddSpriteFrame(int pivotX, int pivotY, int width, int height, int sprX, int sprY);
} // namespace Native

#endif // RETRO_USE_NATIVE_OBJECTS
#endif // !NATIVE_OBJECT_H
