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

    const tuple& get_tuple() const;

  protected:
    euclidean(float x, float y, float z, float w);
};
