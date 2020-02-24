#pragma once

#include "vector.h"

TEST (vector_test, vector_is_vector_tuple)
{
  vector v{4, -4, 3};

  EXPECT_TRUE(is_vector(v));
  EXPECT_FALSE(is_point(v));
}

TEST (vector_test, add_vectors)
{
  vector v1{ 3, -2, 5};
  vector v2{-2,  3, 1};

  vector v3 = v1 + v2;

  EXPECT_EQ(1, v3.x());
  EXPECT_EQ(1, v3.y());
  EXPECT_EQ(6, v3.z());

  EXPECT_TRUE(is_vector(v3));
}
