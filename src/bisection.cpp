#include "numerical/bisection.hpp"

#include <iomanip>

#ifndef NDEBUG
#include <iostream>

#define BASE_PRECISION 3
#endif

namespace numerical {

auto bisection(const std::function<double(double)> func, double_t a, double_t b, double_t err) -> double_t {
  if (func(a) * func(b) >= 0) {
    throw "No root between points.";
  }

  double_t c = a;
  int nit = 1;

  while (std::abs(b - a) > err) {
#ifndef NDEBUG
    std::cout << std::fixed << " Iteration=" << nit << "\ta=" << a << "\tb=" << b;
#endif

    c = (a + b) / 2;

    if (func(c) == 0.0) {
      break;
    }

    if (func(c) * func(a) < 0) {
      b = c;
    } else {
      a = c;
    }

#ifndef NDEBUG
    std::cout << "\tx" << nit << "=" << c << std::setprecision(BASE_PRECISION + 2) << "\tErr"
              << "=" << std::abs(b - a) << std::endl
              << std::endl;
#endif

    nit++;
  }

#ifndef NDEBUG
  std::cout << std::endl << std::endl << " The root is " << std::setprecision(BASE_PRECISION) << c << std::endl;
#endif

  return c;
}

}; // namespace numerical
