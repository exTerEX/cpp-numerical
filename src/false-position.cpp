#include "numerical/false-position.hpp"

#include <iomanip>

#ifndef NDEBUG
#include <iostream>

#define BASE_PRECISION 3
#endif

namespace numerical {

auto false_position(const std::function<double(double)> func, double_t a, double_t b, double_t err) -> double_t {
  if (func(a) * func(b) >= 0) {
    throw "You have not assumed right a and b\n";
  }

  double_t x = a;
  int nit = 1;

  while (func(a) > err || func(b) > err) {
#ifndef NDEBUG
    std::cout << std::fixed << " Iteration=" << nit << "\ta=" << a << "\tb=" << b;
#endif
    x = (a * func(b) - b * func(a)) / (func(b) - func(a));

    if (func(x) == 0) {
      break;
    }

    if (func(x) * func(a) < 0) {
      b = x;
    } else {
      a = x;
    }

#ifndef NDEBUG
    std::cout << "\tx" << nit << "=" << x;
    std::cout << "\tf(x" << nit << ")=" << func(b) << std::endl << std::endl;
#endif

    nit++;
  }

#ifndef NDEBUG
  std::cout << std::endl << std::endl << " The root is " << std::setprecision(BASE_PRECISION) << x << std::endl;
#endif

  return x;
}

}; // namespace numerical
