#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "global_functions.h"
#include "global_data.h"

static char errorBuffer[1024] = "";

void LogError(const char* errorMessage) {
    snprintf(errorBuffer, sizeof(errorBuffer), "Error: %s", errorMessage);
}

void ShowErrorWindow(){
    CreateWindow("Error Log", {625.0f, 640.0f}, {555.0f, 150.0f});
    ImGui::Text("Error Window");
    ImGui::TextWrapped("%s", errorBuffer);

    CloseWindow();
}

void ExecuteSQL(const char *sql)
{
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("../data/Database.db", &db);

    if (rc != SQLITE_OK)
    {
        LogError(sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK)
    {
        LogError(err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
}

void CreateWindow(const char *name, ImVec2 pos, ImVec2 size){
    ImGui::SetNextWindowPos(ImVec2(pos.x, pos.y));
    ImGui::SetNextWindowSize(ImVec2(size.x, size.y));
    ImGui::Begin(name, NULL,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);
}

void CloseWindow(){
    ImGui::End();
}
