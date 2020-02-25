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

    tuple& operator+=(const tuple& rhs);

    friend tuple operator+(tuple lhs, const tuple& rhs)
    {
      lhs += rhs;
      return lhs;
    }

    friend bool operator==(const tuple& lhs, const tuple& rhs)
    {
      return lhs.x() == rhs.x() && lhs.y() == rhs.y() && lhs.z() == rhs.z() && lhs.w() == rhs.w();
    }

    friend bool operator!=(const tuple& lhs, const tuple& rhs)
    {
      return !(lhs == rhs);
    }
};

bool is_vector(const tuple &t);

bool is_vector(const euclidean &e);

bool is_point(const tuple &t);

bool is_point(const euclidean &e);

