/**
 * @file entity.cc
 * @author Lucas Calatayud (calatayudbri@esat-alumni.com)
 * @brief source code for entity.h
 * @version 0.1
 * @date 2023-11-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "entity.h"
#include "game_manager.h"

uint64_t Entity::next_id_ = 0;

Entity::Entity()
{
  tag_ = 0;
  enable_ = true;
  position_ = {0.0f, 0.0f};
  rotation_ = 0.0f;
  scale_ = {1.0f, 1.0f};
  speed_ = 1.0f;

  origin_rotation_ = 0.0f;
  origin_pos_ = {0.0f, 0.0f};
  animation_ = nullptr;

  is_path_ = false;

  id_ = Entity::next_id_;
  Entity::next_id_ ++;
}


Entity::Entity(const Entity& copy)
{
  tag_ = copy.tag_;
  enable_ = copy.enable_;
  position_ = copy.position_;
  rotation_ = copy.rotation_;
  scale_ = copy.scale_;
  animation_ = nullptr;

  is_path_ = false;


  id_ = Entity::next_id_;
  Entity::next_id_++;
}

Entity::Entity(int tag, bool enable, Vec2 pos, float rot, Vec2 scale) 
{
    tag_ = tag;
    enable_ = enable;
    position_ = pos; 
    rotation_ = rot;
    scale_ = scale;

}

/* Entity::~Entity()
{
  stopAnimation();
} */

void Entity::init(int tag, bool enable, Vec2 pos, float rot, Vec2 scale, float speed)
{
  tag_ = tag;
  enable_ = enable;
  position_ = pos;
  rotation_ = rot;
  scale_ = scale;
  speed_ = speed;
  animation_ = nullptr; 
}

void Entity::set_position(const Vec2& pos)
{
  if(!is_path_)
  {
    position_ = pos;
  }
  if(is_path_)
  {
    origin_pos_ = pos;
  }
}
void Entity::set_rotation(const float rads)
{
    rotation_ = rads;
}
void Entity::set_scale(const Vec2 &scale)
{
  scale_ = scale;
}

Vec2 Entity::position() const {
    return position_;
} 

float Entity::rotation() const
{
  return rotation_; 
}

Vec2 Entity::scale() const
{
    return scale_;
}

uint64_t Entity::id() const{
  return id_;
}

void Entity::draw(){}

void Entity::PlayAnimation(const AnimationConfig &ac) 
{
  stopAnimation();
  animation_ = new AnimationInstance(ac, this);
}


void Entity::update(float dt)
{
  if(true == enable_)
  {
    if(nullptr != animation_)
    {
      animation_->update(dt);
    }
  }
}

void Entity::stopAnimation()
{
  if(nullptr != animation_)
  {
    delete animation_;
    animation_ = nullptr;
  }
}
