#ifndef __GAME_H__
#define __GAME_H__ 1

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
#include "entity.h"
#include "path.h"
#include "game_manager.h"

class game
{
public:
  game(/* args */);
  ~game();

void init();
void gameLoop();
void finish();
};


void initAllAnimationConfig();

void updateAllAnimation();

void initAnimationConfigFlygon();

void initAnimationConfigManektrik();

void initAnimationConfigMainCharacter();

void initAnimationConfigVolbeat();

void initAnimationConfigTorchic(); 

void updateAnimationFlygon();

void updateAnimationManektrik();

void updateAnimationMainCharacter();

void updateAnimationVolbeat();

void updateAnimationTorchic();

void initAllEntityParallax();

void initAllEntityCharacter();

void updateParallax();

void drawParallax();

void drawSprites();

void animManektrik();

void animMainCharacter();

void animVolbeat();

void animTorchic();

#endif