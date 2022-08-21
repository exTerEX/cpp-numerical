#ifndef NUMERICAL_BISECTION_HPP
#define NUMERICAL_BISECTION_HPP

#include <cmath>
#include <functional>

namespace numerical {

auto bisection(const std::function<double(double)>, double_t, double_t, double_t = 1e-4) -> double_t;

}; // namespace numerical

#endif
