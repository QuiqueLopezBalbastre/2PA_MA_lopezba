/**
 * @file transform.h
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
struct GameData;

struct Transform {
    esat::Vec2 position;
    esat::Vec2 scale; 
    esat::Vec2 origin;
    float rotation;
};

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
void TransformAndDraw(GameData info, esat::Vec2 position, esat::Vec2 scale, int row);

#endif
