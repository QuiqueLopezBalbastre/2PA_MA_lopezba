/**
 * @file removedata.cc
 * @author Quique López (lopezba@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include "remove_data.h"
#include "interface.h"
#include "global_data.h"

int id = -1;

int DeleteCallback(void *data, int argc, char **argv, char **colNames)
{

    return 0;
}

int RemoveData(GlobalData *info)
{
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
    ImGui::SameLine();
    ImGui::Separator();
    ImGui::Separator();

    ShowDatabaseTable(info);
    ImGui::Separator();
    ImGui::Separator();
    ImGui::InputInt("ID", &id);

    sqlite3 *db;
    char *err_msg = 0;
    char *sql = nullptr;
    int rc = sqlite3_open("../data/Database.db", &db);

    if (ImGui::Button("Remove tuple"))
    {
        switch (info->table_id)
        {
        case TableSelector::Employee:
            snprintf(sql, sizeof(sql), "DELETE FROM Employee WHERE ID = %d", id);
            break;
        case TableSelector::Company:
            snprintf(sql, sizeof(sql), "DELETE FROM Employee WHERE ID = %d", id);            break;
        case TableSelector::City:
            snprintf(sql, sizeof(sql), "DELETE FROM Employee WHERE ID = %d", id);
            break;
        case TableSelector::Country:
            snprintf(sql, sizeof(sql), "DELETE FROM Country WHERE ID = %d", id);            break;
        }
        printf("%s", sql);
        rc = sqlite3_exec(db, sql, 0, (void *)id, &err_msg);
    }

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

    sqlite3_close(db);
    return 0;
}