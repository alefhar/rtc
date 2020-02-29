#pragma once

#include "tuple.h"

class euclidean
{
  protected:
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
    euclidean(const tuple& t);

  public:    
    friend bool operator==(const euclidean& lhs, const euclidean& rhs)
    {
      return lhs.get_tuple() == rhs.get_tuple();
    }
    
    friend bool operator!=(const euclidean& lhs, const euclidean& rhs)
    {
      return !(lhs == rhs);
    }
};

class vector : public euclidean
{
  public:
    vector(float x, float y, float z);
    vector(tuple t);

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
};

class point : public euclidean
{
  public:
    point(float x, float y, float z);

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
};
