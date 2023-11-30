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

#include "app_window.h"
#include "gtexture.h"
#include "gsprite.h"

void RenderFPS() {
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


void Test() {
  GameManager &GM = GameManager::Instance();
  windowManager(0); 
  esat::WindowInit(640, 480);
  esat::DrawSetTextFont("../data/test.ttf");
  darkTaronja();
 
  Texture *text;
  text = text->TextureFactory("../data/parallax/Space_Background.png");
  /* text->init(text->getHandle(), 0,0,57,46); */
  /* Sprite sp_test; 

  sp_test.position_ = {50.0f, 50.0f};
  sp_test.texture_handle_ = text; */
  for(int i = 0; i < 2; i++){
    GM.sp[i].texture_handle_ = text;
    GM.sp[i].position_ = {(float)(i * GM.sp[i].width()),  -(float)(GM.sp[i].height()/4)};
  }
/*   GM.sp[0].position_.x = 0.0f;
  GM.sp[1].position_.x = (float)GM.sp[1].width(); */



  esat::WindowSetMouseVisibility(true);
  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)
          && false == GM.window_bool.exit){
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
  }
  esat::WindowDestroy();
}

int esat::main(int argc, char **argv) {
  Test();
  return 0;
}