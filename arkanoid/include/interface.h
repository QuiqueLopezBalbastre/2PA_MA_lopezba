/**
 * @file interface.h
 * @author Sergio Madaleno (madalenofi@domain.com)
 * @brief Interface methods definitions
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __INTERFACE_H__
#define __INTERFACE_H__ 1

struct GameData;
/**
 * @brief Main Menu created with imgui.
 *
 * @param game_data 
 */
void MainMenu(GameData* game_data);

#endif 