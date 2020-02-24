#pragma once

#include "point.h"

TEST (point_test, point_is_point_tuple)
{
  point p{4, -4, 3};

  EXPECT_TRUE(is_point(p));
  EXPECT_FALSE(is_vector(p));
}
