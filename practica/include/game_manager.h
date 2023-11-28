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

#include "path.h"

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
 
    bool welcome, parallax, transform, exit;
  
 private:
  GameManager(){}; //this MAY change :)
  GameManager(const GameManager& other){};

  static GameManager* instance_; 
};


#endif