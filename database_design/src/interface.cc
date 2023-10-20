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

static int ImGuiCallback(void* data, int argc, char** argv, char** colNames) {
    
    ImGui::Columns(argc, "Database Table", false);

    for (int i = 0; i < argc; i++) {
        ImGui::Text("%s", colNames[i]);
        ImGui::NextColumn();
    }

    ImGui::Separator();

    ImGui::Columns(argc, "Database Table Data", false);

    for (int i = 0; i < argc; i++) {
        ImGui::Text("%s", (argv[i] ? argv[i] : "NULL"));
        ImGui::NextColumn();
    }

    return 0;
}


void ShowDatabaseTable(/*const char *table_selected*/GlobalData* info) {

    sqlite3* db;
    int rc = sqlite3_open("../data/Database.db", &db);

    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    ImGui::SetNextWindowPos(ImVec2(20, 60));
    ImGui::SetNextWindowSize(ImVec2(768, 365));

    ImGui::Begin("Database Table", NULL,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |   
        ImGuiWindowFlags_NoMove); 
    
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
    ImGui::SetNextWindowPos(ImVec2(20.0f, 435.0f));
    ImGui::SetNextWindowSize(ImVec2(768, 150));
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
        
        ImGui::SetCursorPos(ImVec2(640, 40));
        if (ImGui::Button("Login", ImVec2(100, 40)))
        {
            NULL;
        }
    }
    ImGui::End();
}

void Buttons(GlobalData *info)
{
    ImGui::SetNextWindowPos(ImVec2(20.0f, 10.0f));
    ImGui::SetNextWindowSize(ImVec2(768, 40));

    ImGui::Begin("Button Table", NULL,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |   
        ImGuiWindowFlags_NoMove);
    {
        //This window is not seen, I dont know why
    }
    ImGui::End();
}

