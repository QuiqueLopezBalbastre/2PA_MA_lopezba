#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "buttons_window.h"
#include "global_data.h"

void DatabaseButton(GlobalData *info)
{
    ImGui::Columns(5, "Options selector", false);
    if (ImGui::Button("Initial menu"))
    {
        info->menu_id = MenuSelector::kMenuSelector_InitialMenu;
    }
    ImGui::NextColumn();
    if (ImGui::Button("Select tables"))
    {
        ImGui::OpenPopup("TablesPopup");
        info->menu_id = MenuSelector::kMenuSelector_ShowTable;
    }
    ImGui::NextColumn();
    if (ImGui::Button("Update data"))
    {
        
        info->menu_id = MenuSelector::kMenuSelector_UdateData;
    }
    ImGui::NextColumn();
    if (ImGui::Button("Insert data"))
    {
        info->menu_id = MenuSelector::kMenuSelector_InsertData;
    }
    ImGui::NextColumn();
    if (ImGui::Button("Remove data"))
    {
        info->menu_id = MenuSelector::kMenuSelector_RemoveData;
    }

    if (ImGui::BeginPopup("TablesPopup"))
    {
        if (ImGui::Button("Employee"))
        {
            info->table_id = TableSelector::Employee;
        }
        if (ImGui::Button("Company"))
        {
            info->table_id = TableSelector::Company;
        }
        if (ImGui::Button("City"))
        {
            info->table_id = TableSelector::City;
        }
        if (ImGui::Button("Country"))
        {
            info->table_id = TableSelector::Country;
        }
        if (ImGui::Button("Query"))
        {
            info->table_id = TableSelector::Database;
        }
        ImGui::Separator();
        if (ImGui::Button("Close"))
        {
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
}

void TopWindow(GlobalData *info)
{
    ImGui::SetNextWindowPos(ImVec2(20.0f, 10.0f));
    ImGui::SetNextWindowSize(ImVec2(1160, 40));

    ImGui::Begin("Button Table", NULL,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);
    {
        DatabaseButton(info);
    }
    ImGui::End();
}