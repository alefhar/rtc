#pragma once

#include "euclidean.h"

TEST (point_test, point_is_point_tuple)
{
  point p{4, -4, 3};

  EXPECT_TRUE(p.is_point());
  EXPECT_FALSE(p.is_vector());
}

TEST (point_test, difference_of_points_is_vector)
{
  point p1{3, 2, 1};
  point p2{5, 6, 7};

  vector v = p1 - p2;

  EXPECT_EQ(vector(-2, -4, -6), v);
}

TEST (point_test, add_assign_vector_to_point)
{
  point  p{3, 2, 1};
  vector v{5, 6, 7};

  p += v;

  EXPECT_EQ(point(8, 8, 8), p);
}

TEST (point_test, add_vector_to_point)
{
  point  p{3, 2, 1};
  vector v{5, 6, 7};

  point p2 = p + v;

  EXPECT_EQ(point(8, 8, 8), p2);
  EXPECT_EQ(point(3, 2, 1), p);
  EXPECT_EQ(vector(5, 6, 7), v);
}

TEST (point_test, subtract_assign_vector_from_point)
{
  point  p{3, 2, 1};
  vector v{5, 6, 7};

  p -= v;

  EXPECT_EQ(point(-2, -4, -6), p);
}

TEST (point_test, subtract_vector_from_point)
{
  point  p{3, 2, 1};
  vector v{5, 6, 7};

  point p2 = p - v;

  EXPECT_EQ(point(-2, -4, -6), p2);
  EXPECT_EQ(point(3, 2, 1), p);
  EXPECT_EQ(vector(5, 6, 7), v);
}

TEST (point_test, negate)
{
  point p1{3, -4, 9};

  point p2 = -p1;

  EXPECT_EQ(point(-3,  4, -9), p2);
  EXPECT_EQ(point( 3, -4,  9), p1);
}

TEST (point_test, multiply_scale_up)
{
  point p(1, -2, 3);
 
  EXPECT_EQ(point(tuple(3.5, -7, 10.5, 3.5)), p * 3.5);
}

TEST (point_test, multiply_scale_down)
{
  point p(1, -2, 3);

  EXPECT_EQ(point(tuple(0.5, -1, 1.5, 0.5)), p * 0.5);
}

TEST (point_test, divide)
{
  point p(1, -2, 3);

  EXPECT_EQ(point(tuple(0.5, -1, 1.5, 0.5)), p / 2);
}
