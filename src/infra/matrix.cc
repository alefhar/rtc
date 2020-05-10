#include "matrix.h"

#include <string>
#include <stdexcept>

matrix::matrix(float m11, float m12, float m13, float m14, 
               float m21, float m22, float m23, float m24,
               float m31, float m32, float m33, float m34,
               float m41, float m42, float m43, float m44,
               std::size_t dim)
  : _m11{m11}, _m12{m12}, _m13{m13}, _m14{m14},
    _m21{m21}, _m22{m22}, _m23{m23}, _m24{m24},
    _m31{m31}, _m32{m32}, _m33{m33}, _m34{m34},
    _m41{m41}, _m42{m42}, _m43{m43}, _m44{m44},
    _dim{dim}
{}

void matrix::check_dimension(std::size_t x, std::size_t y) const
{
  if (x > _dim || y > _dim)
    throw std::range_error("accessing element m" + std::to_string(x) + "" + std::to_string(y) +
        "for mat" + std::to_string(_dim) + "" + std::to_string(_dim));
}
    
matrix matrix::operator*=(const matrix& rhs) {
  float r11 = m11() * rhs.m11() + m12() * rhs.m21();
  float r12 = m11() * rhs.m12() + m12() * rhs.m22();
  float r21 = m21() * rhs.m11() + m22() * rhs.m21();
  float r22 = m21() * rhs.m12() + m22() * rhs.m22();
  
  if (_dim == 2) {
    _m11 = r11; _m12 = r12;
    _m21 = r21; _m22 = r22;
    return *this;
  }
  
  r11 += m13() * rhs.m31();
  r12 += m13() * rhs.m32();
  r21 += m23() * rhs.m31();
  r22 += m23() * rhs.m32();
  float r13 = m11() * rhs.m13() + m12() * rhs.m23() + m13() * rhs.m33();
  float r23 = m21() * rhs.m13() + m22() * rhs.m23() + m23() * rhs.m33();
  float r31 = m31() * rhs.m11() + m32() * rhs.m21() + m33() * rhs.m31();
  float r32 = m31() * rhs.m12() + m32() * rhs.m22() + m33() * rhs.m32();
  float r33 = m31() * rhs.m13() + m32() * rhs.m23() + m33() * rhs.m33();

  if (_dim == 3) {
    _m11 = r11; _m12 = r12; _m13 = r13;
    _m21 = r21; _m22 = r22; _m23 = r23;
    _m31 = r31; _m32 = r32; _m33 = r33;
    return *this;
  }

  r11 += m14() * rhs.m41();
  r12 += m14() * rhs.m42();
  r13 += m14() * rhs.m43();
  r21 += m24() * rhs.m41();
  r22 += m24() * rhs.m42();
  r23 += m24() * rhs.m43();
  r31 += m34() * rhs.m41();
  r32 += m34() * rhs.m42();
  r33 += m34() * rhs.m43();
  float r14 = m11() * rhs.m14() + m12() * rhs.m24() + m13() * rhs.m34() + m14() * rhs.m44();
  float r24 = m21() * rhs.m14() + m22() * rhs.m24() + m23() * rhs.m34() + m24() * rhs.m44();
  float r34 = m31() * rhs.m14() + m32() * rhs.m24() + m33() * rhs.m34() + m34() * rhs.m44();
  float r41 = m41() * rhs.m11() + m42() * rhs.m21() + m43() * rhs.m31() + m44() * rhs.m41();
  float r42 = m41() * rhs.m12() + m42() * rhs.m22() + m43() * rhs.m32() + m44() * rhs.m42();
  float r43 = m41() * rhs.m13() + m42() * rhs.m23() + m43() * rhs.m33() + m44() * rhs.m43();
  float r44 = m41() * rhs.m14() + m42() * rhs.m24() + m43() * rhs.m34() + m44() * rhs.m44();

  if (_dim == 4) {
    _m11 = r11; _m12 = r12; _m13 = r13; _m14 = r14;
    _m21 = r21; _m22 = r22; _m23 = r23; _m24 = r24;
    _m31 = r31; _m32 = r32; _m33 = r33; _m34 = r34;
    _m41 = r41; _m42 = r42; _m43 = r43; _m44 = r44;
    return *this;
  }

  return *this;
}

matrix mat4(float m11, float m12, float m13, float m14,
            float m21, float m22, float m23, float m24,
            float m31, float m32, float m33, float m34,
            float m41, float m42, float m43, float m44)
{
  return matrix(m11, m12, m13, m14,
                m21, m22, m23, m24,
                m31, m32, m33, m34,
                m41, m42, m43, m44,
                4);
}

matrix mat3(float m11, float m12, float m13,
            float m21, float m22, float m23,
            float m31, float m32, float m33)
{
  return matrix(m11, m12, m13, 0.f,
                m21, m22, m23, 0.f,
                m31, m32, m33, 0.f,
                0.f, 0.f, 0.f, 0.f,
                3);
}

matrix mat2(float m11, float m12,
            float m21, float m22)
{
  return matrix(m11, m12, 0.f, 0.f,
                m21, m22, 0.f, 0.f,
                0.f, 0.f, 0.f, 0.f,
                0.f, 0.f, 0.f, 0.f,
                2);
}
