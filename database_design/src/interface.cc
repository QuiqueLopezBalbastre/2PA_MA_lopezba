/**
 * @file interface.cc
 * @author Sergio Madaleno (madalenofi@esat-alumni.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "global_data.h"

static int ImGuiCallback(void* data, int argc, char** argv, char** colNames){
    ImGui::Columns(argc, "Database Table", false);

    for (int i = 0; i < argc; i++) {
        ImGui::Text("%s: %s", colNames[i], (argv[i] ? argv[i] : "NULL"));
        ImGui::NextColumn();
    }

    return 0;
}

void ShowDatabaseTable(/*const char *table_selected*/GlobalData* info) {

    sqlite3* db;
    int rc = sqlite3_open("../data/Database.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    ImGui::Begin("Database Table");
    
    const char* query = "SELECT * FROM EMPLOYEE";
    char* errMsg = 0;
    rc = sqlite3_exec(db, query, ImGuiCallback, 0, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);

    ImGui::End();
    

    

}

void Login(GlobalData *info)
{
    ImGui::SetNextWindowPos(ImVec2(100.0f, 50.0f), ImGuiCond_Once);
    // ImGui::SetNextWindowSize(ImVec2(login_size.x, login_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);

    ImGui::Begin("Login");
    {
        ImGui::SetCursorPos(ImVec2(60, 240));
        ImGui::InputText("##Username", info->user_name, IM_ARRAYSIZE(info->user_name));

        ImGui::SetCursorPos(ImVec2(60, 280));
        ImGui::InputText("##Password", info->pass_word, IM_ARRAYSIZE(info->pass_word, ImGuiInputTextFlags_Password));
        ImGui::SetCursorPos(ImVec2(127, 325));
        if (ImGui::Button("Login", ImVec2(100, 40)))
        {
            NULL;
        }
    }
    ImGui::End();
}


