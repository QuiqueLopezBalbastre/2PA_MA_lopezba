#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include "count_rows.h"
#include "global_data.h"


int Readrow(void *data, int argc, char **field_values, char **colNames)
{
    
     int *t = (int*)data;
    
    *t= atoi(field_values[0]);

   
    //printf("%d",*t);

    return 0;
}


void ShowFile(GlobalData* info,int i) {
    
    char sql[512];
    sqlite3* db;
    char* err_msg = 0;
    int rc = sqlite3_open("../data/Database.db", &db);

    switch(i){
        case 0:
            
                
                
                 snprintf(sql, sizeof(sql), " Select COUNT(*) FROM Employee;"
                     );


    
    
    
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sql, Readrow, (void*) &(info->countfiles), &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
    
    printf("%d",info->countfiles);
            
    
            
          
            
        break;
         
        case TableSelector::Company:
            
            
                
                 snprintf(sql, sizeof(sql), " Select COUNT(*) FROM Company;"
                     );


    
    

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sql, Readrow, (void*) &(info->countfiles2), &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
    
    printf("%d",info->countfiles);
        break;

        case TableSelector::City:
            
                
                 snprintf(sql, sizeof(sql), " Select COUNT(*) FROM City;"
                     );


    
    

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sql, Readrow, (void*) &(info->countfiles3), &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
    
    printf("%d",info->countfiles);
        break;

        case TableSelector::Country:
          
          
                
                 snprintf(sql, sizeof(sql), " Select COUNT(*) FROM Country;"
                     );


    
    

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sql, Readrow, (void*) &(info->countfiles4), &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
    
    

        break;
        
    }

    
}


