#pragma once

class euclidean;

class tuple
{
  private:
    float _x;
    float _y;
    float _z;
    float _w;

  public:
    tuple(float x, float y, float z, float w);

    float x() const;
    float y() const;
    float z() const;
    float w() const;
};

bool is_vector(const tuple &t);

bool is_vector(const euclidean &e);

bool is_point(const tuple &t);

bool is_point(const euclidean &e);

