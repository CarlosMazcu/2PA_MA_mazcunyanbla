//
//
//

#include "entity.h"
#include "animation.h"
#include "game_manager.h"

uint64_t Entity::next_id_ = 0;

Entity::Entity()
{
  tag_ = 0;
  enable_ = true;
  position_ = {0.0f, 0.0f};
  rotation_ = 0.0f;
  scale_ = {1.0f, 1.0f};
  // animation_ = nullptr;

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
  // animation_ = nullptr;

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

// Entity::~Entity()
// {
//   stopAnimation();
// }

void Entity::init(int tag, bool enable, Vec2 pos, float rot, Vec2 scale, float speed)
{
  tag_ = tag;
  enable_ = enable;
  position_ = pos;
  rotation_ = rot;
  scale_ = scale;
  speed_ = speed;

  // animation_ = nullptr; 
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

uint64_t Entity::id() const{
  return id_;
}

void initAllEntity()
{
  GameManager &GM = GameManager::Instance();
  Texture *text;

  //Space background
  text = text->TextureFactory("../data/parallax/Space_Background.png");
  for(int i = 0; i < 2; i++)
  {
    GM.all_sprites.parallax.space[i].texture_handle_ = text;
    GM.all_sprites.parallax.space[i].Entity::init(0, true, {(float)(i * GM.all_sprites.parallax.space[i].width()), 
                               -(float)(GM.all_sprites.parallax.space[i].height()/4)}, 0.0f, {1.0f, 1.0f}, 0.025f);


  }
  //Clouds
  text = text->TextureFactory("../data/parallax/near-clouds.png");
  for(int i = 0; i < 6; i++)
  {
    GM.all_sprites.parallax.clouds[i].texture_handle_ = text;
    GM.all_sprites.parallax.clouds[i].Entity::init(1, true, {(float)(i * GM.all_sprites.parallax.clouds->width()),
                                                            50.0f}, 0.0f, {2.0f, 2.0f}, 0.1f);
  }

}

// void Entity::PlayAnimation(const AnimationConfig &ac)
// {
//   stopAnimation();
//   animation_ = new AnimationInstance(ac, this);
// }


// void Entity::update(float dt)
// {
//   if(true == enable_)
//   {
//     if(nullptr != animation_)
//     {
//       animation_->update(dt);
//     }
//   }
// }

// void Entity::stopAnimation()
// {
//   if(nullptr != animation_)
//   {
//     delete animation_;
//     animation_ = nullptr;
//   }
// }