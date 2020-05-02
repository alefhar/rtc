#pragma once

#include "canvas.h"

TEST (canvas_test, canvas_is_black_by_default)
{
  canvas c{10, 20};

  EXPECT_EQ(10, c.width());
  EXPECT_EQ(20, c.height());

  for (std::size_t y = 0; y < c.height(); ++y)
    for (std::size_t x = 0; x < c.width(); ++x)
      EXPECT_EQ(color(0, 0, 0), c(x, y));
}

TEST (canvas_test, write_color_to_canvas_pixel)
{
  canvas c{10, 20};
  color red{1, 0, 0};

  c(2, 3) = red;

  EXPECT_EQ(red, c(2, 3));
}
