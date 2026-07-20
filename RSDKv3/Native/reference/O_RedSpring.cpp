#include "RetroEngine.hpp"

#if RETRO_USE_NATIVE_OBJECTS

#include "O_RedSpring.hpp"
#include "GameConstants.hpp"  // GRAVITY_*, FACING_*, SFX_G_SPRING, ANI_*
#include "PlayerConstants.hpp"

using namespace Native;

// CMODE_FLOOR / CMODE_ROOF come from the engine's Collision.hpp enum — do NOT
// redefine them here (that clashes). Only spring-specific magnitudes are local.
namespace
{
// Launch magnitudes, kept as raw 16.16 hex so the sub-pixel physics is identical
// to the script (0x100000 == 16.0 px/frame, 0xB4000 == 11.25 px/frame).
constexpr int SPRING_POWER      = 0x100000;
constexpr int SPRING_POWER_DIAG = 0xB4000;

// Cached script-function ID for "Player_State_Air" (resolved once per stage).
// See PlayerConstants.hpp for why this indirection is required in the hybrid phase.
int airStateID = 0;
inline void CachePlayerStates()
{
    if (!airStateID) {
        airStateID = PlayerStateID("Player_State_Air");
        // Guard against the bytecode-mode failure mode: script-function names are
        // only populated when compiling text scripts, so in pure bytecode mode this
        // returns 0 (an invalid state that breaks the player). Warn loudly if so.
        if (!airStateID)
            PrintLog("WARNING: RedSpring could not resolve Player_State_Air (function "
                     "names unavailable - bytecode mode?). Diagonal/up springs will break.");
        else
            PrintLog("RedSpring: Player_State_Air resolved to state ID %d", airStateID);
    }
}

// Shared "launch straight up" effect (FACE_UP solid + platform branches).
void BounceUp()
{
    Player *player = Plr();
    Entity *pEnt   = PlrEntity();
    Entity *self   = Self();

    // Player.AnimationReserve == Player.Value7 -> boundEntity->values[7] (NOT the
    // Player struct). Upgraded if the player is already running/peeling out.
    PlayerValue(7) = ANI_WALKING;
    if (pEnt->animation == ANI_RUNNING)
        PlayerValue(7) = ANI_RUNNING;
    if (pEnt->animation == ANI_PEELOUT)
        PlayerValue(7) = ANI_PEELOUT;

    self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;

    pEnt->state       = airStateID; // Player.State = Player_State_Air (standalone path)
    player->gravity   = GRAVITY_AIR;
    player->YVelocity = -SPRING_POWER;
    pEnt->animation   = ANI_BOUNCING;
    player->timer     = 0;

    PlaySfx(SFX_G_SPRING, false);
}
} // namespace

// =============================================================================
//  sub ObjectPlayerInteraction
// =============================================================================
void O_RedSpring::PlayerInteraction()
{
    CachePlayerStates();

    Player *player = Plr();
    Entity *pEnt   = PlrEntity();
    Entity *self   = Self();

    switch (self->propertyValue) {
        case FACE_UP: {
            // "onPlatform" == script TempValue0: true when the player is airborne,
            // or on a roof/wall while still moving upward -> treat spring as a
            // pass-through platform instead of a solid box.
            bool onPlatform = false;
            if (player->gravity == GRAVITY_AIR)
                onPlatform = true;
            if (player->collisionMode > CMODE_FLOOR) {
                if (player->YVelocity < 0)
                    onPlatform = true;
            }

            if (!onPlatform) {
                PlayerObjectCollision(C_BOX, -16, -8, 16, 8);
                PlayerObjectCollision(C_TOUCH, -16, -10, 16, -6);
                if (CheckResult() == true)
                    BounceUp();
            }
            else if (player->YVelocity >= 0) {
                PlayerObjectCollision(C_PLATFORM, -16, -8, 16, 8);
                PlayerObjectCollision(C_TOUCH, -16, -10, 16, -6);
                if (CheckResult() == true)
                    BounceUp();
            }
            break;
        }

        case FACE_RIGHT: {
            PlayerObjectCollision(C_BOX, -8, -16, 8, 16);
            // Origins-only "ANI_GLIDING" guard omitted (standalone build).
            bool eligible = (player->gravity == GRAVITY_GROUND) || (self->values[O_RedSpring::VAL_ENABLED_IN_AIR] == true);
            if (eligible) {
                PlayerObjectCollision(C_TOUCH, 6, -15, 11, 15);
                if (CheckResult() == true) {
                    self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                    player->angle                                      = 0;
                    player->speed                                      = SPRING_POWER;
                    player->collisionMode                              = CMODE_FLOOR;
                    player->pushing                                    = false;
                    pEnt->direction                                    = FACING_RIGHT;
                    player->controlLock                                = 16;
                    PlaySfx(SFX_G_SPRING, false);
                }
            }
            break;
        }

        case FACE_LEFT: {
            PlayerObjectCollision(C_BOX, -8, -16, 8, 16);
            if (player->gravity == GRAVITY_GROUND) {
                PlayerObjectCollision(C_TOUCH, -10, -15, -6, 15);
                if (CheckResult() == true) {
                    self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                    player->speed                                      = -SPRING_POWER;
                    player->collisionMode                              = CMODE_FLOOR;
                    player->pushing                                    = false;
                    pEnt->direction                                    = FACING_LEFT;
                    player->controlLock                                = 16;
                    PlaySfx(SFX_G_SPRING, false);
                }
            }
            else if (self->values[O_RedSpring::VAL_ENABLED_IN_AIR] == true) {
                PlayerObjectCollision(C_TOUCH, -10, -15, -6, 15);
                if (CheckResult() == true) {
                    self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                    player->speed                                      = -SPRING_POWER;
                    player->YVelocity                                  = 0x20000; // air branch nudges Y (script quirk)
                    player->collisionMode                              = CMODE_FLOOR;
                    player->pushing                                    = false;
                    pEnt->direction                                    = FACING_LEFT;
                    player->controlLock                                = 16;
                    PlaySfx(SFX_G_SPRING, false);
                }
            }
            break;
        }

        case FACE_DOWN: {
            PlayerObjectCollision(C_BOX, -16, -8, 16, 8);
            PlayerObjectCollision(C_TOUCH, -15, 6, 15, 10);
            if (CheckResult() == true) {
                if (player->collisionMode == CMODE_ROOF) {
                    // FlipSign(): negate. Needed because on a ceiling the player's
                    // horizontal momentum sign is inverted relative to the spring.
                    player->speed     = -player->speed;
                    player->XVelocity = -player->XVelocity;
                }
                self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                pEnt->state                                        = airStateID;
                player->gravity                                    = GRAVITY_AIR;
                player->YVelocity                                  = SPRING_POWER;
                player->timer                                      = 0;
                PlaySfx(SFX_G_SPRING, false);
            }
            break;
        }

        case FACE_DIAGONAL_UR: {
            PlayerObjectCollision(C_TOUCH, -12, -16, 12, 12);
            // Two independent guards, exactly as scripted: with CheckResult latched,
            // both can fire in one frame (harmless re-apply) — preserved verbatim.
            if (player->gravity == GRAVITY_GROUND && CheckResult() == true) {
                self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                pEnt->state                                        = airStateID;
                player->gravity                                    = GRAVITY_AIR;
                player->speed                                      = SPRING_POWER_DIAG;
                player->YVelocity                                  = -SPRING_POWER_DIAG;
                pEnt->animation                                    = ANI_WALKING;
                pEnt->direction                                    = FACING_RIGHT;
                player->timer                                      = 0;
                PlaySfx(SFX_G_SPRING, false);
            }
            if (player->YVelocity >= 0 && CheckResult() == true) {
                self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                pEnt->state                                        = airStateID;
                player->gravity                                    = GRAVITY_AIR;
                player->speed                                      = SPRING_POWER_DIAG;
                player->YVelocity                                  = -SPRING_POWER_DIAG;
                pEnt->animation                                    = ANI_WALKING;
                pEnt->direction                                    = FACING_RIGHT;
                player->timer                                      = 0;
                PlaySfx(SFX_G_SPRING, false);
            }
            break;
        }

        case FACE_DIAGONAL_UL: {
            PlayerObjectCollision(C_TOUCH, -12, -16, 12, 12);
            // Note: guard order is (YVelocity, then gravity) here — mirror of UR.
            if (player->YVelocity >= 0 && CheckResult() == true) {
                self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                pEnt->state                                        = airStateID;
                player->gravity                                    = GRAVITY_AIR;
                player->speed                                      = -SPRING_POWER_DIAG;
                player->YVelocity                                  = -SPRING_POWER_DIAG;
                pEnt->animation                                    = ANI_WALKING;
                pEnt->direction                                    = FACING_LEFT;
                player->timer                                      = 0;
                PlaySfx(SFX_G_SPRING, false);
            }
            if (player->gravity == GRAVITY_GROUND && CheckResult() == true) {
                self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                pEnt->state                                        = airStateID;
                player->gravity                                    = GRAVITY_AIR;
                player->speed                                      = -SPRING_POWER_DIAG;
                player->YVelocity                                  = -SPRING_POWER_DIAG;
                pEnt->animation                                    = ANI_WALKING;
                pEnt->direction                                    = FACING_LEFT;
                player->timer                                      = 0;
                PlaySfx(SFX_G_SPRING, false);
            }
            break;
        }

        case FACE_DIAGONAL_DR: {
            PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
            if (CheckResult() == true) {
                self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                pEnt->state                                        = airStateID;
                player->gravity                                    = GRAVITY_AIR;
                player->speed                                      = SPRING_POWER_DIAG;
                player->YVelocity                                  = SPRING_POWER_DIAG;
                player->timer                                      = 0;
                PlaySfx(SFX_G_SPRING, false);
            }
            break;
        }

        case FACE_DIAGONAL_DL: {
            PlayerObjectCollision(C_TOUCH, -12, -12, 12, 12);
            if (CheckResult() == true) {
                self->values[O_RedSpring::VAL_ACTIVE_SPRING_FRAME] = 1;
                pEnt->state                                        = airStateID;
                player->gravity                                    = GRAVITY_AIR;
                player->speed                                      = -SPRING_POWER_DIAG;
                player->YVelocity                                  = SPRING_POWER_DIAG;
                player->timer                                      = 0;
                PlaySfx(SFX_G_SPRING, false);
            }
            break;
        }
    }
}

// =============================================================================
//  sub ObjectDraw
// =============================================================================
void O_RedSpring::Draw()
{
    Entity *self = Self();
    int &frameCtr = self->values[VAL_ACTIVE_SPRING_FRAME];

    if (frameCtr == 0) {
        // Idle: draw the plain spring sprite for its facing (propertyValue 0..7).
        DrawSpriteFX_Flip(self->propertyValue, self->XPos, self->YPos);
        return;
    }

    ++frameCtr;

    // The recoil animation advances one drawn frame every TWO ticks (>>1), and the
    // frame group is chosen from that halved counter — a hand-rolled 2x frame hold.
    int phase = frameCtr >> 1;
    switch (phase) {
        case 0:
        case 1: // spring at rest pose
            DrawSpriteFX_Flip(self->propertyValue, self->XPos, self->YPos);
            break;
        case 2:
        case 6: // compressed "head" frames live at propertyValue + 8
            DrawSpriteFX_Flip(self->propertyValue + 8, self->XPos, self->YPos);
            break;
        case 3:
        case 4:
        case 5: // extended "launch" frames live at propertyValue + 16
            DrawSpriteFX_Flip(self->propertyValue + 16, self->XPos, self->YPos);
            break;
    }

    if (frameCtr > 12)
        frameCtr = 0;
}

// =============================================================================
//  sub ObjectStartup
// =============================================================================
void O_RedSpring::Setup()
{
    LoadSpriteSheet("Global/Items.gif");

    // Springs (idle)                       pivotX pivotY  w   h  sprX sprY
    AddSpriteFrame(-16, -8, 32, 16, 84, 1);   // #0  up
    AddSpriteFrame(-8, -16, 16, 32, 117, 1);  // #1  right
    AddSpriteFrame(-8, -16, 16, 32, 175, 1);  // #2  left
    AddSpriteFrame(-16, -8, 32, 16, 84, 59);  // #3  down
    AddSpriteFrame(-16, -16, 32, 32, 84, 117);   // #4  diagonal UR
    AddSpriteFrame(-16, -16, 32, 32, 117, 165);  // #5  diagonal UL
    AddSpriteFrame(-16, -16, 32, 32, 84, 117);   // #6  diagonal DR
    AddSpriteFrame(-16, -16, 32, 32, 117, 165);  // #7  diagonal DL
    // Spring recoil (head)                 propertyValue + 8
    AddSpriteFrame(-16, 0, 32, 8, 84, 1);     // #8  up
    AddSpriteFrame(-8, -16, 8, 32, 125, 1);   // #9  right
    AddSpriteFrame(0, -16, 8, 32, 175, 1);    // #10 left
    AddSpriteFrame(-16, -8, 32, 8, 84, 67);   // #11 down
    AddSpriteFrame(-16, -16, 32, 32, 84, 150);   // #12 diagonal UR
    AddSpriteFrame(-16, -16, 32, 32, 150, 165);  // #13 diagonal UL
    AddSpriteFrame(-16, -16, 32, 32, 84, 150);   // #14 diagonal DR
    AddSpriteFrame(-16, -16, 32, 32, 150, 165);  // #15 diagonal DL
    // Spring launch                        propertyValue + 16
    AddSpriteFrame(-16, -32, 32, 40, 84, 18);    // #16 up
    AddSpriteFrame(-8, -16, 40, 32, 134, 1);     // #17 right
    AddSpriteFrame(-16, -16, 40, 32, 192, 1);    // #18 left
    AddSpriteFrame(-16, -8, 32, 40, 84, 76);     // #19 down
    AddSpriteFrame(-16, -32, 48, 48, 117, 34);   // #20 diagonal UR
    AddSpriteFrame(-32, -32, 48, 48, 166, 34);   // #21 diagonal UL
    AddSpriteFrame(-16, -32, 48, 48, 117, 34);   // #22 diagonal DR
    AddSpriteFrame(-32, -32, 48, 48, 166, 34);   // #23 diagonal DL

    // Per-instance fixup over the act layout entities (script scanned 32..1055):
    // property values 8..15 encode "enabled in air", and 6/7 (down-diagonals)
    // are drawn vertically flipped.
    const int redSpringType = curObjectType; // == TypeName[Red Spring] during its own setup
    for (int i = 32; i < 1056; ++i) {
        Entity *e = &objectEntityList[i];
        if (e->type != redSpringType)
            continue;

        if (e->propertyValue > 7) {
            e->propertyValue -= 8;
            e->values[VAL_ENABLED_IN_AIR] = true;
        }
        if (e->propertyValue > 5)
            e->direction = FLIP_Y;
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
