#pragma once

#include "tuple.h"

class euclidean
{
  private:
    tuple _tuple;

  public:
    float x() const;
    float y() const;
    float z() const;

  protected:
    euclidean(float x, float y, float z, float w);
};
