#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include "remove_data.h"
#include "show_tables.h"
#include "global_data.h"

void ExecuteSQL(char *sql)
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

    char sql[512];

    if (ImGui::Button("Remove tuple"))
    {
        switch (info->table_id)
        {
        case TableSelector::Employee:
            snprintf(sql, sizeof(sql), "DELETE FROM Employee WHERE ID = %d", id);
            ExecuteSQL(sql);
            break;
        // case TableSelector::Company:
        //     snprintf(sql, sizeof(sql), "DELETE FROM Employee WHERE ID = %d", id);
        //     ExecuteSQL(sql);
        //     break;
        // case TableSelector::City:
        //     snprintf(sql, sizeof(sql), "DELETE FROM Employee WHERE ID = %d", id);
        //     ExecuteSQL(sql);
        //     break;
        // case TableSelector::Country:
        //     snprintf(sql, sizeof(sql), "DELETE FROM Country WHERE ID = %d", id);
        //     ExecuteSQL(sql); 
        //     break;
        }
    }
    return 0;
}