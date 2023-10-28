/**
 * @file countrows.cc
 * @author Fede Sanjuan Barea (sanjuanbare@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __COUNT_ROWS_H__
#define __COUNT_ROWS_H__ 1

struct GlobalData;

/**
 * @brief Insert data into the selected database table.
 *
 * This function displays a GUI form that allows the user to input data for a specific database table,
 * such as Employee, Company, City, or Country. After entering the data and clicking the "Insert" button,
 * the data is inserted into the chosen table using a SQL query.
 *
 * @param info A pointer to the GlobalData structure containing application information.
 */


void ShowFile(GlobalData* info,int i);
int Readrow(void *data, int argc, char **field_values, char **colNames);

#endif