#include "vector.h"

vector::vector(float x, float y, float z)
  : euclidean(x, y, z, 0.f)
{
}

vector& vector::operator+=(const vector& rhs)
{
  this->_tuple += rhs._tuple;
  return *this;
}
