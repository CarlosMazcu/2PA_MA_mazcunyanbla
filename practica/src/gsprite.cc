/**
 * @file gsprite.cc
 * @author Lucas Calatayud (calatayudbri@esat-alumni.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

#include "gsprite.h"
#include "vector_2.h"
#include "matrix_3.h"

Sprite::Sprite()
{
  texture_handle_ = nullptr;
}

Sprite::Sprite(const Sprite& other)
{
  texture_handle_= other.texture_handle_;
}

Sprite::~Sprite()
{
  if(nullptr != texture_handle_)
  {
  /*   release(); */
  }
}

void Sprite::init(Texture *texture, int x, int y, int w, int h)
{
  if (nullptr == texture)
  {
    printf("Error texture");
    return;
  }
  /* handle_ = texture.getSubSprite(x,y,w,h); */
  texture_handle_ = texture;
  texture_handle_->getHandle(); 
}



int Sprite::width() const
{
  return texture_handle_->width();
/*   if(nullptr != handle_){
    return esat::SpriteWidth(handle_);
  }
  return 0; */
}

int Sprite::height() const
{
  return texture_handle_->height();
/*   if (nullptr != handle_)
  {
    return esat::SpriteHeight(handle_);
  }
  return 0; */
}

void Sprite::draw(){
  if (true == enable_)
  {
    if (nullptr != texture_handle_)
    {
      // Transform Matrix
      Mat3 m = Mat3::Identity();
      m = Mat3::Scale(scale_.x, scale_.y).Multiply(m);
      m = Mat3::Rotate(rotation_).Multiply(m);
      m = Mat3::Translate(position_.x, position_.y).Multiply(m);
     
      // Draw the sprite with the matrix
      esat::DrawSpriteWithMatrix(texture_handle_->getHandle(), m.m);
    }else{
      printf("\ntesture handle nullptr");
    }
  }
}

/* void Sprite::release(){
  if(nullptr != handle_)
  {
    esat::SpriteRelease(handle_);
    handle_ = nullptr;
  }
} */