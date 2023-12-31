#include "transform.h"

#include <esat/math.h>
#include <esat/draw.h>

#include "game_data.h"


void TransformAndDraw(GameData game_data, esat::Vec2 position, esat::Vec2 scale, int row){

    esat::Mat3 m = esat::Mat3Identity();
    m = esat::Mat3Multiply(esat::Mat3Scale(scale.x, scale.y), m);
    m = esat::Mat3Multiply(esat::Mat3Translate(position.x, position.y), m);

    for(int k = 0; k < kNum_points_brick; ++k){
        esat::Vec3 p = {game_data.brick_points[k * 2], game_data.brick_points[k * 2 + 1], 1.0f};
        esat::Vec3 result = Mat3TransformVec3(m, p);
        game_data.transformed_brick[k * 2] = result.x;
        game_data.transformed_brick[k * 2 + 1] = result.y;
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

    esat::DrawSolidPath(game_data.transformed_brick, kNum_points_brick);
}
