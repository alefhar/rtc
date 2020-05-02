#pragma once

#include "color.h"

class canvas
{
  private:
    std::size_t _width;
    std::size_t _height;

  public:
    canvas(std::size_t width, std::size_t height);

    std::size_t width() const { return _width; };
    std::size_t height() const { return _height; };

    color operator()(std::size_t x, std::size_t y) const;
};
