#ifndef COLLISIONS
#define COLLISIONS

#include "variables.h"

/**
 * @brief Collision between two 2D squares
 * 
 * @param a First square
 * @param a_size Size of x & y of the first square 
 * @param b Second square
 * @param b_size Size of x & y of the second square 
 * @return true There have been a collision between both squares
 * @return false There have not been a collision between both squares
 */
bool BoxCollision(esat::Vec2 a, esat::Vec2 a_size, esat::Vec2 b, esat::Vec2 b_size);

/**
 * @brief Get the Angle of the collision of the ball with the center of the brick.
 * 
 * @param centervec Center of the figure (brick)
 * @return float Degrees of the angle
 */
float GetAngle(esat::Vec2 centervec);
/**
 * @brief Collsion between the ball and a brick
 * 
 * @param brick 
 * @param ball 
 */
void BrickCollision(TBrick *brick, TBall *ball);
/**
 * @brief Collision between the ball and the player
 * 
 * Collision between the ball and the player allowing the rebound to send the ball up again.
 * 
 * @param ball 
 * @param player 
 */
void BallPlayerCollision(TBall *ball, TPlayer *player);

#endif