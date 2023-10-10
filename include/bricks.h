/**
 * @file bricks.h
 * @author Sergio Madaleno (madalenofi@esat-alumni.com)
 * @brief Bricks data structure & method definition
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __BRICKS_H_
#define __BRICKS_H__ 1

#include "variables.h"

struct TBrick
{
    esat::Vec2 position, scale;
    bool active;
    int hp;
};

/**
 * @brief Initializes brick array to default values.
 */
void InitBrick();


/**
 * @brief Updates transform propierties of an element
 *
 * Updates transform propierties of an element and draws it with a graphic library.
 *
 * @param posX Component x of the position propierty
 * @param posY Component y of the position propierty
 * @param scaleX Component x of the scale propierty
 * @param scaleY Component y of the scale propierty
 * @param row Component x of the position propierty
 */



/**
 * @brief Draws bricks from a Brick array.
 * 
 * @param brick array of bricks that are being painted.
 */
void DrawBrick(TBrick brick[8][11]);


/**
 * @brief Checks if there has been a collision between a brick and the ball
 * 
 * @param brick 
 */
void UpdateBrick(TBrick brick[8][11]);

#endif