#include "game.h"
#include "game_manager.h"

void initAllAnimationConfig()
{
  initAnimationConfigFlygon();
  initAnimationConfigManektrik();
  initAnimationConfigMainCharacter();
  initAnimationConfigVolbeat();
  initAnimationConfigTorchic();
}

void updateAllAnimation()
{
  GameManager &GM = GameManager::Instance();
  updateAnimationFlygon();
  updateAnimationManektrik();
  updateAnimationMainCharacter();
  updateAnimationVolbeat();
  updateAnimationTorchic();
}

void initAnimationConfigFlygon()
{
  GameManager &GM = GameManager::Instance();
  GM.all_sprites.flygon.phase_ = 0;
  GM.all_config_.ac_flygon_ = {
            1, 0, 1, 
            {-(float)GM.all_sprites.flygon.width(), 100.0f}, {-(float)GM.all_sprites.flygon.width(), 100.0f}, 5.5f, 
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
              {GM.windowSize.x / 1.5f, 400.0f / 1.5f}, {GM.windowSize.x / 1.5f, 400.0f / 1.5f}, 1.5f, 
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
      1, 0, 0, {630.0f / 1.5f, 210.0f}, {600.0f / 1.5f, 210.0f}, 1.0f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

  for (int i = 0; i < 8; i++)
  {
    GM.all_sprites.maincharacter[i].phase_ = 0;
    GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,
                                                                   &GM.all_sprites.maincharacter[i]);
  }
}

void initAnimationConfigVolbeat()
{
  GameManager &GM = GameManager::Instance();
  GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {GM.windowSize.x / 1.5f, 225.0f},{GM.windowSize.x / 1.5f, 225.0f},2.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 0.0f };
  for(int i = 0; i < 2; i++)
  {
    GM.all_sprites.volbeat[i].phase_ = 0;
    GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                &GM.all_sprites.volbeat[i]);
  }
}

void initAnimationConfigTorchic()
{
  GameManager &GM = GameManager::Instance();
  GM.all_config_.ac_torchic_ = {
      1, 0, 0, {GM.windowSize.x / 1.5f, 250.0f}, {GM.windowSize.x / 1.5f, 250.0f}, 7.0f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
  for (int i = 0; i < 5; i++)
  {
    GM.all_sprites.torchic[i].phase_ = 0;
    GM.all_sprites.torchic[i].animation_ = new AnimationInstance(GM.all_config_.ac_torchic_, &GM.all_sprites.torchic[i]);
      }
}


void updateAnimationVolbeat()
{
  GameManager &GM = GameManager::Instance();
  for(int i = 0; i < 2; i++){
    if(GM.all_sprites.volbeat[i].animation_->config_.is_moving == 0)
    {
      GM.all_sprites.volbeat[i].phase_++;

      if(GM.all_sprites.volbeat[i].phase_ > 16)
      {
        GM.all_sprites.volbeat[i].phase_ = 0;
      }

      switch (GM.all_sprites.volbeat[i].phase_)
      {
      case 0:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {GM.windowSize.x / 1.5f, 225.0f},{GM.windowSize.x / 1.5f, 225.0f},2.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 0.0f};

        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 1:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {GM.windowSize.x / 1.5f, 225.0f},{590.0f/ 1.5f, 225.0f},1.0f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 0.0f};
        
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 2:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {590.0f/ 1.5f, 225.0f},{530.0f/ 1.5f, 250.0f},1.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 0.0f};
        
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 3:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {530.0f/ 1.5f, 250.0f},{130.0f / 1.5f, 225.0f},1.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 0.0f};
        
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 4:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {130.0f / 1.5f, 225.0f},{130.0f / 1.5f, 225.0f},0.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 0.0f};
        
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 5:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {130.0f / 1.5f, 225.0f},{140.0f / 1.5f, 235.0f},0.3f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 0.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 6:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {140.0f / 1.5f, 235.0f},{140.0f / 1.5f, 235.0f},1.0f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 7:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {140.0f / 1.5f, 235.0f},{160.0f / 1.5f, 210.0f},0.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 8:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {160.0f / 1.5f, 210.0f},{160.0f / 1.5f, 210.0f},1.0f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 9:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {160.0f / 1.5f, 210.0f},{150.0f / 1.5f, 240.0f},0.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 10:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {150.0f / 1.5f, 240.0f},{150.0f / 1.5f, 240.0f},0.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 11:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {150.0f / 1.5f, 240.0f},{70.0f / 1.5f, 240.0f},1.0f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 12:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {70.0f / 1.5f, 240.0f},{70.0f / 1.5f, 240.0f},0.3f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 13:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {70.0f / 1.5f, 240.0f},{170 / 1.5f, 240.0f},1.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 14:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {170.0f / 1.5f, 240.0f},{170 / 1.5f, 240.0f},0.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 15:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {170.0f / 1.5f, 240.0f},{-120.0f / 1.5f, 240.0f},1.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 16:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {-120.0f / 1.5f, 240.0f},{-120.0f / 1.5f, 240.0f},7.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      default:
        break;
      }
    //23.1
    }
    GM.all_sprites.volbeat[i].animation_->update((GM.dt) * (GM.incr_speed_));
  }
}

void updateAnimationFlygon()
{
  GameManager &GM = GameManager::Instance();
  if (GM.all_sprites.flygon.animation_->config_.is_moving == 0)
  {
    GM.all_sprites.flygon.phase_++;
    if(GM.all_sprites.flygon.phase_ > 7)
    {
      GM.all_sprites.flygon.phase_ = 0;
    }
    switch (GM.all_sprites.flygon.phase_)
    {
    case 0:
      GM.all_config_.ac_flygon_ = {
          1, 0, 1, 
          {-(float)GM.all_sprites.flygon.width(), 100.0f}, {-(float)GM.all_sprites.flygon.width(), 100.0f}, 5.5f, 
          0.0f, 0.0f, 0.0f, 
          {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

      GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 1:
      GM.all_config_.ac_flygon_ = {
          1, 0, 1, 
          {-(float)GM.all_sprites.flygon.width(), 100.0f}, {GM.windowSize.x, 100.0f}, 2.5f, 
          0.0f, 0.0f, 0.0f, 
          {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

      GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;

    case 2:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {GM.windowSize.x, 40.0f}, {(GM.windowSize.x * 0.75f)/2.0f, 100.0f}, 1.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 1.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 3:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.75f)/2.0f, 100.0f}, {(GM.windowSize.x * 0.5f)/2.0f, 20.0f}, 1.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 2.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 4:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.5f)/2.0f, 20.0f}, {(GM.windowSize.x * 0.25f)/2.0f, 80.0f}, 2.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 3.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 5:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.25f)/2.0f, 80.0f}, {(GM.windowSize.x * 0.25f + 70.0f)/2.0f, 80.0f}, 2.0f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 2.0f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 6:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.25f + 70.0f)/2.0f, 80.0f}, {(-(float)GM.all_sprites.flygon.width()), 30.0f}, 2.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {0.25f, 0.25f}, 2.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 7:

        GM.all_config_.ac_flygon_ = {
            1, 0, 1, 
            {-(float)GM.all_sprites.flygon.width(), 30.0f}, {-(float)GM.all_sprites.flygon.width(), 30.0f}, 5.1f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {4.0f, 4.0f}, 1.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    default:
      break;
    }
    //23.1
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
      if (GM.all_sprites.manektrik[i].phase_ > 12)
      {
        GM.all_sprites.manektrik[i].phase_ = 0;
      }
      
      switch (GM.all_sprites.manektrik[i].phase_)
      {
      case 0:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {GM.windowSize.x / 1.5f, 400.0f / 1.5f}, {GM.windowSize.x / 1.5f, 400.0f / 1.5f}, 1.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 1:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {GM.windowSize.x / 1.5f, 400.0f / 1.5f}, {540.0f / 1.5f, 400.0f / 1.5f}, 1.0f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 2:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {540.0f / 1.5f, 400.0f / 1.5f}, {530.0f / 1.5f, 400.0f / 1.5f}, 1.0f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 3:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {530.0f / 1.5f, 400.0f / 1.5f}, {15.0f / 1.5f, 400.0f / 1.5f}, 3.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 4:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {15.0f / 1.5f, 400.0f / 1.5f}, {30.0f / 1.5f, 380.0f / 1.5f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 1.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 5:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {30.0f / 1.5f, 380.0f / 1.5f}, {50.0f / 1.5f, 360.0f / 1.5f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 1.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 6:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {50.0f / 1.5f, 360.0f / 1.5f}, {100.0f /1.5f, 360.0f / 1.5f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 7:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {100.0f / 1.5f, 360.0f/1.5f}, {120.0f/1.5f, 380.0f/1.5f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 8:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {120.0f/1.5f, 380.0f/1.5f}, {100.0f / 1.5f, 400.0f / 1.5f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 9:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {100.0f / 1.5f, 400.0f/ 1.5f}, {50.0f/ 1.5f, 400.0f/ 1.5f}, 0.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 10:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
              {50.0f/ 1.5f, 400.0f/ 1.5f}, {240.0f/ 1.5f, 400.0f/ 1.5f}, 2.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 11:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
             {240.0f/ 1.5f, 400.0f/ 1.5f}, {-150.0f/ 1.5f, 400.0f/ 1.5f}, 2.5f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      case 12:
            GM.all_config_.ac_manektrik_ = {
              1, 0, 0, 
             {-150.0f/ 1.5f, 400.0f/ 1.5f}, {-150.0f/ 1.5f, 400.0f/ 1.5f}, 8.1f, 
              0.0f, 0.0f, 0.0f, 
              {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
              
            GM.all_sprites.manektrik[i].animation_ = new AnimationInstance(GM.all_config_.ac_manektrik_,
                                                                       &GM.all_sprites.manektrik[i]);
        break;
      }
    }
    //total time 23.1
    GM.all_sprites.manektrik[i].animation_->update((GM.dt) * (GM.incr_speed_));
  }
}

void updateAnimationMainCharacter()
{
    //5 fases
    GameManager &GM = GameManager::Instance();
    for (int i = 0; i < 8; i++)
    {
      if (GM.all_sprites.maincharacter[i].animation_->config_.is_moving == 0)
      {
        GM.all_sprites.maincharacter[i].phase_++;
        if (GM.all_sprites.maincharacter[i].phase_ > 7)
        {
          GM.all_sprites.maincharacter[i].phase_ = 0;
        }

        switch (GM.all_sprites.maincharacter[i].phase_)
        {
        case 0:
          GM.all_config_.ac_maincharacter_ = {
              1, 0, 0, {630.0f  /1.5f, 210.0f}, {600.0f  /1.5f, 210.0f}, 1.0f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

          GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,
                                                                         &GM.all_sprites.maincharacter[i]);
          break;
        case 1:
          GM.all_config_.ac_maincharacter_ = {
              1, 0, 0, {600.0f  /1.5f, 210.0f}, {580.0f  /1.5f, 250.0f}, 1.5f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

          GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,
                                                                         &GM.all_sprites.maincharacter[i]);
          break;
        case 2:
          GM.all_config_.ac_maincharacter_ = {
              1, 0, 0, {580.0f /1.5f, 250.0f}, {580.0f /1.5f, 250.0f}, 3.0f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

          GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,
                                                                         &GM.all_sprites.maincharacter[i]);
          break;
        case 3:
          GM.all_config_.ac_maincharacter_ = {
              1, 0, 0, {580.0f /1.5f, 250.0f}, {50.0f /1.5f, 210.0f}, 1.5f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

          GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,
                                                                         &GM.all_sprites.maincharacter[i]);
          break;
        case 4:
          GM.all_config_.ac_maincharacter_ = {
            1, 0, 0, {50.0f /1.5f, 210.0f}, {510.0f /1.5f, 210.0f}, 3.5f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

          GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,
                                                                         &GM.all_sprites.maincharacter[i]);
          break;
        case 5:
          GM.all_config_.ac_maincharacter_ = {
              1, 0, 0, {510.0f /1.5f, 210.0f}, {510.0f /1.5f, 210.0f}, 2.3f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

          GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,
                                                                         &GM.all_sprites.maincharacter[i]);
          break;
        case 6:
          GM.all_config_.ac_maincharacter_ = {
              1, 0, 0, {510.0f /1.5f, 210.0f}, {-120.0f /1.5f, 210.0f}, 3.5f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

          GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,
                                                                         &GM.all_sprites.maincharacter[i]);
          break;
        case 7:
          GM.all_config_.ac_maincharacter_ = {
              1, 0, 0, {-120.0f /1.5f, 210.0f}, {-120.0f /1.5f, 210.0f}, 6.8f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};

          GM.all_sprites.maincharacter[i].animation_ = new AnimationInstance(GM.all_config_.ac_maincharacter_,
                                                                         &GM.all_sprites.maincharacter[i]);
          break;
        }
      }
      //23.1
      GM.all_sprites.maincharacter[i].animation_->update((GM.dt) * (GM.incr_speed_));
    }
}

void updateAnimationTorchic()
{
  GameManager &GM = GameManager::Instance();
  for(int i = 0; i < 5; i++)
  {
    if (GM.all_sprites.torchic[i].animation_->config_.is_moving == 0)
    {
      GM.all_sprites.torchic[i].phase_++;
      if(GM.all_sprites.torchic[i].phase_ > 6)
      {
        GM.all_sprites.torchic[i].phase_ = 0;
      }
      switch (GM.all_sprites.torchic[i].phase_)
      {
      case 0:
        GM.torchic_fall = false;
        GM.torchic_lying = false;
        GM.all_config_.ac_torchic_ = {
            1, 0, 0, {GM.windowSize.x /1.5f, 250.0f}, {GM.windowSize.x /1.5f, 250.0f}, 7.0f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
        GM.all_sprites.torchic[i].animation_ = new AnimationInstance(GM.all_config_.ac_torchic_,&GM.all_sprites.torchic[i]);
       
        break;
      case 1:
        GM.torchic_fall = false;
        GM.torchic_lying = false;
        GM.all_config_.ac_torchic_ = {
            1, 0, 0, {GM.windowSize.x /1.5f, 250.0f}, {550.0f /1.5f, 250.0f}, 3.5f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
        GM.all_sprites.torchic[i].animation_ = new AnimationInstance(GM.all_config_.ac_torchic_,&GM.all_sprites.torchic[i]);
       
        break;
      
      case 2:
        GM.torchic_fall = false;
        GM.torchic_lying = false;
        GM.all_config_.ac_torchic_ = {
            1, 0, 0, {550.0f /1.5f, 250.0f}, {590.0f /1.5f, 250.0f}, 4.5f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
        GM.all_sprites.torchic[i].animation_ = new AnimationInstance(GM.all_config_.ac_torchic_, &GM.all_sprites.torchic[i]);

        break;
      case 3:
        GM.torchic_fall = false;
        GM.torchic_lying = false;
        GM.all_config_.ac_torchic_ = {
            1, 0, 0, {590.0f /1.5f, 250.0f}, {550.0f /1.5f, 250.0f}, 1.3f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
        GM.all_sprites.torchic[i].animation_ = new AnimationInstance(GM.all_config_.ac_torchic_, &GM.all_sprites.torchic[i]);

        break;
        case 4:
        GM.torchic_fall = true;
        GM.all_config_.ac_torchic_ = {
            1, 0, 0, {550.0f /1.5f, 250.0f}, {GM.windowSize.x /1.5f, 250.0f}, 0.3f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
        GM.torchic_lying = true;
        GM.all_sprites.torchic[i].animation_ = new AnimationInstance(GM.all_config_.ac_torchic_, &GM.all_sprites.torchic[i]);

        break;
        case 5:
          GM.torchic_fall = true;
          GM.torchic_lying = true;
          GM.all_config_.ac_torchic_ = {
              1, 0, 0, {GM.windowSize.x /1.5f , 250.0f}, {690.0f /1.5f, 250.0f}, 3.0f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
          GM.all_sprites.torchic[i].animation_ = new AnimationInstance(GM.all_config_.ac_torchic_, &GM.all_sprites.torchic[i]);

          break;

        case 6:
          GM.torchic_fall = false;
          GM.all_config_.ac_torchic_ = {
              1, 0, 0, {690.0f /1.5f, 250.0f}, {-120.0f /1.5f, 250.0f}, 3.5f, 0.0f, 0.0f, 0.0f, {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
          GM.torchic_lying = false;
          GM.all_sprites.torchic[i].animation_ = new AnimationInstance(GM.all_config_.ac_torchic_, &GM.all_sprites.torchic[i]);
          break;
      }
    }
    //23.1
    GM.all_sprites.torchic[i].animation_->update((GM.dt) * (GM.incr_speed_));
  }
}