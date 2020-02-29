#include "euclidean.h"

point::point(float x, float y, float z)
  : euclidean(x, y, z, 1.f)
{
}

point& point::operator+=(const vector& rhs)
{
  _tuple += rhs.get_tuple();
  return *this;
}
