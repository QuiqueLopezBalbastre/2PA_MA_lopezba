#include <esat/draw.h>
#include <esat_extra/imgui.h>

#include "interface.h"
#include "game_data.h"

void MainMenu() {

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
        game_data.window_type = TWindowType::kTWindowType_StartGame;
    }

    //Spacing between buttons
    ImGui::Dummy(ImVec2(0, 180.0f));

    if (ImGui::Button("Quit", buttonSize)) {
        game_data.window_type = TWindowType::kTWindowType_QuitGame;
    }

    ImGui::PopStyleColor();

    ImGui::End();
}















