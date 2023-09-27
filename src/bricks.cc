#include <esat/draw.h>

#include "../include/variables.h"
#include "../include/bricks.h"
#include "../include/collisions.h"

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

void TransformAndDraw(float posX, float posY, float scaleX, float scaleY, int row){

    esat::Mat3 m = esat::Mat3Identity();
    m = esat::Mat3Multiply(esat::Mat3Scale(scaleX, scaleY), m);
    m = esat::Mat3Multiply(esat::Mat3Translate(posX, posY), m);

    for(int k = 0; k < kNumPointsBrick; ++k){
        esat::Vec3 p = {brick_points[k * 2], brick_points[k * 2 + 1], 1.0f};
        esat::Vec3 result = Mat3TransformVec3(m, p);
        transformed_brick[k * 2] = result.x;
        transformed_brick[k * 2 + 1] = result.y;
    }

    switch(row){
        case 0: esat::DrawSetFillColor(255, 0, 0); break;
        case 1: esat::DrawSetFillColor(255, 0, 0); break;

        case 2: esat::DrawSetFillColor(255, 165, 0); break;
        case 3: esat::DrawSetFillColor(255, 165, 0); break;

        case 4: esat::DrawSetFillColor(255, 255, 0); break;
        case 5: esat::DrawSetFillColor(255, 255, 0); break;

        case 6: esat::DrawSetFillColor(0, 255, 0); break;
        case 7: esat::DrawSetFillColor(0, 255, 0); break;
    }

    esat::DrawSolidPath(transformed_brick, kNumPointsBrick);
}

void DrawBrick(TBrick brick[8][11]){

    for(int i=0; i<kBrick_cols; ++i){
        for(int j=0; j<kBrick_rows; ++j){

            if(brick[i][j].active){
                int row = i;
                TransformAndDraw(brick[i][j].position.x, brick[i][j].position.y, brick[i][j].scale.x, brick[i][j].scale.y, row);
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
