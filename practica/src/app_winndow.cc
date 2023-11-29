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
/* #include "gsprite.h" */


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
void MainMenuBar()
{
    if(ImGui::BeginMainMenuBar()) 
    {
        if (ImGui::BeginMenu("Test"))
        {
            
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}
void welcomeWindow()
{
    GameManager &GM = GameManager::Instance();
    ImGui::SetNextWindowSize(ImVec2(300, 400));
    ImGui::SetNextWindowPos(ImVec2(150, 200));

    ImGui::Begin("WELCOME", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);

    ImGui::Spacing();
    ImGui::SameLine(0.0f, 90.0f);
    if (ImGui::Button("Start Animation", ImVec2(100.0f, 20.0f)))
    {
       windowManager(2);

    }
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::SameLine(0.0f, 90.0f);
  
    if (ImGui::Button("Credits", ImVec2(100.0f, 20.0f)))
    {
        windowManager(1);
        // GM.credits = true;
    }
    for (int i = 0; i < 10; i++)
    {
        ImGui::Spacing();
    }
    ImGui::SameLine(0.0f, 90.0f);

    if (ImGui::Button("Exit", ImVec2(100.0f, 20.0f)))
    {
        windowManager(4);
    }
    ImGui::End();
}

void creditsWindow()
{
    GameManager &GM = GameManager::Instance();
    ImGui::SetNextWindowSize(ImVec2(600, 600));
    ImGui::SetNextWindowPos(ImVec2(50,50));
    ImGui::Begin("CREDITS", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
    
    ImGui::Text("ESAT Academic Project made by Lucas Calatayud and Carlos Mazcuñan");
    if (ImGui::Button("Return", ImVec2(100.0f, 20.0f)))
    {
       windowManager(0);
    }
    ImGui::End();
}

void parallaxWindow()
{
    GameManager &GM = GameManager::Instance();
    ImGui::SetNextWindowSize(ImVec2(300, 400));
    ImGui::SetNextWindowPos(ImVec2(150, 200));
    ImGui::Begin("PARALLAX", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
    if (ImGui::Button("Return", ImVec2(100.0f, 20.0f)))
    {
       windowManager(0);
    }
    ImGui::End();
   
}

void stateMachine()
{
    GameManager &GM = GameManager::Instance();

    if (GM.window_bool.welcome)
    {
      welcomeWindow();
    }
    if(GM.window_bool.credits)
    {
      creditsWindow();
    }
    if(GM.window_bool.parallax)
    {
      parallaxWindow();
    }

}