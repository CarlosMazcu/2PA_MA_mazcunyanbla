//@file parallax.cc
//@brief
//@author



#include "parallax.h"

Parallax::Parallax()
{
  order_ = 0;
  n_tiles_ = 0;
  speed_ = {1.0f, 1.0f};
}

void Parallax::move(const Vec2 speed)
{
  Vec2::DotProduct(position_, (speed) * -1);
}

void Parallax::drawLayer()
{
  Sprite *sp;
  sp = (Sprite*)malloc(n_tiles_ * sizeof(Sprite));
  //sp[n_tiles_];
  for(int i = 0; i < n_tiles_; i++)
  {
    if(i < n_tiles_)
    {
      sp[i + 1].position_.x = sp[i].position_.x + sp[i].width(); 
    }
    if(sp[i].position_.x <= (sp[i].width()) * -1)
    {
      sp[i].position_.x = sp[n_tiles_ - 1].position_.x + sp[n_tiles_ - 1].width();
    }
    sp[i].draw();

  }
}


