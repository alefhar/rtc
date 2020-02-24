#pragma once

#include "euclidean.h"

class vector : public euclidean
{
  public:
    vector(float x, float y, float z);

    friend vector operator+(vector lhs, const vector& rhs)
    {
      return vector{lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z()};
    }
};

