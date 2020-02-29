#include "euclidean.h"

euclidean::euclidean(float x, float y, float z, float w)
  : _tuple{x, y, z, w}
{
}

euclidean::euclidean(const tuple& t)
  : _tuple{t}
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

void euclidean::x(float x)
{
  _tuple.x(x);
}

void euclidean::y(float y)
{
  _tuple.y(y);
}

void euclidean::z(float z)
{
  _tuple.z(z);
}

const tuple& euclidean::get_tuple() const
{
  return _tuple;
}

bool is_vector(const euclidean &e)
{
  return is_vector(e.get_tuple());
}

bool is_point(const euclidean &e)
{
  return is_point(e.get_tuple());
}
