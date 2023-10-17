/**
 * @file player.h
 * @author Quique López (lopezba@esat-alumni.com)
 * @brief Player data structure & methods definitions
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __PLAYER_H__
#define __PLAYER_H__ 1

#include <esat/math.h>

struct TPlayer {
    esat::Vec2 position, speed, scale;
    esat::Vec2 *points, *world_points;
};

#include "game_data.h"

/**
 * @brief Set a player variable to a default parameters.
 * 
 * @return TPlayer Player variable set to default parameters.
 */
TPlayer InitPlayer();

/**
 * @brief Controls the movement of the player
 * 
 * @param player 
 */
void PlayerMovement(TPlayer *player);

/**
 * @brief Draws the player
 * 
 * @param player 
 */
void DrawPlayer(TPlayer player);

#endif
