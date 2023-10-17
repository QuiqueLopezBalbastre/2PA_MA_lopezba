#include <esat/math.h>
#include <esat/draw.h>

#include <stdlib.h>
#include <math.h>

#include "ball.h"
#include "game_data.h"

void InitShapeCoords(float *circle)
{
    double portion = PI * 2 / kNum_ball_points;
    for (int i = 0; i < kNum_ball_points; ++i)
    {
        circle[i * 2] = cos(portion * i);
        circle[i * 2 + 1] = sin(portion * i);
    }
}

void TransformAndDraw(const float *shape_coords, float scaleX, float scaleY, float posX, float posY, GameData info)
{

    esat::Mat3 m = esat::Mat3Identity();
    m = esat::Mat3Multiply(esat::Mat3Scale(scaleX, scaleY), m);
    m = esat::Mat3Multiply(esat::Mat3Translate(posX, posY), m);

    for (int i = 0; i < kNum_ball_points; ++i)
    {
        esat::Vec3 p = {shape_coords[i * 2], shape_coords[i * 2 + 1], 1.0f};
        esat::Vec3 result = esat::Mat3TransformVec3(m, p);
        info.transformed_coords[i * 2] = result.x;
        info.transformed_coords[i * 2 + 1] = result.y;
    }

    esat::DrawSetStrokeColor(255, 255, 255);
    esat::DrawSetFillColor(255, 255, 255);
    esat::DrawSolidPath(info.transformed_coords, kNum_ball_points, true);
    esat::DrawSetFillColor(255, 255, 255, 0);
}

void InitBall(GameData* info)
{
    int randDir = rand() % 2;

    info->ball.position.x = kWindow_width / 2;
    info->ball.position.y = kWindow_height / 2 + 10;
    info->ball.speed.x = 2;
    info->ball.speed.y = 2;
    info->ball.active = true;
    info->ball.scale.x = 12;
    info->ball.scale.y = 12;
    info->ball.direction.x = info->right_up.x;
    info->ball.direction.y = info->right_up.x;
    info->ball.initial_direction = randDir;

    InitShapeCoords(info->ball_coords);
}


void DrawBall(GameData info)
{

    if (info.ball.active)
    {
        TransformAndDraw(info.ball_coords, info.ball.scale.x, info.ball.scale.y, info.ball.position.x, info.ball.position.y, info);
    }
}

void UpdateBall(TBall* ball)
{

    switch (ball->initial_direction)
    {
    case 0:
        ball->position.x += ball->speed.x * ball->direction.x;
        ball->position.y -= ball->speed.y * ball->direction.y;
        break;

    case 1:
        ball->position.x -= ball->speed.x * ball->direction.x;
        ball->position.y -= ball->speed.y * ball->direction.y;
        break;
    }

    if (ball->position.y - ball->scale.y < 0 || ball->position.y + ball->scale.y > kWindow_height)
    {
        ball->speed.y *= -1;
    }

    if (ball->position.x - ball->scale.y < 0 || ball->position.x + ball->scale.y > kWindow_width)
    {
        ball->speed.x *= -1;
    }

    if (ball->position.y > kWindow_height - 50)
    {
        //InitBall();
        //InitBrick();
    }
}
