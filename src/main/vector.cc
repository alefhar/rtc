#include "euclidean.h"

vector::vector(float x, float y, float z)
  : euclidean(x, y, z, 0.f)
{
}

vector::vector(const tuple& t)
  : euclidean(t)
{
}

vector& vector::operator+=(const vector& rhs)
{
  this->_tuple += rhs._tuple;
  return *this;
}

vector& vector::operator-=(const vector& rhs)
{
  this->_tuple -= rhs._tuple;
  return *this;
}

float vector::magnitude() const
{
  return this->_tuple.magnitude();
}

vector vector::normalize() const
{
  return vector(_tuple.normalize());
}
    
float vector::dot(const vector& v) const
{
  return _tuple.dot(v.get_tuple());
}

vector vector::cross(const vector& v) const
{
  float x = _tuple.y() * v.get_tuple().z() - _tuple.z() * v.get_tuple().y();
  float y = _tuple.z() * v.get_tuple().x() - _tuple.x() * v.get_tuple().z();
  float z = _tuple.x() * v.get_tuple().y() - _tuple.y() * v.get_tuple().x();
  return vector{x, y, z};
}
