/**
 * @file main.cc
 * @author Carlos Mazcuñán Blanes <mazcunyanbla@esat-alumni.com>
 * @brief Source code for main.cc
 * 
 * three methods: to initialize, to update and to release
 * 
 * @version 0.1
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat_extra/soloud/soloud.h>
#include <esat_extra/soloud/soloud_wav.h>

#include "game.h"

int esat::main(int argc, char **argv) {
  game g;

  g.init();
  g.gameLoop();
  g.finish();

  return 0;
}