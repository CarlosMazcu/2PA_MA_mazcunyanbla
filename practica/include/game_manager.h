/**
 * @file game_manager.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

#include "gsprite.h"

class GameManager{
 public:
  static GameManager& Instance()
  {
    if(nullptr == instance_)
    {
      instance_ = new GameManager();
    }
    return *instance_;
  }
  // all globals go here
  struct TWindow
  {
    bool welcome, parallax, transform, exit, credits;
  };
  
  TWindow window_bool;

  Sprite sp[2];
  enum
  {
    kWelcomeWindow = 0,
    kParallaxWindow = 1,
    kTransformWindow = 2,
    kExitWindow = 3,
    kCreditsWindow = 4,
  };

 private:
  GameManager(){}; //this MAY change :)
  GameManager(const GameManager& other){};

  static GameManager* instance_; 
};


#endif