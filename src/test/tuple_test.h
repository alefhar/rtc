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

  EXPECT_FLOAT_EQ(3, t1.x());
  EXPECT_FLOAT_EQ(2, t1.y());
  EXPECT_FLOAT_EQ(5, t1.z());
  EXPECT_FLOAT_EQ(1, t1.w());
  
  EXPECT_FLOAT_EQ(-1, t2.x());
  EXPECT_FLOAT_EQ( 3, t2.y());
  EXPECT_FLOAT_EQ(-2, t2.z());
  EXPECT_FLOAT_EQ( 1, t2.w());
}

TEST (tuple_test, tuples_add)
{
  tuple t1( 4, -1,  7, 0);
  tuple t2(-1,  3, -2, 1);

  tuple t3 = t1 + t2;

  EXPECT_FLOAT_EQ(3, t3.x());
  EXPECT_FLOAT_EQ(2, t3.y());
  EXPECT_FLOAT_EQ(5, t3.z());
  EXPECT_FLOAT_EQ(1, t3.w());

  EXPECT_FLOAT_EQ( 4, t1.x());
  EXPECT_FLOAT_EQ(-1, t1.y());
  EXPECT_FLOAT_EQ( 7, t1.z());
  EXPECT_FLOAT_EQ( 0, t1.w());
  
  EXPECT_FLOAT_EQ(-1, t2.x());
  EXPECT_FLOAT_EQ( 3, t2.y());
  EXPECT_FLOAT_EQ(-2, t2.z());
  EXPECT_FLOAT_EQ( 1, t2.w());
}

TEST (tuple_test, tuple_subtract_assign)
{
  tuple t1( 4, -1,  7, 0);
  tuple t2(-1,  3, -2, 1);

  t1 -= t2;

  EXPECT_FLOAT_EQ( 5, t1.x());
  EXPECT_FLOAT_EQ(-4, t1.y());
  EXPECT_FLOAT_EQ( 9, t1.z());
  EXPECT_FLOAT_EQ(-1, t1.w());
  
  EXPECT_FLOAT_EQ(-1, t2.x());
  EXPECT_FLOAT_EQ( 3, t2.y());
  EXPECT_FLOAT_EQ(-2, t2.z());
  EXPECT_FLOAT_EQ( 1, t2.w());
}

TEST (tuple_test, tuples_subtract)
{
  tuple t1( 4, -1,  7, 0);
  tuple t2(-1,  3, -2, 1);

  tuple t3 = t1 - t2;

  EXPECT_FLOAT_EQ( 5, t3.x());
  EXPECT_FLOAT_EQ(-4, t3.y());
  EXPECT_FLOAT_EQ( 9, t3.z());
  EXPECT_FLOAT_EQ(-1, t3.w());

  EXPECT_FLOAT_EQ( 4, t1.x());
  EXPECT_FLOAT_EQ(-1, t1.y());
  EXPECT_FLOAT_EQ( 7, t1.z());
  EXPECT_FLOAT_EQ( 0, t1.w());
  
  EXPECT_FLOAT_EQ(-1, t2.x());
  EXPECT_FLOAT_EQ( 3, t2.y());
  EXPECT_FLOAT_EQ(-2, t2.z());
  EXPECT_FLOAT_EQ( 1, t2.w());
}

TEST (tuple_test, tuple_negate)
{
  tuple t1(4, -1, 7, 0);

  tuple t2 = -t1;

  EXPECT_FLOAT_EQ(-4, t2.x());
  EXPECT_FLOAT_EQ( 1, t2.y());
  EXPECT_FLOAT_EQ(-7, t2.z());
  EXPECT_FLOAT_EQ( 0, t2.w());
  
  EXPECT_FLOAT_EQ( 4, t1.x());
  EXPECT_FLOAT_EQ(-1, t1.y());
  EXPECT_FLOAT_EQ( 7, t1.z());
  EXPECT_FLOAT_EQ( 0, t1.w());
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
