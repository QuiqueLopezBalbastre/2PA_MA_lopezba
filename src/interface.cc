#include <esat/draw.h>
#include <esat_extra/imgui.h>
#include "../include/interface.h"
#include "../include/variables.h"

void MainMenu(){

    esat::DrawSetTextFont("./resources/font/Arka_solid.ttf");
	esat::DrawSetFillColor(255, 255, 255);
    esat::DrawSetTextSize(120.0f);
    esat::DrawText(260, 200, "Breakout");
    
    ImVec2 windowSize(500, 350);
    ImGui::SetNextWindowPos(ImVec2((kWindowWidth - windowSize.x) * 0.5f, (kWindowHeight - windowSize.y) * 0.5f + 50));

    ImGui::Begin("                                 Menu", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

    ImVec2 rect1Pos((windowSize.x - 100) * 0.5f, (windowSize.y - 50) * 0.4f);
    ImVec2 rect2Pos((windowSize.x - 100) * 0.5f, (windowSize.y - 50) * 0.4f + 70);

    ImGui::SetCursorPos(rect1Pos);
    if (ImGui::Button("Start Game", ImVec2(100, 40))) {
        window_type = TWindowType::start_game;
    }

    ImGui::SetCursorPos(rect2Pos);
    if(ImGui::Button("Quit", ImVec2(100, 40))) {
        window_type = TWindowType::quit_game;
    }

    ImGui::End();
    ImGui::Render();
}









