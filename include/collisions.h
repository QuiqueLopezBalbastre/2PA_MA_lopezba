#ifndef COLLISIONS
#define COLLISIONS

#include "variables.h"

bool BoxCollision(esat::Vec2 a, esat::Vec2 a_size, esat::Vec2 b, esat::Vec2 b_size);
float GetAngle(esat::Vec2 centervec);
void BrickCollision(TBrick *brick, TBall *ball);
void BallPlayerCollision(TBall *ball, TPlayer *player);

#endif