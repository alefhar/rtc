#include "vector.h"

vector::vector(float x, float y, float z)
  : euclidean(x, y, z, 0.f)
{
}

vector& vector::operator+=(const vector& rhs)
{
  x(x() + rhs.x());
  y(y() + rhs.y());
  z(z() + rhs.z());
  return *this;
}
