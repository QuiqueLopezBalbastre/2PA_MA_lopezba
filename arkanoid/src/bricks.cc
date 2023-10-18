#include <esat/draw.h>
#include <esat/math.h>

#include "bricks.h"
#include "collisions.h"
#include "transform.h"
// #include "game_data.h"


void InitBrick(GameData* info)
{
    float initialX=175.0f, initialY = 120.0f;
    float brickWidth = 40, brickHeight = 30;
    int spacingX = 45, spacingY = 5;

    for (int i = 0; i < kBrick_cols; ++i)
    {
        for (int j = 0; j < kBrick_rows; ++j)
        {
            info->brick[i][j].position.x = initialX + j * (brickWidth + spacingX);
            info->brick[i][j].position.y = initialY + i * (brickHeight + spacingY);
            info->brick[i][j].scale.x = brickWidth;
            info->brick[i][j].scale.y = brickHeight;
            info->brick[i][j].active = true;
            info->brick[i][j].hp = 1;
        }
    }
}

void DrawBrick(GameData info){

    for(int i=0; i<kBrick_cols; ++i){
        for(int j=0; j<kBrick_rows; ++j){

            if(info.brick[i][j].active){
                TransformAndDraw(info, info.brick[i][j].position, info.brick[i][j].scale, i);
            }
        }
    }
}

void UpdateBrick(GameData *info){

    for(int i=0; i<kBrick_cols; ++i){
        for(int j=0; j<kBrick_rows; ++j){

            BrickCollision(&info->brick[i][j], &info->ball);
        }
    }
}
