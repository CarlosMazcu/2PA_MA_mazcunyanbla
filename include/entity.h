/**
 * @file entity.h
 * @author Lucas Calatayud (calatayudbri@esat-alumni.com)
 * @brief header with entity class 
 * 
 * Entity class is the parent class with some general attributes 
 *
 * @version 0.1
 * @date 2023-11-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#ifndef __ENTITY_H__
#define __ENTITY_H_ 1

#include <stdint.h>
#include <string>
#include "../deps/math_library/include/vector_2.h"
#include "animation.h"

struct AnimationConfig;
class AnimationInstance;

/**
 * @brief Base class for game entities.
 *
 * The Entity class represents a basic game entity with properties such as position, scale, rotation, and visibility.
 * Derived classes can inherit from this class to create specific types of entities.
 */
class Entity{
  public:
    /**
    * @brief Constructor for the Entity class.
    * 
    * This constructor initializes an instance of the Entity class with default values.
    */
    Entity();
    /**
    * @brief Copy constructor for the Entity class.
    *
    * This constructor creates a new instance of the Entity class by copying the values
    * from an existing instance (copy).
    * @param copy The Entity object to be copied.
    */
    Entity(const Entity& copy);
    /**
    * @brief Parameterized constructor for the Entity class.
    *
    * This constructor creates an instance of the Entity class with specified values.
    *
    * @param tag The tag to assign to the entity.
    * @param enable A boolean indicating whether the entity is enabled or disabled.
    * @param pos The initial position (Vec2) of the entity.
    * @param rot The initial rotation angle of the entity.
    * @param scale The initial scale (Vec2) of the entity.
    */
    Entity(int tag, bool enable, Vec2 pos, float rot, Vec2 scale);
    /* virtual ~Entity(); */

    /**
    * @brief Initialize the Entity with specified values.
    *
    * This method initializes the attributes of the Entity with the specified values.
    *
    * @param tag The tag to assign to the entity.
    * @param enable A boolean indicating whether the entity is enabled or disabled.
    * @param pos The initial position (Vec2) of the entity.
    * @param rot The initial rotation angle of the entity.
    * @param scale The initial scale (Vec2) of the entity.
    * @param speed The speed of the entity.
    */
    void init(int tag, bool enable, Vec2 pos, float rot, Vec2 scale, float speed);
    /**
    * @brief Play an animation on the Entity.
    *
    * This method stops any currently playing animation and starts a new animation
    * with the specified configuration.
    *
    * @param ac The AnimationConfig object specifying the configuration of the animation.
    */
    void PlayAnimation(const AnimationConfig &ac);
    /**
    * @brief Stop the currently playing animation.
    *
    * This method stops the currently playing animation, if any, by deleting the
    * associated AnimationInstance object and setting the animation pointer to nullptr.
    */
    void stopAnimation();
    /**
    * @brief Update the Entity based on the elapsed time.
    *
    * Updates the state of the Entity, taking into account the elapsed time (dt).
    * If the entity is enabled and has an active animation, the animation is updated.
    *
    * @param dt The elapsed time since the last update, in seconds.
    */
    void update(float dt);
    /**
    * @brief Get the unique identifier of the Entity.
    *
    * Returns the unique identifier assigned to the Entity.
    *
    * @return The unique identifier of the Entity.
    */
    uint64_t id() const;

    // transform methods`
    /**
    * @brief Set the position of the Entity.
    *
    * This method sets the position of the Entity to the specified Vec2 coordinates.
    *
    * @param pos The Vec2 coordinates to set as the new position of the Entity.
    */
    void set_position(const Vec2& pos);
    /**
    * @brief Set the rotation angle of the Entity.
    *
    * Sets the rotation angle of the Entity to the specified value in radians.
    *
    * @param rads The rotation angle in radians to set for the Entity.
    */
    void set_rotation(const float rads);
    /**
    * @brief Set the scale of the Entity.
    *
    * Sets the scale of the Entity to the specified Vec2 values.
    *
    * @param scale The Vec2 values representing the new scale of the Entity.
    */
    void set_scale(const Vec2& scale);
    /**
    * @brief Draw the Entity.
    *
    * This method is responsible for drawing the visual representation of the Entity.
    * The actual drawing implementation details are expected to be defined in derived classes
    * or other components.
    */
    virtual void draw();
    /**
    * @brief Get the current position of the entity.
    *
    * Returns a Vec2 object representing the current coordinates of the entity.
    *
    * @return Vec2 object with the current coordinates of the entity.
    */
    Vec2 position() const;
    /**
    * @brief Get the current rotation angle of the entity.
    *
    * Returns the current rotation angle of the entity in radians.
    *
    * @return Current rotation angle of the entity in radians.
    */
    float rotation() const;
    /**
    * @brief Get the current scale of the entity.
    *
    * This method returns a Vec2 object representing the current scale values of the entity.
    *
    * @return Vec2 object with the current scale values of the entity.
    */
    Vec2 scale() const;

    //attributes
    int tag_;
    bool enable_;
    int phase_;

    Vec2 position_;
    
    float rotation_;
    Vec2 scale_;

    float origin_rotation_;
    Vec2 origin_pos_;
    
    float speed_;
    AnimationInstance *animation_;
    

  protected:

  private:
    uint64_t id_;
    static uint64_t next_id_;
};




#endif