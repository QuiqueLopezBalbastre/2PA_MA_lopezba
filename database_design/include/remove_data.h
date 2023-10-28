/**
 * @file remove_data.cc
 * @author Enrique López (lopezba@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __REMOVE_DATA_H__
#define __REMOVE_DATA_H__ 1

#include "global_data.h"

/**
 * @brief Remove data from the selected database table through a GUI.
 *
 * This function allows users to specify an ID and remove a tuple from the selected database table (e.g., Employee,
 * Company, City, or Country) by clicking the "Remove tuple" button. The data removal is performed using SQL queries,
 * and the updated table is displayed afterward.
 *
 * @param info A pointer to the GlobalData structure containing application information, including the table selection and ID.
 *
 * @return An integer status code (always 0 in this implementation).
 */
int RemoveData(GlobalData *info);

#endif