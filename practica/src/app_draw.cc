#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>

#include "path.h"
#include "entity.h"

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
  esat::WindowInit(640, 480);
  esat::DrawSetTextFont("../data/test.ttf");

  std::vector<Path> entities;
  Path curretn_path;
  float origin_x = 0.0f;
  float origin_y = 0.0f;
  bool is_drawing = false;

  esat::WindowSetMouseVisibility(true);
  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    //Input
    float x = esat::MousePositionX();
    float y = esat::MousePositionY();

    //Update
    if(true == esat::MouseButtonDown(0)){
      if(false==is_drawing){
        is_drawing = true;
        curretn_path.addVertex({x, y});
        origin_x = x;
        origin_y = y;
      }else{//true == is_drawing
        is_drawing = false;
        curretn_path.addVertex({x, origin_y});
        curretn_path.addVertex({x, y});
        curretn_path.addVertex({origin_x, y});
        entities.push_back(curretn_path);
        curretn_path = Path();//TODO Implement path reset
      }
    }
    //Draw
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);
    for(int i = 0; i < entities.size(); i++){
      entities[i].draw();
    }
    // single line...
    //esat::DrawSetStrokeColor(255, 255, 255);
    //RenderFPS();
    esat::DrawEnd();
    esat::WindowFrame();
  }
  esat::WindowDestroy();
}

int esat::main(int argc, char **argv) {
  Test();
  return 0;
}
