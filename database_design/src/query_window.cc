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

    ImGui::SetCursorPos(ImVec2(20, 20));
    ImVec2 inputSize(550, 40); 

    ImGui::InputTextMultiline("##UserQuery", info->user_query, IM_ARRAYSIZE(info->user_query) * 200, inputSize);

    ImGui::SetCursorPos(ImVec2(20, 80));
    if (ImGui::Button("Execute query", ImVec2(150, 45))) {
        info->menu_id = MenuSelector::kMenuSelector_Query;
    }
}

void BottomWindow(GlobalData *info){
    
    ExecuteUserQuery(info);
    
}