#ifndef __PLAYER__
#define __PLAYER__ 1

#include "variables.h"

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