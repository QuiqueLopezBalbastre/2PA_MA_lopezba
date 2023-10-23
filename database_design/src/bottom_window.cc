#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bottom_window.h"
#include "global_data.h"

void ExecuteUserQuery(GlobalData *info){

    ImGui::SetCursorPos(ImVec2(60, 30));
    ImGui::InputText("##UserQuery", info->user_query, IM_ARRAYSIZE(info->user_query) * 20);

    ImGui::SetCursorPos(ImVec2(1000, 40));
    if (ImGui::Button("Execute query", ImVec2(100, 40)))
    {
        info->query_execute=true;
    }
}

void BottomWindow(GlobalData *info)
{
    ImGui::SetNextWindowPos(ImVec2(20.0f, 640.0f));
    ImGui::SetNextWindowSize(ImVec2(1160, 150));
    ImGui::SetNextWindowBgAlpha(1.0f);

    ImGui::Begin("TextTable", NULL,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);
    {
        ExecuteUserQuery(info);
    }
    ImGui::End();
}