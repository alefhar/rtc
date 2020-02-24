#include "gtest/gtest.h"

#include "tuple_test.h"
#include "point_test.h"
#include "vector_test.h"

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
