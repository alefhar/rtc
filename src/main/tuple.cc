#include "tuple.h"

tuple::tuple(float x, float y, float z, float w)
  : _x{x}, _y{y}, _z{z}, _w{w}
{
}

tuple::tuple(const tuple& t)
  : _x{t._x}, _y{t._y}, _z{t._z}, _w{t._w}
{
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

void tuple::x(float x)
{
  this->_x = x;
}

void tuple::y(float y)
{
  this->_y = y;
}

void tuple::z(float z)
{
  this->_z = z;
}

void tuple::w(float w)
{
  this->_w = w;
}

tuple& tuple::operator+=(const tuple& rhs)
{
  this->_x += rhs.x();
  this->_y += rhs.y();
  this->_z += rhs.z();
  this->_w += rhs.w();

  return *this;
}

tuple& tuple::operator-=(const tuple& rhs)
{
  this->_x -= rhs.x();
  this->_y -= rhs.y();
  this->_z -= rhs.z();
  this->_w -= rhs.w();

  return *this;
}

tuple tuple::operator-() const
{
  return tuple{-this->_x, -this->_y, -this->_z, -this->_w};
}

bool is_vector(const tuple &t)
{
  return t.w() == 0.f;
}

bool is_point(const tuple &t)
{
  return t.w() == 1.f;
}
