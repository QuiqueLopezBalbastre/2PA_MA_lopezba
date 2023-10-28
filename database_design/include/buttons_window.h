/**
 * @file buttons_window.cc
 * @author Enrique López (lopezba@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __BUTTONS_WINDOW_H__
#define __BUTTONS_WINDOW_H__ 1

struct GlobalData;

#include <esat/math.h>

/**
 * @brief Create GUI window with a button.
 * 
 * @param info A pointer to the GlobalData structure containing application information.
 */
void TopWindow(GlobalData *info);

/**
 * @brief Create a menu selection window for choosing different application options.
 * 
 * @param info A pointer to the GlobalData structure containing application information.
 */

void MenuSelectionWindow(GlobalData *info);

/**
 * @brief Create a window for selecting a database table.
 * 
 * @param info A pointer to the GlobalData structure containing application information.
 */
void TableSelectionWindow(GlobalData *info);

#endif