#include "euclidean.h"
#include "canvas.h"

#include <ar/image_io.h>

#include <iostream>
#include <cstdlib>

struct projectile
{
  point position;
  vector velocity;
};

struct environment
{
  vector gravity;
  vector wind;
};

projectile tick(const projectile& proj, const environment& env)
{
  point position = proj.position + proj.velocity;
  vector velocity = proj.velocity + env.gravity + env.wind;
  return projectile{position, velocity};
}

float component(int argi, char** args) {
  return static_cast<float>(std::atof(args[argi]));
}

int main(int argc, char** args) {
  if (argc < 13) {
    std::cout << "Starting position, velocity, gravity and wind parameters expected!" << std::endl;
    return 1;
  }

  canvas canvas{900, 550};
  point position = point{component(1, args), component(2, args), component(3, args)};
  vector velocity = vector{component(4, args), component(5, args), component(6, args)};
  projectile p = projectile{position, velocity};

  vector gravity = vector{component(7, args), component(8, args), component(9, args)};
  vector wind = vector{component(10, args), component(11, args), component(12, args)};
  environment e = environment{gravity, wind};

  std::cout << "Starting conditions:\n"
    << "projectile: position = " << p.position << ", velocity = " << p.velocity << "\n"
    << "environment: gravity = " << e.gravity << ", wind = " << e.wind << "\n" << std::endl;

  while (p.position.y() > 0) {
    p = tick(p, e);
    std::size_t x = static_cast<std::size_t>(p.position.x());
    std::size_t y = static_cast<std::size_t>(p.position.y());
    if (x >= 0 && x < 900 && y >= 0 && y < 550)
      canvas(x, y) = color(0.75, 0.75, 0.75);
  }

  argon::image_io::write("trajectory.ppm", canvas.to_image(), argon::pnm_type::PPM_BINARY);
  
  return 0;
}

