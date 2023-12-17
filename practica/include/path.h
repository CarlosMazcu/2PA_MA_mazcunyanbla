/**
 * @file path.h
 * @author Lucas Calatayud (calatayudbri@esat-alumni.com)
 * @brief base class for path who inherit from entity class
 * @version 0.5
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __PATH_H__
#define __PATH_H__ 1

#include <vector>
#include "entity.h"

#include "../deps/math_library/include/vector_4.h"
#include "math_utils.h"


class Path : public Entity
{

  public:
    /**
    * @brief Default constructor for the Path class.
    *
    * A constructor that initializes a Path object with default values.
    * The path is solid by default, and the stroke and fill colors are set to white and red, respectively.
    * The number of vertices is set to 3.
    */
    Path();
    /**
    * @brief Copy constructor for the Path class.
    *
    * This constructor creates a new Path object by copying the attributes from another Path object.
    *
    * @param other The Path object to be copied.
    */
    Path(const Path& other);
    /**
    * @brief Set the stroke color of the Path.
    *
    * Sets the stroke color of the Path to the specified RGBA color.
    *
    * @param color The Vec4 representing the RGBA color to set as the stroke color.
    */
    void set_stroke_color(const Vec4& color);
    /**
    * @brief Set the fill color of the Path.
    *
    * This method sets the fill color of the Path to the specified RGBA color.
    *
    * @param color The Vec4 representing the RGBA color to set as the fill color.
    */
    void set_fill_color(const Vec4& color);
    /**
    * @brief Get the stroke color of the Path.
    *
    * Returns the stroke color of the Path as a Vec4 representing the RGBA color.
    *
    * @return The stroke color of the Path.
    */
    Vec4 stroke_color() const;
    /**
    * @brief Get the fill color of the Path.
    *
    * Returns the fill color of the Path as a Vec4 representing the RGBA color.
    *
    * @return The fill color of the Path.
    */
    Vec4 fill_color() const;
    /**
    * @brief Add a vertex to the Path.
    *
    * Adds a vertex to the end of the vertex list (std::vector<Vec2>) of the Path.
    *
    * @param v The Vec2 representing the coordinates of the new vertex.
    */
    void addVertex(const Vec2& v);
    /**
    * @brief Remove the last vertex from the Path.
    *
    * Removes the last vertex from the vertex list (std::vector<Vec2>) of the Path.
    * If the vertex list is empty, no action is taken.
    */
    void removeEndVertex();
    /**
    * @brief Remove all vertices from the Path.
    *
    * Clears the entire vertex list (std::vector<Vec2>) of the Path, removing all vertices.
    */
    void removeAllVertex();
    /**
    * @brief Draw the Path.
    *
    * This method draws the Path based on its current properties and vertices.
    * If the Path has at least three vertices, it sets the stroke and fill colors,
    * applies the transformation matrix, and draws the transformed vertices.
    * The drawing is either a solid path or an outline based on the `solid_` property.
    */
    void draw();

    bool solid_;
    int n_vertex_;
    Vec4 stroke_color_;
  
  protected:
    //could have a Color class/struct, a packed int32 color, Vec4  
    // or array of 4 values
    // rgba {0.0f <--> 255.0f}
    Vec4 fill_color_;
    std::vector<Vec2> vertices_;
};

    

#endif