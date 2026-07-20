#include "RetroEngine.hpp"

#if RETRO_USE_NATIVE_OBJECTS

#include "O_Player.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"

using namespace Native;

// ---------------------------------------------------------------------------
//  Cached player-state function IDs. While ObjectMain is still interpreted,
//  Player.State holds a script-function ID (see PlayerConstants.hpp).
// ---------------------------------------------------------------------------
namespace
{
// Lazy, cached name->ID lookups. Each stays 0 until scripts are loaded, then
// caches the resolved ID (function IDs are nonzero for these states).
int GroundStateID()
{
    static int id = 0;
    if (!id)
        id = PlayerStateID("Player_State_Ground");
    return id;
}
int AirStateID()
{
    static int id = 0;
    if (!id)
        id = PlayerStateID("Player_State_Air");
    return id;
}
int SpindashCDStateID()
{
    static int id = 0;
    if (!id)
        id = PlayerStateID("Player_State_Spindash_CD");
    return id;
}
int PeeloutCDStateID()
{
    static int id = 0;
    if (!id)
        id = PlayerStateID("Player_State_Peelout_CD");
    return id;
}
int LookUpStateID()
{
    static int id = 0;
    if (!id)
        id = PlayerStateID("Player_State_LookUp");
    return id;
}
int CrouchStateID()
{
    static int id = 0;
    if (!id)
        id = PlayerStateID("Player_State_Crouch");
    return id;
}
int RollStateID()
{
    static int id = 0;
    if (!id)
        id = PlayerStateID("Player_State_Roll");
    return id;
}
int OuttaHereStateID()
{
    static int id = 0;
    if (!id)
        id = PlayerStateID("Player_State_OuttaHere");
    return id;
}

// --- Global variables (GameConfig). Names must match the .gc; verify on extract.
inline int WarpDestination() { return GetGlobalVariableByName("Warp.Destination"); }
inline void SetWarpDestination(int v) { SetGlobalVariableByName("Warp.Destination", v); }
inline int WarpTimer() { return GetGlobalVariableByName("Warp.Timer"); }
inline void SetWarpTimer(int v) { SetGlobalVariableByName("Warp.Timer", v); }
inline int WarpSpeedCompare() { return GetGlobalVariableByName("Warp.SpeedCompare"); }
inline void SetWarpSpeedCompare(int v) { SetGlobalVariableByName("Warp.SpeedCompare", v); }
inline int RingAniCount() { return GetGlobalVariableByName("Ring.AniCount"); }

// Spawns/refreshes the Warp Star on entity slot 3 (WarpStar.* aliases -> Object[3]).
void SpawnWarpStar()
{
    ResetObjectEntity(3, TypeNameID("WarpStar"), 0, pXPos(), pYPos());
    objectEntityList[3].values[0]  = 7; // WarpStar.Timer
    objectEntityList[3].drawOrder  = 4; // WarpStar.DrawOrder
}
} // namespace

// ===========================================================================
//  function Player_Action_Jump
// ===========================================================================
void O_Player::Action_Jump()
{
    Entity *self  = Self();
    CheckResult() = false;

    // Roof check: temporarily move THIS object (the player entity) to the player's
    // position and probe the right wall/roof, so you can't jump into a low ceiling.
    if (pCollisionMode() == CMODE_FLOOR) {
        int savedX = self->XPos;
        int savedY = self->YPos;
        self->XPos = pXPos();
        self->YPos = pYPos();
        int top    = pCollisionTop() - 2;
        ObjectRWallCollision(0, top, 0); // ObjectTileCollision(CSIDE_RWALL, ...) -> sets CheckResult
        self->XPos = savedX;
        self->YPos = savedY;
    }

    if (CheckResult() == false) {
        pControlLock()  = 0;
        pGravity()      = GRAVITY_AIR;
        pAbilityTimer() = 8;

        int t;
        // XVelocity = (sin(angle)*jumpStrength + cos(angle)*speed) >> 8
        pXVel() = Sin256(pAngle());
        pXVel() *= pJumpStrength();
        t = Cos256(pAngle());
        t *= pSpeed();
        pXVel() += t;
        pXVel() >>= 8;

        // YVelocity = (sin(angle)*speed - cos(angle)*jumpStrength) >> 8
        pYVel() = Sin256(pAngle());
        pYVel() *= pSpeed();
        t = Cos256(pAngle());
        t *= pJumpStrength();
        pYVel() -= t;
        pYVel() >>= 8;

        pSpeed()         = pXVel();
        pTrackScroll()   = true;
        pAnimation()     = ANI_JUMPING;
        pAngle()         = 0;
        pCollisionMode() = CMODE_FLOOR;
        pTimer()         = 1;
        HandleRollAnimSpeed(); // CallFunction(Player_HandleRollAnimSpeed)

        pState() = AirStateID();

        PlaySfx(SFX_G_JUMP, false);
    }
    // (Origins-only DropDashCharge init omitted — standalone build.)
}

// ===========================================================================
//  function Player_Action_Spindash_CD  (starts the CD spindash; state does the rest)
// ===========================================================================
void O_Player::Action_Spindash_CD()
{
    pState()        = SpindashCDStateID();
    pAnimation()    = ANI_JUMPING;
    pYPos()        += 0x50000; // sink 5px so the ball sits on the ground
    pAbilityTimer() = 0;
    PlaySfx(SFX_G_CHARGE, false);
}

// ===========================================================================
//  function Player_Action_Peelout_CD
// ===========================================================================
void O_Player::Action_Peelout_CD()
{
    pState()        = PeeloutCDStateID();
    pAbilityTimer() = 0;
    PlaySfx(SFX_G_CHARGE, false);
}

// ===========================================================================
//  function Player_State_Static  (a parked player does nothing)
// ===========================================================================
void O_Player::State_Static() { CheckResult() = false; }

// ===========================================================================
//  Animation-speed helpers
//  RollAnimationSpeed == Value2; AnimationSpeed == boundEntity->animationSpeed.
//  Integer division is intentional (matches the script's fixed-point scaling).
// ===========================================================================
void O_Player::HandleRollAnimSpeed()
{
    if (playerListPos == PLAYER_TAILS_A) {
        pRollAnimationSpeed() = 120;
    }
    else {
        int &ras = pRollAnimationSpeed();
        ras       = pSpeed();
        if (ras < 0)
            ras = -ras; // FlipSign
        ras *= 240;
        ras /= 0x60000;
        ras += 48;
    }
}

void O_Player::HandleWalkAnimSpeed()
{
    int &as = pAnimationSpeed();
    as       = pSpeed();
    if (as < 0)
        as = -as;
    as *= 60;
    as /= 0x60000;
    as += 20;
}

void O_Player::HandleRunAnimSpeed()
{
    int &as = pAnimationSpeed();
    as       = pSpeed();
    if (as < 0)
        as = -as;
    as *= 80;
    as /= 0x60000;
}

// ===========================================================================
//  function Player_HandleGroundMovement  ("this makes you move")
// ===========================================================================
void O_Player::HandleGroundMovement()
{
    int t;

    if (pControlLock() > 0) {
        // Locked: only the slope component of gravity acts on speed.
        pControlLock()--;
        t = Sin256(pAngle());
        t *= 0x2000;
        t >>= 8;
        pSpeed() += t;
        return;
    }

    // --- Holding Left ---
    if (pLeft() == true) {
        int negTop = -pTopSpeed(); // FlipSign(TopSpeed)
        if (pSpeed() > negTop) {
            if (pSpeed() > 0) {
                if (pCollisionMode() == CMODE_FLOOR) {
                    if (pSpeed() > 0x40000)
                        pSkidding() = 16; // skid puff threshold
                }
                if (pSpeed() < 0x8000) {
                    pSpeed()    = -0x8000;
                    pSkidding() = 0;
                }
                else {
                    pSpeed() -= 0x8000;
                }
            }
            else {
                pSpeed() -= pAccel();
                pSkidding() = 0;
            }
        }
        if (pSpeed() <= 0)
            pDirection() = FACING_LEFT;
    }

    // --- Holding Right (mirror of Left) ---
    if (pRight() == true) {
        if (pSpeed() < pTopSpeed()) {
            if (pSpeed() < 0) {
                if (pCollisionMode() == CMODE_FLOOR) {
                    if (pSpeed() < -0x40000)
                        pSkidding() = 16;
                }
                if (pSpeed() > -0x8000) {
                    pSpeed()    = 0x8000;
                    pSkidding() = 0;
                }
                else {
                    pSpeed() += 0x8000;
                }
            }
            else {
                pSpeed() += pAccel();
                pSkidding() = 0;
            }
        }
        if (pSpeed() >= 0)
            pDirection() = FACING_RIGHT;
    }

    // --- No horizontal input: decelerate, then apply slope factor ---
    if ((pLeft() | pRight()) == false) {
        if (pSpeed() > 0) {
            pSpeed() -= pDecel();
            if (pSpeed() < 0)
                pSpeed() = 0;
        }
        else {
            pSpeed() += pDecel();
            if (pSpeed() > 0)
                pSpeed() = 0;
        }

        if (pSpeed() > 0x2000) {
            t = Sin256(pAngle());
            t *= 0x2000;
            t >>= 8;
            pSpeed() += t;
        }
        if (pSpeed() < -0x2000) {
            t = Sin256(pAngle());
            t *= 0x2000;
            t >>= 8;
            pSpeed() += t;
        }

        // On steep-ish slopes at low speed, lock control so the player slides off.
        if (pAngle() > 192 && pAngle() < 228) {
            if (pSpeed() > -0x10000 && pSpeed() < 0x10000)
                pControlLock() = 30;
        }
        if (pAngle() > 28 && pAngle() < 64) {
            if (pSpeed() > -0x10000 && pSpeed() < 0x10000)
                pControlLock() = 30;
        }
    }
    else {
        // Input held on a slope: apply slope factor, then a directional lock rule.
        t = Sin256(pAngle());
        t *= 0x2000;
        t >>= 8;
        pSpeed() += t;

        // Nested exactly as scripted: rule A only when Right&&!Left, rule B only
        // when !Right&&Left (both-held must fall through to neither).
        if (pRight() == true) {
            if (pLeft() == false) {
                if (pAngle() > 192 && pAngle() < 228) {
                    if (pSpeed() < 0x28000 && pSpeed() > -0x20000)
                        pControlLock() = 30;
                }
            }
        }
        else {
            if (pLeft() == true) {
                if (pAngle() > 28 && pAngle() < 64) {
                    if (pSpeed() > -0x28000 && pSpeed() < 0x20000)
                        pControlLock() = 30;
                }
            }
        }
    }
}

// ===========================================================================
//  function Player_HandleAirFriction
// ===========================================================================
void O_Player::HandleAirFriction()
{
    int t;

    // Air drag near the apex of a jump (moving up, below terminal).
    if (pYVel() > -0x40000) {
        if (pYVel() < 0) {
            t = pSpeed();
            t >>= 5;
            pSpeed() -= t;
        }
    }

    int negTop = -pTopSpeed(); // FlipSign(TopSpeed)
    if (pSpeed() > negTop) {
        if (pLeft() == true) {
            pSpeed() -= pAirAccel();
            pDirection() = FACING_LEFT;
        }
    }
    else if (pLeft() == true) {
        pDirection() = FACING_LEFT;
    }

    if (pSpeed() < pTopSpeed()) {
        if (pRight() == true) {
            pSpeed() += pAirAccel();
            pDirection() = FACING_RIGHT;
        }
    }
    else if (pRight() == true) {
        pDirection() = FACING_RIGHT;
    }

    // Original (S1/CD-accurate) control clamps top speed hard.
    if (GetGlobalVariableByName("Options.OriginalControls") == true) {
        if (pLeft() == true) {
            int negTop2 = -pTopSpeed();
            if (pSpeed() < negTop2)
                pSpeed() = negTop2;
        }
        if (pRight() == true) {
            if (pSpeed() > pTopSpeed())
                pSpeed() = pTopSpeed();
        }
    }
}

// ===========================================================================
//  function Player_HandleRollDeceleration
// ===========================================================================
void O_Player::HandleRollDeceleration()
{
    int t;

    if (pRight() == true) {
        if (pSpeed() < 0)
            pSpeed() += pRollingDecel();
    }
    if (pLeft() == true) {
        if (pSpeed() > 0)
            pSpeed() -= pRollingDecel();
    }

    if (pSpeed() > 0) {
        pSpeed() -= pAirDecel();
        if (pSpeed() < 0)
            pSpeed() = 0;

        if (pSpeed() == 0) {
            if (pAngle() > 224)
                pState() = GroundStateID();
            if (pAngle() < 32)
                pState() = GroundStateID();
        }

        // Slope factor: steeper multiplier downhill (0x5000) than uphill (0x1E00).
        t = Sin256(pAngle());
        if (t > 0)
            t *= 0x5000;
        else
            t *= 0x1E00;
        t >>= 8;
        pSpeed() += t;
    }
    else {
        pSpeed() += pAirDecel();
        if (pSpeed() > 0)
            pSpeed() = 0;

        if (pSpeed() == 0) {
            if (pAngle() > 224)
                pState() = GroundStateID();
            if (pAngle() < 32)
                pState() = GroundStateID();
        }

        t = Sin256(pAngle());
        if (t < 0)
            t *= 0x5000;
        else
            t *= 0x1E00;
        t >>= 8;
        pSpeed() += t;
    }

    // Clamp rolling speed to +/- 24.0 px/frame.
    if (pSpeed() > 0x180000)
        pSpeed() = 0x180000;
    if (pSpeed() < -0x180000)
        pSpeed() = -0x180000;
}

// ===========================================================================
//  function Player_HandleAirMovement  (gravity + variable jump height)
// ===========================================================================
void O_Player::HandleAirMovement()
{
    int t;

    pTrackScroll() = true;

    pYVel() += pGravityStrength();
    if (pYVel() < pJumpCap()) {
        if (pJumpHold() == false) {
            if (pTimer() > 0) {
                // Released jump early -> cap upward velocity (variable jump height).
                pYVel() = pJumpCap();
                t        = pSpeed();
                t >>= 5;
                pSpeed() -= t;
            }
        }
    }
    pXVel() = pSpeed();

    // Ease jump-spin rotation back toward upright.
    if (pRotation() < 256) {
        if (pRotation() > 0)
            pRotation() -= 4;
        else
            pRotation() = 0;
    }
    else {
        if (pRotation() < 512)
            pRotation() += 4;
        else
            pRotation() = 0;
    }

    pCollisionMode() = CMODE_FLOOR;
    if (pAnimation() == ANI_JUMPING)
        pAnimationSpeed() = pRollAnimationSpeed();
}

// ===========================================================================
//  function Player_HandleOnGround  (resolve speed into X/Y velocity by angle)
// ===========================================================================
void O_Player::HandleOnGround()
{
    int t;

    pTrackScroll() = false;

    t = Cos256(pAngle());
    t *= pSpeed();
    t >>= 8;
    pXVel() = t;

    t = Sin256(pAngle());
    t *= pSpeed();
    t >>= 8;
    pYVel() = t;
}

// ===========================================================================
//  function Player_State_Ground  (standalone path)
// ===========================================================================
void O_Player::State_Ground()
{
    // Skid SFX plays only on the frame the skid starts (anim wasn't already skidding).
    bool skidSfxAllowed = (pAnimation() != ANI_SKIDDING);

    HandleGroundMovement();

    if (pGravity() == GRAVITY_AIR) {
        pState() = AirStateID();
        HandleAirMovement();
        return;
    }

    HandleOnGround();

    if (pSpeed() == 0) {
        // Consume a pending warp if the player stops slightly too late.
        if (WarpDestination() > WARPDEST_NONE) {
            if (WarpTimer() > 99 && WarpTimer() < 220)
                SetWarpDestination(WARPDEST_NONE);
            SetWarpTimer(0);
        }

        if (pCollisionMode() == CMODE_FLOOR) {
            // Idle -> waiting -> "I'm outta here!" after ~177s (Sonic only).
            if (pTimer() < 240) {
                pAnimation() = ANI_STOPPED;
                pTimer()++;
            }
            else {
                pAnimation() = ANI_WAITING;
                if (playerListPos == PLAYER_SONIC_A) {
                    pTimer()++;
                    if (pTimer() == 10620) {
                        pTimer() = 0;
                        PlaySfx(SFX_G_OUTTAHERE, false);
                        pState()     = OuttaHereStateID();
                        pAnimation() = ANI_BORED;
                    }
                }
            }

            // Ledge balancing (a floor sensor is off the edge).
            if (pFloorSensorC() == false) {
                if (pFloorSensorR() == false) {
                    pTimer()     = 0;
                    pAnimation() = (pDirection() == FACING_LEFT) ? ANI_FLAILINGLEFT : ANI_FLAILINGRIGHT;
                }
                if (pFloorSensorL() == false) {
                    pTimer()     = 0;
                    pAnimation() = (pDirection() == FACING_RIGHT) ? ANI_FLAILINGLEFT : ANI_FLAILINGRIGHT;
                }
            }
        }
    }
    else {
        pTimer() = 0;
        // Speed>0 and Speed<0 are mirror images; helper keeps it faithful.
        int absSpeed = pSpeed() < 0 ? -pSpeed() : pSpeed();
        if (absSpeed < 0x5F5C2) {
            pAnimation() = ANI_WALKING;
            HandleWalkAnimSpeed();
            // Consume the warp + delete the warp star if you slow down in time.
            if (WarpDestination() > WARPDEST_NONE) {
                if (WarpTimer() > 99 && WarpTimer() < 204)
                    SetWarpDestination(WARPDEST_NONE);
                SetWarpTimer(0);
                objectEntityList[3].type = 0; // Object[3].Type = Blank Object
            }
        }
        else {
            // Fast enough to time-warp: spawn the warp stars.
            if (WarpDestination() > WARPDEST_NONE) {
                if (WarpTimer() == 0) {
                    SetWarpTimer(1);
                    SpawnWarpStar();
                }
            }
            if (absSpeed > 0x9FFFF)
                pAnimation() = ANI_PEELOUT;
            else
                pAnimation() = ANI_RUNNING;
            HandleRunAnimSpeed();
        }
    }

    // Skidding
    if (pSkidding() > 0) {
        if (skidSfxAllowed)
            PlaySfx(SFX_G_SKIDDING, false);
        pAnimation()      = ANI_SKIDDING;
        pAnimationSpeed() = 0;
        pSkidding()--;

        if (RingAniCount() == 0) {
            int tmp    = CreateTempObject(TypeNameID("DustPuff"), 0, pXPos(), pYPos());
            Entity *dp = &objectEntityList[tmp];
            dp->YPos   = ((dp->YPos >> 16) + pCollisionBottom()) << 16; // iYPos += CollisionBottom
            dp->drawOrder = pDrawOrder();
        }

        pDirection() = (pSpeed() > 0) ? FACING_RIGHT : FACING_LEFT;
    }

    // Pushing (a 1-frame delay means 2 is the "true" pushing state)
    if (pCollisionMode() == CMODE_FLOOR) {
        if (pPushing() == 2) {
            pAnimation()      = ANI_PUSHING;
            pAnimationSpeed() = 0;
        }
    }

    // Jump / Look Up / Crouch / Roll
    if (pJumpPress() == true) {
        Action_Jump();
    }
    else {
        if (pUp() == true) {
            if (pSpeed() == 0) {
                if (pAnimation() != ANI_FLAILINGLEFT && pAnimation() != ANI_FLAILINGRIGHT) {
                    pState()     = LookUpStateID();
                    pAnimation() = ANI_LOOKINGUP;
                    pTimer()     = 0;
                }
            }
        }

        if (pDown() == true) {
            if (pSpeed() == 0) {
                if (pAnimation() != ANI_FLAILINGLEFT && pAnimation() != ANI_FLAILINGRIGHT) {
                    pState()     = CrouchStateID();
                    pAnimation() = ANI_LOOKINGDOWN;
                    pTimer()     = 0;
                }
            }
            else {
                // Roll (only with no left/right held, above the roll threshold)
                if (pLeft() == false && pRight() == false) {
                    bool fast = pSpeed() > 0 ? (pSpeed() > 0x8800) : (pSpeed() < -0x8800);
                    if (fast) {
                        pState()     = RollStateID();
                        pAnimation() = ANI_JUMPING;
                        pYPos()      = ((pYPos() >> 16) - pJumpOffset()) << 16; // iYPos -= JumpOffset
                        pAbilityTimer() = 1024;
                    }
                }
            }
        }
    }
}

// ===========================================================================
//  function Player_State_Air  (standalone path)
// ===========================================================================
void O_Player::State_Air()
{
    HandleAirFriction();

    if (pGravity() == GRAVITY_AIR) {
        HandleAirMovement();

        // Warp: cancel it if you drift too far off the warp-run speed.
        if (WarpDestination() > WARPDEST_NONE) {
            int absY = pYVel() < 0 ? -pYVel() : pYVel();
            if (absY < 0x60000) {
                int absX = pXVel() < 0 ? -pXVel() : pXVel();
                if (absX < 0x60000) {
                    int dv = pXVel() - WarpSpeedCompare();
                    if (dv < 0)
                        dv = -dv;
                    if (dv > 0x40000) {
                        if (WarpTimer() > 99 && WarpTimer() < 204)
                            SetWarpDestination(WARPDEST_NONE);
                        SetWarpTimer(0);
                    }
                }
            }
            SetWarpSpeedCompare(pXVel());
        }

        // Falling fast enough: drop the ledge-balance anim back to walking.
        if (pYVel() > 0x20000) {
            if (pAnimation() == ANI_FLAILINGLEFT)
                pAnimation() = ANI_WALKING;
            if (pAnimation() == ANI_FLAILINGRIGHT)
                pAnimation() = ANI_WALKING;
        }

        // Coming down out of a spring bounce -> restore the reserved anim.
        if (pAnimation() == ANI_BOUNCING) {
            if (pYVel() >= 0) {
                if (pAnimationReserve() == ANI_STOPPED)
                    pAnimationReserve() = ANI_WALKING;
                pAnimation() = pAnimationReserve();
            }
        }

        // Coming down out of a hit -> restore the reserved anim.
        if (pAnimation() == ANI_HURT) {
            if (pYVel() >= 0) {
                if (pAnimationReserve() == ANI_STOPPED)
                    pAnimationReserve() = ANI_WALKING;
                pAnimation() = pAnimationReserve();
            }
        }

        // Jump ability (dynamic dispatch -> interpreter during the hybrid phase).
        if (pAnimation() == ANI_JUMPING)
            CallScriptFunction(pJumpAbility(), SUB_MAIN);
    }
    else {
        // Landed.
        pState() = GroundStateID();
        HandleOnGround();
        pSkidding() = 0;
    }
}

// ===========================================================================
//  function Player_State_Roll  (standalone path)
// ===========================================================================
void O_Player::State_Roll()
{
    HandleRollDeceleration();

    if (pGravity() == GRAVITY_AIR) {
        pState() = AirStateID();
        pTimer() = 0;
        HandleAirMovement();
    }
    else {
        HandleRollAnimSpeed();
        pAnimationSpeed() = pRollAnimationSpeed();

        int absSpeed = pSpeed() < 0 ? -pSpeed() : pSpeed();
        if (absSpeed < 0x5F5C2) {
            if (WarpDestination() > WARPDEST_NONE) {
                if (WarpTimer() > 99 && WarpTimer() < 204)
                    SetWarpDestination(WARPDEST_NONE);
                SetWarpTimer(0);
            }
        }
        else {
            if (WarpDestination() > WARPDEST_NONE) {
                if (WarpTimer() == 0) {
                    SetWarpTimer(1);
                    SpawnWarpStar();
                }
            }
        }

        HandleOnGround();

        if (pJumpPress() == true)
            Action_Jump();
    }
}

// ===========================================================================
//  function Player_State_LookUp
// ===========================================================================
void O_Player::State_LookUp()
{
    if (pUp() == false) {
        pState() = GroundStateID();
        pTimer() = 0;
    }
    else {
        if (pTimer() < 60)
            pTimer()++;
        else if (pLookPos() > -112)
            pLookPos() -= 2; // pan the camera up

        if (pGravity() == GRAVITY_AIR) {
            pState() = AirStateID();
            pTimer() = 0;
        }
        else if (pJumpPress() == true) {
            CallScriptFunction(pActionPeelout(), SUB_MAIN); // CD peelout (dynamic)
        }
    }
}

// ===========================================================================
//  function Player_State_Crouch
// ===========================================================================
void O_Player::State_Crouch()
{
    if (pDown() == false) {
        pState() = GroundStateID();
        pTimer() = 0;
    }
    else {
        if (pTimer() < 60)
            pTimer()++;
        else if (pLookPos() < 96)
            pLookPos() += 2; // pan the camera down

        if (pGravity() == GRAVITY_AIR) {
            pState() = AirStateID();
            pTimer() = 0;
        }
        else if (pJumpPress() == true) {
            CallScriptFunction(pActionSpindash(), SUB_MAIN); // CD spindash (dynamic)
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
