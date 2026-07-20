#include "RetroEngine.hpp"

#if RETRO_USE_NATIVE_OBJECTS

#include "RemasterMenu.hpp"
#include "NativeObject.hpp"
#include "Input.hpp"
#include <math.h>
#include <string>
#include <map>

#if RETRO_USE_TTF
#include <SDL_ttf.h>
#endif
#if RETRO_USE_IMG
#include <SDL_image.h>
#endif

using namespace Native;

// =============================================================================
//  Fully custom modern main menu — light frosted theme, condensed anti-aliased
//  type (SDL_ttf), instant navigation, and a large per-option "feature card"
//  with procedural iconography. Backgrounds, accents and the card pulse in time
//  with the menu music (via audioMeterPeak / audioMeterBass from Audio.cpp),
//  falling back to a gentle idle animation when nothing is playing.
// =============================================================================

namespace RemasterMenu
{
// ---- easing -----------------------------------------------------------------
static inline float clamp01(float x) { return x < 0 ? 0 : (x > 1 ? 1 : x); }
static inline float easeOutCubic(float x) { x = clamp01(x); float u = 1 - x; return 1 - u * u * u; }
static inline float easeOutQuint(float x) { x = clamp01(x); float u = 1 - x; return 1 - u * u * u * u * u; }
static inline float easeInOutCubic(float x) { x = clamp01(x); return x < 0.5f ? 4 * x * x * x : 1 - powf(-2 * x + 2, 3) / 2; }
static inline float easeOutBack(float x)
{
    x = clamp01(x);
    const float c1 = 1.70158f, c3 = c1 + 1.0f;
    float u = x - 1.0f;
    return 1.0f + c3 * u * u * u + c1 * u * u;
}
static const float TAU = 6.28318530718f;

// ---- SDL primitive helpers --------------------------------------------------
static SDL_Renderer *R = nullptr;
static inline void rect(float x, float y, float w, float h)
{
    SDL_FRect fr = { x, y, w, h };
    SDL_RenderFillRectF(R, &fr);
}
static void tri(float x1, float y1, float x2, float y2, float x3, float y3, SDL_Color c)
{
    SDL_Vertex v[3];
    v[0].position = { x1, y1 }; v[0].color = c; v[0].tex_coord = { 0, 0 };
    v[1].position = { x2, y2 }; v[1].color = c; v[1].tex_coord = { 0, 0 };
    v[2].position = { x3, y3 }; v[2].color = c; v[2].tex_coord = { 0, 0 };
    SDL_RenderGeometry(R, nullptr, v, 3, nullptr, 0);
}
static void gradRect(float x, float y, float w, float h, SDL_Color a, SDL_Color b, bool horizontal)
{
    SDL_Vertex v[4];
    SDL_Color c0 = a, c1 = horizontal ? b : a, c2 = b, c3 = horizontal ? a : b;
    v[0].position = { x, y };         v[0].color = c0;
    v[1].position = { x + w, y };     v[1].color = c1;
    v[2].position = { x + w, y + h }; v[2].color = c2;
    v[3].position = { x, y + h };     v[3].color = c3;
    for (int i = 0; i < 4; ++i) v[i].tex_coord = { 0, 0 };
    const int idx[6] = { 0, 1, 2, 0, 2, 3 };
    SDL_RenderGeometry(R, nullptr, v, 4, idx, 6);
}
static void circle(float cx, float cy, float r, SDL_Color c)
{
    const int N = 32;
    SDL_Vertex v[3];
    for (int i = 0; i < N; ++i) {
        float a0 = (float)i / N * TAU, a1 = (float)(i + 1) / N * TAU;
        v[0].position = { cx, cy };
        v[1].position = { cx + cosf(a0) * r, cy + sinf(a0) * r };
        v[2].position = { cx + cosf(a1) * r, cy + sinf(a1) * r };
        for (int k = 0; k < 3; ++k) { v[k].color = c; v[k].tex_coord = { 0, 0 }; }
        SDL_RenderGeometry(R, nullptr, v, 3, nullptr, 0);
    }
}
// ---- Sonic CD logo image (loaded once, drawn in the header) -----------------
static SDL_Texture *s_logoTex = nullptr;
static int  s_logoW = 0, s_logoH = 0;
static bool s_logoTried = false;
// zone-preview atlas for Time Attack (declared here so clearCache can free it)
static SDL_Texture *s_taSheet = nullptr;
static bool s_taSheetTried = false;
static void ensureLogo()
{
    if (s_logoTried) return;
    s_logoTried = true;
#if RETRO_USE_IMG
    // tried relative to the working dir (SonicCD-Native/) with a couple fallbacks
    static const char *paths[] = { "images/Sonic_Logo.png", "./images/Sonic_Logo.png",
                                   "SonicCD-Native/images/Sonic_Logo.png" };
    for (const char *p : paths) {
        SDL_Surface *surf = IMG_Load(p);
        if (!surf) continue;
        s_logoW = surf->w; s_logoH = surf->h;
        s_logoTex = SDL_CreateTextureFromSurface(R, surf);
        SDL_FreeSurface(surf);
        if (s_logoTex) SDL_SetTextureBlendMode(s_logoTex, SDL_BLENDMODE_BLEND);
        break;
    }
#endif
}
static float logoWidthFor(float targetH) { return (s_logoTex && s_logoH > 0) ? s_logoW * (targetH / s_logoH) : 0.0f; }
static void drawLogo(float x, float cy, float targetH, Uint8 a)
{
    ensureLogo();
    if (!s_logoTex || s_logoH <= 0) return;
    float w = logoWidthFor(targetH);
    SDL_SetTextureAlphaMod(s_logoTex, a);
    SDL_FRect dst = { x, cy - targetH * 0.5f, w, targetH };
    SDL_RenderCopyF(R, s_logoTex, nullptr, &dst);
    SDL_SetTextureAlphaMod(s_logoTex, 255);
}

// annulus / ring outline
static void ring(float cx, float cy, float rO, float rI, SDL_Color c, int N = 40, float a0 = 0, float a1 = TAU)
{
    for (int i = 0; i < N; ++i) {
        float t0 = a0 + (a1 - a0) * i / N, t1 = a0 + (a1 - a0) * (i + 1) / N;
        float co0 = cosf(t0), si0 = sinf(t0), co1 = cosf(t1), si1 = sinf(t1);
        SDL_Vertex v[6];
        v[0].position = { cx + co0 * rO, cy + si0 * rO };
        v[1].position = { cx + co1 * rO, cy + si1 * rO };
        v[2].position = { cx + co1 * rI, cy + si1 * rI };
        v[3].position = { cx + co0 * rO, cy + si0 * rO };
        v[4].position = { cx + co1 * rI, cy + si1 * rI };
        v[5].position = { cx + co0 * rI, cy + si0 * rI };
        for (int k = 0; k < 6; ++k) { v[k].color = c; v[k].tex_coord = { 0, 0 }; }
        SDL_RenderGeometry(R, nullptr, v, 6, nullptr, 0);
    }
}
// thick stroked line
static void line(float x1, float y1, float x2, float y2, float th, SDL_Color c)
{
    float dx = x2 - x1, dy = y2 - y1;
    float len = sqrtf(dx * dx + dy * dy);
    if (len < 0.0001f) return;
    float nx = -dy / len * th * 0.5f, ny = dx / len * th * 0.5f;
    SDL_Vertex v[6];
    v[0].position = { x1 + nx, y1 + ny };
    v[1].position = { x2 + nx, y2 + ny };
    v[2].position = { x2 - nx, y2 - ny };
    v[3].position = { x1 + nx, y1 + ny };
    v[4].position = { x2 - nx, y2 - ny };
    v[5].position = { x1 - nx, y1 - ny };
    for (int k = 0; k < 6; ++k) { v[k].color = c; v[k].tex_coord = { 0, 0 }; }
    SDL_RenderGeometry(R, nullptr, v, 6, nullptr, 0);
}
// filled n-point star
static void star(float cx, float cy, float rO, float rI, int pts, float rot, SDL_Color c)
{
    int N = pts * 2;
    for (int i = 0; i < N; ++i) {
        float a0 = rot + (float)i / N * TAU, a1 = rot + (float)(i + 1) / N * TAU;
        float r0 = (i & 1) ? rI : rO, r1 = (i & 1) ? rO : rI;
        tri(cx, cy, cx + cosf(a0) * r0, cy + sinf(a0) * r0, cx + cosf(a1) * r1, cy + sinf(a1) * r1, c);
    }
}
// soft rounded panel — filled as ONE convex polygon (triangle fan from the
// centre) so translucent fills blend uniformly with no overlapping/seamed
// corner circles.
static void roundRect(float x, float y, float w, float h, float r, SDL_Color c)
{
    if (r < 0) r = 0;
    if (r > w * 0.5f) r = w * 0.5f;
    if (r > h * 0.5f) r = h * 0.5f;
    const int CS = 12; // segments per corner (smooth, artifact-free corners)
    SDL_FPoint pts[4 * (CS + 1)];
    int n = 0;
    const float cxs[4] = { x + w - r, x + w - r, x + r,     x + r };
    const float cys[4] = { y + r,     y + h - r, y + h - r, y + r };
    const float a0s[4] = { -1.5708f,  0.0f,      1.5708f,   3.14159f };
    for (int k = 0; k < 4; ++k)
        for (int s = 0; s <= CS; ++s) {
            float a = a0s[k] + 1.5708f * s / CS;
            pts[n].x = cxs[k] + cosf(a) * r;
            pts[n].y = cys[k] + sinf(a) * r;
            ++n;
        }
    float ccx = x + w * 0.5f, ccy = y + h * 0.5f;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        tri(ccx, ccy, pts[i].x, pts[i].y, pts[j].x, pts[j].y, c);
    }
}

// ---- text (SDL_ttf, cached) -------------------------------------------------
#if RETRO_USE_TTF
static bool s_ttfReady    = false;
static const char *s_fontPath = nullptr;
static SDL_Renderer *s_cacheOwner = nullptr;
static std::map<int, TTF_Font *> s_fonts;
struct Cached { SDL_Texture *tex; int w, h; };
static std::map<std::string, Cached> s_text;

static void clearCache()
{
    for (auto &kv : s_text) SDL_DestroyTexture(kv.second.tex);
    s_text.clear();
    for (auto &kv : s_fonts) TTF_CloseFont(kv.second);
    s_fonts.clear();
    if (s_logoTex) { SDL_DestroyTexture(s_logoTex); s_logoTex = nullptr; }
    s_logoTried = false; // reload against the new renderer
    if (s_taSheet) { SDL_DestroyTexture(s_taSheet); s_taSheet = nullptr; }
    s_taSheetTried = false;
}
static bool ensureTTF()
{
    if (s_ttfReady) return true;
    if (TTF_WasInit() == 0 && TTF_Init() != 0) return false;
    static const char *cands[] = { "C:/Windows/Fonts/bahnschrift.ttf", "C:/Windows/Fonts/seguisb.ttf",
                                   "C:/Windows/Fonts/segoeui.ttf", "C:/Windows/Fonts/arial.ttf" };
    for (const char *c : cands) {
        SDL_RWops *f = SDL_RWFromFile(c, "rb");
        if (f) { SDL_RWclose(f); s_fontPath = c; break; }
    }
    if (!s_fontPath) return false;
    s_ttfReady = true;
    return true;
}
static TTF_Font *fontAt(int px)
{
    if (px < 8) px = 8;
    auto it = s_fonts.find(px);
    if (it != s_fonts.end()) return it->second;
    TTF_Font *f = TTF_OpenFont(s_fontPath, px);
    s_fonts[px] = f;
    return f;
}
// align: 0=left 1=center 2=right. scale multiplies the cached texture size.
static void drawText(float x, float y, const char *s, int px, SDL_Color col, int align, bool bold, float scale = 1.0f)
{
    if (!ensureTTF() || !s || !*s) return;
    char key[256];
    snprintf(key, sizeof(key), "%d|%d|%02x%02x%02x|%s", px, bold ? 1 : 0, col.r, col.g, col.b, s);
    std::string k = key;
    Cached cc;
    auto it = s_text.find(k);
    if (it == s_text.end()) {
        TTF_Font *f = fontAt(px);
        if (!f) return;
        TTF_SetFontStyle(f, bold ? TTF_STYLE_BOLD : TTF_STYLE_NORMAL);
        // IMPORTANT: bake the glyph texture at FULL opacity and modulate alpha at
        // draw time. Rendering with col's (possibly mid-fade) alpha would cache a
        // dim/transparent texture forever, since the cache key ignores alpha —
        // that made text first drawn during a fade stay invisible.
        SDL_Color oc = { col.r, col.g, col.b, 255 };
        SDL_Surface *surf = TTF_RenderUTF8_Blended(f, s, oc);
        if (!surf) return;
        cc.tex = SDL_CreateTextureFromSurface(R, surf);
        cc.w = surf->w; cc.h = surf->h;
        SDL_FreeSurface(surf);
        if (!cc.tex) return;                 // retry next frame instead of caching null
        SDL_SetTextureBlendMode(cc.tex, SDL_BLENDMODE_BLEND);
        s_text[k] = cc;
    } else {
        cc = it->second;
    }
    float w = cc.w * scale, h = cc.h * scale;
    float dx = (align == 1) ? x - w * 0.5f : (align == 2) ? x - w : x;
    float dy = y - (h - cc.h) * 0.5f;
    SDL_SetTextureAlphaMod(cc.tex, col.a);
    SDL_FRect dst = { dx, dy, w, h };
    SDL_RenderCopyF(R, cc.tex, nullptr, &dst);
    SDL_SetTextureAlphaMod(cc.tex, 255);
}
static int textWidth(const char *s, int px, bool bold)
{
    if (!ensureTTF() || !s || !*s) return 0;
    TTF_Font *f = fontAt(px);
    if (!f) return 0;
    TTF_SetFontStyle(f, bold ? TTF_STYLE_BOLD : TTF_STYLE_NORMAL);
    int w = 0, h = 0;
    TTF_SizeUTF8(f, s, &w, &h);
    return w;
}
// Text rotated `angleDeg` (clockwise), centred at (cx,cy). Reuses drawText's cache.
static void drawTextRot(float cx, float cy, const char *s, int px, SDL_Color col, bool bold, float angleDeg)
{
    if (!ensureTTF() || !s || !*s) return;
    char key[256];
    snprintf(key, sizeof(key), "%d|%d|%02x%02x%02x|%s", px, bold ? 1 : 0, col.r, col.g, col.b, s);
    std::string k = key;
    Cached cc;
    auto it = s_text.find(k);
    if (it == s_text.end()) {
        TTF_Font *f = fontAt(px);
        if (!f) return;
        TTF_SetFontStyle(f, bold ? TTF_STYLE_BOLD : TTF_STYLE_NORMAL);
        SDL_Color oc = { col.r, col.g, col.b, 255 };
        SDL_Surface *surf = TTF_RenderUTF8_Blended(f, s, oc);
        if (!surf) return;
        cc.tex = SDL_CreateTextureFromSurface(R, surf);
        cc.w = surf->w; cc.h = surf->h;
        SDL_FreeSurface(surf);
        if (!cc.tex) return;
        SDL_SetTextureBlendMode(cc.tex, SDL_BLENDMODE_BLEND);
        s_text[k] = cc;
    } else {
        cc = it->second;
    }
    SDL_SetTextureAlphaMod(cc.tex, col.a);
    SDL_FRect dst = { cx - cc.w * 0.5f, cy - cc.h * 0.5f, (float)cc.w, (float)cc.h };
    SDL_RenderCopyExF(R, cc.tex, nullptr, &dst, angleDeg, nullptr, SDL_FLIP_NONE);
    SDL_SetTextureAlphaMod(cc.tex, 255);
}
#else
static void clearCache() {}
static void drawText(float, float, const char *, int, SDL_Color, int, bool, float = 1.0f) {}
static int textWidth(const char *, int, bool) { return 0; }
static void drawTextRot(float, float, const char *, int, SDL_Color, bool, float) {}
#endif

// Forward decls for premium helpers defined further down (used by earlier
// overlays such as the Play character-select too).
static void glossTop(float x, float y, float w, float h, Uint8 a);
static void drawTextFit(float cx, float y, const char *s, int px, SDL_Color col, float maxW, bool bold);

// ---- menu model -------------------------------------------------------------
static const int BTN_BASE = 34;
static int buttonCount()
{
    int n = objectEntityList[1].values[2];
    if (n < 1) n = 1;
    if (n > 9) n = 9;
    return n;
}
// Leaderboards (pv 4) is a non-functional stub on standalone PC (its handler
// calls LoadOnlineMenu, a no-op), so we hide that dead button. Achievements
// (pv 3) is kept — the user plans to implement it — even though it's inert today.
static inline bool buttonHidden(int pv) { return pv == 4; }
// Fill idx[] with the stock button offsets (0-based from BTN_BASE) that are shown,
// skipping hidden stubs. Returns the visible count (>= 1).
static int visibleButtons(int idx[9])
{
    int n = 0;
    int raw = buttonCount();
    for (int i = 0; i < raw; ++i)
        if (!buttonHidden(objectEntityList[BTN_BASE + i].propertyValue)) idx[n++] = i;
    if (n < 1) { idx[0] = 0; n = 1; }
    return n;
}
static const char *labelFor(int pv)
{
    switch (pv) {
        case 1: return "PLAY";
        case 2: return "TIME ATTACK";
        case 3: return "ACHIEVEMENTS";
        case 4: return "LEADERBOARDS";
        case 5: return "OPTIONS";
        case 6: return "EXTRAS";
        case 7: return "MANIA MODE";
        case 9: return "EXIT";
        case 10: return "SOUNDTRACK";
        case 11: return "TROPHIES";
        default: return "MENU";
    }
}
static const char *tagFor(int pv)
{
    switch (pv) {
        case 1: return "NEW GAME";
        case 2: return "CHALLENGE";
        case 3: return "PROGRESS";
        case 4: return "RANKINGS";
        case 5: return "SETTINGS";
        case 6: return "BONUS";
        case 9: return "QUIT";
        case 10: return "MUSIC";
        case 11: return "AWARDS";
        default: return "MENU";
    }
}
static const char *descFor(int pv)
{
    switch (pv) {
        case 1: return "Start a new game or continue your journey through time.";
        case 2: return "Race against the clock on any stage you have unlocked.";
        case 3: return "View the achievements you have earned.";
        case 4: return "See how your times rank against the world.";
        case 5: return "Adjust display, sound, and control settings.";
        case 6: return "Bonus content, artwork, and unlockables.";
        case 9: return "Return to your desktop.";
        case 10: return "Switch between the JP and US soundtracks.";
        case 11: return "Review your trophies.";
        default: return "";
    }
}

// ---- per-option procedural icon --------------------------------------------
// Drawn centred at (cx,cy) with overall radius s. `spin` accumulates over time,
// `bass` (0..1) lets the icon breathe on the beat.
static void drawIcon(int pv, float cx, float cy, float s, SDL_Color col, float t, float spin, float bass)
{
    SDL_Color soft = col; soft.a = (Uint8)(col.a * 0.42f);
    switch (pv) {
        case 1: { // PLAY — play triangle inside a ring
            ring(cx, cy, s, s * 0.86f, soft);
            float p = 0.28f + 0.05f * bass;
            tri(cx - s * p, cy - s * 0.44f, cx - s * p, cy + s * 0.44f, cx + s * 0.5f, cy, col);
            break;
        }
        case 2: { // TIME ATTACK — stopwatch
            ring(cx, cy + s * 0.06f, s * 0.92f, s * 0.74f, col);
            rect(cx - s * 0.10f, cy - s * 1.06f, s * 0.20f, s * 0.20f); // crown stem
            for (int i = 0; i < 12; ++i) {
                float a = i / 12.0f * TAU;
                float rr = s * 0.80f;
                line(cx + cosf(a) * rr, cy + s * 0.06f + sinf(a) * rr,
                     cx + cosf(a) * rr * 0.88f, cy + s * 0.06f + sinf(a) * rr * 0.88f, s * 0.05f, soft);
            }
            float ha = -1.5708f + t * 3.2f;              // sweeping hand
            line(cx, cy + s * 0.06f, cx + cosf(ha) * s * 0.6f, cy + s * 0.06f + sinf(ha) * s * 0.6f, s * 0.07f, col);
            circle(cx, cy + s * 0.06f, s * 0.09f, col);
            break;
        }
        case 3: { // ACHIEVEMENTS — medal (ribbon + star disc)
            tri(cx - s * 0.42f, cy - s * 0.9f, cx - s * 0.08f, cy - s * 0.9f, cx - s * 0.05f, cy + s * 0.1f, soft);
            tri(cx + s * 0.42f, cy - s * 0.9f, cx + s * 0.08f, cy - s * 0.9f, cx + s * 0.05f, cy + s * 0.1f, soft);
            ring(cx, cy + s * 0.28f, s * 0.7f, s * 0.55f, col);
            star(cx, cy + s * 0.28f, s * 0.42f, s * 0.17f, 5, -1.5708f + spin * 0.4f, col);
            break;
        }
        case 4: { // LEADERBOARDS — three bars that ride the beat
            SDL_SetRenderDrawColor(R, col.r, col.g, col.b, col.a); // rect() uses the ambient color
            float base = cy + s * 0.8f, bw = s * 0.34f, gap = s * 0.06f;
            float hs[3] = { 0.7f, 1.25f, 0.95f };
            for (int i = 0; i < 3; ++i) {
                float pulse = 1.0f + bass * 0.35f * sinf(t * 6.0f + i);
                float hh = s * hs[i] * pulse;
                float bx = cx + (i - 1) * (bw + gap) - bw * 0.5f;
                rect(bx, base - hh, bw, hh);
            }
            break;
        }
        case 5: { // OPTIONS — rotating cog
            int teeth = 8;
            for (int i = 0; i < teeth; ++i) {
                float a = spin * 0.6f + i / (float)teeth * TAU;
                float rr = s * 1.02f;
                float tw = s * 0.24f;
                float ca = cosf(a), sa = sinf(a);
                float px = cx + ca * rr, py = cy + sa * rr;
                float ox = -sa * tw, oy = ca * tw;
                tri(px + ox, py + oy, px - ox, py - oy, cx + ca * s * 0.7f, cy + sa * s * 0.7f, col);
            }
            ring(cx, cy, s * 0.78f, s * 0.34f, col);
            break;
        }
        case 6: { // EXTRAS — slowly turning star
            ring(cx, cy, s, s * 0.9f, soft);
            star(cx, cy, s * 0.72f, s * 0.3f, 5, -1.5708f + spin * 0.5f, col);
            break;
        }
        case 9: { // EXIT — power symbol
            ring(cx, cy + s * 0.08f, s * 0.86f, s * 0.66f, col, 40, -1.05f, TAU - 1.05f + TAU * -0.0f);
            // draw the arc as almost-full then punch the top with the stem
            ring(cx, cy + s * 0.08f, s * 0.86f, s * 0.66f, col, 40, -1.9f + TAU * 0.08f, TAU - 1.25f);
            line(cx, cy - s * 0.95f, cx, cy - s * 0.05f, s * 0.16f, col);
            break;
        }
        case 10: { // SOUNDTRACK — spinning CD (fitting for Sonic CD!)
            circle(cx, cy, s * (1.0f + 0.03f * bass), col);
            SDL_Color sheen = { 255, 255, 255, (Uint8)(col.a * 0.5f) };
            ring(cx, cy, s * 0.98f, s * 0.62f, sheen, 40, spin, spin + 1.5f);
            SDL_Color hole = { 236, 242, 248, col.a };
            circle(cx, cy, s * 0.34f, hole);
            ring(cx, cy, s * 0.34f, s * 0.24f, soft);
            break;
        }
        case 11: { // TROPHIES — cup
            ring(cx - s * 0.85f, cy - s * 0.35f, s * 0.42f, s * 0.24f, col, 24, -1.5708f, 1.5708f); // L handle
            ring(cx + s * 0.85f, cy - s * 0.35f, s * 0.42f, s * 0.24f, col, 24, 1.5708f, 4.7124f);  // R handle
            tri(cx - s * 0.7f, cy - s * 0.7f, cx + s * 0.7f, cy - s * 0.7f, cx, cy + s * 0.35f, col); // bowl
            rect(cx - s * 0.09f, cy + s * 0.3f, s * 0.18f, s * 0.4f);                                 // stem
            rect(cx - s * 0.45f, cy + s * 0.7f, s * 0.9f, s * 0.16f);                                 // base
            break;
        }
        default: {
            ring(cx, cy, s, s * 0.86f, col);
            circle(cx, cy, s * 0.3f, col);
            break;
        }
    }
}

static int s_sel      = 0;
static bool s_wasOn   = false;
static float s_barY   = -1.0f;
static Uint32 s_openAt = 0;
static Uint32 s_selAt  = 0;
static float s_uiBass = 0.0f;  // UI-side smoothed meters
static float s_uiPeak = 0.0f;
static float s_iconSpin = 0.0f;

// ---- activation -------------------------------------------------------------
bool Active()
{
    if (Engine.gameMode != ENGINE_MAINGAME)
        return false;
    if (!StrComp(currentStageFolder, (char *)"Menu"))
        return false;
    if (objectEntityList[0].type != TypeNameID("Menu Control"))
        return false;
    if (objectEntityList[62].type != 0)
        return false;
    // must be the actual interactive mode-select: a Menu Button present at the
    // first slot. Guards against ever activating over the title / a transition.
    if (objectEntityList[BTN_BASE].type != TypeNameID("Menu Button"))
        return false;
    return true;
}

// ---- input (instant; no waiting on the stock fade) --------------------------
//  When an overlay owns input, it must stop the parked stock object from ALSO
//  reacting to the same press. Clearing the `keyPress` global is NOT enough:
//  ProcessStage re-reads raw input via CheckKeyPress, which pulls from
//  inputDevice[].press directly. So we zero that raw edge here. We clear only
//  .press (not .hold) — setHeld() computes press = !hold, so zeroing .hold would
//  make a still-held key report a fresh press again next frame (auto-repeat).
//  Without this the stock object double-navigates and plays a SECOND nav SFX.
static void swallowMenuInput()
{
    for (int i = 0; i < INPUT_BUTTONCOUNT; ++i)
        inputDevice[i].press = false;
    keyDown = InputData(); keyPress = InputData(); anyPress = false;
}

void Update()
{
    // keyPress is only filled by ProcessStage, which runs AFTER this hook — and
    // swallowMenuInput() clears the raw inputDevice edge, so relying on the stock
    // to fill keyPress would leave us reading zeros. Fill it now from the fresh
    // per-frame input (ProcessInput ran just before us) so our nav sees the press.
    CheckKeyDown(&keyDown, 0xFF); CheckKeyPress(&keyPress, 0xFF);

    int idx[9];
    int n = visibleButtons(idx);   // s_sel now indexes the VISIBLE list
    if (!s_wasOn) {
        s_wasOn  = true;
        s_openAt = SDL_GetTicks();
        s_selAt  = s_openAt;
        s_barY   = -1.0f;
        int g = objectEntityList[0].values[3] - 1; // stock CurrentSelection -> visible index
        s_sel = 0;
        for (int i = 0; i < n; ++i) if (idx[i] == g) { s_sel = i; break; }
    }
    if (s_sel >= n) s_sel = n - 1;

    if (keyPress.up)   { s_sel = (s_sel + n - 1) % n; s_selAt = SDL_GetTicks(); PlaySfx(23, 0); }
    if (keyPress.down) { s_sel = (s_sel + 1) % n;     s_selAt = SDL_GetTicks(); PlaySfx(23, 0); }
    int stockIdx = idx[s_sel];
    objectEntityList[0].values[3] = stockIdx + 1; // keep the stock controller in sync

    if (keyPress.start || keyPress.A) {
        int e = BTN_BASE + stockIdx;
        PlaySfx(27, 0);
        objectEntityList[0].state     = 3;
        objectEntityList[e].state     = 3;
        objectEntityList[e].values[0] = 0;
    }

    swallowMenuInput();
}

// ---- transition accelerator -------------------------------------------------
//  The stock menu drives section transitions through long count-up/down timers:
//    * Menu Button  state 0  — 60-frame entrance wait
//    * Menu Button  state 1  — 80-frame slide-in
//    * Menu Button  state 3  — 30-frame wait AFTER confirm, before the section
//                              object is even spawned  (the visible "lag" when
//                              you pick a section)
//    * Section controller state 0 — ~43-frame fade-in that ignores input, so a
//                              quick tap after entering a section does nothing
//    * Section controller exit state — ~31-frame fade-out before it hands back
//                              to the main menu (the section -> main menu "lag")
//  Our overlays cover the buttons, so shortening these is invisible except that
//  sections appear/respond and hand back far sooner. values[0] is a plain frame
//  counter in every state we touch, so nudging it only advances the same anim.
void AccelMenu()
{
    if (Engine.gameMode != ENGINE_MAINGAME) return;
    if (!StrComp(currentStageFolder, (char *)"Menu")) return;

    int mbType = TypeNameID("Menu Button");
    for (int e = BTN_BASE - 1; e <= BTN_BASE + 9; ++e) {
        Entity *b = &objectEntityList[e];
        if (b->type != mbType) continue;
        switch (b->state) {
            case 0: if (b->values[0] < 60) b->values[0] += 6; break; // entrance wait
            case 1: if (b->values[0] < 80) b->values[0] += 6; break; // slide-in
            case 3: if (b->values[0] < 30) b->values[0] += 5; break; // confirm -> spawn wait
            default: break;
        }
    }

    // Section controller (entity 62). Every remastered section uses state 0 for a
    // values[0]<256 fade-in, and hands back to the main menu from a values[0]-=8
    // fade-out: state 11 for Load Save / Extras / Options C, state 3/4 for the
    // Soundtrack Menu. (We touch ONLY those exact states, never the level-load or
    // sub-screen fades, so nothing that loads a stage is affected.)
    Entity *sec = &objectEntityList[62];
    int t = sec->type;
    bool isSection = t == TypeNameID("Load Save Menu") || t == TypeNameID("Extras Menu") ||
                     t == TypeNameID("Soundtrack Menu") || t == TypeNameID("Options Menu C");
    if (isSection) {
        if (sec->state == 0 && sec->values[0] < 256)
            sec->values[0] += 24; // fade-in: reach the interactive state almost immediately

        bool isSoundtrack = (t == TypeNameID("Soundtrack Menu"));
        bool exitFade = isSoundtrack ? (sec->state == 3 || sec->state == 4) : (sec->state == 11);
        if (exitFade && sec->values[0] > 0)
            sec->values[0] -= 20; // fade-out to main menu: speed the hand-back
    }
}

// ---- render -----------------------------------------------------------------
void Render(SDL_Renderer *renderer)
{
    if (!Active()) { s_wasOn = false; return; }
    R = renderer;
    int W = 0, H = 0;
    SDL_GetRendererOutputSize(R, &W, &H);
    if (W <= 0 || H <= 0)
        return;

#if RETRO_USE_TTF
    if (s_cacheOwner != R) { clearCache(); s_cacheOwner = R; }
#endif

    int prevLW = 0, prevLH = 0;
    SDL_RenderGetLogicalSize(R, &prevLW, &prevLH);
    SDL_RenderSetLogicalSize(R, 0, 0);
    SDL_SetRenderDrawBlendMode(R, SDL_BLENDMODE_BLEND);

    const float fw = (float)W, fh = (float)H;
    const float t  = SDL_GetTicks() / 1000.0f;
    const float now = (float)SDL_GetTicks();
    const float tOpen = now - s_openAt;
    const float tSel  = now - s_selAt;
    float fade = clamp01(tOpen / 260.0f);
    Uint8 A = (Uint8)(fade * 255);

    // audio-reactive meters (extra UI smoothing on top of the audio-thread ones)
    s_uiBass += (audioMeterBass - s_uiBass) * 0.35f;
    s_uiPeak += (audioMeterPeak - s_uiPeak) * 0.35f;
    // a little idle life so it never looks frozen when music is quiet/off
    float idle = 0.10f + 0.06f * sinf(t * 1.7f);
    float bass = s_uiBass > idle ? s_uiBass : idle;
    float peak = s_uiPeak > idle ? s_uiPeak : idle;
    s_iconSpin += (0.6f + 1.6f * peak) * 0.016f;

    // 1) OPAQUE frosted gradient backdrop — a complete screen so the stock
    //    mode-select behind it never shows through (its draw is also suppressed).
    gradRect(0, 0, fw, fh, { 238, 243, 248, 255 }, { 194, 206, 219, 255 }, false);

    // 2) drifting geometric accents — scale/brighten with the bass
    for (int i = 0; i < 5; ++i) {
        float dy = fmodf(t * (5.0f + i * 2.0f) + i * 260.0f, fh + 400.0f) - 200.0f;
        float y = fh - dy, s = fh * (0.14f + 0.05f * i) * (1.0f + 0.28f * bass), rot = t * 0.1f + i;
        float ax = fw * (0.58f + 0.11f * i);
        Uint8 ta = (Uint8)(24 + 22 * bass);
        tri(ax, y, ax + cosf(rot) * s, y + sinf(rot) * s, ax + cosf(rot + 2.1f) * s, y + sinf(rot + 2.1f) * s,
            { 255, 255, 255, ta });
    }

    // 3) top accent bar (shimmer rides the loudness)
    gradRect(0, 0, fw, fh * 0.014f, { 46, 143, 212, 255 }, { 95, 200, 240, (Uint8)(180 + 75 * peak) }, true);

    // 4) header (logo + wordmark, slides down + underline draws in)
    float hdrE = easeOutCubic(clamp01(tOpen / 400.0f));
    int hpx = (int)(fh * 0.050f);
    float hx = fw * 0.05f, hy = fh * 0.055f - (1.0f - hdrE) * fh * 0.03f;
    Uint8 hA = (Uint8)(A * hdrE);
    drawText(hx, hy, "SONIC CD", hpx, { 18, 58, 92, hA }, 0, true);
    int hw2 = textWidth("SONIC CD", hpx, true);
    drawText(hx + hw2 + fh * 0.03f, hy + hpx * 0.22f, "MAIN MENU", (int)(fh * 0.028f), { 90, 119, 148, hA }, 0, false);
    float ulW = (fw * 0.24f) * hdrE;
    gradRect(hx, hy + hpx * 1.25f, ulW, fh * 0.004f, { 46, 143, 212, hA }, { 120, 210, 245, 0 }, true);

    // 5) item list — adaptive height, entry stagger, animated selection
    int idx[9];
    int n = visibleButtons(idx);   // hides the dead Achievements/Leaderboards
    if (s_sel >= n) s_sel = n - 1;
    float listX = fw * 0.05f, listW = fw * 0.42f;
    float availTop = fh * 0.235f, availBot = fh * 0.82f;
    float stride = (availBot - availTop) / n;
    if (stride > fh * 0.105f) stride = fh * 0.105f;
    float rowH = stride * 0.86f;
    float top  = availTop + ((availBot - availTop) - stride * n) * 0.5f;
    if (top < availTop) top = availTop;
    int itemPx = (int)(rowH * 0.52f);

    // selection bar spring
    float targetBarY = top + s_sel * stride;
    if (s_barY < 0) s_barY = targetBarY;
    s_barY += (targetBarY - s_barY) * 0.4f;

    // bar drop shadow
    SDL_SetRenderDrawColor(R, 20, 60, 110, (Uint8)(50 * fade));
    rect(listX + fw * 0.004f, s_barY + rowH * 0.16f, listW, rowH);
    // the bar itself — brightens subtly on the beat
    Uint8 barHi = (Uint8)(A * (0.85f + 0.15f * peak));
    gradRect(listX, s_barY, listW, rowH, { 47, 143, 212, A }, { 89, 189, 236, barHi }, true);
    SDL_SetRenderDrawColor(R, 191, 233, 255, A);
    rect(listX, s_barY + rowH * 0.12f, listW * 0.010f, rowH * 0.76f);
    // sweep glint that travels across the bar right after a selection change
    float sweep = clamp01(tSel / 420.0f);
    if (sweep < 1.0f) {
        float gx = listX + sweep * listW;
        float gw = listW * 0.12f;
        Uint8 ga = (Uint8)(90 * (1.0f - sweep) * fade);
        gradRect(gx - gw, s_barY, gw, rowH, { 255, 255, 255, 0 }, { 255, 255, 255, ga }, true);
        gradRect(gx, s_barY, gw, rowH, { 255, 255, 255, ga }, { 255, 255, 255, 0 }, true);
    }
    // chevron: spring in from the right + idle bob
    float chSpring = easeOutBack(clamp01(tSel / 300.0f));
    float chx = listX + listW - fw * 0.028f + (1.0f - chSpring) * fw * 0.02f + sinf(t * 4.0f) * fh * 0.004f;
    float chy = s_barY + rowH * 0.5f, chs = rowH * 0.24f;
    tri(chx, chy - chs, chx + chs * 0.9f, chy, chx, chy + chs, { 223, 243, 255, A });

    for (int i = 0; i < n; ++i) {
        int pv = objectEntityList[BTN_BASE + idx[i]].propertyValue;
        bool sel = (i == s_sel);
        float ry = top + i * stride;
        float e = easeOutCubic(clamp01((tOpen - 60.0f - i * 45.0f) / 340.0f));
        float xoff = (1.0f - e) * (-fw * 0.05f);
        Uint8 rowA = (Uint8)(A * e);

        if (!sel) {
            SDL_SetRenderDrawColor(R, 255, 255, 255, (Uint8)(70 * fade * e));
            rect(listX + xoff, ry, listW, rowH);
        }
        float pop = sel ? 1.0f + 0.10f * (1.0f - easeOutCubic(clamp01(tSel / 220.0f))) : 1.0f;
        float nudge = sel ? (1.0f - easeOutCubic(clamp01(tSel / 260.0f))) * fw * 0.012f : 0.0f;
        SDL_Color tc = sel ? SDL_Color{ 255, 255, 255, rowA } : SDL_Color{ 63, 92, 120, rowA };
        drawText(listX + listW * 0.055f + xoff + nudge, ry + rowH * 0.5f - itemPx * 0.62f * pop, labelFor(pv), itemPx, tc, 0, sel, pop);
    }

    // 6) FEATURE CARD — a big visual of the option currently hovered ----------
    int selPv = objectEntityList[BTN_BASE + idx[s_sel]].propertyValue;
    float cardW = fw * 0.325f, cardH = fh * 0.560f;
    float cardX = fw * 0.625f, cardY = fh * 0.205f;
    float ccx = cardX + cardW * 0.5f;
    // entrance + per-change pop
    float cardIn = easeOutCubic(clamp01((tOpen - 120.0f) / 420.0f));
    float chg = easeOutBack(clamp01(tSel / 320.0f)); // 0..1 settle after a change
    Uint8 cardA = (Uint8)(A * cardIn);

    // pulsing outer glow (beat)
    float glow = 0.5f + 0.5f * bass;
    SDL_Color glowC = { 90, 175, 230, (Uint8)(46 * glow * cardIn * fade) };
    roundRect(cardX - fw * 0.012f, cardY - fh * 0.016f, cardW + fw * 0.024f, cardH + fh * 0.032f, fh * 0.05f, glowC);
    // card drop shadow
    SDL_Color shadow = { 25, 55, 95, (Uint8)(46 * cardIn * fade) };
    roundRect(cardX + fw * 0.006f, cardY + fh * 0.012f, cardW, cardH, fh * 0.035f, shadow);
    // frosted card body + slim inner border
    roundRect(cardX, cardY, cardW, cardH, fh * 0.035f, { 249, 251, 253, (Uint8)(238 * cardIn * fade) });
    roundRect(cardX + 2, cardY + 2, cardW - 4, cardH * 0.5f, fh * 0.03f, { 255, 255, 255, (Uint8)(70 * cardIn * fade) });

    // little category tag pill at the top of the card
    {
        const char *tag = tagFor(selPv);
        int tpx = (int)(fh * 0.024f);
        int tw = textWidth(tag, tpx, true);
        float pillW = tw + fh * 0.05f, pillH = fh * 0.044f;
        float pillX = ccx - pillW * 0.5f, pillY = cardY + cardH * 0.075f;
        roundRect(pillX, pillY, pillW, pillH, pillH * 0.5f, { 47, 143, 212, (Uint8)(cardA) });
        drawText(ccx, pillY + pillH * 0.5f - tpx * 0.62f, tag, tpx, { 255, 255, 255, cardA }, 1, true);
    }

    // icon — springs/pops on selection change, breathes with the beat
    {
        float iconCY = cardY + cardH * 0.40f;
        float baseS  = cardH * 0.20f;
        float sc = (0.7f + 0.3f * chg) * (1.0f + 0.05f * bass); // pop-in + beat breathe
        // beat pulse ring behind the icon
        float pr = baseS * (1.35f + 0.55f * bass);
        SDL_Color pulseC = { 66, 158, 224, (Uint8)(70 * bass * cardIn * fade) };
        ring(ccx, iconCY, pr, pr * 0.9f, pulseC);
        SDL_Color iconC = { 39, 118, 180, cardA };
        drawIcon(selPv, ccx, iconCY, baseS * sc, iconC, t, s_iconSpin, bass);
    }

    // big option name inside the card (fades/rises on change)
    {
        Uint8 nmA = (Uint8)(cardA * (0.4f + 0.6f * chg));
        float ny = cardY + cardH * 0.66f + (1.0f - chg) * fh * 0.02f;
        drawText(ccx, ny, labelFor(selPv), (int)(fh * 0.048f), { 20, 62, 98, nmA }, 1, true);
    }

    // music-reactive equalizer strip near the bottom of the card
    {
        int bars = 11;
        float eqW = cardW * 0.66f, eqX = ccx - eqW * 0.5f;
        float eqBase = cardY + cardH * 0.90f, eqMax = cardH * 0.13f, bw = eqW / bars * 0.55f;
        for (int i = 0; i < bars; ++i) {
            float ctr = 1.0f - fabsf((i - (bars - 1) * 0.5f) / ((bars - 1) * 0.5f)); // 0..1 center weight
            float drive = peak * (0.35f + 0.65f * ctr) + bass * 0.5f * ctr;
            float hh = eqMax * clamp01(0.12f + drive * (0.7f + 0.5f * (0.5f + 0.5f * sinf(t * 9.0f + i * 0.8f))));
            float bx = eqX + (i + 0.5f) * (eqW / bars) - bw * 0.5f;
            Uint8 ea = (Uint8)(cardA * 0.9f);
            gradRect(bx, eqBase - hh, bw, hh, { 60, 180, 235, ea }, { 46, 120, 190, ea }, false);
        }
    }

    // 7) description — cross-fades + slides up on selection change
    float dE = easeOutCubic(clamp01(tSel / 280.0f));
    Uint8 dA = (Uint8)(A * dE);
    drawText(fw * 0.05f, fh * 0.88f + (1.0f - dE) * fh * 0.012f, descFor(selPv), (int)(fh * 0.030f), { 74, 103, 132, dA }, 0, false);

    // 8) button hints (A Select / B Back)
    {
        float by = fh * 0.90f, r = fh * 0.026f, px = fw * 0.95f;
        int hp = (int)(fh * 0.030f);
        int bw = textWidth("Back", hp, false);
        drawText(px, by, "Back", hp, { 44, 77, 107, A }, 2, false);
        float bcx = px - bw - r - fw * 0.008f;
        circle(bcx, by + hp * 0.55f, r, { 130, 150, 168, A });
        drawText(bcx, by + hp * 0.05f, "B", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
        float ax2 = bcx - r - fw * 0.03f;
        int sw = textWidth("Select", hp, false);
        drawText(ax2, by, "Select", hp, { 44, 77, 107, A }, 2, false);
        float acx = ax2 - sw - r - fw * 0.008f;
        circle(acx, by + hp * 0.55f, r, { 47, 143, 212, A });
        drawText(acx, by + hp * 0.05f, "A", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
    }

    SDL_RenderSetLogicalSize(R, prevLW, prevLH);
    R = nullptr;
}

// =============================================================================
//  PLAY / SAVE-SELECT overlay
// -----------------------------------------------------------------------------
//  When PLAY is chosen the stock game spawns a "Load Save Menu" controller at a
//  fixed entity index (62), with the four save-slot records living in entities
//  62..65 and a helper at 66. We draw a modern hi-res save-select over the top
//  of its "browsing" states and let the stock object keep handling all input and
//  transitions (continue / new game / delete), so nothing about the flow breaks.
// =============================================================================
static const int LSM = 62; // Load Save Menu controller entity

// diamond (rotated square) — used for the time-stone gems
static void diamond(float cx, float cy, float r, SDL_Color c)
{
    tri(cx, cy - r, cx + r, cy, cx, cy + r, c);
    tri(cx, cy - r, cx, cy + r, cx - r, cy, c);
}

static const char *zoneNameFor(int prog)
{
    if (prog <= 0) return "NEW GAME";
    int z = (prog - 1) / 10;
    if (z < 0) z = 0;
    if (z > 8) z = 8;
    static const char *n[9] = { "PALMTREE PANIC", "COLLISION CHAOS", "TIDAL TEMPEST", "QUARTZ QUADRANT",
                                "WACKY WORKBENCH", "STARDUST SPEEDWAY", "METALLIC MADNESS", "METALLIC MADNESS",
                                "STARDUST SPEEDWAY" };
    return n[z];
}
static int roundFor(int prog)
{
    int z = (prog - 1) / 10;
    if (z < 0) z = 0;
    if (z > 6) z = 6;
    return z + 1;
}

static bool  s_playWasOn = false;
static Uint32 s_playOpenAt = 0;
static float s_playBarY = -1.0f;
static int   s_playLastSel = -99;
static Uint32 s_playSelAt = 0;

bool PlayActive()
{
    if (Engine.gameMode != ENGINE_MAINGAME)
        return false;
    if (!StrComp(currentStageFolder, (char *)"Menu"))
        return false;
    if (objectEntityList[LSM].type != TypeNameID("Load Save Menu"))
        return false;
    int st = objectEntityList[LSM].state;
    // Skin every save-select state so the stock low-res menu never shows:
    //   0 fade-in  1 browse  2 confirm  3 continue->black-fade
    //   4..10 new-game character select (Sonic / Tails)   8 = load->black-fade
    //   11 back out   12 delete-mode   13..18 delete-confirm flow
    return (st >= 0 && st <= 18);
}

void PlayRender(SDL_Renderer *renderer)
{
    if (!PlayActive()) { s_playWasOn = false; return; }
    // states 3 (continue) & 8 (new-game load): the engine fades to black to load
    // the stage, so draw nothing and let that fade play cleanly.
    if (objectEntityList[LSM].state == 3 || objectEntityList[LSM].state == 8) return;
    R = renderer;
    int W = 0, H = 0;
    SDL_GetRendererOutputSize(R, &W, &H);
    if (W <= 0 || H <= 0) return;

#if RETRO_USE_TTF
    if (s_cacheOwner != R) { clearCache(); s_cacheOwner = R; }
#endif

    int prevLW = 0, prevLH = 0;
    SDL_RenderGetLogicalSize(R, &prevLW, &prevLH);
    SDL_RenderSetLogicalSize(R, 0, 0);
    SDL_SetRenderDrawBlendMode(R, SDL_BLENDMODE_BLEND);

    const float fw = (float)W, fh = (float)H;
    const float t  = SDL_GetTicks() / 1000.0f;
    const float now = (float)SDL_GetTicks();

    if (!s_playWasOn) { s_playWasOn = true; s_playOpenAt = (Uint32)now; s_playBarY = -1.0f; s_playLastSel = -99; }
    const float tOpen = now - s_playOpenAt;
    float fade = clamp01(tOpen / 260.0f);
    Uint8 A = (Uint8)(fade * 255);

    // audio meters + idle fallback
    s_uiBass += (audioMeterBass - s_uiBass) * 0.35f;
    s_uiPeak += (audioMeterPeak - s_uiPeak) * 0.35f;
    float idle = 0.10f + 0.06f * sinf(t * 1.7f);
    float bass = s_uiBass > idle ? s_uiBass : idle;
    float peak = s_uiPeak > idle ? s_uiPeak : idle;

    Entity *ctrl = &objectEntityList[LSM];
    int st = ctrl->state;
    bool charSel = (st >= 4 && st <= 10);      // new-game character select
    int sel = ctrl->values[1];                 // 0..3 = slot, 4 = top button
    bool haveSaves = (ctrl->direction == 1);
    if (sel != s_playLastSel) { s_playLastSel = sel; s_playSelAt = (Uint32)now; }
    float tSel = now - s_playSelAt;

    // 1) OPAQUE backdrop — a complete screen, so nothing behind (the dismantling
    //    mode-select, its window/heading, the menu art) can ever show through.
    gradRect(0, 0, fw, fh, { 238, 243, 248, 255 }, { 194, 206, 219, 255 }, false);
    // large faint watermark ring, slowly rotating
    {
        float wr = fh * (0.42f + 0.02f * bass);
        ring(fw * 0.82f, fh * 0.42f, wr, wr * 0.965f, { 120, 175, 220, 26 });
        ring(fw * 0.82f, fh * 0.42f, wr * 0.78f, wr * 0.75f, { 120, 175, 220, 20 });
    }
    for (int i = 0; i < 4; ++i) {
        float dy = fmodf(t * (5.0f + i * 2.0f) + i * 300.0f, fh + 400.0f) - 200.0f;
        float y = fh - dy, s = fh * (0.16f + 0.06f * i) * (1.0f + 0.22f * bass), rot = t * 0.09f + i;
        float ax = fw * (0.14f + 0.16f * i);
        Uint8 ta = (Uint8)(20 + 16 * bass);
        tri(ax, y, ax + cosf(rot) * s, y + sinf(rot) * s, ax + cosf(rot + 2.1f) * s, y + sinf(rot + 2.1f) * s,
            { 255, 255, 255, ta });
    }
    // floating spark particles drifting up, brightening on the beat
    for (int i = 0; i < 18; ++i) {
        float px = fmodf(0.0618f * i + 0.13f * sinf(i * 2.3f) + t * 0.004f * ((i & 1) ? 1 : -1), 1.0f) * fw;
        float spd = 10.0f + (i % 5) * 6.0f;
        float py = fh + fh * 0.05f - fmodf(t * spd + i * 90.0f, fh + fh * 0.1f);
        float sz = fh * 0.005f * (1.0f + (i % 3) * 0.5f) * (1.0f + 0.7f * bass);
        Uint8 pa = (Uint8)(26 + 46 * bass);
        diamond(px, py, sz, { 120, 190, 235, pa });
    }
    gradRect(0, 0, fw, fh * 0.014f, { 46, 143, 212, 255 }, { 95, 200, 240, (Uint8)(180 + 75 * peak) }, true);
    // subtle vignette for depth
    {
        float m = fh * 0.20f; Uint8 va = 34;
        gradRect(0, 0, fw, m, { 18, 40, 66, va }, { 18, 40, 66, 0 }, false);
        gradRect(0, fh - m, fw, m, { 18, 40, 66, 0 }, { 18, 40, 66, va }, false);
        gradRect(0, 0, m, fh, { 18, 40, 66, va }, { 18, 40, 66, 0 }, true);
        gradRect(fw - m, 0, m, fh, { 18, 40, 66, 0 }, { 18, 40, 66, va }, true);
    }

    // 2) header
    float hdrE = easeOutCubic(clamp01(tOpen / 420.0f));
    int hpx = (int)(fh * 0.050f);
    float hx = fw * 0.06f, hy = fh * 0.052f - (1.0f - hdrE) * fh * 0.03f;
    Uint8 hA = (Uint8)(255 * hdrE);
    drawText(hx, hy, "SONIC CD", hpx, { 18, 58, 92, hA }, 0, true);
    int hw2 = textWidth("SONIC CD", hpx, true);
    drawText(hx + hw2 + fh * 0.03f, hy + hpx * 0.22f, charSel ? "NEW GAME" : "SELECT SAVE", (int)(fh * 0.028f), { 90, 119, 148, hA }, 0, false);
    gradRect(hx, hy + hpx * 1.25f, (fw * 0.24f) * hdrE, fh * 0.004f, { 46, 143, 212, hA }, { 120, 210, 245, 0 }, true);

    // 2b) NEW-GAME CHARACTER SELECT (states 4..10) — Sonic / Tails picker.
    //     Stock drives Left/Right (cycles the slot's character), A start, B back;
    //     the chosen character lives on the slot entity's values[3].
    if (charSel) {
        int slot = sel; if (slot < 0) slot = 0; if (slot > 3) slot = 3;
        int chr = objectEntityList[LSM + slot].values[3]; if (chr < 0) chr = 0; if (chr > 1) chr = 1;
        static const char *chName[2] = { "SONIC", "TAILS" };
        static const char *chRole[2] = { "THE HEDGEHOG", "THE FOX" };
        SDL_Color chCol[2] = { { 0, 120, 214, 255 }, { 232, 150, 42, 255 } };
        float cardW = fw * 0.26f, cardH = fh * 0.46f, cgap = fw * 0.05f;
        float totW = cardW * 2.0f + cgap, x0 = fw * 0.5f - totW * 0.5f, cy = fh * 0.28f;
        drawText(fw * 0.5f, fh * 0.20f, "CHOOSE YOUR CHARACTER", (int)(fh * 0.034f), { 30, 62, 96, A }, 1, true);
        for (int c = 0; c < 2; ++c) {
            float bx = x0 + c * (cardW + cgap);
            bool selc = (c == chr);
            float en = easeOutBack(clamp01((tOpen - 60.0f - c * 70.0f) / 360.0f)); en = clamp01(en);
            float scl = (selc ? 1.05f : 0.95f) * en + (1.0f - en) * 0.7f;
            float w = cardW * scl, h = cardH * scl;
            float x = bx + (cardW - w) * 0.5f, y = cy + (cardH - h) * 0.5f;
            Uint8 cA = (Uint8)(A * en);
            SDL_Color ac = chCol[c];
            if (selc)
                roundRect(x - fw * 0.012f, y - fh * 0.016f, w + fw * 0.024f, h + fh * 0.03f, fh * 0.032f,
                          { ac.r, ac.g, ac.b, (Uint8)(90 * (0.5f + 0.5f * bass) * fade) });
            roundRect(x, y + h * 0.06f, w, h, fh * 0.026f, { 18, 42, 78, (Uint8)((selc ? 70 : 40) * fade) });
            roundRect(x, y, w, h, fh * 0.026f, selc ? SDL_Color{ ac.r, ac.g, ac.b, cA } : SDL_Color{ 255, 255, 255, (Uint8)(175 * fade) });
            glossTop(x, y, w, h * 0.42f, (Uint8)((selc ? 115 : 55) * fade));
            float ecx = x + w * 0.5f, ecy = y + h * 0.36f, er = h * 0.2f * (1.0f + (selc ? 0.05f * bass : 0.0f));
            circle(ecx, ecy, er, selc ? SDL_Color{ 255, 255, 255, cA } : SDL_Color{ ac.r, ac.g, ac.b, cA });
            drawText(ecx, ecy - er * 0.64f, c == 0 ? "S" : "T", (int)(er * 1.15f), selc ? ac : SDL_Color{ 255, 255, 255, cA }, 1, true);
            drawTextFit(x + w * 0.5f, y + h * 0.64f, chName[c], (int)(h * 0.135f), selc ? SDL_Color{ 255, 255, 255, cA } : SDL_Color{ 40, 72, 104, cA }, w * 0.82f, true);
            drawTextFit(x + w * 0.5f, y + h * 0.80f, chRole[c], (int)(h * 0.066f), selc ? SDL_Color{ 216, 237, 251, cA } : SDL_Color{ 120, 142, 166, cA }, w * 0.82f, false);
        }
        drawText(fw * 0.5f, fh * 0.80f, "Press A to begin your journey through time.", (int)(fh * 0.030f), { 74, 103, 132, A }, 1, false);
        // hints: Choose / Start / Back
        {
            float by = fh * 0.905f, r = fh * 0.026f, rx = fw * 0.88f;
            int hp = (int)(fh * 0.030f);
            int bw = textWidth("Back", hp, false);
            drawText(rx, by, "Back", hp, { 44, 77, 107, A }, 2, false);
            float bcx = rx - bw - r - fw * 0.008f;
            circle(bcx, by + hp * 0.55f, r, { 130, 150, 168, A });
            drawText(bcx, by + hp * 0.05f, "B", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
            float ax2 = bcx - r - fw * 0.03f;
            int sw2 = textWidth("Start", hp, false);
            drawText(ax2, by, "Start", hp, { 44, 77, 107, A }, 2, false);
            float acx = ax2 - sw2 - r - fw * 0.008f;
            circle(acx, by + hp * 0.55f, r, { 47, 143, 212, A });
            drawText(acx, by + hp * 0.05f, "A", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
            float adj = acx - r - fw * 0.05f;
            int aw = textWidth("Choose", hp, false);
            drawText(adj, by, "Choose", hp, { 44, 77, 107, A }, 2, false);
            float cxr = adj - aw - fw * 0.012f;
            tri(cxr, by + hp * 0.55f - r * 0.7f, cxr, by + hp * 0.55f + r * 0.7f, cxr - r * 0.8f, by + hp * 0.55f, { 90, 120, 150, A });
            float cxl = cxr - r * 1.1f;
            tri(cxl, by + hp * 0.55f - r * 0.7f, cxl, by + hp * 0.55f + r * 0.7f, cxl + r * 0.8f, by + hp * 0.55f, { 90, 120, 150, A });
        }
        SDL_RenderSetLogicalSize(R, prevLW, prevLH);
        R = nullptr;
        return;
    }

    // 3) rows: slots 0..3 then the DELETE / NO SAVE button (nav index 4)
    float colX = fw * 0.06f, colW = fw * 0.88f;
    float availTop = fh * 0.195f, availBot = fh * 0.855f;
    float gap = fh * 0.016f;
    float btnH = fh * 0.070f;
    float slotH = (availBot - availTop - btnH - gap * 5.0f) / 4.0f;
    float rowY[5];
    for (int i = 0; i < 4; ++i) rowY[i] = availTop + i * (slotH + gap);
    rowY[4] = availTop + 4 * (slotH + gap) + gap;
    const float cr = fh * 0.024f; // card corner radius

    int selIdx = sel; if (selIdx < 0) selIdx = 0; if (selIdx > 4) selIdx = 4;
    float targetY = rowY[selIdx];
    float curH    = (selIdx == 4) ? btnH : slotH;
    if (s_playBarY < 0) s_playBarY = targetY;
    s_playBarY += (targetY - s_playBarY) * 0.4f;

    // ---- pass 1: frosted backgrounds for the non-selected rows --------------
    for (int i = 0; i < 5; ++i) {
        if (i == selIdx) continue;
        float y = rowY[i], h = (i == 4) ? btnH : slotH;
        float en = easeOutCubic(clamp01((tOpen - 80.0f - i * 55.0f) / 360.0f));
        float xoff = (1.0f - en) * (-fw * 0.03f);
        roundRect(colX + xoff, y + h * 0.10f, colW, h, cr, { 30, 60, 100, (Uint8)(24 * en) }); // soft shadow
        roundRect(colX + xoff, y, colW, h, cr, { 255, 255, 255, (Uint8)(82 * en) });           // frosted fill
    }

    // ---- selection highlight (spring bar, beat glow, sweep glint) -----------
    {
        float y = s_playBarY, h = curH;
        SDL_Color glow = { 66, 158, 224, (Uint8)(70 * bass) };
        roundRect(colX - fw * 0.010f, y - fh * 0.012f, colW + fw * 0.020f, h + fh * 0.024f, cr + fh * 0.006f, glow);
        roundRect(colX, y + h * 0.12f, colW, h, cr, { 16, 52, 98, 70 });                  // drop shadow
        roundRect(colX, y, colW, h, cr, { 47, 143, 212, 255 });                            // base
        gradRect(colX + cr, y, colW - cr * 2.0f, h, { 47, 143, 212, 0 }, { 96, 194, 238, (Uint8)(150 + 90 * peak) }, true);
        SDL_SetRenderDrawColor(R, 200, 236, 255, 255);                                      // bright left accent
        rect(colX + colW * 0.014f, y + h * 0.16f, colW * 0.006f, h * 0.68f);
        float sweep = clamp01(tSel / 420.0f);
        if (sweep < 1.0f) {
            float gx = colX + sweep * colW, gw = colW * 0.10f;
            Uint8 ga = (Uint8)(80 * (1.0f - sweep));
            gradRect(gx - gw, y, gw, h, { 255, 255, 255, 0 }, { 255, 255, 255, ga }, true);
            gradRect(gx, y, gw, h, { 255, 255, 255, ga }, { 255, 255, 255, 0 }, true);
        }
    }

    // ---- pass 2: row content ------------------------------------------------
    for (int i = 0; i < 5; ++i) {
        bool selRow = (i == selIdx);
        float y = rowY[i], h = (i == 4) ? btnH : slotH;
        float en = easeOutCubic(clamp01((tOpen - 80.0f - i * 55.0f) / 360.0f));
        float xoff = (1.0f - en) * (-fw * 0.03f);
        Uint8 rA = (Uint8)(255 * en);
        SDL_Color primary = selRow ? SDL_Color{ 255, 255, 255, rA } : SDL_Color{ 30, 62, 96, rA };
        SDL_Color subtle  = selRow ? SDL_Color{ 216, 237, 251, rA } : SDL_Color{ 104, 130, 158, rA };

        if (i == 4) { // DELETE / NO SAVE button
            const char *lbl = haveSaves ? "DELETE SAVE" : "NO SAVE";
            float ix = colX + xoff + h * 0.85f, iy = y + h * 0.5f, ir = h * 0.26f;
            if (haveSaves) {
                line(ix - ir, iy - ir * 0.62f, ix + ir, iy - ir * 0.62f, h * 0.06f, primary);   // lid
                SDL_SetRenderDrawColor(R, primary.r, primary.g, primary.b, primary.a);
                rect(ix - ir * 0.66f, iy - ir * 0.5f, ir * 1.32f, ir * 1.55f);                    // body
            } else {
                ring(ix, iy, ir, ir * 0.72f, primary);
                line(ix - ir * 0.62f, iy - ir * 0.62f, ix + ir * 0.62f, iy + ir * 0.62f, h * 0.07f, primary);
            }
            drawText(ix + ir + h * 0.4f, y + h * 0.5f - h * 0.21f, lbl, (int)(h * 0.40f), primary, 0, selRow);
            continue;
        }

        Entity *e = &objectEntityList[LSM + i];
        int prog = e->values[2], chr = e->values[3], lives = e->values[6], score = e->values[5], stoneBits = e->values[4];
        bool empty = (prog <= 0);
        float pop = selRow ? 1.0f + 0.04f * (1.0f - easeOutCubic(clamp01(tSel / 220.0f))) : 1.0f;

        // avatar
        float bcx = colX + xoff + h * 0.66f, bcy = y + h * 0.5f, br = h * 0.30f * pop;
        if (empty) {
            SDL_Color rc = selRow ? SDL_Color{ 255, 255, 255, rA } : SDL_Color{ 150, 170, 190, rA };
            ring(bcx, bcy, br, br * 0.80f, rc);
            line(bcx - br * 0.4f, bcy, bcx + br * 0.4f, bcy, h * 0.055f, rc);
            line(bcx, bcy - br * 0.4f, bcx, bcy + br * 0.4f, h * 0.055f, rc);
        } else {
            SDL_Color badge = selRow ? SDL_Color{ 255, 255, 255, rA }
                                     : (chr == 0 ? SDL_Color{ 0, 112, 200, rA } : SDL_Color{ 232, 150, 42, rA });
            circle(bcx, bcy, br, badge);
            SDL_Color initc = selRow ? SDL_Color{ 47, 130, 200, rA } : SDL_Color{ 255, 255, 255, rA };
            drawText(bcx, bcy - br * 0.66f, (chr == 0) ? "S" : "T", (int)(br * 1.15f), initc, 1, true);
        }

        float tx = colX + xoff + h * 1.28f;
        if (empty) {
            drawText(tx, y + h * 0.5f - h * 0.24f, "NEW GAME", (int)(h * 0.34f), primary, 0, selRow);
            drawText(tx, y + h * 0.5f + h * 0.10f, "Start a new adventure through time.", (int)(h * 0.175f), subtle, 0, false);
        } else {
            char slotLbl[16]; snprintf(slotLbl, sizeof(slotLbl), "SAVE %d", i + 1);
            drawText(tx, y + h * 0.15f, slotLbl, (int)(h * 0.155f), subtle, 0, false);
            drawText(tx, y + h * 0.31f, zoneNameFor(prog), (int)(h * 0.29f), primary, 0, selRow);
            char sub[24]; snprintf(sub, sizeof(sub), "ROUND %d", roundFor(prog));
            drawText(tx, y + h * 0.67f, sub, (int)(h * 0.17f), subtle, 0, false);

            // right cluster: time stones (labelled) + lives / score
            float rx = colX + xoff + colW - h * 0.45f;
            drawText(rx, y + h * 0.15f, "TIME STONES", (int)(h * 0.135f), subtle, 2, false);
            float gR = h * 0.075f, gSp = gR * 2.5f, gY = y + h * 0.40f;
            for (int b = 0; b < 7; ++b) {
                bool lit = ((stoneBits >> b) & 1) != 0;
                float gx = rx - (6 - b) * gSp;
                SDL_Color gc = lit ? SDL_Color{ 92, 206, 246, rA }
                                   : (selRow ? SDL_Color{ 255, 255, 255, (Uint8)(rA * 0.35f) }
                                             : SDL_Color{ 150, 168, 186, (Uint8)(rA * 0.45f) });
                diamond(gx, gY, gR * (lit ? 1.0f + 0.12f * bass : 0.82f), gc);
                if (lit) diamond(gx, gY - gR * 0.12f, gR * 0.38f, { 255, 255, 255, (Uint8)(rA * 0.85f) });
            }
            char rstat[48]; snprintf(rstat, sizeof(rstat), "LIVES  %d      SCORE  %d", lives, score);
            drawText(rx, y + h * 0.67f, rstat, (int)(h * 0.16f), subtle, 2, false);
        }
    }

    // 4) contextual description (delete-mode aware)
    {
        bool deleteMode = (objectEntityList[LSM + 4].rotation >= 2);
        const char *desc;
        if (deleteMode) {
            desc = "DELETE MODE — choose a save to erase, or press B to cancel.";
        } else if (sel == 4) {
            desc = haveSaves ? "Erase a saved game." : "Play a round without saving your progress.";
        } else {
            Entity *e = &objectEntityList[LSM + (sel < 0 ? 0 : (sel > 3 ? 3 : sel))];
            desc = (e->values[2] <= 0) ? "Begin a brand new journey through time."
                                       : "Continue your saved adventure.";
        }
        SDL_Color dcol = deleteMode ? SDL_Color{ 200, 66, 66, A } : SDL_Color{ 74, 103, 132, A };
        drawText(fw * 0.06f, fh * 0.885f, desc, (int)(fh * 0.030f), dcol, 0, false);
    }

    // 5) button hints (A Select / B Back)
    {
        float by = fh * 0.905f, r = fh * 0.026f, px = fw * 0.94f;
        int hp = (int)(fh * 0.030f);
        int bw = textWidth("Back", hp, false);
        drawText(px, by, "Back", hp, { 44, 77, 107, A }, 2, false);
        float bcx = px - bw - r - fw * 0.008f;
        circle(bcx, by + hp * 0.55f, r, { 130, 150, 168, A });
        drawText(bcx, by + hp * 0.05f, "B", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
        float ax2 = bcx - r - fw * 0.03f;
        int sw = textWidth("Select", hp, false);
        drawText(ax2, by, "Select", hp, { 44, 77, 107, A }, 2, false);
        float acx = ax2 - sw - r - fw * 0.008f;
        circle(acx, by + hp * 0.55f, r, { 47, 143, 212, A });
        drawText(acx, by + hp * 0.05f, "A", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
    }

    // 6) DELETE-CONFIRM modal — states 15..18 of the stock delete flow. The stock
    //    object still drives Yes/No (values[1] on entity LSM+4); we just skin it.
    {
        int st = objectEntityList[LSM].state;
        static bool s_delWasOn = false;
        static Uint32 s_delOpenAt = 0;
        if (st >= 15 && st <= 18) {
            if (!s_delWasOn) { s_delWasOn = true; s_delOpenAt = (Uint32)now; }
            float tmo = now - s_delOpenAt;
            float pin = easeOutBack(clamp01(tmo / 260.0f));
            float appear = (st == 18) ? 0.55f : 1.0f; // dim as it fades out
            Uint8 mA = (Uint8)(255 * appear);
            // dim scrim over the slot list
            SDL_SetRenderDrawColor(R, 8, 20, 38, (Uint8)(150 * appear));
            rect(0, 0, fw, fh);
            // modal card (pops in)
            float sc = 0.9f + 0.1f * pin;
            float mw = fw * 0.42f * sc, mh = fh * 0.36f * sc;
            float mx = (fw - mw) * 0.5f, my = (fh - mh) * 0.5f, mcx = fw * 0.5f;
            roundRect(mx + fw * 0.006f, my + fh * 0.014f, mw, mh, fh * 0.03f, { 8, 26, 52, (Uint8)(90 * appear) });
            roundRect(mx, my, mw, mh, fh * 0.03f, { 249, 251, 253, mA });
            gradRect(mx + fh * 0.03f, my, mw - fh * 0.06f, mh * 0.016f, { 224, 80, 80, mA }, { 244, 128, 128, mA }, true);
            drawText(mcx, my + mh * 0.15f, "DELETE THIS SAVE?", (int)(mh * 0.135f), { 30, 62, 96, mA }, 1, true);
            int sl = ctrl->values[1]; if (sl < 0) sl = 0; if (sl > 3) sl = 3;
            Entity *se = &objectEntityList[LSM + sl];
            char sub[56]; snprintf(sub, sizeof(sub), "SAVE %d    %s", sl + 1, zoneNameFor(se->values[2]));
            drawText(mcx, my + mh * 0.31f, sub, (int)(mh * 0.085f), { 120, 138, 158, mA }, 1, false);
            // two options: 0 = DELETE, 1 = CANCEL (entity LSM+4 values[1])
            int selDel = objectEntityList[LSM + 4].values[1];
            const char *opt[2] = { "DELETE", "CANCEL" };
            SDL_Color hi[2] = { { 216, 72, 72, mA }, { 60, 128, 200, mA } };
            for (int i = 0; i < 2; ++i) {
                bool s = (selDel == i);
                float ow = mw * 0.72f, ox = mcx - ow * 0.5f, oh = mh * 0.17f;
                float oy = my + mh * (0.48f + i * 0.23f);
                if (s) {
                    roundRect(ox - fw * 0.004f, oy - fh * 0.006f, ow + fw * 0.008f, oh + fh * 0.012f, oh * 0.35f, { hi[i].r, hi[i].g, hi[i].b, (Uint8)(70 * appear) });
                    roundRect(ox, oy, ow, oh, oh * 0.32f, hi[i]);
                    drawText(mcx, oy + oh * 0.5f - mh * 0.055f, opt[i], (int)(mh * 0.10f), { 255, 255, 255, mA }, 1, true);
                } else {
                    roundRect(ox, oy, ow, oh, oh * 0.32f, { 234, 238, 242, mA });
                    drawText(mcx, oy + oh * 0.5f - mh * 0.055f, opt[i], (int)(mh * 0.10f), { 92, 112, 134, mA }, 1, true);
                }
            }
        } else {
            s_delWasOn = false;
        }
    }

    SDL_RenderSetLogicalSize(R, prevLW, prevLH);
    R = nullptr;
}

// =============================================================================
//  EXTRAS submenu  (D.A. Garden / Visual Mode / Sound Test / Stage Select)
// -----------------------------------------------------------------------------
//  Controller "Extras Menu" at entity 62; selection in values[1] (0..3); each
//  item is unlocked via an Options.* GVar flag. Visual overlay only — the stock
//  object keeps handling nav / confirm / the video-select sub-screen.
// =============================================================================
static bool  s_exWasOn = false;
static Uint32 s_exOpenAt = 0;
static float s_exBarY = -1.0f;
static int   s_exLastSel = -99;
static Uint32 s_exSelAt = 0;

// a small padlock glyph for locked entries
static void padlock(float cx, float cy, float s, SDL_Color c)
{
    ring(cx, cy - s * 0.15f, s * 0.62f, s * 0.42f, c, 20, 3.14159f, 6.28318f); // shackle
    roundRect(cx - s * 0.6f, cy - s * 0.1f, s * 1.2f, s * 0.9f, s * 0.18f, c);   // body
}

// per-item icon for the extras list
static void extrasIcon(int i, float cx, float cy, float s, SDL_Color c, float t)
{
    switch (i) {
        case 0: { // D.A. Garden — flower
            for (int k = 0; k < 6; ++k) {
                float a = t * 0.4f + k / 6.0f * TAU;
                circle(cx + cosf(a) * s * 0.5f, cy + sinf(a) * s * 0.5f, s * 0.34f, c);
            }
            SDL_Color mid = { 255, 214, 90, c.a };
            circle(cx, cy, s * 0.34f, mid);
            break;
        }
        case 1: { // Visual Mode — film / play
            ring(cx, cy, s, s * 0.86f, c);
            tri(cx - s * 0.3f, cy - s * 0.42f, cx - s * 0.3f, cy + s * 0.42f, cx + s * 0.5f, cy, c);
            break;
        }
        case 2: { // Sound Test — music note
            line(cx + s * 0.35f, cy - s * 0.7f, cx + s * 0.35f, cy + s * 0.45f, s * 0.14f, c);
            circle(cx + s * 0.05f, cy + s * 0.5f, s * 0.34f, c);
            SDL_SetRenderDrawColor(R, c.r, c.g, c.b, c.a); // rect() uses the ambient color
            rect(cx + s * 0.28f, cy - s * 0.82f, s * 0.5f, s * 0.2f);
            break;
        }
        default: { // Stage Select — 2x2 map grid
            float g = s * 0.44f;
            for (int r = 0; r < 2; ++r)
                for (int cc = 0; cc < 2; ++cc)
                    roundRect(cx - g - s * 0.06f + cc * (g + s * 0.12f), cy - g - s * 0.06f + r * (g + s * 0.12f), g, g, g * 0.2f, c);
            break;
        }
    }
}

bool ExtrasActive()
{
    if (Engine.gameMode != ENGINE_MAINGAME) return false;
    if (!StrComp(currentStageFolder, (char *)"Menu")) return false;
    if (objectEntityList[LSM].type != TypeNameID("Extras Menu")) return false;
    int st = objectEntityList[LSM].state;
    return (st == 0 || st == 1 || st == 2 || st == 11);
}

void ExtrasRender(SDL_Renderer *renderer)
{
    if (!ExtrasActive()) { s_exWasOn = false; return; }
    R = renderer;
    int W = 0, H = 0;
    SDL_GetRendererOutputSize(R, &W, &H);
    if (W <= 0 || H <= 0) return;
#if RETRO_USE_TTF
    if (s_cacheOwner != R) { clearCache(); s_cacheOwner = R; }
#endif
    int prevLW = 0, prevLH = 0;
    SDL_RenderGetLogicalSize(R, &prevLW, &prevLH);
    SDL_RenderSetLogicalSize(R, 0, 0);
    SDL_SetRenderDrawBlendMode(R, SDL_BLENDMODE_BLEND);

    const float fw = (float)W, fh = (float)H;
    const float t = SDL_GetTicks() / 1000.0f;
    const float now = (float)SDL_GetTicks();
    if (!s_exWasOn) { s_exWasOn = true; s_exOpenAt = (Uint32)now; s_exBarY = -1.0f; s_exLastSel = -99; }
    const float tOpen = now - s_exOpenAt;

    s_uiBass += (audioMeterBass - s_uiBass) * 0.35f;
    s_uiPeak += (audioMeterPeak - s_uiPeak) * 0.35f;
    float idle = 0.10f + 0.06f * sinf(t * 1.7f);
    float bass = s_uiBass > idle ? s_uiBass : idle;
    float peak = s_uiPeak > idle ? s_uiPeak : idle;

    int sel = objectEntityList[LSM].values[1];
    if (sel != s_exLastSel) { s_exLastSel = sel; s_exSelAt = (Uint32)now; }
    float tSel = now - s_exSelAt;

    // opaque backdrop + accents + top bar
    gradRect(0, 0, fw, fh, { 238, 243, 248, 255 }, { 194, 206, 219, 255 }, false);
    for (int i = 0; i < 4; ++i) {
        float dy = fmodf(t * (5.0f + i * 2.0f) + i * 300.0f, fh + 400.0f) - 200.0f;
        float y = fh - dy, s = fh * (0.16f + 0.06f * i) * (1.0f + 0.22f * bass), rot = t * 0.09f + i;
        float ax = fw * (0.62f - 0.14f * i);
        tri(ax, y, ax + cosf(rot) * s, y + sinf(rot) * s, ax + cosf(rot + 2.1f) * s, y + sinf(rot + 2.1f) * s,
            { 255, 255, 255, (Uint8)(20 + 16 * bass) });
    }
    gradRect(0, 0, fw, fh * 0.014f, { 46, 143, 212, 255 }, { 95, 200, 240, (Uint8)(180 + 75 * peak) }, true);

    float hdrE = easeOutCubic(clamp01(tOpen / 420.0f));
    int hpx = (int)(fh * 0.050f);
    float hx = fw * 0.06f, hy = fh * 0.052f - (1.0f - hdrE) * fh * 0.03f;
    Uint8 hA = (Uint8)(255 * hdrE);
    drawText(hx, hy, "SONIC CD", hpx, { 18, 58, 92, hA }, 0, true);
    int hw2 = textWidth("SONIC CD", hpx, true);
    drawText(hx + hw2 + fh * 0.03f, hy + hpx * 0.22f, "EXTRAS", (int)(fh * 0.028f), { 90, 119, 148, hA }, 0, false);
    gradRect(hx, hy + hpx * 1.25f, (fw * 0.24f) * hdrE, fh * 0.004f, { 46, 143, 212, hA }, { 120, 210, 245, 0 }, true);

    static const char *lbl[4]  = { "D.A. GARDEN", "VISUAL MODE", "SOUND TEST", "STAGE SELECT" };
    static const char *desc[4] = { "Relax in the interactive sound-test garden.",
                                   "Watch the game's animated intro and endings.",
                                   "Listen to every music track and sound effect.",
                                   "Warp straight to any stage you have reached." };
    int unlocked[4];
    unlocked[0] = GVar("Options.DAGardenFlag");
    unlocked[1] = GVar("Options.VisualModeFlag");
    unlocked[2] = GVar("Options.SoundTestFlag");
    unlocked[3] = GVar("Options.StageSelectFlag");

    float colX = fw * 0.06f, colW = fw * 0.88f;
    float availTop = fh * 0.215f, availBot = fh * 0.85f;
    float gap = fh * 0.020f;
    float slotH = (availBot - availTop - gap * 3.0f) / 4.0f;
    const float cr = fh * 0.024f;
    float rowY[4];
    for (int i = 0; i < 4; ++i) rowY[i] = availTop + i * (slotH + gap);

    int selIdx = sel; if (selIdx < 0) selIdx = 0; if (selIdx > 3) selIdx = 3;
    float targetY = rowY[selIdx];
    if (s_exBarY < 0) s_exBarY = targetY;
    s_exBarY += (targetY - s_exBarY) * 0.4f;

    // pass 1: frosted backgrounds
    for (int i = 0; i < 4; ++i) {
        if (i == selIdx) continue;
        float y = rowY[i];
        float en = easeOutCubic(clamp01((tOpen - 80.0f - i * 55.0f) / 360.0f));
        roundRect(colX, y + slotH * 0.10f, colW, slotH, cr, { 30, 60, 100, (Uint8)(24 * en) });
        roundRect(colX, y, colW, slotH, cr, { 255, 255, 255, (Uint8)(82 * en) });
    }
    // highlight
    {
        float y = s_exBarY, h = slotH;
        roundRect(colX - fw * 0.010f, y - fh * 0.012f, colW + fw * 0.020f, h + fh * 0.024f, cr + fh * 0.006f, { 66, 158, 224, (Uint8)(70 * bass) });
        roundRect(colX, y + h * 0.12f, colW, h, cr, { 16, 52, 98, 70 });
        roundRect(colX, y, colW, h, cr, { 47, 143, 212, 255 });
        gradRect(colX + cr, y, colW - cr * 2.0f, h, { 47, 143, 212, 0 }, { 96, 194, 238, (Uint8)(150 + 90 * peak) }, true);
        SDL_SetRenderDrawColor(R, 200, 236, 255, 255);
        rect(colX + colW * 0.014f, y + h * 0.16f, colW * 0.006f, h * 0.68f);
        float sweep = clamp01(tSel / 420.0f);
        if (sweep < 1.0f) {
            float gx = colX + sweep * colW, gw = colW * 0.10f; Uint8 ga = (Uint8)(80 * (1.0f - sweep));
            gradRect(gx - gw, y, gw, h, { 255, 255, 255, 0 }, { 255, 255, 255, ga }, true);
            gradRect(gx, y, gw, h, { 255, 255, 255, ga }, { 255, 255, 255, 0 }, true);
        }
    }
    // pass 2: content
    for (int i = 0; i < 4; ++i) {
        bool selRow = (i == selIdx);
        bool lock = (unlocked[i] != 1);
        float y = rowY[i], h = slotH;
        float en = easeOutCubic(clamp01((tOpen - 80.0f - i * 55.0f) / 360.0f));
        Uint8 rA = (Uint8)(255 * en);
        SDL_Color primary = selRow ? SDL_Color{ 255, 255, 255, rA }
                                   : (lock ? SDL_Color{ 150, 165, 182, rA } : SDL_Color{ 30, 62, 96, rA });
        SDL_Color subtle = selRow ? SDL_Color{ 216, 237, 251, rA } : SDL_Color{ 120, 142, 166, rA };
        float icx = colX + h * 0.66f, icy = y + h * 0.5f, ics = h * 0.26f;
        SDL_Color iconC = selRow ? SDL_Color{ 255, 255, 255, rA } : (lock ? SDL_Color{ 165, 180, 196, rA } : SDL_Color{ 39, 118, 180, rA });
        extrasIcon(i, icx, icy, ics, iconC, t);
        drawText(colX + h * 1.25f, y + h * 0.5f - h * 0.24f, lbl[i], (int)(h * 0.36f), primary, 0, selRow);
        if (lock) {
            padlock(colX + colW - h * 0.5f, icy, h * 0.20f, selRow ? SDL_Color{ 255, 255, 255, rA } : SDL_Color{ 150, 165, 182, rA });
            drawText(colX + colW - h * 0.85f, y + h * 0.5f - h * 0.12f, "LOCKED", (int)(h * 0.16f), subtle, 2, false);
        } else {
            drawText(colX + h * 1.25f, y + h * 0.5f + h * 0.14f, desc[i], (int)(h * 0.17f), subtle, 0, false);
        }
    }

    // hints
    {
        float by = fh * 0.905f, r = fh * 0.026f, px = fw * 0.94f;
        int hp = (int)(fh * 0.030f);
        int bw = textWidth("Back", hp, false);
        drawText(px, by, "Back", hp, { 44, 77, 107, 255 }, 2, false);
        float bcx = px - bw - r - fw * 0.008f;
        circle(bcx, by + hp * 0.55f, r, { 130, 150, 168, 255 });
        drawText(bcx, by + hp * 0.05f, "B", (int)(hp * 0.9f), { 255, 255, 255, 255 }, 1, true);
        float ax2 = bcx - r - fw * 0.03f;
        int sw = textWidth("Select", hp, false);
        drawText(ax2, by, "Select", hp, { 44, 77, 107, 255 }, 2, false);
        float acx = ax2 - sw - r - fw * 0.008f;
        circle(acx, by + hp * 0.55f, r, { 47, 143, 212, 255 });
        drawText(acx, by + hp * 0.05f, "A", (int)(hp * 0.9f), { 255, 255, 255, 255 }, 1, true);
    }

    SDL_RenderSetLogicalSize(R, prevLW, prevLH);
    R = nullptr;
}

// =============================================================================
//  TIME ATTACK menu overlay  (separate "TAttack" presentation stage)
// -----------------------------------------------------------------------------
//  Controller "Menu Control" at entity 0; eight round icons at 32..39 (portraits
//  0..6 = the seven zones, 7 = EXIT / total-time tile). Object[40] = Large Icon
//  (the zone shown in the records sub-menu); 41..43 = per-act Records.
//    MenuControl values : v0 timer  v3 savedRound(0..7)  v4 SMYPos
//                         v5 subBtn(0..2)  v6 beatedRecord(0..3)  v7 SSUnlocked
//    Round-icon  values : v1 min  v2 sec  v3 centis (zone total)  v4 locked
//                         propertyValue = portrait (0..7)
//  Visual overlay only — the stock controller keeps all navigation, SFX and
//  transitions; we only skin it (its native draw is suppressed).  Records for
//  the sub-menu are read straight from saveRAM: base = zone*18 + act*6 + 48 +
//  section, with the top-three placements at +0 / +2 / +4.
// =============================================================================
static const int TA_CTRL  = 0;
static const int TA_ICON  = 32; // 32..39
static const int TA_LICON = 40;

static const char *taZoneName(int p, bool special)
{
    if (special) {
        static const char *s[7] = { "SPECIAL STAGE 1", "SPECIAL STAGE 2", "SPECIAL STAGE 3", "SPECIAL STAGE 4",
                                    "SPECIAL STAGE 5", "SPECIAL STAGE 6", "SPECIAL STAGE 7" };
        return (p >= 0 && p < 7) ? s[p] : "EXIT";
    }
    static const char *z[7] = { "PALMTREE PANIC", "COLLISION CHAOS", "TIDAL TEMPEST", "QUARTZ QUADRANT",
                                "WACKY WORKBENCH", "STARDUST SPEEDWAY", "METALLIC MADNESS" };
    return (p >= 0 && p < 7) ? z[p] : "EXIT";
}
static const char *taZoneShort(int p, bool special) // fits the small grid tiles
{
    if (special) {
        static const char *s[7] = { "STAGE 1", "STAGE 2", "STAGE 3", "STAGE 4", "STAGE 5", "STAGE 6", "STAGE 7" };
        return (p >= 0 && p < 7) ? s[p] : "EXIT";
    }
    static const char *z[7] = { "PALMTREE", "COLLISION", "TIDAL", "QUARTZ", "WACKY", "STARDUST", "METALLIC" };
    return (p >= 0 && p < 7) ? z[p] : "EXIT";
}
static SDL_Color taAccent(int p, bool special)
{
    if (special) return SDL_Color{ 150, 96, 214, 255 }; // special stages — violet
    static const SDL_Color c[7] = {
        {  46, 172,  96, 255 }, // Palmtree Panic  — verdant green
        { 226,  96, 138, 255 }, // Collision Chaos — hot pink
        {  46, 154, 216, 255 }, // Tidal Tempest   — aqua blue
        { 218, 160,  46, 255 }, // Quartz Quadrant — amber
        { 150, 112, 212, 255 }, // Wacky Workbench — purple
        { 220,  86,  74, 255 }, // Stardust Speedway — red
        {  96, 114, 146, 255 }, // Metallic Madness — steel
    };
    return (p >= 0 && p < 7) ? c[p] : SDL_Color{ 96, 114, 146, 255 };
}
static void taSplit(int raw, int &mn, int &sc, int &cs)
{
    if (raw < 0) raw = 0;
    mn = raw / 6000;
    sc = (raw / 100) % 60;
    cs = raw % 100;
}
// a compact stopwatch glyph (used as the section emblem)
static void taStopwatch(float cx, float cy, float s, SDL_Color c, float handAng)
{
    SDL_Color soft = c; soft.a = (Uint8)(c.a * 0.4f);
    ring(cx, cy + s * 0.08f, s * 0.94f, s * 0.76f, c);
    SDL_SetRenderDrawColor(R, c.r, c.g, c.b, c.a);
    rect(cx - s * 0.11f, cy - s * 1.06f, s * 0.22f, s * 0.22f); // crown stem
    for (int i = 0; i < 12; ++i) {
        float a = i / 12.0f * TAU, rr = s * 0.82f;
        line(cx + cosf(a) * rr, cy + s * 0.08f + sinf(a) * rr,
             cx + cosf(a) * rr * 0.88f, cy + s * 0.08f + sinf(a) * rr * 0.88f, s * 0.05f, soft);
    }
    line(cx, cy + s * 0.08f, cx + cosf(handAng) * s * 0.6f, cy + s * 0.08f + sinf(handAng) * s * 0.6f, s * 0.08f, c);
    circle(cx, cy + s * 0.08f, s * 0.10f, c);
}

static bool   s_taWasOn = false;
static Uint32 s_taOpenAt = 0;
static float  s_taBarX = -1.0f, s_taBarY = -1.0f;
static int    s_taLastSel = -99;
static Uint32 s_taSelAt = 0;
static float  s_taSub = 0.0f; // 0 = grid .. 1 = records sub-menu (eased)
static float  s_taActX = -1.0f;

// ---- zone preview thumbnails, blitted from TAttack/TimeAttack.gif -----------
// Each zone's full screenshot lives in a 4x2 atlas in the top of the sheet.
static const SDL_Rect s_taZoneRect[7] = {
    {   1,   6, 126, 140 }, // Palmtree Panic
    { 257,   6, 126, 140 }, // Collision Chaos
    { 385,   6, 126, 140 }, // Tidal Tempest
    {   1, 150, 126, 140 }, // Quartz Quadrant
    { 129, 150, 126, 140 }, // Wacky Workbench
    { 257, 150, 126, 140 }, // Stardust Speedway
    { 385, 150, 126, 140 }, // Metallic Madness
};
static void ensureTASheet()
{
    if (s_taSheetTried) return;
    s_taSheetTried = true;
#if RETRO_USE_IMG
    static const char *paths[] = { "Data/Sprites/TAttack/TimeAttack.gif", "./Data/Sprites/TAttack/TimeAttack.gif",
                                   "SonicCD-Native/Data/Sprites/TAttack/TimeAttack.gif" };
    for (const char *p : paths) {
        SDL_Surface *s = IMG_Load(p);
        if (!s) continue;
        s_taSheet = SDL_CreateTextureFromSurface(R, s);
        SDL_FreeSurface(s);
        if (s_taSheet) {
            SDL_SetTextureBlendMode(s_taSheet, SDL_BLENDMODE_BLEND);
            SDL_SetTextureScaleMode(s_taSheet, SDL_ScaleModeLinear); // smooth upscale
        }
        break;
    }
#endif
}
// Draw a zone screenshot filling (x,y,w,h). The SOURCE rect is cropped to the
// destination's aspect (centred) so the copy fills the box exactly with no
// overflow — that avoids per-preview SDL clip-rect changes, which stall the
// software renderer's batching (the old clipped path caused the nav lag).
// anim > 0 adds a gentle Ken Burns zoom+drift; tint (grey multiply) dims it.
static bool drawZonePreview(int zone, bool special, float x, float y, float w, float h,
                            Uint8 alpha, float anim = 0.0f, Uint8 tint = 255)
{
    ensureTASheet();
    if (special || !s_taSheet || zone < 0 || zone > 6) return false;
    SDL_Rect src = s_taZoneRect[zone];
    if (anim > 0.0f) {
        float z = 0.05f + 0.025f * sinf(anim * 0.5f);
        int ix = (int)(src.w * z), iy = (int)(src.h * z);
        src.x += ix + (int)(5.0f * sinf(anim * 0.37f));
        src.y += iy + (int)(3.5f * cosf(anim * 0.29f));
        src.w -= ix * 2; src.h -= iy * 2;
    }
    float dstAsp = w / h, srcAsp = (float)src.w / (float)src.h;
    if (srcAsp > dstAsp) { int nw = (int)(src.h * dstAsp); src.x += (src.w - nw) / 2; src.w = nw; }
    else                 { int nh = (int)(src.w / dstAsp); src.y += (src.h - nh) / 2; src.h = nh; }
    SDL_FRect dst = { x, y, w, h };
    SDL_SetTextureColorMod(s_taSheet, tint, tint, tint);
    SDL_SetTextureAlphaMod(s_taSheet, alpha);
    SDL_RenderCopyF(R, s_taSheet, &src, &dst);
    SDL_SetTextureAlphaMod(s_taSheet, 255);
    SDL_SetTextureColorMod(s_taSheet, 255, 255, 255);
    return true;
}
// soft top-light for a glassy card finish
static void glossTop(float x, float y, float w, float h, Uint8 a)
{
    gradRect(x, y, w, h, { 255, 255, 255, a }, { 255, 255, 255, 0 }, false);
}
// Rounded top-gloss: respects a rounded rect's corners (no rectangular spill into
// the rounded corners — which read as ugly semi-transparent notches). Two soft
// layers fake the top-bright falloff. Use on any rounded button/card.
static void glossTopR(float x, float y, float w, float h, float r, Uint8 a)
{
    roundRect(x, y, w, h, r, { 255, 255, 255, (Uint8)(a * 0.5f) });
    roundRect(x, y, w, h * 0.58f, r, { 255, 255, 255, (Uint8)(a * 0.5f) });
}
// a specular sheen band sweeping L->R across (x,y,w,h); t01 in [0,1] is the pass
static void sheenSweep(float x, float y, float w, float h, float t01, Uint8 a)
{
    if (t01 < 0.0f || t01 > 1.0f) return;
    SDL_Rect clip = { (int)x, (int)y, (int)(w + 0.999f), (int)(h + 0.999f) };
    SDL_RenderSetClipRect(R, &clip);
    float bx = x - w * 0.35f + t01 * (w * 1.7f), bw = w * 0.16f;
    gradRect(bx - bw, y, bw, h, { 255, 255, 255, 0 }, { 255, 255, 255, a }, true);
    gradRect(bx, y, bw, h, { 255, 255, 255, a }, { 255, 255, 255, 0 }, true);
    SDL_RenderSetClipRect(R, nullptr);
}
// small filled play-triangle badge (accent disc) — marks the focused tile
static void playBadge(float cx, float cy, float r, SDL_Color disc, SDL_Color tri_, Uint8 a)
{
    disc.a = a; tri_.a = a;
    circle(cx, cy, r, disc);
    tri(cx - r * 0.32f, cy - r * 0.42f, cx - r * 0.32f, cy + r * 0.42f, cx + r * 0.46f, cy, tri_);
}
// split a full zone name across up to two lines at the first space
static void taNameLines(int zone, bool special, char *l1, char *l2, int sz)
{
    const char *full = taZoneName(zone, special);
    int i = 0; while (full[i] && full[i] != ' ') ++i;
    int n = (i < sz - 1) ? i : sz - 1;
    for (int k = 0; k < n; ++k) l1[k] = full[k];
    l1[n] = 0;
    if (full[i] == ' ') snprintf(l2, sz, "%s", full + i + 1);
    else l2[0] = 0;
}
// centred text that auto-scales down to fit maxW
static void drawTextFit(float cx, float y, const char *s, int px, SDL_Color col, float maxW, bool bold)
{
    int w = textWidth(s, px, bold);
    float sc = (w > maxW && w > 0) ? maxW / w : 1.0f;
    drawText(cx, y, s, px, col, 1, bold, sc);
}

bool TAActive()
{
    if (Engine.gameMode != ENGINE_MAINGAME) return false;
    if (!StrComp(currentStageFolder, (char *)"TAttack")) return false;
    if (objectEntityList[TA_CTRL].type != TypeNameID("Menu Control")) return false;
    int it = objectEntityList[TA_ICON].type;
    if (it != TypeNameID("Round Icon") && it != TypeNameID("Special Icon")) return false;
    return true;
}

void TARender(SDL_Renderer *renderer)
{
    if (!TAActive()) { s_taWasOn = false; return; }
    R = renderer;
    int W = 0, H = 0;
    SDL_GetRendererOutputSize(R, &W, &H);
    if (W <= 0 || H <= 0) return;
#if RETRO_USE_TTF
    if (s_cacheOwner != R) { clearCache(); s_cacheOwner = R; }
#endif
    int prevLW = 0, prevLH = 0;
    SDL_RenderGetLogicalSize(R, &prevLW, &prevLH);
    SDL_RenderSetLogicalSize(R, 0, 0);
    SDL_SetRenderDrawBlendMode(R, SDL_BLENDMODE_BLEND);

    const float fw = (float)W, fh = (float)H;
    const float t = SDL_GetTicks() / 1000.0f;
    const float now = (float)SDL_GetTicks();
    if (!s_taWasOn) {
        s_taWasOn = true; s_taOpenAt = (Uint32)now;
        s_taBarX = s_taBarY = -1.0f; s_taActX = -1.0f; s_taLastSel = -99; s_taSub = 0.0f;
    }
    const float tOpen = now - s_taOpenAt;
    float fade = clamp01(tOpen / 300.0f);

    s_uiBass += (audioMeterBass - s_uiBass) * 0.35f;
    s_uiPeak += (audioMeterPeak - s_uiPeak) * 0.35f;
    float idle = 0.10f + 0.06f * sinf(t * 1.7f);
    float bass = s_uiBass > idle ? s_uiBass : idle;
    float peak = s_uiPeak > idle ? s_uiPeak : idle;

    Entity *ctrl   = &objectEntityList[TA_CTRL];
    int state      = ctrl->state;
    int savedRound = ctrl->values[3];
    int smBtn      = ctrl->values[5];
    int smYPos     = ctrl->values[4];
    int beated     = ctrl->values[6];
    bool ssUnlock  = ctrl->values[7] != 0;
    int section    = GVar("TimeAttack.MenuSection");
    bool special   = (section == 1);

    if (savedRound != s_taLastSel) { s_taLastSel = savedRound; s_taSelAt = (Uint32)now; }
    float tSel = now - s_taSelAt;

    // grid vs. records sub-menu (states 5..15 are the sub-menu flow)
    bool inSub = (state >= 5 && state <= 15);
    s_taSub += ((inSub ? 1.0f : 0.0f) - s_taSub) * 0.18f;
    float gridA = clamp01(1.0f - s_taSub * 1.6f); // grid clears out as the panel arrives
    float subA  = clamp01((s_taSub - 0.12f) / 0.88f);

    // ---------------------------------------------------------------- backdrop
    gradRect(0, 0, fw, fh, { 238, 243, 248, 255 }, { 194, 206, 219, 255 }, false);
    {
        float wr = fh * (0.44f + 0.02f * bass);
        ring(fw * 0.83f, fh * 0.40f, wr, wr * 0.965f, { 120, 175, 220, 24 });
        ring(fw * 0.83f, fh * 0.40f, wr * 0.74f, wr * 0.72f, { 120, 175, 220, 18 });
    }
    for (int i = 0; i < 4; ++i) {
        float dy = fmodf(t * (5.0f + i * 2.0f) + i * 300.0f, fh + 400.0f) - 200.0f;
        float y = fh - dy, s = fh * (0.16f + 0.06f * i) * (1.0f + 0.22f * bass), rot = t * 0.09f + i;
        float ax = fw * (0.12f + 0.17f * i);
        tri(ax, y, ax + cosf(rot) * s, y + sinf(rot) * s, ax + cosf(rot + 2.1f) * s, y + sinf(rot + 2.1f) * s,
            { 255, 255, 255, (Uint8)(20 + 16 * bass) });
    }
    for (int i = 0; i < 16; ++i) {
        float px = fmodf(0.0625f * i + 0.13f * sinf(i * 2.3f) + t * 0.004f * ((i & 1) ? 1 : -1), 1.0f) * fw;
        float spd = 10.0f + (i % 5) * 6.0f;
        float py = fh + fh * 0.05f - fmodf(t * spd + i * 90.0f, fh + fh * 0.1f);
        float sz = fh * 0.005f * (1.0f + (i % 3) * 0.5f) * (1.0f + 0.7f * bass);
        diamond(px, py, sz, { 120, 190, 235, (Uint8)(24 + 44 * bass) });
    }
    gradRect(0, 0, fw, fh * 0.014f, { 46, 143, 212, 255 }, { 95, 200, 240, (Uint8)(180 + 75 * peak) }, true);
    {
        float m = fh * 0.20f; Uint8 va = 34;
        gradRect(0, 0, fw, m, { 18, 40, 66, va }, { 18, 40, 66, 0 }, false);
        gradRect(0, fh - m, fw, m, { 18, 40, 66, 0 }, { 18, 40, 66, va }, false);
        gradRect(0, 0, m, fh, { 18, 40, 66, va }, { 18, 40, 66, 0 }, true);
        gradRect(fw - m, 0, m, fh, { 18, 40, 66, 0 }, { 18, 40, 66, va }, true);
    }

    // ------------------------------------------------------------------ header
    float hdrE = easeOutCubic(clamp01(tOpen / 420.0f));
    int hpx = (int)(fh * 0.050f);
    float hx = fw * 0.06f, hy = fh * 0.052f - (1.0f - hdrE) * fh * 0.03f;
    Uint8 hA = (Uint8)(255 * hdrE);
    drawText(hx, hy, "SONIC CD", hpx, { 18, 58, 92, hA }, 0, true);
    int hw2 = textWidth("SONIC CD", hpx, true);
    drawText(hx + hw2 + fh * 0.03f, hy + hpx * 0.22f, "TIME ATTACK", (int)(fh * 0.028f), { 90, 119, 148, hA }, 0, false);
    gradRect(hx, hy + hpx * 1.25f, (fw * 0.24f) * hdrE, fh * 0.004f, { 46, 143, 212, hA }, { 120, 210, 245, 0 }, true);

    // total time (icon 39) + section pill, right side of the header
    {
        Entity *tot = &objectEntityList[TA_ICON + 7];
        char tbuf[24]; snprintf(tbuf, sizeof(tbuf), "%d'%02d\"%02d", tot->values[1], tot->values[2], tot->values[3]);
        float rx = fw * 0.94f, ry = fh * 0.052f;
        drawText(rx, ry, tbuf, (int)(fh * 0.044f), { 30, 62, 96, hA }, 2, true);
        drawText(rx, ry + fh * 0.052f, special ? "SPECIAL STAGE TOTAL" : "TOTAL TIME", (int)(fh * 0.022f), { 96, 122, 150, hA }, 2, false);
    }

    // =========================================================== GRID (screen 1)
    if (gridA > 0.004f) {
        Uint8 GA = (Uint8)(gridA * fade * 255);
        float gx0 = fw * 0.055f, gx1 = fw * 0.945f;
        float colGap = fw * 0.016f, rowGap = fh * 0.028f;
        float cardW = (gx1 - gx0 - colGap * 3.0f) / 4.0f;
        float gy0 = fh * 0.225f;
        float cardH = (fh * 0.600f - rowGap) * 0.5f;

        int selCell = savedRound; if (selCell < 0) selCell = 0; if (selCell > 7) selCell = 7;
        bool haveSel = (savedRound >= 0);
        bool confirming = objectEntityList[TA_ICON + selCell].state == 1;
        SDL_Color selAcc = taAccent(objectEntityList[TA_ICON + selCell].propertyValue, special);
        float selPop = 1.0f + 0.055f * (1.0f - easeOutCubic(clamp01(tSel / 240.0f))); // pop when the selection moves

        // sprung glow -> selected tile centre (gives the moving-selection feel)
        float selCX = gx0 + (selCell % 4) * (cardW + colGap) + cardW * 0.5f;
        float selCY = gy0 + (selCell / 4) * (cardH + rowGap) + cardH * 0.5f;
        if (s_taBarX < 0) { s_taBarX = selCX; s_taBarY = selCY; }
        s_taBarX += (selCX - s_taBarX) * 0.55f;   // snappier: the glow keeps up with the cursor
        s_taBarY += (selCY - s_taBarY) * 0.55f;
        if (haveSel) {
            float pulseA = confirming ? (0.6f + 0.4f * sinf(now * 0.03f)) : (0.42f + 0.5f * bass);
            float gw = cardW * 1.16f, gh = cardH * 1.16f;
            roundRect(s_taBarX - gw * 0.5f, s_taBarY - gh * 0.5f, gw, gh, fh * 0.032f,
                      { selAcc.r, selAcc.g, selAcc.b, (Uint8)(120 * pulseA * fade * gridA) });
        }

        for (int i = 0; i < 8; ++i) {
            int col = i % 4, row = i / 4;
            Entity *ic = &objectEntityList[TA_ICON + i];
            int p = ic->propertyValue; if (p < 0 || p > 7) p = i;
            bool exitTile = (p == 7);
            bool locked = !exitTile && ic->values[4] != 0;
            bool sel = (i == selCell && haveSel);

            float en = clamp01(easeOutBack(clamp01((tOpen - 60.0f - i * 42.0f) / 380.0f)));
            Uint8 cA = (Uint8)(GA * en);
            float baseX = gx0 + col * (cardW + colGap);
            float baseY = gy0 + row * (cardH + rowGap) + (1.0f - en) * fh * 0.03f;
            float scl = sel ? selPop : 1.0f;                 // selected tile pops out
            float w = cardW * scl, h = cardH * scl;
            float x = baseX + (cardW - w) * 0.5f, y = baseY + (cardH - h) * 0.5f;
            SDL_Color acc = taAccent(p, special);
            float rr = fh * 0.020f;

            roundRect(x, y + h * 0.07f, w, h, rr, { 18, 42, 76, (Uint8)((sel ? 70 : 30) * en * gridA) }); // soft drop shadow
            if (sel) {
                roundRect(x - fh * 0.004f, y - fh * 0.004f, w + fh * 0.008f, h + fh * 0.008f, rr + fh * 0.004f,
                          { acc.r, acc.g, acc.b, cA });                                                    // accent frame
                roundRect(x, y, w, h, rr, { 253, 254, 255, cA });                                          // bright body
            } else {
                // subtle zone-tinted frosted body for a richer, colour-coded look
                SDL_Color body = { (Uint8)(248 - (248 - acc.r) * 0.06f), (Uint8)(250 - (250 - acc.g) * 0.06f),
                                   (Uint8)(252 - (252 - acc.b) * 0.06f), (Uint8)(178 * en * gridA) };
                roundRect(x, y, w, h, rr, body);
            }
            glossTop(x, y, w, h * 0.42f, (Uint8)((sel ? 120 : 60) * en * gridA));                          // glass sheen

            if (exitTile) {
                SDL_Color ec = { 64, 96, 128, cA };
                float ax = x + w * 0.5f, ay = y + h * 0.32f, ar = h * 0.135f;
                ring(ax + ar * 0.18f, ay, ar, ar * 0.58f, ec, 28, 2.2f, 2.2f + TAU * 0.72f);
                tri(ax - ar * 0.5f, ay - ar * 0.55f, ax - ar * 0.5f, ay + ar * 0.14f, ax - ar * 1.2f, ay - ar * 0.2f, ec);
                drawTextFit(x + w * 0.5f, y + h * 0.55f, "EXIT", (int)(h * 0.15f), { 38, 70, 102, cA }, w * 0.8f, true);
                Entity *tt = &objectEntityList[TA_ICON + 7];
                char tb[24]; snprintf(tb, sizeof(tb), "%d'%02d\"%02d", tt->values[1], tt->values[2], tt->values[3]);
                drawTextFit(x + w * 0.5f, y + h * 0.72f, "TOTAL", (int)(h * 0.08f), { 120, 142, 166, cA }, w * 0.8f, false);
                drawTextFit(x + w * 0.5f, y + h * 0.82f, tb, (int)(h * 0.10f), { 70, 118, 168, cA }, w * 0.8f, true);
                continue;
            }

            // ---- zone preview thumbnail (no clip: tint via the texture, Ken Burns on the selected tile) ----
            float pw = w * 0.86f, ph = h * 0.44f;
            float pxx = x + (w - pw) * 0.5f, pyy = y + h * 0.075f;
            roundRect(pxx - fh * 0.005f, pyy - fh * 0.005f, pw + fh * 0.010f, ph + fh * 0.010f, fh * 0.008f,
                      { acc.r, acc.g, acc.b, cA });                                          // accent frame
            Uint8 tint = locked ? 74 : (sel ? 255 : 206);
            if (!drawZonePreview(p, special, pxx, pyy, pw, ph, cA, sel ? t : 0.0f, tint)) {
                circle(pxx + pw * 0.5f, pyy + ph * 0.5f, ph * 0.42f, { acc.r, acc.g, acc.b, cA });
                taStopwatch(pxx + pw * 0.5f, pyy + ph * 0.5f, ph * 0.24f, { 255, 255, 255, cA }, -1.5708f + t * 2.0f);
            }
            gradRect(pxx, pyy + ph * 0.66f, pw, ph * 0.34f, { 10, 20, 38, 0 }, { 10, 20, 38, (Uint8)(64 * en * gridA) }, false); // grounded base
            if (locked)    padlock(pxx + pw * 0.5f, pyy + ph * 0.5f, ph * 0.22f, { 236, 241, 247, cA });
            else if (!sel) playBadge(pxx + pw - fh * 0.018f, pyy + fh * 0.018f, fh * 0.018f, acc, { 255, 255, 255, 255 }, cA);

            // ---- full zone name (two lines) + best time ----
            char l1[24], l2[24]; taNameLines(p, special, l1, l2, 24);
            SDL_Color nc = sel ? SDL_Color{ 22, 58, 94, cA } : SDL_Color{ 52, 80, 110, cA };
            int npx = (int)(h * 0.10f);
            drawTextFit(x + w * 0.5f, y + h * 0.56f, l1, npx, nc, w * 0.9f, true);
            if (l2[0]) drawTextFit(x + w * 0.5f, y + h * 0.665f, l2, npx, nc, w * 0.9f, true);
            if (locked) {
                drawTextFit(x + w * 0.5f, y + h * 0.82f, "LOCKED", (int)(h * 0.085f), { 150, 165, 184, cA }, w * 0.9f, true);
            } else {
                char tb[24]; snprintf(tb, sizeof(tb), "%d'%02d\"%02d", ic->values[1], ic->values[2], ic->values[3]);
                SDL_Color tc = sel ? SDL_Color{ acc.r, acc.g, acc.b, cA } : SDL_Color{ 96, 122, 152, cA };
                drawTextFit(x + w * 0.5f, y + h * 0.82f, tb, (int)(h * 0.10f), tc, w * 0.9f, true);
            }
        }

        // section switch hint + prompt
        Uint8 GT = (Uint8)(GA);
        if (ssUnlock)
            drawText(fw * 0.055f, fh * 0.85f, special ? "UP / DOWN   \xC2\xB7   Back to the zones" : "UP / DOWN   \xC2\xB7   Special Stages",
                     (int)(fh * 0.026f), { 96, 122, 150, GT }, 0, false);
        drawText(fw * 0.055f, fh * 0.885f,
                 (savedRound == 7) ? "Return to the main menu."
                                   : "Select a zone to race the clock for your best time.",
                 (int)(fh * 0.030f), { 74, 103, 132, GT }, 0, false);
    }

    // ==================================================== RECORDS (screen 2)
    if (subA > 0.004f) {
        Uint8 SA = (Uint8)(subA * 255);
        float ein = easeOutBack(clamp01(subA));              // spring entrance
        float pop = 0.92f + 0.10f * ein;
        int zone = objectEntityList[TA_LICON].propertyValue;
        if (zone < 0 || zone > 6) { zone = savedRound; if (zone < 0 || zone > 6) zone = 0; }
        SDL_Color acc = taAccent(zone, special);
        SDL_Color accS = { acc.r, acc.g, acc.b, SA };

        float pw = fw * 0.62f * pop, ph = fh * 0.76f * pop;
        float px = (fw - pw) * 0.5f, py = fh * 0.13f + (1.0f - clamp01(ein)) * fh * 0.04f;
        float rr = fh * 0.028f;

        // glow + shadow + frosted panel
        roundRect(px - fw * 0.012f, py - fh * 0.016f, pw + fw * 0.024f, ph + fh * 0.032f, fh * 0.042f,
                  { acc.r, acc.g, acc.b, (Uint8)(55 * (0.5f + 0.5f * bass) * subA) });
        roundRect(px + fw * 0.006f, py + fh * 0.014f, pw, ph, rr, { 18, 42, 78, (Uint8)(85 * subA) });
        roundRect(px, py, pw, ph, rr, { 250, 252, 254, (Uint8)(250 * subA) });
        glossTop(px, py, pw, ph * 0.28f, (Uint8)(40 * subA));

        // ---- header bar (rounded top) with the zone name ----
        float hb = ph * 0.11f;
        roundRect(px, py, pw, hb, rr, accS);
        SDL_SetRenderDrawColor(R, acc.r, acc.g, acc.b, SA);
        rect(px, py + hb * 0.5f, pw, hb * 0.5f);              // square off the bottom edge
        sheenSweep(px, py, pw, hb, fmodf(t * 0.3f, 4.0f), (Uint8)(70 * subA));
        {
            float ecx = px + pw * 0.05f, ecy = py + hb * 0.5f, er = hb * 0.32f;
            circle(ecx, ecy, er, { 255, 255, 255, SA });
            taStopwatch(ecx, ecy, er * 0.6f, acc, -1.5708f + t * 2.4f);
            drawText(px + pw * 0.10f, py + hb * 0.5f - ph * 0.036f, taZoneName(zone, special), (int)(ph * 0.058f), { 255, 255, 255, SA }, 0, true);
            drawText(px + pw * 0.95f, py + hb * 0.5f - ph * 0.02f, special ? "SPECIAL STAGE" : "BEST TIMES",
                     (int)(ph * 0.03f), { 235, 242, 250, SA }, 2, false);
        }

        // ---- content: hero preview (left) + vertical act list (right) --------
        float cy0 = py + hb + ph * 0.035f, ch = ph * 0.45f;
        float hx = px + pw * 0.045f, hw = pw * 0.32f, hh = ch;
        roundRect(hx - fh * 0.004f, cy0 - fh * 0.004f, hw + fh * 0.008f, hh + fh * 0.008f, fh * 0.009f, accS);
        if (!drawZonePreview(zone, special, hx, cy0, hw, hh, SA, t)) {
            gradRect(hx, cy0, hw, hh, accS,
                     { (Uint8)(acc.r * 0.55f), (Uint8)(acc.g * 0.55f), (Uint8)(acc.b * 0.55f), SA }, false);
            taStopwatch(hx + hw * 0.5f, cy0 + hh * 0.5f, hh * 0.28f, { 255, 255, 255, SA }, -1.5708f + t * 2.2f);
        }
        sheenSweep(hx, cy0, hw, hh, fmodf(t * 0.33f + 0.5f, 3.6f), (Uint8)(70 * subA));

        // vertical act list (Up/Down navigates it — matches the stock control)
        int actCount = special ? 1 : 3;
        float ax = hx + hw + pw * 0.05f, aw = (px + pw * 0.955f) - ax, ay = cy0, ah = ch;
        bool actFocus = (!special && smBtn == 1);

        float af = (smYPos - 192) / 192.0f;
        int curAct = ((int)lroundf(af)) % 3; if (curAct < 0) curAct += 3;
        if (special) curAct = 0;

        if (actFocus) { // focus glow when the act list is the active control
            float pf = 0.6f + 0.4f * sinf(now * 0.006f);
            roundRect(ax - fh * 0.008f, ay - fh * 0.008f, aw + fh * 0.016f, ah + fh * 0.016f, fh * 0.018f,
                      { acc.r, acc.g, acc.b, (Uint8)(90 * pf * subA) });
        }

        // Reversed row order: the stock's UP increments the act index, so we place
        // higher acts higher up — pressing UP then moves the highlight UPWARD (and
        // onto the act shown above), which is what a player expects.
        float rowH = ah / actCount;
        float curRowY = ay + ((actCount - 1) - curAct) * rowH;
        if (s_taActX < 0) s_taActX = curRowY;
        s_taActX += (curRowY - s_taActX) * 0.5f;   // snappier
        roundRect(ax, s_taActX + rowH * 0.05f, aw, rowH * 0.9f, fh * 0.014f, { acc.r, acc.g, acc.b, (Uint8)(52 * subA) });

        static const SDL_Color medal[3] = { { 232, 194, 78, 255 }, { 190, 202, 214, 255 }, { 202, 132, 82, 255 } };
        for (int a = 0; a < actCount; ++a) {
            float ry = ay + ((actCount - 1) - a) * rowH, rh = rowH * 0.9f;
            bool curc = (a == curAct);
            if (curc) {
                SDL_SetRenderDrawColor(R, acc.r, acc.g, acc.b, SA);
                rect(ax + aw * 0.006f, ry + rh * 0.18f, aw * 0.008f, rh * 0.64f);       // left accent bar
                tri(ax + aw * 0.035f, ry + rh * 0.30f, ax + aw * 0.035f, ry + rh * 0.70f, ax + aw * 0.075f, ry + rh * 0.5f, accS); // pointer
            }
            const char *al = special ? "RECORD" : (a == 0 ? "ACT 1" : a == 1 ? "ACT 2" : "ACT 3");
            SDL_Color alc = curc ? SDL_Color{ 30, 62, 96, SA } : SDL_Color{ 118, 138, 162, SA };
            drawText(ax + aw * 0.10f, ry + rh * 0.5f - rh * 0.18f, al, (int)(rh * 0.34f), alc, 0, true);

            int base = zone * 18 + a * 6 + 48 + section;
            float tx = ax + aw * 0.34f, tstep = aw * 0.225f;
            for (int rk = 0; rk < 3; ++rk) {
                int idx = base + rk * 2;
                int raw = (idx >= 0 && idx < SAVEDATA_SIZE) ? saveRAM[idx] : 0;
                int mn, sc2, cs; taSplit(raw, mn, sc2, cs);
                SDL_Color mc = medal[rk]; mc.a = (Uint8)(curc ? SA : SA * 0.7f);
                diamond(tx, ry + rh * 0.5f, rh * 0.13f, mc);
                char rb[24]; snprintf(rb, sizeof(rb), "%d'%02d\"%02d", mn, sc2, cs);
                SDL_Color rc = curc ? SDL_Color{ 34, 64, 96, SA } : SDL_Color{ 120, 140, 166, (Uint8)(SA * 0.8f) };
                drawText(tx + rh * 0.24f, ry + rh * 0.5f - rh * 0.17f, rb, (int)(rh * 0.30f), rc, 0, rk == 0);
                tx += tstep;
            }
        }
        if (!special) { // act-switch caption — brightens when the list is focused
            SDL_Color cc = actFocus ? SDL_Color{ acc.r, acc.g, acc.b, SA }
                                    : SDL_Color{ 120, 140, 164, (Uint8)(subA * 170) };
            drawText(ax + aw * 0.5f, ay + ah + ph * 0.008f, "UP / DOWN  to choose act", (int)(ph * 0.03f), cc, 1, actFocus);
        }

        // ---- buttons: BACK / NEXT / GO  (NEXT hidden for special stages) -----
        {
            const char *lbl[3] = { "BACK", "NEXT", "GO" };
            const char *sub[3] = { "to zones", "next act", "" };
            char goSub[12]; snprintf(goSub, sizeof(goSub), "act %d", curAct + 1);
            float by = py + ph * 0.70f, bh = ph * 0.13f;
            int shown = special ? 2 : 3;
            int order[3] = { 0, 1, 2 };
            if (special) order[1] = 2; // BACK, GO
            float bw = (pw * 0.86f - pw * 0.03f * (shown - 1)) / shown;
            float bx0 = px + pw * 0.07f;
            for (int s = 0; s < shown; ++s) {
                int id = order[s];
                bool bs = (smBtn == id);
                float bx = bx0 + s * (bw + pw * 0.03f);
                SDL_Color fill = (id == 2) ? acc : SDL_Color{ 92, 118, 148, 255 };
                const char *ss = (id == 2) ? (special ? "" : goSub) : sub[id];
                if (bs) {
                    roundRect(bx - fw * 0.004f, by - fh * 0.006f, bw + fw * 0.008f, bh + fh * 0.012f, bh * 0.34f,
                              { fill.r, fill.g, fill.b, (Uint8)(80 * subA) });
                    roundRect(bx, by, bw, bh, bh * 0.30f, { fill.r, fill.g, fill.b, SA });
                    glossTop(bx, by, bw, bh * 0.5f, (Uint8)(70 * subA));
                    drawTextFit(bx + bw * 0.5f, by + bh * 0.30f - ph * 0.03f, lbl[id], (int)(ph * 0.05f), { 255, 255, 255, SA }, bw * 0.8f, true);
                    if (ss[0]) drawTextFit(bx + bw * 0.5f, by + bh * 0.66f, ss, (int)(ph * 0.028f), { 255, 255, 255, (Uint8)(SA * 0.8f) }, bw * 0.8f, false);
                } else {
                    roundRect(bx, by, bw, bh, bh * 0.30f, { 236, 240, 244, SA });
                    drawTextFit(bx + bw * 0.5f, by + bh * 0.30f - ph * 0.03f, lbl[id], (int)(ph * 0.05f), { 92, 114, 140, SA }, bw * 0.8f, true);
                    if (ss[0]) drawTextFit(bx + bw * 0.5f, by + bh * 0.66f, ss, (int)(ph * 0.028f), { 150, 166, 186, SA }, bw * 0.8f, false);
                }
            }
        }

        // ---- control legend ----
        drawTextFit(px + pw * 0.5f, py + ph * 0.90f,
                    special ? "LEFT / RIGHT  Move       A  Confirm       B  Back"
                            : "UP / DOWN  Change Act      LEFT / RIGHT  Move      A  Confirm      B  Back",
                    (int)(ph * 0.032f), { 120, 140, 164, (Uint8)(subA * 220) }, pw * 0.92f, false);

        // ---- NEW RECORD! celebration (state 15) ----
        if (state == 15 && beated > 0) {
            float cy = fh * 0.5f;
            SDL_SetRenderDrawColor(R, 8, 20, 38, (Uint8)(120 * subA));
            rect(0, 0, fw, fh);
            float bw = fw * 0.5f, bh = fh * 0.22f, bx = (fw - bw) * 0.5f, byy = cy - bh * 0.5f;
            SDL_Color gold = { 232, 194, 78, 255 };
            roundRect(bx, byy, bw, bh, fh * 0.03f, { 249, 251, 253, SA });
            roundRect(bx, byy, bw, bh * 0.14f, fh * 0.03f, { gold.r, gold.g, gold.b, SA });
            star(fw * 0.5f, byy + bh * 0.34f, fh * 0.045f * (1.0f + 0.1f * sinf(now * 0.02f)), fh * 0.018f, 5, now * 0.004f, gold);
            drawText(fw * 0.5f, byy + bh * 0.52f, "NEW RECORD!", (int)(fh * 0.05f), { 30, 62, 96, SA }, 1, true);
            const char *place = beated == 1 ? "1ST PLACE" : beated == 2 ? "2ND PLACE" : "3RD PLACE";
            drawText(fw * 0.5f, byy + bh * 0.74f, place, (int)(fh * 0.03f), { 150, 120, 40, SA }, 1, true);
        }
    }

    // ------------------------------------------------ button hints (grid only)
    if (subA <= 0.02f) {
        float by = fh * 0.905f, r = fh * 0.026f, px = fw * 0.94f;
        int hp = (int)(fh * 0.030f);
        Uint8 A = (Uint8)(fade * 255);
        int bw = textWidth("Back", hp, false);
        drawText(px, by, "Back", hp, { 44, 77, 107, A }, 2, false);
        float bcx = px - bw - r - fw * 0.008f;
        circle(bcx, by + hp * 0.55f, r, { 130, 150, 168, A });
        drawText(bcx, by + hp * 0.05f, "B", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
        float ax2 = bcx - r - fw * 0.03f;
        int sw = textWidth("Select", hp, false);
        drawText(ax2, by, "Select", hp, { 44, 77, 107, A }, 2, false);
        float acx = ax2 - sw - r - fw * 0.008f;
        circle(acx, by + hp * 0.55f, r, { 47, 143, 212, A });
        drawText(acx, by + hp * 0.05f, "A", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
    }

    // ------------------------------------------------- black cover (fade states)
    if (state == 0 || state == 1 || state == 4 || state == 11 || state == 12) {
        int timer = ctrl->values[0];
        int a = timer > 255 ? 255 : (timer < 0 ? 0 : timer);
        if (a > 0) { SDL_SetRenderDrawColor(R, 0, 0, 0, (Uint8)a); rect(0, 0, fw, fh); }
    }

    SDL_RenderSetLogicalSize(R, prevLW, prevLH);
    R = nullptr;
}

// =============================================================================
//  OPTIONS overlay  ("Options Menu C" controller at entity 62)
// -----------------------------------------------------------------------------
//  The stock console Options list (How to Play / Controls / Settings / Staff
//  Credits) is mostly inert on PC: those three callbacks are no-ops and the
//  working volume/spin-dash slider states are unreachable dead code. So instead
//  of skinning three dead buttons we present a real, working settings panel and
//  OWN the input (like the main mode-select): Music/SFX volume + Spin Dash style
//  are applied live to the engine (bgmVolume / sfxVolume / saveRAM[33..35]) and
//  persisted on exit; Staff Credits and Back reuse the stock transitions by
//  driving the controller's state machine (state 2 -> credits, state 11 -> exit).
//    saveRAM[33]=BGM(0..100)  [34]=SFX(0..100)  [35]=SpinDash(0=S2,1=CD)
// =============================================================================
// ---- tabbed settings model --------------------------------------------------
enum { OTAB_GAME, OTAB_SOUND, OTAB_GFX, OTAB_CTRL, OTAB_N };
enum { OK_SLIDER, OK_TOGGLE, OK_CHOICE, OK_ACTION, OK_KEY };

static int    s_optTab = OTAB_SOUND;
static int    s_optRow = 0;          // -1 = tab-bar focus
static bool   s_optWasOn = false;    // input side
static bool   s_optDrawOn = false;   // render side
static Uint32 s_optOpenAt = 0;
static float  s_optBarY = -1.0f, s_optTabX = -1.0f;
static int    s_optLastRow = -99;
static Uint32 s_optSelAt = 0;
static bool   s_optListening = false; // waiting to capture a key for a control
static int    s_optListenBtn = -1;
static bool   s_optDriving = false;   // true only while we deliberately run the stock credits/exit transition
static int    s_optRebindCd = 0;      // frames to ignore game input after a rebind (so binding a game key doesn't re-fire)

static const int   OPT_KEYBTN[8]  = { INPUT_UP, INPUT_DOWN, INPUT_LEFT, INPUT_RIGHT,
                                      INPUT_BUTTONA, INPUT_BUTTONB, INPUT_BUTTONC, INPUT_START };
static const char *OPT_KEYLBL[8]  = { "UP", "DOWN", "LEFT", "RIGHT", "JUMP  (A)", "JUMP  (B)", "JUMP  (C)", "PAUSE / START" };

static const char *optTabName(int tb)
{
    switch (tb) { case OTAB_GAME: return "GAME"; case OTAB_SOUND: return "SOUND"; case OTAB_GFX: return "GRAPHICS"; default: return "CONTROLS"; }
}
static int optRowCount(int tb)
{
    switch (tb) { case OTAB_GAME: return 4; case OTAB_SOUND: return 3; case OTAB_GFX: return 4; default: return 9; }
}
static const char *optItemLabel(int tb, int r)
{
    switch (tb) {
        case OTAB_GAME:  { static const char *l[4] = { "SPIN DASH STYLE", "SOUNDTRACK", "LANGUAGE", "STAFF CREDITS" }; return l[r]; }
        case OTAB_SOUND: { static const char *l[3] = { "MASTER VOLUME", "MUSIC VOLUME", "SOUND EFFECTS" }; return l[r]; }
        case OTAB_GFX:   { static const char *l[4] = { "FULLSCREEN", "V-SYNC", "SCALING FILTER", "WINDOW SCALE" }; return l[r]; }
        default:         return (r < 8) ? OPT_KEYLBL[r] : "RESET TO DEFAULT";
    }
}
static int optItemKind(int tb, int r)
{
    if (tb == OTAB_GAME)  return (r == 3) ? OK_ACTION : OK_CHOICE;
    if (tb == OTAB_SOUND) return OK_SLIDER;
    if (tb == OTAB_GFX)   return (r < 2) ? OK_TOGGLE : OK_CHOICE;
    return (r < 8) ? OK_KEY : OK_ACTION;
}
static const char *optLangName(int l)
{
    switch (l) { case 0: return "ENGLISH"; case 1: return "FRENCH"; case 2: return "ITALIAN"; case 3: return "GERMAN"; case 4: return "SPANISH"; case 5: return "JAPANESE"; default: return "ENGLISH"; }
}
static int optSliderVal(int tb, int r)   // 0..100, or -1 if not a slider
{
    if (tb == OTAB_SOUND) { int v = (r == 0) ? userMasterVolume : (r == 1) ? saveRAM[33] : saveRAM[34]; if (v < 0) v = 0; if (v > 100) v = 100; return v; }
    return -1;
}
static void optKeyText(int btn, char *out, int sz)
{
    const char *n = SDL_GetScancodeName((SDL_Scancode)inputDevice[btn].keyMappings);
    if (!n || !n[0]) { snprintf(out, sz, "---"); return; }
    int k = 0; for (; n[k] && k < sz - 1; ++k) out[k] = (n[k] >= 'a' && n[k] <= 'z') ? (char)(n[k] - 32) : n[k];
    out[k] = 0;
}
static void optValueText(int tb, int r, char *out, int sz)   // CHOICE / TOGGLE display
{
    if (tb == OTAB_GAME) {
        if (r == 0)      snprintf(out, sz, "%s", saveRAM[35] ? "SONIC CD" : "SONIC 2");
        else if (r == 1) snprintf(out, sz, "%s", GVar("Options.Soundtrack") ? "USA" : "JAPAN");
        else if (r == 2) snprintf(out, sz, "%s", optLangName(Engine.language));
        else out[0] = 0;
    } else if (tb == OTAB_GFX) {
        if (r == 0)      snprintf(out, sz, "%s", Engine.isFullScreen ? "ON" : "OFF");
        else if (r == 1) snprintf(out, sz, "%s", Engine.vsync ? "ON" : "OFF");
        else if (r == 2) snprintf(out, sz, "%s", Engine.scalingMode ? "SMOOTH" : "SHARP");
        else             snprintf(out, sz, "%dX", Engine.windowScale);
    } else out[0] = 0;
}
static const char *optItemDesc(int tb, int r)
{
    if (tb == OTAB_GAME) { static const char *d[4] = {
        "Sonic 2 (hold down, tap jump) or Sonic CD (hold down + jump) spin dash.",
        "Play the original Japanese soundtrack or the US soundtrack.",
        "Set the on-screen text language (applies on restart).",
        "Meet the team behind the game." }; return d[r]; }
    if (tb == OTAB_SOUND) { static const char *d[3] = {
        "Overall volume for all audio.", "Background-music volume.", "Sound-effects volume." }; return d[r]; }
    if (tb == OTAB_GFX) { static const char *d[4] = {
        "Switch between fullscreen and windowed.", "Sync to the display refresh to remove tearing.",
        "Crisp pixels (Sharp) or a smoothed image (Smooth).", "Windowed size multiplier." }; return d[r]; }
    return (r < 8) ? "Press A, then the key you want bound to this action." : "Restore the default keyboard controls.";
}

// ---- live-apply helpers (mirror the F8 SettingsOverlay) ---------------------
static void optApplyVSync()
{
#if RETRO_USING_SDL2 && !RETRO_USING_OPENGL && SDL_VERSION_ATLEAST(2, 0, 18)
    if (Engine.renderer) SDL_RenderSetVSync(Engine.renderer, Engine.vsync ? 1 : 0);
#endif
}
static void optApplyWindowScale()
{
#if RETRO_USING_SDL2
    if (!Engine.isFullScreen && Engine.window) {
        SDL_SetWindowSize(Engine.window, SCREEN_XSIZE_CONFIG * Engine.windowScale, SCREEN_YSIZE * Engine.windowScale);
        SDL_SetWindowPosition(Engine.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }
#endif
}
static void optAdjust(int tb, int r, int dir)
{
    if (tb == OTAB_GAME) {
        if (r == 0)      { saveRAM[35] = saveRAM[35] ? 0 : 1; SetGlobalVariableByName("Options.OriginalControls", saveRAM[35]); }
        else if (r == 1) { int s = GVar("Options.Soundtrack") ? 0 : 1; GVar("Options.Soundtrack") = s; saveRAM[38] = s;
                           StopMusic(); PlayMusic(s); } // apply immediately so the switch is audible (was a silent flag)
        else if (r == 2) { Engine.language = (Engine.language + dir + 6) % 6; }
    } else if (tb == OTAB_SOUND) {
        int *v = (r == 0) ? &userMasterVolume : (r == 1) ? &saveRAM[33] : &saveRAM[34];
        *v += dir * 10; if (*v < 0) *v = 0; if (*v > 100) *v = 100;
        bgmVolume = saveRAM[33]; sfxVolume = saveRAM[34];
    } else if (tb == OTAB_GFX) {
        if (r == 0)      { Engine.isFullScreen = !Engine.isFullScreen; SetFullScreen(Engine.isFullScreen); Engine.startFullScreen = Engine.isFullScreen; }
        else if (r == 1) { Engine.vsync = !Engine.vsync; optApplyVSync(); }
        else if (r == 2) { Engine.scalingMode = Engine.scalingMode ? 0 : 1; }
        else if (r == 3) { int s = Engine.windowScale + dir; if (s < 1) s = 1; if (s > 6) s = 6; Engine.windowScale = s; optApplyWindowScale(); }
    }
}
static void optResetControls()
{
    static const int def[8] = { 82, 81, 80, 79, 29, 27, 6, 40 }; // Up,Down,Left,Right,A,B,C,Start scancodes
    for (int i = 0; i < 8; ++i) inputDevice[OPT_KEYBTN[i]].keyMappings = def[i];
}
static void optPersistAll()
{
    bgmVolume = saveRAM[33]; sfxVolume = saveRAM[34];
    saveRAM[32] = 1;
    saveRAM[38] = GVar("Options.Soundtrack");
    SetGlobalVariableByName("Options.OriginalControls", saveRAM[35]);
    Engine.startFullScreen = Engine.isFullScreen;
    WriteSaveRAMData();
    WriteSettings();
}

// True only while the interactive settings list owns input (states 0/1).
bool OptionsActive()
{
    if (Engine.gameMode != ENGINE_MAINGAME) return false;
    if (!StrComp(currentStageFolder, (char *)"Menu")) return false;
    if (objectEntityList[LSM].type != TypeNameID("Options Menu C")) return false;
    int st = objectEntityList[LSM].state;
    // We own input across the browse states AND the "selected/loading" states
    // (2/3/8) so we can pin the stock controller back before it can ever fade or
    // mute on its own. State 11 (exit) is left to the stock on purpose.
    return (st >= 0 && st <= 3) || st == 8;
}
// True while the panel is drawn — includes the credits/exit fade transitions.
static bool OptionsShown()
{
    if (Engine.gameMode != ENGINE_MAINGAME) return false;
    if (!StrComp(currentStageFolder, (char *)"Menu")) return false;
    if (objectEntityList[LSM].type != TypeNameID("Options Menu C")) return false;
    int st = objectEntityList[LSM].state;
    return (st == 0 || st == 1 || st == 2 || st == 3 || st == 11);
}

// Per-frame input: tab / row navigation + live setting changes, then swallow the
// frame's input so the parked stock controller never also reacts.
void OptionsUpdate()
{
    Entity *ctrl = &objectEntityList[LSM];
    // Fill keyPress from the fresh per-frame input now (see Update(): ProcessStage
    // fills it only after us, and we clear the raw edge before ProcessStage runs).
    CheckKeyDown(&keyDown, 0xFF); CheckKeyPress(&keyPress, 0xFF);
    if (!s_optWasOn) { s_optWasOn = true; s_optTab = OTAB_SOUND; s_optRow = 0; s_optListening = false; s_optListenBtn = -1; s_optDriving = false; }

    // Credits/exit are the only times the stock controller is allowed to run its
    // own transition; let it proceed and resume control once it settles.
    if (s_optDriving) {
        if (ctrl->state == 1) s_optDriving = false;   // finished (or credits bounced back) — resume
        else { swallowMenuInput(); return; }
    }

    // The stock menu RE-READS raw input in ProcessStage (CheckKeyPress) after our
    // hook runs, so clearing keyPress can't stop it. Instead PIN the parked
    // controller every frame — force the CONTROLS state and a non-muting
    // selection — so its own A / Up / Down handling can never fade, mute or
    // transition. (Its draw is suppressed; we read its data, it obeys us.)
    ctrl->state     = 1;
    ctrl->values[0] = 0;
    ctrl->values[1] = 1; // slots 0 & 3 make the stock zero masterVolume; keep it on 1

    // while rebinding, ignore game input (the raw key is captured in OptionsCaptureKey)
    if (s_optListening) { swallowMenuInput(); return; }
    // brief cooldown after a rebind so the just-bound key (if it's a game button)
    // doesn't immediately re-open the rebind prompt
    if (s_optRebindCd > 0) { s_optRebindCd--; swallowMenuInput(); return; }

    int rc = optRowCount(s_optTab);

    if (s_optRow < 0) {                            // tab-bar focus
        if (keyPress.left)  { s_optTab = (s_optTab + OTAB_N - 1) % OTAB_N; PlaySfx(23, 0); }
        if (keyPress.right) { s_optTab = (s_optTab + 1) % OTAB_N;          PlaySfx(23, 0); }
        if (keyPress.down || keyPress.A || keyPress.start) { s_optRow = 0; PlaySfx(23, 0); }
    } else {                                       // setting-row focus
        if (keyPress.up)   { s_optRow = (s_optRow == 0) ? -1 : s_optRow - 1; PlaySfx(23, 0); }
        if (keyPress.down) { if (s_optRow < rc - 1) { s_optRow++; PlaySfx(23, 0); } }

        int kind = optItemKind(s_optTab, s_optRow);
        if ((keyPress.left || keyPress.right) && (kind == OK_SLIDER || kind == OK_TOGGLE || kind == OK_CHOICE)) {
            optAdjust(s_optTab, s_optRow, keyPress.right ? +1 : -1);
            PlaySfx(23, 0);
        }
        if (keyPress.A || keyPress.start) {
            if (s_optTab == OTAB_GAME && s_optRow == 3) {           // Staff Credits (reuse stock flow)
                PlaySfx(27, 0); optPersistAll();
                s_optDriving = true;                                // let the stock run its load-credits transition
                ctrl->values[1] = 3; ctrl->values[0] = 0; ctrl->state = 2;
                swallowMenuInput();
                return;
            } else if (kind == OK_KEY) {                            // begin rebind
                s_optListening = true; s_optListenBtn = OPT_KEYBTN[s_optRow]; PlaySfx(27, 0);
            } else if (s_optTab == OTAB_CTRL && s_optRow == 8) {    // reset defaults
                optResetControls(); PlaySfx(27, 0);
            }
        }
    }
    if (s_optRow >= optRowCount(s_optTab)) s_optRow = optRowCount(s_optTab) - 1;

    if (keyPress.B) {                              // save + exit (reuse stock exit)
        optPersistAll();
        s_optDriving = true;                       // let the stock run the exit-to-menu transition
        ctrl->values[0] = 248; ctrl->state = 11;
        PlaySfx(23, 0);
    }

    swallowMenuInput();
}

// Raw-key capture for control rebinding — hooked in the SDL_KEYDOWN event.
// Returns true when it consumes the key (i.e. we were listening).
bool OptionsCaptureKey(int scancode)
{
    if (!s_optListening) return false;
    if (scancode != SDL_SCANCODE_ESCAPE && s_optListenBtn >= 0 && s_optListenBtn < INPUT_BUTTONCOUNT) {
        int oldKey = inputDevice[s_optListenBtn].keyMappings;
        // No two actions may share a key: if another bound action already uses this
        // scancode, swap it onto the key we're vacating (so nothing ends up unbound).
        for (int i = 0; i < 8; ++i) {
            int b = OPT_KEYBTN[i];
            if (b != s_optListenBtn && inputDevice[b].keyMappings == scancode) {
                inputDevice[b].keyMappings = oldKey;
                break;
            }
        }
        inputDevice[s_optListenBtn].keyMappings = scancode;
    }
    s_optListening = false; s_optListenBtn = -1;
    s_optRebindCd = 6; // swallow the next few frames of game input
    return true;
}

void OptionsRender(SDL_Renderer *renderer)
{
    if (!OptionsShown()) { s_optWasOn = false; s_optDrawOn = false; s_optListening = false; return; }
    R = renderer;
    int W = 0, H = 0;
    SDL_GetRendererOutputSize(R, &W, &H);
    if (W <= 0 || H <= 0) return;
#if RETRO_USE_TTF
    if (s_cacheOwner != R) { clearCache(); s_cacheOwner = R; }
#endif
    int prevLW = 0, prevLH = 0;
    SDL_RenderGetLogicalSize(R, &prevLW, &prevLH);
    SDL_RenderSetLogicalSize(R, 0, 0);
    SDL_SetRenderDrawBlendMode(R, SDL_BLENDMODE_BLEND);

    const float fw = (float)W, fh = (float)H;
    const float t = SDL_GetTicks() / 1000.0f;
    const float now = (float)SDL_GetTicks();
    if (!s_optDrawOn) { s_optDrawOn = true; s_optOpenAt = (Uint32)now; s_optBarY = -1.0f; s_optTabX = -1.0f; s_optLastRow = -99; }

    Entity *ctrl = &objectEntityList[LSM];
    int st = ctrl->state, timer = ctrl->values[0];
    float tOpen = now - s_optOpenAt;
    float fade = clamp01(tOpen / 300.0f);
    float exitA = (st == 11) ? clamp01(timer / 248.0f) : 1.0f;
    Uint8 A = (Uint8)(fade * exitA * 255);

    s_uiBass += (audioMeterBass - s_uiBass) * 0.35f;
    s_uiPeak += (audioMeterPeak - s_uiPeak) * 0.35f;
    float idle = 0.10f + 0.06f * sinf(t * 1.7f);
    float bass = s_uiBass > idle ? s_uiBass : idle;
    float peak = s_uiPeak > idle ? s_uiPeak : idle;

    bool tabFocus = (s_optRow < 0);
    int rc = optRowCount(s_optTab);
    int selRowI = tabFocus ? 0 : (s_optRow >= rc ? rc - 1 : s_optRow);
    if (s_optRow != s_optLastRow) { s_optLastRow = s_optRow; s_optSelAt = (Uint32)now; }

    // ---- opaque frosted backdrop ----
    gradRect(0, 0, fw, fh, { 238, 243, 248, 255 }, { 194, 206, 219, 255 }, false);
    for (int i = 0; i < 4; ++i) {
        float dy = fmodf(t * (5.0f + i * 2.0f) + i * 300.0f, fh + 400.0f) - 200.0f;
        float y = fh - dy, s = fh * (0.16f + 0.06f * i) * (1.0f + 0.22f * bass), rot = t * 0.09f + i;
        float ax = fw * (0.6f - 0.13f * i);
        tri(ax, y, ax + cosf(rot) * s, y + sinf(rot) * s, ax + cosf(rot + 2.1f) * s, y + sinf(rot + 2.1f) * s,
            { 255, 255, 255, (Uint8)(20 + 16 * bass) });
    }
    gradRect(0, 0, fw, fh * 0.014f, { 46, 143, 212, 255 }, { 95, 200, 240, (Uint8)(180 + 75 * peak) }, true);

    // ---- header ----
    float hdrE = easeOutCubic(clamp01(tOpen / 420.0f));
    int hpx = (int)(fh * 0.050f);
    float hx = fw * 0.06f, hy = fh * 0.052f - (1.0f - hdrE) * fh * 0.03f;
    Uint8 hA = (Uint8)(A * hdrE);
    drawText(hx, hy, "SONIC CD", hpx, { 18, 58, 92, hA }, 0, true);
    int hw2 = textWidth("SONIC CD", hpx, true);
    drawText(hx + hw2 + fh * 0.03f, hy + hpx * 0.22f, "OPTIONS", (int)(fh * 0.028f), { 90, 119, 148, hA }, 0, false);
    gradRect(hx, hy + hpx * 1.25f, (fw * 0.24f) * hdrE, fh * 0.004f, { 46, 143, 212, hA }, { 120, 210, 245, 0 }, true);

    // ---- tab bar ----
    float tabY = fh * 0.155f, tabH = fh * 0.058f;
    float tbX = fw * 0.12f, tbW = fw * 0.76f, tw = tbW / OTAB_N;
    float actTX = tbX + s_optTab * tw;
    if (s_optTabX < 0) s_optTabX = actTX;
    s_optTabX += (actTX - s_optTabX) * 0.5f;
    // active-tab pill (slides) + focus glow when the tab bar is selected
    if (tabFocus) {
        float pf = 0.55f + 0.45f * sinf(now * 0.006f);
        roundRect(s_optTabX + tw * 0.02f - fh * 0.006f, tabY - fh * 0.006f, tw * 0.96f + fh * 0.012f, tabH + fh * 0.012f,
                  tabH * 0.34f, { 66, 158, 224, (Uint8)(110 * pf * exitA) });
    }
    roundRect(s_optTabX + tw * 0.05f, tabY, tw * 0.90f, tabH, tabH * 0.30f, { 47, 143, 212, A });
    glossTop(s_optTabX + tw * 0.05f, tabY, tw * 0.90f, tabH * 0.5f, (Uint8)(70 * exitA));
    for (int tb = 0; tb < OTAB_N; ++tb) {
        bool active = (tb == s_optTab);
        SDL_Color tc = active ? SDL_Color{ 255, 255, 255, A } : SDL_Color{ 112, 134, 162, (Uint8)(A * 0.9f) };
        drawTextFit(tbX + tb * tw + tw * 0.5f, tabY + tabH * 0.5f - fh * 0.018f, optTabName(tb), (int)(fh * 0.030f), tc, tw * 0.82f, active);
    }
    SDL_SetRenderDrawColor(R, 150, 172, 196, (Uint8)(A * 0.5f));
    rect(tbX, tabY + tabH + fh * 0.010f, tbW, fh * 0.0025f);
    if (tabFocus) { // switch-tab chevrons
        float cy = tabY + tabH * 0.5f, cs = tabH * 0.24f, bob = sinf(t * 4.0f) * fh * 0.004f;
        tri(tbX - fw * 0.018f - bob, cy - cs, tbX - fw * 0.018f - bob, cy + cs, tbX - fw * 0.018f - cs - bob, cy, { 90, 120, 150, A });
        float rxc = tbX + tbW + fw * 0.018f + bob;
        tri(rxc, cy - cs, rxc, cy + cs, rxc + cs, cy, { 90, 120, 150, A });
    }

    // ---- settings list (adaptive row height) ----
    float colX = fw * 0.14f, colW = fw * 0.72f;
    float listTop = fh * 0.285f, listBot = fh * 0.83f;
    float gap = (rc > 5) ? fh * 0.010f : fh * 0.020f;
    float slotH = (listBot - listTop - gap * (rc - 1)) / rc;
    if (slotH > fh * 0.105f) slotH = fh * 0.105f;
    float listH = slotH * rc + gap * (rc - 1);
    float y0 = listTop + ((listBot - listTop) - listH) * 0.5f;
    const float cr = fh * 0.016f;

    float targetY = y0 + selRowI * (slotH + gap);
    if (s_optBarY < 0) s_optBarY = targetY;
    s_optBarY += (targetY - s_optBarY) * 0.5f;

    // frosted backgrounds for unselected rows
    for (int i = 0; i < rc; ++i) {
        if (i == selRowI && !tabFocus) continue;
        float y = y0 + i * (slotH + gap);
        float en = easeOutCubic(clamp01((tOpen - 60.0f - i * 40.0f) / 340.0f));
        roundRect(colX, y + slotH * 0.10f, colW, slotH, cr, { 30, 60, 100, (Uint8)(22 * en * exitA) });
        roundRect(colX, y, colW, slotH, cr, { 255, 255, 255, (Uint8)(150 * en * exitA) });
        glossTop(colX, y, colW, slotH * 0.5f, (Uint8)(46 * en * exitA));
    }
    // selected-row highlight (hidden while the tab bar is focused)
    if (!tabFocus) {
        float y = s_optBarY, h = slotH;
        roundRect(colX - fw * 0.008f, y - fh * 0.009f, colW + fw * 0.016f, h + fh * 0.018f, cr + fh * 0.004f,
                  { 66, 158, 224, (Uint8)(70 * bass * exitA) });
        roundRect(colX, y + h * 0.10f, colW, h, cr, { 16, 52, 98, (Uint8)(64 * exitA) });
        roundRect(colX, y, colW, h, cr, { 47, 143, 212, A });
        gradRect(colX + cr, y, colW - cr * 2.0f, h, { 47, 143, 212, 0 }, { 96, 194, 238, (Uint8)((150 + 90 * peak) * exitA) }, true);
        glossTop(colX, y, colW, h * 0.5f, (Uint8)(70 * exitA));
        SDL_SetRenderDrawColor(R, 200, 236, 255, A);
        rect(colX + colW * 0.010f, y + h * 0.18f, colW * 0.005f, h * 0.64f);
    }

    // row content
    for (int i = 0; i < rc; ++i) {
        bool selRow = (i == selRowI && !tabFocus);
        float y = y0 + i * (slotH + gap), h = slotH;
        float en = easeOutCubic(clamp01((tOpen - 60.0f - i * 40.0f) / 340.0f));
        Uint8 rA = (Uint8)(A * en);
        int kind = optItemKind(s_optTab, i);
        SDL_Color primary = selRow ? SDL_Color{ 255, 255, 255, rA } : SDL_Color{ 30, 62, 96, rA };
        SDL_Color subtle  = selRow ? SDL_Color{ 216, 237, 251, rA } : SDL_Color{ 108, 132, 160, rA };

        drawText(colX + h * 0.42f, y + h * 0.5f - h * 0.19f, optItemLabel(s_optTab, i), (int)(h * 0.30f), primary, 0, selRow);

        float wx = colX + colW * 0.44f, ww = colW * 0.52f, wcy = y + h * 0.5f;
        if (kind == OK_SLIDER) {
            int val = optSliderVal(s_optTab, i);
            float tkw = ww * 0.74f, tx = wx, th = h * 0.13f;
            SDL_Color trk = selRow ? SDL_Color{ 255, 255, 255, (Uint8)(rA * 0.35f) } : SDL_Color{ 158, 178, 200, (Uint8)(rA * 0.7f) };
            roundRect(tx, wcy - th * 0.5f, tkw, th, th * 0.5f, trk);
            float fillw = tkw * (val / 100.0f);
            SDL_Color fillc = selRow ? SDL_Color{ 255, 255, 255, rA } : SDL_Color{ 47, 143, 212, rA };
            if (fillw > th) roundRect(tx, wcy - th * 0.5f, fillw, th, th * 0.5f, fillc);
            diamond(tx + fillw, wcy, h * 0.15f, selRow ? SDL_Color{ 255, 255, 255, rA } : SDL_Color{ 39, 118, 180, rA });
            char vb[8]; snprintf(vb, sizeof(vb), "%d%%", val);
            drawText(tx + tkw + ww * 0.07f, wcy - h * 0.16f, vb, (int)(h * 0.28f), primary, 0, selRow);
        } else if (kind == OK_TOGGLE) {
            char v[8]; optValueText(s_optTab, i, v, sizeof(v));
            bool on = (v[1] == 'N'); // "ON"
            float swW = ww * 0.24f, swH = h * 0.34f, sx = wx, sy = wcy - swH * 0.5f;
            SDL_Color trk = on ? (selRow ? SDL_Color{ 255, 255, 255, rA } : SDL_Color{ 47, 143, 212, rA })
                               : (selRow ? SDL_Color{ 255, 255, 255, (Uint8)(rA * 0.3f) } : SDL_Color{ 190, 204, 220, rA });
            roundRect(sx, sy, swW, swH, swH * 0.5f, trk);
            float kx = on ? sx + swW - swH * 0.5f : sx + swH * 0.5f;
            circle(kx, wcy, swH * 0.4f, on ? (selRow ? SDL_Color{ 47, 130, 200, rA } : SDL_Color{ 255, 255, 255, rA }) : SDL_Color{ 245, 248, 251, rA });
            drawText(sx + swW + ww * 0.06f, wcy - h * 0.16f, on ? "ON" : "OFF", (int)(h * 0.28f), primary, 0, selRow);
        } else if (kind == OK_CHOICE) {
            char v[32]; optValueText(s_optTab, i, v, sizeof(v));
            float vcx = wx + ww * 0.42f;
            drawTextFit(vcx, wcy - h * 0.17f, v, (int)(h * 0.30f), primary, ww * 0.5f, selRow);
            if (selRow) {
                float chs = h * 0.13f, bob = sinf(t * 4.0f) * h * 0.03f;
                float lxc = wx + ww * 0.02f - bob;
                tri(lxc, wcy - chs, lxc, wcy + chs, lxc - chs, wcy, { 223, 243, 255, rA });
                float rxc = wx + ww * 0.82f + bob;
                tri(rxc, wcy - chs, rxc, wcy + chs, rxc + chs, wcy, { 223, 243, 255, rA });
            }
        } else if (kind == OK_KEY) {
            bool listening = (s_optListening && s_optListenBtn == OPT_KEYBTN[i]);
            float bw2 = ww * 0.5f, bh = h * 0.56f, bx = wx + ww * 0.24f, byk = wcy - bh * 0.5f;
            if (listening) {
                float pf = 0.5f + 0.5f * sinf(now * 0.02f);
                roundRect(bx, byk, bw2, bh, bh * 0.28f, { 232, 168, 60, (Uint8)(rA * (0.6f + 0.4f * pf)) });
                drawTextFit(bx + bw2 * 0.5f, wcy - h * 0.15f, "PRESS A KEY", (int)(h * 0.24f), { 255, 255, 255, rA }, bw2 * 0.86f, true);
            } else {
                roundRect(bx, byk, bw2, bh, bh * 0.28f, selRow ? SDL_Color{ 255, 255, 255, rA } : SDL_Color{ 224, 232, 240, rA });
                char kb[32]; optKeyText(OPT_KEYBTN[i], kb, sizeof(kb));
                drawTextFit(bx + bw2 * 0.5f, wcy - h * 0.15f, kb, (int)(h * 0.26f), selRow ? SDL_Color{ 47, 130, 200, rA } : SDL_Color{ 50, 84, 118, rA }, bw2 * 0.86f, true);
            }
        } else { // OK_ACTION (Staff Credits / Reset)
            const char *lbl = (s_optTab == OTAB_CTRL) ? "RESET" : "VIEW";
            float bw2 = ww * 0.5f, bh = h * 0.56f, bx = wx + ww * 0.28f, byk = wcy - bh * 0.5f;
            roundRect(bx, byk, bw2, bh, bh * 0.28f, selRow ? SDL_Color{ 255, 255, 255, rA } : SDL_Color{ 224, 232, 240, rA });
            SDL_Color vc = selRow ? SDL_Color{ 47, 130, 200, rA } : SDL_Color{ 60, 92, 126, rA };
            drawText(bx + bw2 * 0.44f, wcy - h * 0.15f, lbl, (int)(h * 0.26f), vc, 1, true);
            if (s_optTab != OTAB_CTRL)
                tri(bx + bw2 * 0.82f, wcy - h * 0.12f, bx + bw2 * 0.82f, wcy + h * 0.12f, bx + bw2 * 0.92f, wcy, vc);
        }
    }

    // ---- description ----
    drawText(fw * 0.14f, fh * 0.865f, tabFocus ? "Left / Right to switch tabs, Down to enter." : optItemDesc(s_optTab, selRowI),
             (int)(fh * 0.028f), { 74, 103, 132, A }, 0, false);

    // ---- hints: Adjust / Select / Back ----
    {
        float by = fh * 0.915f, r = fh * 0.026f, rx = fw * 0.86f;
        int hp = (int)(fh * 0.030f);
        int bw = textWidth("Back", hp, false);
        drawText(rx, by, "Back", hp, { 44, 77, 107, A }, 2, false);
        float bcx = rx - bw - r - fw * 0.008f;
        circle(bcx, by + hp * 0.55f, r, { 130, 150, 168, A });
        drawText(bcx, by + hp * 0.05f, "B", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
        float ax2 = bcx - r - fw * 0.03f;
        int sw2 = textWidth("Select", hp, false);
        drawText(ax2, by, "Select", hp, { 44, 77, 107, A }, 2, false);
        float acx = ax2 - sw2 - r - fw * 0.008f;
        circle(acx, by + hp * 0.55f, r, { 47, 143, 212, A });
        drawText(acx, by + hp * 0.05f, "A", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
        float adj = acx - r - fw * 0.05f;
        int aw = textWidth("Adjust", hp, false);
        drawText(adj, by, "Adjust", hp, { 44, 77, 107, A }, 2, false);
        float cxr = adj - aw - fw * 0.012f;
        tri(cxr, by + hp * 0.55f - r * 0.7f, cxr, by + hp * 0.55f + r * 0.7f, cxr - r * 0.8f, by + hp * 0.55f, { 90, 120, 150, A });
        float cxl = cxr - r * 1.1f;
        tri(cxl, by + hp * 0.55f - r * 0.7f, cxl, by + hp * 0.55f + r * 0.7f, cxl + r * 0.8f, by + hp * 0.55f, { 90, 120, 150, A });
    }

    // ---- rebind prompt scrim ----
    if (s_optListening) {
        SDL_SetRenderDrawColor(R, 8, 20, 38, (Uint8)(120 * exitA));
        rect(0, 0, fw, fh);
        float bw = fw * 0.42f, bh = fh * 0.20f, bx = (fw - bw) * 0.5f, byy = (fh - bh) * 0.5f;
        roundRect(bx, byy, bw, bh, fh * 0.03f, { 249, 251, 253, A });
        roundRect(bx, byy, bw, bh * 0.16f, fh * 0.03f, { 232, 168, 60, A });
        drawText(fw * 0.5f, byy + bh * 0.42f, "PRESS A KEY", (int)(fh * 0.05f), { 30, 62, 96, A }, 1, true);
        drawText(fw * 0.5f, byy + bh * 0.68f, "ESC to cancel", (int)(fh * 0.028f), { 120, 140, 164, A }, 1, false);
    }

    // ---- black cover for the credits load fade (state 3) ----
    if (st == 3) {
        int a = timer > 255 ? 255 : (timer < 0 ? 0 : timer);
        if (a > 0) { SDL_SetRenderDrawColor(R, 0, 0, 0, (Uint8)a); rect(0, 0, fw, fh); }
    }

    SDL_RenderSetLogicalSize(R, prevLW, prevLH);
    R = nullptr;
}

// =============================================================================
//  SOUNDTRACK overlay  ("Soundtrack Menu" controller at entity 62)
// -----------------------------------------------------------------------------
//  Choose the game's soundtrack. Stock is a JP/US selector: values[1] is the
//  highlighted OST, GVar("Options.Soundtrack") the active one. Visual overlay
//  only — the stock object drives Left/Right, confirm and exit. The featured CD
//  spins and does an engaging swap (spin burst + colour wash + note burst +
//  scale bounce) each time the highlight changes.
//
//  >>> ADDING A SOUNDTRACK (e.g. the planned South American OST): add one entry
//      to OST[] below (name / code / subtitle / blurb / accent). OST_COUNT then
//      updates automatically. Also widen the wrap in Menu/SoundMenu.txt
//      (OST_SELECTION: raise the "> OST_US" / "< OST_JP" bounds to the new max)
//      and register its music track. The overlay handles any count already.
// =============================================================================
struct OstDef { const char *name; const char *code; const char *sub; const char *desc; SDL_Color accent; };
static const OstDef OST[] = {
    { "JAPANESE", "JP", "1993  \xC2\xB7  JP / EU SOUNDTRACK", "Naofumi Hataya & Masafumi Ogata's original score.", { 216, 72, 92, 255 } },
    { "AMERICAN", "US", "1995  \xC2\xB7  US SOUNDTRACK",      "Spencer Nilsen's atmospheric US soundtrack.",        {  52, 120, 212, 255 } },
    // { "SOUTH AMERICAN", "SA", "\xC2\xB7  SA SOUNDTRACK", "The new South American soundtrack.", { 54, 178, 110, 255 } },
};
static const int OST_COUNT = (int)(sizeof(OST) / sizeof(OST[0]));

static bool     s_stWasOn = false;
static Uint32   s_stOpenAt = 0;
static int      s_stLastSel = -99;
static Uint32   s_stSelAt = 0;
static float    s_stSpin = 0.0f, s_stBurst = 0.0f;
static SDL_Color s_stCol = { 52, 120, 212, 255 };

// a small music-note glyph
static void musicNote(float cx, float cy, float s, SDL_Color c)
{
    line(cx + s * 0.5f, cy - s * 0.9f, cx + s * 0.5f, cy + s * 0.5f, s * 0.18f, c);
    circle(cx + s * 0.18f, cy + s * 0.55f, s * 0.36f, c);
    SDL_SetRenderDrawColor(R, c.r, c.g, c.b, c.a);
    rect(cx + s * 0.4f, cy - s * 1.02f, s * 0.55f, s * 0.2f);
}
// a shiny CD: silver body, rotating iridescent sheen, coloured label + code, hole
static void drawCD(float cx, float cy, float r, SDL_Color col, const char *code, float spin, Uint8 a)
{
    circle(cx, cy, r, { 232, 238, 246, a });                                   // body
    static const SDL_Color hue[3] = { { 120, 220, 245, 0 }, { 245, 130, 210, 0 }, { 250, 214, 120, 0 } };
    for (int k = 0; k < 3; ++k) {
        SDL_Color h = hue[k]; h.a = (Uint8)(a * 0.5f);
        float b = spin + k * 2.094f;
        ring(cx, cy, r * 0.97f, r * 0.44f, h, 44, b, b + 1.15f);
    }
    ring(cx, cy, r * 0.85f, r * 0.845f, { 176, 194, 214, (Uint8)(a * 0.4f) });  // grooves
    ring(cx, cy, r * 0.66f, r * 0.655f, { 176, 194, 214, (Uint8)(a * 0.35f) });
    circle(cx, cy, r * 0.46f, col);                                            // colour label
    ring(cx, cy, r * 0.46f, r * 0.42f, { 255, 255, 255, (Uint8)(a * 0.5f) });
    drawText(cx, cy - r * 0.22f, code, (int)(r * 0.44f), { 255, 255, 255, a }, 1, true);
    circle(cx, cy, r * 0.11f, { 238, 243, 248, a });                           // centre hole
    ring(cx, cy, r * 0.11f, r * 0.075f, { 150, 170, 190, (Uint8)(a * 0.6f) });
}

bool OstActive()
{
    if (Engine.gameMode != ENGINE_MAINGAME) return false;
    if (!StrComp(currentStageFolder, (char *)"Menu")) return false;
    if (objectEntityList[LSM].type != TypeNameID("Soundtrack Menu")) return false;
    int st = objectEntityList[LSM].state;
    return (st == 0 || st == 1 || st == 2 || st == 3 || st == 4);
}

void OstRender(SDL_Renderer *renderer)
{
    if (!OstActive()) { s_stWasOn = false; return; }
    R = renderer;
    int W = 0, H = 0;
    SDL_GetRendererOutputSize(R, &W, &H);
    if (W <= 0 || H <= 0) return;
#if RETRO_USE_TTF
    if (s_cacheOwner != R) { clearCache(); s_cacheOwner = R; }
#endif
    int prevLW = 0, prevLH = 0;
    SDL_RenderGetLogicalSize(R, &prevLW, &prevLH);
    SDL_RenderSetLogicalSize(R, 0, 0);
    SDL_SetRenderDrawBlendMode(R, SDL_BLENDMODE_BLEND);

    const float fw = (float)W, fh = (float)H;
    const float t = SDL_GetTicks() / 1000.0f;
    const float now = (float)SDL_GetTicks();

    Entity *ctrl = &objectEntityList[LSM];
    int st = ctrl->state;
    int sel = ctrl->values[1]; if (sel < 0) sel = 0; if (sel >= OST_COUNT) sel = OST_COUNT - 1;
    int active = GVar("Options.Soundtrack"); if (active < 0) active = 0; if (active >= OST_COUNT) active = OST_COUNT - 1;

    if (!s_stWasOn) { s_stWasOn = true; s_stOpenAt = (Uint32)now; s_stLastSel = sel; s_stSelAt = (Uint32)now; s_stCol = OST[sel].accent; }
    if (sel != s_stLastSel) { s_stLastSel = sel; s_stSelAt = (Uint32)now; s_stBurst = 1.0f; } // engaging swap trigger
    float tOpen = now - s_stOpenAt, tSwap = now - s_stSelAt;

    float openFade = clamp01(tOpen / 300.0f);
    float exitA = (st == 3 || st == 4) ? clamp01(ctrl->values[0] / 248.0f) : 1.0f;
    Uint8 A = (Uint8)(openFade * exitA * 255);

    s_uiBass += (audioMeterBass - s_uiBass) * 0.35f;
    s_uiPeak += (audioMeterPeak - s_uiPeak) * 0.35f;
    float idle = 0.10f + 0.06f * sinf(t * 1.7f);
    float bass = s_uiBass > idle ? s_uiBass : idle;
    float peak = s_uiPeak > idle ? s_uiPeak : idle;

    // spin (audio-reactive) + swap burst; morph the accent colour toward the pick
    s_stBurst *= 0.90f;
    s_stSpin += (0.4f + 1.6f * peak + 7.0f * s_stBurst) * 0.016f;
    SDL_Color tgt = OST[sel].accent;
    s_stCol.r += (int)((tgt.r - s_stCol.r) * 0.14f);
    s_stCol.g += (int)((tgt.g - s_stCol.g) * 0.14f);
    s_stCol.b += (int)((tgt.b - s_stCol.b) * 0.14f);

    // ---- backdrop: frosted, ambient-tinted by the current OST colour ----
    gradRect(0, 0, fw, fh, { 238, 243, 248, 255 }, { 196, 208, 220, 255 }, false);
    { // radial glow behind the disc in the OST colour
        float gcx = fw * 0.5f, gcy = fh * 0.4f;
        for (int k = 6; k >= 1; --k) {
            float rr = fh * (0.12f + k * 0.07f) * (1.0f + 0.15f * bass);
            SDL_Color g = { s_stCol.r, s_stCol.g, s_stCol.b, (Uint8)(9 * (0.5f + 0.5f * bass) * exitA) };
            circle(gcx, gcy, rr, g);
        }
    }
    for (int i = 0; i < 5; ++i) {
        float dy = fmodf(t * (5.0f + i * 2.0f) + i * 260.0f, fh + 400.0f) - 200.0f;
        float y = fh - dy, s = fh * (0.13f + 0.05f * i) * (1.0f + 0.26f * bass), rot = t * 0.1f + i;
        float ax = fw * (0.1f + 0.2f * i);
        SDL_Color tc = { s_stCol.r, s_stCol.g, s_stCol.b, (Uint8)(16 + 20 * bass) };
        tri(ax, y, ax + cosf(rot) * s, y + sinf(rot) * s, ax + cosf(rot + 2.1f) * s, y + sinf(rot + 2.1f) * s, tc);
    }
    gradRect(0, 0, fw, fh * 0.014f, s_stCol, { 150, 210, 245, (Uint8)(180 + 75 * peak) }, true);

    // ---- header ----
    float hdrE = easeOutCubic(clamp01(tOpen / 420.0f));
    int hpx = (int)(fh * 0.050f);
    float hx = fw * 0.06f, hy = fh * 0.052f - (1.0f - hdrE) * fh * 0.03f;
    Uint8 hA = (Uint8)(A * hdrE);
    drawText(hx, hy, "SONIC CD", hpx, { 18, 58, 92, hA }, 0, true);
    int hw2 = textWidth("SONIC CD", hpx, true);
    drawText(hx + hw2 + fh * 0.03f, hy + hpx * 0.22f, "SOUNDTRACK", (int)(fh * 0.028f), { 90, 119, 148, hA }, 0, false);
    gradRect(hx, hy + hpx * 1.25f, (fw * 0.24f) * hdrE, fh * 0.004f, s_stCol, { 150, 210, 245, 0 }, true);

    // ---- featured CD (scale bounce on swap) ----
    float dcx = fw * 0.5f, dcy = fh * 0.40f, dr = fh * 0.185f;
    float pop = 1.0f + 0.14f * (1.0f - easeOutCubic(clamp01(tSwap / 360.0f))) + 0.03f * bass;
    // beat pulse ring
    {
        SDL_Color pr = { s_stCol.r, s_stCol.g, s_stCol.b, (Uint8)(60 * bass * exitA) };
        ring(dcx, dcy, dr * (1.18f + 0.5f * bass), dr * (1.12f + 0.5f * bass), pr);
    }
    // swap ripple
    if (tSwap < 560.0f) {
        float rt = clamp01(tSwap / 560.0f);
        SDL_Color rc = { s_stCol.r, s_stCol.g, s_stCol.b, (Uint8)(150 * (1.0f - rt) * exitA) };
        float rr = dr * (1.0f + rt * 1.7f);
        ring(dcx, dcy, rr, rr * 0.96f, rc, 48);
    }
    // shadow + disc
    circle(dcx, dcy + dr * 0.12f, dr * pop, { 20, 46, 82, (Uint8)(50 * exitA) });
    drawCD(dcx, dcy, dr * pop, s_stCol, OST[sel].code, s_stSpin, A);
    // note burst on swap
    if (tSwap < 620.0f) {
        float rt = clamp01(tSwap / 620.0f);
        for (int k = 0; k < 7; ++k) {
            float a = k / 7.0f * TAU + s_stSpin * 0.2f;
            float rr = dr * (1.1f + rt * 1.9f);
            float nx = dcx + cosf(a) * rr, ny = dcy + sinf(a) * rr;
            SDL_Color nc = { s_stCol.r, s_stCol.g, s_stCol.b, (Uint8)(200 * (1.0f - rt) * exitA) };
            musicNote(nx, ny, dr * 0.12f * (1.0f - 0.4f * rt), nc);
        }
    }

    // ---- OST name / subtitle / description (slide + fade on swap) ----
    float nmE = easeOutCubic(clamp01(tSwap / 300.0f));
    Uint8 nmA = (Uint8)(A * (0.35f + 0.65f * nmE));
    float ny = fh * 0.635f + (1.0f - nmE) * fh * 0.02f;
    drawText(dcx, ny, OST[sel].name, (int)(fh * 0.052f), { 22, 60, 96, nmA }, 1, true);
    drawText(dcx, ny + fh * 0.062f, OST[sel].sub, (int)(fh * 0.026f), { s_stCol.r, s_stCol.g, s_stCol.b, nmA }, 1, true);

    // ---- selector chips (all OSTs; active = NOW PLAYING) ----
    {
        float chW = fw * 0.16f, chH = fh * 0.052f, chGap = fw * 0.02f;
        float totW = OST_COUNT * chW + (OST_COUNT - 1) * chGap;
        float cx0 = fw * 0.5f - totW * 0.5f, cy = fh * 0.775f;
        for (int i = 0; i < OST_COUNT; ++i) {
            float x = cx0 + i * (chW + chGap);
            bool selc = (i == sel), act = (i == active);
            SDL_Color ac = OST[i].accent;
            if (selc) {
                roundRect(x - fw * 0.004f, cy - fh * 0.005f, chW + fw * 0.008f, chH + fh * 0.010f, chH * 0.36f, { ac.r, ac.g, ac.b, (Uint8)(70 * exitA) });
                roundRect(x, cy, chW, chH, chH * 0.32f, { ac.r, ac.g, ac.b, A });
                glossTop(x, cy, chW, chH * 0.5f, (Uint8)(70 * exitA));
                drawTextFit(x + chW * 0.5f, cy + chH * 0.5f - fh * 0.017f, OST[i].name, (int)(fh * 0.026f), { 255, 255, 255, A }, chW * 0.84f, true);
            } else {
                roundRect(x, cy, chW, chH, chH * 0.32f, { 255, 255, 255, (Uint8)(160 * exitA) });
                drawTextFit(x + chW * 0.5f, cy + chH * 0.5f - fh * 0.017f, OST[i].name, (int)(fh * 0.026f), { 96, 120, 150, A }, chW * 0.84f, false);
            }
            if (act) { // NOW PLAYING badge above the chip
                float bx = x + chW * 0.5f;
                musicNote(bx - fw * 0.052f, cy - fh * 0.028f, fh * 0.016f, { ac.r, ac.g, ac.b, A });
                drawText(bx + fw * 0.006f, cy - fh * 0.040f, "NOW PLAYING", (int)(fh * 0.020f), { ac.r, ac.g, ac.b, A }, 1, true);
            }
        }
    }

    // ---- description ----
    drawText(fw * 0.5f, fh * 0.855f, OST[sel].desc, (int)(fh * 0.028f), { 74, 103, 132, A }, 1, false);

    // ---- confirm flourish (state 2) ----
    if (st == 2) {
        float pf = 0.5f + 0.5f * sinf(now * 0.03f);
        SDL_Color rc = { s_stCol.r, s_stCol.g, s_stCol.b, (Uint8)(180 * pf * exitA) };
        ring(dcx, dcy, dr * 1.28f, dr * 1.2f, rc);
        drawText(dcx, fh * 0.30f, "SOUNDTRACK SET", (int)(fh * 0.03f), { s_stCol.r, s_stCol.g, s_stCol.b, A }, 1, true);
    }

    // ---- hints: Browse / Set / Back ----
    {
        float by = fh * 0.925f, r = fh * 0.026f, rx = fw * 0.88f;
        int hp = (int)(fh * 0.030f);
        int bw = textWidth("Back", hp, false);
        drawText(rx, by, "Back", hp, { 44, 77, 107, A }, 2, false);
        float bcx = rx - bw - r - fw * 0.008f;
        circle(bcx, by + hp * 0.55f, r, { 130, 150, 168, A });
        drawText(bcx, by + hp * 0.05f, "B", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
        float ax2 = bcx - r - fw * 0.03f;
        int sw2 = textWidth("Set", hp, false);
        drawText(ax2, by, "Set", hp, { 44, 77, 107, A }, 2, false);
        float acx = ax2 - sw2 - r - fw * 0.008f;
        circle(acx, by + hp * 0.55f, r, s_stCol);
        drawText(acx, by + hp * 0.05f, "A", (int)(hp * 0.9f), { 255, 255, 255, A }, 1, true);
        float adj = acx - r - fw * 0.05f;
        int aw = textWidth("Browse", hp, false);
        drawText(adj, by, "Browse", hp, { 44, 77, 107, A }, 2, false);
        float cxr = adj - aw - fw * 0.012f;
        tri(cxr, by + hp * 0.55f - r * 0.7f, cxr, by + hp * 0.55f + r * 0.7f, cxr - r * 0.8f, by + hp * 0.55f, { 90, 120, 150, A });
        float cxl = cxr - r * 1.1f;
        tri(cxl, by + hp * 0.55f - r * 0.7f, cxl, by + hp * 0.55f + r * 0.7f, cxl + r * 0.8f, by + hp * 0.55f, { 90, 120, 150, A });
    }

    SDL_RenderSetLogicalSize(R, prevLW, prevLH);
    R = nullptr;
}

// =============================================================================
//  PAUSE overlay  ("Pause Menu" controller at entity 9, during gameplay)
// -----------------------------------------------------------------------------
//  A premium in-game pause menu drawn over the frozen (dimmed) gameplay. This is
//  a VISUAL overlay only: the stock Pause Menu object keeps running its state
//  machine + input from ObjectMain (states 0-6), we just read its selection
//  (values[1]) and state and render hi-res, then suppress its low-res draw.
//  Items map to values[1]: 0 Continue, 1 Restart (disabled when values[6]==1 —
//  low lives / special), 2 Exit, 3 Dev Menu (dev flag) or trial store.
// =============================================================================
static const int PAUSE_ENT   = 9;
static bool      s_pauseWasOn = false;
static Uint32    s_pauseOpenAt = 0;
static int       s_pauseLastState = -1;
static Uint32    s_pauseExitAt = 0;
static int       s_pauseLastSel = -99;
static Uint32    s_pauseSelAt = 0;
static float     s_pauseCurSel = 0.0f;   // smoothed selection index (for the moving highlight)

// --- angled-shape + icon helpers for the pause overlay -----------------------
static void pQuad(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, SDL_Color c)
{
    tri(ax, ay, bx, by, cx, cy, c);
    tri(ax, ay, cx, cy, dx, dy, c);
}
// parallelogram: fixed left x `lx`, top `top`, bottom `bot`, right edge (rt@top -> rb@bot), inset by d
static void pPara(float lx, float top, float rt, float rb, float bot, float d, SDL_Color c)
{
    pQuad(lx, top + d, rt - d, top + d, rb - d, bot - d, lx, bot - d, c);
}
static void pIconPlay(float cx, float cy, float s, SDL_Color c)
{
    tri(cx - s * 0.38f, cy - s * 0.52f, cx - s * 0.38f, cy + s * 0.52f, cx + s * 0.52f, cy, c);
}
static void pIconRestart(float cx, float cy, float s, SDL_Color c)
{
    ring(cx, cy, s * 0.60f, s * 0.40f, c, 30, 1.05f, 1.05f + 5.05f); // ~open circle
    float ae = 1.05f;                                               // arrowhead at the gap
    float ex = cx + cosf(ae) * s * 0.50f, ey = cy + sinf(ae) * s * 0.50f;
    tri(ex + s * 0.02f, ey - s * 0.30f, ex + s * 0.34f, ey + s * 0.02f, ex - s * 0.10f, ey + s * 0.06f, c);
}
static void pIconDoor(float cx, float cy, float s, SDL_Color c)
{
    roundRect(cx - s * 0.72f, cy - s * 0.62f, s * 0.24f, s * 1.24f, s * 0.07f, c);      // jamb
    roundRect(cx - s * 0.22f, cy - s * 0.10f, s * 0.62f, s * 0.20f, s * 0.05f, c);      // shaft
    tri(cx + s * 0.34f, cy - s * 0.34f, cx + s * 0.34f, cy + s * 0.34f, cx + s * 0.74f, cy, c); // head
}
static void pIconGear(float cx, float cy, float s, SDL_Color c)
{
    for (int k = 0; k < 8; ++k) {
        float a = k * 0.7853982f, px = -sinf(a), py = cosf(a);
        float tx = cx + cosf(a) * s * 0.66f, ty = cy + sinf(a) * s * 0.66f;
        float b1x = cx + cosf(a) * s * 0.44f + px * s * 0.13f, b1y = cy + sinf(a) * s * 0.44f + py * s * 0.13f;
        float b2x = cx + cosf(a) * s * 0.44f - px * s * 0.13f, b2y = cy + sinf(a) * s * 0.44f - py * s * 0.13f;
        tri(tx, ty, b1x, b1y, b2x, b2y, c);
    }
    ring(cx, cy, s * 0.48f, s * 0.22f, c, 26);
}
static void pIcon(int id, float cx, float cy, float s, SDL_Color c)
{
    switch (id) { case 0: pIconPlay(cx, cy, s, c); break; case 1: pIconRestart(cx, cy, s, c); break;
                  case 2: pIconDoor(cx, cy, s, c); break; default: pIconGear(cx, cy, s, c); break; }
}

static bool s_pauseSession = false; // latched true for the duration of a real pause

// True for the WHOLE life of a genuine pause (entrance → interactive → resume/exit
// transitions), so the stock low-res pause stays suppressed the entire time. We
// latch on `stageMode==PAUSED` (only a real gameplay pause reaches that) and hold
// it until the stage loads or entity 9 stops being the pause menu — the latch is
// what stops both the title-screen type-ID collision AND the stock menu flashing
// through during the resume/exit states (which run at a non-PAUSED stageMode).
bool PauseActive()
{
    if (Engine.gameMode != ENGINE_MAINGAME)          { s_pauseSession = false; return false; }
    if (stageMode == STAGEMODE_LOAD)                 { s_pauseSession = false; return false; }
    if (StrComp(currentStageFolder, (char *)"Menu")) { s_pauseSession = false; return false; }
    if (objectEntityList[PAUSE_ENT].type != TypeNameID("Pause Menu")) { s_pauseSession = false; return false; }
    if (stageMode == STAGEMODE_PAUSED) s_pauseSession = true; // latch only on a real pause
    return s_pauseSession;
}

void PauseRender(SDL_Renderer *renderer)
{
    if (!PauseActive()) { s_pauseWasOn = false; return; }
    R = renderer;
    int W = 0, H = 0;
    SDL_GetRendererOutputSize(R, &W, &H);
    if (W <= 0 || H <= 0) return;
#if RETRO_USE_TTF
    if (s_cacheOwner != R) { clearCache(); s_cacheOwner = R; }
#endif
    int prevLW = 0, prevLH = 0;
    SDL_RenderGetLogicalSize(R, &prevLW, &prevLH);
    SDL_RenderSetLogicalSize(R, 0, 0);
    SDL_SetRenderDrawBlendMode(R, SDL_BLENDMODE_BLEND);

    const float fw = (float)W, fh = (float)H;
    const float t   = SDL_GetTicks() / 1000.0f;
    const float now = (float)SDL_GetTicks();

    Entity *pm = &objectEntityList[PAUSE_ENT];
    int  state       = pm->state;
    int  sel         = pm->values[1]; if (sel < 0) sel = 0;
    bool hideRestart = (pm->values[6] == 1);
    bool devMenu     = (GVar("Options.DevMenuFlag") == 1);
    bool trial       = (Engine.trialMode == 1);

    // ---- build the item list (Restart stays visible but disabled when locked) --
    struct Item { const char *label; int idx; bool enabled; int icon; }; // icon: 0 play,1 restart,2 exit,3 gear
    Item items[4]; int n = 0;
    items[n++] = { "CONTINUE", 0, true,         0 };
    items[n++] = { "RESTART",  1, !hideRestart, 1 };
    items[n++] = { "EXIT",     2, true,         2 };
    if (devMenu)    items[n++] = { "DEV MENU", 3, true, 3 };
    else if (trial) items[n++] = { "STORE",    3, true, 3 };
    int selRow = 0; for (int i = 0; i < n; ++i) if (items[i].idx == sel) selRow = i;

    if (!s_pauseWasOn) {
        s_pauseWasOn = true; s_pauseOpenAt = (Uint32)now;
        s_pauseLastState = -1; s_pauseLastSel = sel; s_pauseSelAt = (Uint32)now;
        s_pauseCurSel = (float)selRow;
    }
    if (state >= 4 && s_pauseLastState < 4) s_pauseExitAt = (Uint32)now; // captured start of exit/confirm
    s_pauseLastState = state;
    if (sel != s_pauseLastSel) { s_pauseLastSel = sel; s_pauseSelAt = (Uint32)now; }
    s_pauseCurSel += ((float)selRow - s_pauseCurSel) * 0.32f;            // smoothed moving highlight

    float tOpen  = now - s_pauseOpenAt;
    float exProg = (state >= 4) ? clamp01((now - s_pauseExitAt) / 320.0f) : 0.0f;
    float exE    = exProg * exProg;                                     // gentle accelerating exit
    float m      = easeOutCubic(clamp01(tOpen / 320.0f)) * (1.0f - exE); // master 0..1
    Uint8 A      = (Uint8)(clamp01(m) * 255);
    if (m <= 0.003f) { SDL_RenderSetLogicalSize(R, prevLW, prevLH); R = nullptr; return; }

    float idle = 0.5f + 0.5f * sinf(t * 1.4f);
    const SDL_Color accent  = { 38, 150, 245 };
    const SDL_Color accentHi = { 120, 195, 255 };

    // Smooth, understated entrance: elements ease in (easeOutQuint — no overshoot)
    // with a gentle stagger and a SHORT slide from the left; on close they drift
    // back out. Deliberately subtle so it reads premium, not springy/aggressive.
    #define PAUSE_APPEAR(delay) easeOutQuint(clamp01((tOpen - (delay)) / 560.0f))
    #define PAUSE_SLIDE(delay)  ((1.0f - PAUSE_APPEAR(delay)) * (-fw * 0.05f) - exE * fw * 0.09f)

    // ---- 1) cinematic scrim over the frozen gameplay --------------------------
    gradRect(0, 0, fw, fh, { 7, 10, 16, (Uint8)(226 * m) }, { 2, 3, 6, (Uint8)(244 * m) }, false);
    for (int k = 6; k >= 1; --k) // cool light pooled behind the menu column (depth on the left)
        circle(fw * 0.14f, fh * 0.48f, fh * (0.26f + k * 0.14f), { 42, 82, 128, (Uint8)(9 * m) });
    for (int k = 7; k >= 1; --k) // strong vignette to focus the eye
        circle(fw * 0.54f, fh * 0.52f, fh * (0.50f + k * 0.11f), { 0, 0, 0, (Uint8)(11 * m) });
    // filmic top/bottom letterbox falloff
    gradRect(0, 0, fw, fh * 0.11f, { 0, 0, 0, (Uint8)(130 * m) }, { 0, 0, 0, 0 }, false);
    gradRect(0, fh * 0.89f, fw, fh * 0.11f, { 0, 0, 0, 0 }, { 0, 0, 0, (Uint8)(130 * m) }, false);

    // ---- 2) angled "GAME PAUSED" banner (top-left) ----------------------------
    {
        float bSlide = PAUSE_SLIDE(0.0f);
        Uint8 bA     = (Uint8)(A * clamp01(PAUSE_APPEAR(0.0f)));
        float byT = fh * 0.055f, byB = fh * 0.205f;
        float lx  = -fh * 0.12f + bSlide;
        float rB  = fw * 0.50f + bSlide;
        float slant = (byB - byT) * 0.85f;
        float rT  = rB + slant;
        float mid = (byT + byB) * 0.5f;
        // drop shadow
        pQuad(lx, byT + fh * 0.014f, rT + fh * 0.010f, byT + fh * 0.014f, rB + fh * 0.010f, byB + fh * 0.016f,
              lx, byB + fh * 0.016f, { 0, 0, 0, (Uint8)(130 * m) });
        pPara(lx, byT, rT, rB, byB, 0.0f,        { 128, 138, 154, bA });   // brushed-silver rail
        pPara(lx, byT, rT, rB, byB, fh * 0.004f, { 10, 12, 17, bA });      // black gap
        pPara(lx, byT, rT, rB, byB, fh * 0.008f, { 66, 178, 255, bA });    // blue frame (bright)
        // deeper blue over the lower half of the frame → vertical gradient depth
        pQuad(lx, mid, rT - (rT - rB) * 0.5f, mid, rB, byB, lx, byB, { 18, 92, 190, (Uint8)(bA * 0.5f) });
        pPara(lx, byT, rT, rB, byB, fh * 0.023f, { 9, 12, 18, bA });       // interior
        // interior top sheen
        pQuad(lx + fh * 0.023f, byT + fh * 0.026f, rT - fh * 0.10f, byT + fh * 0.026f,
              rT - fh * 0.12f, mid, lx + fh * 0.023f, mid, { 255, 255, 255, (Uint8)(12 * m) });
        int   tpx = (int)(fh * 0.080f);
        drawText(lx + fh * 0.16f, mid - tpx * 0.5f, "GAME PAUSED", tpx, { 242, 247, 253, bA }, 0, true);
        // animated sheen sweeping across the banner
        float sweep = fmodf(t * 0.32f, 1.7f);
        if (sweep < 1.0f) {
            float sx = lx + sweep * (rB - lx + fh * 0.12f) - fh * 0.06f;
            float sl = (byB - byT) * 0.85f * 0.45f;
            pQuad(sx, byT + fh * 0.026f, sx + fh * 0.028f, byT + fh * 0.026f,
                  sx + fh * 0.028f - sl, byB - fh * 0.026f, sx - sl, byB - fh * 0.026f,
                  { 255, 255, 255, (Uint8)(20 * m * (bA / 255.0f)) });
        }
    }

    // ---- 3) menu buttons (left column, icon on the right) ---------------------
    float btnLx    = -fh * 0.10f;
    float btnRight = fw * 0.44f;
    float rowH     = fh * 0.108f;
    float gap      = fh * 0.026f;
    float y0       = fh * 0.36f;

    // pass 1 — shells (shadow + glassy fill + bevel)
    for (int i = 0; i < n; ++i) {
        float ap = PAUSE_APPEAR(145.0f + i * 62.0f);
        if (ap <= 0.001f) continue;
        float slide = PAUSE_SLIDE(145.0f + i * 62.0f);
        Uint8 apc = (Uint8)(clamp01(ap) * 255), rA = (Uint8)(A * clamp01(ap));
        float bt = y0 + i * (rowH + gap), bl = btnLx + slide, bw = (btnRight + slide) - bl, rr = rowH * 0.26f;
        // soft drop shadow
        roundRect(bl, bt + fh * 0.009f, bw, rowH, rr, { 0, 0, 0, (Uint8)(115 * clamp01(ap) * (1.0f - exE)) });
        // solid dark base (opaque so corners never read as semi-transparent)
        SDL_Color fill = items[i].enabled ? SDL_Color{ 28, 32, 41, rA } : SDL_Color{ 20, 22, 28, rA };
        roundRect(bl, bt, bw, rowH, rr, fill);
        glossTopR(bl, bt, bw, rowH * 0.5f, rr, (Uint8)(30 * clamp01(ap)));
        // bevel: bright top edge + dark bottom edge (inset from the rounded corners)
        gradRect(bl + rr, bt + fh * 0.0016f, bw - 2 * rr, fh * 0.0022f, { 150, 166, 190, (Uint8)(44 * apc / 255) },
                 { 150, 166, 190, 0 }, false);
        gradRect(bl + rr, bt + rowH - fh * 0.004f, bw - 2 * rr, fh * 0.004f, { 0, 0, 0, 0 },
                 { 0, 0, 0, (Uint8)(60 * apc / 255) }, false);
    }

    // pass 2 — moving accent highlight at the (smoothed) selected row
    {
        float apH   = clamp01(PAUSE_APPEAR(145.0f + s_pauseCurSel * 62.0f));
        float slide = PAUSE_SLIDE(145.0f + s_pauseCurSel * 62.0f);
        float bt = y0 + s_pauseCurSel * (rowH + gap), bl = btnLx + slide, bw = (btnRight + slide) - bl, rr = rowH * 0.26f;
        float pulse = 0.55f + 0.45f * idle;
        Uint8 rA = (Uint8)(A * apH);
        // layered outer glow (soft, breathing)
        for (int g = 3; g >= 1; --g)
            roundRect(bl - fh * 0.004f * g, bt - fh * 0.004f * g, bw + fh * 0.008f * g, rowH + fh * 0.008f * g,
                      rr + fh * 0.004f * g, { accent.r, accent.g, accent.b, (Uint8)(30 * m * pulse / g) });
        roundRect(bl, bt, bw, rowH, rr, { 33, 51, 78, rA });                                  // blue-glass fill
        roundRect(bl, bt, bw, rowH, rr, { accent.r, accent.g, accent.b, (Uint8)(38 * apH) });  // blue wash
        glossTopR(bl, bt, bw, rowH * 0.5f, rr, (Uint8)(52 * apH));
        // bright top edge highlight (inset from the rounded corners)
        gradRect(bl + rr, bt + fh * 0.0016f, bw - 2 * rr, fh * 0.0028f, accentHi, { accentHi.r, accentHi.g, accentHi.b, 0 }, false);
        // accent left bar (rounded)
        roundRect(bl + fh * 0.007f, bt + rowH * 0.16f, fh * 0.012f, rowH * 0.68f, fh * 0.006f, accentHi);
    }

    // pass 3 — labels + icons (brightness eases toward the highlighted row)
    for (int i = 0; i < n; ++i) {
        float ap = PAUSE_APPEAR(145.0f + i * 62.0f);
        if (ap <= 0.001f) continue;
        float slide = PAUSE_SLIDE(145.0f + i * 62.0f);
        Uint8 rA = (Uint8)(A * clamp01(ap));
        float bt = y0 + i * (rowH + gap), bl = btnLx + slide, br = btnRight + slide;
        bool  en = items[i].enabled;
        float prox = 1.0f - clamp01(fabsf((float)i - s_pauseCurSel)); // 1 on the selected row
        SDL_Color lc;
        if (!en)       lc = { 92, 100, 116, (Uint8)(rA * 0.7f) };
        else {
            Uint8 lum = (Uint8)(210 + 45 * prox);
            lc = { lum, (Uint8)(lum + 8 < 255 ? lum + 8 : 255), 255, rA };
        }
        int   lpx  = (int)(fh * 0.047f);
        float labx = bl + fh * 0.15f;   // clear of the off-screen left edge (labels were clipped)
        drawText(labx, bt + rowH * 0.5f - lpx * 0.5f, items[i].label, lpx, lc, 0, true);
        // icon sits in a subtle recessed circle on the right for a finished look
        float icx = br - fh * 0.066f, icy = bt + rowH * 0.5f;
        if (en) circle(icx, icy, fh * 0.031f, { 0, 0, 0, (Uint8)(rA * 0.28f) });
        SDL_Color ic = en ? SDL_Color{ 236, 243, 251, rA } : lc;
        pIcon(items[i].icon, icx, icy, fh * 0.040f, ic);
        if (!en) { // "locked" dot after the label
            float lw = textWidth(items[i].label, lpx, true);
            circle(labx + lw + fh * 0.03f, bt + rowH * 0.5f, fh * 0.008f, lc);
        }
    }

    // ---- 3b) right-side status panel — fills the space, reads as a pause HUD ---
    {
        char v[4][24];
        snprintf(v[0], 24, "%d:%02d.%02d", stageMinutes, stageSeconds, stageMilliseconds);
        int rings = playerList[0].boundEntity ? playerList[0].boundEntity->values[0] : 0;
        snprintf(v[1], 24, "%d", rings);
        snprintf(v[2], 24, "%d", (int)GVar("Player.Score"));
        snprintf(v[3], 24, "%d", (int)GVar("Player.Lives"));
        const char *lab[4] = { "TIME", "RINGS", "SCORE", "LIVES" };

        float gx = fw * 0.585f, cw = fw * 0.170f, ch = fh * 0.190f, gxp = fw * 0.022f, gyp = fh * 0.032f;
        float gy = fh * 0.360f;
        // header eyebrow (slides in from the right, opposite the menu)
        float hap = clamp01(PAUSE_APPEAR(240.0f));
        Uint8 hcA = (Uint8)(A * hap);
        float hsl = (1.0f - hap) * fw * 0.05f + exE * fw * 0.09f;
        roundRect(gx + hsl, gy - fh * 0.066f, fw * 0.024f, fh * 0.006f, fh * 0.003f, { accent.r, accent.g, accent.b, hcA });
        drawText(gx + hsl + fw * 0.036f, gy - fh * 0.075f, "STAGE STATUS", (int)(fh * 0.027f), { 150, 172, 200, hcA }, 0, true);

        for (int q = 0; q < 4; ++q) {
            int col = q % 2, row = q / 2;
            float ap = clamp01(PAUSE_APPEAR(290.0f + q * 62.0f));
            if (ap <= 0.001f) continue;
            float sl = (1.0f - ap) * fw * 0.055f + exE * fw * 0.10f;   // from/to the right
            Uint8 cA = (Uint8)(A * ap);
            float cx = gx + col * (cw + gxp) + sl, cy = gy + row * (ch + gyp), rr = ch * 0.15f;
            roundRect(cx, cy + fh * 0.007f, cw, ch, rr, { 0, 0, 0, (Uint8)(95 * ap * (1.0f - exE)) });   // shadow
            roundRect(cx, cy, cw, ch, rr, { 25, 29, 38, cA });                                          // glass card
            glossTopR(cx, cy, cw, ch * 0.5f, rr, (Uint8)(24 * ap));
            gradRect(cx + rr, cy + fh * 0.0016f, cw - 2 * rr, fh * 0.0022f, { 140, 158, 186, (Uint8)(38 * ap) },
                     { 140, 158, 186, 0 }, false);
            drawText(cx + cw * 0.5f, cy + ch * 0.17f, lab[q], (int)(fh * 0.024f), { 140, 162, 190, cA }, 1, true);
            drawTextFit(cx + cw * 0.5f, cy + ch * 0.42f, v[q], (int)(fh * 0.060f), { 236, 244, 253, cA }, cw * 0.82f, true);
            roundRect(cx + cw * 0.5f - cw * 0.13f, cy + ch * 0.81f, cw * 0.26f, fh * 0.005f, fh * 0.0025f,
                      { accent.r, accent.g, accent.b, (Uint8)(cA * 0.85f) });
        }
    }

    // ---- 4) control-hint badges (bottom-left) ---------------------------------
    {
        float hAp = easeOutCubic(clamp01((tOpen - 360.0f) / 320.0f)) * (1.0f - exE);
        Uint8 hA2 = (Uint8)(A * hAp);
        if (hA2 > 4) {
            float hy = fh * 0.905f, r = fh * 0.030f;
            float g1 = fh * 0.065f;                                   // NAVIGATE
            ring(g1, hy, r, r * 0.80f, { accentHi.r, accentHi.g, accentHi.b, hA2 });
            tri(g1, hy - r * 0.44f, g1 - r * 0.34f, hy - r * 0.04f, g1 + r * 0.34f, hy - r * 0.04f, { 236, 243, 250, hA2 });
            tri(g1, hy + r * 0.44f, g1 - r * 0.34f, hy + r * 0.04f, g1 + r * 0.34f, hy + r * 0.04f, { 236, 243, 250, hA2 });
            drawText(g1 + r + fh * 0.016f, hy - fh * 0.017f, "NAVIGATE", (int)(fh * 0.028f), { 188, 200, 216, hA2 }, 0, true);
            float g2 = fh * 0.065f + fw * 0.15f;                      // SELECT
            ring(g2, hy, r, r * 0.80f, { accentHi.r, accentHi.g, accentHi.b, hA2 });
            drawText(g2, hy - fh * 0.020f, "A", (int)(fh * 0.032f), { 236, 243, 250, hA2 }, 1, true);
            drawText(g2 + r + fh * 0.016f, hy - fh * 0.017f, "SELECT", (int)(fh * 0.028f), { 188, 200, 216, hA2 }, 0, true);
        }
    }

    // ---- 5) version ribbon (bottom-right corner, slides in/out diagonally) -----
    {
        float apIn = easeOutCubic(clamp01((tOpen - 420.0f) / 320.0f));
        Uint8 rA   = (Uint8)(A * apIn);
        if (rA > 4) {
            float off = (1.0f - apIn) * fh * 0.45f + exE * fh * 0.45f; // in from / out to the corner
            float a = fh * 0.275f, b = fh * 0.180f, lw = fh * 0.014f;
            float ox = off, oy = off;
            // blue accent edge (just outside the band)
            pQuad(fw - (a + lw) + ox, fh + oy, fw + ox, fh - (a + lw) + oy, fw + ox, fh - a + oy, fw - a + ox, fh + oy,
                  { 38, 150, 245, rA });
            // white ribbon band
            pQuad(fw - a + ox, fh + oy, fw + ox, fh - a + oy, fw + ox, fh - b + oy, fw - b + ox, fh + oy,
                  { 236, 240, 247, rA });
            // blue corner triangle (inner edge → corner)
            tri(fw - b + ox, fh + oy, fw + ox, fh - b + oy, fw + ox, fh + oy, { 38, 150, 245, rA });
            // rotated version text, centred on the band
            float cx = fw - (a + b) * 0.25f + ox, cy = fh - (a + b) * 0.25f + oy;
            drawTextRot(cx, cy, "REMASTER v1.0", (int)(fh * 0.023f), { 22, 30, 44, rA }, true, -45.0f);
        }
    }

    #undef PAUSE_SLIDE
    #undef PAUSE_APPEAR
    SDL_RenderSetLogicalSize(R, prevLW, prevLH);
    R = nullptr;
}

// Own the pause input so it's crisp + deterministic. The stock Pause Menu never
// initialises values[1], so it opened on a stale row; and the engine's
// Start-to-unpause (Scene.cpp) can double-fire with the menu's own confirm. We
// drive selection/confirm ourselves and swallow the raw edge so neither the stock
// object nor the engine unpause also react. Hooked in RetroEngine.cpp.
void PauseUpdate()
{
    Entity *pm = &objectEntityList[PAUSE_ENT];
    CheckKeyDown(&keyDown, 0xFF); CheckKeyPress(&keyPress, 0xFF); // fresh per-frame input

    if (pm->state >= 5) return;                                            // resume/exit: hand input back to the game
    if (pm->state <= 2) { pm->values[1] = 0; swallowMenuInput(); return; } // entrance: default Continue
    if (pm->state == 4) { swallowMenuInput(); return; }                    // confirm flash: block input

    bool hideRestart = (pm->values[6] == 1);
    bool devMenu     = (GVar("Options.DevMenuFlag") == 1);
    bool trial       = (Engine.trialMode == 1);
    int  maxSel      = (devMenu || trial) ? 3 : 2;

    if (keyPress.up) {
        pm->values[1]--;
        if (pm->values[1] < 0) pm->values[1] = maxSel;
        if (hideRestart && pm->values[1] == 1) pm->values[1] = 0;          // skip locked Restart
        pm->values[0] = 0; pm->animationTimer = 0; pm->frame = 0; pm->values[2] = SCREEN_XSIZE;
        PlaySfx(23, 0);
    } else if (keyPress.down) {
        pm->values[1]++;
        if (pm->values[1] > maxSel) pm->values[1] = 0;
        if (hideRestart && pm->values[1] == 1) pm->values[1] = 2;          // skip locked Restart
        pm->values[0] = 0; pm->animationTimer = 0; pm->frame = 0; pm->values[2] = SCREEN_XSIZE;
        PlaySfx(23, 0);
    }
    if (keyPress.A || keyPress.start) {   // confirm — the stock state machine runs the chosen action
        pm->state = 4; pm->alpha = 248; pm->values[0] = 0;
        PlaySfx(27, 0);
    }
    swallowMenuInput();
}

// =============================================================================
//  Draw-suppression + master render entry point
// =============================================================================
bool SuppressStockMenuDraw(int type)
{
    if (Engine.gameMode != ENGINE_MAINGAME) return false;

    // --- In-game pause menu --------------------------------------------------
    // Suppress the stock low-res pause draw while our hi-res overlay covers it.
    // Safe: the Pause Menu's state machine / input all live in ObjectMain, so
    // dropping its draw removes pixels only. (Runs before the stage-folder gates
    // below because pause happens inside a gameplay stage, not "Menu".)
    if (PauseActive() && type == TypeNameID("Pause Menu")) return true;

    // --- Time Attack (its own "TAttack" presentation stage) ------------------
    // We intentionally DON'T suppress any of its draws: in RSDKv3 an object's
    // Draw sub can carry game logic, and the Round Icon advances the whole menu
    // state machine (enter-zone / exit) from inside ObjectDraw. Suppressing it
    // froze selection/exit. Our TA overlay's backdrop is fully opaque and drawn
    // after the stock pass, so the low-res menu is covered anyway — no leak.
    if (StrComp(currentStageFolder, (char *)"TAttack"))
        return false;

    // --- Main "Menu" stage overlays ------------------------------------------
    if (!StrComp(currentStageFolder, (char *)"Menu")) return false;

    // Any remastered overlay covering the Menu stage owns the ENTIRE screen, so
    // suppress every stock draw in it — chrome, the animated background AND all
    // the decorations (Eggman / Metal Sonic / notes / etc.). That is what used to
    // bleed through beneath the overlays. Verified: no Menu-stage object carries
    // state logic in its ObjectDraw (that only happens in Time Attack's RoundIcon,
    // a different stage), so dropping the draw removes pixels only — never logic.
    // Screens we haven't remastered yet activate no overlay, so they still draw.
    if (Active() || PlayActive() || ExtrasActive() || OptionsShown() || OstActive()) {
        (void)type;
        return true;
    }
    return false;
}

// -----------------------------------------------------------------------------
//  Opaque frosted base for the ENTIRE Menu stage, drawn before any overlay each
//  frame. This is what finally kills the original menu/section rendering: even
//  during transitions and hand-offs (when no single overlay is "active" yet) the
//  remaster owns the screen, so the stock background / buttons / heading can
//  never flash through. Skipped only while the engine is fading to black to load
//  a level (so that fade plays) and while the still-stock Extras Visual-Mode
//  video picker is up (so it stays usable).
// -----------------------------------------------------------------------------
static bool menuFadingToLevel()
{
    int ty = objectEntityList[LSM].type, st = objectEntityList[LSM].state;
    if (ty == TypeNameID("Load Save Menu") && (st == 3 || st == 8)) return true; // continue / new-game load
    if (ty == TypeNameID("Options Menu C") && st == 3) return true;              // staff-credits load
    return false;
}
static bool extrasVideoPicker()
{
    return objectEntityList[LSM].type == TypeNameID("Extras Menu") && !ExtrasActive();
}
static void MenuBackdrop(SDL_Renderer *renderer)
{
    if (Engine.gameMode != ENGINE_MAINGAME) return;
    if (!StrComp(currentStageFolder, (char *)"Menu")) return;
    if (menuFadingToLevel() || extrasVideoPicker()) return;
    R = renderer;
    int W = 0, H = 0;
    SDL_GetRendererOutputSize(R, &W, &H);
    if (W <= 0 || H <= 0) return;
    int prevLW = 0, prevLH = 0;
    SDL_RenderGetLogicalSize(R, &prevLW, &prevLH);
    SDL_RenderSetLogicalSize(R, 0, 0);
    SDL_SetRenderDrawBlendMode(R, SDL_BLENDMODE_BLEND);
    const float fw = (float)W, fh = (float)H;
    const float t = SDL_GetTicks() / 1000.0f;
    gradRect(0, 0, fw, fh, { 238, 243, 248, 255 }, { 194, 206, 219, 255 }, false);
    for (int i = 0; i < 4; ++i) {
        float dy = fmodf(t * (5.0f + i * 2.0f) + i * 300.0f, fh + 400.0f) - 200.0f;
        float y = fh - dy, s = fh * (0.16f + 0.06f * i), rot = t * 0.09f + i;
        float ax = fw * (0.6f - 0.13f * i);
        tri(ax, y, ax + cosf(rot) * s, y + sinf(rot) * s, ax + cosf(rot + 2.1f) * s, y + sinf(rot + 2.1f) * s, { 255, 255, 255, 22 });
    }
    gradRect(0, 0, fw, fh * 0.014f, { 46, 143, 212, 255 }, { 95, 200, 240, 220 }, true);
    SDL_RenderSetLogicalSize(R, prevLW, prevLH);
    R = nullptr;
}

void RenderAll(SDL_Renderer *renderer)
{
    MenuBackdrop(renderer); // opaque base for the whole Menu stage (kills transition bleed)
    Render(renderer);       // main mode-select (each early-returns unless active)
    PlayRender(renderer);   // save-select
    ExtrasRender(renderer); // extras
    TARender(renderer);     // time attack (zone-select + records)
    OptionsRender(renderer);// options (settings panel)
    OstRender(renderer);    // soundtrack selector
    PauseRender(renderer);  // in-game pause menu (over frozen gameplay)
}
} // namespace RemasterMenu

#endif // RETRO_USE_NATIVE_OBJECTS
