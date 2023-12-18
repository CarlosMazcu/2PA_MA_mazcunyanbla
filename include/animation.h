/**
 * @file animation.h
 * @author Lucas Calatayud Briva <calatayudbri@esat-alumni.com>
 * @brief Header with Animation Class and Config that manage the movement, scale and rotation of entitiesS
 * @version 1.7
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __ANIMATION_H__
#define __ANIMATION_H__ 1

#include <stdint.h>
#include "vector_2.h"

class Entity;
/**
 * @brief Animation Configuration structure.
 *
 * Holds flags and parameters for movement, rotation, and scaling animations.
 */
//Animation Config
struct AnimationConfig
{
    // Flags
    uint8_t is_moving;
    uint8_t is_rotating;
    uint8_t is_scaling;
    // Move
    Vec2 move_from;
    Vec2 move_to;
    float move_duration;
    // Rotation
    float rotate_from;
    float rotate_to;
    float rotate_duration;
    // Scale
    Vec2 scale_from;
    Vec2 scale_to;
    float scale_duration;
};
/**
 * @brief Initializes an AnimationConfig structure with default values.
 *
 * @param ac AnimationConfig structure to be initialized.
 */
void InitAnimationConfig(AnimationConfig& ac);

/**
 * @brief Animation Instance class.
 *
 * Manages animation state and logic for movement, rotation, and scaling animations.
 */
//Animation Instance
class AnimationInstance
{
public:
    /**
    * @brief Default constructor for AnimationInstance.
    *
    * This constructor initializes an instance of AnimationInstance with default values.
    * The default values include an initialized AnimationConfig, a null target,
    * and flags indicating completion for move, scale, and rotate animations.
    * The alpha values and elapsed times for move, scale, and rotate animations are set to default values.
    */
    AnimationInstance();
    /**
    * @brief Constructor for AnimationInstance with specified AnimationConfig and target Entity.
    *
    * This constructor initializes an instance of AnimationInstance with the provided AnimationConfig
    * and associates it with a target Entity. The constructor sets flags and values for move, scale, and rotate animations
    * based on the configuration provided.
    *
    * @param ac The AnimationConfig specifying the animation parameters.
    * @param entity Pointer to the target Entity for the animation.
    */
    AnimationInstance(const AnimationConfig& ac, Entity* entity);
    /**
    * @brief Destructor for AnimationInstance.
    *
    * This destructor cleans up resources associated with the AnimationInstance.
    * It sets the target Entity pointer to nullptr.
    */
    ~AnimationInstance();
    /**
    * @brief Update the AnimationInstance based on the elapsed time.
    *
    * Updates the state of the AnimationInstance, applying changes to the target Entity's
    * position, scale, and rotation based on the elapsed time (dt) and the configured animation parameters.
    *
    * @param dt (Delta Time) The elapsed time since the last update, in seconds.
    */
    void update(float dt);
    /**
    * @brief Check if the animation is completed.
    *
    * This method returns a boolean value indicating whether the animation is completed.
    * The return value is based on the state of the movement animation; if true, the animation is done.
    *
    * @return True if the animation is completed, false otherwise.
    */
    bool done() const;

    //For debugging
    /**
    * @brief Get the progress of the movement animation.
    *
    * This method provides the current progress of the movement animation
    * by returning the movement alpha value and elapsed time.
    *
    * @param movement_alpha Pointer to a float variable to store the movement alpha value.
    * @param movement_elapsed Pointer to a float variable to store the movement elapsed time.
    */
    void progress(float* movement_alpha, float* movement_elapsed);
    AnimationConfig config_;


 protected:
   Entity* target_;
   //Movement related variables
   bool move_done_;
   float move_alpha_;
   float move_elapsed_;

   //scale related variables
   bool scale_done_;
   float scale_alpha_;
   float scale_elapsed_;

   //rotate variables
   bool rotate_done_;
   float rotate_alpha_;
   float rotate_elapsed_;
  
 private:
   AnimationInstance(const AnimationInstance& other){} 
};
#endif 