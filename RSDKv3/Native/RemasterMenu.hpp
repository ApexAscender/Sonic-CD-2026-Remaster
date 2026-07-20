#ifndef REMASTER_MENU_H
#define REMASTER_MENU_H

// =============================================================================
//  Remastered Main Menu  (SonicCD-Native)
// -----------------------------------------------------------------------------
//  A fully custom, high-resolution main menu that replaces the stock mode-select
//  screen. It renders its own modern UI (SDL primitives at window resolution),
//  handles its own navigation, and on confirm it drives the game's REAL menu
//  transition for that option (by activating the matching stock Menu Button), so
//  Play / Time Attack / Options / Extras / Soundtrack / Exit all still work.
//
//  Hooks:
//    * after ProcessInput (RetroEngine.cpp) -> Update()  (nav + confirm, then it
//      swallows the frame's input so the stock menu underneath stays put)
//    * before the SW present (Drawing.cpp)  -> Render()   (draws over everything)
// =============================================================================

#if RETRO_USE_NATIVE_OBJECTS

struct SDL_Renderer;

namespace RemasterMenu
{
// True while the stock main mode-select menu is the active screen.
bool Active();
// Per-frame: read input, move the selection / confirm, then neutralise the
// frame's game input so the stock menu doesn't also react.
void Update();
// Draw the custom menu at the renderer's output resolution.
void Render(SDL_Renderer *renderer);

// --- PLAY / save-select screen (visual overlay; stock object handles input) --
// True while the save-select "browsing" screen is up.
bool PlayActive();
// Draw the modern save-select over the stock screen.
void PlayRender(SDL_Renderer *renderer);

// --- EXTRAS submenu ----------------------------------------------------------
bool ExtrasActive();
void ExtrasRender(SDL_Renderer *renderer);

// --- TIME ATTACK (zone-select grid + per-zone records sub-menu) --------------
// True while the Time Attack menu (its own "TAttack" stage) is the active screen.
bool TAActive();
// Draw the modern zone-select / records screens over the stock Time Attack menu.
void TARender(SDL_Renderer *renderer);

// --- OPTIONS (working settings panel — volume / spin dash / credits) ---------
// True while the interactive settings list owns input (parks the stock object).
bool OptionsActive();
// Per-frame: adjust settings live, then swallow the frame's input.
void OptionsUpdate();
// Draw the settings panel over the stock Options screen.
void OptionsRender(SDL_Renderer *renderer);
// Raw SDL keydown capture for control rebinding (returns true if consumed).
bool OptionsCaptureKey(int scancode);

// --- SOUNDTRACK (JP / US / … selector with an animated CD swap) --------------
bool OstActive();
void OstRender(SDL_Renderer *renderer);

// --- PAUSE (in-game pause menu, over frozen gameplay) ------------------------
// True while the stock "Pause Menu" object (entity 9) is up during a gameplay
// stage. We own its input (PauseUpdate) and draw a hi-res overlay (PauseRender).
bool PauseActive();
void PauseUpdate();
void PauseRender(SDL_Renderer *renderer);

// -----------------------------------------------------------------------------
//  Draw-suppression: while a remastered overlay is covering a menu screen, the
//  matching stock menu object's low-res draw is skipped entirely (its logic
//  still runs). Called from the native object dispatch for SUB_DRAW.
// -----------------------------------------------------------------------------
bool SuppressStockMenuDraw(int type);

// Draw every active remastered menu overlay (called once from FlipScreen).
void RenderAll(SDL_Renderer *renderer);

// Per-frame (Menu stage, logic phase): fast-forward the stock menu-transition
// timers (button entrance/confirm slides, section fade-ins) so switching between
// sections is snappy instead of waiting on long stock animations.
void AccelMenu();
}

#endif // RETRO_USE_NATIVE_OBJECTS
#endif // !REMASTER_MENU_H
