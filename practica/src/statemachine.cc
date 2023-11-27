

#include "statemachine.h"

void welcomeWindow(TMachine *conf){
  ImGui::SetNextWindowSize(ImVec2(300, 400));
  ImGui::SetNextWindowPos(ImVec2(250, 230));

  ImGui::Begin("WELCOME", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);

  ImGui::Spacing();
  ImGui::SameLine(0.0f, 90.0f);
  if (ImGui::Button("Parallax", ImVec2(100.0f, 20.0f)))
  {

  }
  ImGui::Separator();
  ImGui::Spacing();
  ImGui::SameLine(0.0f, 90.0f);
  if (ImGui::Button("Transform", ImVec2(100.0f, 20.0f)))
  {

  }
  ImGui::Separator();
  ImGui::Spacing();
  ImGui::SameLine(0.0f, 90.0f);
  if (ImGui::Button("[...]", ImVec2(100.0f, 20.0f)))
  {

  }
  ImGui::Separator();
  ImGui::Spacing();
  ImGui::SameLine(0.0f, 90.0f);
  if (ImGui::Button("Credits", ImVec2(100.0f, 20.0f)))
  {

  }
  for (int i = 0; i < 45; i++)
  {
    ImGui::Spacing();
  }
  ImGui::SameLine(0.0f, 90.0f);

  if (ImGui::Button("Exit", ImVec2(100.0f, 20.0f)))
  {
    conf->exit = true;
  }
  ImGui::End();
}