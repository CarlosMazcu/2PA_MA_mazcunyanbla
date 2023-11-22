//@file gsprite.h
//@brief
//@author

#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

#include "esat/sprite.h"
#include "entity.h"
#include "gtexture.h"
#include "vector_2.h"
#include "matrix_3.h"



class Sprite : public Entity
{
 public:
  Sprite();
  Sprite(const Sprite& other);
  ~Sprite();
  
  int width() const;
  int height() const;

  void init(const Texture& texture, int x, int y, int w, int h);
  
  void draw();

  void release();
 protected:
 esat::SpriteHandle handle_;
        
};
    
    



#endif