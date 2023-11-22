//@file gtexture.cc
//@brief 
//@author
#include "gtexture.h"

Texture::Texture(){
  handle_ = nullptr;
}

Texture::~Texture(){
  if(nullptr != handle_){
    release();
  }
}

void Texture::init(const char* fname){
  if(nullptr != handle_)
  {
    release();
  }
  handle_ = esat::SpriteFromFile(fname);
}

void Texture::init(int w, int h, uint8_t *data)
{
  if (nullptr != handle_)
  {
    release();
  }
  handle_ = esat::SpriteFromMemory(w, h , data);
}

int Texture::width()const{
  if(nullptr != handle_){
    return esat::SpriteWidth(handle_);
  }else{
    return 0;
  }
}

int Texture::height() const
{
  if (nullptr != handle_)
  {
    return esat::SpriteHeight(handle_);
  }
  else
  {
    return 0;
  }
}

esat::SpriteHandle Texture::getSubSprite(int x, int y, int w, int h) const
{
  if (nullptr != handle_)
  {
    return esat::SubSprite(handle_,x, y, w, h); 
  }
  else
  {
    return nullptr;
  }
}

void Texture::release(){
  if(nullptr != handle_){
    esat::SpriteRelease(handle_);
    handle_ = nullptr;
  }
}
