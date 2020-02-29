#pragma once

#include "euclidean.h"

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

  EXPECT_EQ(1, v1.x());
  EXPECT_EQ(1, v1.y());
  EXPECT_EQ(6, v1.z());

  EXPECT_TRUE(is_vector(v1));

  EXPECT_EQ(-2, v2.x());
  EXPECT_EQ( 3, v2.y());
  EXPECT_EQ( 1, v2.z());
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

  EXPECT_EQ( 3, v1.x());
  EXPECT_EQ(-2, v1.y());
  EXPECT_EQ( 5, v1.z());

  EXPECT_EQ(-2, v2.x());
  EXPECT_EQ( 3, v2.y());
  EXPECT_EQ( 1, v2.z());
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
