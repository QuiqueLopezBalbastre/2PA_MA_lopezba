/**
 * @file transform.cc
 * @author Sergio Madaleno (madalenofi@esat-alumni.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__ 1

#include <esat/math.h>

struct Transform
{
    esat::Vec2 position;
    esat::Vec2 scale; 
    esat::Vec2 origin;
    float rotation;
};

void TransformAndDraw(esat::Vec2 position, esat::Vec2 scale, int row);

#endif