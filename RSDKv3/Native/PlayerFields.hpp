#ifndef NATIVE_PLAYER_FIELDS_H
#define NATIVE_PLAYER_FIELDS_H

// =============================================================================
//  Player field accessors  (for the active player, playerList[activePlayer])
// -----------------------------------------------------------------------------
//  Named lvalue accessors so ported player code reads like the script's
//  `Player.Xxx`. Return types match the real storage (some fields are `byte` on
//  the Player struct / bound entity, some `int`) — verified against the
//  VAR_PLAYER* table in Script.cpp. The Value0..15 split is handled by
//  Native::PlayerValue() (Value0..7 -> bound entity, Value8..15 -> Player struct).
// =============================================================================

#if RETRO_USE_NATIVE_OBJECTS

namespace Native
{
// --- Player struct, int fields ---
inline int &pXPos() { return playerList[activePlayer].XPos; }
inline int &pYPos() { return playerList[activePlayer].YPos; }
inline int &pSpeed() { return playerList[activePlayer].speed; }
inline int &pXVel() { return playerList[activePlayer].XVelocity; }
inline int &pYVel() { return playerList[activePlayer].YVelocity; }
inline int &pAngle() { return playerList[activePlayer].angle; }
inline int &pTimer() { return playerList[activePlayer].timer; }
inline int &pLookPos() { return playerList[activePlayer].lookPos; }
inline int &pTopSpeed() { return playerList[activePlayer].topSpeed; }
inline int &pAccel() { return playerList[activePlayer].acceleration; }
inline int &pDecel() { return playerList[activePlayer].deceleration; }
inline int &pAirAccel() { return playerList[activePlayer].airAcceleration; }
inline int &pAirDecel() { return playerList[activePlayer].airDeceleration; }
inline int &pGravityStrength() { return playerList[activePlayer].gravityStrength; }
inline int &pJumpStrength() { return playerList[activePlayer].jumpStrength; }
inline int &pJumpCap() { return playerList[activePlayer].jumpCap; }
inline int &pRollingAccel() { return playerList[activePlayer].rollingAcceleration; }
inline int &pRollingDecel() { return playerList[activePlayer].rollingDeceleration; }
inline int &pScreenXPos() { return playerList[activePlayer].screenXPos; }
inline int &pScreenYPos() { return playerList[activePlayer].screenYPos; }

// --- Player struct, byte fields (inputs & flags) ---
inline byte &pCollisionMode() { return playerList[activePlayer].collisionMode; }
inline byte &pCollisionPlane() { return playerList[activePlayer].collisionPlane; }
inline byte &pSkidding() { return playerList[activePlayer].skidding; }
inline byte &pPushing() { return playerList[activePlayer].pushing; }
inline byte &pControlLock() { return playerList[activePlayer].controlLock; }
inline byte &pGravity() { return playerList[activePlayer].gravity; }
inline byte &pWater() { return playerList[activePlayer].water; }
inline byte &pVisible() { return playerList[activePlayer].visible; }
inline byte &pTileCollisions() { return playerList[activePlayer].tileCollisions; }
inline byte &pObjectInteractions() { return playerList[activePlayer].objectInteractions; }
inline byte &pTrackScroll() { return playerList[activePlayer].trackScroll; }
inline byte &pLeft() { return playerList[activePlayer].left; }
inline byte &pRight() { return playerList[activePlayer].right; }
inline byte &pUp() { return playerList[activePlayer].up; }
inline byte &pDown() { return playerList[activePlayer].down; }
inline byte &pJumpPress() { return playerList[activePlayer].jumpPress; }
inline byte &pJumpHold() { return playerList[activePlayer].jumpHold; }
inline sbyte &pControlMode() { return playerList[activePlayer].controlMode; }

// --- Bound-entity fields (state/animation/direction live here, not on Player) ---
inline byte &pState() { return playerList[activePlayer].boundEntity->state; }
inline byte &pDirection() { return playerList[activePlayer].boundEntity->direction; }
inline byte &pAnimation() { return playerList[activePlayer].boundEntity->animation; }
inline byte &pPrevAnimation() { return playerList[activePlayer].boundEntity->prevAnimation; }
inline byte &pFrame() { return playerList[activePlayer].boundEntity->frame; }
inline int &pAnimationSpeed() { return playerList[activePlayer].boundEntity->animationSpeed; }
inline int &pAnimationTimer() { return playerList[activePlayer].boundEntity->animationTimer; }
inline int &pRotation() { return playerList[activePlayer].boundEntity->rotation; }
inline byte &pDrawOrder() { return playerList[activePlayer].boundEntity->drawOrder; }

// Floor sensors (Player.Flailing[0..2] = FloorSensorL/C/R).
inline byte &pFloorSensorL() { return playerList[activePlayer].flailing[0]; }
inline byte &pFloorSensorC() { return playerList[activePlayer].flailing[1]; }
inline byte &pFloorSensorR() { return playerList[activePlayer].flailing[2]; }

// --- Named Value aliases (from PlayerObject.txt #alias header) ---
inline int &pRings() { return PlayerValue(0); }
inline int &pAbilityTimer() { return PlayerValue(1); }
inline int &pRollAnimationSpeed() { return PlayerValue(2); }
inline int &pSpeedShoesTimer() { return PlayerValue(3); }
inline int &pInvincibleTimer() { return PlayerValue(4); }
inline int &pBlinkTimer() { return PlayerValue(5); }
inline int &pMinRollSpeed() { return PlayerValue(6); }
inline int &pAnimationReserve() { return PlayerValue(7); }
inline int &pScrollDelay() { return PlayerValue(8); }
inline int &pJumpOffset() { return PlayerValue(9); }
inline int &pJumpAbility() { return PlayerValue(10); }
inline int &pActionPeelout() { return PlayerValue(11); }
inline int &pActionSpindash() { return PlayerValue(12); }
inline int &pForceGrounded() { return PlayerValue(13); }
inline int &pDropDashCharge() { return PlayerValue(14); }
inline int &pFlightVelocity() { return PlayerValue(15); }

// --- Player.CollisionTop/Bottom/Left/Right ---
// Read the current animation frame's hitbox (mirrors VAR_PLAYERCOLLISION* in
// Script.cpp): frame -> hitboxID -> hitboxList entry, edge[0]. Read-only.
inline Hitbox *pCurrentHitbox()
{
    AnimationFile *animFile = playerList[activePlayer].animationFile;
    if (!animFile)
        return nullptr;
    Entity *e = playerList[activePlayer].boundEntity;
    int h     = animFrames[animationList[animFile->aniListOffset + e->animation].frameListOffset + e->frame].hitboxID;
    return &hitboxList[animFile->hitboxListOffset + h];
}
inline int pCollisionTop()
{
    Hitbox *hb = pCurrentHitbox();
    return hb ? hb->top[0] : 0;
}
inline int pCollisionBottom()
{
    Hitbox *hb = pCurrentHitbox();
    return hb ? hb->bottom[0] : 0;
}
inline int pCollisionLeft()
{
    Hitbox *hb = pCurrentHitbox();
    return hb ? hb->left[0] : 0;
}
inline int pCollisionRight()
{
    Hitbox *hb = pCurrentHitbox();
    return hb ? hb->right[0] : 0;
}
} // namespace Native

#endif // RETRO_USE_NATIVE_OBJECTS
#endif // !NATIVE_PLAYER_FIELDS_H
