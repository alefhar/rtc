#include "color.h"

color::color(float red, float green, float blue)
  : _tuple{red, green, blue, 0.f}
{}

color::color(tuple t)
  : _tuple{t}
{}

color& color::operator+=(const color& rhs)
{
  _tuple += rhs._tuple;
  return *this;
}

color& color::operator-=(const color& rhs)
{
  _tuple -= rhs._tuple;
  return *this;
}

color& color::operator*=(float rhs)
{
  _tuple *= rhs;
  return *this;
}

color& color::operator*=(const color& rhs)
{
  _tuple *= rhs._tuple;
  return *this;
}

bool color::operator==(const color& rhs) const
{
  return _tuple == rhs._tuple;
}
  
bool color::operator!=(const color& rhs) const
{
  return !(*this == rhs);
}
