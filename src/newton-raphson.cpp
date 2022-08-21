#include "numerical/newton-raphson.hpp"
#include "numerical/derivative.hpp"

#include <iomanip>

#ifndef NDEBUG
#include <iostream>

#define BASE_PRECISION 3
#endif

namespace numerical {

auto newton_raphson(const std::function<double(double)>& func, double_t x0, double_t err) -> double_t {
  double_t xn = x0;

  int nit = 0;

  do {
    xn = xn - (func(xn) / derivative(func, xn));

#ifndef NDEBUG
    std::cout << std::fixed << " n = " << nit << "\tx" << nit << "=" << x0 << "\tf(x" << nit << ") = " << func(x0)
              << "\tx" << nit + 1 << " = " << xn << std::endl;
#endif

    nit++;
  } while (std::abs(func(xn)) > err);

#ifndef NDEBUG
  std::cout << std::endl << std::endl << " The root is " << std::setprecision(BASE_PRECISION) << xn << std::endl;
#endif

  return xn;
}

}; // namespace numerical
