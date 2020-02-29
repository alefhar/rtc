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

TEST (tuple_test, tuple_add_assign)
{
  tuple t1( 4, -1,  7, 0);
  tuple t2(-1,  3, -2, 1);

  t1 += t2;

  EXPECT_EQ(tuple(3, 2, 5, 1), t1);
  EXPECT_EQ(tuple(-1, 3, -2, 1), t2); 
}

TEST (tuple_test, tuples_add)
{
  tuple t1( 4, -1,  7, 0);
  tuple t2(-1,  3, -2, 1);

  tuple t3 = t1 + t2;

  EXPECT_EQ(tuple( 3,  2,  5, 1), t3);
  EXPECT_EQ(tuple( 4, -1,  7, 0), t1);
  EXPECT_EQ(tuple(-1,  3, -2, 1), t2); 
}

TEST (tuple_test, tuple_subtract_assign)
{
  tuple t1( 4, -1,  7, 0);
  tuple t2(-1,  3, -2, 1);

  t1 -= t2;

  EXPECT_EQ(tuple( 5, -4,  9, -1), t1);
  EXPECT_EQ(tuple(-1,  3, -2,  1), t2); 
}

TEST (tuple_test, tuples_subtract)
{
  tuple t1( 4, -1,  7, 0);
  tuple t2(-1,  3, -2, 1);

  tuple t3 = t1 - t2;
  
  EXPECT_EQ(tuple( 5, -4,  9, -1), t3);
  EXPECT_EQ(tuple( 4, -1,  7,  0), t1);
  EXPECT_EQ(tuple(-1,  3, -2,  1), t2);
}

TEST (tuple_test, tuple_negate)
{
  tuple t1(4, -1, 7, 0);

  tuple t2 = -t1;

  EXPECT_EQ(tuple(-4,  1, -7, 0), t2);
  EXPECT_EQ(tuple( 4, -1,  7, 0), t1);
}

TEST (tuple_test, tuples_equal)
{
  tuple t1(1, 2, 3, 4);
  tuple t2(1, 2, 3, 4);

  EXPECT_EQ(t1, t2);
}

TEST (tuple_test, tuples_not_equal_at_x)
{
  tuple t1(1, 2, 3, 4);
  tuple t2(0, 2, 3, 4);

  EXPECT_NE(t1, t2);
}

TEST (tuple_test, tuples_not_equal_at_y)
{
  tuple t1(1, 2, 3, 4);
  tuple t2(1, 0, 3, 4);

  EXPECT_NE(t1, t2);
}

TEST (tuple_test, tuples_not_equal_at_z)
{
  tuple t1(1, 2, 3, 4);
  tuple t2(1, 2, 0, 4);

  EXPECT_NE(t1, t2);
}

TEST (tuple_test, tuples_not_equal_at_w)
{
  tuple t1(1, 2, 3, 4);
  tuple t2(1, 2, 3, 0);

  EXPECT_NE(t1, t2);
}

TEST (tuple_test, multiply_scale_up)
{
  tuple t(1, -2, 3, -4);
  
  EXPECT_EQ(tuple(3.5, -7, 10.5, -14), t * 3.5);
}

TEST (tuple_test, multiply_scale_down)
{
  tuple t(1, -2, 3, -4);

  EXPECT_EQ(tuple(0.5, -1, 1.5, -2), t * 0.5);
}
