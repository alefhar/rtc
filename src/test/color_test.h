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
