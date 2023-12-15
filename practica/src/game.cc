#include "game.h"
#include "game_manager.h"

void initAllAnimationConfig()
{
  initAnimationConfigFlygon();
  initAnimationConfigManektrik();
  initAnimationConfigMainCharacter();
}

void updateAllAnimation()
{
  GameManager &GM = GameManager::Instance();
  updateAnimationFlygon();
  updateAnimationManektrik();
  updateAnimationMainCharacter();
}

void initAnimationConfigFlygon()
{
  GameManager &GM = GameManager::Instance();
  GM.all_sprites.flygon.phase_ = 0;
  GM.all_config_.ac_flygon_ = {
            1, 0, 1, 
            {-(float)GM.all_sprites.flygon.width(), 40.0f}, {GM.windowSize.x, 40.0f}, 2.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

  GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
}

void initAnimationConfigManektrik()
{
  GameManager &GM = GameManager::Instance();
  GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {GM.windowSize.x, 250.0f}, {15.0f, 250.0f}, 2.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
  for(int i = 0; i < 4; i++){  
    GM.all_sprites.manektrik[i].phase_ = 0;
    GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                               &GM.all_sprites.manektrik[i]);
  }
}

void initAnimationConfigMainCharacter()
{
  GameManager &GM = GameManager::Instance();

    GM.all_config_.ac_maincharacter_ = {
      1,0,0, 
          {GM.windowSize.x, (GM.windowSize.y / 2)}, {(GM.windowSize.x + GM.all_sprites.maincharacter[0].width()), (GM.windowSize.y / 2)}, 2.5f,
          0.0f,0.0f,0.0f,{1.0f,1.0f},{1.0f,1.0f},0.0f};
  for(int i = 0; i < 8; i++)
  {
    GM.all_sprites.maincharacter[i].phase_ = 0;
    GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,&GM.all_sprites.maincharacter[i]);
  }
}

void updateAnimationFlygon()
{
  GameManager &GM = GameManager::Instance();
  if (GM.all_sprites.flygon.animation_->config_.is_moving == 0)
  {
    GM.all_sprites.flygon.phase_++;
    if(GM.all_sprites.flygon.phase_ > 6)
    {
      GM.all_sprites.flygon.phase_ = 0;
    }
    switch (GM.all_sprites.flygon.phase_)
    {
    case 0:
      GM.all_config_.ac_flygon_ = {
          1, 0, 1, 
          {-(float)GM.all_sprites.flygon.width(), 40.0f}, {GM.windowSize.x, 40.0f}, 2.5f, 
          0.0f, 0.0f, 0.0f, 
          {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

      GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;

    case 1:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {GM.windowSize.x, 40.0f}, {(GM.windowSize.x * 0.75f)/2.0f, 100.0f}, 1.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 1.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 2:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.75f)/2.0f, 100.0f}, {(GM.windowSize.x * 0.5f)/2.0f, 20.0f}, 1.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 2.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 3:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.5f)/2.0f, 20.0f}, {(GM.windowSize.x * 0.25f)/2.0f, 80.0f}, 2.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 3.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 4:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.25f)/2.0f, 80.0f}, {(GM.windowSize.x * 0.25f + 70.0f)/2.0f, 80.0f}, 2.0f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 2.0f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 5:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.25f + 70.0f)/2.0f, 80.0f}, {(-(float)GM.all_sprites.flygon.width()), 30.0f}, 2.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {0.25f, 0.25f}, 2.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 6:

        GM.all_config_.ac_flygon_ = {
            1, 0, 1, 
            {-(float)GM.all_sprites.flygon.width(), 30.0f}, {-(float)GM.all_sprites.flygon.width(), 30.0f}, 1.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {4.0f, 4.0f}, 1.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    default:
      break;
    }
  }
  GM.all_sprites.flygon.animation_->update((GM.dt) * (GM.incr_speed_));
}

void updateAnimationManektrik()
{
  GameManager &GM = GameManager::Instance();
  for(int i = 0; i < 4; i++)
  {
    if (GM.all_sprites.manektrik[i].animation_->config_.is_moving == 0)
    {
      GM.all_sprites.manektrik[i].phase_++;
      if (GM.all_sprites.manektrik[i].phase_ > 7)
      {
        GM.all_sprites.manektrik[i].phase_ = 0;
      }
      
      switch (GM.all_sprites.manektrik[i].phase_)
      {
      case 0:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {GM.windowSize.x, 250.0f}, {15.0f, 250.0f}, 2.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 1:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {15.0f, 250.0f}, {30.0f, 230.0f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 2:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {30.0f, 230.0f}, {50.0f, 210.0f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 3:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {50.0f, 210.0f}, {100.0f, 210.0f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 4:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {100.0f, 210.0f}, {120.0f, 230.0f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 5:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {120.0f, 230.0f}, {100.0f, 250.0f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 6:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {100.0f, 250.0f}, {50.0f, 250.0f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 7:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {50.0f, 250.0f}, {GM.windowSize.x, 250.0f}, 3.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      }
    }
    GM.all_sprites.manektrik[i].animation_->update((GM.dt) * (GM.incr_speed_));
  }
}

void updateAnimationMainCharacter()
{
    //5 fases
  GameManager &GM = GameManager::Instance();
  for(int i = 0; i < 8; i++)
  {
  if(0 == GM.all_sprites.maincharacter[i].animation_->config_.is_moving)
  {
    GM.all_sprites.maincharacter[i].phase_++;

  if(GM.all_sprites.maincharacter[i].phase_ > 1)
  {
    GM.all_sprites.maincharacter[i].phase_ = 0;
  }
  
  switch (GM.all_sprites.maincharacter[i].phase_)
  {
    case 0:
      GM.all_config_.ac_maincharacter_ = {
          1, 0, 0, {300.0f, 120.0f}, {0.0f, 120.0f}, 5.5f,
          0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

      GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_, &GM.all_sprites.maincharacter[i]);
      break;
        case 1:

          GM.all_config_.ac_maincharacter_ = {
              1, 0, 0, {0.0f,120.0f}, {300.0f,120.0f},5.5f, 
              0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

          GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_, &GM.all_sprites.maincharacter[i]);
          break;
        
      }
    }
  }
  GM.all_sprites.maincharacter->animation_->update((GM.dt) * (GM.incr_speed_));
}
