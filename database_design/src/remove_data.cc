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
#include "global_functions.h"

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