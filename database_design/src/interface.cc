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

#include "interface.h"
#include "global_data.h"

const int Kfiles=3;
Ttable1 t[Kfiles];

void Inittable(){


    for(int i=0; i< Kfiles;i++){
        t[i].id=-1;
        t[i].name[40]='\0';
        t[i].surname[40]='\0';
        t[i].adress[40]='\0';
        t[i].company=-1;
        t[i].city=-1;
        t[i].nacionality=-1;
        t[i].salary=-1;
}



}
/*
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



//void ShowDatabaseTable(/*const char *table_selected/ GlobalData* info) {
/*
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
*/

int ImGuiCallback(void* data, int argc, char** field_values, char** colNames){
  
   
const int Kncolumst1=1;
Ttable1* t= (Ttable1*) data;

int index=0;


for(index=0;index<Kfiles ;index++){

if(t[index].id==-1) break;

}



if(Kfiles == index){
return 0;
}


t[index].id=atoi(field_values[0]);
strncpy_s(t[index].name,field_values[1],40);
strncpy_s(t[index].surname,field_values[2],40);

//strncpy_s(t[0].adress,field_values[3],16);
t[index].company=atoi(field_values[4]);
t[index].city=atoi(field_values[5]);
t[index].nacionality=atoi(field_values[6]);
t[index].salary=atoi(field_values[7]);


   
printf("%d",t[index].id);
printf("%s",t[index].name);
printf("%s",t[index].surname);
printf("%d",t[index].company);
printf("%d",t[index].city);
printf("%d",t[index].nacionality);
printf("%d",t[index].salary);

if(index==0){

    ImGui::Columns(argc, "Database Table", false);

    for (int i = 0; i < argc; i++) {
        ImGui::Text("%s", colNames[i]);
        ImGui::NextColumn();
    }
}




return 0;

}

int ShowDatabaseTable(void) {
    Inittable();
    sqlite3* db;
    char *err_msg = 0;
    int rc = sqlite3_open("../data/Database.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    ImGui::Begin("Database Table", NULL,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |   
        ImGuiWindowFlags_NoMove); 
    char *sql = "SELECT * FROM Employee";

    rc = sqlite3_exec(db, sql, ImGuiCallback, (void*) t , &err_msg);
    
    

    ImGui::Separator();

    ImGui::Columns(8, "Database Table Data", false);
    
    for (int i = 0; i < Kfiles; i++) {
        ImGui::Text("%d", t[i].id);
        ImGui::NextColumn();
        ImGui::Text("%s", t[i].name);
        ImGui::NextColumn();
        ImGui::Text("%s", t[i].surname);
        ImGui::NextColumn();
        ImGui::Text("NULL(RELLENAR)");
        ImGui::NextColumn();
        ImGui::Text("%d", t[i].company);
        ImGui::NextColumn();
        ImGui::Text("%d", t[i].city);
        ImGui::NextColumn();
        ImGui::Text("%d", t[i].nacionality);
        ImGui::NextColumn();
        ImGui::Text("%d", t[i].salary);
       ImGui::NextColumn();
       

    }
    

    if (rc != SQLITE_OK ) {
    fprintf(stderr, "Failed to select data\n");
    fprintf(stderr, "SQL error: %s\n", err_msg);

    sqlite3_free(err_msg);
    sqlite3_close(db);

    return 1;
} 
      
sqlite3_close(db);
    
ImGui::End();

return 0;
   
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

