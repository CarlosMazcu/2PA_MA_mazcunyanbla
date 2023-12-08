//@file gtexture.cc
//@brief 
//@author
#include "gtexture.h"
#include <stdio.h>
#include <algorithm>

int Texture::total_textures = 0; 

std::vector<esat::SpriteHandle*> Texture::sprite_vector_;

static bool AddToVector(std::vector<esat::SpriteHandle*> &vec, esat::SpriteHandle* img ){
  if (std::find(vec.begin(), vec.end(), img) != vec.end())
  {
    printf("encontrado\n");
    return false;
  }
  vec.push_back(img);
  return true;

}

Texture::Texture(){
  handle_ = nullptr;
}

Texture::~Texture(){
  if(nullptr != handle_){
    release();
  }
  Texture::total_textures--;
}


void Texture::init(const char* fname){
  if(nullptr != handle_)
  {
    release();
  }
  handle_ = esat::SpriteFromFile(fname);
  AddToVector(sprite_vector_, &handle_);
}

void Texture::init(int w, int h, uint8_t *data)
{
  if (nullptr != handle_)
  {
    release();
  }
  handle_ = esat::SpriteFromMemory(w, h , data);
  AddToVector(sprite_vector_, &handle_);
}

void Texture::init(esat::SpriteHandle sp, int x, int y, int w, int h)
{
  handle_ = esat::SubSprite(sp, x, y, w, h);
  AddToVector(sprite_vector_, &handle_);

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

/* esat::SpriteHandle Texture::getSubSprite(int x, int y, int w, int h) const
{
  if (nullptr != handle_)
  {
    return esat::SubSprite(handle_,x, y, w, h); 
  }
  else
  {
    return nullptr;
  }
} */
Texture Texture::getSubSprite(int x, int y, int w, int h) const
{
  Texture tr;
  tr.init(handle_, x, y, w, h);
  return tr; 
}

void Texture::release(){
  if(nullptr != handle_){
    esat::SpriteRelease(handle_);
    handle_ = nullptr;
  }
}

Texture *Texture::TextureFactory(int w, int h, uint8_t *data)
{
  if(Texture::total_textures < kMaxTextures)
  {
    Texture* p_texture = new Texture();
    p_texture->init(w, h, data);
    Texture::total_textures++;
    return p_texture;
  }else
  {
    return nullptr;
  }
}

Texture *Texture::TextureFactory(const char *fname)
{
/*   if (Texture::total_textures < kMaxTextures)
  { */
  Texture *p_texture = new Texture();
  p_texture->init(fname);
  Texture::total_textures++;
  return p_texture;
 /*  }
  else
  {
    return nullptr;
  } */
}

void Texture::releaseAllSprites()
{
  for(int i = 0; i < sprite_vector_.size(); i++)
  {
    printf("\n%p",sprite_vector_[i]);
    esat::SpriteRelease(*sprite_vector_[i]);
  }
  sprite_vector_.clear();
}
