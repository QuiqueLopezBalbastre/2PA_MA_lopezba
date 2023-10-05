#ifndef BALL
#define BALL

#include "variables.h"

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
void InitBall();
/**
 * @brief Draws with the graphic library the ball
 * 
 * @param ball 
 */
void DrawBall(TBall ball);

/**
 * @brief Checks if there have been a collision with any of the windows borders.
 * 
 * @param ball 
 */
void UpdateBall(TBall *ball);


#endif