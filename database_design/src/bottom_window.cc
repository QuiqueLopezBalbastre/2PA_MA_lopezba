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

void LoginWindow(GlobalData *info)
{
    ImGui::SetNextWindowPos(ImVec2(20.0f, 640.0f));
    ImGui::SetNextWindowSize(ImVec2(1160, 150));
    ImGui::SetNextWindowBgAlpha(1.0f);

    ImGui::Begin("login Table", NULL,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);
    {
        ImGui::SetCursorPos(ImVec2(60, 30));
        ImGui::InputText("##Username", info->user_name, IM_ARRAYSIZE(info->user_name));

        ImGui::SetCursorPos(ImVec2(60, 70));
        ImGui::InputText("##Password", info->pass_word, IM_ARRAYSIZE(info->pass_word, ImGuiInputTextFlags_Password));

        ImGui::SetCursorPos(ImVec2(1000, 40));
        if (ImGui::Button("Login", ImVec2(100, 40)))
        {
            NULL;
        }
    }
    ImGui::End();
}