#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "query_window.h"
#include "global_data.h"

void ExecuteUserQuery(GlobalData *info){

    ImGui::SetCursorPos(ImVec2(60, 60));
    ImGui::InputText("##UserQuery", info->user_query, IM_ARRAYSIZE(info->user_query) * 20);

    ImGui::SetCursorPos(ImVec2(900, 50));
    if (ImGui::Button("Execute query", ImVec2(150, 45)))
    {
        info->menu_id = MenuSelector::kMenuSelector_Query;
    }
}

void BottomWindow(GlobalData *info)
{
    ExecuteUserQuery(info);
}