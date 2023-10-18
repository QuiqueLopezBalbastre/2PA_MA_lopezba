#include <esat/draw.h>
#include <esat/input.h>
#include <esat_extra/imgui.h>

#include "interface.h"
#include "game_data.h"

void MainMenu(GameData* game_data) {

    float fontSize = ImGui::GetFontSize();

    ImVec2 windowSize(600, 500);
    ImVec2 windowPos(
        (kWindow_width - windowSize.x) * 0.5f,
        (kWindow_height - windowSize.y) * 0.5f
    );

    ImGui::SetNextWindowPos(windowPos);
    ImGui::SetNextWindowSize(windowSize);

    //ImGui::SetNextWindowBgAlpha(0.0f);

    ImGui::Begin("Main Menu", NULL,
        ImGuiWindowFlags_NoTitleBar | 
        ImGuiWindowFlags_NoResize |   
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoSavedSettings); 

    ImVec2 buttonSize(windowSize.x, 120);

    ImGui::Dummy(ImVec2(0, 30.0f));

    ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(0, 89, 79, 255));

    if (ImGui::Button("Start Game", buttonSize)) {
        game_data->window_type = TWindowType::kTWindowType_StartGame;
    }

    //Spacing between buttons
    ImGui::Dummy(ImVec2(0, 180.0f));

    if (ImGui::Button("Quit", buttonSize)) {
        game_data->window_type = TWindowType::kTWindowType_QuitGame;
    }

    ImGui::PopStyleColor();

    ImGui::End();
}

void DebugWindow(GameData* info) {
    if (esat::IsKeyDown('D')) {
        info->isDebugWindowVisible = !info->isDebugWindowVisible;
    }

    if (info->isDebugWindowVisible) {
        ImVec2 windowSize(20, 30);

        ImGui::PushID(info);

        if (ImGui::Button("Stop Ball")) {
            info->ball.speed.x = 0.0f;
            info->ball.speed.y = 0.0f;
        }
        if (ImGui::Button("Resume Ball")) {
            info->ball.speed.x = 2.0f;
            info->ball.speed.y = 2.0f;
        }

        ImGui::DragFloat2("Ball position", &info->ball.position.x);

        for (int i = 0; i < kBrick_cols; ++i) {
            for (int j = 0; j < kBrick_rows; ++j) {
                if (i == 0 && j == 0) {
                    ImGui::DragFloat2("Bricks position", &info->brick[i][j].position.x);
                }
            }
        }

        ImGui::PopID();
    }
}
















