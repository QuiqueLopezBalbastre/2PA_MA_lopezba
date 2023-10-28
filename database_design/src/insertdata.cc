#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include "insertdata.h"
#include "show_tables.h"
#include "global_data.h"
#include "global_functions.h"

TableEmployee newEmployee;
TableCompany newCompany;
TableCity newCity;
TableCountry newCountry;

void InsertDataTable(GlobalData *info){
    char sql[512];

    switch(info->table_id){

        case TableSelector::Employee:
            ImGui::InputInt("ID", &newEmployee.id);
            ImGui::InputText("Name", newEmployee.name, 40);
            ImGui::InputText("Surname", newEmployee.surname, 40);
            ImGui::InputText("Address", newEmployee.address, 40);
            ImGui::InputInt("Company", &newEmployee.company);
            ImGui::InputInt("City", &newEmployee.city);
            ImGui::InputInt("Nationality", &newEmployee.nacionality);
            ImGui::InputInt("Salary", &newEmployee.salary);

            if(ImGui::Button("Insert")){

                snprintf(sql, sizeof(sql), "INSERT INTO Employee (id, name, surname, address, company, city, nationality, salary) VALUES (%d, '%s', '%s', '%s', %d, %d, %d, %d);",
                         newEmployee.id, newEmployee.name, newEmployee.surname, newEmployee.address, newEmployee.company, newEmployee.city, newEmployee.nacionality, newEmployee.salary);

                ExecuteSQL(sql);
                info->count_rows++;
                InitTable(info, 0);
            }
        break;

        case TableSelector::Company:
            ImGui::InputInt("ID", &newCompany.id);
            ImGui::InputText("Name", newCompany.name, 40);
            ImGui::InputText("Country", newCompany.country, 40);

            if(ImGui::Button("Insert")){
                snprintf(sql, sizeof(sql), "INSERT INTO Company (id, name, country) VALUES (%d, '%s', '%s');",
                         newCompany.id, newCompany.name, newCompany.country);

                ExecuteSQL(sql);
                info->count_rows_2++;
                InitTable(info, 1);
            }
        break;

        case TableSelector::City:

            ImGui::InputInt("ID", &newCity.id);
            ImGui::InputText("Name", newCity.name, 40);
            ImGui::InputText("Country", newCity.country, 40);

            if(ImGui::Button("Insert")){
                snprintf(sql, sizeof(sql), "INSERT INTO City (id, name, country) VALUES (%d, '%s', '%s');",
                         newCity.id, newCity.name, newCity.country);

                ExecuteSQL(sql);
                info->count_rows_3++;
                InitTable(info, 2);
            }
        break;

        case TableSelector::Country:
            ImGui::InputInt("ID", &newCountry.id);
            ImGui::InputText("Name", newCountry.name, 40);

            if(ImGui::Button("Insert")){
                snprintf(sql, sizeof(sql), "INSERT INTO Country (id, name) VALUES (%d, '%s');",
                         newCountry.id, newCountry.name);

                ExecuteSQL(sql);
                info->count_rows_4++;
                InitTable(info, 3);
            }
        break;
    }
}   
