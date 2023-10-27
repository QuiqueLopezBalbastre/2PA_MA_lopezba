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

int DeleteCallback(void *data, int argc, char **argv, char **colNames)
{

    return 0;
}

int id = -0;

int RemoveData(GlobalData *info)
{
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
        case TableSelector::Company:
            snprintf(sql, sizeof(sql), "DELETE FROM Company WHERE ID = %d", id);
            ExecuteSQL(sql);
            break;
        case TableSelector::City:
            snprintf(sql, sizeof(sql), "DELETE FROM City WHERE ID = %d", id);
            ExecuteSQL(sql);
            break;
        case TableSelector::Country:
            snprintf(sql, sizeof(sql), "DELETE FROM Country WHERE ID = %d", id);
            ExecuteSQL(sql);
            break;
        }
    }
    ImGui::Dummy(ImVec2(0, 10));
    ImGui::Separator();
    ShowDatabaseTable(info);
    return 0;
}