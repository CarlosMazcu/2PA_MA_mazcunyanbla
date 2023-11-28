//@file gsprite.cc
//@brief
//@author

#include "gsprite.h"
#include "vector_2.h"
#include "matrix_3.h"

Sprite::Sprite()
{
  handle_ = nullptr;
}

Sprite::Sprite(const Sprite& other)
{
  handle_= esat::SubSprite(other.handle_, 0, 0, 
                           other.width(), 
                           other.height());
}

Sprite::~Sprite()
{
  if(nullptr != handle_)
  {
    release();
  }
}

void Sprite::init(const Texture& texture, int x, int y, int w, int h){
  if (nullptr != handle_)
  {
    release();
  }
  handle_ = texture.getSubSprite(x,y,w,h);
}

void Sprite::init(const char* fname){
  if(nullptr != handle_)
  {
    release();
  }
  handle_ = esat::SpriteFromFile(fname);
}

int Sprite::width() const
{
  if(nullptr != handle_){
    return esat::SpriteWidth(handle_);
  }
  return 0;
}

int Sprite::height() const
{
  if (nullptr != handle_)
  {
    return esat::SpriteHeight(handle_);
  }
  return 0;
}

void Sprite::draw(){
  if (true == enable_)
  {
    if (nullptr == handle_)
    {
      // Transform Matrix
      Mat3 m = Mat3::Identity();
      m = Mat3::Scale(scale_.x, scale_.y).Multiply(m);
      m = Mat3::Rotate(rotation_).Multiply(m);
      m = Mat3::Translate(position_.x, position_.y).Multiply(m);
     
      // Draw the sprite with the matrix
      esat::DrawSpriteWithMatrix(handle_, m.m);
    }
  }
}

void Sprite::release(){
  if(nullptr != handle_)
  {
    esat::SpriteRelease(handle_);
    handle_ = nullptr;
  }
}