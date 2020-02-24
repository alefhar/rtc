#pragma once

#include "vector.h"

TEST (vector_test, vector_is_vector_tuple)
{
  vector v{4, -4, 3};

  EXPECT_TRUE(is_vector(p));
  EXPECT_FALSE(is_point(p));
}
