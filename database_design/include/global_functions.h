/**
 * @file global_functions.cc
 * @author Sergio Madaleno (madalenofi@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __GLOBAL_FUNCTIONS_H__
#define __GLOBAL_FUNCTIONS_H__ 1

#include <esat_extra/imgui.h>

/**
 * @brief Logs an error message to a buffer.
 *
 * @param errorMessage The error message to log.
 */
void LogError(const char* errorMessage);

/**
 * @brief Displays an error window with error messages.
 */
void ShowErrorWindow();

/**
 * @brief Execute a SQL query on a SQLite database.
 *
 * This function opens a SQLite database file, executes a SQL query provided as input, and handles any potential errors.
 * It is responsible for executing SQL queries on the specified database and printing error messages to the standard error stream.
 *
 * @param sql A null-terminated string containing the SQL query to be executed.
 */
void ExecuteSQL(const char *sql);

/**
 * @brief Create a GUI window with specified position and size.
 *
 * @param name The name or title of the GUI window.
 * @param pos The position of the top-left corner of the window.
 * @param size The dimensions of the window.
 */
void CreateWindow(const char *name, ImVec2 pos, ImVec2 size);

/**
 * @brief Close the currently open GUI window.
 */
void CloseWindow();



#endif