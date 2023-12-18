/**
 * @file animation.cc
 * @author Lucas Calatayud Briva <calatayudbri@esat-alumni.com>
 * @brief Source code for methods of Animation Class.
 * @version 1.7
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

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

    //rotate
    rotate_done_ = true;
    rotate_alpha_ = 1.0f;
    rotate_elapsed_ = 0.0f;
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
        scale_done_ = false;
        scale_alpha_ = 0.0f;
        scale_elapsed_ = 0.0f;
    }else{
        scale_done_ = true;
        scale_alpha_ = 1.0f;
        scale_elapsed_ = 0.0f;
    }
    //rotate
    if(1 == config_.is_rotating)
    {
        rotate_done_ = false;
        rotate_alpha_ = 0.0f;
        rotate_elapsed_ = 0.0f;
    }else{
        rotate_done_ = true;
        rotate_alpha_ = 1.0f;
        rotate_elapsed_ = 0.0f;
    }

}

AnimationInstance::~AnimationInstance(){
    target_ = nullptr;
}

float LerpFloat(float x, float y, float t)
{
    if(t > 1.0f || t < -1.0f){ t = 1.0f/t;}
    if(t < 0.0f){ t *= -1.0f;}
    return (x + (y - x) * t);
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
        //check if scale has arrived
        if(scale_elapsed_ >= config_.move_duration)
        {
            //scale has finished
            target_->set_scale(config_.scale_to);
            scale_alpha_ = 1.0f;
            scale_done_ = true;
            config_.is_scaling = 0;
        }else{
            //The scale is not completed yet
            //Update the Entity's  scale
            //LERP
            scale_alpha_ = scale_elapsed_ / config_.scale_duration;
            Vec2 new_scale;
            new_scale = Vec2::Lerp(config_.scale_from,config_.scale_to, scale_alpha_);
            target_->set_scale(new_scale); 
        }
    }
    if(1 == config_.is_rotating)
    {
        rotate_elapsed_+= dt;
        if(rotate_elapsed_ >= config_.rotate_duration)
        {
            target_->set_rotation(config_.rotate_to);
            rotate_alpha_ = 1.0f;
            rotate_done_ = true;
            config_.is_rotating = 0;
        }else{
            rotate_alpha_ = rotate_elapsed_ / config_.rotate_duration;
            float new_rotate = LerpFloat(config_.rotate_from, config_.rotate_to, rotate_alpha_);
            target_->set_rotation(new_rotate);
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