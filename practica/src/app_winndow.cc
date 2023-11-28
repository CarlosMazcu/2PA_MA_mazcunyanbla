/**
 * @file window_class.cc
 * @author 
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "app_window.h"


void welcomeWindow()
{
GameManager &GM = GameManager::Instance();
    ImGui::SetNextWindowSize(ImVec2(300, 400));
    ImGui::SetNextWindowPos(ImVec2(150, 200));

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
        GM.window_bool.welcome = false;
        // GM.credits = true;
    }
    for (int i = 0; i < 45; i++)
    {
        ImGui::Spacing();
    }
    ImGui::SameLine(0.0f, 90.0f);

    if (ImGui::Button("Exit", ImVec2(100.0f, 20.0f)))
    {
        // GM.exit = true;
    }
    ImGui::End();
}

void creditsWindow()
{
    GameManager &GM = GameManager::Instance();
    ImGui::SetNextWindowSize(ImVec2(300, 400));
    ImGui::SetNextWindowPos(ImVec2(150, 200));
    ImGui::Begin("CREDITS", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);

    ImGui::End();
}


void windowManager(int n)
{
    GameManager &GM = GameManager::Instance();
    switch (n)
    {
    case 0:
        GM.window_bool.welcome = true;
        GM.window_bool.credits = false;
        GM.window_bool.exit = false;
        GM.window_bool.parallax = false;
        GM.window_bool.transform = false;
        break;
    case 1:
        GM.window_bool.welcome = false;
        GM.window_bool.credits = true;
        GM.window_bool.exit = false;
        GM.window_bool.parallax = false;
        GM.window_bool.transform = false;
        break;
    case 2:
        GM.window_bool.welcome = false;
        GM.window_bool.credits = false;
        GM.window_bool.exit = false;
        GM.window_bool.parallax = true;
        GM.window_bool.transform = false;
        break;
    case 3:
        GM.window_bool.welcome = false;
        GM.window_bool.credits = false;
        GM.window_bool.exit = false;
        GM.window_bool.parallax = false;
        GM.window_bool.transform = true;
        break;
    case 4:
        GM.window_bool.welcome = false;
        GM.window_bool.credits = false;
        GM.window_bool.exit = true;
        GM.window_bool.parallax = false;
        GM.window_bool.transform = false;
        break;
    default:
        break;
    }
}