/**
 * @file gsprite.cc
 * @author Carlos Mazcuñán Blanes <mazcunyanbla@esat-alumni.com>
 * @brief Source code for gsprite.h
 * @version 0.5
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
    release();
  }
}

void Sprite::initSp(Texture *texture, int x, int y, int w, int h)
{
  if (nullptr == texture)
  {
    printf("Error texture");
    return;
  }
  texture_handle_ = texture;
  // GUSTAVO: ???
  texture_handle_->getHandle(); 
}



int Sprite::width() const
{
  return texture_handle_->width();
}

int Sprite::height() const
{
  return texture_handle_->height();
}

void Sprite::draw(){
  if (true == enable_)
  {
    if (nullptr != texture_handle_)
    {
      // Transform Matrix
      Mat3 m = Mat3::Identity();
      m = Mat3::Rotate(origin_rotation_).Multiply(m);
      m = Mat3::Translate(origin_pos_.x, origin_pos_.y).Multiply(m);
      m = Mat3::Scale(scale_.x, scale_.y).Multiply(m);
      m = Mat3::Rotate(rotation_).Multiply(m);
      m = Mat3::Translate(position_.x, position_.y).Multiply(m);
     
      // Draw the sprite with the matrix
      esat::DrawSpriteWithMatrix(texture_handle_->getHandle(), m.m);
    }else{
      printf("\ntexture handle nullptr");
    }
  }
}

void Sprite::release(){
  if(nullptr != texture_handle_)
  {
    esat::SpriteRelease(texture_handle_);
    texture_handle_ = nullptr;
  }
}

