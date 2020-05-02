#pragma once

#include "tuple.h"

class color
{
  private:
    tuple _tuple;

    color(tuple t);

  public:
    color(float red, float green, float blue);

    float red() const { return _tuple.x(); };
    float green() const { return _tuple.y(); };
    float blue() const { return _tuple.z(); };

    color& operator+=(const color& rhs);
    friend color operator+(color lhs, const color& rhs)
    {
      lhs += rhs;
      return lhs;
    }
    
    color& operator-=(const color& rhs);
    friend color operator-(color lhs, const color& rhs)
    {
      lhs -= rhs;
      return lhs;
    }

    bool operator==(const color& rhs) const;
    bool operator!=(const color& rhs) const;
};

