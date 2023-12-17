#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat_extra/soloud/soloud.h>
#include <esat_extra/soloud/soloud_wav.h>

#include "game.h"

//TODO release sprites when click RETURN button in parallax window

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

int esat::main(int argc, char **argv) {
  game g;

  g.init();
  g.gameLoop();
  g.finish();

  return 0;
}