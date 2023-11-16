/*
*/

#ifndef __PATH_H__
#define __PATH_H__ 1

#include <vector>
#include "entity.h"

#include "vector_4.h"

class Path : public Entity
{

  public:
    Path();
    Path(const Path& other);
    
    void set_stroke_color(const Vec4& color);
    void set_fill_color(const Vec4& color);

    Vec4 stroke_color() const;
    Vec4 fill_color() const;

    void addVertex(const Vec2& v);

    void draw();

    bool solid_;
  
  protected:
    //could have a Color class/struct, a packed int32 color, Vec4  
    // or array of 4 values
    // rgba {0.0f <--> 255.0f}
    Vec4 stroke_color_;
    Vec4 fill_color_;
      /*8==========================================================D     
      <===========================================================3 */
    // store vertices: could be a list, dynamic vector, reallocated array,
    // pool, ADT_Vector
    //DINAMIC VECTOR 
    std::vector<Vec2> vertices_;
};

    

#endif