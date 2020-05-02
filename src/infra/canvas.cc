#include "canvas.h"

canvas::canvas(std::size_t width, std::size_t height)
  : _width{width}, _height{height}
{}
    
color canvas::operator()(std::size_t x, std::size_t y) const
{
  return color(0, 0, 0);
}
