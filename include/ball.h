#ifndef BALL
#define BALL

#include "variables.h"

void InitShapeCoords(float *circle);
void TransformAndDraw(const float *shape_coords, float scaleX, float scaleY, float posX, float posY);
void InitBall();
void DrawBall(TBall ball);
void UpdateBall(TBall *ball);


#endif