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
