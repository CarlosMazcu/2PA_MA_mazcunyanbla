#include "path.h"
#include "esat/draw.h"
#include "../deps/math_library/include/matrix_3.h"
#include "../deps/math_library/include/vector_4.h"
#include "../deps/math_library/include/math_utils.h"

Path::Path()
{
  solid_ = true;
  stroke_color_ = { 255.0f, 255.0f, 255.0f, 255.0f };
  fill_color_ = { 200.0f, 50.0f, 50.0f, 255.0f};
  n_vertex_ = 3;
}

Path::Path(const Path& other)
{
  solid_ = other.solid_;
  stroke_color_ = other.stroke_color_;
  fill_color_ = other.fill_color_;
  vertices_ = other.vertices_;
  n_vertex_ = other.n_vertex_;

}

void Path::set_stroke_color(const Vec4& color){
  //clamp color components {0.0f ---> 255.0f}
 /*  stroke_color_.x = MathUtils::Clamp(color.x, 0.0f, 255.0f);
  stroke_color_.y = MathUtils::Clamp(color.y, 0.0f, 255.0f);
  stroke_color_.z = MathUtils::Clamp(color.z, 0.0f, 255.0f);
  stroke_color_.w = MathUtils::Clamp(color.w, 0.0f, 255.0f); */
stroke_color_.x = color.x;
stroke_color_.y = color.y;
stroke_color_.z = color.z;
stroke_color_.w = color.w;
}

void Path::set_fill_color(const Vec4& color)
{
/*   fill_color_.x = MathUtils::Clamp(color.x, 0.0f, 255.0f);
  fill_color_.y = MathUtils::Clamp(color.y, 0.0f, 255.0f);
  fill_color_.z = MathUtils::Clamp(color.z, 0.0f, 255.0f);
  fill_color_.w = MathUtils::Clamp(color.w, 0.0f, 255.0f); */
  fill_color_.x = color.x;
  fill_color_.y = color.y;
  fill_color_.z = color.z;
  fill_color_.w = color.w;
}

Vec4 Path::stroke_color() const
{
    return stroke_color_;
}

Vec4 Path::fill_color() const
{
    return fill_color_;
}
void Path::addVertex(const Vec2& v)
{
  vertices_.push_back(v);
}

void Path::removeEndVertex()
{
  vertices_.pop_back();
}

void Path::removeAllVertex()
{
    vertices_.clear();
}

void Path::draw(){
  if(true == enable_){
    if(3 <= vertices_.size())
    {
    //colors
    esat::DrawSetStrokeColor((unsigned char) stroke_color_.x,
                              (unsigned char) stroke_color_.y,
                              (unsigned char) stroke_color_.z,
                              (unsigned char) stroke_color_.w);
    esat::DrawSetFillColor((unsigned char)fill_color_.x,
                             (unsigned char)fill_color_.y,
                             (unsigned char)fill_color_.z,
                             (unsigned char)fill_color_.w);

  //Transform Matrix
  Mat3 m = Mat3::Identity();
  m = Mat3::Rotate(origin_rotation_).Multiply(m);
  m = Mat3::Translate(origin_pos_.x, origin_pos_.y).Multiply(m);

  m = Mat3::Scale(scale_.x, scale_.y).Multiply(m);

  m = Mat3::Rotate(rotation_).Multiply(m);
  m = Mat3::Translate(position_.x, position_.y).Multiply(m);
  //Transform vertices

  //TransformVec2
  std::vector<Vec2> transformed;
  for(int i = 0; i < (int)vertices_.size(); i++)
  {
    transformed.push_back(m.TransformVec2(vertices_[i]));
  }
  transformed.push_back(transformed[0]);
  //Draw the transform vertices
  if(true == solid_){
    esat::DrawSolidPath((float*)transformed.data(), transformed.size(), true);
  }else{
    esat::DrawPath((float *)transformed.data(), transformed.size());
       }
    }
  }
}


