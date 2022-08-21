#include "numerical/derivative.hpp"

#include <iomanip>

#ifndef NDEBUG
#include <iostream>

#define BASE_PRECISION 3
#endif

namespace numerical {

auto derivative(const std::function<double(double)> func, double_t x) -> double_t {
  double_t h = std::sqrt(DBL_EPSILON / (double_t)2);

  return (func(x + h) - func(x - h)) / (2 * h);
}

}; // namespace numerical
