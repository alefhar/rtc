#pragma once

#include "tuple.h"

template <class T> class euclidean
{
  protected:
    tuple _tuple;

  public:
    float x() const { return _tuple.x(); };
    float y() const { return _tuple.y(); };
    float z() const { return _tuple.z(); };

    void x(float x) { _tuple.x(x); };
    void y(float y) { _tuple.y(y); };
    void z(float z) { _tuple.z(z); };

    const tuple& get_tuple() const { return _tuple; };

    bool is_point() const { return _tuple.is_point(); };
    bool is_vector() const { return _tuple.is_vector(); };

  protected:
    euclidean(float x, float y, float z, float w) : _tuple{x, y, z, w} {};
    euclidean(const tuple& t) : _tuple{t} {};

  public:
    friend bool operator==(const euclidean& lhs, const euclidean& rhs)
    {
      return lhs.get_tuple() == rhs.get_tuple();
    }
    
    friend bool operator!=(const euclidean& lhs, const euclidean& rhs)
    {
      return !(lhs == rhs);
    }

    T operator-() const
    {
      return T{-_tuple.x(), -_tuple.y(), -_tuple.z()};
    }
 
    friend T operator*(T lhs, float rhs)
    {
      tuple t = lhs.get_tuple();
      return T{t * rhs};
    }

    friend T operator/(T lhs, float rhs)
    {
      tuple t = lhs.get_tuple();
      return T{t / rhs};
    }
};

class vector : public euclidean<vector>
{
  public:
    vector(float x, float y, float z);
    vector(const tuple& t);

    vector& operator+=(const vector& rhs);
    
    friend vector operator+(vector lhs, const vector& rhs)
    {
      lhs += rhs;
      return lhs;
    }

    vector& operator-=(const vector& rhs);

    friend vector operator-(vector lhs, const vector& rhs)
    {
      lhs -= rhs;
      return lhs;
    }

    float magnitude();
};

class point : public euclidean<point>
{
  public:
    point(float x, float y, float z);
    point(const tuple& t);

    friend vector operator-(const point& lhs, const point& rhs)
    {
      tuple t = lhs.get_tuple() - rhs.get_tuple();
      return vector(t);
    }

    point& operator+=(const vector& rhs);

    friend point operator+(point lhs, const vector& rhs)
    {
      lhs += rhs;
      return lhs;
    }

    point& operator-=(const vector& rhs);

    friend point operator-(point lhs, const vector& rhs)
    {
      lhs -= rhs;
      return lhs;
    }
};

