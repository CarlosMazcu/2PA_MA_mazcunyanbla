//
//
//

#include "entity.h"

Entity::Entity()
{
  tag_ = 0;
  enable_ = true;
  position_ = {0.0f, 0.0f};
  rotation_ = 0.0f;
  scale_ = {1.0f, 1.0f};
}


Entity::Entity(const Entity& copy)
{
  tag_ = copy.tag_;
  enable_ = copy.enable_;
  position_ = copy.position_;
  rotation_ = copy.rotation_;
  scale_ = copy.scale_;
}

Entity::Entity(int tag, bool enable, Vec2 pos, float rot, Vec2 scale) 
{
    tag_ = tag;
    enable_ = enable;
    position_ = pos; 
    rotation_ = rot;
    scale_ = scale;
}

void Entity::init()
{
  tag_ = 0;
  enable_ = true;
  position_ = {0.0f, 0.0f};
  rotation_ = 0.0f;
  scale_ = {1.0f, 1.0f};
    
}

void Entity::set_position(const Vec2& pos)
{
    position_ = pos;
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