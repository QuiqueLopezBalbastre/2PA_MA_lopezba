/**
 * @file count_rows.cc
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
 * @brief Reads and processes data from a database result row.
 *
 * This function is used to extract and process data from a single row
 * of a database query result.
 *
 * @param data A pointer to an integer variable where the extracted data will be stored.
 * @param argc The number of columns in the result row.
 * @param field_values An array of character pointers containing the field values for each column.
 * @param colNames An array of character pointers containing the column names.
 *
 * @return 0 if the data is successfully read and stored in the 'data' variable, otherwise an error code.
 */
int ReadRows(void *data, int argc, char **field_values, char **colNames);

/**
 * @brief Queries a SQLite database for the number of rows in specific tables.
 *
 * This function executes SQL queries to count the number of rows in different tables
 * of a SQLite database and stores the results in a global data structure.
 *
 * @param info A pointer to a 'GlobalData' structure where the row counts are stored.
 * @param table_identifier An integer value representing the table to query.
 *
 */
void ShowRows(GlobalData* info, int table_identifier);

#endif