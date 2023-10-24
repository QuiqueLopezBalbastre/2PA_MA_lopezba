#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include "insertdata.h"
#include "interface.h"
#include "global_data.h"

TableEmployee newEmployee;
TableCompany newCompany;
TableCity newCity;
TableCountry newCountry;

void ExecuteSQL(const char *sql)
{
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("../data/Database.db", &db);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
}

void InsertDataTable(GlobalData *info)
{

    ImGui::SetNextWindowPos(ImVec2(20, 60));
    ImGui::SetNextWindowSize(ImVec2(1160, 570));
    ImGui::Begin("InsertEmployeeData", NULL,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);

    if (ImGui::Button("Employee"))
    {
        info->table_id = TableSelector::Employee;
    }
    ImGui::SameLine();
    if (ImGui::Button("Company"))
    {
        info->table_id = TableSelector::Company;
    }
    ImGui::SameLine();
    if (ImGui::Button("City"))
    {
        info->table_id = TableSelector::City;
    }
    ImGui::SameLine();
    if (ImGui::Button("Country"))
    {
        info->table_id = TableSelector::Country;
    }
    ImGui::Separator();
    

    switch (info->table_id)
    {
    case TableSelector::Employee:

        ImGui::InputInt("ID", &newEmployee.id);
        ImGui::InputText("Name", newEmployee.name, 40);
        ImGui::InputText("Surname", newEmployee.surname, 40);
        ImGui::InputText("Address", newEmployee.address, 40);
        ImGui::InputInt("Company", &newEmployee.company);
        ImGui::InputInt("City", &newEmployee.city);
        ImGui::InputInt("Nationality", &newEmployee.nacionality);
        ImGui::InputInt("Salary", &newEmployee.salary);

        if (ImGui::Button("Insert"))
        {
            char sql[512];
            snprintf(sql, sizeof(sql), "INSERT INTO Employee (id, name, surname, adress, company, city, nationality, salary) VALUES (%d, '%s', '%s', '%s', %d, %d, %d, %d);",
                     newEmployee.id, newEmployee.name, newEmployee.surname, newEmployee.address, newEmployee.company, newEmployee.city, newEmployee.nacionality, newEmployee.salary);

            ExecuteSQL(sql);
        }
        break;

    case TableSelector::Company:

        ImGui::InputInt("ID", &newCompany.id);
        ImGui::InputText("Name", newCompany.name, 40);
        ImGui::InputText("Country", newCompany.country, 40);

        if (ImGui::Button("Insert"))
        {
            char sql[512];
            snprintf(sql, sizeof(sql), "INSERT INTO Company (id, name, country) VALUES (%d, '%s', '%s');",
                     newCompany.id, newCompany.name, newCompany.country);

            ExecuteSQL(sql);
        }
        break;

    case TableSelector::City:

        ImGui::InputInt("ID", &newCity.id);
        ImGui::InputText("Name", newCity.name, 40);
        ImGui::InputText("Country", newCity.country, 40);

        if (ImGui::Button("Insert"))
        {
            char sql[512];
            snprintf(sql, sizeof(sql), "INSERT INTO City (id, name, country) VALUES (%d, '%s', '%s');",
                     newCity.id, newCity.name, newCity.country);

            ExecuteSQL(sql);
        }
        break;

    case TableSelector::Country:

        ImGui::InputInt("ID", &newCountry.id);
        ImGui::InputText("Name", newCountry.name, 40);

        if (ImGui::Button("Insert"))
        {
            char sql[512];
            snprintf(sql, sizeof(sql), "INSERT INTO Country (id, name) VALUES (%d, '%s');",
                     newCountry.id, newCountry.name);

            ExecuteSQL(sql);
        }
        break;
    }

    ImGui::End();
}
