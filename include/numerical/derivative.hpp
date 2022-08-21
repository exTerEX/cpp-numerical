#ifndef NUMERICAL_DERIVATIVE_HPP
#define NUMERICAL_DERIVATIVE_HPP

#include <cfloat>
#include <cmath>
#include <functional>

namespace numerical {

auto derivative(const std::function<double(double)>, double_t) -> double_t;

}; // namespace numerical

#endif
