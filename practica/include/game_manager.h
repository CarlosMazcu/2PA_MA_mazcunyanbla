/**
 * @file game_manager.h
 * @author Lucas Calatayud Briva <calatayudbri@esat-alumni.com>
 * @brief header with game manager class that manage variables of general scope
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

#include "path.h"
#include "gsprite.h"
#include <esat_extra/soloud/soloud.h>
#include <esat_extra/soloud/soloud_wav.h>

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
    bool welcome, parallax, path, exit, credits;
  };
  
  TWindow window_bool;


  struct TParallax
  {
    Sprite space[2];
    Sprite clouds[6];
    Sprite mountains[8];
    Sprite smallTrees[8];
    Sprite bigTrees[8];
    Sprite grass[2];
  };

  struct TSprite
  {
    Sprite manektrik[4];
    Sprite maincharacter[8];
    Sprite volbeat[2];
    Sprite torchic[5];
    Sprite flygon;
    TParallax parallax;
  };

  struct TAnimationConfig
  {
    AnimationConfig ac_manektrik_;
    AnimationConfig ac_maincharacter_;
    AnimationConfig ac_volbeat_;
    AnimationConfig ac_torchic_;
    AnimationConfig ac_flygon_;
  };

  TAnimationConfig all_config_;

  TSprite all_sprites;

  float incr_speed_;


  enum
  {
    kWelcomeWindow = 0,
    kParallaxWindow = 1,
    kTransformWindow = 2,
    kExitWindow = 3,
    kCreditsWindow = 4,
  };

  //audio variables
  SoLoud::Soloud soloud_;
  SoLoud::Wav sample_[4];
  int controller_;
  int change_sample_;
  float volume_;
  float music_counter_;
  float max_music_time_;
  std::string sample_name_; 
  bool available_audio;
  Path mypath_;
  int compare_vertex_;

  float strk_color_[4];
  float f_color_[4];

  Vec2 windowSize = {640.0f, 480.0f};

  bool torchic_fall;
  bool torchic_lying;
  
  float current_time, last_time, dt;
 private:
  GameManager(){}; //this MAY change :)
  GameManager(const GameManager& other){};

  static GameManager* instance_; 
};


#endif