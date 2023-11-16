#include "path.h"


Path::Path()
{
  solid_ = true;
  stroke_color_ = { 255.0f, 255.0f, 255.0f, 255.0f };
  fill_color_ = { 200.0f, 50.0f, 50.0f, 255.0f};
}

Path::Path(const Path& other)
{
  solid_ = other.solid_;
  stroke_color_ = other.stroke_color_;
  fill_color_ = other.fill_color_;
  vertices_ = other.vertices_;
}

void Path::set_stroke_color(const Vec4& color){
  //clamp color components {0.0f ---> 255.0f}
  stroke_color_.x = MathUtils::Clamp(color.x, 0.0f, 255.0f);
  stroke_color_.y = MathUtils::Clamp(color.y, 0.0f, 255.0f);
  stroke_color_.z = MathUtils::Clamp(color.z, 0.0f, 255.0f);
  stroke_color_.w = MathUtils::Clamp(color.w, 0.0f, 255.0f);
}

void Path::set_fill_color(const Vec4& color)
{
  //TODO
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


