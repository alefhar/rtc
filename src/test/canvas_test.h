#pragma once

#include "canvas.h"

TEST (canvas_test, canvas_is_black_by_default)
{
  canvas c{10, 20};

  EXPECT_EQ(10, c.width());
  EXPECT_EQ(20, c.height());

  for (int y = 0; y < c.height(); ++y)
    for (int x = 0; x < c.width(); ++x)
      EXPECT_EQ(color(0, 0, 0), c(x, y));
}
