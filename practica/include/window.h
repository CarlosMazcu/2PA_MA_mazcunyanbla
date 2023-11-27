
#ifndef __WINDOW_H__
#define __WINDOW_H__ 1

#include "esat_extra\imgui.h"
//combo bools to do a state machine
struct TMachine{
  bool welcome, parallax, transform, exit;
};


void welcomeWindow();

#endif