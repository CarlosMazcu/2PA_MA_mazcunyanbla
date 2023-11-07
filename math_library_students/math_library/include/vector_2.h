//--------------------------------------------------------------//
//  Math Library
//  Vector 2 Class.
//--------------------------------------------------------------//

#ifndef __VEC2_H__
#define __VEC2_H__ 1

/// @class Vec2 vector2.h "vector2.h"
/// @brief Basic float vector 2.
class Vec2 {
 public:

  Vec2();
  Vec2(float x, float y);
  Vec2(const Vec2& copy);
  ~Vec2();

  Vec2 operator+(const Vec2& other) const;
  Vec2 operator+(float value);
  Vec2& operator+=(const Vec2& other);
  Vec2& operator+=(float value);
  Vec2 operator-(const Vec2& other) const;  // Vec2 v = a - b;
  Vec2 operator-(float value) const;        // Vec2 v = a - 3.0f;
  Vec2 operator-() const;                   // Vec2 v = -a;
  Vec2& operator-=(const Vec2& other);
  Vec2& operator-=(float value);
  bool operator==(const Vec2& other) const;
  bool operator!=(const Vec2& other) const;
  void operator=(const Vec2& other);
  void operator=(float value);
  Vec2 operator*(float value) const;
  Vec2& operator*=(float value);
  Vec2 operator/(float value) const;
  Vec2& operator/=(float value);

  float Magnitude() const;

  /// @brief Normalizes the Vec2.
  void Normalize();

  /// @brief Returns a normalized version of this Vec2.
  /// @return Normalized version of this Vec2.
  Vec2 Normalized() const;

  void Scale(const Vec2 scale);

  float SqrMagnitude() const;
  static float Distance(const Vec2 a, const Vec2 b);

  static float DotProduct(Vec2 a, Vec2 b);

  static Vec2 Lerp(const Vec2 a, const Vec2 b, float t);
  static Vec2 LerpUnclamped(const Vec2 a, const Vec2 b, float t);

  static const Vec2 up;
  static const Vec2 down;
  static const Vec2 right;
  static const Vec2 left;
  static const Vec2 zero;
  static const Vec2 one;

  float x;
  float y;
};


inline Vec2 Vec2::operator+(const Vec2& other) const {
  return Vec2();
}

inline Vec2 Vec2::operator+(float value) {
  return Vec2();
}

inline Vec2& Vec2::operator+=(const Vec2& other){
  return *this;
}

inline Vec2& Vec2::operator+=(float value){
  return *this;
}

inline Vec2 Vec2::operator-(const Vec2& other) const {
  Vec2 ret;
  ret.x = x - other.x;
  ret.y = y - other.y;
  return ret;
}

inline Vec2 Vec2::operator-(float value) const {
  Vec2 ret;
  ret.x = x - value;
  ret.y = y - value;
  return ret;
}

inline Vec2 Vec2::operator-() const {
  Vec2 ret;
  ret.x = -x;
  ret.y = -y;
	return ret;
}

inline Vec2& Vec2::operator-=(const Vec2& other) {
  return *this;
}

inline Vec2& Vec2::operator-=(float value){
  return *this;
}

inline bool Vec2::operator==(const Vec2& value) const {
  return false;
}

inline bool Vec2::operator!=(const Vec2& value) const {
  return true;
}


inline void Vec2::operator=(const Vec2& other) {
}

inline void Vec2::operator=(float value) {
}

inline Vec2 Vec2::operator*(float value) const {
	return Vec2();
}

inline Vec2& Vec2::operator*=(float value) {  
  return *this;
}

inline Vec2 Vec2::operator/(float value) const {
	return Vec2();
}

inline Vec2& Vec2::operator/=(float value) {
	return *this;
}

inline float Vec2::Magnitude() const {
  return 0.0f;
}

inline void Vec2::Normalize() {  
}

inline Vec2 Vec2::Normalized() const {
	return Vec2();
}

inline void Vec2::Scale(const Vec2 scale){

}

inline float Vec2::SqrMagnitude() const {
  return 0.0f;
}


inline float Vec2::Distance(const Vec2 a, const Vec2 b) {
  return 0.0f;
}

inline Vec2 Vec2::Lerp(const Vec2 a, const Vec2 b, float t) {
	return Vec2();
}

inline Vec2 Vec2::LerpUnclamped(const Vec2 a, const Vec2 b, float t) {
	return Vec2();
}


inline float Vec2::DotProduct(Vec2 a, Vec2 b) {
	return 0.0f;
}

#endif 
