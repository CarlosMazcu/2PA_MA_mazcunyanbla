/**
 * @file entity.h
 * @author Lucas Calatayud (calatayudbri@esat-alumni.com)
 * @brief
 * @version 0.1
 * @date 2023-11-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#ifndef __ENTITY_H__
#define __ENTITY_H_ 1

#include "../deps/math_library/include/vector_2.h"
#include <stdint.h>
#include <string>

// struct AnimationConfig;
/* class AnimationInstance;
*/
class Entity{
  public:
    Entity();
    Entity(const Entity& copy);
    Entity(int tag, bool enable, Vec2 pos, float rot, Vec2 scale);
// virtual ~Entity();
    void init(int tag, bool enable, Vec2 pos, float rot, Vec2 scale, float speed);

// void PlayAnimation(const AnimationConfig &ac);

    // void stopAnimation();
 
    /* void update(float dt); */

    uint64_t id() const;

    // transform methods
    void set_position(const Vec2& pos);
    void set_rotation(const float rads);
    void set_scale(const Vec2& scale);
    virtual void draw();
    Vec2 position() const;
    float rotation() const;
    Vec2 scale() const;

    //attributes
    int tag_;
    bool enable_;
    Vec2 position_;
    float speed_;
    

  protected:
    float rotation_;
    Vec2 scale_;
    // AnimationInstance *animation_;

  private:
  uint64_t id_;
  static uint64_t next_id_;
};


void initAllEntityParallax();

void initAllEntityCharacter();

void updateParallax();

void drawParallax();

void drawSprites();

void animManektrik();

void animMainCharacter();

void animVolbeat();

void animTorchic();


#endif