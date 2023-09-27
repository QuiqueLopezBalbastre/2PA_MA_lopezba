#ifndef BRICKS
#define BRICKS

#include "variables.h"

void InitBrick();
void TransformAndDraw(float posX, float posY, float scaleX, float scaleY, int row);
void DrawBrick(TBrick brick[8][11]);
void UpdateBrick(TBrick brick[8][11]);

#endif