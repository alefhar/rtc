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

// vector vector::operator-() const
// {
//   return vector{-_tuple};
// }

vector& vector::operator-=(const vector& rhs)
{
  this->_tuple -= rhs._tuple;
  return *this;
}

float vector::magnitude()
{
  return std::sqrt(
      x() * x() +
      y() * y() +
      z() * z());
}
