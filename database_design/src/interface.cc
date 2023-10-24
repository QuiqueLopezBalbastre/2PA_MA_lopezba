/**
 * @file interface.cc
 * @author Sergio Madaleno (madalenofi@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-19
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "interface.h"
#include "global_data.h"

TableEmployee employee[kTableEmployeeRows];
TableCompany company[kTableCompanyRows];
TableCity city[kTableCityRows];
TableCountry country[kTableCountryRows];

void InitTable(int id)
{
    switch(id){
        case TableSelector::Employee:
            for (int i = 0; i < kTableEmployeeRows; i++)
            {
                employee[i].id = -1;
                employee[i].name[40] = '\0';
                employee[i].surname[40] = '\0';
                employee[i].address[40] = '\0';
                employee[i].company = -1;
                employee[i].city = -1;
                employee[i].nacionality = -1;
                employee[i].salary = -1;
            }
            break;

        case TableSelector::Company:
            for (int i = 0; i < kTableCompanyRows; i++)
            {
                company[i].id = -1;
                company[i].name[40] = '\0';
                company[i].country[40] = '\0';
            }
            break;

        case TableSelector::City:
            for (int i = 0; i < kTableCityRows; i++)
            {
                city[i].id = -1;
                city[i].name[40] = '\0';
                city[i].country[40] = '\0';
            }
            break;
            
        case TableSelector::Country:
            for (int i = 0; i < kTableCountryRows; i++)
            {
                country[i].id = -1;
                country[i].name[40] = '\0';
            }
            break;
    }
}

int TableEmployeeCallback(void *data, int argc, char **field_values, char **colNames)
{
    TableEmployee *t = (TableEmployee *)data;

    int index = 0;

    for(index = 0; index < kTableEmployeeRows; index++){

        if(t[index].id == -1)
        break;
    }

    if(kTableEmployeeRows == index){
        return 0;
    }

    t[index].id = atoi(field_values[0]);
    strncpy_s(t[index].name, field_values[1], 40);
    strncpy_s(t[index].surname, field_values[2], 40);

    // strncpy_s(t[0].adress,field_values[3],16);
    t[index].company = atoi(field_values[4]);
    t[index].city = atoi(field_values[5]);
    t[index].nacionality = atoi(field_values[6]);
    t[index].salary = atoi(field_values[7]);
    /*
        printf("%d", t[index].id);
        printf("%s", t[index].name);
        printf("%s", t[index].surname);
        printf("%d", t[index].company);
        printf("%d", t[index].city);
        printf("%d", t[index].nacionality);
        printf("%d", t[index].salary);
    */

    if(index == 0){
        ImGui::Columns(argc, "Database Table", false);

        for (int i = 0; i < argc; i++){
            ImGui::Text("%s", colNames[i]);
            ImGui::NextColumn();
        }
    }

    return 0;
}

int TableCompanyCallback(void *data, int argc, char **field_values, char **colNames)
{
    TableCompany *t = (TableCompany *)data;

    int index = 0;

    for(index = 0; index < kTableCompanyRows; index++){

        if(t[index].id == -1)
        break;
    }

    if(kTableCompanyRows == index){
        return 0;
    }

    t[index].id = atoi(field_values[0]);
    strncpy_s(t[index].name, field_values[1], 40);
    strncpy_s(t[index].country, field_values[2], 40);

    if(index == 0){
        ImGui::Columns(argc, "Database Table", false);

        for (int i = 0; i < argc; i++){
            ImGui::Text("%s", colNames[i]);
            ImGui::NextColumn();
        }
    }

    return 0;
}

int TableCityCallback(void *data, int argc, char **field_values, char **colNames)
{
    TableCity *t = (TableCity *)data;

    int index = 0;

    for(index = 0; index < kTableCityRows; index++){

        if(t[index].id == -1)
        break;
    }

    if(kTableCityRows == index){
        return 0;
    }

    t[index].id = atoi(field_values[0]);
    strncpy_s(t[index].name, field_values[1], 40);
    strncpy_s(t[index].country, field_values[2], 40);

    if(index == 0){
        ImGui::Columns(argc, "Database Table", false);

        for (int i = 0; i < argc; i++){
            ImGui::Text("%s", colNames[i]);
            ImGui::NextColumn();
        }
    }

    return 0;
}

int TableCountryCallback(void *data, int argc, char **field_values, char **colNames)
{
    TableCountry *t = (TableCountry *)data;

    int index = 0;

    for(index = 0; index < kTableCountryRows; index++){

        if(t[index].id == -1)
        break;
    }

    if(kTableCountryRows == index){
        return 0;
    }

    t[index].id = atoi(field_values[0]);
    strncpy_s(t[index].name, field_values[1], 40);

    if(index == 0){
        ImGui::Columns(argc, "Database Table", false);

        for (int i = 0; i < argc; i++){
            ImGui::Text("%s", colNames[i]);
            ImGui::NextColumn();
        }
    }

    return 0;
}

int QueryCallback(void* data, int argc, char** argv, char** colNames){
    ImGui::Columns(argc, "Database Table", false);

    for (int i = 0; i < argc; i++) {
        ImGui::Text("%s: %s", colNames[i], (argv[i] ? argv[i] : "NULL"));
        ImGui::NextColumn();
    }

    return 0;
}

void ShowQuery(GlobalData *info){

    sqlite3* db;
    int rc = sqlite3_open("../data/Database.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }
    
    
    ImGui::SetNextWindowSize(ImVec2(830, 151));
    ImGui::Begin("Database Table");
    char* query;
    if(!info->structb){
    query = info->user_query;
    }else{
   
     query = info->struct_database;

    }
    char* err_msg = 0;
    rc = sqlite3_exec(db, query, QueryCallback, 0, &err_msg);
    
    

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);

    ImGui::End();


}

void CreateWindow()
{
    ImGui::SetNextWindowPos(ImVec2(20, 60));
    ImGui::SetNextWindowSize(ImVec2(1160, 570));
    ImGui::Begin("Database Table", NULL,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);
}

void CloseWindow()
{
    ImGui::End();
}

int ShowDatabaseTable(GlobalData *info)
{
    InitTable(info->table_id);
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("../data/Database.db", &db);

    if(rc != SQLITE_OK){

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // ImGui::SetNextWindowPos(ImVec2(20, 60));
    // ImGui::SetNextWindowSize(ImVec2(1160, 570));
    // ImGui::Begin("Database Table", NULL,
    //             ImGuiWindowFlags_NoTitleBar |
    //             ImGuiWindowFlags_NoResize |
    //             ImGuiWindowFlags_NoMove);

    char *sql = nullptr;

    switch (info->table_id){

        case TableSelector::Employee:
            sql = "SELECT * FROM Employee";
            rc = sqlite3_exec(db, sql, TableEmployeeCallback, (void *)employee, &err_msg);
            ImGui::Columns(8, "Employee Table Data", false);

            ImGui::Separator();
            for(int i = 0; i < kTableEmployeeRows; i++){

                ImGui::Text("%d", employee[i].id);
                ImGui::NextColumn();
                ImGui::Text("%s", employee[i].name);
                ImGui::NextColumn();
                ImGui::Text("%s", employee[i].surname);
                ImGui::NextColumn();
                ImGui::Text("NULL(RELLENAR)");
                ImGui::NextColumn();
                ImGui::Text("%d", employee[i].company);
                ImGui::NextColumn();
                ImGui::Text("%d", employee[i].city);
                ImGui::NextColumn();
                ImGui::Text("%d", employee[i].nacionality);
                ImGui::NextColumn();
                ImGui::Text("%d", employee[i].salary);
                ImGui::NextColumn();
            }
            break;

        case TableSelector::Company:
            sql = "SELECT * FROM Company";
            rc = sqlite3_exec(db, sql, TableCompanyCallback, (void *)company, &err_msg);
            ImGui::Columns(3, "Company Table Data", false);

            ImGui::Separator();
            for(int i = 0; i < kTableCompanyRows; i++){

                ImGui::Text("%d", company[i].id);
                ImGui::NextColumn();
                ImGui::Text("%s", company[i].name);
                ImGui::NextColumn();
                ImGui::Text("%s", company[i].country);
                ImGui::NextColumn();
            }
            break;

        case TableSelector::City:
            sql = "SELECT * FROM City";
            rc = sqlite3_exec(db, sql, TableCityCallback, (void *)city, &err_msg);
            ImGui::Columns(3, "City Table Data", false);

            ImGui::Separator();
            for(int i = 0; i < kTableCityRows; i++){

                ImGui::Text("%d", city[i].id);
                ImGui::NextColumn();
                ImGui::Text("%s", city[i].name);
                ImGui::NextColumn();
                ImGui::Text("%s", city[i].country);
                ImGui::NextColumn();
            }
            break;

        case TableSelector::Country:
            sql = "SELECT * FROM Country";
            rc = sqlite3_exec(db, sql, TableCountryCallback, (void *)country, &err_msg);
            ImGui::Columns(2, "Country Table Data", false);

            ImGui::Separator();
            for(int i = 0; i < kTableCountryRows; i++){

                ImGui::Text("%d", country[i].id);
                ImGui::NextColumn();
                ImGui::Text("%s", country[i].name);
                ImGui::NextColumn();
            }
            break;
        case TableSelector::Database:
             if(info->query_execute){
                ShowQuery(info);
             }
            break;
    }

    if(rc != SQLITE_OK){
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);

    // ImGui::End();

    return 0;
}

