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

void TopWindow(GlobalData *info)
{
    ImGui::SetNextWindowPos(ImVec2(20.0f, 10.0f));
    ImGui::SetNextWindowSize(ImVec2(1160, 40));

    ImGui::Begin("Button Table", NULL,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);
    {
        if (ImGui::Button("Initial menu", {125.0f, 20.0f}))
        {
            info->menu_id = MenuSelector::kMenuSelector_InitialMenu;
        }
    }
    ImGui::End();
}

void MenuSelectionWindow(GlobalData *info)
{
    const ImVec2 size = {125.0f, 20.0f};

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 15));
    if (ImGui::Button("Select tables", size))
    {
        info->menu_id = MenuSelector::kMenuSelector_ShowTable;
    }
    if (ImGui::Button("Update data", size))
    {
        info->menu_id = MenuSelector::kMenuSelector_UpdateData;
    }
    if (ImGui::Button("Insert data", size))
    {
        info->menu_id = MenuSelector::kMenuSelector_InsertData;
    }
    if (ImGui::Button("Remove data", size))
    {
        info->menu_id = MenuSelector::kMenuSelector_RemoveData;
    }
    if(ImGui::Button("DDBB structure", size))
    {
        info->menu_id = MenuSelector::kMenuSelector_ShowDatabase;
    }
    ImGui::PopStyleVar();
}

void TableSelectionWindow(GlobalData *info)
{
    const ImVec2 size = {125.0f, 20.0f};
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 15));

    if (ImGui::Button("Employee", size))
    {
        info->table_id = TableSelector::Employee;
    }
    if (ImGui::Button("Company", size))
    {
        info->table_id = TableSelector::Company;
    }
    if (ImGui::Button("City", size))
    {
        info->table_id = TableSelector::City;
    }
    if (ImGui::Button("Country", size))
    {
        info->table_id = TableSelector::Country;
    }
    ImGui::PopStyleVar();
}