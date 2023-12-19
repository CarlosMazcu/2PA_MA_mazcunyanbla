/**
 * @file game.cc
 * @author Carlos Mazcuñán Blanes <mazcunyanbla@esat-alumni.com>
 * @brief source code for game.h 
 * 
 * @version 1.5
 * @date 2023-12-3
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "game.h"

game::game(){}
game::~game(){}

void game::init()
{
  GameManager &GM = GameManager::Instance();
  // load sample
  GM.sample_[0].load("../data/music/emerald.ogg");
  GM.sample_[1].load("../data/music/anime.ogg");
  GM.sample_[2].load("../data/music/league.wav");
  GM.sample_[3].load("../data/music/red.ogg");
  // set state (welcome window)
  windowManager(0);
  // set window position
  esat::WindowInit((int)GM.windowSize.x, (int)GM.windowSize.y);
  // set theme
  darkTaronja();
  // init some music variables and global speed
  GM.change_sample_ = 0;
  GM.max_music_time_ = 72.0f;
  GM.volume_ = 1.0f;
  GM.available_audio = true;
  GM.incr_speed_ = 1.0f;
  if (7 == GM.soloud_.init())
  {
    GM.available_audio = false;
  }
  esat::WindowSetMouseVisibility(true);
}

void game::gameLoop()
{
  GameManager &GM = GameManager::Instance();
  while (esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape) && false == GM.window_bool.exit)
  {
    GM.dt = (GM.last_time - GM.current_time) / 1000.0f;
    GM.current_time = (float)esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0, 0, 0);

    MainMenuBar();

    stateMachine();

    esat::DrawSetStrokeColor(255, 255, 255);
    esat::DrawEnd();
    esat::WindowFrame();
    GM.last_time = (float)esat::Time();
  }
}

void game::finish()
{
  GameManager &GM = GameManager::Instance();
  esat::WindowDestroy();
  if (GM.available_audio)
  {
    GM.soloud_.deinit();
  }
}


void initAllAnimationConfig()
{
  initAnimationConfigFlygon();
  initAnimationConfigManektrik();
  initAnimationConfigMainCharacter();
  initAnimationConfigVolbeat();
  initAnimationConfigTorchic();
  initAnimationStar();
}

void updateAllAnimation()
{
  updateAnimationFlygon();
  updateAnimationManektrik();
  updateAnimationMainCharacter();
  updateAnimationVolbeat();
  updateAnimationTorchic();
  updateStarAnimation();
}

void initStar()
{
  GameManager &GM = GameManager::Instance();
  float angle = 6.28f / 10.0f;
  for (int i = 0; i < 10; ++i)
  {
    if(i%2==0)
    {
      GM.star_.addVertex({cosf(i * angle), sinf(i * angle)});
    }else{
      GM.star_.addVertex({cosf(i * angle) * 0.55f, sinf(i * angle)  * 0.55f});
    }
  }
  GM.star_.is_path_ = true;
  GM.star_.fill_color_ = {255.0f, 255.0f, 255.0f,255.0f};
  GM.star_.Entity::init(13, true, {0.0f, 0.0f}, 0.0f, {10.0f, 10.0f},0.0f);
}

void initAnimationConfigFlygon()
{
  GameManager &GM = GameManager::Instance();
  GM.all_sprites.flygon.phase_ = 0;
  GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {-(float)GM.all_sprites.flygon.width(), 100.0f}, {-(float)GM.all_sprites.flygon.width(), 600.0f}, 5.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

  GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
}

void initAnimationStar(){
  GameManager &GM = GameManager::Instance();
  GM.star_.phase_ = 0;
  GM.all_config_.ac_star_ = {
            1, 0, 0, 
            {-10.0f, 100.0f}, {(GM.windowSize.x + 50.0f), 100.0f}, 1.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

  GM.star_.animation_ = new AnimationInstance(GM.all_config_.ac_star_,
                                                               &GM.star_);

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
                {GM.windowSize.x / 1.5f, 225.0f},{GM.windowSize.x / 1.5f / 0.5f, 225.0f},2.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 2.5f };
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

      if(GM.all_sprites.volbeat[i].phase_ > 17)
      {
        GM.all_sprites.volbeat[i].phase_ = 0;
      }

      switch (GM.all_sprites.volbeat[i].phase_)
      {
      case 0:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {GM.windowSize.x / 1.5f, 225.0f},{GM.windowSize.x / 1.5f / 0.5f, 225.0f},2.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};

        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 1:
        GM.all_config_.ac_volbeat_ = {
                1, 0,0,
                {GM.windowSize.x / 1.5f / 0.5f, 225.0f},{590.0f/ 1.5f, 225.0f},1.0f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
        
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
        GM.all_sprites.volbeat[i].origin_pos_ = {170.0f, 240.0f * 1.5f};
        GM.all_config_.ac_volbeat_ = {
                1, 1, 0,
                {0.0f, 0.0f},{-80.0f, 0.0f},1.5f,
                0.0f,(3.14159265f * 2.0f)/*  * 2.0f */,1.5f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 16:
        GM.all_sprites.volbeat[i].origin_pos_ = {0.0f, 0.0f};
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {170.0f / 1.5f - 80.0f, 240.0f},{-120.0f / 1.5f, 240.0f},1.5f,
                0.0f,0.0f,0.0f,
                {1.0f, 1.0f},{1.0f,1.0f}, 1.0f};
          
        GM.all_sprites.volbeat[i].animation_ = new AnimationInstance(GM.all_config_.ac_volbeat_,
                                                                       &GM.all_sprites.volbeat[i]);
        break;
      case 17:
        GM.all_config_.ac_volbeat_ = {
                1, 0, 0,
                {-120.0f / 1.5f, 240.0f},{-120.0f / 1.5f, 240.0f},6.0f,
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

void updateStarAnimation(){
  GameManager &GM = GameManager::Instance();
  if(GM.star_.animation_->config_.is_moving == 0)
  {
    GM.star_.phase_++;
    if(GM.star_.phase_ > 4)
    {
      GM.star_.phase_ = 0;
    }
    switch (GM.star_.phase_)
    {
    case 0:
      GM.all_config_.ac_star_ = {
                1, 1, 0, 
                {-10.0f, 100.0f}, {(GM.windowSize.x + 50.0f), 100.0f}, 1.5f, 
                0.0f, 3.14159265f * 4.0, 1.5f, 
                {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

      GM.star_.animation_ = new AnimationInstance(GM.all_config_.ac_star_,
                                                               &GM.star_);
      break;
    case 1:
      GM.all_config_.ac_star_ = {
                1, 0, 0, 
                {GM.windowSize.x, 100.0f}, {610.0f, 120.0f}, 0.1f, 
                0.0f, (3.14159265f * 10.0f), 3.5f, 
                {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

      GM.star_.animation_ = new AnimationInstance(GM.all_config_.ac_star_,
                                                               &GM.star_);
      break;
    case 2:
      GM.all_config_.ac_star_ = {
                1, 0, 0, 
               {610.0f, 120.0f}, {580.0f, 90.0f}, 0.1f, 
                0.0f, (3.14159265f * 10.0f), 3.5f, 
                {1.0f, 1.0f}, {0.5f, 0.0f}, 2.5f};

      GM.star_.animation_ = new AnimationInstance(GM.all_config_.ac_star_,
                                                               &GM.star_);
      break;
    case 3:
      GM.all_config_.ac_star_ = {
                1, 1, 0, 
               {580.0f, 90.0f}, {200.0f, 120.0f}, 1.0f, 
                0.0f, (3.14159265f * 10.0f), 1.0f, 
                {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

      GM.star_.animation_ = new AnimationInstance(GM.all_config_.ac_star_,
                                                               &GM.star_);
      break;
    case 4:
      GM.all_config_.ac_star_ = {
                1, 0, 0, 
               {200.0f, 120.0f}, {-50.0f, 90.0f},1.0f, 
                0.0f, (0.0f), 1.0f, 
                {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

      GM.star_.animation_ = new AnimationInstance(GM.all_config_.ac_star_,
                                                               &GM.star_);
      break;

    
    
    default:
      break;
    }
  }
  GM.star_.animation_->update((GM.dt) * (GM.incr_speed_));

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
          1, 0, 0, 
          {(-(float)GM.all_sprites.flygon.width()), (100.0f)}, {-(float)GM.all_sprites.flygon.width(), 600.0f}, 5.5f, 
          0.0f, 0.0f, 0.0f, 
          {1.0f, 1.0f}, {2.0f, 2.0f}, 2.5f};

      GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 1:
      GM.all_config_.ac_flygon_ = {
          1, 0, 1, 
          {-(float)GM.all_sprites.flygon.width() / 1.5f, 600.0f / 1.5f}, {GM.windowSize.x * 2.0f /3.5f, 150.0f / 3.5f}, 2.5f, 
          0.0f, 0.0f, 0.0f, 
          {0.5f, 0.5f}, {2.0f, 2.0f}, 2.5f};

      GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;

    case 2:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {GM.windowSize.x * 2.0f / 3.5f, 150.0f / 3.5f}, {(GM.windowSize.x * 0.75f)/ 3.5f, 300.0f / 3.5f}, 1.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 1.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 3:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.75f)/ 3.5f, 300.0f/ 3.5f}, {(GM.windowSize.x * 0.5f)/ 3.5f, 100.0f/ 3.5f}, 1.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 2.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 4:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.5f)/ 3.5f, 100.0f / 3.5f}, {(GM.windowSize.x * 0.25f)/ 3.5f, 280.0f / 3.5f}, 2.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 3.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 5:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.25f) / 3.5f, 280.0f / 3.5f}, {(GM.windowSize.x * 0.25f + 70.0f) / 3.5f, 280.0f / 3.5f}, 2.0f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 2.0f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 6:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {(GM.windowSize.x * 0.25f + 70.0f) / 3.5f, 280.0f / 3.5f}, {(-(float)GM.all_sprites.flygon.width()) * 6.0f / 3.5f, 130.0f / 3.5f}, 2.5f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {0.25f, 0.25f}, 2.5f};
        
        GM.all_sprites.flygon.animation_ = new AnimationInstance(GM.all_config_.ac_flygon_,
                                                               &GM.all_sprites.flygon);
      break;
    case 7:

        GM.all_config_.ac_flygon_ = {
            1, 0, 0, 
            {-(float)GM.all_sprites.flygon.width() * 6.0f / 3.5f, 130.0f / 3.5f}, {-(float)GM.all_sprites.flygon.width() * 6.0f/ 3.5f, 130.0f / 3.5f}, 5.1f, 
            0.0f, 0.0f, 0.0f, 
            {1.0f, 1.0f}, {1.0f, 1.0f}, 0.0f};
        
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

void initAllEntityParallax()
{
  GameManager &GM = GameManager::Instance();
  Texture *text;

  //Space background
  text = text->TextureFactory("../data/parallax/Space_Background.png");
  for(int i = 0; i < 2; i++)
  {
    GM.all_sprites.parallax.space[i].texture_handle_ = text;
    GM.all_sprites.parallax.space[i].Entity::init(0, true, {(float)(i * GM.all_sprites.parallax.space[i].width()), 
                               -(float)(GM.all_sprites.parallax.space[i].height()/4)}, 0.0f, {1.0f, 1.0f}, 10.0f);
  }
  //Clouds
  text = text->TextureFactory("../data/parallax/near-clouds.png");
  for(int i = 0; i < 6; i++)
  {
    GM.all_sprites.parallax.clouds[i].texture_handle_ = text;
    GM.all_sprites.parallax.clouds[i].Entity::init(1, true, {(float)(i * GM.all_sprites.parallax.clouds->width()),
                                                            60.0f}, 0.0f, {2.0f, 2.0f}, 20.0f);
  }
  //mountains
  text = text->TextureFactory("../data/parallax/mountain.png");
  for(int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.mountains[i].texture_handle_ = text;
    GM.all_sprites.parallax.mountains[i].Entity::init(2, true, {(float)(i * GM.all_sprites.parallax.mountains->width()),
                                                      230.0f}, 0.0f, {1.0f, 1.0f}, 60.0f);
  }
  //small trees
  text = text->TextureFactory("../data/SpriteSheet/background_sheet.png");
  text->init(text->getHandle(), 526, 428, 220, 20);
  for(int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.smallTrees[i].texture_handle_ = text;
    GM.all_sprites.parallax.smallTrees[i].Entity::init(3, true, {(float)(i * GM.all_sprites.parallax.smallTrees->width()),
                                                       350.0f}, 0.0f, {1.0f, 1.0f}, 100.0f);
  }
  //bigtrees
  text = text->TextureFactory("../data/SpriteSheet/background_sheet.png");
  text->init(text->getHandle(), 265, 409, 253, 43);
  for (int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.bigTrees[i].texture_handle_ = text;
    GM.all_sprites.parallax.bigTrees[i].Entity::init(4, true, {(float)(i * GM.all_sprites.parallax.bigTrees->width()), 
                                                      330.0f}, 0.0f, {1.0f, 1.0f}, 150.0f);
  }
  text = text->TextureFactory("../data/parallax/grass.png");
  for (int i = 0; i < 2; i++)
  {
    GM.all_sprites.parallax.grass[i].texture_handle_ = text;
    GM.all_sprites.parallax.grass[i].Entity::init(5, true, {(float)(i * GM.all_sprites.parallax.grass->width()), 
                                                      300.0f}, 0.0f, {1.2f, 1.2f}, 230.0f);
  }
}

void initAllEntityCharacter()
{
  GameManager &GM = GameManager::Instance();

  
  // main character
  for (int i = 0; i < 8; i++)
  {
    Texture *text_main_character;
    text_main_character = text_main_character->TextureFactory("../data/SpriteSheet/main_character.png");
    text_main_character->init(text_main_character->getHandle(), 367 + (61 * i), 130, 44, 45);

    GM.all_sprites.maincharacter[i].texture_handle_ = text_main_character;
    GM.all_sprites.maincharacter[i].Entity::init(6, true, {61.0f, 100.0f}, 0.0f, {1.5f, 1.5f}, 20.0f);
  }
  // manektrik
  for (int i = 0; i < 4; i++)
  {
    Texture *text_manektrik;
    text_manektrik = text_manektrik->TextureFactory("../data/SpriteSheet/characters_sheet.png");
    text_manektrik->init(text_manektrik->getHandle(), i * 57, 0, 57, 46);

    GM.all_sprites.manektrik[i].texture_handle_ = text_manektrik;
    GM.all_sprites.manektrik[i].Entity::init(7, true, {100.0f, 200.0f}, 0.0f, {1.5f, 1.5f}, 20.0f);
  }
  //volbeat
  for (int i = 0; i < 2; i++)
  {
    Texture *text_volbeat;
    text_volbeat = text_volbeat->TextureFactory("../data/SpriteSheet/characters_sheet.png");
    text_volbeat->init(text_volbeat->getHandle(), 236 + (i * 30), 0, 24 + (i * 6), 27);

    GM.all_sprites.volbeat[i].texture_handle_ = text_volbeat;
    GM.all_sprites.volbeat[i].Entity::init(8, true, {27.0f, 160.0f}, 0.0f, {1.5f, 1.5f}, 20.0f);
  }
  //torchic
  for(int i = 0; i < 5; i++)
  {
    Texture *text_torchic;
    text_torchic = text_torchic->TextureFactory("../data/SpriteSheet/characters_sheet.png");
    text_torchic->init(text_torchic->getHandle(), 300 + (i * 25), 0, 24, 24);

    GM.all_sprites.torchic[i].texture_handle_ = text_torchic;
    GM.all_sprites.torchic[i].Entity::init(9, true, {30.0f, 200.0f}, 0.0f, {1.5f, 1.5f}, 20.f);
  }
  
  GM.torchic_fall = false;
  GM.torchic_lying = false;
  //flygon
  Texture *text_flygon;
  text_flygon = text_flygon->TextureFactory("../data/SpriteSheet/characters_sheet.png");
  text_flygon->init(text_flygon->getHandle(), 462, 0, 114, 40);
  GM.all_sprites.flygon.texture_handle_ = text_flygon;
  GM.all_sprites.flygon.Entity::init(10, true, {0.0f, 250.0f}, 0.0f, {1.5f, 1.5f}, 20.0f);
  
  initStar();



}

void updateParallax()
{
  GameManager &GM = GameManager::Instance();
  // space
  GM.all_sprites.parallax.space[0].position_.x += ((GM.all_sprites.parallax.space[0].speed_ * GM.dt) * GM.incr_speed_);
  GM.all_sprites.parallax.space[1].position_.x = GM.all_sprites.parallax.space[0].position_.x - GM.all_sprites.parallax.space[0].width() + 1;
  for (int i = 0; i < 2; i++)
  {
    if (GM.all_sprites.parallax.space[i].position_.x >=
        (float)((GM.all_sprites.parallax.space[i].width())))
    {
      GM.all_sprites.parallax.space[i].position_.x =
          -(float)(GM.all_sprites.parallax.space[i].width());
    }
  }

  
    //clouds
    for(int i = 0; i < 6; i++)
    {
      //move
      GM.all_sprites.parallax.clouds[i].position_.x += ((GM.all_sprites.parallax.clouds[i].speed_ * GM.dt) * GM.incr_speed_);
      //teleport
      if((GM.all_sprites.parallax.clouds[i].position_.x) >= GM.windowSize.x)
      {
        if(i == 5){
          GM.all_sprites.parallax.clouds[i].position_.x = GM.all_sprites.parallax.clouds[i - i].position_.x - GM.all_sprites.parallax.clouds[i].width();
        }else{
          GM.all_sprites.parallax.clouds[i].position_.x = GM.all_sprites.parallax.clouds[i + 1].position_.x - GM.all_sprites.parallax.clouds[i].width();
        }
      }
    }
    //mountains
    for(int i = 0; i < 8; i++)
    {
      GM.all_sprites.parallax.mountains[i].position_.x += ((GM.all_sprites.parallax.mountains[i].speed_ * GM.dt) * GM.incr_speed_);
      if ((GM.all_sprites.parallax.mountains[i].position_.x) >= GM.windowSize.x)
      {
        if (i == 7)
        {
          GM.all_sprites.parallax.mountains[i].position_.x = GM.all_sprites.parallax.mountains[i - i].position_.x - GM.all_sprites.parallax.mountains[i].width();
        }
        else
        {
          GM.all_sprites.parallax.mountains[i].position_.x = GM.all_sprites.parallax.mountains[i + 1].position_.x - GM.all_sprites.parallax.mountains[i].width();
        }
      }
    }
    //small trees
    for (int i = 0; i < 8; i++)
    {
      GM.all_sprites.parallax.smallTrees[i].position_.x += ((GM.all_sprites.parallax.smallTrees[i].speed_ * GM.dt) * GM.incr_speed_);
      if ((GM.all_sprites.parallax.smallTrees[i].position_.x) >= GM.windowSize.x)
      {
        if (i == 7)
        {
          GM.all_sprites.parallax.smallTrees[i].position_.x = GM.all_sprites.parallax.smallTrees[i - i].position_.x - GM.all_sprites.parallax.smallTrees[i].width();
        }
        else
        {
          GM.all_sprites.parallax.smallTrees[i].position_.x = GM.all_sprites.parallax.smallTrees[i + 1].position_.x - GM.all_sprites.parallax.smallTrees[i].width();
        }
      }
    }
    //big trees
    for (int i = 0; i < 8; i++)
    {
      GM.all_sprites.parallax.bigTrees[i].position_.x += ((GM.all_sprites.parallax.bigTrees[i].speed_ * GM.dt) * GM.incr_speed_);
      if ((GM.all_sprites.parallax.bigTrees[i].position_.x) >= GM.windowSize.x)
      {
        if (i == 7)
        {
          GM.all_sprites.parallax.bigTrees[i].position_.x = GM.all_sprites.parallax.bigTrees[i - i].position_.x - GM.all_sprites.parallax.bigTrees[i].width();
        }
        else
        {
          GM.all_sprites.parallax.bigTrees[i].position_.x = GM.all_sprites.parallax.bigTrees[i + 1].position_.x - GM.all_sprites.parallax.bigTrees[i].width();
        }
      }
    }
    //grass
    int first_pos = 0;
    if (GM.all_sprites.parallax.grass[0].position_.x > GM.all_sprites.parallax.grass[1].position_.x){first_pos = 0;}
    if (GM.all_sprites.parallax.grass[0].position_.x < GM.all_sprites.parallax.grass[1].position_.x){first_pos = 1;}
    if (0 == first_pos)
    {
      GM.all_sprites.parallax.grass[0].position_.x += ((GM.all_sprites.parallax.grass[0].speed_ * GM.dt) * GM.incr_speed_);
      GM.all_sprites.parallax.grass[0 + 1].position_.x = GM.all_sprites.parallax.grass[0].position_.x - GM.all_sprites.parallax.grass[1].width() + 2;
    }else if( 1 == first_pos)
    {
      GM.all_sprites.parallax.grass[1].position_.x += ((GM.all_sprites.parallax.grass[1].speed_ * GM.dt) * GM.incr_speed_);
      GM.all_sprites.parallax.grass[0].position_.x = GM.all_sprites.parallax.grass[1].position_.x - GM.all_sprites.parallax.grass[1].width() + 2;
    }

    for (int i = 0; i < 2; i++)
    {
      if (GM.all_sprites.parallax.grass[i].position_.x >=
          (float)((GM.all_sprites.parallax.grass[i].width())))
      {
        GM.all_sprites.parallax.grass[i].position_.x =
            -(float)(GM.all_sprites.parallax.grass[i].width());
      }
    }

}

void drawParallax()
{
  GameManager &GM = GameManager::Instance();
  //space
  for (int i = 0; i < 2; i++)
  {
    GM.all_sprites.parallax.space[i].draw();
  }
  //clouds
  for(int i = 0; i < 6; i++)
  {
    GM.all_sprites.parallax.clouds[i].draw();
  }
  //mountains
  for(int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.mountains[i].draw();
  }
  //small trees
  for (int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.smallTrees[i].draw();
  }
  //big trees
  for (int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.bigTrees[i].draw();
  }
  //grass
  for (int i = 0; i < 2; i++)
  {
     GM.all_sprites.parallax.grass[i].draw();
  }
}

void drawSprites()
{
  GameManager &GM = GameManager::Instance();
  
  animTorchic();
  animMainCharacter();
  animVolbeat();
  GM.all_sprites.flygon.draw();
  animManektrik();
}

void animManektrik()
{
  GameManager &GM = GameManager::Instance();

  static float counter = 0.0f;

  if(counter >= 0.0f && counter <= 0.1f)
  {
    GM.all_sprites.manektrik[0].draw();
  }
  else if(counter > 0.1f && counter <= 0.2f)
  {
    GM.all_sprites.manektrik[1].draw();
  }
  else if(counter > 0.2f && counter <= 0.3f)
  {
    GM.all_sprites.manektrik[2].draw();
  }
  else if(counter > 0.3f && counter <= 0.4f)
  {
    GM.all_sprites.manektrik[3].draw();
  }
  else {
    GM.all_sprites.manektrik[3].draw();
  }
  
  if(counter > 0.4f)
  {
    counter = 0.0f;
  }
  counter += (GM.dt * GM.incr_speed_);
}

void animMainCharacter()
{
  GameManager &GM = GameManager::Instance();
  static float counter = 0.0f;

  if(counter >= 0.0f && counter <= 0.1f)
  {
    GM.all_sprites.maincharacter[0].draw();
  }
  else if(counter > 0.1f && counter <= 0.2f)
  {
    GM.all_sprites.maincharacter[1].draw();
  }
  else if(counter > 0.2f && counter <= 0.3f)
  {
    GM.all_sprites.maincharacter[2].draw();
  }
  else if(counter > 0.3f && counter <= 0.4f)
  {
    GM.all_sprites.maincharacter[3].draw();
  }
  else if(counter > 0.4f && counter <= 0.5f)
  {
    GM.all_sprites.maincharacter[4].draw();
  }
  else if(counter > 0.5f && counter <= 0.6f)
  {
    GM.all_sprites.maincharacter[5].draw();
  }
  else if(counter > 0.6f && counter <= 0.7f)
  {
    GM.all_sprites.maincharacter[6].draw();
  }else{
    GM.all_sprites.maincharacter[6].draw();
  }
  if(counter > 0.7f)
  {
    counter = 0.0f;
  }
  counter += (GM.dt * GM.incr_speed_);
}

void animVolbeat()
{
  GameManager &GM = GameManager::Instance();
  static float counter = 0.0f;

  if(counter >= 0.0f && counter <= 0.1f)
  {
    GM.all_sprites.volbeat[0].draw();
  }
  else if(counter > 0.1f && counter <= 0.2f)
  {
    GM.all_sprites.volbeat[1].draw();
  }else{
    GM.all_sprites.volbeat[1].draw();
  }
  if(counter > 0.2f)
  {
    counter = 0.0f;
  }
  counter += (GM.dt * GM.incr_speed_);
}

void animTorchic()
{
  GameManager &GM = GameManager::Instance();
  static float counter = 0.0f;

  if(!GM.torchic_fall && !GM.torchic_lying){
    if(counter >= 0.0f && counter <= 0.1f)
    {
      GM.all_sprites.torchic[0].draw();
    }
    else if(counter > 0.1f && counter <= 0.2f)
    {
      GM.all_sprites.torchic[1].draw();
    }
    else if(counter > 0.2f && counter <= 0.3f)
    {
      GM.all_sprites.torchic[2].draw();
    }else{
      GM.all_sprites.torchic[2].draw();
    }
  }else if(GM.torchic_fall && !GM.torchic_lying){
    if(counter > 0.0f && counter <= 0.1f)
    {
      GM.all_sprites.torchic[3].draw();
    }
    else if(counter > 0.1f && counter <= 0.2f)
    {
      GM.all_sprites.torchic[4].draw();
    }else if(counter > 0.1f && counter <= 0.3f){
      GM.all_sprites.torchic[3].draw();
    }else{
      GM.all_sprites.torchic[4].draw();
    }
  }else if(GM.torchic_fall && GM.torchic_lying)
  {
      GM.all_sprites.torchic[4].draw();
  }

  if(counter > 0.3f)
  {
    counter = 0.0f;
  }
  counter += (GM.dt * GM.incr_speed_);
}
