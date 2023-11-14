//--------------------------------------------------------------//
//  Math Library
//  Matrix 3 Class Definition.
//--------------------------------------------------------------//
//
//   m0 m3 m6
//   m1 m4 m7
//   m2 m5 m8
//
//--------------------------------------------------------------//
#ifndef __MATRIX3_H__
#define __MATRIX3_H__ 1

#include "vector_2.h"
#include "vector_3.h"

class Mat3 {
public:

	Mat3();
	Mat3(float *values_array);
	Mat3(float value);
	Mat3(Vec3 a, Vec3 b, Vec3 c);

	Mat3(const Mat3& copy);
	~Mat3();

	static Mat3 Identity();

	Mat3 Multiply(const Mat3& other) const;

	float Determinant() const;

	Mat3 Adjoint() const;
	bool GetInverse(Mat3& out) const;
	bool Inverse();

	Mat3 Transpose() const;

	static Mat3 Translate(const Vec2& position);
	static Mat3 Translate(float x, float y);
  static Mat3 Rotate(float rotation);
  static Mat3 Scale(const Vec2& scale);
  static Mat3 Scale(float x, float y);

	Vec3 GetColumn(int colum) const;
	Vec3 GetLine(int line) const;

	inline Mat3 operator+(const Mat3& other) const;
	inline Mat3& operator+=(const Mat3& other);
	inline Mat3 operator+(float value) const;
	inline Mat3& operator+=(float value);
	inline Mat3 operator-(const Mat3& other) const;
	inline Mat3& operator-=(const Mat3& other);
	inline Mat3 operator-(float value) const;
	inline Mat3& operator-=(float value);
	inline Mat3 operator*(float value) const;
	inline Mat3& operator*=(float value);
	inline Mat3 operator/(float value) const;
	inline Mat3& operator/=(float value);
	bool operator==(const Mat3& other) const;
	bool operator!=(const Mat3& other) const;
	inline void operator=(const Mat3& other);
	
  Vec3 TransformVec3(const Vec3& vec);
  Vec2 TransformVec2(const Vec2& vec);

	float m[9];
};


inline Mat3 Mat3::operator+(const Mat3& other) const {
	return Mat3();
}

inline Mat3& Mat3::operator+=(const Mat3& other) {
	return (*this);
}

inline Mat3 Mat3::operator+(float value) const {
	return Mat3();
}

inline Mat3& Mat3::operator+=(float value) {	
	return (*this);
}

inline Mat3 Mat3::operator-(const Mat3& other) const {
	return Mat3();
}

inline Mat3& Mat3::operator-=(const Mat3& other) {
	return (*this);
}

inline Mat3 Mat3::operator-(float value) const {
	return Mat3();
}

inline Mat3& Mat3::operator-=(float value) {
	return (*this);
}

inline Mat3 Mat3::operator*(float value) const {
	return Mat3();
}

inline Mat3& Mat3::operator*=(float value) {
	return (*this);
}

inline Mat3 Mat3::operator/(float value) const {
	return Mat3();
}

inline Mat3& Mat3::operator/=(float value) {
	return (*this);
}

inline bool Mat3::operator==(const Mat3& other) const {
	return true;
}

inline bool Mat3::operator!=(const Mat3& other) const {
	return true;
}

inline void Mat3::operator=(const Mat3& other) {
}

inline Mat3 Mat3::Identity() {
	return Mat3();
}

inline float Mat3::Determinant() const {
	return 42.0f;
}

inline bool Mat3::GetInverse(Mat3& out) const {
	return true;
}

inline bool Mat3::Inverse() {	
	return true;
}

inline Mat3 Mat3::Translate(const Vec2& mov_vector) {	
	return Mat3();
}

inline Mat3 Mat3::Translate(float x, float y) {
	return Mat3();
}

inline Mat3 Mat3::Multiply(const Mat3& other) const {
	return Mat3();
}

inline Mat3 Mat3::Adjoint() const {
	return Mat3();
}

inline Mat3 Mat3::Transpose() const {
	return Mat3();
}

inline Vec3 Mat3::GetColumn(int colum) const {
	return Vec3();
}

inline Vec3 Mat3::GetLine(int line) const {
	return Vec3();
}

inline Vec3 Mat3::TransformVec3(const Vec3& vec) {
  float c[3] = { vec.x, vec.y, vec.z };
  float r[3] = {
    m[0] * c[0] + m[3] * c[1] + m[6] * c[2],
    m[1] * c[0] + m[4] * c[1] + m[7] * c[2],
    m[2] * c[0] + m[5] * c[1] + m[8] * c[2]};
  Vec3 k;
  k.x = r[0];
  k.y = r[1];
  k.z = r[2];
  return k;
}

inline Vec2 Mat3::TransformVec2(const Vec2& vec) {
  Vec3 tmp = { vec.x, vec.y, 1.0 };
  Vec3 result = TransformVec3(tmp);
  result.x = result.x/result.z;
  result.y = result.y/result.z;
  Vec2 k;
  k.x = result.x;
  k.y = result.y;
  return k;
}
#endif 
