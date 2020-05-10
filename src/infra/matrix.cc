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
