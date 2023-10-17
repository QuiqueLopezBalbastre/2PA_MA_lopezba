#include <esat/math.h>
#include <esat/draw.h>

#include <stdlib.h>
#include <math.h>

#include "ball.h"
#include "variables.cc"

void InitShapeCoords(float *circle)
{
    double portion = PI * 2 / num_ball_points;
    for (int i = 0; i < num_ball_points; ++i)
    {
        circle[i * 2] = cos(portion * i);
        circle[i * 2 + 1] = sin(portion * i);
    }
}

void TransformAndDraw(const float *shape_coords, float scaleX, float scaleY, float posX, float posY)
{

    esat::Mat3 m = esat::Mat3Identity();
    m = esat::Mat3Multiply(esat::Mat3Scale(scaleX, scaleY), m);
    m = esat::Mat3Multiply(esat::Mat3Translate(posX, posY), m);

    for (int i = 0; i < num_ball_points; ++i)
    {
        esat::Vec3 p = {shape_coords[i * 2], shape_coords[i * 2 + 1], 1.0f};
        esat::Vec3 result = esat::Mat3TransformVec3(m, p);
        transformed_coords[i * 2] = result.x;
        transformed_coords[i * 2 + 1] = result.y;
    }

    esat::DrawSetStrokeColor(255, 255, 255);
    esat::DrawSetFillColor(255, 255, 255);
    esat::DrawSolidPath(transformed_coords, num_ball_points, true);
    esat::DrawSetFillColor(255, 255, 255, 0);
}

void InitBall()
{

    int randDir = rand() % 2;

    g_ball.position.x = kWindowWidth / 2;
    g_ball.position.y = kWindowHeight / 2 + 10;
    g_ball.speed.x = 2;
    g_ball.speed.y = 2;
    g_ball.active = true;
    g_ball.scale.x = 12;
    g_ball.scale.y = 12;
    g_ball.direction.x = RightUp.x;
    g_ball.direction.y = RightUp.y;
    g_ball.initial_direction = randDir;

    InitShapeCoords(ball_coords);
}

void DrawBall(TBall ball)
{

    if (ball.active)
    {
        TransformAndDraw(ball_coords, ball.scale.x, ball.scale.y, ball.position.x, ball.position.y);
    }
}

void UpdateBall(TBall *ball)
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

    if (ball->position.y - ball->scale.y < 0 || ball->position.y + ball->scale.y > kWindowHeight)
    {
        ball->speed.y *= -1;
    }

    if (ball->position.x - ball->scale.y < 0 || ball->position.x + ball->scale.y > kWindowWidth)
    {
        ball->speed.x *= -1;
    }

    if (ball->position.y > kWindowHeight - 50)
    {
        InitBall();
        InitBrick();
    }
}
