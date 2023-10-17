#include <stdio.h>
#include <math.h>
#include "collisions.h"

bool BoxCollision(esat::Vec2 a, esat::Vec2 a_size, esat::Vec2 b, esat::Vec2 b_size){

    if(a.x + a_size.x > b.x - b_size.x && 
        a.x - a_size.x < b.x + b_size.x && 
        a.y + a_size.y > b.y - b_size.y && 
        a.y - a_size.y < b.y + b_size.y){
        return true;
    }else{
        return false;
    }
}

float GetAngle(esat::Vec2 centervec)
{
    float radians = (float)atan2(centervec.y, centervec.x);
    float degrees = radians * 180 / 3.1416f;
    return degrees;
}

void BrickCollision(TBrick *brick, TBall *ball)
{
    if (BoxCollision(brick->position,  /*brick->scale*/{brick->scale.x * 0.5f, brick->scale.y * 0.5f}, {ball->position.x + ball->scale.x, ball->position.y + ball->scale.y}, /*{ball->scale.x * 0.5f, ball->scale.y * 0.5f}*/ ball->scale) && brick->active)
    {
        brick->active = false;
        float degree = GetAngle({ball->position.x - brick->position.x, ball->position.y - brick->position.y});
        // printf("Degrees: %.0f\n", GetAngle({ball->position.x - brick->position.x, ball->position.y - brick->position.y}));
        if (degree > 45.0f && degree < 135.0f)
        {
            // Abajo
            ball->direction.y = 1.0f;
        }
        else if (degree > 135.0f || degree < -135.0f)
        {
            // Izquierda
            ball->direction.x = -1.0f;
        }
        else if (degree > -45.0f && degree < 45.0f)
        {
            // Derecha
            ball->direction.x = 1.0f;
        }
        else if (degree > -135.0f && degree < -45.0f)
        {
            // Äbajo
            ball->direction.y = -1.0f;
        }
    }
}

void BallPlayerCollision(TBall *ball, TPlayer *player){
    if(BoxCollision(ball->position, {ball->scale.x, ball->scale.y - 35}, player->position, player->scale)) {
        ball->speed.y *= -1;
    }
}