/**
 * @file gtexture.h
 * @author Carlos Mazcuñán Blanes <mazcunyanbla@esat-alumni.com>
 * @brief Header for base class for texture atlas
 * @version 0.5
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __TEXTURE_H_
#define __TEXTURE_H_ 1

#include <stdint.h>
#include <vector>

#include "esat/sprite.h"

const unsigned int kMaxTextures = 20;

class Texture{
 public:
  /**
  * @brief Destructor for the Texture class.
  *
  * This destructor releases resources associated with the Texture, such as the texture handle,
  * by calling the `release` method. If the texture handle is not a null pointer, it is set to nullptr.
  * Additionally, it decrements the total count of Texture instances.
  */
  ~Texture();
  /**
  * @brief Default constructor for the Texture class.
  *
  * This constructor initializes a Texture object with a null texture handle.
  */
  Texture();
  
  /**
  * @brief Initialize the Texture from a file.
  *
  * This method initializes the Texture by loading a sprite from the specified file.
  * If the texture handle is not a null pointer, it releases the existing resources
  * using the `release` method before loading the new texture.
  *
  * @param fname The file name or path of the image file to load as the texture.
  */
  void init(const char* fname);
  /**
  * @brief Initialize the Texture from raw pixel data.
  *
  * This method initializes the Texture by creating a sprite from raw pixel data
  * with the specified width, height, and data. If the texture handle is not a null pointer,
  * it releases the existing resources using the `release` method before creating the new texture.
  *
  * @param w The width of the texture in pixels.
  * @param h The height of the texture in pixels.
  * @param data A pointer to the raw pixel data.
  */
  void init(int w, int h, uint8_t* data);
  /**
  * @brief Initialize the Texture from a sub-sprite of an existing sprite.
  *
  * This method initializes the Texture by creating a sub-sprite from an existing sprite
  * with the specified coordinates (x, y) and dimensions (w, h). The resulting sub-sprite
  * is set as the texture handle.
  *
  * @param sp The handle of the existing sprite from which the sub-sprite is created.
  * @param x The x-coordinate of the top-left corner of the sub-sprite.
  * @param y The y-coordinate of the top-left corner of the sub-sprite.
  * @param w The width of the sub-sprite.
  * @param h The height of the sub-sprite.
  */
  void init(esat::SpriteHandle sp, int x, int y, int w, int h);
  /**
  * @brief Get the width of the Texture.
  *
  * Returns the width of the Texture based on its handle.
  * If the handle is a null pointer, the width is returned as 0.
  *
  * @return The width of the Texture.
  */
  int width() const;
  /**
  * @brief Get the height of the Texture.
  *
  * Returns the height of the Texture based on its handle.
  * If the handle is a null pointer, the height is returned as 0.
  *
  * @return The height of the Texture.
  */
  int height() const;
  /**
  * @brief Get a sub-sprite of the Texture.
  *
  * Returns a new Texture object that represents a sub-sprite of the current Texture.
  * The sub-sprite is defined by the specified coordinates (x, y) and dimensions (w, h).
  *
  * @param x The x-coordinate of the top-left corner of the sub-sprite.
  * @param y The y-coordinate of the top-left corner of the sub-sprite.
  * @param w The width of the sub-sprite.
  * @param h The height of the sub-sprite.
  *
  * @return A new Texture object representing the specified sub-sprite.
  */
  Texture getSubSprite(int x, int y, int w, int h) const;
  /**
  * @brief Release resources associated with the Texture.
  *
  * This method releases the allocated resources, such as the texture handle,
  * by calling `esat::SpriteRelease`. After releasing the resources, the texture handle
  * is set to nullptr.
  */
  void release();
  /**
  * @brief Create a new Texture using the TextureFactory.
  *
  * This static method creates a new Texture. It initializes the Texture with 
  * raw pixel data of the specified width, height, and data.
  * The new Texture is returned regardless of the total number of textures created.
  *
  * @param w The width of the new Texture in pixels.
  * @param h The height of the new Texture in pixels.
  * @param data A pointer to the raw pixel data.
  *
  * @return A pointer to the newly created Texture.
  */
  static Texture *TextureFactory(int w, int h, uint8_t *data);
  /**
  * @brief Create a new Texture using the TextureFactory from a file.
  *
  * Creates a new Texture by allocating memory.
  * It initializes the Texture by loading a sprite from the specified file.
  * The new Texture is returned regardless of the total number of textures created.
  *
  * @param fname The file name or path of the image file to load as the texture.
  *
  * @return A pointer to the newly created Texture.
  */
  static Texture *TextureFactory(const char *fname);
  static int total_textures;
  /**
  * @brief Get the handle of the underlying sprite.
  *
  * Returns the handle of the underlying sprite associated with the Texture.
  *
  * @return The handle of the underlying sprite.
  */
  esat::SpriteHandle getHandle();
  /**
  * @brief Release all sprites associated with the Texture.
  *
  * Releases all sprites associated with the Texture by calling `esat::SpriteRelease`
  * for each sprite in the sprite vector. After releasing the sprites, the sprite vector is cleared.
  */
  static void releaseAllSprites();
 protected:
  esat::SpriteHandle handle_;

 private:
  static std::vector<esat::SpriteHandle*> sprite_vector_;
};




#endif