#pragma once

#include "euclidean.h"

TEST (point_test, point_is_point_tuple)
{
  point p{4, -4, 3};

  EXPECT_TRUE(is_point(p));
  EXPECT_FALSE(is_vector(p));
}

TEST (point_test, difference_of_points_is_vector)
{
  point p1{3, 2, 1};
  point p2{5, 6, 7};

  vector v = p1 - p2;

  EXPECT_EQ(vector(-2, -4, -6), v);
}
