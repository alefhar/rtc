#pragma once

#include "matrix.h"

TEST (matrix_test, construct_4x4)
{
  matrix m = mat4(  1  ,  2  ,  3  ,  4  ,
                    5.5,  6.5,  7.5,  8.5,
                    9  , 10  , 11  , 12  ,
                   13.5, 14.5, 15.5, 16.5);

  EXPECT_FLOAT_EQ(m.m11(),  1  );
  EXPECT_FLOAT_EQ(m.m12(),  2  );
  EXPECT_FLOAT_EQ(m.m13(),  3  );
  EXPECT_FLOAT_EQ(m.m14(),  4  );
  EXPECT_FLOAT_EQ(m.m21(),  5.5);
  EXPECT_FLOAT_EQ(m.m22(),  6.5);
  EXPECT_FLOAT_EQ(m.m23(),  7.5);
  EXPECT_FLOAT_EQ(m.m24(),  8.5);
  EXPECT_FLOAT_EQ(m.m31(),  9  );
  EXPECT_FLOAT_EQ(m.m32(), 10  );
  EXPECT_FLOAT_EQ(m.m33(), 11  );
  EXPECT_FLOAT_EQ(m.m34(), 12  );
  EXPECT_FLOAT_EQ(m.m41(), 13.5);
  EXPECT_FLOAT_EQ(m.m42(), 14.5);
  EXPECT_FLOAT_EQ(m.m43(), 15.5);
  EXPECT_FLOAT_EQ(m.m44(), 16.5);
}

TEST (matrix_test, construct_3x3)
{
  matrix m = mat3( -3,  5,  0,
                    1, -2, -7,
                    0,  1,  1);

  EXPECT_FLOAT_EQ(m.m11(), -3);
  EXPECT_FLOAT_EQ(m.m12(),  5);
  EXPECT_FLOAT_EQ(m.m13(),  0);
  EXPECT_FLOAT_EQ(m.m21(),  1);
  EXPECT_FLOAT_EQ(m.m22(), -2);
  EXPECT_FLOAT_EQ(m.m23(), -7);
  EXPECT_FLOAT_EQ(m.m31(),  0);
  EXPECT_FLOAT_EQ(m.m32(),  1);
  EXPECT_FLOAT_EQ(m.m33(),  1);
}

TEST (matrix_test, construct_2x2)
{
  matrix m = mat2( -3,  5,
                    1, -2);

  EXPECT_FLOAT_EQ(m.m11(), -3);
  EXPECT_FLOAT_EQ(m.m12(),  5);
  EXPECT_FLOAT_EQ(m.m21(),  1);
  EXPECT_FLOAT_EQ(m.m22(), -2);
}
