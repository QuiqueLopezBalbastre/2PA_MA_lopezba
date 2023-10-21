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

TableEmployee employee[kTableEmployeeColumns];
TableCompany company[kTableCompanyColumns];
TableCity city[kTableCityColumns];
TableCountry country[kTableCountryColumns];

void InitTable(int id)
{
    switch(id){
        case TableSelector::Employee:
            for (int i = 0; i < kTableEmployeeColumns; i++)
            {
                employee[i].id = -1;
                employee[i].name[40] = '\0';
                employee[i].surname[40] = '\0';
                employee[i].adress[40] = '\0';
                employee[i].company = -1;
                employee[i].city = -1;
                employee[i].nacionality = -1;
                employee[i].salary = -1;
            }
            break;

        case TableSelector::Company:
            for (int i = 0; i < kTableCompanyColumns; i++)
            {
                company[i].id = -1;
                company[i].name[40] = '\0';
                company[i].country[40] = '\0';
            }
            break;

        case TableSelector::City:
            for (int i = 0; i < kTableCityColumns; i++)
            {
                city[i].id = -1;
                city[i].name[40] = '\0';
                city[i].country[40] = '\0';
            }
            break;
            
        case TableSelector::Country:
            for (int i = 0; i < kTableCountryColumns; i++)
            {
                country[i].id = -1;
                country[i].name[40] = '\0';
            }
            break;
    }
}

int TableEmployeeCallback(void *data, int argc, char **field_values, char **colNames)
{
    const int Kncolumst1 = 1;
    TableEmployee *t = (TableEmployee *)data;

    int index = 0;

    for(index = 0; index < kTableEmployeeColumns; index++){

        if(t[index].id == -1)
        break;
    }

    if(kRows == index){
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

    ImGui::SetNextWindowPos(ImVec2(20, 60));
    ImGui::SetNextWindowSize(ImVec2(768, 365));
    ImGui::Begin("Database Table", NULL,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);

    char *sql = "SELECT * FROM Employee";

    rc = sqlite3_exec(db, sql, TableEmployeeCallback, (void *)employee, &err_msg);

    ImGui::Separator();
    switch (info->table_id){

        case TableSelector::Employee:
            ImGui::Columns(kTableEmployeeColumns, "Employee Table Data", false);
            break;

        case TableSelector::Company:
            ImGui::Columns(kTableCompanyColumns, "Company Table Data", false);
            break;

        case TableSelector::City:
            ImGui::Columns(kTableCityColumns, "City Table Data", false);
            break;

        case TableSelector::Country:
            ImGui::Columns(kTableCountryColumns, "Country Table Data", false);
            break;
    }

    for(int i = 0; i < kTableEmployeeColumns; i++){

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

    if(rc != SQLITE_OK){
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);

    ImGui::End();

    return 0;
}

void Login(GlobalData *info)
{
    ImGui::SetNextWindowPos(ImVec2(20.0f, 435.0f));
    ImGui::SetNextWindowSize(ImVec2(768, 150));
    ImGui::SetNextWindowBgAlpha(1.0f);

    ImGui::Begin("login Table", NULL,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);
    {
        ImGui::SetCursorPos(ImVec2(60, 30));
        ImGui::InputText("##Username", info->user_name, IM_ARRAYSIZE(info->user_name));

        ImGui::SetCursorPos(ImVec2(60, 70));
        ImGui::InputText("##Password", info->pass_word, IM_ARRAYSIZE(info->pass_word, ImGuiInputTextFlags_Password));

        ImGui::SetCursorPos(ImVec2(640, 40));
        if (ImGui::Button("Login", ImVec2(100, 40)))
        {
            NULL;
        }
    }
    ImGui::End();
}

void ButtonsWindow(GlobalData *info)
{
    ImGui::SetNextWindowPos(ImVec2(20.0f, 10.0f));
    ImGui::SetNextWindowSize(ImVec2(768, 40));

    ImGui::Begin("Button Table", NULL,
                ImGuiWindowFlags_NoTitleBar |
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoMove);
    {
        if(ImGui::Button("Open Popup")){ ImGui::OpenPopup("MyPopup"); }

        if(ImGui::BeginPopup("MyPopup"))
        {
            if (ImGui::Button("Employee")) { info->table_id = TableSelector::Employee; }
            if (ImGui::Button("Company")) { info->table_id = TableSelector::Company;}
            if (ImGui::Button("City")) { info->table_id = TableSelector::City; }
            if (ImGui::Button("Country")) { info->table_id = TableSelector::Country; }
            if (ImGui::Button("Close")){ ImGui::CloseCurrentPopup(); }
            ImGui::EndPopup();
        }
    }
    ImGui::End();
}
