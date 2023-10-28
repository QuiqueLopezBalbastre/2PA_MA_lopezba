/**
 * @file query_window.cc
 * @author Federico Sanjuan (sanjuanbare@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __QUERY_WINDOW_H__
#define __QUERY_WINDOW_H__ 1

struct GlobalData;

#include <esat/math.h>

/**
 * @brief Execute a user-defined SQL query.
 *
 * @param info A pointer to the GlobalData structure containing application information, including the user-defined query.
 */
void ExecuteUserQuery(GlobalData *info);

/**
 * @brief Display the bottom user interface window for executing user-defined SQL queries.

 * @param info A pointer to the GlobalData structure containing application information, including the user-defined query.
 */
void BottomWindow(GlobalData *info);

#endif