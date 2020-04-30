#pragma once

#include "constants.h"

#include <cmath>

class tuple
{
  private:
    float _x;
    float _y;
    float _z;
    float _w;

  public:
    tuple(float x, float y, float z, float w);
    tuple(const tuple& t);

    float x() const;
    float y() const;
    float z() const;
    float w() const;
    
    void x(float x);
    void y(float y);
    void z(float z);
    void w(float w);

    tuple& operator+=(const tuple& rhs);

    friend tuple operator+(tuple lhs, const tuple& rhs)
    {
      lhs += rhs;
      return lhs;
    }

    tuple& operator-=(const tuple& rhs);

    friend tuple operator-(tuple lhs, const tuple& rhs)
    {
      lhs -= rhs;
      return lhs;
    }

    tuple operator-() const;

    tuple& operator*=(float rhs);
    friend tuple operator*(tuple lhs, float rhs)
    {
      lhs *= rhs;
      return lhs;
    }

    friend bool operator==(const tuple& lhs, const tuple& rhs)
    {
      return std::abs(lhs.x() - rhs.x()) < EPS
        && std::abs(lhs.y() - rhs.y()) < EPS
        && std::abs(lhs.z() - rhs.z()) < EPS
        && std::abs(lhs.w() - rhs.w()) < EPS;
    }

    friend bool operator!=(const tuple& lhs, const tuple& rhs)
    {
      return !(lhs == rhs);
    }
};

bool is_vector(const tuple &t);

bool is_point(const tuple &t);
