#pragma once

#include "euclidean.h"

class vector : public euclidean
{
  public:
    vector(float x, float y, float z);

    vector& operator+=(const vector& rhs);
    
    friend vector operator+(vector lhs, const vector& rhs)
    {
      lhs += rhs;
      return lhs;
    }
};

