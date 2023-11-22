//@file entity.h
//@brief Base class for Entity
//@author

#ifndef __ENTITY_H__
#define __ENTITY_H_ 1

#include "vector_2.h"

class Entity{
  public:
    Entity();
    Entity(const Entity& copy);
    Entity(int tag, bool enable, Vec2 pos, float rot, Vec2 scale);
    void init();

    // transform methods
    void set_position(const Vec2& pos);
    void set_rotation(const float rads);
    void set_scale(const Vec2& scale);

    Vec2 position() const;
    float rotation() const;
    Vec2 scale() const;

    //attributes
    int tag_;
    bool enable_;

  protected:
    Vec2 position_;
    float rotation_;
    Vec2 scale_;
};


#endif