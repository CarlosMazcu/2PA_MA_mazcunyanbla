//@file gtexture.h
//@brief Base cclass for Texture Atlas
//@author 

#ifndef __TEXTURE_H_
#define __TEXTURE_H_ 1

#include <stdint.h>

#include "esat/sprite.h"

const unsigned int kMaxTextures = 16;

class Texture{
 public:
  ~Texture();
  
  void init(const char* fname);
  void init(int w, int h, uint8_t* data);
  void init(esat::SpriteHandle sp, int x, int y, int w, int h);
  
  int width() const;
  int height() const;

  Texture getSubSprite(int x, int y, int w, int h) const;

  void release();
  static Texture *TextureFactory(int w, int h, uint8_t *data);
  static Texture *TextureFactory(const char *fname);
  static int total_textures;

  esat::SpriteHandle getHandle()
  {
      return handle_;
  }

protected:
  esat::SpriteHandle handle_; //for the atlas/entire texture

 private:
  Texture();

};




#endif