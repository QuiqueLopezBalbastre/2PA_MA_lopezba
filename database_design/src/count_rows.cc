#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "count_rows.h"
#include "global_data.h"

int ReadRows(void *data, int argc, char **field_values, char **colNames){
    
    int *t = (int*)data;
    *t= atoi(field_values[0]);

    return 0;
}

void ShowRows(GlobalData* info, int table_identifier) {
    
    char sql[512];
    sqlite3* db;
    char* err_msg = 0;
    int rc = sqlite3_open("../data/Database.db", &db);

    switch(table_identifier){
        case TableSelector::Employee: 
            snprintf(sql, sizeof(sql), " Select COUNT(*) FROM Employee;");

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                sqlite3_close(db);
                return;
            }

            rc = sqlite3_exec(db, sql, ReadRows, (void*) &(info->count_rows), &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
            }

            sqlite3_close(db); 
        break;
         
        case TableSelector::Company:
            snprintf(sql, sizeof(sql), " Select COUNT(*) FROM Company;");

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                sqlite3_close(db);
                return;
            }

            rc = sqlite3_exec(db, sql, ReadRows, (void*) &(info->count_rows_2), &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
            }

            sqlite3_close(db);
        break;

        case TableSelector::City:
            snprintf(sql, sizeof(sql), " Select COUNT(*) FROM City;");

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                sqlite3_close(db);
                return;
            }

            rc = sqlite3_exec(db, sql, ReadRows, (void*) &(info->count_rows_3), &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
            }

            sqlite3_close(db);
        break;

        case TableSelector::Country:
            snprintf(sql, sizeof(sql), " Select COUNT(*) FROM Country;");

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                sqlite3_close(db);
                return;
            }

            rc = sqlite3_exec(db, sql, ReadRows, (void*) &(info->count_rows_4), &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
            }

            sqlite3_close(db);
        break;

    }
}


