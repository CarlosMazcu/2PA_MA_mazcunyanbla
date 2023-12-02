#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat_extra/soloud/soloud.h>
#include <esat_extra/soloud/soloud_wav.h>

#include "app_window.h"
#include "gtexture.h"
#include "gsprite.h"



/* void RenderFPS() {
  static double last_time = esat::Time();
  double current_time = esat::Time();
  double fps = 1000.0 / (current_time - last_time);
  std::stringstream ss;
  ss << "FPS = " << std::setprecision(2) << std::fixed << fps;
  esat::DrawSetFillColor(0, 255, 255, 255);
  esat::DrawSetTextSize(40);
  esat::DrawSetTextBlur(0);
  esat::DrawText(10, 45, ss.str().c_str());
  last_time = current_time;
}
 */

void Test() {
  GameManager &GM = GameManager::Instance();
  GM.sample_[0].load("../data/music/emerald.ogg");
  GM.sample_[1].load("../data/music/anime.ogg");
  GM.sample_[2].load("../data/music/league.wav");
  GM.sample_[3].load("../data/music/red.ogg");

  windowManager(0); 
  esat::WindowInit((int)GM.windowSize.x, (int)GM.windowSize.y);
  esat::DrawSetTextFont("../data/test.ttf");
  darkTaronja();

  esat::WindowSetMouseVisibility(true);
  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)
          && false == GM.window_bool.exit){
    GM.dt = (GM.last_time - GM.current_time) / 1000.0f;
    /* GM.dt = (GM.current_time - GM.last_time) / 1000.0f; */
    GM.current_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    //HERE COMES GAME CLASS

    MainMenuBar();
    ImGui::ShowDemoWindow();
    
    stateMachine();

    esat::DrawSetStrokeColor(255, 255, 255);
    /* RenderFPS(); */
    esat::DrawEnd();
    esat::WindowFrame();
    GM.last_time = esat::Time();
  }

  esat::WindowDestroy();
}

int esat::main(int argc, char **argv) {
  Test();
  return 0;
}