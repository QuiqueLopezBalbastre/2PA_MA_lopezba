#include <esat/draw.h>

#include "../include/variables.h"
#include "../include/bricks.h"
#include "../include/collisions.h"
#include "../include/transform.h"

void InitBrick()
{
    float initialX=175.0f, initialY = 120.0f;
    int brickWidth = 40, brickHeight = 30;
    int spacingX = 45, spacingY = 5;

    for (int i = 0; i < kBrick_cols; ++i)
    {
        for (int j = 0; j < kBrick_rows; ++j)
        {
            g_brick[i][j].position.x = initialX + j * (brickWidth + spacingX);
            g_brick[i][j].position.y = initialY + i * (brickHeight + spacingY);
            g_brick[i][j].scale.x = brickWidth;
            g_brick[i][j].scale.y = brickHeight;
            g_brick[i][j].active = true;
            g_brick[i][j].hp = 1;
        }
    }
}

void DrawBrick(TBrick brick[8][11]){

    for(int i=0; i<kBrick_cols; ++i){
        for(int j=0; j<kBrick_rows; ++j){

            if(brick[i][j].active){
                int row = i;
                TransformAndDraw(brick[i][j].position, brick[i][j].scale, row);
            }
        }
    }
}

void UpdateBrick(TBrick brick[8][11]){

    for(int i=0; i<kBrick_cols; ++i){
        for(int j=0; j<kBrick_rows; ++j){

            BrickCollision(&brick[i][j], &g_ball);
        }
    }
}
