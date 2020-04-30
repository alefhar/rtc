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

tuple& tuple::operator*=(float rhs)
{
  this->_x *= rhs;
  this->_y *= rhs;
  this->_w *= rhs;
  this->_z *= rhs;
  return *this;
}

tuple& tuple::operator/=(float rhs)
{
  this->_x /= rhs;
  this->_y /= rhs;
  this->_z /= rhs;
  this->_w /= rhs;
  return *this;
}

bool tuple::is_vector() const
{
  return _w == 0.f;
}

bool tuple::is_point() const
{
  return _w == 1.f;
}
