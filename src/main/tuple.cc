#include "tuple.h"

tuple::tuple(float x, float y, float z, float w)
{
  this->_x = x;
  this->_y = y;
  this->_z = z;
  this->_w = w;
}

float tuple::x() const
{
  return this->_x;
}

float tuple::y() const
{
  return this->_y;
}

float tuple::z() const
{
  return this->_z;
}

float tuple::w() const
{
  return this->_w;
}

bool is_point(const tuple &t)
{
  return t.w() == 1.f;
}

bool is_vector(const tuple &t)
{
  return t.w() == 0.f;
}
