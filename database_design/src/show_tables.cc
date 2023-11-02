#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "show_tables.h"
#include "global_data.h"
#include "global_functions.h"

TableEmployee *employee=nullptr;
TableCompany *company=nullptr;
TableCity *city=nullptr;
TableCountry *country=nullptr;

TableEmployee newEmployee;
TableCompany newCompany;
TableCity newCity;
TableCountry newCountry;

static char errorBuffer[1024] = "";

void InitTable(GlobalData *info, int table_identifier){

    switch(table_identifier){
        case TableSelector::Employee:
            
            employee=(TableEmployee*)realloc(employee,(info->count_rows+15)*sizeof(TableEmployee));

            for(int i=0; i<info->count_rows; i++){
                (employee+i)->id = -1;
                (employee+i)->name[40] = '\0';
                (employee+i)->surname[40] = '\0';
                (employee+i)->address[40] = '\0';
                (employee+i)->company = -1;
                (employee+i)->city = -1;
                (employee+i)->nacionality = -1;
                (employee+i)->salary = -1;
                (employee+i)->rows= info->count_rows;
            }
        break;

        case TableSelector::Company:

            company=(TableCompany*)realloc(company,(info->count_rows_2+15)*sizeof(TableCompany));

            for(int i=0; i<info->count_rows_2; i++){
                (company+i)->id = -1;
                (company+i)->name[40] = '\0';
                (company+i)->country = -1;
                (company+i)->rows= info->count_rows_2;
            }
        break;

        case TableSelector::City:

            city=(TableCity*)realloc(city,(info->count_rows_3+15)*sizeof(TableCity));

            for(int i=0; i<info->count_rows_3; i++){
                (city+i)->id = -1;
                (city+i)->name[40] = '\0';
                (city+i)->country = -1;
                (city+i)->rows= info->count_rows_3;
            }
        break;
            
        case TableSelector::Country:

            country=(TableCountry*)realloc(country,(info->count_rows_4+15)*sizeof(TableCountry));

            for(int i=0; i<info->count_rows_4; i++){
                (country+i)->id = -1;
                (country+i)->name[40] = '\0';
                (country+i)->rows= info->count_rows_4;
            }
        break;
    }
}

int TableEmployeeCallback(void *data, int argc, char **field_values, char **colNames){

    int index = 0;

    for(index = 0; index < (employee+index)->rows; index++){
        if((employee+index)->id == -1)
        break;
    }

    if((employee+index)->rows == index){
        return 0;
    }
    if(NULL!=field_values[0]){
    (employee+index)->id = atoi(field_values[0]);
    }
    if(NULL!=field_values[1]){
    strncpy_s((employee+index)->name, field_values[1], 40);
    }
    if(NULL!=field_values[2]){
    strncpy_s((employee+index)->surname, field_values[2], 40);
    }
    if(NULL!=field_values[3]){
    strncpy_s((employee+index)->address, field_values[3], 40);
    }
    if(NULL!=field_values[4]){
    (employee+index)->company = atoi(field_values[4]);
    }
    if(NULL!=field_values[5]){
    (employee+index)->city = atoi(field_values[5]);
    }
    if(NULL!=field_values[6]){
    (employee+index)->nacionality = atoi(field_values[6]);
    }
    if(NULL!=field_values[7]){
    (employee+index)->salary = atoi(field_values[7]);
    }
    
    if(index == 0){
        ImGui::Columns(argc, "Database Table", false);

        for (int i = 0; i < argc; i++){
            ImGui::Text("%s", colNames[i]);
            ImGui::NextColumn();
        }
    }
    return 0;
}

int TableCompanyCallback(void *data, int argc, char **field_values, char **colNames){

    int index = 0;

    for(index = 0; index < (company+index)->rows; index++){
        if((company+index)->id == -1)
        break;
    }

    if((company+index)->rows == index){
        return 0;
    }
    if(NULL!=field_values[0]){
    (company+index)->id = atoi(field_values[0]);
    }
    if(NULL!=field_values[1]){
    strncpy_s((company+index)->name, field_values[1], 40);
    }
    if(NULL!=field_values[2]){
    (company+index)->country = atoi(field_values[2]);
    }

    if(index == 0){
        ImGui::Columns(argc, "Database Table", false);

        for(int i=0; i<argc; i++){
            ImGui::Text("%s", colNames[i]);
            ImGui::NextColumn();
        }
    }
    return 0;
}

int TableCityCallback(void *data, int argc, char **field_values, char **colNames){

    int index = 0;

    for(index = 0; index < (city+index)->rows; index++){
        if((city+index)->id == -1)
        break;
    }

    if((city+index)->rows == index){
        return 0;
    }
    if(NULL!=field_values[0]){
    (city+index)->id = atoi(field_values[0]);
    }
    if(NULL!=field_values[1]){
    strncpy_s((city+index)->name, field_values[1], 40);
    }
    if(NULL!=field_values[2]){
    (city+index)->country = atoi(field_values[2]);
    }

    if(index == 0){
        ImGui::Columns(argc, "Database Table", false);

        for(int i=0; i<argc; i++){
            ImGui::Text("%s", colNames[i]);
            ImGui::NextColumn();
        }
    }
    return 0;
}

int TableCountryCallback(void *data, int argc, char **field_values, char **colNames){

    int index = 0;

    for(index = 0; index < (country+index)->rows; index++){
        if((country+index)->id == -1)
        break;
    }

    if((country+index)->rows == index){
        return 0;
    }
    if(NULL!=field_values[0]){
    (country+index)->id = atoi(field_values[0]);
    }
    if(NULL!=field_values[1]){
    strncpy_s((country+index)->name, field_values[1], 40);
    }

    if(index == 0){
        ImGui::Columns(argc, "Database Table", false);

        for (int i = 0; i < argc; i++){
            ImGui::Text("%s", colNames[i]);
            ImGui::NextColumn();
        }
    }
    return 0;
}

int DatabaseStructureCallback(void *data, int argc, char **argv, char **colNames){
    ImGui::Columns(argc, "Database Table", false);

    for(int i=0; i<argc; i++){
        ImGui::Text("%s: %s", colNames[i], (argv[i] ? argv[i] : "NULL"));
        ImGui::NextColumn();
    }
    return 0;
}

int EmptyCallback(void *data, int argc, char **argv, char **colNames){
    char *t=(char*)data;

    if (strlen(t) < (kBufferQueryMax-1024)) {

      for(int i=0; i<argc; i++){
          if (NULL == argv[i]) {
              strcat(t, "NULL\0");
          } else {
              strcat(t, argv[i]);
          }
      }

      strcat(t, "\n");
      return 0;
    } else {
        fprintf(stderr, "WARNING: Query result overflowing max query character limit!\n");
        return 0;  // Revise error code
    }
}

void ShowQuery(GlobalData *info){
    sqlite3 *db;

    int rc = sqlite3_open("../data/Database.db", &db);

    if(rc){
        LogError(sqlite3_errmsg(db));
        info->insert_query = false;
        return;
    }

    char *err_msg = 0;

    rc = sqlite3_exec(db, info->user_query, EmptyCallback, info->buffer_query, &err_msg);
    LogConfirmed("Query confirmed");

    if(rc != SQLITE_OK){
        LogError(err_msg);
        sqlite3_free(err_msg);
        info->insert_query = false;
    }

    sqlite3_close(db); 
}

void ShowDatabaseStructure(GlobalData *info){

    sqlite3 *db;
    int rc = sqlite3_open("../data/Database.db", &db);

    if(rc){
        LogError(sqlite3_errmsg(db));
        return;
    }

    char *query=nullptr;
    if(!info->structb){
        query = info->user_query;

    }else{
        query = info->struct_database;
        info->structb = false;
    }

    char *err_msg = 0;
    rc = sqlite3_exec(db, query, DatabaseStructureCallback, 0, &err_msg);

    if(rc != SQLITE_OK){
        LogError(err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
}

int ShowDatabaseTable(GlobalData *info){
    
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("../data/Database.db", &db);

    if(rc != SQLITE_OK){

        LogError(sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sql = nullptr;
    char null[] = "\0";
    ImVec4 textColor = ImVec4(1.0f, 0.5f, 0.0f, 1.0f);
    switch(info->table_id){

        case TableSelector::Employee:
            sql = "SELECT * FROM Employee";
            rc = sqlite3_exec(db, sql, TableEmployeeCallback, (void *) &(employee), &err_msg);
            ImGui::Columns(8, "Employee Table Data", false);
            ImGui::Text("EMPLOYEE TABLE");
            ImGui::Separator();
            
                ImGui::TextColored(textColor, "ID");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Name");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Surname");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Address");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Company");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "City");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Nationality");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Salary");
                ImGui::NextColumn();
            
            for(int i=0; i<info->count_rows; i++){

                ImGui::Text("%d", (employee+i)->id);
                ImGui::NextColumn();
                if(strcmp((employee+i)->name, null)!=0){
                ImGui::Text("%s", (employee+i)->name);
                }else{
                    strncpy_s((employee+i)->name,"(null)", 40);
                }
                ImGui::NextColumn();
                
                if(strcmp((employee+i)->surname, null)!=0){
                ImGui::Text("%s", (employee+i)->surname);
                }else{
                    strncpy_s((employee+i)->surname,"(null)", 40);
                }
                ImGui::NextColumn();
                if(strcmp((employee+i)->address, null)!=0){
                ImGui::Text("%s", (employee+i)->address);
                }else{
                    strncpy_s((employee+i)->address,"(null)", 40);
                }
                ImGui::NextColumn();
                ImGui::Text("%d",(employee+i)->company);
                ImGui::NextColumn();
                ImGui::Text("%d", (employee+i)->city);
                ImGui::NextColumn();
                ImGui::Text("%d", (employee+i)->nacionality);
                ImGui::NextColumn();
                ImGui::Text("%d", (employee+i)->salary);
                ImGui::NextColumn();
            }
            break;

        case TableSelector::Company:
            sql = "SELECT * FROM Company";
            rc = sqlite3_exec(db, sql, TableCompanyCallback, (void *)&(company), &err_msg);
            ImGui::Columns(3, "Company Table Data", false);
            ImGui::Text("COMPANY TABLE");
            ImGui::Separator();

                ImGui::TextColored(textColor, "ID");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Name");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Country");
                ImGui::NextColumn();

            for(int i=0; i<info->count_rows_2; i++){

                ImGui::Text("%d", (company+i)->id);
                ImGui::NextColumn();
                if(strcmp((company+i)->name, null)!=0){
                ImGui::Text("%s", (company+i)->name);
                }else{
                    strncpy_s((company+i)->name,"(null)", 40);
                }
                ImGui::NextColumn();
                ImGui::Text("%d", (company+i)->country);
                ImGui::NextColumn();
            }
            break;

        case TableSelector::City:
            sql = "SELECT * FROM City";
            rc = sqlite3_exec(db, sql, TableCityCallback, (void *)&(city), &err_msg);
            ImGui::Columns(3, "City Table Data", false);
            ImGui::Text("CITY TABLE");
            ImGui::Separator();

                ImGui::TextColored(textColor, "ID");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Name");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Country");
                ImGui::NextColumn();


            for(int i=0; i<info->count_rows_3; i++){

                ImGui::Text("%d", (city+i)->id);
                ImGui::NextColumn();
                if(strcmp((city+i)->name, null)!=0){
                ImGui::Text("%s", (city+i)->name);
                }else{
                    strncpy_s((city+i)->name,"(null)", 40);
                }
                ImGui::NextColumn();
                ImGui::Text("%d", (city+i)->country);
                ImGui::NextColumn();
            }
            break;

        case TableSelector::Country:
            sql = "SELECT * FROM Country";
            rc = sqlite3_exec(db, sql, TableCountryCallback, (void *)&(country), &err_msg);
            ImGui::Columns(2, "Country Table Data", false);
            ImGui::Text("COUNTRY TABLE");
            ImGui::Separator();

                ImGui::TextColored(textColor, "ID");
                ImGui::NextColumn();
                ImGui::TextColored(textColor, "Name");
                ImGui::NextColumn();


            for(int i=0; i<info->count_rows_4; i++){

                ImGui::Text("%d",  (country+i)->id);
                ImGui::NextColumn();
                if(strcmp((country+i)->name, null)!=0){
                ImGui::Text("%s", (country+i)->name);
                }else{
                    strncpy_s((country+i)->name,"(null)", 40);
                }
                ImGui::NextColumn();
            }
            break;
    }

    if(rc != SQLITE_OK){
        LogError(err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);
    
    return 0;
}

void Updatevalues(GlobalData *info){

    switch(info->table_id){
        case TableSelector::Employee:
            ImGui::Text("EMPLOYEE TABLE");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            for(int i=0; i<info->count_rows; i++){
                ImGui::PushID(i);
                ImGui::Text("ID %d", (int)employee[i].id);
                ImGui::NextColumn();
                ImGui::InputText("Name", employee[i].name, 40);
                ImGui::NextColumn();
                ImGui::InputText("surname", employee[i].surname, 40);
                ImGui::NextColumn();
                ImGui::InputText("Address", employee[i].address, 40);
                ImGui::NextColumn();
                ImGui::InputInt("company", &employee[i].company);
                ImGui::NextColumn();
                ImGui::InputInt("city", &employee[i].city);
                ImGui::NextColumn();
                ImGui::InputInt("nacionality", &employee[i].nacionality);
                ImGui::NextColumn();
                ImGui::InputInt("salary", &employee[i].salary);
                ImGui::NextColumn();
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Spacing();

                ImGui::PopID();
            }

            if(ImGui::Button("Insert")){
                for(int i=0; i<info->count_rows; i++){
                    char sql[512];
                    snprintf(sql, sizeof(sql), "UPDATE Employee Set Name = '%s' , Surname = '%s', Company = %d , city = %d , nationality = %d , salary = %d WHERE ID = %d ;",
                             &employee[i].name, &employee[i].surname, employee[i].company, employee[i].city, employee[i].nacionality, employee[i].salary, employee[i].id);

                    LogConfirmed("Update employee table confirmed");
                    
                    ExecuteSQL(sql);
                }
            }
        break;

        case TableSelector::Company:
            ImGui::Text("COMPANY TABLE");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            for(int i=0; i<info->count_rows_2; i++){
                ImGui::PushID(i);
                ImGui::Text("ID %d", (int)company[i].id);
                ImGui::NextColumn();
                ImGui::InputText("Name", company[i].name, 40);
                ImGui::NextColumn();
                ImGui::InputInt("Country", &company[i].country);
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Spacing();

                ImGui::PopID();
            }

            if(ImGui::Button("Insert")){
                for(int i=0; i<info->count_rows_2; i++){
                    char sql[512];
                    snprintf(sql, sizeof(sql), "UPDATE Country Set Name = '%s' , Country = '%d' WHERE ID = %d ;",
                             &company[i].name, company[i].country, employee[i].id);

                    LogConfirmed("Update company table confirmed");

                    ExecuteSQL(sql);
                }
            }
        break;

        case TableSelector::City:
            ImGui::Text("CITY TABLE");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            for(int i=0; i<info->count_rows_3; i++){
                ImGui::PushID(i);
                ImGui::Text("ID %d", (int)city[i].id);
                ImGui::NextColumn();
                ImGui::InputText("Name", city[i].name, 40);
                ImGui::NextColumn();
                ImGui::InputInt("Country", &city[i].country);
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Spacing();

                ImGui::PopID();
            }

            if(ImGui::Button("Insert")){
                for(int i=0; i<info->count_rows_3; i++){
                    char sql[512];
                    snprintf(sql, sizeof(sql), "UPDATE City Set Name = '%s' , Country = '%d' WHERE ID = %d ;",
                             &city[i].name, city[i].country, city[i].id);

                    LogConfirmed("Update city table confirmed");

                    ExecuteSQL(sql);
                }
            }
        break;

        case TableSelector::Country:
            ImGui::Text("COUNTRY TABLE");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            for(int i=0; i<info->count_rows_4; i++){
                ImGui::PushID(i);
                ImGui::Text("ID %d", (int)country[i].id);
                ImGui::NextColumn();
                ImGui::InputText("Name", country[i].name, 40);
                ImGui::Separator();
                ImGui::Spacing();
                ImGui::Spacing();

                ImGui::PopID();
            }

            if(ImGui::Button("Insert")){
                for(int i=0; i<info->count_rows_4; i++){
                    char sql[512];
                    snprintf(sql, sizeof(sql), "UPDATE City Set Name = '%s' WHERE ID = %d ;",
                             &country[i].name, country[i].id);

                    LogConfirmed("Update country table confirmed");

                    ExecuteSQL(sql);
                }
            }
        break;
    }
}

int InitTablesvalues(int i){
    
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("../data/Database.db", &db);

    if(rc != SQLITE_OK){

        LogError(sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sql = nullptr;

    switch(i){

        case 0:
            sql = "SELECT * FROM Employee";
            rc = sqlite3_exec(db, sql, TableEmployeeCallback, (void *) &(employee), &err_msg);

            
            break;

        case 1:
            sql = "SELECT * FROM Company";
            rc = sqlite3_exec(db, sql, TableCompanyCallback, (void *)&(company), &err_msg);
            
            break;

        case 2:
            sql = "SELECT * FROM City";
            rc = sqlite3_exec(db, sql, TableCityCallback, (void *)&(city), &err_msg);
           
            break;

        case 3:
            sql = "SELECT * FROM Country";
            rc = sqlite3_exec(db, sql, TableCountryCallback, (void *)&(country), &err_msg);
            
            break;
    }
       
    

    if(rc != SQLITE_OK){
        LogError(err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);
    
    return 0;
}

void InsertDataTable(GlobalData *info){

    char sql[512];
    bool print;
    int min = 0;
    switch(info->table_id){
        
        case TableSelector::Employee:
            ImGui::Text("EMPLOYEE TABLE");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::InputInt("ID", &newEmployee.id);
            ImGui::InputText("Name", newEmployee.name, 40);
            ImGui::InputText("Surname", newEmployee.surname, 40);
            ImGui::InputText("Address", newEmployee.address, 40);
            ImGui::InputInt("Company", &newEmployee.company);
            ImGui::InputInt("City", &newEmployee.city);
            ImGui::InputInt("Nationality", &newEmployee.nacionality);
            ImGui::InputInt("Salary", &newEmployee.salary);
             
             if (newEmployee.id < min) {
                newEmployee.id = min;
                }
            if(ImGui::Button("Insert")){
                
                for(int i=0;i<info->count_rows;i++){
                if(newEmployee.id==(employee+i)->id){
                     print=false;
                     printf("no ejecutar");
                    }
                }
                
                snprintf(sql, sizeof(sql), "INSERT INTO Employee (id, name, surname, address, company, city, nationality, salary) VALUES (%d, '%s', '%s', '%s', %d, %d, %d, %d);",
                         newEmployee.id, newEmployee.name, newEmployee.surname, newEmployee.address, newEmployee.company, newEmployee.city, newEmployee.nacionality, newEmployee.salary);

                ExecuteSQL(sql);
                if(print){
                info->count_rows++;
                InitTable(info, 0);
                InitTablesvalues(0);
                }
                    
            }
        break;

        case TableSelector::Company:
            ImGui::Text("COMPANY TABLE");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::InputInt("ID", &newCompany.id);
            ImGui::InputText("Name", newCompany.name, 40);
            ImGui::InputInt("Country", &newCompany.country);
           
             if (newCompany.id < min) {
                newCompany.id = min;
                }
            if(ImGui::Button("Insert")){
                for(int i=0;i<info->count_rows_2;i++){
                if(newCompany.id==(company+i)->id){
                     print=false;
                     printf("no ejecutar");
                    }
                }


                snprintf(sql, sizeof(sql), "INSERT INTO Company (id, name, country) VALUES (%d, '%s', '%d');",
                         newCompany.id, newCompany.name, newCompany.country);

                ExecuteSQL(sql);
                if(print){
                info->count_rows_2++;
                InitTable(info, 1);
                InitTablesvalues(1);
                }
            }
        break;

        case TableSelector::City:
            ImGui::Text("CITY TABLE");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::InputInt("ID", &newCity.id);
            ImGui::InputText("Name", newCity.name, 40);
            ImGui::InputInt("Country", &newCity.country);
            if (newCity.id < min) {
                newCity.id = min;
                }
            if(ImGui::Button("Insert")){
                   
                for(int i=0;i<info->count_rows_3;i++){
                if(newCity.id==(city+i)->id){
                     print=false;
                     printf("no ejecutar");
                    }
                }
                snprintf(sql, sizeof(sql), "INSERT INTO City (id, name, country) VALUES (%d, '%s', '%d');",
                         newCity.id, newCity.name, newCity.country);

                ExecuteSQL(sql);
                if(print){
                    info->count_rows_3++;
                    InitTable(info, 2);
                    InitTablesvalues(2);
                    InitTablesvalues(2);
                }
            }
        break;

        case TableSelector::Country:
            ImGui::Text("COUNTRY TABLE");
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::InputInt("ID", &newCountry.id);
            ImGui::InputText("Name", newCountry.name, 40);
            if (newCountry.id < min) {
                newCountry.id = min;
                }
            if(ImGui::Button("Insert")){
                for(int i=0;i<info->count_rows_4;i++){
                if(newCountry.id==(country+i)->id){
                     print=false;
                     printf("no ejecutar");
                    }
                }

                snprintf(sql, sizeof(sql), "INSERT INTO Country (id, name) VALUES (%d, '%s');",
                         newCountry.id, newCountry.name);

                ExecuteSQL(sql);
                if(print){
                info->count_rows_4++;
                InitTable(info, 3);
                InitTablesvalues(3);
                }
            }
        break;
    }
}  

int RemoveData(GlobalData *info) {
    ImGui::InputInt("ID", &info->remove_id);
    char sql[512];
    int min = 0;
    if (info->remove_id < min) {
                info->remove_id = min;
                }
    if(ImGui::Button("Remove tuple")) {
        int indexToDelete = -1;

        switch(info->table_id){
            case TableSelector::Employee:
                for (int i = 0; i < info->count_rows; i++) {
                    if (info->remove_id == employee[i].id) {
                        indexToDelete = i;
                        break;
                    }
                }
                if(indexToDelete >= 0) {
                    snprintf(sql, sizeof(sql), "DELETE FROM Employee WHERE ID = %d", info->remove_id);
                    ExecuteSQL(sql);

                    LogConfirmed("Delete confirmed in employee table");

                    info->count_rows--;
                    InitTable(info, 0);
                }
                break;

            case TableSelector::Company:
                for(int i = 0; i < info->count_rows_2; i++) {
                    if (info->remove_id == company[i].id) {
                        indexToDelete = i;
                        break;
                    }
                }
                if(indexToDelete >= 0){
                    snprintf(sql, sizeof(sql), "DELETE FROM Company WHERE ID = %d", info->remove_id);
                    ExecuteSQL(sql);

                    LogConfirmed("Delete confirmed in company table");

                    info->count_rows_2--;
                    InitTable(info, 1);
                }
                break;

            case TableSelector::City:
                for(int i = 0; i < info->count_rows_3; i++) {
                    if (info->remove_id == city[i].id) {
                        indexToDelete = i;
                        break;
                    }
                }
                if(indexToDelete >= 0) {
                    snprintf(sql, sizeof(sql), "DELETE FROM City WHERE ID = %d", info->remove_id);
                    ExecuteSQL(sql);

                    LogConfirmed("Delete confirmed in city table");

                    info->count_rows_3--;
                    InitTable(info, 2);
                }
                break;

            case TableSelector::Country:
                for(int i = 0; i < info->count_rows_4; i++) {
                    if(info->remove_id == country[i].id) {
                        indexToDelete = i;
                        break;
                    }
                }
                if(indexToDelete >= 0) {
                    snprintf(sql, sizeof(sql), "DELETE FROM Country WHERE ID = %d", info->remove_id);
                    ExecuteSQL(sql);

                    LogConfirmed("Delete confirmed in country table");

                    info->count_rows_4--;
                    InitTable(info, 3);
                }
                break;
        }
    }

    ImGui::Dummy(ImVec2(0, 10));
    ImGui::Separator();
    ShowDatabaseTable(info);

    return 0;
}
