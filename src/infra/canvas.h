#pragma once

#include "color.h"

#include <vector>

class canvas
{
  private:
    std::size_t _width;
    std::size_t _height;

    std::vector<color> _pixels;

  public:
    canvas(std::size_t width, std::size_t height);

    std::size_t width() const { return _width; };
    std::size_t height() const { return _height; };

    const color& operator()(std::size_t x, std::size_t y) const;
    color& operator()(std::size_t x, std::size_t y);
};
