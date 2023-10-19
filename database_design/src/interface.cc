
#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>
#include <esat_extra/sqlite3.h>

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int ImGuiCallback(void* data, int argc, char** argv, char** colNames){
    ImGui::Columns(argc, "Database Table", false);

    for (int i = 0; i < argc; i++) {
        ImGui::Text("%s: %s", colNames[i], (argv[i] ? argv[i] : "NULL"));
        ImGui::NextColumn();
    }

    return 0;
}

void ShowDatabaseTable() {

    sqlite3* db;
    int rc = sqlite3_open("../data/Database.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    ImGui::Begin("Database Table");

    const char* query = "SELECT * FROM Country";
    char* errMsg = 0;
    rc = sqlite3_exec(db, query, ImGuiCallback, 0, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);

    ImGui::End();
}


 


