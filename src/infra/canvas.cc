#include "canvas.h"

canvas::canvas(std::size_t width, std::size_t height)
  : _width{width}, _height{height}, _pixels{_width * _height, color{0, 0, 0}}
{}
    
const color& canvas::operator()(std::size_t x, std::size_t y) const
{
  return _pixels[y * _width + x];
}

color& canvas::operator()(std::size_t x, std::size_t y)
{
  return _pixels[y * _width + x];
}
