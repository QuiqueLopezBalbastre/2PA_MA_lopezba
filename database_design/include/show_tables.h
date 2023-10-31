/**
 * @file show_tables.cc
 * @author Federico Sanjuan (sanjuanbare@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __SHOW_TABLES_H__
#define __SHOW_TABLES_H__ 1

struct GlobalData;

struct TableEmployee
{
    int id;
    char name[40];
    char surname[40];
    char address[40];
    int company;
    int city;
    int nacionality;
    int salary;
    int rows;
};

struct TableCompany
{
    int id;
    char name[40];
    char country[40];
    int rows;
};

struct TableCity
{
    int id;
    char name[40];
    char country[40];
    int rows;
};

struct TableCountry
{
    int id;
    char name[40];
    int rows;
};

/**
 * @brief Initialize a database table by resetting its contents.
 *
 * @param id An integer representing the type of the database table to initialize (e.g., Employee, Company, City, or Country).
 */
void InitTable(GlobalData *info, int table_identifier);

/**
 * @brief Callback function for processing database results and populating the Employee table.
 *
 * This callback function is designed to process database query results and populate the Employee table
 * with the retrieved data. It iterates through the results, extracts relevant information, and stores it
 * in the provided data structure. The function also handles GUI rendering to display
 * the retrieved data in a table format.
 *
 * @param data A pointer to the data structure for storing the Employee table.
 * @param argc The number of columns in the query result.
 * @param field_values An array of field values from the query result.
 * @param colNames An array of column names from the query result.
 *
 * @return An integer status code (always 0 in this implementation).
 */
static int TableEmployeeCallback(void *data, int argc, char **argv, char **colNames);

/**
 * @brief Callback function for processing database results and populating the Company table.
 *
 * @param data A pointer to the data structure for storing the Company table.
 * @param argc The number of columns in the query result.
 * @param field_values An array of field values from the query result.
 * @param colNames An array of column names from the query result.
 *
 * @return An integer status code (always 0 in this implementation).
 */
static int TableCompanyCallback(void *data, int argc, char **field_values, char **colNames);

/**
 * @brief Callback function for processing database results and populating the City table.
 *
 * @param data A pointer to the data structure for storing the City table.
 * @param argc The number of columns in the query result.
 * @param field_values An array of field values from the query result.
 * @param colNames An array of column names from the query result.
 *
 * @return An integer status code (always 0 in this implementation).
 */
static int TableCityCallback(void *data, int argc, char **field_values, char **colNames);

/**
 * @brief Callback function for processing database results and populating the Country table.
 *
 * @param data A pointer to the data structure for storing the Country table.
 * @param argc The number of columns in the query result.
 * @param field_values An array of field values from the query result.
 * @param colNames An array of column names from the query result.
 *
 * @return An integer status code (always 0 in this implementation).
 */
static int TableCountryCallback(void *data, int argc, char **field_values, char **colNames);

/**
 * @brief Callback function for displaying the structure of a database table.
 *
 * This callback function is designed to display the structure of a database table, including column names
 * and their corresponding attributes. It is primarily used for rendering the database table structure within
 * the graphical user interface using the ImGui library.
 *
 * @param data A pointer to data (not used in this implementation).
 * @param argc The number of columns in the database table.
 * @param argv An array of field values, representing the attributes of each column.
 * @param colNames An array of column names from the database table.
 *
 * @return An integer status code (always 0 in this implementation).
 */
int DatabaseStructureCallback(void *data, int argc, char **argv, char **colNames);

/**
 * @brief Execute a user-defined SQL query to display database table structure.
 *
 * This function opens a database, executes a user-defined SQL query to retrieve information about the structure of a
 * specific database table, and displays the results in the application. It is primarily used to show the structure of
 * the database tables and their columns to the user.
 *
 * @param info A pointer to the GlobalData structure containing the user-defined SQL query and database information.
 */
void ShowQuery(GlobalData *info);

/**
 * @brief Display the structure of a database table based on user selection.
 *
 * This function allows the user to view the structure of a database table by executing an SQL query. It can display
 * the structure of either a user-defined query or a predefined query stored in the GlobalData structure. The function
 * opens the database, executes the query, and displays the table structure within the application's graphical interface.
 *
 * @param info A pointer to the GlobalData structure containing the user-defined or predefined SQL query and database information.
 */
void ShowDatabaseStructure(GlobalData *info);

/**
 * @brief Display the contents of a selected database table.
 *
 * This function displays the contents of a selected database table within the application's graphical user interface.
 * It opens the database, executes a SQL query to retrieve table data, and renders the data using the ImGui library.
 * The specific table to be displayed is determined by the user's selection in the GlobalData structure.
 *
 * @param info A pointer to the GlobalData structure that contains information about the selected table and database connection.
 *
 * @return An integer status code (0 for success, 1 for failure).
 */

/**
 * @brief insert new rows into the table.
 *
 * @param info A pointer to the GlobalData structure that contains information about the selected table and database connection.
 *
 * @return An integer status code (0 for success, 1 for failure).
 */

void InsertDataTable(GlobalData *info);

int ShowDatabaseTable(GlobalData *info);

/**
 * @brief Update values in a selected database table.
 *
 * This function allows users to modify and update values in a selected database table using the application's graphical user interface.
 * The specific table and values to be updated are determined by the user's selection in the GlobalData structure.
 * After making modifications, users can press the "Insert" button to save the changes back to the database.
 *
 * @param info A pointer to the GlobalData structure that contains information about the selected table and database connection.
 */
void Updatevalues(GlobalData *info);

/**
 * @brief Init values in a database table.
 *
 * This collects allows init values of databse.
 *
 * @param i A variable to collect the diferents tables.
 */

int InitTablesvalues(int i);

#endif
