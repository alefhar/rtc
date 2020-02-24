#pragma once

#include "tuple.h"

TEST (tuple_test, tuple_is_point)
{
  tuple a(4.3, -4.2, 3.1, 1.0);
  
  EXPECT_FLOAT_EQ( 4.3, a.x());
  EXPECT_FLOAT_EQ(-4.2, a.y());
  EXPECT_FLOAT_EQ( 3.1, a.z());
  EXPECT_FLOAT_EQ( 1.0, a.w());

  EXPECT_TRUE(is_point(a));
  EXPECT_FALSE(is_vector(a));
}

TEST (tuple_test, tuple_is_vector)
{
  tuple a(4.3, -4.2, 3.1, 0.0);
  
  EXPECT_FLOAT_EQ( 4.3, a.x());
  EXPECT_FLOAT_EQ(-4.2, a.y());
  EXPECT_FLOAT_EQ( 3.1, a.z());
  EXPECT_FLOAT_EQ( 0.0, a.w());
  
  EXPECT_FALSE(is_point(a));
  EXPECT_TRUE(is_vector(a));
}
