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

    void x(float x);
    void y(float y);
    void z(float z);

    const tuple& get_tuple() const;

  protected:
    euclidean(float x, float y, float z, float w);
};
