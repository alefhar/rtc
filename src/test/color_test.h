#pragma once

#include "color.h"

TEST (color_test, components_are_set)
{
  color c{-0.5, 0.4, 1.7};

  EXPECT_FLOAT_EQ(-0.5, c.red());
  EXPECT_FLOAT_EQ( 0.4, c.green());
  EXPECT_FLOAT_EQ( 1.7, c.blue());
}

TEST (color_test, add_colors)
{
  color c1{0.9, 0.6, 0.75};
  color c2{0.7, 0.1, 0.25};

  EXPECT_EQ(color(1.6, 0.7, 1.0), c1 + c2);
}

TEST (color_test, subtract_colors)
{
  color c1{0.9, 0.6, 0.75};
  color c2{0.7, 0.1, 0.25};

  EXPECT_EQ(color(0.2, 0.5, 0.5), c1 - c2);
}

TEST (color_test, multiply_with_scalar)
{
  color c{0.2, 0.3, 0.4};

  EXPECT_EQ(color(0.4, 0.6, 0.8), c * 2);
}

TEST (color_test, multiply_with_scalar_commutative)
{
  color c{0.2, 0.3, 0.4};

  EXPECT_EQ(color(0.4, 0.6, 0.8), 2 * c);
}

TEST (color_test, schur_product) {
  color c1{1.0, 0.2, 0.4};
  color c2{0.9, 1.0, 0.1};

  EXPECT_EQ(color(0.9, 0.2, 0.04), c1 * c2);
}
