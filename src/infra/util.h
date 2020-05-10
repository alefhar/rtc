#pragma once

#include "constants.h"

#include <cmath>

template <typename T> bool are_close(const T& lhs, const T& rhs)
{
  return std::abs(lhs - rhs) < EPS;
}
