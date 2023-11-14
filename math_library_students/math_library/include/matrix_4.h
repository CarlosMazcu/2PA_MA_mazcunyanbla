#ifndef __MATRIX4_H__
#define __MATRIX4_H__ 1

#include "vector_3.h"
#include "vector_4.h"
#include "matrix_3.h"

class Mat4 {
 public:

  Mat4();
  Mat4(float a[16]);
  Mat4(float value);
  Mat4(const Mat4& copy);
  ~Mat4();

  static Mat4 Identity();
  Mat4 Multiply(const Mat4& other) const;

  float Determinant() const;
  Mat4 Adjoint() const;

  Vec4 TransformVec4(const Vec4 &v);
	Vec3 TransformVec3(const Vec3 &r);

  bool GetInverse(Mat4* out) const;
  bool Inverse();

  Mat4 Transpose() const;

  static Mat4 Translate(const Vec3& distance);
  static Mat4 Translate(float x, float y, float z);

  static Mat4 Scale(const Vec3& scale);
  static Mat4 Scale(float x, float y, float z);

  static Mat4 RotateX(float radians);
  static Mat4 RotateY(float radians);
  static Mat4 RotateZ(float radians);

  static Mat4 GetTransform(const Vec3& translate, const Vec3& scale,
                      float rotateX, float rotateY, float rotateZ);

  static Mat4 GetTransform(float trans_x, float trans_y, float trans_z,
                      float scale_x, float scale_y, float scale_Z,
                      float rotateX, float rotateY, float rotateZ);

  // NOTE: Not necessary until OpenGL.
  Mat4 PerspectiveMatrix(float fov, float aspect,
	  float near, float far) const;

  // NOTE: Not necessary until OpenGL.
  Mat4 OrthoMatrix(float right, float left, float top, float valueottom,
	  float near, float far) const;

  Vec4 GetColumn(int colum) const;
  Vec4 GetLine(int line) const;

  Mat4 operator+(const Mat4& other) const;
  Mat4& operator+=(const Mat4& other);
  Mat4 operator+(float value) const;
  Mat4& operator+=(float value);
  Mat4 operator-(const Mat4& other) const;
  Mat4& operator-=(const Mat4& other);
  Mat4 operator-(float value) const;
  Mat4& operator-=(float value);
  Mat4& operator*=(float value);
  Mat4 operator*(float value) const;
  Mat4& operator/=(float value);
  Mat4 operator/(float value) const;
  bool operator==(const Mat4& other);
  bool operator!=(const Mat4& other);
  void operator=(const Mat4& other);

  float m[16];
};


inline Mat4 Mat4::Identity() {
	return Mat4();
}

inline Mat4 Mat4::Multiply(const Mat4& other)const  {
	return Mat4();
}

inline float Mat4::Determinant() const {
	
	return 0.0f;
}

inline Mat4 Mat4::Adjoint() const {
	
	Mat4 result;
	return result;
}

inline Vec4 Mat4::TransformVec4(const Vec4 &v) {
  Vec4 o;
  o.x = m[0] * v.x + m[4] * v.y + m[8]  * v.z + m[12] * v.w;
  o.y = m[1] * v.x + m[5] * v.y + m[9]  * v.z + m[13] * v.w;
  o.z = m[2] * v.x + m[6] * v.y + m[10] * v.z + m[14] * v.w;
  o.w = m[3] * v.x + m[7] * v.y + m[11] * v.z + m[15] * v.w;
  return o;
}

inline Vec3 Mat4::TransformVec3(const Vec3 &r) {
  Vec4 tmp;
  tmp.x = r.x;
  tmp.y = r.y;
  tmp.z = r.z;
  tmp.w = 1.0;
  Vec4 result = TransformVec4(tmp);
  result.x = result.x / result.w;
  result.y = result.y / result.w;
  result.z = result.z / result.w;
  Vec3 k;
  k.x = result.x;
  k.y = result.y;
  k.z = result.z;
  return k;
}

inline bool Mat4::Inverse() {
	return true;
}

inline bool Mat4::GetInverse(Mat4* out) const {
	return true;

}

inline Mat4 Mat4::Transpose() const {
		
	return Mat4();
}

inline Mat4 Mat4::Translate(const Vec3& distance){
	
	return Mat4();
}

inline Mat4 Mat4::Translate(float x, float y, float z){
	
	return Mat4();
}

inline Mat4 Mat4::Scale(const Vec3& scale){
	
	return Mat4();
}

inline Mat4 Mat4::Scale(float x, float y, float z){
	
	return Mat4();
}

inline Mat4 Mat4::RotateX(float radians){
	
	return Mat4();
}

inline Mat4 Mat4::RotateY(float radians){
	
	return Mat4();
}

inline Mat4 Mat4::RotateZ(float radians) {
	
	return Mat4();
}

inline Mat4 Mat4::GetTransform(const Vec3& translate,
								const Vec3& scale,
								float rotateX, float rotateY,
								float rotateZ)   {
	return Mat4();
}

inline Mat4 Mat4::GetTransform(float trans_x, float trans_y, float trans_z,
	float scale_x, float scale_y, float scale_Z,
	float rotateX, float rotateY, float rotateZ)  {
	
	return Mat4();
}

inline Vec4 Mat4::GetColumn(int colum) const {
	return Vec4();
}

inline Vec4 Mat4::GetLine(int line) const {
	return Vec4();
}

inline Mat4 Mat4::PerspectiveMatrix(float fov, float aspect,
	float near, float far) const {
	
	return Mat4();
}

inline Mat4 Mat4::OrthoMatrix(float right, float left, float top, float valueottom,
	float near, float far) const {

	return Mat4();
}

inline Mat4 Mat4::operator+(const Mat4& other) const {
	return Mat4();
}

inline Mat4& Mat4::operator+=(const Mat4& other) {
	return (*this);
}

inline Mat4 Mat4::operator+(float value) const {
	return Mat4();
}

inline Mat4& Mat4::operator+=(float value) {	
	return (*this);
}

inline Mat4 Mat4::operator-(const Mat4& other) const  {
	return Mat4();
}

inline Mat4& Mat4::operator-=(const Mat4& other) {
	return (*this);
}

inline Mat4 Mat4::operator-(float value) const  {
	return Mat4();
}

inline Mat4& Mat4::operator-=(float value) {
	return (*this);
}

inline Mat4& Mat4::operator*=(float value) {
	return (*this);
}

inline Mat4 Mat4::operator*(float value) const  {
	return Mat4();
}

inline Mat4& Mat4::operator/=(float value) {
	return (*this);
}

inline Mat4 Mat4::operator/(float value) const {
	return Mat4();
}

inline bool Mat4::operator==(const Mat4& other) {
	return true;
}

inline bool Mat4::operator!=(const Mat4& other) {
	return false;
}

inline void Mat4::operator=(const Mat4& other) {
}

#endif
