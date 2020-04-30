#pragma once

#include "euclidean.h"

#include <cmath>

TEST (vector_test, vector_is_vector_tuple)
{
  vector v{4, -4, 3};

  EXPECT_TRUE(is_vector(v));
  EXPECT_FALSE(is_point(v));
}

TEST (vector_test, add_assign)
{
  vector v1{ 3, -2, 5};
  vector v2{-2,  3, 1};

  v1 += v2;

  EXPECT_EQ(vector(1, 1, 6), v1);
  EXPECT_TRUE(is_vector(v1));

  EXPECT_EQ(vector(-2, 3, 1), v2);
}

TEST (vector_test, add_vectors)
{
  vector v1{ 3, -2, 5};
  vector v2{-2,  3, 1};

  vector v3 = v1 + v2;

  EXPECT_EQ(vector(1, 1, 6), v3);
  EXPECT_TRUE(is_vector(v3));

  EXPECT_EQ(vector( 3, -2, 5), v1);
  EXPECT_EQ(vector(-2,  3, 1), v2);
}

TEST (vector_test, subtract_assign)
{
  vector v1{ 3, -2, 5};
  vector v2{-2,  3, 1};

  v1 -= v2;

  EXPECT_EQ(vector( 5, -5, 4), v1);
  EXPECT_EQ(vector(-2,  3, 1), v2);
}

TEST (vector_test, subtract_vectors)
{
  vector v1{ 3, -2, 5};
  vector v2{-2,  3, 1};

  vector v3 = v1 - v2;

  EXPECT_EQ(vector( 5, -5, 4), v3);
  EXPECT_EQ(vector( 3, -2, 5), v1);
  EXPECT_EQ(vector(-2,  3, 1), v2);
}

TEST (vector_test, negate)
{
  vector v1{3, -4, 9};

  vector v2 = -v1;

  EXPECT_EQ(vector(-3,  4, -9), v2);
  EXPECT_EQ(vector( 3, -4,  9), v1);
}

TEST (vector_test, magnitude_x_one)
{
  vector v{1, 0, 0};

  EXPECT_EQ(v.magnitude(), 1);
}
TEST (vector_test, magnitude_y_one)
{
  vector v{0, 1, 0};

  EXPECT_EQ(v.magnitude(), 1);
}

TEST (vector_test, magnitude_z_one)
{
  vector v{0, 1, 0};

  EXPECT_EQ(v.magnitude(), 1);
}

TEST (vector_test, magnitude_all_positive)
{
  vector v{1, 2, 3};

  EXPECT_FLOAT_EQ(v.magnitude(), std::sqrt(14));
}

TEST (vector_test, magnitude_all_negative)
{
  vector v{-1, -2, -3};

  EXPECT_FLOAT_EQ(v.magnitude(), std::sqrt(14));
}
