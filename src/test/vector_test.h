#pragma once

#include "euclidean.h"

#include <cmath>

TEST (vector_test, vector_is_vector_tuple)
{
  vector v{4, -4, 3};

  EXPECT_TRUE(v.is_vector());
  EXPECT_FALSE(v.is_point());
}

TEST (vector_test, add_assign)
{
  vector v1{ 3, -2, 5};
  vector v2{-2,  3, 1};

  v1 += v2;

  EXPECT_EQ(vector(1, 1, 6), v1);
  EXPECT_TRUE(v1.is_vector());

  EXPECT_EQ(vector(-2, 3, 1), v2);
}

TEST (vector_test, add_vectors)
{
  vector v1{ 3, -2, 5};
  vector v2{-2,  3, 1};

  vector v3 = v1 + v2;

  EXPECT_EQ(vector(1, 1, 6), v3);
  EXPECT_TRUE(v3.is_vector());

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

TEST (vector_test, multiply_scale_up)
{
  vector v(1, -2, 3);
 
  EXPECT_EQ(vector(tuple(3.5, -7, 10.5, 0.)), v * 3.5);
}

TEST (vector_test, multiply_scale_down)
{
  vector v(1, -2, 3);

  EXPECT_EQ(vector(tuple(0.5, -1, 1.5, 0.)), v * 0.5);
}

TEST (vector_test, divide)
{
  vector v(1, -2, 3);

  EXPECT_EQ(vector(tuple(0.5, -1, 1.5, 0)), v / 2);
}

TEST (vector_test, normalize_single_component)
{
  vector v(4, 0, 0);

  EXPECT_EQ(vector(1, 0, 0), v.normalize());
}

TEST (vector_test, normalize_all_components)
{
  vector v(1, 2, 3);

  EXPECT_EQ(vector(0.26726f, 0.53452, 0.80178), v.normalize());
}

TEST (vector_test, magnitude_of_normalized_vector_is_one)
{
  vector v(1, 2, 3);
  
  EXPECT_FLOAT_EQ(1, v.normalize().magnitude());
}

TEST (vector_test, dot_product)
{
  vector v1(1, 2, 3);
  vector v2(2, 3, 4);

  EXPECT_FLOAT_EQ(20, v1.dot(v2));
}

TEST (vector_test, cross_product)
{
  vector v1(1, 2, 3);
  vector v2(2, 3, 4);

  EXPECT_EQ(vector(-1, 2, -1), v1.cross(v2));
  EXPECT_EQ(vector(1, -2, 1), v2.cross(v1));
}
