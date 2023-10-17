/**
 * @file ball.h
 * @author Quique López (lopezba@esat-alumni.com)
 * @brief Ball data structure & method definition
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __BALL_H__
#define __BALL_H__ 1


struct TBall
{
    esat::Vec2 position, speed, scale, direction;
    bool active;
    int initial_direction;
};

// #include "game_data.h"
struct GameData;

/**
 * @brief Initialize the drawing points of the ball. 
 * 
 * @param circle Array where the drawing points will be stored.
 */
void InitShapeCoords(float *circle);

void TransformAndDraw(const float *shape_coords, float scaleX, float scaleY, float posX, float posY);


/**
 * @brief Initializes the ball transform propierties to default
 */
void InitBall(GameData* info);


/**
 * @brief Draws with the graphic library the ball
 * 
 * @param ball 
 */
void DrawBall(GameData info);


/**
 * @brief Checks if there have been a collision with any of the windows borders.
 * 
 * @param ball 
 */
void UpdateBall(TBall* ball);


#endif