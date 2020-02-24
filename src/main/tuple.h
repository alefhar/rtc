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
    
    void x(float x);
    void y(float y);
    void z(float z);
    void w(float w);
};

bool is_vector(const tuple &t);

bool is_vector(const euclidean &e);

bool is_point(const tuple &t);

bool is_point(const euclidean &e);

