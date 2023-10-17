#include <stdio.h>
#include <stdlib.h>

#include <esat/input.h>
#include <esat/draw.h>
#include <esat/math.h>

#include "player.h"
#include "collisions.h"
//#include "variables.cc"

TPlayer InitPlayer() {
    TPlayer temp_player;
    temp_player = {{kWindowWidth * 0.5f, kWindowHeight * 0.9f}, {15.0f, 15.0f}, {50.0f, 50.0f}};
    temp_player.points = (esat::Vec2 *)malloc(6 * sizeof(esat::Vec2));
    temp_player.world_points = (esat::Vec2 *)malloc(6 * sizeof(esat::Vec2));
    *(temp_player.points + 0) = {-1.0f, 0.0f};
    *(temp_player.points + 1) = {-0.5f, -0.25f};
    *(temp_player.points + 2) = {0.5f, -0.25f};
    *(temp_player.points + 3) = {1.0f, 0.0f};
    *(temp_player.points + 4) = {0.5f, 0.25f};
    *(temp_player.points + 5) = {-0.5f, 0.25f};
    return temp_player;
}

void PlayerMovement(TPlayer *player)
{

    BallPlayerCollision(&g_ball, player);

    // Screen's limits check
    if (player->position.x + player->scale.x * 0.5f < kWindowWidth && player->position.x - player->scale.x * 0.5f > 0)
    {
        // *(player) movement
        if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Right))
        {
            player->position.x += player->speed.x;
        }
        if (esat::IsSpecialKeyPressed(esat::kSpecialKey_Left))
        {
            player->position.x -= player->speed.x;
        }
    }
    else
    {
        if (player->position.x + player->scale.x * 0.5f >= kWindowWidth)
        {
            player->position.x -= player->speed.x;
        }
        if (player->position.x - player->scale.x * 0.5f <= 0)
        {
            player->position.x += player->speed.x;
        }
    }
}

void DrawPlayer(TPlayer player)
{
    esat::Mat3 m = esat::Mat3Identity();
    m = esat::Mat3Multiply(esat::Mat3Scale(player.scale.x, player.scale.y), m);
    m = esat::Mat3Multiply(esat::Mat3Translate(player.position.x, player.position.y), m);

    for (int i = 0; i < 6; i++)
    {
        esat::Vec2 temp = esat::Mat3TransformVec2(m, *(player.points + i));
        *(player.world_points + i) = temp;
    }

    esat::DrawSetStrokeColor(255, 255, 255, 255);
    esat::DrawSolidPath(&(player.world_points + 0)->x, 6);
}
