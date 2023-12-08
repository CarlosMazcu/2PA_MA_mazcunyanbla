// /**
//  * @file animation.h
//  * @author 
//  * @brief 
//  * @version 0.1
//  * @date 2023-11-28
//  * 
//  * @copyright Copyright (c) 2023
//  * 
//  */

// #ifndef __ANIMATION_H__
// #define __ANIMATION_H__ 1

// #include <stdint.h>
// #include "vector_2.h"

// //Animation Config
// struct AnimationConfig
// {
//     // Flags
//     uint8_t is_moving;
//     uint8_t is_rotating;
//     uint8_t is_scaling;
//     // Move
//     Vec2 move_from;
//     Vec2 move_to;
//     float move_duration;
//     // Rotation
//     float rotate_from;
//     float rotate_to;
//     float rotate_duration;
//     // Scale
//     Vec2 scale_from;
//     Vec2 scale_to;
//     float scale_duration;
// };

// void InitAnimationConfig(AnimationConfig& ac);

// //Animation Instance
// class AnimationInstance
// {
// public:
//     AnimationInstance();
//     AnimationInstance(const AnimationConfig& ac, Entity* entity);
//     ~AnimationInstance();

//     void update(float dt);
//     bool done() const;

//     //For debugging
//     void progress(float* movement_alpha, float* movement_elapsed);

// protected:
//   AnimationConfig config_;
//   Entity* target_;
//   //Movement related variables
//   bool move_done_;
//   float move_alpha_;
//   float move_elapsed_;
  
// private:
//   AnimationInstance(const AnimationInstance& other){}

// };

// #endif 