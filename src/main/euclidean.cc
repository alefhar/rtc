#include "euclidean.h"

euclidean::euclidean(float x, float y, float z, float w)
  : _tuple{x, y, z, w}
{
}

float euclidean::x() const
{
  return _tuple.x();
}

float euclidean::y() const
{
  return _tuple.y();
}

float euclidean::z() const
{
  return _tuple.z();
}
