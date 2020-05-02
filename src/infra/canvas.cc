#include "canvas.h"

canvas::canvas(std::size_t width, std::size_t height)
  : _width{width}, _height{height}, _pixels(_width * _height, color{0, 0, 0})
{}
 
argon::image<std::int32_t> canvas::to_image() const
{
  auto img = argon::image<std::int32_t>{static_cast<int>(_width), static_cast<int>(_height), 3};
  for (std::size_t y = 0; y < _height; ++y)
    for (std::size_t x = 0; x < _width; ++x)
    {
      color pixel = (*this)(x, y);
      img(x, y, 0) = pixel.red() * 255;
      img(x, y, 1) = pixel.green() * 255;
      img(x, y, 2) = pixel.blue() * 255;
    }

  return img;
}

const color& canvas::operator()(std::size_t x, std::size_t y) const
{
  return _pixels[y * _width + x];
}

color& canvas::operator()(std::size_t x, std::size_t y)
{
  return _pixels[y * _width + x];
}
