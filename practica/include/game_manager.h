/*
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
 private:
  GameManager(){}; //this MAY change :)
  GameManager(const GameManager& other){};

  static GameManager* instance_; 
};


#endif