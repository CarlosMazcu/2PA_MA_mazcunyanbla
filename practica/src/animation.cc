#include "animation.h"
#include "entity.h"


void InitAnimationConfig(AnimationConfig &ac)
{
    ac.is_moving = 0;
    ac.is_rotating = 0;
    ac.is_scaling = 0;

    ac.move_from = {0.0f,0.0f};
    ac.move_to = {0.0f, 0.0f};
    ac.move_duration = 0.0f;

    ac.rotate_from = 0.0f;
    ac.rotate_to = 0.0f;
    ac.rotate_duration = 0.0f;

    ac.scale_from = {1.0f,1.0f};
    ac.scale_to = { 1.0f, 1.0f };
    ac.scale_duration = 0.0f;
}


AnimationInstance::AnimationInstance()
{
    InitAnimationConfig(config_);
    target_ = nullptr;
    //move
    move_done_ = true;
    move_alpha_ = 1.0f;
    move_elapsed_ = 0.0f;

    //scale
    scale_done_ = true;
    scale_alpha_ = 1.0f;
    scale_elapsed_ = 0.0f;
}


AnimationInstance::AnimationInstance(const AnimationConfig& ac, Entity* entity) 
{
    config_ = ac;
    target_ = entity;
    //move
    if(1 == config_.is_moving){
        move_done_ = false;
        move_alpha_ = 0.0f;
        move_elapsed_ = 0.0f;
    }else{    
        move_done_ = true;
        move_alpha_ = 1.0f;
        move_elapsed_ = 0.0f;
    }
    //scale
    if(1 == config_.is_scaling)
    {
        scale_done_ = true;
        scale_alpha_ = 0.0f;
        scale_elapsed_ = 0.0f;
    }else{
        scale_done_ = true;
        scale_alpha_ = 1.0f;
        scale_elapsed_ = 0.0f;
    }
}

AnimationInstance::~AnimationInstance(){
    target_ = nullptr;
}

void AnimationInstance::update(float dt)
{
    //Movement
    if(1 == config_.is_moving)
    {
        move_elapsed_ += dt;
        //check if movement has arrived
        if(move_elapsed_ >= config_.move_duration)
        {
            //Movement has finished
            target_->set_position(config_.move_to);
            move_alpha_ = 1.0f;
            move_done_ = true;
            config_.is_moving = 0;
        }else{
            //The movement is not completed yet
            //Update the Entity's  position
            //LERP
            move_alpha_ = move_elapsed_ / config_.move_duration;
            Vec2 new_pos;
            new_pos = Vec2::Lerp(config_.move_from,config_.move_to, move_alpha_);
            target_->set_position(new_pos); 
        }
    }
    //scale
    if(1 == config_.is_scaling)
    {
        scale_elapsed_ += dt;
        //check if movement has arrived
        if(scale_elapsed_ >= config_.move_duration)
        {
            //Movement has finished
            target_->set_scale(config_.scale_to);
            scale_alpha_ = 1.0f;
            scale_done_ = true;
            config_.is_scaling = 0;
        }else{
            //The movement is not completed yet
            //Update the Entity's  position
            //LERP
            scale_alpha_ = scale_elapsed_ / config_.scale_duration;
            Vec2 new_scale;
            new_scale = Vec2::Lerp(config_.scale_from,config_.scale_to, scale_alpha_);
            target_->set_scale(new_scale); 
        }
    }
}

bool AnimationInstance::done() const
{
    return move_done_;
}

void AnimationInstance::progress(float *movement_alpha, float *movement_elpased){
    *movement_alpha = move_alpha_;
    *movement_elpased = move_elapsed_;
}