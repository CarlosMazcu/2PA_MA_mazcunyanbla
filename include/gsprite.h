/**
 * @file gsprite.h
 * @author Carlos Mazcuñán Blanes <mazcunyanbla@esat-alumni.com>
 * @brief Header for class Sprite who inherit from entity class
 * 
 * Manage the sprites that taken from textures
 * @version 0.5
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

#include "esat/sprite.h"
#include "entity.h"
#include "gtexture.h"
#include "../deps/math_library/include/vector_2.h"
#include "../deps/math_library/include/matrix_3.h"
/**
 * @brief Class representing a sprite entity in the game.
 *
 * The Sprite class extends the functionality of the base Entity class to represent a sprite entity,
 * which is associated with a texture for rendering.
 */
class Sprite : public Entity
{
 public:
  /**
  * @brief Default constructor for the Sprite class.
  *
  * This constructor initializes a Sprite object with a null texture handle.
  */
  Sprite();
  /**
  * @brief Copy constructor for the Sprite class.
  *
  * This constructor creates a new Sprite object by copying the texture handle from another Sprite.
  *
  * @param other The Sprite object to be copied.
  */
  Sprite(const Sprite& other);
  /**
  * @brief Destructor for the Sprite class.
  *
  * This destructor releases the allocated resources, such as the texture handle,
  * if it is not a null pointer.
  */
  ~Sprite();
  /**
  * @brief Get the width of the Sprite.
  *
  * Returns the width of the Sprite based on the width of its associated texture handle.
  *
  * @return The width of the Sprite.
  */
  int width() const;
  /**
  * @brief Get the height of the Sprite.
  *
  * Returns the height of the Sprite based on the height of its associated texture handle.
  *
  * @return The height of the Sprite.
  */
  int height() const;
  /**
  * @brief Initialize the Sprite with a specified texture and region.
  *
  * This method initializes the Sprite with the provided texture and sets its region
  * based on the specified coordinates (x, y) and dimensions (w, h).
  *
  * @param texture Pointer to the Texture object to be associated with the Sprite.
  * @param x The x-coordinate of the top-left corner of the Sprite's region.
  * @param y The y-coordinate of the top-left corner of the Sprite's region.
  * @param w The width of the Sprite's region.
  * @param h The height of the Sprite's region.
  */
  void initSp(Texture *texture, int x, int y, int w, int h);
  /**
  * @brief Draw the Sprite.
  *
  * This method draws the Sprite on the screen. It checks if the Sprite is enabled
  * and if a valid texture handle is associated with it. If conditions are met,
  * it applies a transformation matrix and uses it to draw the sprite.
  * If the texture handle is nullptr, an error message is printed.
  */
  void draw() override;
  /**
  * @brief Release resources associated with the Sprite.
  *
  * This method releases the allocated resources, such as the texture handle,
  * by calling `esat::SpriteRelease`. After releasing the resources, the texture handle
  * is set to nullptr.
  */
  void release();
  
 Texture *texture_handle_;
 protected:
};
    
    


#endif